	.file	"dct8x8.c"
	.globl	Av
	.data
	.align 32
	.type	Av, @object
	.size	Av, 256
Av:
	.long	1040187392
	.long	1043662066
	.long	1043662066
	.long	1043662066
	.long	1043662066
	.long	1043662066
	.long	1043662066
	.long	1043662066
	.long	1043662066
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1043662066
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1043662066
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1043662066
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1043662066
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1043662066
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1043662066
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.long	1048576000
	.text
	.globl	dct8x8
	.type	dct8x8, @function
dct8x8:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	call	mcount
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z17slow_float_dct8x8PA8_sS0_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	dct8x8, .-dct8x8
	.globl	_Z17slow_float_dct8x8PA8_sS0_
	.type	_Z17slow_float_dct8x8PA8_sS0_, @function
_Z17slow_float_dct8x8PA8_sS0_:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$192, %rsp
	call	mcount
	movq	%rdi, -168(%rbp)
	movq	%rsi, -176(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L3
.L10:
	movl	$0, -12(%rbp)
	jmp	.L4
.L9:
	movl	$0, %eax
	movq	%rax, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L5
.L8:
	movl	$0, -8(%rbp)
	jmp	.L6
.L7:
	movl	-16(%rbp), %eax
	cltq
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movss	Av(,%rax,4), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm2
	movsd	%xmm2, -184(%rbp)
	movl	-4(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	imull	-12(%rbp), %eax
	cvtsi2sd	%eax, %xmm0
	movsd	.LC1(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	call	cos
	mulsd	-184(%rbp), %xmm0
	movsd	%xmm0, -184(%rbp)
	movl	-8(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	imull	-16(%rbp), %eax
	cvtsi2sd	%eax, %xmm0
	movsd	.LC1(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	call	cos
	movsd	-184(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-168(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	movzwl	(%rdx,%rax,2), %eax
	cwtl
	cvtsi2sd	%eax, %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-24(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	addl	$1, -8(%rbp)
.L6:
	cmpl	$7, -8(%rbp)
	jle	.L7
	addl	$1, -4(%rbp)
.L5:
	cmpl	$7, -4(%rbp)
	jle	.L8
	movsd	-24(%rbp), %xmm0
	cvttsd2si	%xmm0, %eax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	movl	-12(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$3, %rcx
	addq	%rcx, %rdx
	movw	%ax, -160(%rbp,%rdx,2)
	addl	$1, -12(%rbp)
.L4:
	cmpl	$7, -12(%rbp)
	jle	.L9
	addl	$1, -16(%rbp)
.L3:
	cmpl	$7, -16(%rbp)
	jle	.L10
	movl	$0, -16(%rbp)
	jmp	.L11
.L14:
	movl	$0, -12(%rbp)
	jmp	.L12
.L13:
	movl	-12(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-176(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movl	-16(%rbp), %eax
	cltq
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movzwl	-160(%rbp,%rax,2), %edx
	movl	-16(%rbp), %eax
	cltq
	movw	%dx, (%rcx,%rax,2)
	addl	$1, -12(%rbp)
.L12:
	cmpl	$7, -12(%rbp)
	jle	.L13
	addl	$1, -16(%rbp)
.L11:
	cmpl	$7, -16(%rbp)
	jle	.L14
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_Z17slow_float_dct8x8PA8_sS0_, .-_Z17slow_float_dct8x8PA8_sS0_
	.globl	_Z17fast_float_dct8x8PA8_sS0_
	.type	_Z17fast_float_dct8x8PA8_sS0_, @function
_Z17fast_float_dct8x8PA8_sS0_:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$272, %rsp
	call	mcount
	movq	%rdi, -264(%rbp)
	movq	%rsi, -272(%rbp)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_Z17fast_float_dct8x8PA8_sS0_, .-_Z17fast_float_dct8x8PA8_sS0_
	.globl	_Z15slow_float_dct8PfS_
	.type	_Z15slow_float_dct8PfS_, @function
_Z15slow_float_dct8PfS_:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	call	mcount
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_Z15slow_float_dct8PfS_, .-_Z15slow_float_dct8PfS_
	.globl	_Z15fast_float_dct8PfS_
	.type	_Z15fast_float_dct8PfS_, @function
_Z15fast_float_dct8PfS_:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	call	mcount
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_Z15fast_float_dct8PfS_, .-_Z15fast_float_dct8PfS_
	.section	.rodata
	.align 8
.LC1:
	.long	776530087
	.long	1074340351
	.align 8
.LC2:
	.long	0
	.long	1076887552
	.ident	"GCC: (GNU) 4.8.2 20131212 (Red Hat 4.8.2-7)"
	.section	.note.GNU-stack,"",@progbits
