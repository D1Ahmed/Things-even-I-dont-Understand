	.file	"q3.c"
	.text
	.globl	_f
	.def	_f;	.scl	2;	.type	32;	.endef
_f:
LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	sall	$2, %eax
	addl	$3, %eax
	movl	%eax, 8(%ebp)
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
