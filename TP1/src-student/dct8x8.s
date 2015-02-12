	.file	"dct8x8.c"
	.text
	.p2align 4,,15
	.globl	_Z17slow_float_dct8x8PA8_sS0_
	.type	_Z17slow_float_dct8x8PA8_sS0_, @function
_Z17slow_float_dct8x8PA8_sS0_:
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
	subq	$616, %rsp
	call	mcount
	movabsq	$4607182418800017408, %r9
	movabsq	$4607182418800017408, %rax
	movabsq	$4607182418800017408, %rdx
	movq	%r9, -208(%rbp)
	movswl	10(%rdi), %r9d
	movabsq	$4607182418800017408, %rcx
	movq	%rsi, -584(%rbp)
	movabsq	$4607182418800017408, %r8
	movabsq	$4607182418800017408, %rsi
	movabsq	$4607182418800017408, %r10
	movabsq	$4607182418800017408, %r11
	movq	%rax, -248(%rbp)
	movq	%rdx, -240(%rbp)
	movswl	(%rdi), %eax
	movl	%r9d, -616(%rbp)
	movswl	12(%rdi), %r9d
	movswl	2(%rdi), %edx
	movq	%rcx, -232(%rbp)
	movq	%rsi, -224(%rbp)
	movswl	4(%rdi), %ecx
	movswl	6(%rdi), %esi
	movq	%r8, -216(%rbp)
	movl	%r9d, -620(%rbp)
	movswl	14(%rdi), %r9d
	movswl	8(%rdi), %r8d
	movq	$0, -272(%rbp)
	movl	$0, -608(%rbp)
	movl	$0, -604(%rbp)
	movl	$0, -596(%rbp)
	movl	$0, -588(%rbp)
	movl	%r9d, -624(%rbp)
	movswl	16(%rdi), %r9d
	movl	$0, -592(%rbp)
	movl	$0, -612(%rbp)
	movl	$0, -600(%rbp)
	movq	%r10, -200(%rbp)
	movq	%r11, -192(%rbp)
	movl	$0, -496(%rbp)
	movl	%r9d, -628(%rbp)
	movswl	18(%rdi), %r9d
	cvtsi2sd	%eax, %xmm1
	movl	%r9d, -444(%rbp)
	movswl	20(%rdi), %r9d
	movl	%r9d, -448(%rbp)
	movswl	22(%rdi), %r9d
	movl	%r9d, -452(%rbp)
	movswl	24(%rdi), %r9d
	movl	%r9d, -456(%rbp)
	movswl	26(%rdi), %r9d
	movl	%r9d, -460(%rbp)
	movswl	28(%rdi), %r9d
	movl	%r9d, -464(%rbp)
	movswl	30(%rdi), %r9d
	movl	%r9d, -468(%rbp)
	movswl	32(%rdi), %r9d
	movl	%r9d, -472(%rbp)
	movswl	34(%rdi), %r9d
	movl	%r9d, -476(%rbp)
	movswl	36(%rdi), %r9d
	movl	%r9d, -480(%rbp)
	movswl	38(%rdi), %r9d
	movl	%r9d, -484(%rbp)
	movswl	40(%rdi), %r9d
	movl	%r9d, -488(%rbp)
	movswl	42(%rdi), %r9d
	movl	%r9d, -492(%rbp)
	movswl	44(%rdi), %r9d
	movl	%r9d, -276(%rbp)
	movswl	46(%rdi), %r9d
	movl	%r9d, -280(%rbp)
	movswl	48(%rdi), %r9d
	movl	%r9d, -284(%rbp)
	movswl	50(%rdi), %r9d
	movl	%r9d, -288(%rbp)
	movswl	52(%rdi), %r9d
	movl	%r9d, -292(%rbp)
	movswl	54(%rdi), %r9d
	movl	%r9d, -296(%rbp)
	movswl	56(%rdi), %r9d
	movl	%r9d, -300(%rbp)
	movswl	58(%rdi), %r9d
	movl	%r9d, -304(%rbp)
	movswl	60(%rdi), %r9d
	movl	%r9d, -308(%rbp)
	movswl	62(%rdi), %r9d
	movl	%r9d, -312(%rbp)
	movswl	64(%rdi), %r9d
	movl	%r9d, -316(%rbp)
	movswl	66(%rdi), %r9d
	movl	%r9d, -320(%rbp)
	movswl	68(%rdi), %r9d
	movl	%r9d, -324(%rbp)
	movswl	70(%rdi), %r9d
	movl	%r9d, -328(%rbp)
	movswl	72(%rdi), %r9d
	movl	%r9d, -332(%rbp)
	movswl	74(%rdi), %r9d
	movl	%r9d, -336(%rbp)
	movswl	76(%rdi), %r9d
	movl	%r9d, -340(%rbp)
	movswl	78(%rdi), %r9d
	movl	%r9d, -344(%rbp)
	movswl	80(%rdi), %r9d
	movl	%r9d, -348(%rbp)
	movswl	82(%rdi), %r9d
	movl	%r9d, -352(%rbp)
	movswl	84(%rdi), %r9d
	movl	%r9d, -356(%rbp)
	movswl	86(%rdi), %r9d
	movl	%r9d, -360(%rbp)
	movswl	88(%rdi), %r9d
	movl	%r9d, -364(%rbp)
	movswl	90(%rdi), %r9d
	movl	%r9d, -368(%rbp)
	movswl	92(%rdi), %r9d
	movl	%r9d, -372(%rbp)
	movswl	94(%rdi), %r9d
	movl	%r9d, -376(%rbp)
	movswl	96(%rdi), %r9d
	movl	%r9d, -380(%rbp)
	movswl	98(%rdi), %r9d
	movl	%r9d, -384(%rbp)
	movswl	100(%rdi), %r9d
	movl	%r9d, -388(%rbp)
	movswl	102(%rdi), %r9d
	movl	%r9d, -392(%rbp)
	movswl	104(%rdi), %r9d
	movl	%r9d, -396(%rbp)
	movswl	106(%rdi), %r9d
	movl	%r9d, -400(%rbp)
	movswl	108(%rdi), %r9d
	movl	%r9d, -404(%rbp)
	movswl	110(%rdi), %r9d
	movl	%r9d, -408(%rbp)
	movswl	112(%rdi), %r9d
	movl	%r9d, -412(%rbp)
	movswl	114(%rdi), %r9d
	movl	%r9d, -416(%rbp)
	movswl	116(%rdi), %r9d
	movl	%r9d, -420(%rbp)
	movswl	118(%rdi), %r9d
	movl	%r9d, -424(%rbp)
	movswl	120(%rdi), %r9d
	movl	%r9d, -428(%rbp)
	movswl	122(%rdi), %r9d
	movl	%r9d, -432(%rbp)
	movsd	%xmm1, -544(%rbp)
	movswl	124(%rdi), %r9d
	cvtsi2sd	%edx, %xmm1
	movswl	126(%rdi), %edi
	movl	%r9d, -436(%rbp)
	movl	%edi, -440(%rbp)
	movsd	%xmm1, -552(%rbp)
	cvtsi2sd	%ecx, %xmm1
	movsd	%xmm1, -560(%rbp)
	cvtsi2sd	%esi, %xmm1
	movsd	%xmm1, -568(%rbp)
	cvtsi2sd	%r8d, %xmm1
	movsd	%xmm1, -576(%rbp)
	.p2align 4,,10
	.p2align 3
.L2:
	movq	-272(%rbp), %r9
	xorl	%r15d, %r15d
	.cfi_offset 3, -56
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	xorl	%r14d, %r14d
	xorl	%r13d, %r13d
	cvtsi2sd	-616(%rbp), %xmm1
	xorl	%ebx, %ebx
	movsd	%xmm1, -512(%rbp)
	movl	$0, -252(%rbp)
	cvtsi2sd	-620(%rbp), %xmm1
	addq	%r9, %r9
	movsd	%xmm1, -520(%rbp)
	xorl	%r12d, %r12d
	cvtsi2sd	-624(%rbp), %xmm1
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm1, -528(%rbp)
	movq	%r9, -504(%rbp)
	cvtsi2sd	-628(%rbp), %xmm1
	movl	%r15d, -256(%rbp)
	movsd	%xmm1, -536(%rbp)
	movl	%r14d, -260(%rbp)
	movl	%r13d, -264(%rbp)
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L3:
	cvtsi2sd	%r12d, %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	movq	-504(%rbp), %r9
.L5:
	movss	Av(%r9,%rbx,2), %xmm1
	movsd	-192(%rbp), %xmm2
	addl	$1, %r12d
	cvtps2pd	%xmm1, %xmm1
	mulsd	%xmm1, %xmm0
	movsd	%xmm1, -184(%rbp)
	xorpd	%xmm1, %xmm1
	mulsd	%xmm0, %xmm2
	mulsd	-544(%rbp), %xmm2
	addsd	%xmm1, %xmm2
	movsd	-200(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	-552(%rbp), %xmm1
	addsd	%xmm1, %xmm2
	movsd	-208(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	-560(%rbp), %xmm1
	addsd	%xmm1, %xmm2
	movsd	-216(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	-568(%rbp), %xmm1
	addsd	%xmm1, %xmm2
	movsd	-224(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	-576(%rbp), %xmm1
	addsd	%xmm1, %xmm2
	movsd	-232(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	-512(%rbp), %xmm1
	addsd	%xmm1, %xmm2
	movsd	-240(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	-248(%rbp), %xmm0
	mulsd	-520(%rbp), %xmm1
	mulsd	-528(%rbp), %xmm0
	addsd	%xmm1, %xmm2
	addsd	%xmm0, %xmm2
	cvtsi2sd	-264(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	movsd	%xmm2, -656(%rbp)
	mulsd	.LC2(%rip), %xmm0
	call	cos
	cvtsi2sd	-444(%rbp), %xmm3
	mulsd	-184(%rbp), %xmm0
	movsd	-192(%rbp), %xmm1
	movsd	-656(%rbp), %xmm2
	mulsd	%xmm0, %xmm1
	mulsd	-536(%rbp), %xmm1
	addsd	%xmm2, %xmm1
	movsd	-200(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-448(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-208(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-452(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-216(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-456(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-224(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-460(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-232(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-464(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-240(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	-248(%rbp), %xmm0
	mulsd	%xmm3, %xmm2
	addsd	%xmm2, %xmm1
	cvtsi2sd	-468(%rbp), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	cvtsi2sd	-260(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	movsd	%xmm1, -656(%rbp)
	call	cos
	cvtsi2sd	-472(%rbp), %xmm3
	mulsd	-184(%rbp), %xmm0
	movsd	-192(%rbp), %xmm2
	movsd	-656(%rbp), %xmm1
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-476(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-200(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-480(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-208(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-484(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-216(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-488(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-224(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-492(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-232(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-276(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-240(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	-248(%rbp), %xmm0
	mulsd	%xmm3, %xmm2
	addsd	%xmm2, %xmm1
	cvtsi2sd	-280(%rbp), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	cvtsi2sd	-256(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	movsd	%xmm1, -656(%rbp)
	mulsd	.LC2(%rip), %xmm0
	call	cos
	cvtsi2sd	-284(%rbp), %xmm3
	mulsd	-184(%rbp), %xmm0
	movsd	-192(%rbp), %xmm2
	movsd	-656(%rbp), %xmm1
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-288(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-200(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-292(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-208(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-296(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-216(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-300(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-224(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-304(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-232(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-308(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-240(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	-248(%rbp), %xmm0
	mulsd	%xmm3, %xmm2
	addsd	%xmm2, %xmm1
	cvtsi2sd	-312(%rbp), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	cvtsi2sd	-252(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	movsd	%xmm1, -656(%rbp)
	call	cos
	cvtsi2sd	-316(%rbp), %xmm3
	mulsd	-184(%rbp), %xmm0
	movsd	-192(%rbp), %xmm2
	movsd	-656(%rbp), %xmm1
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-320(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-200(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-324(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-208(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-328(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-216(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-332(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-224(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-336(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-232(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-340(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-240(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	-248(%rbp), %xmm0
	mulsd	%xmm3, %xmm2
	addsd	%xmm2, %xmm1
	cvtsi2sd	-344(%rbp), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	cvtsi2sd	%r15d, %xmm0
	addl	$11, %r15d
	movsd	%xmm1, -656(%rbp)
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	cvtsi2sd	-348(%rbp), %xmm3
	mulsd	-184(%rbp), %xmm0
	movsd	-192(%rbp), %xmm2
	movsd	-656(%rbp), %xmm1
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-352(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-200(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-356(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-208(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-360(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-216(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-364(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-224(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-368(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-232(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-372(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-240(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	-248(%rbp), %xmm0
	mulsd	%xmm3, %xmm2
	addsd	%xmm2, %xmm1
	cvtsi2sd	-376(%rbp), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	cvtsi2sd	%r14d, %xmm0
	addl	$13, %r14d
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	movsd	%xmm1, -656(%rbp)
	call	cos
	cvtsi2sd	-380(%rbp), %xmm3
	mulsd	-184(%rbp), %xmm0
	movsd	-192(%rbp), %xmm2
	movsd	-656(%rbp), %xmm1
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-384(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-200(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-388(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-208(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-392(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-216(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-396(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-224(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-400(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-232(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-404(%rbp), %xmm3
	addsd	%xmm2, %xmm1
	movsd	-240(%rbp), %xmm2
	mulsd	%xmm0, %xmm2
	mulsd	-248(%rbp), %xmm0
	mulsd	%xmm3, %xmm2
	addsd	%xmm2, %xmm1
	cvtsi2sd	-408(%rbp), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	cvtsi2sd	%r13d, %xmm0
	addl	$15, %r13d
	movsd	%xmm1, -656(%rbp)
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	cvtsi2sd	-412(%rbp), %xmm3
	mulsd	-184(%rbp), %xmm0
	leaq	-176(%rbp), %rax
	addq	-272(%rbp), %rax
	movsd	-192(%rbp), %xmm2
	movsd	-656(%rbp), %xmm1
	mulsd	%xmm0, %xmm2
	mulsd	%xmm3, %xmm2
	cvtsi2sd	-416(%rbp), %xmm3
	addsd	%xmm1, %xmm2
	movsd	-200(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	%xmm3, %xmm1
	cvtsi2sd	-420(%rbp), %xmm3
	addsd	%xmm1, %xmm2
	movsd	-208(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	%xmm3, %xmm1
	cvtsi2sd	-424(%rbp), %xmm3
	addsd	%xmm1, %xmm2
	movsd	-216(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	%xmm3, %xmm1
	cvtsi2sd	-428(%rbp), %xmm3
	addsd	%xmm1, %xmm2
	movsd	-224(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	%xmm3, %xmm1
	cvtsi2sd	-432(%rbp), %xmm3
	addsd	%xmm1, %xmm2
	movsd	-232(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	%xmm3, %xmm1
	cvtsi2sd	-436(%rbp), %xmm3
	addsd	%xmm1, %xmm2
	movsd	-240(%rbp), %xmm1
	mulsd	%xmm0, %xmm1
	mulsd	-248(%rbp), %xmm0
	mulsd	%xmm3, %xmm1
	addsd	%xmm1, %xmm2
	cvtsi2sd	-440(%rbp), %xmm1
	mulsd	%xmm1, %xmm0
	addsd	%xmm0, %xmm2
	cvttsd2si	%xmm2, %edx
	movw	%dx, (%rax,%rbx)
	addl	$3, -264(%rbp)
	addq	$16, %rbx
	addl	$5, -260(%rbp)
	addl	$7, -256(%rbp)
	addl	$9, -252(%rbp)
	cmpl	$8, %r12d
	jne	.L3
	addq	$2, -272(%rbp)
	addl	$1, -496(%rbp)
	addl	$3, -600(%rbp)
	addl	$5, -612(%rbp)
	addl	$7, -592(%rbp)
	addl	$9, -588(%rbp)
	addl	$11, -596(%rbp)
	addl	$13, -604(%rbp)
	addl	$15, -608(%rbp)
	cmpq	$16, -272(%rbp)
	je	.L4
	cvtsi2sd	-496(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	movsd	%xmm0, -192(%rbp)
	cvtsi2sd	-600(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	movsd	%xmm0, -200(%rbp)
	cvtsi2sd	-612(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	movsd	%xmm0, -208(%rbp)
	cvtsi2sd	-592(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	movsd	%xmm0, -216(%rbp)
	cvtsi2sd	-588(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	movsd	%xmm0, -224(%rbp)
	cvtsi2sd	-596(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	movsd	%xmm0, -232(%rbp)
	cvtsi2sd	-604(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	movsd	%xmm0, -240(%rbp)
	cvtsi2sd	-608(%rbp), %xmm0
	mulsd	.LC1(%rip), %xmm0
	mulsd	.LC2(%rip), %xmm0
	call	cos
	movsd	%xmm0, -248(%rbp)
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L4:
	movq	-584(%rbp), %rsi
	movdqa	-176(%rbp), %xmm0
	movdqu	%xmm0, (%rsi)
	movdqa	-160(%rbp), %xmm0
	movdqu	%xmm0, 16(%rsi)
	movdqa	-144(%rbp), %xmm0
	movdqu	%xmm0, 32(%rsi)
	movdqa	-128(%rbp), %xmm0
	movdqu	%xmm0, 48(%rsi)
	movdqa	-112(%rbp), %xmm0
	movdqu	%xmm0, 64(%rsi)
	movdqa	-96(%rbp), %xmm0
	movdqu	%xmm0, 80(%rsi)
	movdqa	-80(%rbp), %xmm0
	movdqu	%xmm0, 96(%rsi)
	movdqa	-64(%rbp), %xmm0
	movdqu	%xmm0, 112(%rsi)
	addq	$616, %rsp
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
	.size	_Z17slow_float_dct8x8PA8_sS0_, .-_Z17slow_float_dct8x8PA8_sS0_
	.p2align 4,,15
	.globl	_Z15slow_float_dct8PfS_
	.type	_Z15slow_float_dct8PfS_, @function
_Z15slow_float_dct8PfS_:
.LFB54:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	mcount
	movss	.LC4(%rip), %xmm0
	movss	(%rdi), %xmm2
	xorpd	%xmm1, %xmm1
	mulss	%xmm0, %xmm2
	movss	4(%rdi), %xmm3
	mulss	%xmm0, %xmm3
	movsd	.LC7(%rip), %xmm11
	movsd	.LC9(%rip), %xmm6
	unpcklps	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	movsd	.LC10(%rip), %xmm10
	cvtps2pd	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	addsd	%xmm1, %xmm2
	movsd	.LC15(%rip), %xmm9
	movsd	.LC18(%rip), %xmm8
	movsd	.LC21(%rip), %xmm7
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	8(%rdi), %xmm3
	mulss	%xmm0, %xmm3
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	12(%rdi), %xmm3
	mulss	%xmm0, %xmm3
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	16(%rdi), %xmm3
	mulss	%xmm0, %xmm3
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	20(%rdi), %xmm3
	mulss	%xmm0, %xmm3
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	24(%rdi), %xmm3
	mulss	%xmm0, %xmm3
	mulss	28(%rdi), %xmm0
	unpcklpd	%xmm2, %xmm2
	unpcklps	%xmm3, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm0, %xmm2
	movss	.LC5(%rip), %xmm0
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	mulss	%xmm0, %xmm2
	movss	%xmm2, (%rsi)
	movss	(%rdi), %xmm2
	movss	4(%rdi), %xmm3
	movss	8(%rdi), %xmm4
	movss	28(%rdi), %xmm5
	cvtps2pd	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	mulsd	.LC6(%rip), %xmm2
	cvtps2pd	%xmm4, %xmm4
	mulsd	%xmm11, %xmm3
	cvtps2pd	%xmm5, %xmm5
	addsd	%xmm1, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movsd	.LC8(%rip), %xmm3
	mulsd	%xmm3, %xmm4
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm4, %xmm2
	movss	12(%rdi), %xmm4
	cvtps2pd	%xmm4, %xmm4
	unpcklpd	%xmm2, %xmm2
	mulsd	%xmm6, %xmm4
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm4, %xmm2
	movss	16(%rdi), %xmm4
	cvtps2pd	%xmm4, %xmm4
	unpcklpd	%xmm2, %xmm2
	mulsd	%xmm10, %xmm4
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm4, %xmm2
	movss	20(%rdi), %xmm4
	cvtps2pd	%xmm4, %xmm4
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC11(%rip), %xmm4
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm4, %xmm2
	movss	24(%rdi), %xmm4
	cvtps2pd	%xmm4, %xmm4
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC12(%rip), %xmm4
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm4, %xmm2
	movsd	.LC13(%rip), %xmm4
	mulsd	%xmm4, %xmm5
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	mulss	%xmm0, %xmm2
	movss	%xmm2, 4(%rsi)
	movss	(%rdi), %xmm2
	movss	4(%rdi), %xmm5
	cvtps2pd	%xmm2, %xmm2
	cvtps2pd	%xmm5, %xmm5
	mulsd	.LC14(%rip), %xmm2
	mulsd	%xmm9, %xmm5
	addsd	%xmm1, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	movss	8(%rdi), %xmm5
	cvtps2pd	%xmm5, %xmm5
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC16(%rip), %xmm5
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	movss	12(%rdi), %xmm5
	cvtps2pd	%xmm5, %xmm5
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC17(%rip), %xmm5
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	movss	16(%rdi), %xmm5
	cvtps2pd	%xmm5, %xmm5
	unpcklpd	%xmm2, %xmm2
	mulsd	%xmm8, %xmm5
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	movss	20(%rdi), %xmm5
	cvtps2pd	%xmm5, %xmm5
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC19(%rip), %xmm5
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	movss	24(%rdi), %xmm5
	cvtps2pd	%xmm5, %xmm5
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC20(%rip), %xmm5
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	movss	28(%rdi), %xmm5
	cvtps2pd	%xmm5, %xmm5
	unpcklpd	%xmm2, %xmm2
	mulsd	%xmm7, %xmm5
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	mulss	%xmm0, %xmm2
	movss	%xmm2, 8(%rsi)
	movss	(%rdi), %xmm2
	movss	4(%rdi), %xmm5
	cvtps2pd	%xmm2, %xmm2
	cvtps2pd	%xmm5, %xmm5
	mulsd	%xmm11, %xmm2
	movss	28(%rdi), %xmm11
	mulsd	%xmm10, %xmm5
	movss	12(%rdi), %xmm10
	cvtps2pd	%xmm11, %xmm11
	addsd	%xmm1, %xmm2
	cvtps2pd	%xmm10, %xmm10
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	movss	8(%rdi), %xmm5
	cvtps2pd	%xmm5, %xmm5
	unpcklpd	%xmm2, %xmm2
	mulsd	%xmm4, %xmm5
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm5, %xmm2
	movsd	.LC22(%rip), %xmm5
	mulsd	%xmm5, %xmm10
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm10, %xmm2
	movss	16(%rdi), %xmm10
	cvtps2pd	%xmm10, %xmm10
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC23(%rip), %xmm10
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm10, %xmm2
	movss	20(%rdi), %xmm10
	cvtps2pd	%xmm10, %xmm10
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC24(%rip), %xmm10
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm10, %xmm2
	movss	24(%rdi), %xmm10
	cvtps2pd	%xmm10, %xmm10
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC25(%rip), %xmm10
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm10, %xmm2
	movsd	.LC26(%rip), %xmm10
	mulsd	%xmm10, %xmm11
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm11, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	mulss	%xmm0, %xmm2
	movss	%xmm2, 12(%rsi)
	movss	(%rdi), %xmm2
	movss	4(%rdi), %xmm11
	cvtps2pd	%xmm2, %xmm2
	cvtps2pd	%xmm11, %xmm11
	mulsd	.LC27(%rip), %xmm2
	mulsd	.LC28(%rip), %xmm11
	addsd	%xmm1, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm11, %xmm2
	movss	8(%rdi), %xmm11
	cvtps2pd	%xmm11, %xmm11
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC29(%rip), %xmm11
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm11, %xmm2
	movss	12(%rdi), %xmm11
	cvtps2pd	%xmm11, %xmm11
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC30(%rip), %xmm11
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm11, %xmm2
	movss	16(%rdi), %xmm11
	cvtps2pd	%xmm11, %xmm11
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC31(%rip), %xmm11
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm11, %xmm2
	movss	20(%rdi), %xmm11
	cvtps2pd	%xmm11, %xmm11
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC32(%rip), %xmm11
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm11, %xmm2
	movss	24(%rdi), %xmm11
	cvtps2pd	%xmm11, %xmm11
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC33(%rip), %xmm11
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm11, %xmm2
	movss	28(%rdi), %xmm11
	cvtps2pd	%xmm11, %xmm11
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC34(%rip), %xmm11
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm11, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	mulss	%xmm0, %xmm2
	movss	%xmm2, 16(%rsi)
	movss	(%rdi), %xmm2
	cvtps2pd	%xmm2, %xmm2
	mulsd	%xmm3, %xmm2
	movss	4(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	addsd	%xmm1, %xmm2
	mulsd	%xmm4, %xmm3
	movsd	.LC36(%rip), %xmm4
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	8(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC35(%rip), %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	12(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	%xmm4, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	16(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	%xmm10, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	20(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC37(%rip), %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	24(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC38(%rip), %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	28(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC39(%rip), %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	mulss	%xmm0, %xmm2
	movss	%xmm2, 20(%rsi)
	movss	(%rdi), %xmm2
	movss	4(%rdi), %xmm3
	popq	%rbp
	.cfi_def_cfa 7, 8
	cvtps2pd	%xmm2, %xmm2
	cvtps2pd	%xmm3, %xmm3
	mulsd	%xmm9, %xmm2
	mulsd	%xmm8, %xmm3
	addsd	%xmm1, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	8(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	%xmm7, %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	12(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC40(%rip), %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	16(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC41(%rip), %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	20(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC42(%rip), %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	24(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC43(%rip), %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	movss	28(%rdi), %xmm3
	cvtps2pd	%xmm3, %xmm3
	unpcklpd	%xmm2, %xmm2
	mulsd	.LC44(%rip), %xmm3
	cvtpd2ps	%xmm2, %xmm2
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm2
	addsd	%xmm3, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm2
	mulss	%xmm0, %xmm2
	movss	%xmm2, 24(%rsi)
	movss	(%rdi), %xmm2
	cvtps2pd	%xmm2, %xmm2
	mulsd	%xmm6, %xmm2
	addsd	%xmm1, %xmm2
	unpcklpd	%xmm2, %xmm2
	cvtpd2ps	%xmm2, %xmm1
	movss	4(%rdi), %xmm2
	cvtps2pd	%xmm2, %xmm2
	mulsd	%xmm5, %xmm2
	unpcklps	%xmm1, %xmm1
	cvtps2pd	%xmm1, %xmm1
	addsd	%xmm2, %xmm1
	movss	8(%rdi), %xmm2
	cvtps2pd	%xmm2, %xmm2
	unpcklpd	%xmm1, %xmm1
	mulsd	%xmm4, %xmm2
	cvtpd2ps	%xmm1, %xmm1
	unpcklps	%xmm1, %xmm1
	cvtps2pd	%xmm1, %xmm1
	addsd	%xmm2, %xmm1
	movss	12(%rdi), %xmm2
	cvtps2pd	%xmm2, %xmm2
	unpcklpd	%xmm1, %xmm1
	mulsd	.LC45(%rip), %xmm2
	cvtpd2ps	%xmm1, %xmm1
	unpcklps	%xmm1, %xmm1
	cvtps2pd	%xmm1, %xmm1
	addsd	%xmm2, %xmm1
	movss	16(%rdi), %xmm2
	cvtps2pd	%xmm2, %xmm2
	unpcklpd	%xmm1, %xmm1
	mulsd	.LC46(%rip), %xmm2
	cvtpd2ps	%xmm1, %xmm1
	unpcklps	%xmm1, %xmm1
	cvtps2pd	%xmm1, %xmm1
	addsd	%xmm2, %xmm1
	movss	20(%rdi), %xmm2
	cvtps2pd	%xmm2, %xmm2
	unpcklpd	%xmm1, %xmm1
	mulsd	.LC47(%rip), %xmm2
	cvtpd2ps	%xmm1, %xmm1
	unpcklps	%xmm1, %xmm1
	cvtps2pd	%xmm1, %xmm1
	addsd	%xmm2, %xmm1
	movss	24(%rdi), %xmm2
	cvtps2pd	%xmm2, %xmm2
	unpcklpd	%xmm1, %xmm1
	mulsd	.LC48(%rip), %xmm2
	cvtpd2ps	%xmm1, %xmm1
	unpcklps	%xmm1, %xmm1
	cvtps2pd	%xmm1, %xmm1
	addsd	%xmm2, %xmm1
	movss	28(%rdi), %xmm2
	cvtps2pd	%xmm2, %xmm2
	unpcklpd	%xmm1, %xmm1
	mulsd	.LC49(%rip), %xmm2
	cvtpd2ps	%xmm1, %xmm1
	unpcklps	%xmm1, %xmm1
	cvtps2pd	%xmm1, %xmm1
	addsd	%xmm2, %xmm1
	unpcklpd	%xmm1, %xmm1
	cvtpd2ps	%xmm1, %xmm1
	mulss	%xmm0, %xmm1
	movss	%xmm1, 28(%rsi)
	ret
	.cfi_endproc
.LFE54:
	.size	_Z15slow_float_dct8PfS_, .-_Z15slow_float_dct8PfS_
	.p2align 4,,15
	.globl	_Z15fast_float_dct8PfS_
	.type	_Z15fast_float_dct8PfS_, @function
_Z15fast_float_dct8PfS_:
.LFB55:
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
	movsd	.LC50(%rip), %xmm0
	cvtps2pd	%xmm2, %xmm2
	movaps	%xmm1, %xmm10
	movaps	%xmm8, %xmm3
	cvtps2pd	%xmm4, %xmm4
	mulsd	%xmm0, %xmm2
	movsd	.LC51(%rip), %xmm6
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
	movss	.LC5(%rip), %xmm0
	movapd	%xmm3, %xmm4
	cvtps2pd	%xmm8, %xmm8
	addsd	%xmm2, %xmm4
	subsd	%xmm2, %xmm3
	movsd	.LC52(%rip), %xmm2
	cvtpd2ps	%xmm6, %xmm6
	unpcklpd	%xmm4, %xmm4
	unpcklpd	%xmm3, %xmm3
	cvtpd2ps	%xmm4, %xmm4
	mulss	%xmm0, %xmm4
	movss	%xmm4, (%rsi)
	cvtpd2ps	%xmm3, %xmm4
	movsd	.LC53(%rip), %xmm3
	mulsd	%xmm8, %xmm3
	mulss	%xmm0, %xmm4
	movss	%xmm4, 16(%rsi)
	movapd	%xmm9, %xmm4
	mulsd	%xmm2, %xmm4
	mulsd	%xmm8, %xmm2
	movaps	%xmm5, %xmm8
	addss	%xmm7, %xmm8
	addsd	%xmm3, %xmm4
	movsd	.LC54(%rip), %xmm3
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
	movsd	.LC55(%rip), %xmm4
	subss	%xmm6, %xmm1
	addss	%xmm6, %xmm0
	movss	%xmm3, 24(%rsi)
	movsd	.LC56(%rip), %xmm3
	unpcklps	%xmm0, %xmm0
	mulsd	%xmm8, %xmm3
	unpcklps	%xmm1, %xmm1
	cvtps2pd	%xmm0, %xmm0
	cvtps2pd	%xmm1, %xmm1
	movapd	%xmm0, %xmm2
	mulsd	.LC62(%rip), %xmm0
	mulsd	%xmm4, %xmm2
	mulsd	%xmm8, %xmm4
	addsd	%xmm3, %xmm2
	movsd	.LC57(%rip), %xmm3
	addsd	%xmm4, %xmm0
	mulsd	%xmm3, %xmm2
	mulsd	%xmm3, %xmm0
	unpcklpd	%xmm2, %xmm2
	unpcklpd	%xmm0, %xmm0
	cvtpd2ps	%xmm2, %xmm2
	cvtpd2ps	%xmm0, %xmm0
	movss	%xmm2, 4(%rsi)
	movaps	%xmm7, %xmm2
	movsd	.LC60(%rip), %xmm7
	subss	%xmm5, %xmm2
	movss	.LC58(%rip), %xmm5
	movss	%xmm0, 28(%rsi)
	xorps	%xmm5, %xmm2
	movsd	.LC59(%rip), %xmm5
	unpcklps	%xmm2, %xmm2
	cvtps2pd	%xmm2, %xmm6
	movapd	%xmm1, %xmm2
	mulsd	.LC61(%rip), %xmm1
	mulsd	%xmm5, %xmm2
	mulsd	%xmm6, %xmm7
	mulsd	%xmm6, %xmm5
	addsd	%xmm7, %xmm2
	addsd	%xmm5, %xmm1
	mulsd	%xmm3, %xmm2
	mulsd	%xmm3, %xmm1
	unpcklpd	%xmm2, %xmm2
	unpcklpd	%xmm1, %xmm1
	cvtpd2ps	%xmm2, %xmm2
	cvtpd2ps	%xmm1, %xmm1
	movss	%xmm2, 20(%rsi)
	movss	%xmm1, 12(%rsi)
	ret
	.cfi_endproc
.LFE55:
	.size	_Z15fast_float_dct8PfS_, .-_Z15fast_float_dct8PfS_
	.p2align 4,,15
	.globl	_Z17fast_float_dct8x8PA8_sS0_
	.type	_Z17fast_float_dct8x8PA8_sS0_, @function
_Z17fast_float_dct8x8PA8_sS0_:
.LFB52:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$64, %rsp
	call	mcount
	movswl	(%rdi), %eax
	movq	%rsi, %rbx
	.cfi_offset 3, -32
	.cfi_offset 12, -24
	movq	%rdi, %r12
	leaq	-48(%rbp), %rsi
	cvtsi2ss	%eax, %xmm0
	movswl	2(%rdi), %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	4(%rdi), %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	6(%rdi), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	8(%rdi), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	10(%rdi), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	12(%rdi), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	14(%rdi), %eax
	leaq	-80(%rbp), %rdi
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm0
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm0, %eax
	leaq	-80(%rbp), %rdi
	movss	-44(%rbp), %xmm1
	movss	-40(%rbp), %xmm2
	movss	-36(%rbp), %xmm3
	movss	-32(%rbp), %xmm4
	movss	-28(%rbp), %xmm5
	movss	-24(%rbp), %xmm6
	movss	-20(%rbp), %xmm7
	movw	%ax, (%rbx)
	cvttss2si	%xmm1, %eax
	movw	%ax, 2(%rbx)
	cvttss2si	%xmm2, %eax
	movw	%ax, 4(%rbx)
	cvttss2si	%xmm3, %eax
	movw	%ax, 6(%rbx)
	cvttss2si	%xmm4, %eax
	movw	%ax, 8(%rbx)
	cvttss2si	%xmm5, %eax
	movw	%ax, 10(%rbx)
	cvttss2si	%xmm6, %eax
	movw	%ax, 12(%rbx)
	cvttss2si	%xmm7, %eax
	movw	%ax, 14(%rbx)
	movswl	16(%r12), %eax
	cvtsi2ss	%eax, %xmm0
	movswl	18(%r12), %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	20(%r12), %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	22(%r12), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	24(%r12), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	26(%r12), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	28(%r12), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	30(%r12), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm8
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm8, %eax
	leaq	-80(%rbp), %rdi
	movss	-44(%rbp), %xmm9
	movss	-40(%rbp), %xmm10
	movss	-36(%rbp), %xmm11
	movss	-32(%rbp), %xmm12
	movss	-28(%rbp), %xmm13
	movss	-24(%rbp), %xmm14
	movss	-20(%rbp), %xmm15
	movw	%ax, 16(%rbx)
	cvttss2si	%xmm9, %eax
	movw	%ax, 18(%rbx)
	cvttss2si	%xmm10, %eax
	movw	%ax, 20(%rbx)
	cvttss2si	%xmm11, %eax
	movw	%ax, 22(%rbx)
	cvttss2si	%xmm12, %eax
	movw	%ax, 24(%rbx)
	cvttss2si	%xmm13, %eax
	movw	%ax, 26(%rbx)
	cvttss2si	%xmm14, %eax
	movw	%ax, 28(%rbx)
	cvttss2si	%xmm15, %eax
	movw	%ax, 30(%rbx)
	movswl	32(%r12), %eax
	cvtsi2ss	%eax, %xmm0
	movswl	34(%r12), %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	36(%r12), %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	38(%r12), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	40(%r12), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	42(%r12), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	44(%r12), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	46(%r12), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm0
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm0, %eax
	leaq	-80(%rbp), %rdi
	movss	-44(%rbp), %xmm1
	movss	-40(%rbp), %xmm2
	movss	-36(%rbp), %xmm3
	movss	-32(%rbp), %xmm4
	movss	-28(%rbp), %xmm5
	movss	-24(%rbp), %xmm6
	movss	-20(%rbp), %xmm7
	movw	%ax, 32(%rbx)
	cvttss2si	%xmm1, %eax
	movw	%ax, 34(%rbx)
	cvttss2si	%xmm2, %eax
	movw	%ax, 36(%rbx)
	cvttss2si	%xmm3, %eax
	movw	%ax, 38(%rbx)
	cvttss2si	%xmm4, %eax
	movw	%ax, 40(%rbx)
	cvttss2si	%xmm5, %eax
	movw	%ax, 42(%rbx)
	cvttss2si	%xmm6, %eax
	movw	%ax, 44(%rbx)
	cvttss2si	%xmm7, %eax
	movw	%ax, 46(%rbx)
	movswl	48(%r12), %eax
	cvtsi2ss	%eax, %xmm0
	movswl	50(%r12), %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	52(%r12), %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	54(%r12), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	56(%r12), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	58(%r12), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	60(%r12), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	62(%r12), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm8
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm8, %eax
	leaq	-80(%rbp), %rdi
	movss	-44(%rbp), %xmm9
	movss	-40(%rbp), %xmm10
	movss	-36(%rbp), %xmm11
	movss	-32(%rbp), %xmm12
	movss	-28(%rbp), %xmm13
	movss	-24(%rbp), %xmm14
	movss	-20(%rbp), %xmm15
	movw	%ax, 48(%rbx)
	cvttss2si	%xmm9, %eax
	movw	%ax, 50(%rbx)
	cvttss2si	%xmm10, %eax
	movw	%ax, 52(%rbx)
	cvttss2si	%xmm11, %eax
	movw	%ax, 54(%rbx)
	cvttss2si	%xmm12, %eax
	movw	%ax, 56(%rbx)
	cvttss2si	%xmm13, %eax
	movw	%ax, 58(%rbx)
	cvttss2si	%xmm14, %eax
	movw	%ax, 60(%rbx)
	cvttss2si	%xmm15, %eax
	movw	%ax, 62(%rbx)
	movswl	64(%r12), %eax
	cvtsi2ss	%eax, %xmm0
	movswl	66(%r12), %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	68(%r12), %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	70(%r12), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	72(%r12), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	74(%r12), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	76(%r12), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	78(%r12), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm0
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm0, %eax
	leaq	-80(%rbp), %rdi
	movss	-44(%rbp), %xmm1
	movss	-40(%rbp), %xmm2
	movss	-36(%rbp), %xmm3
	movss	-32(%rbp), %xmm4
	movss	-28(%rbp), %xmm5
	movss	-24(%rbp), %xmm6
	movss	-20(%rbp), %xmm7
	movw	%ax, 64(%rbx)
	cvttss2si	%xmm1, %eax
	movw	%ax, 66(%rbx)
	cvttss2si	%xmm2, %eax
	movw	%ax, 68(%rbx)
	cvttss2si	%xmm3, %eax
	movw	%ax, 70(%rbx)
	cvttss2si	%xmm4, %eax
	movw	%ax, 72(%rbx)
	cvttss2si	%xmm5, %eax
	movw	%ax, 74(%rbx)
	cvttss2si	%xmm6, %eax
	movw	%ax, 76(%rbx)
	cvttss2si	%xmm7, %eax
	movw	%ax, 78(%rbx)
	movswl	80(%r12), %eax
	cvtsi2ss	%eax, %xmm0
	movswl	82(%r12), %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	84(%r12), %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	86(%r12), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	88(%r12), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	90(%r12), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	92(%r12), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	94(%r12), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm8
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm8, %eax
	leaq	-80(%rbp), %rdi
	movss	-44(%rbp), %xmm9
	movss	-40(%rbp), %xmm10
	movss	-36(%rbp), %xmm11
	movss	-32(%rbp), %xmm12
	movss	-28(%rbp), %xmm13
	movss	-24(%rbp), %xmm14
	movss	-20(%rbp), %xmm15
	movw	%ax, 80(%rbx)
	cvttss2si	%xmm9, %eax
	movw	%ax, 82(%rbx)
	cvttss2si	%xmm10, %eax
	movw	%ax, 84(%rbx)
	cvttss2si	%xmm11, %eax
	movw	%ax, 86(%rbx)
	cvttss2si	%xmm12, %eax
	movw	%ax, 88(%rbx)
	cvttss2si	%xmm13, %eax
	movw	%ax, 90(%rbx)
	cvttss2si	%xmm14, %eax
	movw	%ax, 92(%rbx)
	cvttss2si	%xmm15, %eax
	movw	%ax, 94(%rbx)
	movswl	96(%r12), %eax
	cvtsi2ss	%eax, %xmm0
	movswl	98(%r12), %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	100(%r12), %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	102(%r12), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	104(%r12), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	106(%r12), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	108(%r12), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	110(%r12), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm0
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm0, %eax
	leaq	-80(%rbp), %rdi
	movss	-44(%rbp), %xmm1
	movss	-40(%rbp), %xmm2
	movss	-36(%rbp), %xmm3
	movss	-32(%rbp), %xmm4
	movss	-28(%rbp), %xmm5
	movss	-24(%rbp), %xmm6
	movss	-20(%rbp), %xmm7
	movw	%ax, 96(%rbx)
	cvttss2si	%xmm1, %eax
	movw	%ax, 98(%rbx)
	cvttss2si	%xmm2, %eax
	movw	%ax, 100(%rbx)
	cvttss2si	%xmm3, %eax
	movw	%ax, 102(%rbx)
	cvttss2si	%xmm4, %eax
	movw	%ax, 104(%rbx)
	cvttss2si	%xmm5, %eax
	movw	%ax, 106(%rbx)
	cvttss2si	%xmm6, %eax
	movw	%ax, 108(%rbx)
	cvttss2si	%xmm7, %eax
	movw	%ax, 110(%rbx)
	movswl	112(%r12), %eax
	cvtsi2ss	%eax, %xmm0
	movswl	114(%r12), %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	116(%r12), %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	118(%r12), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	120(%r12), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	122(%r12), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	124(%r12), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	126(%r12), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-44(%rbp), %xmm9
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm9, %edx
	leaq	-80(%rbp), %rdi
	movss	-40(%rbp), %xmm10
	movss	-36(%rbp), %xmm11
	movss	-32(%rbp), %xmm12
	movss	-28(%rbp), %xmm13
	movss	-24(%rbp), %xmm14
	movss	-20(%rbp), %xmm15
	movss	-48(%rbp), %xmm8
	cvttss2si	%xmm8, %eax
	movw	%dx, 114(%rbx)
	cvttss2si	%xmm10, %edx
	movw	%ax, 112(%rbx)
	cwtl
	movw	%dx, 116(%rbx)
	cvttss2si	%xmm11, %edx
	movw	%dx, 118(%rbx)
	cvttss2si	%xmm12, %edx
	movw	%dx, 120(%rbx)
	cvttss2si	%xmm13, %edx
	movw	%dx, 122(%rbx)
	cvttss2si	%xmm14, %edx
	movw	%dx, 124(%rbx)
	cvttss2si	%xmm15, %edx
	movw	%dx, 126(%rbx)
	movswl	(%rbx), %edx
	cvtsi2ss	%edx, %xmm0
	movswl	16(%rbx), %edx
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	32(%rbx), %edx
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	48(%rbx), %edx
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	64(%rbx), %edx
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	80(%rbx), %edx
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	96(%rbx), %edx
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%edx, %xmm0
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm0
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm0, %eax
	leaq	-80(%rbp), %rdi
	movss	-44(%rbp), %xmm1
	movss	-40(%rbp), %xmm2
	cvttss2si	%xmm2, %edx
	movss	-36(%rbp), %xmm3
	movss	-32(%rbp), %xmm4
	movss	-28(%rbp), %xmm5
	movss	-24(%rbp), %xmm6
	movss	-20(%rbp), %xmm7
	movw	%ax, (%rbx)
	cvttss2si	%xmm1, %eax
	movw	%dx, 4(%rbx)
	cvttss2si	%xmm3, %edx
	movw	%ax, 2(%rbx)
	cwtl
	cvtsi2ss	%eax, %xmm0
	movswl	18(%rbx), %eax
	movw	%dx, 6(%rbx)
	cvttss2si	%xmm4, %edx
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	34(%rbx), %eax
	movw	%dx, 8(%rbx)
	cvttss2si	%xmm5, %edx
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	50(%rbx), %eax
	movw	%dx, 10(%rbx)
	cvttss2si	%xmm6, %edx
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	66(%rbx), %eax
	movw	%dx, 12(%rbx)
	cvttss2si	%xmm7, %edx
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	82(%rbx), %eax
	movw	%dx, 14(%rbx)
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	98(%rbx), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	114(%rbx), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-36(%rbp), %xmm11
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm11, %edx
	leaq	-80(%rbp), %rdi
	movss	-32(%rbp), %xmm12
	movss	-28(%rbp), %xmm13
	movss	-24(%rbp), %xmm14
	movss	-48(%rbp), %xmm8
	cvttss2si	%xmm8, %eax
	movss	-20(%rbp), %xmm15
	movss	-44(%rbp), %xmm9
	movss	-40(%rbp), %xmm10
	movw	%dx, 22(%rbx)
	cvttss2si	%xmm12, %edx
	movw	%ax, 16(%rbx)
	cvttss2si	%xmm9, %eax
	movw	%dx, 24(%rbx)
	cvttss2si	%xmm13, %edx
	movw	%ax, 18(%rbx)
	cvttss2si	%xmm10, %eax
	movw	%dx, 26(%rbx)
	cvttss2si	%xmm14, %edx
	movw	%ax, 20(%rbx)
	cwtl
	movw	%dx, 28(%rbx)
	cvttss2si	%xmm15, %edx
	movw	%dx, 30(%rbx)
	movswl	4(%rbx), %edx
	cvtsi2ss	%edx, %xmm0
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	36(%rbx), %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	52(%rbx), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	68(%rbx), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	84(%rbx), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	100(%rbx), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	116(%rbx), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-32(%rbp), %xmm4
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm4, %edx
	leaq	-80(%rbp), %rdi
	movss	-28(%rbp), %xmm5
	movss	-24(%rbp), %xmm6
	movss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movss	-20(%rbp), %xmm7
	movss	-44(%rbp), %xmm1
	movss	-40(%rbp), %xmm2
	movss	-36(%rbp), %xmm3
	movw	%dx, 40(%rbx)
	cvttss2si	%xmm5, %edx
	movw	%ax, 32(%rbx)
	cvttss2si	%xmm1, %eax
	movw	%dx, 42(%rbx)
	cvttss2si	%xmm6, %edx
	movw	%ax, 34(%rbx)
	cvttss2si	%xmm2, %eax
	movw	%dx, 44(%rbx)
	cvttss2si	%xmm7, %edx
	movw	%ax, 36(%rbx)
	cvttss2si	%xmm3, %eax
	movw	%dx, 46(%rbx)
	movswl	6(%rbx), %edx
	cvtsi2ss	%edx, %xmm0
	movswl	22(%rbx), %edx
	movw	%ax, 38(%rbx)
	cwtl
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%edx, %xmm0
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	54(%rbx), %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	70(%rbx), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	86(%rbx), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	102(%rbx), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	118(%rbx), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-28(%rbp), %xmm13
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm13, %edx
	leaq	-80(%rbp), %rdi
	movss	-24(%rbp), %xmm14
	movss	-48(%rbp), %xmm8
	cvttss2si	%xmm8, %eax
	movss	-20(%rbp), %xmm15
	movss	-44(%rbp), %xmm9
	movss	-40(%rbp), %xmm10
	movss	-36(%rbp), %xmm11
	movss	-32(%rbp), %xmm12
	movw	%dx, 58(%rbx)
	cvttss2si	%xmm14, %edx
	movw	%ax, 48(%rbx)
	cvttss2si	%xmm9, %eax
	movw	%dx, 60(%rbx)
	cvttss2si	%xmm15, %edx
	movw	%ax, 50(%rbx)
	cvttss2si	%xmm10, %eax
	movw	%dx, 62(%rbx)
	movswl	8(%rbx), %edx
	movw	%ax, 52(%rbx)
	cvttss2si	%xmm11, %eax
	cvtsi2ss	%edx, %xmm0
	movswl	24(%rbx), %edx
	movw	%ax, 54(%rbx)
	cvttss2si	%xmm12, %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	40(%rbx), %edx
	movw	%ax, 56(%rbx)
	cwtl
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%edx, %xmm0
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	72(%rbx), %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	88(%rbx), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	104(%rbx), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	120(%rbx), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-24(%rbp), %xmm6
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm6, %edx
	leaq	-80(%rbp), %rdi
	movss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movss	-20(%rbp), %xmm7
	movss	-44(%rbp), %xmm1
	movss	-40(%rbp), %xmm2
	movss	-36(%rbp), %xmm3
	movss	-32(%rbp), %xmm4
	movss	-28(%rbp), %xmm5
	movw	%dx, 76(%rbx)
	cvttss2si	%xmm7, %edx
	movw	%ax, 64(%rbx)
	cvttss2si	%xmm1, %eax
	movw	%dx, 78(%rbx)
	movswl	10(%rbx), %edx
	movw	%ax, 66(%rbx)
	cvttss2si	%xmm2, %eax
	cvtsi2ss	%edx, %xmm0
	movswl	26(%rbx), %edx
	movw	%ax, 68(%rbx)
	cvttss2si	%xmm3, %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	42(%rbx), %edx
	movw	%ax, 70(%rbx)
	cvttss2si	%xmm4, %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	58(%rbx), %edx
	movw	%ax, 72(%rbx)
	cvttss2si	%xmm5, %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%edx, %xmm0
	movw	%ax, 74(%rbx)
	cwtl
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	90(%rbx), %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	106(%rbx), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	122(%rbx), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm8
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm8, %eax
	leaq	-80(%rbp), %rdi
	movss	-20(%rbp), %xmm15
	cvttss2si	%xmm15, %edx
	movss	-44(%rbp), %xmm9
	movss	-40(%rbp), %xmm10
	movss	-36(%rbp), %xmm11
	movss	-32(%rbp), %xmm12
	movss	-28(%rbp), %xmm13
	movss	-24(%rbp), %xmm14
	movw	%ax, 80(%rbx)
	cvttss2si	%xmm9, %eax
	movw	%dx, 94(%rbx)
	movswl	12(%rbx), %edx
	cvtsi2ss	%edx, %xmm0
	movswl	28(%rbx), %edx
	movw	%ax, 82(%rbx)
	cvttss2si	%xmm10, %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	44(%rbx), %edx
	movw	%ax, 84(%rbx)
	cvttss2si	%xmm11, %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	60(%rbx), %edx
	movw	%ax, 86(%rbx)
	cvttss2si	%xmm12, %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	76(%rbx), %edx
	movw	%ax, 88(%rbx)
	cvttss2si	%xmm13, %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%edx, %xmm0
	movw	%ax, 90(%rbx)
	cvttss2si	%xmm14, %eax
	movss	%xmm0, -64(%rbp)
	movw	%ax, 92(%rbx)
	cwtl
	cvtsi2ss	%eax, %xmm0
	movswl	108(%rbx), %eax
	movss	%xmm0, -60(%rbp)
	cvtsi2ss	%eax, %xmm0
	movswl	124(%rbx), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm0
	leaq	-48(%rbp), %rsi
	cvttss2si	%xmm0, %eax
	movswl	14(%rbx), %edx
	movss	-44(%rbp), %xmm1
	leaq	-80(%rbp), %rdi
	movss	-40(%rbp), %xmm2
	movss	-36(%rbp), %xmm3
	cvtsi2ss	%edx, %xmm0
	movswl	30(%rbx), %edx
	movss	-32(%rbp), %xmm4
	movss	-28(%rbp), %xmm5
	movss	-24(%rbp), %xmm6
	movss	-20(%rbp), %xmm7
	movw	%ax, 96(%rbx)
	cvttss2si	%xmm1, %eax
	movss	%xmm0, -80(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	46(%rbx), %edx
	movw	%ax, 98(%rbx)
	cvttss2si	%xmm2, %eax
	movss	%xmm0, -76(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	62(%rbx), %edx
	movw	%ax, 100(%rbx)
	cvttss2si	%xmm3, %eax
	movss	%xmm0, -72(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	78(%rbx), %edx
	movw	%ax, 102(%rbx)
	cvttss2si	%xmm4, %eax
	movss	%xmm0, -68(%rbp)
	cvtsi2ss	%edx, %xmm0
	movswl	94(%rbx), %edx
	movw	%ax, 104(%rbx)
	cvttss2si	%xmm5, %eax
	movss	%xmm0, -64(%rbp)
	cvtsi2ss	%edx, %xmm0
	movw	%ax, 106(%rbx)
	cvttss2si	%xmm6, %eax
	movss	%xmm0, -60(%rbp)
	movw	%ax, 108(%rbx)
	cvttss2si	%xmm7, %eax
	movw	%ax, 110(%rbx)
	cwtl
	cvtsi2ss	%eax, %xmm0
	movswl	126(%rbx), %eax
	movss	%xmm0, -56(%rbp)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -52(%rbp)
	call	_Z15fast_float_dct8PfS_
	movss	-48(%rbp), %xmm8
	cvttss2si	%xmm8, %eax
	movss	-44(%rbp), %xmm9
	movss	-40(%rbp), %xmm10
	movss	-36(%rbp), %xmm11
	movss	-32(%rbp), %xmm12
	movss	-28(%rbp), %xmm13
	movss	-24(%rbp), %xmm14
	movss	-20(%rbp), %xmm15
	movw	%ax, 112(%rbx)
	cvttss2si	%xmm9, %eax
	movw	%ax, 114(%rbx)
	cvttss2si	%xmm10, %eax
	movw	%ax, 116(%rbx)
	cvttss2si	%xmm11, %eax
	movw	%ax, 118(%rbx)
	cvttss2si	%xmm12, %eax
	movw	%ax, 120(%rbx)
	cvttss2si	%xmm13, %eax
	movw	%ax, 122(%rbx)
	cvttss2si	%xmm14, %eax
	movw	%ax, 124(%rbx)
	cvttss2si	%xmm15, %eax
	movw	%ax, 126(%rbx)
	addq	$64, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE52:
	.size	_Z17fast_float_dct8x8PA8_sS0_, .-_Z17fast_float_dct8x8PA8_sS0_
	.p2align 4,,15
	.globl	_Z15fast_fixed_dct8PsS_
	.type	_Z15fast_fixed_dct8PsS_, @function
_Z15fast_fixed_dct8PsS_:
.LFB56:
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
	call	mcount
	movswl	2(%rdi), %r8d
	movswl	4(%rdi), %r9d
	movswl	10(%rdi), %r11d
	movswl	12(%rdi), %r10d
	movswl	(%rdi), %ecx
	movswl	6(%rdi), %r15d
	.cfi_offset 3, -56
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
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
	sarl	$15, %r9d
	sall	$15, %r15d
	sarl	$15, %r8d
	sall	$15, %r14d
	sall	$15, %r13d
	imull	$23170, %r8d, %r10d
	sall	$15, %ecx
	leal	(%r15,%r14), %ebx
	imull	$-23170, %r9d, %r11d
	leal	(%rcx,%r13), %eax
	addl	%r9d, %r8d
	movl	%r15d, %edi
	subl	%r13d, %ecx
	leal	(%rax,%rbx), %r9d
	subl	%ebx, %eax
	subl	%r14d, %edi
	addl	%r10d, %r11d
	sarl	$15, %eax
	imull	$23170, %r8d, %r10d
	leal	(%rdx,%r12), %r8d
	sarl	$15, %r9d
	subl	%r12d, %edx
	sarl	$15, %r8d
	sarl	$15, %edx
	leal	(%r9,%r8), %ebx
	subl	%r8d, %r9d
	imull	$23170, %r9d, %r9d
	imull	$30273, %eax, %r8d
	sarl	$16, %r9d
	movw	%r9w, 8(%rsi)
	imull	$12539, %edx, %r9d
	imull	$23170, %ebx, %ebx
	addl	%r9d, %r8d
	sarl	$16, %ebx
	sarl	$16, %r8d
	imull	$-30273, %edx, %edx
	movw	%r8w, 4(%rsi)
	movw	%bx, (%rsi)
	imull	$12539, %eax, %eax
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
	imull	$6393, %edx, %r9d
	subl	%r10d, %ecx
	sarl	$6, %eax
	sarl	$6, %ecx
	popq	%r13
	imull	$32138, %eax, %r8d
	imull	$-32138, %edx, %edx
	popq	%r14
	addl	%r9d, %r8d
	sarl	$25, %r8d
	imull	$27245, %edi, %r9d
	movw	%r8w, 2(%rsi)
	imull	$-18205, %edi, %edi
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	imull	$18205, %ecx, %r8d
	imull	$6393, %eax, %eax
	addl	%r9d, %r8d
	imull	$27245, %ecx, %ecx
	addl	%edx, %eax
	sarl	$25, %r8d
	sarl	$25, %eax
	movw	%r8w, 10(%rsi)
	movw	%ax, 14(%rsi)
	addl	%edi, %ecx
	sarl	$25, %ecx
	movw	%cx, 6(%rsi)
	ret
	.cfi_endproc
.LFE56:
	.size	_Z15fast_fixed_dct8PsS_, .-_Z15fast_fixed_dct8PsS_
	.p2align 4,,15
	.globl	_Z17fast_fixed_dct8x8PA8_sS0_
	.type	_Z17fast_fixed_dct8x8PA8_sS0_, @function
_Z17fast_fixed_dct8x8PA8_sS0_:
.LFB53:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	call	mcount
	movzwl	(%rdi), %eax
	movq	%rsi, %rbx
	.cfi_offset 3, -32
	.cfi_offset 12, -24
	movq	%rdi, %r12
	leaq	-32(%rbp), %rsi
	movw	%ax, -48(%rbp)
	movzwl	2(%rdi), %eax
	movw	%ax, -46(%rbp)
	movzwl	4(%rdi), %eax
	movw	%ax, -44(%rbp)
	movzwl	6(%rdi), %eax
	movw	%ax, -42(%rbp)
	movzwl	8(%rdi), %eax
	movw	%ax, -40(%rbp)
	movzwl	10(%rdi), %eax
	movw	%ax, -38(%rbp)
	movzwl	12(%rdi), %eax
	movw	%ax, -36(%rbp)
	movzwl	14(%rdi), %eax
	leaq	-48(%rbp), %rdi
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, (%rbx)
	movzwl	-30(%rbp), %eax
	movw	%ax, 2(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%ax, 4(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%ax, 6(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%ax, 8(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%ax, 10(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%ax, 12(%rbx)
	movzwl	-18(%rbp), %eax
	movw	%ax, 14(%rbx)
	movzwl	16(%r12), %eax
	movw	%ax, -48(%rbp)
	movzwl	18(%r12), %eax
	movw	%ax, -46(%rbp)
	movzwl	20(%r12), %eax
	movw	%ax, -44(%rbp)
	movzwl	22(%r12), %eax
	movw	%ax, -42(%rbp)
	movzwl	24(%r12), %eax
	movw	%ax, -40(%rbp)
	movzwl	26(%r12), %eax
	movw	%ax, -38(%rbp)
	movzwl	28(%r12), %eax
	movw	%ax, -36(%rbp)
	movzwl	30(%r12), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 16(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%ax, 18(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%ax, 20(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%ax, 22(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%ax, 24(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%ax, 26(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%ax, 28(%rbx)
	movzwl	-18(%rbp), %eax
	movw	%ax, 30(%rbx)
	movzwl	32(%r12), %eax
	movw	%ax, -48(%rbp)
	movzwl	34(%r12), %eax
	movw	%ax, -46(%rbp)
	movzwl	36(%r12), %eax
	movw	%ax, -44(%rbp)
	movzwl	38(%r12), %eax
	movw	%ax, -42(%rbp)
	movzwl	40(%r12), %eax
	movw	%ax, -40(%rbp)
	movzwl	42(%r12), %eax
	movw	%ax, -38(%rbp)
	movzwl	44(%r12), %eax
	movw	%ax, -36(%rbp)
	movzwl	46(%r12), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 32(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%ax, 34(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%ax, 36(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%ax, 38(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%ax, 40(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%ax, 42(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%ax, 44(%rbx)
	movzwl	-18(%rbp), %eax
	movw	%ax, 46(%rbx)
	movzwl	48(%r12), %eax
	movw	%ax, -48(%rbp)
	movzwl	50(%r12), %eax
	movw	%ax, -46(%rbp)
	movzwl	52(%r12), %eax
	movw	%ax, -44(%rbp)
	movzwl	54(%r12), %eax
	movw	%ax, -42(%rbp)
	movzwl	56(%r12), %eax
	movw	%ax, -40(%rbp)
	movzwl	58(%r12), %eax
	movw	%ax, -38(%rbp)
	movzwl	60(%r12), %eax
	movw	%ax, -36(%rbp)
	movzwl	62(%r12), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 48(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%ax, 50(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%ax, 52(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%ax, 54(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%ax, 56(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%ax, 58(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%ax, 60(%rbx)
	movzwl	-18(%rbp), %eax
	movw	%ax, 62(%rbx)
	movzwl	64(%r12), %eax
	movw	%ax, -48(%rbp)
	movzwl	66(%r12), %eax
	movw	%ax, -46(%rbp)
	movzwl	68(%r12), %eax
	movw	%ax, -44(%rbp)
	movzwl	70(%r12), %eax
	movw	%ax, -42(%rbp)
	movzwl	72(%r12), %eax
	movw	%ax, -40(%rbp)
	movzwl	74(%r12), %eax
	movw	%ax, -38(%rbp)
	movzwl	76(%r12), %eax
	movw	%ax, -36(%rbp)
	movzwl	78(%r12), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 64(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%ax, 66(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%ax, 68(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%ax, 70(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%ax, 72(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%ax, 74(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%ax, 76(%rbx)
	movzwl	-18(%rbp), %eax
	movw	%ax, 78(%rbx)
	movzwl	80(%r12), %eax
	movw	%ax, -48(%rbp)
	movzwl	82(%r12), %eax
	movw	%ax, -46(%rbp)
	movzwl	84(%r12), %eax
	movw	%ax, -44(%rbp)
	movzwl	86(%r12), %eax
	movw	%ax, -42(%rbp)
	movzwl	88(%r12), %eax
	movw	%ax, -40(%rbp)
	movzwl	90(%r12), %eax
	movw	%ax, -38(%rbp)
	movzwl	92(%r12), %eax
	movw	%ax, -36(%rbp)
	movzwl	94(%r12), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 80(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%ax, 82(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%ax, 84(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%ax, 86(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%ax, 88(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%ax, 90(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%ax, 92(%rbx)
	movzwl	-18(%rbp), %eax
	movw	%ax, 94(%rbx)
	movzwl	96(%r12), %eax
	movw	%ax, -48(%rbp)
	movzwl	98(%r12), %eax
	movw	%ax, -46(%rbp)
	movzwl	100(%r12), %eax
	movw	%ax, -44(%rbp)
	movzwl	102(%r12), %eax
	movw	%ax, -42(%rbp)
	movzwl	104(%r12), %eax
	movw	%ax, -40(%rbp)
	movzwl	106(%r12), %eax
	movw	%ax, -38(%rbp)
	movzwl	108(%r12), %eax
	movw	%ax, -36(%rbp)
	movzwl	110(%r12), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 96(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%ax, 98(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%ax, 100(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%ax, 102(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%ax, 104(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%ax, 106(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%ax, 108(%rbx)
	movzwl	-18(%rbp), %eax
	movw	%ax, 110(%rbx)
	movzwl	112(%r12), %eax
	movw	%ax, -48(%rbp)
	movzwl	114(%r12), %eax
	movw	%ax, -46(%rbp)
	movzwl	116(%r12), %eax
	movw	%ax, -44(%rbp)
	movzwl	118(%r12), %eax
	movw	%ax, -42(%rbp)
	movzwl	120(%r12), %eax
	movw	%ax, -40(%rbp)
	movzwl	122(%r12), %eax
	movw	%ax, -38(%rbp)
	movzwl	124(%r12), %eax
	movw	%ax, -36(%rbp)
	movzwl	126(%r12), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-30(%rbp), %edx
	movzwl	-32(%rbp), %eax
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%dx, 114(%rbx)
	movzwl	-28(%rbp), %edx
	movw	%ax, 112(%rbx)
	movw	%ax, -34(%rbp)
	movw	%dx, 116(%rbx)
	movzwl	-26(%rbp), %edx
	movw	%dx, 118(%rbx)
	movzwl	-24(%rbp), %edx
	movw	%dx, 120(%rbx)
	movzwl	-22(%rbp), %edx
	movw	%dx, 122(%rbx)
	movzwl	-20(%rbp), %edx
	movw	%dx, 124(%rbx)
	movzwl	-18(%rbp), %edx
	movw	%dx, 126(%rbx)
	movzwl	(%rbx), %edx
	movw	%dx, -48(%rbp)
	movzwl	16(%rbx), %edx
	movw	%dx, -46(%rbp)
	movzwl	32(%rbx), %edx
	movw	%dx, -44(%rbp)
	movzwl	48(%rbx), %edx
	movw	%dx, -42(%rbp)
	movzwl	64(%rbx), %edx
	movw	%dx, -40(%rbp)
	movzwl	80(%rbx), %edx
	movw	%dx, -38(%rbp)
	movzwl	96(%rbx), %edx
	movw	%dx, -36(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	movzwl	-28(%rbp), %edx
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, (%rbx)
	movzwl	-30(%rbp), %eax
	movw	%dx, 4(%rbx)
	movzwl	-26(%rbp), %edx
	movw	%ax, 2(%rbx)
	movw	%ax, -48(%rbp)
	movzwl	18(%rbx), %eax
	movw	%dx, 6(%rbx)
	movzwl	-24(%rbp), %edx
	movw	%ax, -46(%rbp)
	movzwl	34(%rbx), %eax
	movw	%dx, 8(%rbx)
	movzwl	-22(%rbp), %edx
	movw	%ax, -44(%rbp)
	movzwl	50(%rbx), %eax
	movw	%dx, 10(%rbx)
	movzwl	-20(%rbp), %edx
	movw	%ax, -42(%rbp)
	movzwl	66(%rbx), %eax
	movw	%dx, 12(%rbx)
	movzwl	-18(%rbp), %edx
	movw	%ax, -40(%rbp)
	movzwl	82(%rbx), %eax
	movw	%dx, 14(%rbx)
	movw	%ax, -38(%rbp)
	movzwl	98(%rbx), %eax
	movw	%ax, -36(%rbp)
	movzwl	114(%rbx), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	movzwl	-26(%rbp), %edx
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 16(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%dx, 22(%rbx)
	movzwl	-24(%rbp), %edx
	movw	%ax, 18(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%dx, 24(%rbx)
	movzwl	-22(%rbp), %edx
	movw	%ax, 20(%rbx)
	movw	%ax, -46(%rbp)
	movzwl	36(%rbx), %eax
	movw	%dx, 26(%rbx)
	movzwl	-20(%rbp), %edx
	movw	%ax, -44(%rbp)
	movzwl	52(%rbx), %eax
	movw	%dx, 28(%rbx)
	movzwl	-18(%rbp), %edx
	movw	%ax, -42(%rbp)
	movzwl	68(%rbx), %eax
	movw	%dx, 30(%rbx)
	movzwl	4(%rbx), %edx
	movw	%ax, -40(%rbp)
	movzwl	84(%rbx), %eax
	movw	%dx, -48(%rbp)
	movw	%ax, -38(%rbp)
	movzwl	100(%rbx), %eax
	movw	%ax, -36(%rbp)
	movzwl	116(%rbx), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	movzwl	-24(%rbp), %edx
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 32(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%dx, 40(%rbx)
	movzwl	-22(%rbp), %edx
	movw	%ax, 34(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%dx, 42(%rbx)
	movzwl	-20(%rbp), %edx
	movw	%ax, 36(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%dx, 44(%rbx)
	movzwl	-18(%rbp), %edx
	movw	%ax, 38(%rbx)
	movw	%ax, -44(%rbp)
	movzwl	54(%rbx), %eax
	movw	%dx, 46(%rbx)
	movzwl	6(%rbx), %edx
	movw	%ax, -42(%rbp)
	movzwl	70(%rbx), %eax
	movw	%dx, -48(%rbp)
	movzwl	22(%rbx), %edx
	movw	%ax, -40(%rbp)
	movzwl	86(%rbx), %eax
	movw	%dx, -46(%rbp)
	movw	%ax, -38(%rbp)
	movzwl	102(%rbx), %eax
	movw	%ax, -36(%rbp)
	movzwl	118(%rbx), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	movzwl	-22(%rbp), %edx
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 48(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%dx, 58(%rbx)
	movzwl	-20(%rbp), %edx
	movw	%ax, 50(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%dx, 60(%rbx)
	movzwl	-18(%rbp), %edx
	movw	%ax, 52(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%dx, 62(%rbx)
	movzwl	8(%rbx), %edx
	movw	%ax, 54(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%dx, -48(%rbp)
	movzwl	24(%rbx), %edx
	movw	%ax, 56(%rbx)
	movw	%ax, -42(%rbp)
	movzwl	72(%rbx), %eax
	movw	%dx, -46(%rbp)
	movzwl	40(%rbx), %edx
	movw	%ax, -40(%rbp)
	movzwl	88(%rbx), %eax
	movw	%dx, -44(%rbp)
	movw	%ax, -38(%rbp)
	movzwl	104(%rbx), %eax
	movw	%ax, -36(%rbp)
	movzwl	120(%rbx), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	movzwl	-20(%rbp), %edx
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 64(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%dx, 76(%rbx)
	movzwl	-18(%rbp), %edx
	movw	%ax, 66(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%dx, 78(%rbx)
	movzwl	10(%rbx), %edx
	movw	%ax, 68(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%dx, -48(%rbp)
	movzwl	26(%rbx), %edx
	movw	%ax, 70(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%dx, -46(%rbp)
	movzwl	42(%rbx), %edx
	movw	%ax, 72(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%dx, -44(%rbp)
	movzwl	58(%rbx), %edx
	movw	%ax, 74(%rbx)
	movw	%ax, -40(%rbp)
	movzwl	90(%rbx), %eax
	movw	%dx, -42(%rbp)
	movw	%ax, -38(%rbp)
	movzwl	106(%rbx), %eax
	movw	%ax, -36(%rbp)
	movzwl	122(%rbx), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	movzwl	-18(%rbp), %edx
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 80(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%dx, 94(%rbx)
	movzwl	12(%rbx), %edx
	movw	%ax, 82(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%dx, -48(%rbp)
	movzwl	28(%rbx), %edx
	movw	%ax, 84(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%dx, -46(%rbp)
	movzwl	44(%rbx), %edx
	movw	%ax, 86(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%dx, -44(%rbp)
	movzwl	60(%rbx), %edx
	movw	%ax, 88(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%dx, -42(%rbp)
	movzwl	76(%rbx), %edx
	movw	%ax, 90(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%dx, -40(%rbp)
	movw	%ax, 92(%rbx)
	movw	%ax, -38(%rbp)
	movzwl	108(%rbx), %eax
	movw	%ax, -36(%rbp)
	movzwl	124(%rbx), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	movzwl	14(%rbx), %edx
	leaq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	movw	%ax, 96(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%dx, -48(%rbp)
	movzwl	30(%rbx), %edx
	movw	%ax, 98(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%dx, -46(%rbp)
	movzwl	46(%rbx), %edx
	movw	%ax, 100(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%dx, -44(%rbp)
	movzwl	62(%rbx), %edx
	movw	%ax, 102(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%dx, -42(%rbp)
	movzwl	78(%rbx), %edx
	movw	%ax, 104(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%dx, -40(%rbp)
	movzwl	94(%rbx), %edx
	movw	%ax, 106(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%dx, -38(%rbp)
	movw	%ax, 108(%rbx)
	movzwl	-18(%rbp), %eax
	movw	%ax, 110(%rbx)
	movw	%ax, -36(%rbp)
	movzwl	126(%rbx), %eax
	movw	%ax, -34(%rbp)
	call	_Z15fast_fixed_dct8PsS_
	movzwl	-32(%rbp), %eax
	movw	%ax, 112(%rbx)
	movzwl	-30(%rbp), %eax
	movw	%ax, 114(%rbx)
	movzwl	-28(%rbp), %eax
	movw	%ax, 116(%rbx)
	movzwl	-26(%rbp), %eax
	movw	%ax, 118(%rbx)
	movzwl	-24(%rbp), %eax
	movw	%ax, 120(%rbx)
	movzwl	-22(%rbp), %eax
	movw	%ax, 122(%rbx)
	movzwl	-20(%rbp), %eax
	movw	%ax, 124(%rbx)
	movzwl	-18(%rbp), %eax
	movw	%ax, 126(%rbx)
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE53:
	.size	_Z17fast_fixed_dct8x8PA8_sS0_, .-_Z17fast_fixed_dct8x8PA8_sS0_
	.p2align 4,,15
	.globl	dct8x8
	.type	dct8x8, @function
dct8x8:
.LFB50:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	mcount
	popq	%rbp
	.cfi_def_cfa 7, 8
	jmp	_Z17fast_fixed_dct8x8PA8_sS0_
	.cfi_endproc
.LFE50:
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
.LC0:
	.long	0
	.long	1072693248
	.align 8
.LC1:
	.long	776530087
	.long	1074340351
	.align 8
.LC2:
	.long	0
	.long	1068498944
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC4:
	.long	1060439284
	.align 4
.LC5:
	.long	1056964608
	.section	.rodata.cst8
	.align 8
.LC6:
	.long	2682266409
	.long	1072652951
	.align 8
.LC7:
	.long	2385801317
	.long	1072339812
	.align 8
.LC8:
	.long	954203976
	.long	1071761207
	.align 8
.LC9:
	.long	3404157506
	.long	1070135453
	.align 8
.LC10:
	.long	1007654293
	.long	-1077348134
	.align 8
.LC11:
	.long	138405437
	.long	-1075722428
	.align 8
.LC12:
	.long	493374193
	.long	-1075143827
	.align 8
.LC13:
	.long	2706395798
	.long	-1074830694
	.align 8
.LC14:
	.long	310895059
	.long	1072533611
	.align 8
.LC15:
	.long	4190844819
	.long	1071152599
	.align 8
.LC16:
	.long	1904036756
	.long	-1076331020
	.align 8
.LC17:
	.long	4158275044
	.long	-1074950032
	.align 8
.LC18:
	.long	758033258
	.long	-1074950043
	.align 8
.LC19:
	.long	2182313527
	.long	-1076331077
	.align 8
.LC20:
	.long	3911823931
	.long	1071152656
	.align 8
.LC21:
	.long	3710238620
	.long	1072533622
	.align 8
.LC22:
	.long	1769732443
	.long	-1075722454
	.align 8
.LC23:
	.long	3617304119
	.long	1071761232
	.align 8
.LC24:
	.long	2632577308
	.long	1072652945
	.align 8
.LC25:
	.long	3901058613
	.long	1070135332
	.align 8
.LC26:
	.long	1002274655
	.long	-1075143810
	.align 8
.LC27:
	.long	2907089005
	.long	1072079003
	.align 8
.LC28:
	.long	2452029028
	.long	-1075404634
	.align 8
.LC29:
	.long	3361805245
	.long	-1075404656
	.align 8
.LC30:
	.long	1996625314
	.long	1072079025
	.align 8
.LC31:
	.long	3816177753
	.long	1072078981
	.align 8
.LC32:
	.long	1540877863
	.long	-1075404612
	.align 8
.LC33:
	.long	4270206527
	.long	-1075404678
	.align 8
.LC34:
	.long	1084786668
	.long	1072079047
	.align 8
.LC35:
	.long	2905739007
	.long	1070135574
	.align 8
.LC36:
	.long	1874475699
	.long	1072339795
	.align 8
.LC37:
	.long	2001456535
	.long	-1077348376
	.align 8
.LC38:
	.long	2580981108
	.long	1072652939
	.align 8
.LC39:
	.long	1167477809
	.long	-1075722377
	.align 8
.LC40:
	.long	1624271746
	.long	-1076330963
	.align 8
.LC41:
	.long	2459102110
	.long	-1076331134
	.align 8
.LC42:
	.long	2096753193
	.long	1072533587
	.align 8
.LC43:
	.long	2363434648
	.long	-1074950008
	.align 8
.LC44:
	.long	3349317251
	.long	1071152770
	.align 8
.LC45:
	.long	2607017594
	.long	-1074830706
	.align 8
.LC46:
	.long	2775923299
	.long	1072652963
	.align 8
.LC47:
	.long	1509558341
	.long	-1075143793
	.align 8
.LC48:
	.long	350328874
	.long	1071761284
	.align 8
.LC49:
	.long	3800537274
	.long	-1077347772
	.align 8
.LC50:
	.long	769658139
	.long	1072078992
	.align 8
.LC51:
	.long	769658139
	.long	-1075404656
	.align 8
.LC52:
	.long	1094014070
	.long	1071152596
	.align 8
.LC53:
	.long	3391993372
	.long	1072533612
	.align 8
.LC54:
	.long	3391993372
	.long	-1074950036
	.align 8
.LC55:
	.long	1807322238
	.long	1070135561
	.align 8
.LC56:
	.long	3172091046
	.long	1072652940
	.align 8
.LC57:
	.long	0
	.long	1071644672
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC58:
	.long	2147483648
	.long	0
	.long	0
	.long	0
	.section	.rodata.cst8
	.align 8
.LC59:
	.long	8246337
	.long	1072339794
	.align 8
.LC60:
	.long	3041524040
	.long	1071761231
	.align 8
.LC61:
	.long	3041524040
	.long	-1075722417
	.align 8
.LC62:
	.long	3172091046
	.long	-1074830708
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
