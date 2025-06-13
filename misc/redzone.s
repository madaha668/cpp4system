	.file	"redzone.cpp"
	.text
	.globl	_Z12demo_redzonev
	.type	_Z12demo_redzonev, @function
_Z12demo_redzonev:
.LFB0:
	.cfi_startproc
	subq	$16, %rsp
	.cfi_def_cfa_offset 24
	movb	$65, -120(%rsp)
	addq	$16, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z12demo_redzonev, .-_Z12demo_redzonev
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_Z12demo_redzonev
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 12.2.0-14+deb12u1) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
