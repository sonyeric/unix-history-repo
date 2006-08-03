#! /bin/sh -
#	@(#)makesyscalls.sh	8.1 (Berkeley) 6/10/93
# $FreeBSD$

set -e

# name of compat options:
compat=COMPAT_43
compat4=COMPAT_FREEBSD4

# output files:
sysnames="syscalls.c"
sysproto="../sys/sysproto.h"
sysproto_h=_SYS_SYSPROTO_H_
syshdr="../sys/syscall.h"
sysmk="../sys/syscall.mk"
syssw="init_sysent.c"
syscallprefix="SYS_"
switchname="sysent"
namesname="syscallnames"
systrace="systrace_args.c"

# tmp files:
sysdcl="sysent.dcl.$$"
syscompat="sysent.compat.$$"
syscompatdcl="sysent.compatdcl.$$"
syscompat4="sysent.compat4.$$"
syscompat4dcl="sysent.compat4dcl.$$"
sysent="sysent.switch.$$"
sysinc="sysinc.switch.$$"
sysarg="sysarg.switch.$$"
sysprotoend="sysprotoend.$$"

trap "rm $sysdcl $syscompat $syscompatdcl $syscompat4 $syscompat4dcl $sysent $sysinc $sysarg $sysprotoend" 0

touch $sysdcl $syscompat $syscompatdcl $syscompat4 $syscompat4dcl $sysent $sysinc $sysarg $sysprotoend

case $# in
    0)	echo "usage: $0 input-file <config-file>" 1>&2
	exit 1
	;;
esac

if [ -n "$2" -a -f "$2" ]; then
	. $2
fi

sed -e '
s/\$//g
:join
	/\\$/{a\

	N
	s/\\\n//
	b join
	}
2,${
	/^#/!s/\([{}()*,]\)/ \1 /g
}
' < $1 | awk "
	BEGIN {
		sysdcl = \"$sysdcl\"
		sysproto = \"$sysproto\"
		sysprotoend = \"$sysprotoend\"
		sysproto_h = \"$sysproto_h\"
		syscompat = \"$syscompat\"
		syscompatdcl = \"$syscompatdcl\"
		syscompat4 = \"$syscompat4\"
		syscompat4dcl = \"$syscompat4dcl\"
		sysent = \"$sysent\"
		syssw = \"$syssw\"
		sysinc = \"$sysinc\"
		sysarg = \"$sysarg\"
		sysnames = \"$sysnames\"
		syshdr = \"$syshdr\"
		sysmk = \"$sysmk\"
		systrace = \"$systrace\"
		compat = \"$compat\"
		compat4 = \"$compat4\"
		syscallprefix = \"$syscallprefix\"
		switchname = \"$switchname\"
		namesname = \"$namesname\"
		infile = \"$1\"
		"'

		printf "/*\n * System call switch table.\n *\n" > syssw
		printf " * DO NOT EDIT-- this file is automatically generated.\n" > syssw
		printf " * $%s$\n", "FreeBSD" > syssw

		printf "/*\n * System call prototypes.\n *\n" > sysarg
		printf " * DO NOT EDIT-- this file is automatically generated.\n" > sysarg
		printf " * $%s$\n", "FreeBSD" > sysarg

		printf "\n#ifdef %s\n\n", compat > syscompat
		printf "\n#ifdef %s\n\n", compat4 > syscompat4

		printf "/*\n * System call names.\n *\n" > sysnames
		printf " * DO NOT EDIT-- this file is automatically generated.\n" > sysnames
		printf " * $%s$\n", "FreeBSD" > sysnames

		printf "/*\n * System call numbers.\n *\n" > syshdr
		printf " * DO NOT EDIT-- this file is automatically generated.\n" > syshdr
		printf " * $%s$\n", "FreeBSD" > syshdr
		printf "# FreeBSD system call names.\n" > sysmk
		printf "# DO NOT EDIT-- this file is automatically generated.\n" > sysmk
		printf "# $%s$\n", "FreeBSD" > sysmk

		printf "/*\n * System call argument to DTrace register array converstion.\n *\n" > systrace
		printf " * DO NOT EDIT-- this file is automatically generated.\n" > systrace
		printf " * $%s$\n", "FreeBSD" > systrace
	}
	NR == 1 {
		gsub("[$]FreeBSD: ", "", $0)
		gsub(" [$]", "", $0)

		printf " * created from%s\n */\n\n", $0 > syssw

		printf "\n/* The casts are bogus but will do for now. */\n" > sysent
		printf "struct sysent %s[] = {\n",switchname > sysent

		printf " * created from%s\n */\n\n", $0 > sysarg
		printf "#ifndef %s\n", sysproto_h > sysarg
		printf "#define\t%s\n\n", sysproto_h > sysarg
		printf "#include <sys/signal.h>\n" > sysarg
		printf "#include <sys/acl.h>\n" > sysarg
		printf "#include <posix4/_semaphore.h>\n" > sysarg
		printf "#include <sys/ucontext.h>\n\n" > sysarg
		printf "struct proc;\n\n" > sysarg
		printf "struct thread;\n\n" > sysarg
		printf "#define\tPAD_(t)\t(sizeof(register_t) <= sizeof(t) ? \\\n" > sysarg
		printf "\t\t0 : sizeof(register_t) - sizeof(t))\n\n" > sysarg
		printf "#if BYTE_ORDER == LITTLE_ENDIAN\n"> sysarg
		printf "#define\tPADL_(t)\t0\n" > sysarg
		printf "#define\tPADR_(t)\tPAD_(t)\n" > sysarg
		printf "#else\n" > sysarg
		printf "#define\tPADL_(t)\tPAD_(t)\n" > sysarg
		printf "#define\tPADR_(t)\t0\n" > sysarg
		printf "#endif\n\n" > sysarg

		printf " * created from%s\n */\n\n", $0 > sysnames
		printf "const char *%s[] = {\n", namesname > sysnames

		printf " * created from%s\n */\n\n", $0 > syshdr

		printf "# created from%s\nMIASM = ", $0 > sysmk

		printf " * This file is part of the DTrace syscall provider.\n */\n\n" > systrace
		printf "static void\nsystrace_args(int sysnum, void *params, u_int64_t *uarg, int *n_args)\n{\n" > systrace
		printf "\tint64_t *iarg  = (int64_t *) uarg;\n" > systrace
		printf "\tswitch (sysnum) {\n" > systrace

		next
	}
	NF == 0 || $1 ~ /^;/ {
		next
	}
	$1 ~ /^#[ 	]*include/ {
		print > sysinc
		next
	}
	$1 ~ /^#[ 	]*if/ {
		print > sysent
		print > sysdcl
		print > sysarg
		print > syscompat
		print > syscompat4
		print > sysnames
		savesyscall = syscall
		next
	}
	$1 ~ /^#[ 	]*else/ {
		print > sysent
		print > sysdcl
		print > sysarg
		print > syscompat
		print > syscompat4
		print > sysnames
		syscall = savesyscall
		next
	}
	$1 ~ /^#/ {
		print > sysent
		print > sysdcl
		print > sysarg
		print > syscompat
		print > syscompat4
		print > sysnames
		next
	}
	syscall != $1 {
		printf "%s: line %d: syscall number out of sync at %d\n",
		    infile, NR, syscall
		printf "line is:\n"
		print
		exit 1
	}
	function align_sysent_comment(column) {
		printf("\t") > sysent
		column = column + 8 - column % 8
		while (column < 56) {
			printf("\t") > sysent
			column = column + 8
		}
	}
	function parserr(was, wanted) {
		printf "%s: line %d: unexpected %s (expected %s)\n",
		    infile, NR, was, wanted
		exit 1
	}
	function parseline() {
		f=4			# toss number, type, audit event
		argc= 0;
		argssize = "0"
		if ($NF != "}") {
			funcalias=$(NF-2)
			argalias=$(NF-1)
			rettype=$NF
			end=NF-3
		} else {
			funcalias=""
			argalias=""
			rettype="int"
			end=NF
		}
		if ($3 == "NODEF") {
			auditev="AUE_NULL"
			funcname=$4
			argssize = "AS(" $6 ")"
			return
		}
		if ($f != "{")
			parserr($f, "{")
		f++
		if ($end != "}")
			parserr($end, "}")
		end--
		if ($end != ";")
			parserr($end, ";")
		end--
		if ($end != ")")
			parserr($end, ")")
		end--

		f++	#function return type

		funcname=$f
		if (funcalias == "")
			funcalias = funcname
		if (argalias == "") {
			argalias = funcname "_args"
			if ($3 == "COMPAT")
				argalias = "o" argalias
			if ($3 == "COMPAT4")
				argalias = "freebsd4_" argalias
		}
		f++

		if ($f != "(")
			parserr($f, ")")
		f++

		if (f == end) {
			if ($f != "void")
				parserr($f, "argument definition")
			return
		}

		while (f <= end) {
			argc++
			argtype[argc]=""
			oldf=""
			while (f < end && $(f+1) != ",") {
				if (argtype[argc] != "" && oldf != "*")
					argtype[argc] = argtype[argc]" ";
				argtype[argc] = argtype[argc]$f;
				oldf = $f;
				f++
			}
			if (argtype[argc] == "")
				parserr($f, "argument definition")
			argname[argc]=$f;
			f += 2;			# skip name, and any comma
		}
		if (argc != 0)
			argssize = "AS(" argalias ")"
	}
	{	comment = $4
		if (NF < 7)
			for (i = 5; i <= NF; i++)
				comment = comment " " $i
	}

	#
	# The AUE_ audit event identifier.
	#
	{
		auditev = $2;
	}

	$3 == "STD" || $3 == "NODEF" || $3 == "NOARGS"  || $3 == "NOPROTO" \
	    || $3 == "NOIMPL" || $3 == "NOSTD" {
		parseline()
		printf("\t/* %s */\n\tcase %d: {\n", funcname, syscall) > systrace
		if (argc > 0) {
			printf("\t\tstruct %s *p = params;\n", argalias) > systrace
			for (i = 1; i <= argc; i++) {
				if (index(argtype[i], "*") > 0 || argtype[i] == "caddr_t")
					printf("\t\tuarg[%d] = (intptr_t) p->%s; /* %s */\n", \
					     i - 1, \
					     argname[i], argtype[i]) > systrace
				else if (substr(argtype[i], 1, 1) == "u" || argtype[i] == "size_t")
					printf("\t\tuarg[%d] = p->%s; /* %s */\n", \
					     i - 1, \
					     argname[i], argtype[i]) > systrace
				else
					printf("\t\tiarg[%d] = p->%s; /* %s */\n", \
					     i - 1, \
					     argname[i], argtype[i]) > systrace
			}
		}
		printf("\t\t*n_args = %d;\n\t\tbreak;\n\t}\n", argc) > systrace
		if ((!nosys || funcname != "nosys") && \
		    (funcname != "lkmnosys") && (funcname != "lkmressys")) {
			if (argc != 0 && $3 != "NOARGS" && $3 != "NOPROTO") {
				printf("struct %s {\n", argalias) > sysarg
				for (i = 1; i <= argc; i++)
					printf("\tchar %s_l_[PADL_(%s)]; " \
					    "%s %s; char %s_r_[PADR_(%s)];\n",
					    argname[i], argtype[i],
					    argtype[i], argname[i],
					    argname[i], argtype[i]) > sysarg
				printf("};\n") > sysarg
			}
			else if ($3 != "NOARGS" && $3 != "NOPROTO" && \
			    $3 != "NODEF")
				printf("struct %s {\n\tregister_t dummy;\n};\n",
				    argalias) > sysarg
		}
		if (($3 != "NOPROTO" && $3 != "NODEF" && \
		    (funcname != "nosys" || !nosys)) || \
		    (funcname == "lkmnosys" && !lkmnosys) || \
		    funcname == "lkmressys") {
			printf("%s\t%s(struct thread *, struct %s *)",
			    rettype, funcname, argalias) > sysdcl
			printf(";\n") > sysdcl
		}
		if (funcname == "nosys")
			nosys = 1
		if (funcname == "lkmnosys")
			lkmnosys = 1
		printf("\t{ %s, (sy_call_t *)", argssize) > sysent
		column = 8 + 2 + length(argssize) + 15
		if ($3 == "NOIMPL") {
			printf("%s },", "nosys, AUE_NULL, NULL, 0, 0") > sysent
			column = column + length("nosys") + 3
		} else if ($3 == "NOSTD") {
			printf("%s },", "lkmressys, AUE_NULL, NULL, 0, 0") > sysent
			column = column + length("lkmressys") + 3
		} else {
			printf("%s, %s, NULL, 0, 0 },", funcname, auditev) > sysent
			column = column + length(funcname) + length(auditev) + 3
		} 
		align_sysent_comment(column)
		printf("/* %d = %s */\n", syscall, funcalias) > sysent
		printf("\t\"%s\",\t\t\t/* %d = %s */\n",
		    funcalias, syscall, funcalias) > sysnames
		if ($3 != "NODEF") {
			printf("#define\t%s%s\t%d\n", syscallprefix,
		    	    funcalias, syscall) > syshdr
			printf(" \\\n\t%s.o", funcalias) > sysmk
		}
		syscall++
		next
	}
	$3 == "COMPAT" || $3 == "COMPAT4" || $3 == "CPT_NOA" {
		if ($3 == "COMPAT" || $3 == "CPT_NOA") {
			ncompat++
			out = syscompat
			outdcl = syscompatdcl
			wrap = "compat"
			prefix = "o"
		} else if ($3 == "COMPAT4") {
			ncompat4++
			out = syscompat4
			outdcl = syscompat4dcl
			wrap = "compat4"
			prefix = "freebsd4_"
		}
		parseline()
		if (argc != 0 && $3 != "CPT_NOA") {
			printf("struct %s {\n", argalias) > out
			for (i = 1; i <= argc; i++)
				printf("\tchar %s_l_[PADL_(%s)]; %s %s; " \
				    "char %s_r_[PADR_(%s)];\n",
				    argname[i], argtype[i],
				    argtype[i], argname[i],
				    argname[i], argtype[i]) > out
			printf("};\n") > out
		}
		else if($3 != "CPT_NOA")
			printf("struct %s {\n\tregister_t dummy;\n};\n",
			    argalias) > sysarg
		printf("%s\t%s%s(struct thread *, struct %s *);\n",
		    rettype, prefix, funcname, argalias) > outdcl
		printf("\t{ %s(%s,%s), %s, NULL, 0, 0 },",
		    wrap, argssize, funcname, auditev) > sysent
		align_sysent_comment(8 + 9 + \
		    length(argssize) + 1 + length(funcname) + length(auditev) + 4)
		printf("/* %d = old %s */\n", syscall, funcalias) > sysent
		printf("\t\"old.%s\",\t\t/* %d = old %s */\n",
		    funcalias, syscall, funcalias) > sysnames
		printf("\t\t\t\t/* %d is old %s */\n",
		    syscall, funcalias) > syshdr
		syscall++
		next
	}
	$3 == "LIBCOMPAT" {
		ncompat++
		parseline()
		printf("%s\to%s();\n", rettype, funcname) > syscompatdcl
		printf("\t{ compat(%s,%s), %s, NULL, 0, 0 },",
		    argssize, funcname, auditev) > sysent
		align_sysent_comment(8 + 9 + \
		    length(argssize) + 1 + length(funcname) + length(auditev) + 4)
		printf("/* %d = old %s */\n", syscall, funcalias) > sysent
		printf("\t\"old.%s\",\t\t/* %d = old %s */\n",
		    funcalias, syscall, funcalias) > sysnames
		printf("#define\t%s%s\t%d\t/* compatibility; still used by libc */\n",
		    syscallprefix, funcalias, syscall) > syshdr
		printf(" \\\n\t%s.o", funcalias) > sysmk
		syscall++
		next
	}
	$3 == "OBSOL" {
		printf("\t{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0 },") > sysent
		align_sysent_comment(34)
		printf("/* %d = obsolete %s */\n", syscall, comment) > sysent
		printf("\t\"obs_%s\",\t\t\t/* %d = obsolete %s */\n",
		    $4, syscall, comment) > sysnames
		printf("\t\t\t\t/* %d is obsolete %s */\n",
		    syscall, comment) > syshdr
		syscall++
		next
	}
	$3 == "UNIMPL" {
		printf("\t{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0 },\t\t\t/* %d = %s */\n",
		    syscall, comment) > sysent
		printf("\t\"#%d\",\t\t\t/* %d = %s */\n",
		    syscall, syscall, comment) > sysnames
		syscall++
		next
	}
	{
		printf "%s: line %d: unrecognized keyword %s\n", infile, NR, $3
		exit 1
	}
	END {
		printf "\n#define AS(name) (sizeof(struct name) / sizeof(register_t))\n" > sysinc

		if (ncompat != 0 || ncompat4 != 0)
			printf "#include \"opt_compat.h\"\n\n" > syssw
		printf "#include \<bsm/audit_kevents.h\>\n" > syssw

		if (ncompat != 0) {
			printf "\n#ifdef %s\n", compat > sysinc
			printf "#define compat(n, name) n, (sy_call_t *)__CONCAT(o,name)\n" > sysinc
			printf "#else\n" > sysinc
			printf "#define compat(n, name) 0, (sy_call_t *)nosys\n" > sysinc
			printf "#endif\n" > sysinc
		}

		if (ncompat4 != 0) {
			printf "\n#ifdef %s\n", compat4 > sysinc
			printf "#define compat4(n, name) n, (sy_call_t *)__CONCAT(freebsd4_,name)\n" > sysinc
			printf "#else\n" > sysinc
			printf "#define compat4(n, name) 0, (sy_call_t *)nosys\n" > sysinc
			printf "#endif\n" > sysinc
		}

		printf("\n#endif /* %s */\n\n", compat) > syscompatdcl

		printf("\n#endif /* %s */\n\n", compat4) > syscompat4dcl

		printf("#undef PAD_\n") > sysprotoend
		printf("#undef PADL_\n") > sysprotoend
		printf("#undef PADR_\n") > sysprotoend
		printf("\n#endif /* !%s */\n", sysproto_h) > sysprotoend

		printf("\n") > sysmk
		printf("};\n") > sysent
		printf("};\n") > sysnames
		printf("#define\t%sMAXSYSCALL\t%d\n", syscallprefix, syscall) \
		    > syshdr
		printf "\tdefault:\n\t\t*n_args = 0;\n\t\tbreak;\n\t};\n}\n" > systrace
	} '

cat $sysinc $sysent >> $syssw
cat $sysarg $sysdcl \
	$syscompat $syscompatdcl \
	$syscompat4 $syscompat4dcl \
	$sysprotoend > $sysproto

