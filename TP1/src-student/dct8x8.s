	.file	"dct8x8.c"
	.text
	.p2align 4,,15
	.globl	_Z17slow_float_dct8x8PA8_sS0_
	.type	_Z17slow_float_dct8x8PA8_sS0_, @function
_Z17slow_float_dct8x8PA8_sS0_:
.LFB49:
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
.LFE49:
	.size	_Z17slow_float_dct8x8PA8_sS0_, .-_Z17slow_float_dct8x8PA8_sS0_
	.p2align 4,,15
	.globl	_Z15slow_float_dct8PfS_
	.type	_Z15slow_float_dct8PfS_, @function
_Z15slow_float_dct8PfS_:
.LFB52:
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
	jmp	.L12
	.p2align 4,,10
	.p2align 3
.L15:
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
.L12:
	testl	%ebx, %ebx
	je	.L14
	movss	.LC5(%rip), %xmm1
.L10:
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
	jne	.L15
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
.L14:
	.cfi_restore_state
	movss	.LC4(%rip), %xmm1
	jmp	.L10
	.cfi_endproc
.LFE52:
	.size	_Z15slow_float_dct8PfS_, .-_Z15slow_float_dct8PfS_
	.p2align 4,,15
	.globl	_Z15fast_float_dct8PfS_
	.type	_Z15fast_float_dct8PfS_, @function
_Z15fast_float_dct8PfS_:
.LFB53:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	mcount
	popq	%rbp
	.cfi_def_cfa 7, 8
	movss	24(%rdi), %xmm0
	movss	20(%rdi), %xmm3
	movss	4(%rdi), %xmm2
	movss	8(%rdi), %xmm4
	movaps	%xmm2, %xmm9
	movaps	%xmm4, %xmm11
	subss	%xmm0, %xmm2
	movss	(%rdi), %xmm5
	subss	%xmm3, %xmm4
	movaps	%xmm5, %xmm8
	movss	28(%rdi), %xmm6
	addss	%xmm0, %xmm9
	movss	12(%rdi), %xmm1
	subss	%xmm6, %xmm5
	unpcklps	%xmm2, %xmm2
	addss	%xmm6, %xmm8
	unpcklps	%xmm4, %xmm4
	addss	%xmm3, %xmm11
	movsd	.LC7(%rip), %xmm0
	cvtps2pd	%xmm2, %xmm2
	movaps	%xmm1, %xmm10
	movaps	%xmm8, %xmm3
	cvtps2pd	%xmm4, %xmm4
	mulsd	%xmm0, %xmm2
	movsd	.LC8(%rip), %xmm6
	movss	16(%rdi), %xmm7
	addss	%xmm7, %xmm10
	mulsd	%xmm4, %xmm6
	mulsd	%xmm0, %xmm4
	subss	%xmm7, %xmm1
	addsd	%xmm2, %xmm6
	addsd	%xmm2, %xmm4
	movaps	%xmm9, %xmm2
	addss	%xmm10, %xmm3
	addss	%xmm11, %xmm2
	subss	%xmm11, %xmm9
	unpcklpd	%xmm6, %xmm6
	unpcklpd	%xmm4, %xmm4
	subss	%xmm10, %xmm8
	unpcklps	%xmm3, %xmm3
	unpcklps	%xmm2, %xmm2
	cvtpd2ps	%xmm4, %xmm7
	cvtps2pd	%xmm3, %xmm3
	unpcklps	%xmm9, %xmm9
	cvtps2pd	%xmm2, %xmm2
	unpcklps	%xmm8, %xmm8
	mulsd	%xmm0, %xmm3
	cvtps2pd	%xmm9, %xmm9
	mulsd	%xmm0, %xmm2
	movss	.LC6(%rip), %xmm0
	movapd	%xmm3, %xmm4
	cvtps2pd	%xmm8, %xmm8
	addsd	%xmm2, %xmm4
	subsd	%xmm2, %xmm3
	movsd	.LC9(%rip), %xmm2
	cvtpd2ps	%xmm6, %xmm6
	unpcklpd	%xmm4, %xmm4
	unpcklpd	%xmm3, %xmm3
	cvtpd2ps	%xmm4, %xmm4
	mulss	%xmm0, %xmm4
	movss	%xmm4, (%rsi)
	cvtpd2ps	%xmm3, %xmm4
	movsd	.LC10(%rip), %xmm3
	mulsd	%xmm8, %xmm3
	mulss	%xmm0, %xmm4
	movss	%xmm4, 16(%rsi)
	movapd	%xmm9, %xmm4
	mulsd	%xmm2, %xmm4
	mulsd	%xmm8, %xmm2
	movaps	%xmm5, %xmm8
	addss	%xmm7, %xmm8
	addsd	%xmm3, %xmm4
	movsd	.LC11(%rip), %xmm3
	subss	%xmm5, %xmm7
	movss	.LC15(%rip), %xmm5
	mulsd	%xmm9, %xmm3
	unpcklps	%xmm8, %xmm8
	unpcklpd	%xmm4, %xmm4
	addsd	%xmm2, %xmm3
	cvtps2pd	%xmm8, %xmm8
	cvtpd2ps	%xmm4, %xmm4
	unpcklpd	%xmm3, %xmm3
	cvtpd2ps	%xmm3, %xmm3
	mulss	%xmm0, %xmm4
	movss	%xmm4, 8(%rsi)
	mulss	%xmm0, %xmm3
	movaps	%xmm1, %xmm0
	movsd	.LC12(%rip), %xmm4
	subss	%xmm6, %xmm1
	addss	%xmm6, %xmm0
	movss	%xmm3, 24(%rsi)
	movsd	.LC13(%rip), %xmm3
	unpcklps	%xmm0, %xmm0
	mulsd	%xmm8, %xmm3
	unpcklps	%xmm1, %xmm1
	cvtps2pd	%xmm0, %xmm0
	cvtps2pd	%xmm1, %xmm1
	movapd	%xmm0, %xmm2
	mulsd	.LC19(%rip), %xmm0
	mulsd	%xmm4, %xmm2
	mulsd	%xmm8, %xmm4
	addsd	%xmm3, %xmm2
	movsd	.LC14(%rip), %xmm3
	addsd	%xmm4, %xmm0
	mulsd	%xmm3, %xmm2
	mulsd	%xmm3, %xmm0
	unpcklpd	%xmm2, %xmm2
	unpcklpd	%xmm0, %xmm0
	cvtpd2ps	%xmm2, %xmm2
	movss	%xmm2, 4(%rsi)
	movaps	%xmm7, %xmm2
	movsd	.LC17(%rip), %xmm7
	xorps	%xmm5, %xmm2
	movsd	.LC16(%rip), %xmm5
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm6
	movapd	%xmm1, %xmm2
	mulsd	.LC18(%rip), %xmm1
	mulsd	%xmm5, %xmm2
	mulsd	%xmm6, %xmm7
	mulsd	%xmm6, %xmm5
	addsd	%xmm7, %xmm2
	addsd	%xmm5, %xmm1
	mulsd	%xmm3, %xmm2
	mulsd	%xmm3, %xmm1
	unpcklpd	%xmm2, %xmm2
	unpcklpd	%xmm1, %xmm1
	cvtpd2ps	%xmm2, %xmm7
	cvtpd2ps	%xmm1, %xmm5
	cvtpd2ps	%xmm0, %xmm1
	movss	%xmm7, 20(%rsi)
	movss	%xmm5, 12(%rsi)
	movss	%xmm1, 28(%rsi)
	ret
	.cfi_endproc
.LFE53:
	.size	_Z15fast_float_dct8PfS_, .-_Z15fast_float_dct8PfS_
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC20:
	.string	"%d\n"
	.text
	.p2align 4,,15
	.globl	_Z17fast_float_dct8x8PA8_sS0_
	.type	_Z17fast_float_dct8x8PA8_sS0_, @function
_Z17fast_float_dct8x8PA8_sS0_:
.LFB50:
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
	subq	$136, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	call	mcount
	xorl	%r12d, %r12d
	movq	%rsi, %r14
	movq	%rdi, %r13
	movq	%rsi, %rbx
	.p2align 4,,10
	.p2align 3
.L20:
	pxor	%xmm1, %xmm1
	leaq	-80(%rbp), %rsi
	movdqu	0(%r13), %xmm0
	leaq	-112(%rbp), %rdi
	addl	$1, %r12d
	addq	$16, %r13
	addq	$16, %rbx
	pcmpgtw	%xmm0, %xmm1
	movdqa	%xmm0, %xmm3
	punpckhwd	%xmm1, %xmm0
	punpcklwd	%xmm1, %xmm3
	cvtdq2ps	%xmm0, %xmm0
	movaps	%xmm0, -96(%rbp)
	cvtdq2ps	%xmm3, %xmm2
	movaps	%xmm2, -112(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-80(%rbp), %xmm1
	cvttss2si	%xmm1, %eax
	movss	-76(%rbp), %xmm2
	movss	-72(%rbp), %xmm3
	movss	-68(%rbp), %xmm4
	movss	-64(%rbp), %xmm5
	movss	-60(%rbp), %xmm6
	movss	-56(%rbp), %xmm7
	movss	-52(%rbp), %xmm8
	movw	%ax, -16(%rbx)
	cvttss2si	%xmm2, %eax
	movw	%ax, -14(%rbx)
	cvttss2si	%xmm3, %eax
	movw	%ax, -12(%rbx)
	cvttss2si	%xmm4, %eax
	movw	%ax, -10(%rbx)
	cvttss2si	%xmm5, %eax
	movw	%ax, -8(%rbx)
	cvttss2si	%xmm6, %eax
	movw	%ax, -6(%rbx)
	cvttss2si	%xmm7, %eax
	movw	%ax, -4(%rbx)
	cvttss2si	%xmm8, %eax
	movw	%ax, -2(%rbx)
	cmpl	$8, %r12d
	jne	.L20
	leaq	16(%r14), %rax
	xorl	%r13d, %r13d
	movq	%rax, -120(%rbp)
	movq	%rax, %r12
	leaq	32(%r14), %rax
	movq	%rax, -152(%rbp)
	leaq	48(%r14), %rax
	movq	%rax, -128(%rbp)
	leaq	64(%r14), %rax
	movq	%rax, -144(%rbp)
	leaq	80(%r14), %rax
	movq	%rax, -168(%rbp)
	leaq	96(%r14), %rax
	movq	%rax, -136(%rbp)
	leaq	112(%r14), %rax
	movq	%rax, -160(%rbp)
	.p2align 4,,10
	.p2align 3
.L19:
	movswl	-16(%r12), %eax
	movq	-120(%rbp), %rcx
	leaq	-80(%rbp), %rsi
	leaq	-112(%rbp), %rdi
	leaq	-16(%r12), %rbx
	xorl	%r15d, %r15d
	cvtsi2ss	%eax, %xmm0
	movq	%r12, %rax
	subq	%r14, %rax
	movswl	-16(%rax,%rcx), %edx
	movq	-152(%rbp), %rcx
	movss	%xmm0, -112(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	-16(%rax,%rcx), %edx
	movq	-128(%rbp), %rcx
	movss	%xmm0, -108(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	-16(%rax,%rcx), %edx
	movq	-144(%rbp), %rcx
	movss	%xmm0, -104(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	-16(%rax,%rcx), %edx
	movq	-168(%rbp), %rcx
	movss	%xmm0, -100(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	-16(%rax,%rcx), %edx
	movq	-136(%rbp), %rcx
	movss	%xmm0, -96(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	-16(%rax,%rcx), %edx
	movq	-160(%rbp), %rcx
	movswl	-16(%rax,%rcx), %eax
	movss	%xmm0, -92(%rbp)
	cvtsi2ss	%edx, %xmm0
	movss	%xmm0, -88(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -84(%rbp)
	call	_Z15fast_float_dct8PfS_
	.p2align 4,,10
	.p2align 3
.L23:
	movss	-80(%rbp,%r15), %xmm0
	xorl	%eax, %eax
	cvttss2si	%xmm0, %edx
	movl	$.LC20, %esi
	movl	$1, %edi
	movw	%dx, (%rbx,%r15,4)
	movswl	%dx, %edx
	addq	$4, %r15
	call	__printf_chk
	cmpq	$32, %r15
	jne	.L23
	addl	$1, %r13d
	addq	$2, %r12
	cmpl	$8, %r13d
	jne	.L19
	addq	$136, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE50:
	.size	_Z17fast_float_dct8x8PA8_sS0_, .-_Z17fast_float_dct8x8PA8_sS0_
	.p2align 4,,15
	.globl	_Z15fast_fixed_dct8PsS_
	.type	_Z15fast_fixed_dct8PsS_, @function
_Z15fast_fixed_dct8PsS_:
.LFB54:
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
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	call	mcount
	movswl	2(%rdi), %r8d
	movswl	4(%rdi), %r9d
	movswl	10(%rdi), %r11d
	movswl	12(%rdi), %r10d
	movswl	(%rdi), %ecx
	movswl	6(%rdi), %r15d
	movswl	8(%rdi), %r14d
	movswl	14(%rdi), %r13d
	sall	$15, %r8d
	sall	$15, %r9d
	sall	$15, %r11d
	sall	$15, %r10d
	leal	(%r9,%r11), %r12d
	leal	(%r8,%r10), %edx
	subl	%r11d, %r9d
	subl	%r10d, %r8d
	sarl	$10, %r9d
	sall	$15, %r15d
	sarl	$10, %r8d
	sall	$15, %r14d
	sall	$15, %r13d
	imull	$724, %r8d, %r10d
	sall	$15, %ecx
	leal	(%r15,%r14), %ebx
	imull	$-724, %r9d, %r11d
	leal	(%rcx,%r13), %eax
	addl	%r9d, %r8d
	movl	%r15d, %edi
	subl	%r13d, %ecx
	leal	(%rax,%rbx), %r9d
	subl	%ebx, %eax
	subl	%r14d, %edi
	addl	%r10d, %r11d
	sarl	$10, %eax
	imull	$724, %r8d, %r10d
	leal	(%rdx,%r12), %r8d
	sarl	$10, %r9d
	subl	%r12d, %edx
	sarl	$10, %r8d
	sarl	$10, %edx
	leal	(%r9,%r8), %ebx
	subl	%r8d, %r9d
	imull	$724, %r9d, %r9d
	imull	$946, %eax, %r8d
	sarl	$16, %r9d
	movw	%r9w, 8(%rsi)
	imull	$391, %edx, %r9d
	imull	$724, %ebx, %ebx
	addl	%r9d, %r8d
	sarl	$16, %ebx
	sarl	$16, %r8d
	imull	$-946, %edx, %edx
	movw	%r8w, 4(%rsi)
	movw	%bx, (%rsi)
	imull	$391, %eax, %eax
	popq	%rbx
	popq	%r12
	addl	%edx, %eax
	leal	(%rdi,%r11), %edx
	subl	%r11d, %edi
	sarl	$16, %eax
	sarl	$6, %edi
	movw	%ax, 12(%rsi)
	leal	(%rcx,%r10), %eax
	sarl	$6, %edx
	imull	$199, %edx, %r9d
	subl	%r10d, %ecx
	sarl	$6, %eax
	sarl	$6, %ecx
	popq	%r13
	imull	$1004, %eax, %r8d
	imull	$-1004, %edx, %edx
	popq	%r14
	addl	%r9d, %r8d
	sarl	$20, %r8d
	imull	$851, %edi, %r9d
	movw	%r8w, 2(%rsi)
	imull	$-568, %edi, %edi
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	imull	$568, %ecx, %r8d
	imull	$199, %eax, %eax
	addl	%r9d, %r8d
	imull	$851, %ecx, %ecx
	addl	%edx, %eax
	sarl	$20, %r8d
	sarl	$20, %eax
	movw	%r8w, 10(%rsi)
	movw	%ax, 14(%rsi)
	addl	%edi, %ecx
	sarl	$20, %ecx
	movw	%cx, 6(%rsi)
	ret
	.cfi_endproc
.LFE54:
	.size	_Z15fast_fixed_dct8PsS_, .-_Z15fast_fixed_dct8PsS_
	.p2align 4,,15
	.globl	_Z17fast_fixed_dct8x8PA8_sS0_
	.type	_Z17fast_fixed_dct8x8PA8_sS0_, @function
_Z17fast_fixed_dct8x8PA8_sS0_:
.LFB51:
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
	subq	$88, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	call	mcount
	xorl	%r12d, %r12d
	movq	%rsi, %r14
	movq	%rdi, %r13
	movq	%rsi, %rbx
	.p2align 4,,10
	.p2align 3
.L27:
	movdqu	0(%r13), %xmm0
	leaq	-64(%rbp), %rsi
	leaq	-80(%rbp), %rdi
	addl	$1, %r12d
	addq	$16, %r13
	movdqa	%xmm0, -80(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	addq	$16, %rbx
	movzwl	-64(%rbp), %eax
	movw	%ax, -16(%rbx)
	movzwl	-62(%rbp), %eax
	movw	%ax, -14(%rbx)
	movzwl	-60(%rbp), %eax
	movw	%ax, -12(%rbx)
	movzwl	-58(%rbp), %eax
	movw	%ax, -10(%rbx)
	movzwl	-56(%rbp), %eax
	movw	%ax, -8(%rbx)
	movzwl	-54(%rbp), %eax
	movw	%ax, -6(%rbx)
	movzwl	-52(%rbp), %eax
	movw	%ax, -4(%rbx)
	movzwl	-50(%rbp), %eax
	movw	%ax, -2(%rbx)
	cmpl	$8, %r12d
	jne	.L27
	leaq	16(%r14), %r15
	leaq	32(%r14), %r10
	leaq	48(%r14), %r9
	leaq	64(%r14), %r8
	leaq	80(%r14), %rcx
	leaq	96(%r14), %rdx
	leaq	112(%r14), %r13
	movq	%r15, %r12
	movl	$8, -124(%rbp)
	.p2align 4,,10
	.p2align 3
.L29:
	movzwl	-16(%r12), %esi
	movq	%r12, %rbx
	leaq	-80(%rbp), %rdi
	subq	%r14, %rbx
	movq	%r10, -120(%rbp)
	movq	%r9, -112(%rbp)
	movq	%r8, -104(%rbp)
	movq	%rcx, -96(%rbp)
	addq	$2, %r12
	movq	%rdx, -88(%rbp)
	movw	%si, -80(%rbp)
	movzwl	-16(%rbx,%r15), %esi
	movw	%si, -78(%rbp)
	movzwl	-16(%rbx,%r10), %esi
	movw	%si, -76(%rbp)
	movzwl	-16(%rbx,%r9), %esi
	movw	%si, -74(%rbp)
	movzwl	-16(%rbx,%r8), %esi
	movw	%si, -72(%rbp)
	movzwl	-16(%rbx,%rcx), %esi
	movw	%si, -70(%rbp)
	movzwl	-16(%rbx,%rdx), %esi
	movw	%si, -68(%rbp)
	movzwl	-16(%rbx,%r13), %esi
	movw	%si, -66(%rbp)
	leaq	-64(%rbp), %rsi
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-64(%rbp), %esi
	movq	-120(%rbp), %r10
	movq	-112(%rbp), %r9
	movq	-104(%rbp), %r8
	movq	-96(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movw	%si, -18(%r12)
	movzwl	-62(%rbp), %esi
	subl	$1, -124(%rbp)
	movw	%si, -16(%rbx,%r15)
	movzwl	-60(%rbp), %esi
	movw	%si, -16(%rbx,%r10)
	movzwl	-58(%rbp), %esi
	movw	%si, -16(%rbx,%r9)
	movzwl	-56(%rbp), %esi
	movw	%si, -16(%rbx,%r8)
	movzwl	-54(%rbp), %esi
	movw	%si, -16(%rbx,%rcx)
	movzwl	-52(%rbp), %esi
	movw	%si, -16(%rbx,%rdx)
	movzwl	-50(%rbp), %esi
	movw	%si, -16(%rbx,%r13)
	jne	.L29
	addq	$88, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE51:
	.size	_Z17fast_fixed_dct8x8PA8_sS0_, .-_Z17fast_fixed_dct8x8PA8_sS0_
	.p2align 4,,15
	.globl	dct8x8
	.type	dct8x8, @function
dct8x8:
.LFB48:
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
	subq	$88, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	call	mcount
	movl	$8, %r12d
	movq	%rsi, %r14
	movq	%rdi, %r13
	movq	%rsi, %rbx
	.p2align 4,,10
	.p2align 3
.L32:
	movdqu	0(%r13), %xmm0
	leaq	-64(%rbp), %rsi
	leaq	-80(%rbp), %rdi
	addq	$16, %r13
	addq	$16, %rbx
	movdqa	%xmm0, -80(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-64(%rbp), %eax
	movw	%ax, -16(%rbx)
	movzwl	-62(%rbp), %eax
	movw	%ax, -14(%rbx)
	movzwl	-60(%rbp), %eax
	movw	%ax, -12(%rbx)
	movzwl	-58(%rbp), %eax
	movw	%ax, -10(%rbx)
	movzwl	-56(%rbp), %eax
	movw	%ax, -8(%rbx)
	movzwl	-54(%rbp), %eax
	movw	%ax, -6(%rbx)
	movzwl	-52(%rbp), %eax
	movw	%ax, -4(%rbx)
	movzwl	-50(%rbp), %eax
	movw	%ax, -2(%rbx)
	subl	$1, %r12d
	jne	.L32
	leaq	16(%r14), %r15
	leaq	32(%r14), %r10
	leaq	48(%r14), %r9
	leaq	64(%r14), %r8
	leaq	80(%r14), %rcx
	leaq	96(%r14), %rdx
	leaq	112(%r14), %r13
	movq	%r15, %r12
	movl	$8, -124(%rbp)
	.p2align 4,,10
	.p2align 3
.L34:
	movzwl	-16(%r12), %esi
	movq	%r12, %rbx
	leaq	-80(%rbp), %rdi
	subq	%r14, %rbx
	movq	%r10, -120(%rbp)
	movq	%r9, -112(%rbp)
	movq	%r8, -104(%rbp)
	movq	%rcx, -96(%rbp)
	addq	$2, %r12
	movq	%rdx, -88(%rbp)
	movw	%si, -80(%rbp)
	movzwl	-16(%rbx,%r15), %esi
	movw	%si, -78(%rbp)
	movzwl	-16(%rbx,%r10), %esi
	movw	%si, -76(%rbp)
	movzwl	-16(%rbx,%r9), %esi
	movw	%si, -74(%rbp)
	movzwl	-16(%rbx,%r8), %esi
	movw	%si, -72(%rbp)
	movzwl	-16(%rbx,%rcx), %esi
	movw	%si, -70(%rbp)
	movzwl	-16(%rbx,%rdx), %esi
	movw	%si, -68(%rbp)
	movzwl	-16(%rbx,%r13), %esi
	movw	%si, -66(%rbp)
	leaq	-64(%rbp), %rsi
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-64(%rbp), %esi
	movq	-120(%rbp), %r10
	movq	-112(%rbp), %r9
	movq	-104(%rbp), %r8
	movq	-96(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movw	%si, -18(%r12)
	movzwl	-62(%rbp), %esi
	subl	$1, -124(%rbp)
	movw	%si, -16(%rbx,%r15)
	movzwl	-60(%rbp), %esi
	movw	%si, -16(%rbx,%r10)
	movzwl	-58(%rbp), %esi
	movw	%si, -16(%rbx,%r9)
	movzwl	-56(%rbp), %esi
	movw	%si, -16(%rbx,%r8)
	movzwl	-54(%rbp), %esi
	movw	%si, -16(%rbx,%rcx)
	movzwl	-52(%rbp), %esi
	movw	%si, -16(%rbx,%rdx)
	movzwl	-50(%rbp), %esi
	movw	%si, -16(%rbx,%r13)
	jne	.L34
	addq	$88, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE48:
	.size	dct8x8, .-dct8x8
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
	.section	.rodata.cst8
	.align 8
.LC7:
	.long	769658139
	.long	1072078992
	.align 8
.LC8:
	.long	769658139
	.long	-1075404656
	.align 8
.LC9:
	.long	1094014070
	.long	1071152596
	.align 8
.LC10:
	.long	3391993372
	.long	1072533612
	.align 8
.LC11:
	.long	3391993372
	.long	-1074950036
	.align 8
.LC12:
	.long	1807322238
	.long	1070135561
	.align 8
.LC13:
	.long	3172091046
	.long	1072652940
	.align 8
.LC14:
	.long	0
	.long	1071644672
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC15:
	.long	2147483648
	.long	0
	.long	0
	.long	0
	.section	.rodata.cst8
	.align 8
.LC16:
	.long	8246337
	.long	1072339794
	.align 8
.LC17:
	.long	3041524040
	.long	1071761231
	.align 8
.LC18:
	.long	3041524040
	.long	-1075722417
	.align 8
.LC19:
	.long	3172091046
	.long	-1074830708
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
