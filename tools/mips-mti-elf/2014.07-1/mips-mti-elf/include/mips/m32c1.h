/*
 * Copyright (c) 2014, Imagination Technologies LLC and Imagination
 * Technologies Limited. 
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted under the terms of the MIPS Free To Use 1.0 
 * license that you will have received with this package. If you haven't 
 * received this file, please contact Imagination Technologies or see the 
 * following URL for details.
 * http://codescape-mips-sdk.imgtec.com/license/IMG-free-to-use-on-MIPS-license
 *
 */


/*
 * m32c1.h : MIPS32 coprocessor 1 (fpu) definitions
 */


#ifndef _M32C1_H_
#ifdef __cplusplus
extern "C" {
#endif
#define _M32C1_H_

#ifndef __ASSEMBLER__

#if __mips == 64 || __mipsfp64
typedef unsigned long long _fpreg_t;
#else
typedef unsigned long _fpreg_t;
#endif

struct fpactx {
    unsigned	sr;		/* floating-point status register */
    unsigned	dummy;		
    _fpreg_t	regs[32];	/* floating-point registers $f0-$f31 */
#if __mips == 64 || __mipsfp64
    _fpreg_t	acl;		/* MDMX accumulator (low 64 bits) */
    _fpreg_t	acm;		/* MDMX accumulator (middle 64 bits) */
    _fpreg_t	ach;		/* MDMX accumulator (high 64 bits) */
#endif
};

#ifdef __STDC__
int	 fpa_enable(int);	/* enable fpa, return 1 if present (always) */
unsigned fpa_getrid(void);	/* get fpa revision id */
unsigned fpa_getsr(void);	/* get fpa status register */
void	 fpa_setsr(unsigned);
unsigned fpa_xchsr(unsigned);
unsigned fpa_bicsr(unsigned);
unsigned fpa_bissr(unsigned);
void	fpa_save(struct fpactx *);
void	fpa_restore(const struct fpactx *);
#else
int	 fpa_enable();
unsigned fpa_getrid();
unsigned fpa_getsr();
void	 fpa_setsr();
unsigned fpa_xchsr();
unsigned fpa_bicsr();
unsigned fpa_bissr();
void	fpa_save();
void	fpa_restore();
#endif /* __STDC__ */



/* 
 * Define macros to accessing the Coprocessor 1 control registers.
 * Most apart from "set" return the original register value.
 */

#define fpa_getrid() \
__extension__({ \
  register unsigned __r; \
  __asm__ __volatile ("cfc1 %0,$0" : "=d" (__r)); \
  __r; \
})

#define fpa_getfir() fpa_getrid()

#define fpa_getsr() \
__extension__({ \
  register unsigned __r; \
  __asm__ __volatile ("cfc1 %0,$31" : "=d" (__r)); \
  __r; \
})

#define fpa_setsr(val) \
__extension__({ \
    register unsigned __r = (val); \
    __asm__ __volatile ("ctc1 %0,$31" : : "d" (__r)); \
    __r; \
})

#define fpa_xchsr(val) \
__extension__({ \
    register unsigned __o, __n = (val); \
    __asm__ __volatile ("cfc1 %0,$31" : "=d" (__o)); \
    __asm__ __volatile ("ctc1 %0,$31" : : "d" (__n)); \
    __o; \
})


#define fpa_bissr(val) \
__extension__({ \
    register unsigned __o, __n; \
    __asm__ __volatile ("cfc1 %0,$31" : "=d" (__o)); \
    __n = __o | (val); \
    __asm__ __volatile ("ctc1 %0,$31" : : "d" (__n)); \
    __o; \
})


#define fpa_bicsr(val) \
__extension__({ \
    register unsigned __o, __n; \
    __asm__ __volatile ("cfc1 %0,$31" : "=d" (__o)); \
    __n = __o &~ (val); \
    __asm__ __volatile ("ctc1 %0,$31" : : "d" (__n)); \
    __o; \
})



#endif /* !ASSEMBLER */

/* 
 * FCSR - FPU Control & Status Register 
 */
#define FPA_CSR_MD0	0x00200000	/* machine dependent */
#define FPA_CSR_MD1	0x00400000	/* machine dependent */
#define FPA_CSR_COND	0x00800000	/* $fcc0 */
#define FPA_CSR_COND0	0x00800000	/* $fcc0 */
#define FPA_CSR_FLUSH	0x01000000	/* flush to 0 */
#define FPA_CSR_FS	0x01000000	/* flush to 0 */
#define FPA_CSR_COND1	0x02000000	/* $fcc1 */
#define FPA_CSR_COND2	0x04000000	/* $fcc2 */
#define FPA_CSR_COND3	0x08000000	/* $fcc3 */
#define FPA_CSR_COND4	0x10000000	/* $fcc4 */
#define FPA_CSR_COND5	0x20000000	/* $fcc5 */
#define FPA_CSR_COND6	0x40000000	/* $fcc6 */
#define FPA_CSR_COND7	0x80000000	/* $fcc7 */

/*
 * X the exception cause indicator
 * E the exception enable
 * S the sticky/flag bit
*/
#define FPA_CSR_ALL_X 0x0003f000
#define FPA_CSR_UNI_X	0x00020000
#define FPA_CSR_INV_X	0x00010000
#define FPA_CSR_DIV_X	0x00008000
#define FPA_CSR_OVF_X	0x00004000
#define FPA_CSR_UDF_X	0x00002000
#define FPA_CSR_INE_X	0x00001000

#define FPA_CSR_ALL_E	0x00000f80
#define FPA_CSR_INV_E	0x00000800
#define FPA_CSR_DIV_E	0x00000400
#define FPA_CSR_OVF_E	0x00000200
#define FPA_CSR_UDF_E	0x00000100
#define FPA_CSR_INE_E	0x00000080

#define FPA_CSR_ALL_S	0x0000007c
#define FPA_CSR_INV_S	0x00000040
#define FPA_CSR_DIV_S	0x00000020
#define FPA_CSR_OVF_S	0x00000010
#define FPA_CSR_UDF_S	0x00000008
#define FPA_CSR_INE_S	0x00000004

/* rounding mode */
#define FPA_CSR_RN	0x0	/* nearest */
#define FPA_CSR_RZ	0x1	/* towards zero */
#define FPA_CSR_RU	0x2	/* towards +Infinity */
#define FPA_CSR_RD	0x3	/* towards -Infinity */

/* FPU Implementation Register */
#define FPA_FIR_F64	0x00400000	/* implements 64-bits registers */
#define FPA_FIR_L	0x00200000	/* implements long fixed point */
#define FPA_FIR_W	0x00100000	/* implements word fixed point */
#define FPA_FIR_3D	0x00080000	/* implements MIPS-3D ASE */
#define FPA_FIR_PS	0x00040000	/* implements paired-single format */
#define FPA_FIR_D	0x00020000	/* implements double format */
#define FPA_FIR_S	0x00010000	/* implements single format */
#define FPA_FIR_PRID	0x0000ff00	/* ProcessorID */
#define FPA_FIR_REV	0x000000ff	/* Revision */

#ifdef __ASSEMBLER__

	.struct 0
FPACTX_SR:	.word	0
FPACTX_DUMMY:	.word	0
#if __mips == 64 || __mipsfp64
FPACTX_REGS:	.dword	0:32
FPACTX_ACL:	.dword	0
FPACTX_ACM:	.dword	0
FPACTX_ACH:	.dword	0
#define FPACTX_RSIZE	8
#else
FPACTX_REGS:	.word	0:32
#define FPACTX_RSIZE	4
#endif

	.previous

/* control regs */
	$fir =		$0
	$fccr =		$25
	$fexr =		$26
	$fenr =		$28
	$fcsr  =	$31

/* backwards compat */
	$fpa_rid =	$0
	$fpa_sr  =	$31
#endif

#ifdef __cplusplus
}
#endif

#endif /*_M32C1_H_*/
