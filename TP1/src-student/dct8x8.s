	.file	"dct8x8.c"
	.text
	.p2align 4,,15
	.globl	_Z17slow_float_dct8x8PA8_sS0_
	.type	_Z17slow_float_dct8x8PA8_sS0_, @function
_Z17slow_float_dct8x8PA8_sS0_:
.LFB26:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$280, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	call	mcount
	movsd	.LC1(%rip), %xmm5
	leaq	-176(%rbp), %rax
	movq	%rdi, -280(%rbp)
	movq	%rsi, -312(%rbp)
	movsd	%xmm5, -200(%rbp)
	movq	$Av, -296(%rbp)
	movl	$0, -288(%rbp)
	movq	%rax, -304(%rbp)
	movl	$0, -284(%rbp)
	.p2align 4,,10
	.p2align 3
.L2:
	movl	-284(%rbp), %r15d
	leal	(%r15,%r15,2), %ebx
	leal	0(,%r15,8), %r12d
	cvtsi2sd	%ebx, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	leal	(%r15,%r15,4), %eax
	movsd	%xmm0, -216(%rbp)
	cvtsi2sd	%eax, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movl	%r12d, %edi
	movsd	%xmm0, -248(%rbp)
	addl	%r15d, %r12d
	subl	%r15d, %edi
	cvtsi2sd	%edi, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movsd	%xmm0, -240(%rbp)
	cvtsi2sd	%r12d, %xmm0
	xorl	%r12d, %r12d
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movsd	%xmm0, -232(%rbp)
	cvtsi2sd	-288(%rbp), %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	leal	(%r15,%rbx,4), %eax
	movsd	%xmm0, -224(%rbp)
	cvtsi2sd	%eax, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movl	%r15d, %eax
	movsd	%xmm0, -208(%rbp)
	sall	$4, %eax
	subl	%r15d, %eax
	cvtsi2sd	%eax, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movq	-304(%rbp), %rax
	movsd	%xmm0, -256(%rbp)
	movsd	.LC1(%rip), %xmm0
	movq	%rax, -264(%rbp)
	movq	-296(%rbp), %rax
	movq	%rax, -272(%rbp)
	.p2align 4,,10
	.p2align 3
.L7:
	movss	(%rax), %xmm4
	leal	(%r12,%r12), %ebx
	movq	-280(%rbp), %r14
	xorl	%r15d, %r15d
	xorpd	%xmm1, %xmm1
	cvtps2pd	%xmm4, %xmm4
	leal	(%rbx,%r12), %r13d
	movsd	%xmm4, -192(%rbp)
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L3:
	cvtsi2sd	%r13d, %xmm0
	addl	%ebx, %r13d
	movsd	%xmm1, -184(%rbp)
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movsd	-184(%rbp), %xmm1
.L5:
	movswl	(%r14), %esi
	mulsd	-192(%rbp), %xmm0
	addl	$1, %r15d
	movsd	-200(%rbp), %xmm2
	addq	$16, %r14
	cvtsi2sd	%esi, %xmm3
	movswl	-14(%r14), %esi
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	%esi, %xmm3
	movswl	-12(%r14), %esi
	addsd	%xmm1, %xmm2
	movsd	-216(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	%xmm3, %xmm1
	cvtsi2sd	%esi, %xmm3
	movswl	-10(%r14), %esi
	addsd	%xmm1, %xmm2
	movsd	-248(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	%xmm3, %xmm1
	cvtsi2sd	%esi, %xmm3
	movswl	-8(%r14), %esi
	addsd	%xmm2, %xmm1
	movsd	-240(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	%esi, %xmm3
	movswl	-6(%r14), %esi
	addsd	%xmm1, %xmm2
	movsd	-232(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	%xmm3, %xmm1
	cvtsi2sd	%esi, %xmm3
	movswl	-4(%r14), %esi
	addsd	%xmm2, %xmm1
	movsd	-224(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	%esi, %xmm3
	movswl	-2(%r14), %esi
	cmpl	$8, %r15d
	addsd	%xmm1, %xmm2
	movsd	-208(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	-256(%rbp), %xmm0
	mulsd	%xmm3, %xmm1
	addsd	%xmm2, %xmm1
	cvtsi2sd	%esi, %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	jne	.L3
	cvttsd2si	%xmm1, %eax
	movq	-264(%rbp), %rdx
	addl	$1, %r12d
	addq	$32, -272(%rbp)
	addq	$16, -264(%rbp)
	cmpl	$8, %r12d
	movw	%ax, (%rdx)
	je	.L4
	cvtsi2sd	%r12d, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movq	-272(%rbp), %rax
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L4:
	addl	$1, -284(%rbp)
	addl	$11, -288(%rbp)
	addq	$4, -296(%rbp)
	addq	$2, -304(%rbp)
	cmpl	$8, -284(%rbp)
	je	.L6
	cvtsi2sd	-284(%rbp), %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movsd	%xmm0, -200(%rbp)
	jmp	.L2
.L6:
	movq	-176(%rbp), %rax
	movq	-312(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-168(%rbp), %rax
	movq	%rax, 8(%rcx)
	movq	-160(%rbp), %rax
	movq	%rax, 16(%rcx)
	movq	-152(%rbp), %rax
	movq	%rax, 24(%rcx)
	movq	-144(%rbp), %rax
	movq	%rax, 32(%rcx)
	movq	-136(%rbp), %rax
	movq	%rax, 40(%rcx)
	movq	-128(%rbp), %rax
	movq	%rax, 48(%rcx)
	movq	-120(%rbp), %rax
	movq	%rax, 56(%rcx)
	movq	-112(%rbp), %rax
	movq	%rax, 64(%rcx)
	movq	-104(%rbp), %rax
	movq	%rax, 72(%rcx)
	movq	-96(%rbp), %rax
	movq	%rax, 80(%rcx)
	movq	-88(%rbp), %rax
	movq	%rax, 88(%rcx)
	movq	-80(%rbp), %rax
	movq	%rax, 96(%rcx)
	movq	-72(%rbp), %rax
	movq	%rax, 104(%rcx)
	movq	-64(%rbp), %rax
	movq	%rax, 112(%rcx)
	movq	-56(%rbp), %rax
	movq	%rax, 120(%rcx)
	addq	$280, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE26:
	.size	_Z17slow_float_dct8x8PA8_sS0_, .-_Z17slow_float_dct8x8PA8_sS0_
	.p2align 4,,15
	.globl	dct8x8
	.type	dct8x8, @function
dct8x8:
.LFB25:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	mcount
	popq	%rbp
	.cfi_def_cfa 7, 8
	jmp	_Z17slow_float_dct8x8PA8_sS0_
	.cfi_endproc
.LFE25:
	.size	dct8x8, .-dct8x8
	.p2align 4,,15
	.globl	_Z17fast_float_dct8x8PA8_sS0_
	.type	_Z17fast_float_dct8x8PA8_sS0_, @function
_Z17fast_float_dct8x8PA8_sS0_:
.LFB27:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	mcount
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE27:
	.size	_Z17fast_float_dct8x8PA8_sS0_, .-_Z17fast_float_dct8x8PA8_sS0_
	.p2align 4,,15
	.globl	_Z15slow_float_dct8PfS_
	.type	_Z15slow_float_dct8PfS_, @function
_Z15slow_float_dct8PfS_:
.LFB28:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	call	mcount
	movsd	.LC1(%rip), %xmm4
	xorl	%ebx, %ebx
	movq	%rdi, %r12
	movq	%rsi, %r13
	movapd	%xmm4, %xmm6
	movapd	%xmm4, %xmm7
	movapd	%xmm4, %xmm8
	movapd	%xmm4, %xmm9
	movapd	%xmm4, %xmm10
	movapd	%xmm4, %xmm5
	movapd	%xmm4, %xmm3
	jmp	.L14
	.p2align 4,,10
	.p2align 3
.L17:
	cvtsi2sd	%ebx, %xmm0
	leal	(%rbx,%rbx,2), %r14d
	leal	(%rbx,%rbx,4), %r15d
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movsd	%xmm0, -104(%rbp)
	cvtsi2sd	%r14d, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movsd	%xmm0, -96(%rbp)
	cvtsi2sd	%r15d, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	leal	0(,%rbx,8), %eax
	movsd	%xmm0, -88(%rbp)
	movl	%eax, %edx
	movl	%eax, -56(%rbp)
	subl	%ebx, %edx
	cvtsi2sd	%edx, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movl	-56(%rbp), %eax
	movsd	%xmm0, -80(%rbp)
	addl	%ebx, %eax
	cvtsi2sd	%eax, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	leal	(%rbx,%r15,2), %eax
	movsd	%xmm0, -72(%rbp)
	cvtsi2sd	%eax, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	leal	(%rbx,%r14,4), %eax
	movsd	%xmm0, -64(%rbp)
	cvtsi2sd	%eax, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movl	%ebx, %eax
	movsd	%xmm0, -56(%rbp)
	sall	$4, %eax
	subl	%ebx, %eax
	cvtsi2sd	%eax, %xmm0
	mulsd	.LC2(%rip), %xmm0
	mulsd	.LC3(%rip), %xmm0
	call	cos
	movsd	-56(%rbp), %xmm6
	movapd	%xmm0, %xmm4
	movsd	-64(%rbp), %xmm7
	movsd	-72(%rbp), %xmm8
	movsd	-80(%rbp), %xmm9
	movsd	-88(%rbp), %xmm10
	movsd	-96(%rbp), %xmm5
	movsd	-104(%rbp), %xmm3
.L14:
	testl	%ebx, %ebx
	je	.L16
	movss	.LC5(%rip), %xmm1
.L12:
	movss	(%r12), %xmm2
	addl	$1, %ebx
	mulss	%xmm1, %xmm2
	movss	4(%r12), %xmm0
	mulss	%xmm1, %xmm0
	addq	$4, %r13
	unpcklps	%xmm2, %xmm2
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm2, %xmm2
	cvtps2pd	%xmm0, %xmm0
	mulsd	%xmm3, %xmm2
	xorpd	%xmm3, %xmm3
	mulsd	%xmm5, %xmm0
	addsd	%xmm3, %xmm2
	movss	12(%r12), %xmm3
	mulss	%xmm1, %xmm3
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	mulsd	%xmm9, %xmm3
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm0, %xmm2
	movss	8(%r12), %xmm0
	mulss	%xmm1, %xmm0
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm0, %xmm0
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm0, %xmm0
	mulsd	%xmm10, %xmm0
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm0, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	16(%r12), %xmm3
	mulss	%xmm1, %xmm3
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	mulsd	%xmm8, %xmm3
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	20(%r12), %xmm3
	mulss	%xmm1, %xmm3
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	mulsd	%xmm7, %xmm3
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	24(%r12), %xmm3
	mulss	%xmm1, %xmm3
	mulss	28(%r12), %xmm1
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	unpcklps	%xmm1, %xmm1
	mulsd	%xmm6, %xmm3
	cvtps2pd	%xmm1, %xmm1
	unpcklps	%xmm2, %xmm2
	mulsd	%xmm4, %xmm1
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm1, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm0
	mulss	.LC6(%rip), %xmm0
	movss	%xmm0, -4(%r13)
	cmpl	$8, %ebx
	jne	.L17
	addq	$72, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L16:
	.cfi_restore_state
	movss	.LC4(%rip), %xmm1
	jmp	.L12
	.cfi_endproc
.LFE28:
	.size	_Z15slow_float_dct8PfS_, .-_Z15slow_float_dct8PfS_
	.p2align 4,,15
	.globl	_Z15fast_float_dct8PfS_
	.type	_Z15fast_float_dct8PfS_, @function
_Z15fast_float_dct8PfS_:
.LFB29:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	mcount
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE29:
	.size	_Z15fast_float_dct8PfS_, .-_Z15fast_float_dct8PfS_
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
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1072693248
	.align 8
.LC2:
	.long	776530087
	.long	1074340351
	.align 8
.LC3:
	.long	0
	.long	1068498944
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC4:
	.long	1060439284
	.align 4
.LC5:
	.long	1065353216
	.align 4
.LC6:
	.long	1056964608
	.ident	"GCC: (GNU) 4.8.2 20131212 (Red Hat 4.8.2-7)"
	.section	.note.GNU-stack,"",@progbits
