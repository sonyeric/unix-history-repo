/*-
 * Copyright (c) 2009 Rui Paulo <rpaulo@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef _MACHINE_PMC_MDEP_H_
#define	_MACHINE_PMC_MDEP_H_

#define	PMC_MDEP_CLASS_INDEX_XSCALE	0
/*
 * On the ARM platform we support the following PMCs.
 *
 * XSCALE	Intel XScale processors
 */
#include <dev/hwpmc/hwpmc_xscale.h>

union pmc_md_op_pmcallocate {
	uint64_t	__pad[4];
};

/* Logging */
#define	PMCLOG_READADDR		PMCLOG_READ32
#define	PMCLOG_EMITADDR		PMCLOG_EMIT32

#ifdef	_KERNEL
union pmc_md_pmc {
	struct pmc_md_xscale_pmc	pm_xscale;
};

#define	PMC_TRAPFRAME_TO_PC(TF)	((TF)->tf_pc)
#define	PMC_TRAPFRAME_TO_FP(TF)	((TF)->tf_usr_lr)
#define	PMC_TRAPFRAME_TO_SP(TF)	((TF)->tf_usr_sp)

/*
 * Prototypes
 */
struct pmc_mdep *pmc_xscale_initialize(void);
void		pmc_xscale_finalize(struct pmc_mdep *_md);
#endif /* _KERNEL */

#endif /* !_MACHINE_PMC_MDEP_H_ */
