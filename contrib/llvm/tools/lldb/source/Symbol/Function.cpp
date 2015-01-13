//===-- Function.cpp --------------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "lldb/Symbol/Function.h"
#include "lldb/Core/Disassembler.h"
#include "lldb/Core/Module.h"
#include "lldb/Core/Section.h"
#include "lldb/Host/Host.h"
#include "lldb/Symbol/ClangASTType.h"
#include "lldb/Symbol/CompileUnit.h"
#include "lldb/Symbol/LineTable.h"
#include "lldb/Symbol/SymbolFile.h"
#include "lldb/Symbol/SymbolVendor.h"
#include "llvm/Support/Casting.h"

using namespace lldb;
using namespace lldb_private;

//----------------------------------------------------------------------
// Basic function information is contained in the FunctionInfo class.
// It is designed to contain the name, linkage name, and declaration
// location.
//----------------------------------------------------------------------
FunctionInfo::FunctionInfo (const char *name, const Declaration *decl_ptr) :
    m_name(name),
    m_declaration(decl_ptr)
{
}


FunctionInfo::FunctionInfo (const ConstString& name, const Declaration *decl_ptr) :
    m_name(name),
    m_declaration(decl_ptr)
{
}


FunctionInfo::~FunctionInfo()
{
}

void
FunctionInfo::Dump(Stream *s, bool show_fullpaths) const
{
    if (m_name)
        *s << ", name = \"" << m_name << "\"";
    m_declaration.Dump(s, show_fullpaths);
}


int
FunctionInfo::Compare(const FunctionInfo& a, const FunctionInfo& b)
{
    int result = ConstString::Compare(a.GetName(), b.GetName());
    if (result)
        return result;

    return Declaration::Compare(a.m_declaration, b.m_declaration);
}


Declaration&
FunctionInfo::GetDeclaration()
{
    return m_declaration;
}

const Declaration&
FunctionInfo::GetDeclaration() const
{
    return m_declaration;
}

const ConstString&
FunctionInfo::GetName() const
{
    return m_name;
}

size_t
FunctionInfo::MemorySize() const
{
    return m_name.MemorySize() + m_declaration.MemorySize();
}


InlineFunctionInfo::InlineFunctionInfo
(
    const char *name,
    const char *mangled,
    const Declaration *decl_ptr,
    const Declaration *call_decl_ptr
) :
    FunctionInfo(name, decl_ptr),
    m_mangled(ConstString(mangled), true),
    m_call_decl (call_decl_ptr)
{
}

InlineFunctionInfo::InlineFunctionInfo
(
    const ConstString& name,
    const Mangled &mangled,
    const Declaration *decl_ptr,
    const Declaration *call_decl_ptr
) :
    FunctionInfo(name, decl_ptr),
    m_mangled(mangled),
    m_call_decl (call_decl_ptr)
{
}

InlineFunctionInfo::~InlineFunctionInfo()
{
}

int
InlineFunctionInfo::Compare(const InlineFunctionInfo& a, const InlineFunctionInfo& b)
{

    int result = FunctionInfo::Compare(a, b);
    if (result)
        return result;
    // only compare the mangled names if both have them
    return Mangled::Compare(a.m_mangled, a.m_mangled);
}

void
InlineFunctionInfo::Dump(Stream *s, bool show_fullpaths) const
{
    FunctionInfo::Dump(s, show_fullpaths);
    if (m_mangled)
        m_mangled.Dump(s);
}

void
InlineFunctionInfo::DumpStopContext (Stream *s) const
{
//    s->Indent("[inlined] ");
    s->Indent();
    if (m_mangled)
        s->PutCString (m_mangled.GetName().AsCString());
    else
        s->PutCString (m_name.AsCString());
}


const ConstString &
InlineFunctionInfo::GetName () const
{
    if (m_mangled)
        return m_mangled.GetName();
    return m_name;
}


Declaration &
InlineFunctionInfo::GetCallSite ()
{
    return m_call_decl;
}

const Declaration &
InlineFunctionInfo::GetCallSite () const
{
    return m_call_decl;
}


Mangled&
InlineFunctionInfo::GetMangled()
{
    return m_mangled;
}

const Mangled&
InlineFunctionInfo::GetMangled() const
{
    return m_mangled;
}

size_t
InlineFunctionInfo::MemorySize() const
{
    return FunctionInfo::MemorySize() + m_mangled.MemorySize();
}

//----------------------------------------------------------------------
//
//----------------------------------------------------------------------
Function::Function
(
    CompileUnit *comp_unit,
    lldb::user_id_t func_uid,
    lldb::user_id_t type_uid,
    const Mangled &mangled,
    Type * type,
    const AddressRange& range
) :
    UserID (func_uid),
    m_comp_unit (comp_unit),
    m_type_uid (type_uid),
    m_type (type),
    m_mangled (mangled),
    m_block (func_uid),
    m_range (range),
    m_frame_base (),
    m_flags (),
    m_prologue_byte_size (0)
{
    m_block.SetParentScope(this);
    assert(comp_unit != nullptr);
}

Function::Function
(
    CompileUnit *comp_unit,
    lldb::user_id_t func_uid,
    lldb::user_id_t type_uid,
    const char *mangled,
    Type *type,
    const AddressRange &range
) :
    UserID (func_uid),
    m_comp_unit (comp_unit),
    m_type_uid (type_uid),
    m_type (type),
    m_mangled (ConstString(mangled), true),
    m_block (func_uid),
    m_range (range),
    m_frame_base (),
    m_flags (),
    m_prologue_byte_size (0)
{
    m_block.SetParentScope(this);
    assert(comp_unit != nullptr);
}


Function::~Function()
{
}

void
Function::GetStartLineSourceInfo (FileSpec &source_file, uint32_t &line_no)
{
    line_no = 0;
    source_file.Clear();
    
    if (m_comp_unit == nullptr)
        return;
        
    if (m_type != nullptr && m_type->GetDeclaration().GetLine() != 0)
    {
        source_file = m_type->GetDeclaration().GetFile();
        line_no = m_type->GetDeclaration().GetLine();
    }
    else 
    {
        LineTable *line_table = m_comp_unit->GetLineTable();
        if (line_table == nullptr)
            return;
            
        LineEntry line_entry;
        if (line_table->FindLineEntryByAddress (GetAddressRange().GetBaseAddress(), line_entry, nullptr))
        {
            line_no = line_entry.line;
            source_file = line_entry.file;
        }
    }
}

void
Function::GetEndLineSourceInfo (FileSpec &source_file, uint32_t &line_no)
{
    line_no = 0;
    source_file.Clear();
    
    // The -1 is kind of cheesy, but I want to get the last line entry for the given function, not the 
    // first entry of the next.
    Address scratch_addr(GetAddressRange().GetBaseAddress());
    scratch_addr.SetOffset (scratch_addr.GetOffset() + GetAddressRange().GetByteSize() - 1);
    
    LineTable *line_table = m_comp_unit->GetLineTable();
    if (line_table == nullptr)
        return;
        
    LineEntry line_entry;
    if (line_table->FindLineEntryByAddress (scratch_addr, line_entry, nullptr))
    {
        line_no = line_entry.line;
        source_file = line_entry.file;
    }
}

Block &
Function::GetBlock (bool can_create)
{
    if (!m_block.BlockInfoHasBeenParsed() && can_create)
    {
        SymbolContext sc;
        CalculateSymbolContext(&sc);
        if (sc.module_sp)
        {
            sc.module_sp->GetSymbolVendor()->ParseFunctionBlocks(sc);
        }
        else
        {
            Host::SystemLog (Host::eSystemLogError, 
                             "error: unable to find module shared pointer for function '%s' in %s\n", 
                             GetName().GetCString(),
                             m_comp_unit->GetPath().c_str());
        }
        m_block.SetBlockInfoHasBeenParsed (true, true);
    }
    return m_block;
}

CompileUnit*
Function::GetCompileUnit()
{
    return m_comp_unit;
}

const CompileUnit*
Function::GetCompileUnit() const
{
    return m_comp_unit;
}


void
Function::GetDescription(Stream *s, lldb::DescriptionLevel level, Target *target)
{
    Type* func_type = GetType();
    const char *name = func_type ? func_type->GetName().AsCString() : "<unknown>";
    
    *s << "id = " << (const UserID&)*this << ", name = \"" << name << "\", range = ";
    
    Address::DumpStyle fallback_style;
    if (level == eDescriptionLevelVerbose)
        fallback_style = Address::DumpStyleModuleWithFileAddress;
    else
        fallback_style = Address::DumpStyleFileAddress;
    GetAddressRange().Dump(s, target, Address::DumpStyleLoadAddress, fallback_style);
}

void
Function::Dump(Stream *s, bool show_context) const
{
    s->Printf("%p: ", static_cast<const void*>(this));
    s->Indent();
    *s << "Function" << static_cast<const UserID&>(*this);

    m_mangled.Dump(s);

    if (m_type)
        s->Printf(", type = %p", static_cast<void*>(m_type));
    else if (m_type_uid != LLDB_INVALID_UID)
        s->Printf(", type_uid = 0x%8.8" PRIx64, m_type_uid);

    s->EOL();
    // Dump the root object
    if (m_block.BlockInfoHasBeenParsed ())
        m_block.Dump(s, m_range.GetBaseAddress().GetFileAddress(), INT_MAX, show_context);
}


void
Function::CalculateSymbolContext(SymbolContext* sc)
{
    sc->function = this;
    m_comp_unit->CalculateSymbolContext(sc);
}

ModuleSP
Function::CalculateSymbolContextModule ()
{
    SectionSP section_sp (m_range.GetBaseAddress().GetSection());
    if (section_sp)
        return section_sp->GetModule();
    
    return this->GetCompileUnit()->GetModule();
}

CompileUnit *
Function::CalculateSymbolContextCompileUnit ()
{
    return this->GetCompileUnit();
}

Function *
Function::CalculateSymbolContextFunction ()
{
    return this;
}

lldb::DisassemblerSP
Function::GetInstructions (const ExecutionContext &exe_ctx,
                           const char *flavor,
                           bool prefer_file_cache)
{
    ModuleSP module_sp (GetAddressRange().GetBaseAddress().GetModule());
    if (module_sp)
    {
        const bool prefer_file_cache = false;
        return Disassembler::DisassembleRange (module_sp->GetArchitecture(),
                                               nullptr,
                                               flavor,
                                               exe_ctx,
                                               GetAddressRange(),
                                               prefer_file_cache);
    }
    return lldb::DisassemblerSP();
}

bool
Function::GetDisassembly (const ExecutionContext &exe_ctx,
                          const char *flavor,
                          bool prefer_file_cache,
                          Stream &strm)
{
    lldb::DisassemblerSP disassembler_sp = GetInstructions (exe_ctx, flavor, prefer_file_cache);
    if (disassembler_sp)
    {
        const bool show_address = true;
        const bool show_bytes = false;
        disassembler_sp->GetInstructionList().Dump (&strm, show_address, show_bytes, &exe_ctx);
        return true;
    }
    return false;
}


//Symbol *
//Function::CalculateSymbolContextSymbol ()
//{
//    return // TODO: find the symbol for the function???
//}


void
Function::DumpSymbolContext(Stream *s)
{
    m_comp_unit->DumpSymbolContext(s);
    s->Printf(", Function{0x%8.8" PRIx64 "}", GetID());
}

size_t
Function::MemorySize () const
{
    size_t mem_size = sizeof(Function) + m_block.MemorySize();
    return mem_size;
}

clang::DeclContext *
Function::GetClangDeclContext()
{
    SymbolContext sc;
    
    CalculateSymbolContext (&sc);
    
    if (!sc.module_sp)
        return nullptr;
    
    SymbolVendor *sym_vendor = sc.module_sp->GetSymbolVendor();
    
    if (!sym_vendor)
        return nullptr;
    
    SymbolFile *sym_file = sym_vendor->GetSymbolFile();
    
    if (!sym_file)
        return nullptr;
    
    return sym_file->GetClangDeclContextForTypeUID (sc, m_uid);
}

Type*
Function::GetType()
{
    if (m_type == nullptr)
    {
        SymbolContext sc;
        
        CalculateSymbolContext (&sc);
        
        if (!sc.module_sp)
            return nullptr;
        
        SymbolVendor *sym_vendor = sc.module_sp->GetSymbolVendor();
        
        if (sym_vendor == nullptr)
            return nullptr;
        
        SymbolFile *sym_file = sym_vendor->GetSymbolFile();
        
        if (sym_file == nullptr)
            return nullptr;
        
        m_type = sym_file->ResolveTypeUID(m_type_uid);
    }
    return m_type;
}

const Type*
Function::GetType() const
{
    return m_type;
}

ClangASTType
Function::GetClangType()
{
    Type *function_type = GetType();
    if (function_type)
        return function_type->GetClangFullType();
    return ClangASTType();
}

uint32_t
Function::GetPrologueByteSize ()
{
    if (m_prologue_byte_size == 0 && m_flags.IsClear(flagsCalculatedPrologueSize))
    {
        m_flags.Set(flagsCalculatedPrologueSize);
        LineTable* line_table = m_comp_unit->GetLineTable ();
        if (line_table)
        {
            LineEntry first_line_entry;
            uint32_t first_line_entry_idx = UINT32_MAX;
            if (line_table->FindLineEntryByAddress(GetAddressRange().GetBaseAddress(), first_line_entry, &first_line_entry_idx))
            {
                // Make sure the first line entry isn't already the end of the prologue
                addr_t prologue_end_file_addr = LLDB_INVALID_ADDRESS;
                if (first_line_entry.is_prologue_end)
                {
                    prologue_end_file_addr = first_line_entry.range.GetBaseAddress().GetFileAddress();
                }
                else
                {
                    // Check the first few instructions and look for one that has
                    // is_prologue_end set to true.
                    const uint32_t last_line_entry_idx = first_line_entry_idx + 6;
                    for (uint32_t idx = first_line_entry_idx + 1; idx < last_line_entry_idx; ++idx)
                    {
                        LineEntry line_entry;
                        if (line_table->GetLineEntryAtIndex (idx, line_entry))
                        {
                            if (line_entry.is_prologue_end)
                            {
                                prologue_end_file_addr = line_entry.range.GetBaseAddress().GetFileAddress();
                                break;
                            }
                        }
                    }
                }

                // If we didn't find the end of the prologue in the line tables,
                // then just use the end address of the first line table entry
                if (prologue_end_file_addr == LLDB_INVALID_ADDRESS)
                {
                    // Check the first few instructions and look for one that has
                    // a line number that's different than the first entry.
                    const uint32_t last_line_entry_idx = first_line_entry_idx + 6;
                    for (uint32_t idx = first_line_entry_idx + 1; idx < last_line_entry_idx; ++idx)
                    {
                        LineEntry line_entry;
                        if (line_table->GetLineEntryAtIndex (idx, line_entry))
                        {
                            if (line_entry.line != first_line_entry.line)
                            {
                                prologue_end_file_addr = line_entry.range.GetBaseAddress().GetFileAddress();
                                break;
                            }
                        }
                    }

                    if (prologue_end_file_addr == LLDB_INVALID_ADDRESS)
                    {
                        prologue_end_file_addr = first_line_entry.range.GetBaseAddress().GetFileAddress() + first_line_entry.range.GetByteSize();
                    }
                }
                const addr_t func_start_file_addr = m_range.GetBaseAddress().GetFileAddress();
                const addr_t func_end_file_addr = func_start_file_addr + m_range.GetByteSize();

                // Verify that this prologue end file address in the function's
                // address range just to be sure
                if (func_start_file_addr < prologue_end_file_addr && prologue_end_file_addr < func_end_file_addr)
                {
                    m_prologue_byte_size = prologue_end_file_addr - func_start_file_addr;
                }
            }
        }
    }
    return m_prologue_byte_size;
}



