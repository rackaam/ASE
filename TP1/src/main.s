GAS LISTING /tmp/ccJXpt5V.s 			page 1


   1              		.file	"main.cpp"
   2              		.section	.text._ZN7CBitmap7DisposeEv,"axG",@progbits,_ZN7CBitmap7DisposeEv,comdat
   3              		.align 2
   4              		.p2align 4,,15
   5              		.weak	_ZN7CBitmap7DisposeEv
   6              		.type	_ZN7CBitmap7DisposeEv, @function
   7              	_ZN7CBitmap7DisposeEv:
   8              	.LFB95:
   9              		.cfi_startproc
  10 0000 55       		pushl	%ebp
  11              		.cfi_def_cfa_offset 8
  12 0001 89E5     		movl	%esp, %ebp
  13              		.cfi_offset 5, -8
  14              		.cfi_def_cfa_register 5
  15 0003 57       		pushl	%edi
  16 0004 53       		pushl	%ebx
  17 0005 83EC10   		subl	$16, %esp
  18 0008 E8FCFFFF 		call	mcount
  18      FF
  19 000d 8B5D08   		movl	8(%ebp), %ebx
  20              		.cfi_offset 3, -16
  21              		.cfi_offset 7, -12
  22 0010 8B437C   		movl	124(%ebx), %eax
  23 0013 85C0     		testl	%eax, %eax
  24 0015 7408     		je	.L2
  25 0017 890424   		movl	%eax, (%esp)
  26 001a E8FCFFFF 		call	_ZdaPv
  26      FF
  27              	.L2:
  28 001f 8D7B0E   		leal	14(%ebx), %edi
  29 0022 BA6C0000 		movl	$108, %edx
  29      00
  30 0027 F7C70200 		testl	$2, %edi
  30      0000
  31 002d C7437C00 		movl	$0, 124(%ebx)
  31      000000
  32 0034 C7030000 		movl	$0, (%ebx)
  32      0000
  33 003a C7430400 		movl	$0, 4(%ebx)
  33      000000
  34 0041 C7430800 		movl	$0, 8(%ebx)
  34      000000
  35 0048 66C7430C 		movw	$0, 12(%ebx)
  35      0000
  36 004e 7530     		jne	.L7
  37              	.L3:
  38 0050 89D1     		movl	%edx, %ecx
  39 0052 31C0     		xorl	%eax, %eax
  40 0054 C1E902   		shrl	$2, %ecx
  41 0057 83E202   		andl	$2, %edx
  42 005a F3AB     		rep stosl
  43 005c 7405     		je	.L5
  44 005e 66C70700 		movw	$0, (%edi)
  44      00
  45              	.L5:
  46 0063 C7838400 		movl	$0, 132(%ebx)
  46      00000000 
GAS LISTING /tmp/ccJXpt5V.s 			page 2


  46      0000
  47 006d C7838800 		movl	$0, 136(%ebx)
  47      00000000 
  47      0000
  48 0077 83C410   		addl	$16, %esp
  49 007a 5B       		popl	%ebx
  50              		.cfi_remember_state
  51              		.cfi_restore 3
  52 007b 5F       		popl	%edi
  53              		.cfi_restore 7
  54 007c 5D       		popl	%ebp
  55              		.cfi_restore 5
  56              		.cfi_def_cfa 4, 4
  57 007d C3       		ret
  58 007e 6690     		.p2align 4,,7
  59              		.p2align 3
  60              	.L7:
  61              		.cfi_restore_state
  62 0080 66C7430E 		movw	$0, 14(%ebx)
  62      0000
  63 0086 8D7B10   		leal	16(%ebx), %edi
  64 0089 B26A     		movb	$106, %dl
  65 008b EBC3     		jmp	.L3
  66              		.cfi_endproc
  67              	.LFE95:
  68              		.size	_ZN7CBitmap7DisposeEv, .-_ZN7CBitmap7DisposeEv
  69              		.text
  70              		.p2align 4,,15
  71              	.globl correct_color
  72              		.type	correct_color, @function
  73              	correct_color:
  74              	.LFB114:
  75              		.cfi_startproc
  76 0000 55       		pushl	%ebp
  77              		.cfi_def_cfa_offset 8
  78 0001 89E5     		movl	%esp, %ebp
  79              		.cfi_offset 5, -8
  80              		.cfi_def_cfa_register 5
  81 0003 53       		pushl	%ebx
  82 0004 E8FCFFFF 		call	mcount
  82      FF
  83 0009 8B4508   		movl	8(%ebp), %eax
  84 000c 0FB710   		movzwl	(%eax), %edx
  85 000f 6685D2   		testw	%dx, %dx
  86 0012 0F888807 		js	.L209
  86      0000
  87              		.cfi_offset 3, -12
  88 0018 6681FA00 		cmpw	$256, %dx
  88      01
  89 001d B9FF0000 		movl	$255, %ecx
  89      00
  90 0022 0F4DD1   		cmovge	%ecx, %edx
  91 0025 668910   		movw	%dx, (%eax)
  92 0028 0FB75002 		movzwl	2(%eax), %edx
  93 002c 6685D2   		testw	%dx, %dx
  94 002f 0F887D07 		js	.L210
  94      0000
GAS LISTING /tmp/ccJXpt5V.s 			page 3


  95              	.L12:
  96 0035 6681FA00 		cmpw	$256, %dx
  96      01
  97 003a B9FF0000 		movl	$255, %ecx
  97      00
  98 003f 0F4DD1   		cmovge	%ecx, %edx
  99 0042 66895002 		movw	%dx, 2(%eax)
 100 0046 0FB75004 		movzwl	4(%eax), %edx
 101 004a 6685D2   		testw	%dx, %dx
 102 004d 0F887207 		js	.L211
 102      0000
 103              	.L15:
 104 0053 6681FA00 		cmpw	$256, %dx
 104      01
 105 0058 B9FF0000 		movl	$255, %ecx
 105      00
 106 005d 0F4DD1   		cmovge	%ecx, %edx
 107 0060 66895004 		movw	%dx, 4(%eax)
 108 0064 0FB75006 		movzwl	6(%eax), %edx
 109 0068 6685D2   		testw	%dx, %dx
 110 006b 0F886707 		js	.L212
 110      0000
 111              	.L18:
 112 0071 6681FA00 		cmpw	$256, %dx
 112      01
 113 0076 B9FF0000 		movl	$255, %ecx
 113      00
 114 007b 0F4DD1   		cmovge	%ecx, %edx
 115 007e 66895006 		movw	%dx, 6(%eax)
 116 0082 0FB75008 		movzwl	8(%eax), %edx
 117 0086 6685D2   		testw	%dx, %dx
 118 0089 0F885C07 		js	.L213
 118      0000
 119              	.L21:
 120 008f 6681FA00 		cmpw	$256, %dx
 120      01
 121 0094 B9FF0000 		movl	$255, %ecx
 121      00
 122 0099 0F4DD1   		cmovge	%ecx, %edx
 123 009c 66895008 		movw	%dx, 8(%eax)
 124 00a0 0FB7500A 		movzwl	10(%eax), %edx
 125 00a4 6685D2   		testw	%dx, %dx
 126 00a7 0F885107 		js	.L214
 126      0000
 127              	.L24:
 128 00ad 6681FA00 		cmpw	$256, %dx
 128      01
 129 00b2 B9FF0000 		movl	$255, %ecx
 129      00
 130 00b7 0F4DD1   		cmovge	%ecx, %edx
 131 00ba 6689500A 		movw	%dx, 10(%eax)
 132 00be 0FB7500C 		movzwl	12(%eax), %edx
 133 00c2 6685D2   		testw	%dx, %dx
 134 00c5 0F884607 		js	.L215
 134      0000
 135              	.L27:
 136 00cb 6681FA00 		cmpw	$256, %dx
GAS LISTING /tmp/ccJXpt5V.s 			page 4


 136      01
 137 00d0 B9FF0000 		movl	$255, %ecx
 137      00
 138 00d5 0F4DD1   		cmovge	%ecx, %edx
 139 00d8 6689500C 		movw	%dx, 12(%eax)
 140 00dc 0FB7500E 		movzwl	14(%eax), %edx
 141 00e0 6685D2   		testw	%dx, %dx
 142 00e3 0F883B07 		js	.L216
 142      0000
 143              	.L30:
 144 00e9 6681FA00 		cmpw	$256, %dx
 144      01
 145 00ee B9FF0000 		movl	$255, %ecx
 145      00
 146 00f3 0F4DD1   		cmovge	%ecx, %edx
 147 00f6 0FB74810 		movzwl	16(%eax), %ecx
 148 00fa 6689500E 		movw	%dx, 14(%eax)
 149 00fe 8D5010   		leal	16(%eax), %edx
 150 0101 6685C9   		testw	%cx, %cx
 151 0104 0F883007 		js	.L217
 151      0000
 152              	.L33:
 153 010a 6681F900 		cmpw	$256, %cx
 153      01
 154 010f BBFF0000 		movl	$255, %ebx
 154      00
 155 0114 0F4DCB   		cmovge	%ebx, %ecx
 156 0117 66894810 		movw	%cx, 16(%eax)
 157 011b 0FB74A02 		movzwl	2(%edx), %ecx
 158 011f 6685C9   		testw	%cx, %cx
 159 0122 0F882507 		js	.L218
 159      0000
 160              	.L36:
 161 0128 6681F900 		cmpw	$256, %cx
 161      01
 162 012d BBFF0000 		movl	$255, %ebx
 162      00
 163 0132 0F4DCB   		cmovge	%ebx, %ecx
 164 0135 66894A02 		movw	%cx, 2(%edx)
 165 0139 0FB74A04 		movzwl	4(%edx), %ecx
 166 013d 6685C9   		testw	%cx, %cx
 167 0140 0F881A07 		js	.L219
 167      0000
 168              	.L39:
 169 0146 6681F900 		cmpw	$256, %cx
 169      01
 170 014b BBFF0000 		movl	$255, %ebx
 170      00
 171 0150 0F4DCB   		cmovge	%ebx, %ecx
 172 0153 66894A04 		movw	%cx, 4(%edx)
 173 0157 0FB74A06 		movzwl	6(%edx), %ecx
 174 015b 6685C9   		testw	%cx, %cx
 175 015e 0F880F07 		js	.L220
 175      0000
 176              	.L42:
 177 0164 6681F900 		cmpw	$256, %cx
 177      01
GAS LISTING /tmp/ccJXpt5V.s 			page 5


 178 0169 BBFF0000 		movl	$255, %ebx
 178      00
 179 016e 0F4DCB   		cmovge	%ebx, %ecx
 180 0171 66894A06 		movw	%cx, 6(%edx)
 181 0175 0FB74A08 		movzwl	8(%edx), %ecx
 182 0179 6685C9   		testw	%cx, %cx
 183 017c 0F880407 		js	.L221
 183      0000
 184              	.L45:
 185 0182 6681F900 		cmpw	$256, %cx
 185      01
 186 0187 BBFF0000 		movl	$255, %ebx
 186      00
 187 018c 0F4DCB   		cmovge	%ebx, %ecx
 188 018f 66894A08 		movw	%cx, 8(%edx)
 189 0193 0FB74A0A 		movzwl	10(%edx), %ecx
 190 0197 6685C9   		testw	%cx, %cx
 191 019a 0F88F906 		js	.L222
 191      0000
 192              	.L48:
 193 01a0 6681F900 		cmpw	$256, %cx
 193      01
 194 01a5 BBFF0000 		movl	$255, %ebx
 194      00
 195 01aa 0F4DCB   		cmovge	%ebx, %ecx
 196 01ad 66894A0A 		movw	%cx, 10(%edx)
 197 01b1 0FB74A0C 		movzwl	12(%edx), %ecx
 198 01b5 6685C9   		testw	%cx, %cx
 199 01b8 0F88EE06 		js	.L223
 199      0000
 200              	.L51:
 201 01be 6681F900 		cmpw	$256, %cx
 201      01
 202 01c3 BBFF0000 		movl	$255, %ebx
 202      00
 203 01c8 0F4DCB   		cmovge	%ebx, %ecx
 204 01cb 66894A0C 		movw	%cx, 12(%edx)
 205 01cf 0FB74A0E 		movzwl	14(%edx), %ecx
 206 01d3 6685C9   		testw	%cx, %cx
 207 01d6 0F88E306 		js	.L224
 207      0000
 208              	.L54:
 209 01dc 6681F900 		cmpw	$256, %cx
 209      01
 210 01e1 BBFF0000 		movl	$255, %ebx
 210      00
 211 01e6 0F4DCB   		cmovge	%ebx, %ecx
 212 01e9 66894A0E 		movw	%cx, 14(%edx)
 213 01ed 0FB74820 		movzwl	32(%eax), %ecx
 214 01f1 8D5020   		leal	32(%eax), %edx
 215 01f4 6685C9   		testw	%cx, %cx
 216 01f7 0F88D806 		js	.L225
 216      0000
 217              	.L57:
 218 01fd 6681F900 		cmpw	$256, %cx
 218      01
 219 0202 BBFF0000 		movl	$255, %ebx
GAS LISTING /tmp/ccJXpt5V.s 			page 6


 219      00
 220 0207 0F4DCB   		cmovge	%ebx, %ecx
 221 020a 66894820 		movw	%cx, 32(%eax)
 222 020e 0FB74A02 		movzwl	2(%edx), %ecx
 223 0212 6685C9   		testw	%cx, %cx
 224 0215 0F88CD06 		js	.L226
 224      0000
 225              	.L60:
 226 021b 6681F900 		cmpw	$256, %cx
 226      01
 227 0220 BBFF0000 		movl	$255, %ebx
 227      00
 228 0225 0F4DCB   		cmovge	%ebx, %ecx
 229 0228 66894A02 		movw	%cx, 2(%edx)
 230 022c 0FB74A04 		movzwl	4(%edx), %ecx
 231 0230 6685C9   		testw	%cx, %cx
 232 0233 0F88C206 		js	.L227
 232      0000
 233              	.L63:
 234 0239 6681F900 		cmpw	$256, %cx
 234      01
 235 023e BBFF0000 		movl	$255, %ebx
 235      00
 236 0243 0F4DCB   		cmovge	%ebx, %ecx
 237 0246 66894A04 		movw	%cx, 4(%edx)
 238 024a 0FB74A06 		movzwl	6(%edx), %ecx
 239 024e 6685C9   		testw	%cx, %cx
 240 0251 0F88B706 		js	.L228
 240      0000
 241              	.L66:
 242 0257 6681F900 		cmpw	$256, %cx
 242      01
 243 025c BBFF0000 		movl	$255, %ebx
 243      00
 244 0261 0F4DCB   		cmovge	%ebx, %ecx
 245 0264 66894A06 		movw	%cx, 6(%edx)
 246 0268 0FB74A08 		movzwl	8(%edx), %ecx
 247 026c 6685C9   		testw	%cx, %cx
 248 026f 0F88AC06 		js	.L229
 248      0000
 249              	.L69:
 250 0275 6681F900 		cmpw	$256, %cx
 250      01
 251 027a BBFF0000 		movl	$255, %ebx
 251      00
 252 027f 0F4DCB   		cmovge	%ebx, %ecx
 253 0282 66894A08 		movw	%cx, 8(%edx)
 254 0286 0FB74A0A 		movzwl	10(%edx), %ecx
 255 028a 6685C9   		testw	%cx, %cx
 256 028d 0F88A106 		js	.L230
 256      0000
 257              	.L72:
 258 0293 6681F900 		cmpw	$256, %cx
 258      01
 259 0298 BBFF0000 		movl	$255, %ebx
 259      00
 260 029d 0F4DCB   		cmovge	%ebx, %ecx
GAS LISTING /tmp/ccJXpt5V.s 			page 7


 261 02a0 66894A0A 		movw	%cx, 10(%edx)
 262 02a4 0FB74A0C 		movzwl	12(%edx), %ecx
 263 02a8 6685C9   		testw	%cx, %cx
 264 02ab 0F889606 		js	.L231
 264      0000
 265              	.L75:
 266 02b1 6681F900 		cmpw	$256, %cx
 266      01
 267 02b6 BBFF0000 		movl	$255, %ebx
 267      00
 268 02bb 0F4DCB   		cmovge	%ebx, %ecx
 269 02be 66894A0C 		movw	%cx, 12(%edx)
 270 02c2 0FB74A0E 		movzwl	14(%edx), %ecx
 271 02c6 6685C9   		testw	%cx, %cx
 272 02c9 0F888B06 		js	.L232
 272      0000
 273              	.L78:
 274 02cf 6681F900 		cmpw	$256, %cx
 274      01
 275 02d4 BBFF0000 		movl	$255, %ebx
 275      00
 276 02d9 0F4DCB   		cmovge	%ebx, %ecx
 277 02dc 66894A0E 		movw	%cx, 14(%edx)
 278 02e0 0FB74830 		movzwl	48(%eax), %ecx
 279 02e4 8D5030   		leal	48(%eax), %edx
 280 02e7 6685C9   		testw	%cx, %cx
 281 02ea 0F888006 		js	.L233
 281      0000
 282              	.L81:
 283 02f0 6681F900 		cmpw	$256, %cx
 283      01
 284 02f5 BBFF0000 		movl	$255, %ebx
 284      00
 285 02fa 0F4DCB   		cmovge	%ebx, %ecx
 286 02fd 66894830 		movw	%cx, 48(%eax)
 287 0301 0FB74A02 		movzwl	2(%edx), %ecx
 288 0305 6685C9   		testw	%cx, %cx
 289 0308 0F887506 		js	.L234
 289      0000
 290              	.L84:
 291 030e 6681F900 		cmpw	$256, %cx
 291      01
 292 0313 BBFF0000 		movl	$255, %ebx
 292      00
 293 0318 0F4DCB   		cmovge	%ebx, %ecx
 294 031b 66894A02 		movw	%cx, 2(%edx)
 295 031f 0FB74A04 		movzwl	4(%edx), %ecx
 296 0323 6685C9   		testw	%cx, %cx
 297 0326 0F886A06 		js	.L235
 297      0000
 298              	.L87:
 299 032c 6681F900 		cmpw	$256, %cx
 299      01
 300 0331 BBFF0000 		movl	$255, %ebx
 300      00
 301 0336 0F4DCB   		cmovge	%ebx, %ecx
 302 0339 66894A04 		movw	%cx, 4(%edx)
GAS LISTING /tmp/ccJXpt5V.s 			page 8


 303 033d 0FB74A06 		movzwl	6(%edx), %ecx
 304 0341 6685C9   		testw	%cx, %cx
 305 0344 0F885F06 		js	.L236
 305      0000
 306              	.L90:
 307 034a 6681F900 		cmpw	$256, %cx
 307      01
 308 034f BBFF0000 		movl	$255, %ebx
 308      00
 309 0354 0F4DCB   		cmovge	%ebx, %ecx
 310 0357 66894A06 		movw	%cx, 6(%edx)
 311 035b 0FB74A08 		movzwl	8(%edx), %ecx
 312 035f 6685C9   		testw	%cx, %cx
 313 0362 0F885406 		js	.L237
 313      0000
 314              	.L93:
 315 0368 6681F900 		cmpw	$256, %cx
 315      01
 316 036d BBFF0000 		movl	$255, %ebx
 316      00
 317 0372 0F4DCB   		cmovge	%ebx, %ecx
 318 0375 66894A08 		movw	%cx, 8(%edx)
 319 0379 0FB74A0A 		movzwl	10(%edx), %ecx
 320 037d 6685C9   		testw	%cx, %cx
 321 0380 0F884906 		js	.L238
 321      0000
 322              	.L96:
 323 0386 6681F900 		cmpw	$256, %cx
 323      01
 324 038b BBFF0000 		movl	$255, %ebx
 324      00
 325 0390 0F4DCB   		cmovge	%ebx, %ecx
 326 0393 66894A0A 		movw	%cx, 10(%edx)
 327 0397 0FB74A0C 		movzwl	12(%edx), %ecx
 328 039b 6685C9   		testw	%cx, %cx
 329 039e 0F883E06 		js	.L239
 329      0000
 330              	.L99:
 331 03a4 6681F900 		cmpw	$256, %cx
 331      01
 332 03a9 BBFF0000 		movl	$255, %ebx
 332      00
 333 03ae 0F4DCB   		cmovge	%ebx, %ecx
 334 03b1 66894A0C 		movw	%cx, 12(%edx)
 335 03b5 0FB74A0E 		movzwl	14(%edx), %ecx
 336 03b9 6685C9   		testw	%cx, %cx
 337 03bc 0F883306 		js	.L240
 337      0000
 338              	.L102:
 339 03c2 6681F900 		cmpw	$256, %cx
 339      01
 340 03c7 BBFF0000 		movl	$255, %ebx
 340      00
 341 03cc 0F4DCB   		cmovge	%ebx, %ecx
 342 03cf 66894A0E 		movw	%cx, 14(%edx)
 343 03d3 0FB74840 		movzwl	64(%eax), %ecx
 344 03d7 8D5040   		leal	64(%eax), %edx
GAS LISTING /tmp/ccJXpt5V.s 			page 9


 345 03da 6685C9   		testw	%cx, %cx
 346 03dd 0F882806 		js	.L241
 346      0000
 347              	.L105:
 348 03e3 6681F900 		cmpw	$256, %cx
 348      01
 349 03e8 BBFF0000 		movl	$255, %ebx
 349      00
 350 03ed 0F4DCB   		cmovge	%ebx, %ecx
 351 03f0 66894840 		movw	%cx, 64(%eax)
 352 03f4 0FB74A02 		movzwl	2(%edx), %ecx
 353 03f8 6685C9   		testw	%cx, %cx
 354 03fb 0F881D06 		js	.L242
 354      0000
 355              	.L108:
 356 0401 6681F900 		cmpw	$256, %cx
 356      01
 357 0406 BBFF0000 		movl	$255, %ebx
 357      00
 358 040b 0F4DCB   		cmovge	%ebx, %ecx
 359 040e 66894A02 		movw	%cx, 2(%edx)
 360 0412 0FB74A04 		movzwl	4(%edx), %ecx
 361 0416 6685C9   		testw	%cx, %cx
 362 0419 0F881206 		js	.L243
 362      0000
 363              	.L111:
 364 041f 6681F900 		cmpw	$256, %cx
 364      01
 365 0424 BBFF0000 		movl	$255, %ebx
 365      00
 366 0429 0F4DCB   		cmovge	%ebx, %ecx
 367 042c 66894A04 		movw	%cx, 4(%edx)
 368 0430 0FB74A06 		movzwl	6(%edx), %ecx
 369 0434 6685C9   		testw	%cx, %cx
 370 0437 0F880706 		js	.L244
 370      0000
 371              	.L114:
 372 043d 6681F900 		cmpw	$256, %cx
 372      01
 373 0442 BBFF0000 		movl	$255, %ebx
 373      00
 374 0447 0F4DCB   		cmovge	%ebx, %ecx
 375 044a 66894A06 		movw	%cx, 6(%edx)
 376 044e 0FB74A08 		movzwl	8(%edx), %ecx
 377 0452 6685C9   		testw	%cx, %cx
 378 0455 0F88FC05 		js	.L245
 378      0000
 379              	.L117:
 380 045b 6681F900 		cmpw	$256, %cx
 380      01
 381 0460 BBFF0000 		movl	$255, %ebx
 381      00
 382 0465 0F4DCB   		cmovge	%ebx, %ecx
 383 0468 66894A08 		movw	%cx, 8(%edx)
 384 046c 0FB74A0A 		movzwl	10(%edx), %ecx
 385 0470 6685C9   		testw	%cx, %cx
 386 0473 0F88F105 		js	.L246
GAS LISTING /tmp/ccJXpt5V.s 			page 10


 386      0000
 387              	.L120:
 388 0479 6681F900 		cmpw	$256, %cx
 388      01
 389 047e BBFF0000 		movl	$255, %ebx
 389      00
 390 0483 0F4DCB   		cmovge	%ebx, %ecx
 391 0486 66894A0A 		movw	%cx, 10(%edx)
 392 048a 0FB74A0C 		movzwl	12(%edx), %ecx
 393 048e 6685C9   		testw	%cx, %cx
 394 0491 0F88E605 		js	.L247
 394      0000
 395              	.L123:
 396 0497 6681F900 		cmpw	$256, %cx
 396      01
 397 049c BBFF0000 		movl	$255, %ebx
 397      00
 398 04a1 0F4DCB   		cmovge	%ebx, %ecx
 399 04a4 66894A0C 		movw	%cx, 12(%edx)
 400 04a8 0FB74A0E 		movzwl	14(%edx), %ecx
 401 04ac 6685C9   		testw	%cx, %cx
 402 04af 0F88DB05 		js	.L248
 402      0000
 403              	.L126:
 404 04b5 6681F900 		cmpw	$256, %cx
 404      01
 405 04ba BBFF0000 		movl	$255, %ebx
 405      00
 406 04bf 0F4DCB   		cmovge	%ebx, %ecx
 407 04c2 66894A0E 		movw	%cx, 14(%edx)
 408 04c6 0FB74850 		movzwl	80(%eax), %ecx
 409 04ca 8D5050   		leal	80(%eax), %edx
 410 04cd 6685C9   		testw	%cx, %cx
 411 04d0 0F88D005 		js	.L249
 411      0000
 412              	.L129:
 413 04d6 6681F900 		cmpw	$256, %cx
 413      01
 414 04db BBFF0000 		movl	$255, %ebx
 414      00
 415 04e0 0F4DCB   		cmovge	%ebx, %ecx
 416 04e3 66894850 		movw	%cx, 80(%eax)
 417 04e7 0FB74A02 		movzwl	2(%edx), %ecx
 418 04eb 6685C9   		testw	%cx, %cx
 419 04ee 0F88C505 		js	.L250
 419      0000
 420              	.L132:
 421 04f4 6681F900 		cmpw	$256, %cx
 421      01
 422 04f9 BBFF0000 		movl	$255, %ebx
 422      00
 423 04fe 0F4DCB   		cmovge	%ebx, %ecx
 424 0501 66894A02 		movw	%cx, 2(%edx)
 425 0505 0FB74A04 		movzwl	4(%edx), %ecx
 426 0509 6685C9   		testw	%cx, %cx
 427 050c 0F88BA05 		js	.L251
 427      0000
GAS LISTING /tmp/ccJXpt5V.s 			page 11


 428              	.L135:
 429 0512 6681F900 		cmpw	$256, %cx
 429      01
 430 0517 BBFF0000 		movl	$255, %ebx
 430      00
 431 051c 0F4DCB   		cmovge	%ebx, %ecx
 432 051f 66894A04 		movw	%cx, 4(%edx)
 433 0523 0FB74A06 		movzwl	6(%edx), %ecx
 434 0527 6685C9   		testw	%cx, %cx
 435 052a 0F88AF05 		js	.L252
 435      0000
 436              	.L138:
 437 0530 6681F900 		cmpw	$256, %cx
 437      01
 438 0535 BBFF0000 		movl	$255, %ebx
 438      00
 439 053a 0F4DCB   		cmovge	%ebx, %ecx
 440 053d 66894A06 		movw	%cx, 6(%edx)
 441 0541 0FB74A08 		movzwl	8(%edx), %ecx
 442 0545 6685C9   		testw	%cx, %cx
 443 0548 0F88A405 		js	.L253
 443      0000
 444              	.L141:
 445 054e 6681F900 		cmpw	$256, %cx
 445      01
 446 0553 BBFF0000 		movl	$255, %ebx
 446      00
 447 0558 0F4DCB   		cmovge	%ebx, %ecx
 448 055b 66894A08 		movw	%cx, 8(%edx)
 449 055f 0FB74A0A 		movzwl	10(%edx), %ecx
 450 0563 6685C9   		testw	%cx, %cx
 451 0566 0F889905 		js	.L254
 451      0000
 452              	.L144:
 453 056c 6681F900 		cmpw	$256, %cx
 453      01
 454 0571 BBFF0000 		movl	$255, %ebx
 454      00
 455 0576 0F4DCB   		cmovge	%ebx, %ecx
 456 0579 66894A0A 		movw	%cx, 10(%edx)
 457 057d 0FB74A0C 		movzwl	12(%edx), %ecx
 458 0581 6685C9   		testw	%cx, %cx
 459 0584 0F888E05 		js	.L255
 459      0000
 460              	.L147:
 461 058a 6681F900 		cmpw	$256, %cx
 461      01
 462 058f BBFF0000 		movl	$255, %ebx
 462      00
 463 0594 0F4DCB   		cmovge	%ebx, %ecx
 464 0597 66894A0C 		movw	%cx, 12(%edx)
 465 059b 0FB74A0E 		movzwl	14(%edx), %ecx
 466 059f 6685C9   		testw	%cx, %cx
 467 05a2 0F888305 		js	.L256
 467      0000
 468              	.L150:
 469 05a8 6681F900 		cmpw	$256, %cx
GAS LISTING /tmp/ccJXpt5V.s 			page 12


 469      01
 470 05ad BBFF0000 		movl	$255, %ebx
 470      00
 471 05b2 0F4DCB   		cmovge	%ebx, %ecx
 472 05b5 66894A0E 		movw	%cx, 14(%edx)
 473 05b9 0FB74860 		movzwl	96(%eax), %ecx
 474 05bd 8D5060   		leal	96(%eax), %edx
 475 05c0 6685C9   		testw	%cx, %cx
 476 05c3 0F887805 		js	.L257
 476      0000
 477              	.L153:
 478 05c9 6681F900 		cmpw	$256, %cx
 478      01
 479 05ce BBFF0000 		movl	$255, %ebx
 479      00
 480 05d3 0F4DCB   		cmovge	%ebx, %ecx
 481 05d6 66894860 		movw	%cx, 96(%eax)
 482 05da 0FB74A02 		movzwl	2(%edx), %ecx
 483 05de 6685C9   		testw	%cx, %cx
 484 05e1 0F886D05 		js	.L258
 484      0000
 485              	.L156:
 486 05e7 6681F900 		cmpw	$256, %cx
 486      01
 487 05ec BBFF0000 		movl	$255, %ebx
 487      00
 488 05f1 0F4DCB   		cmovge	%ebx, %ecx
 489 05f4 66894A02 		movw	%cx, 2(%edx)
 490 05f8 0FB74A04 		movzwl	4(%edx), %ecx
 491 05fc 6685C9   		testw	%cx, %cx
 492 05ff 0F886205 		js	.L259
 492      0000
 493              	.L159:
 494 0605 6681F900 		cmpw	$256, %cx
 494      01
 495 060a BBFF0000 		movl	$255, %ebx
 495      00
 496 060f 0F4DCB   		cmovge	%ebx, %ecx
 497 0612 66894A04 		movw	%cx, 4(%edx)
 498 0616 0FB74A06 		movzwl	6(%edx), %ecx
 499 061a 6685C9   		testw	%cx, %cx
 500 061d 0F885705 		js	.L260
 500      0000
 501              	.L162:
 502 0623 6681F900 		cmpw	$256, %cx
 502      01
 503 0628 BBFF0000 		movl	$255, %ebx
 503      00
 504 062d 0F4DCB   		cmovge	%ebx, %ecx
 505 0630 66894A06 		movw	%cx, 6(%edx)
 506 0634 0FB74A08 		movzwl	8(%edx), %ecx
 507 0638 6685C9   		testw	%cx, %cx
 508 063b 0F884C05 		js	.L261
 508      0000
 509              	.L165:
 510 0641 6681F900 		cmpw	$256, %cx
 510      01
GAS LISTING /tmp/ccJXpt5V.s 			page 13


 511 0646 BBFF0000 		movl	$255, %ebx
 511      00
 512 064b 0F4DCB   		cmovge	%ebx, %ecx
 513 064e 66894A08 		movw	%cx, 8(%edx)
 514 0652 0FB74A0A 		movzwl	10(%edx), %ecx
 515 0656 6685C9   		testw	%cx, %cx
 516 0659 0F884105 		js	.L262
 516      0000
 517              	.L168:
 518 065f 6681F900 		cmpw	$256, %cx
 518      01
 519 0664 BBFF0000 		movl	$255, %ebx
 519      00
 520 0669 0F4DCB   		cmovge	%ebx, %ecx
 521 066c 66894A0A 		movw	%cx, 10(%edx)
 522 0670 0FB74A0C 		movzwl	12(%edx), %ecx
 523 0674 6685C9   		testw	%cx, %cx
 524 0677 0F883605 		js	.L263
 524      0000
 525              	.L171:
 526 067d 6681F900 		cmpw	$256, %cx
 526      01
 527 0682 BBFF0000 		movl	$255, %ebx
 527      00
 528 0687 0F4DCB   		cmovge	%ebx, %ecx
 529 068a 66894A0C 		movw	%cx, 12(%edx)
 530 068e 0FB74A0E 		movzwl	14(%edx), %ecx
 531 0692 6685C9   		testw	%cx, %cx
 532 0695 0F882B05 		js	.L264
 532      0000
 533              	.L174:
 534 069b 6681F900 		cmpw	$256, %cx
 534      01
 535 06a0 BBFF0000 		movl	$255, %ebx
 535      00
 536 06a5 0F4DCB   		cmovge	%ebx, %ecx
 537 06a8 66894A0E 		movw	%cx, 14(%edx)
 538 06ac 0FB74870 		movzwl	112(%eax), %ecx
 539 06b0 8D5070   		leal	112(%eax), %edx
 540 06b3 6685C9   		testw	%cx, %cx
 541 06b6 0F882005 		js	.L193
 541      0000
 542              	.L265:
 543 06bc 6681F900 		cmpw	$256, %cx
 543      01
 544 06c1 BBFF0000 		movl	$255, %ebx
 544      00
 545 06c6 0F4DCB   		cmovge	%ebx, %ecx
 546 06c9 66894870 		movw	%cx, 112(%eax)
 547 06cd 0FB74202 		movzwl	2(%edx), %eax
 548 06d1 6685C0   		testw	%ax, %ax
 549 06d4 0F881505 		js	.L195
 549      0000
 550              	.L266:
 551 06da 663D0001 		cmpw	$256, %ax
 552 06de B9FF0000 		movl	$255, %ecx
 552      00
GAS LISTING /tmp/ccJXpt5V.s 			page 14


 553 06e3 0F4DC1   		cmovge	%ecx, %eax
 554 06e6 66894202 		movw	%ax, 2(%edx)
 555 06ea 0FB74204 		movzwl	4(%edx), %eax
 556 06ee 6685C0   		testw	%ax, %ax
 557 06f1 0F880B05 		js	.L197
 557      0000
 558              	.L267:
 559 06f7 663D0001 		cmpw	$256, %ax
 560 06fb B9FF0000 		movl	$255, %ecx
 560      00
 561 0700 0F4DC1   		cmovge	%ecx, %eax
 562 0703 66894204 		movw	%ax, 4(%edx)
 563 0707 0FB74206 		movzwl	6(%edx), %eax
 564 070b 6685C0   		testw	%ax, %ax
 565 070e 0F880105 		js	.L199
 565      0000
 566              	.L268:
 567 0714 663D0001 		cmpw	$256, %ax
 568 0718 B9FF0000 		movl	$255, %ecx
 568      00
 569 071d 0F4DC1   		cmovge	%ecx, %eax
 570 0720 66894206 		movw	%ax, 6(%edx)
 571 0724 0FB74208 		movzwl	8(%edx), %eax
 572 0728 6685C0   		testw	%ax, %ax
 573 072b 0F88F704 		js	.L201
 573      0000
 574              	.L269:
 575 0731 663D0001 		cmpw	$256, %ax
 576 0735 B9FF0000 		movl	$255, %ecx
 576      00
 577 073a 0F4DC1   		cmovge	%ecx, %eax
 578 073d 66894208 		movw	%ax, 8(%edx)
 579 0741 0FB7420A 		movzwl	10(%edx), %eax
 580 0745 6685C0   		testw	%ax, %ax
 581 0748 0F88ED04 		js	.L203
 581      0000
 582              	.L270:
 583 074e 663D0001 		cmpw	$256, %ax
 584 0752 B9FF0000 		movl	$255, %ecx
 584      00
 585 0757 0F4DC1   		cmovge	%ecx, %eax
 586 075a 6689420A 		movw	%ax, 10(%edx)
 587 075e 0FB7420C 		movzwl	12(%edx), %eax
 588 0762 6685C0   		testw	%ax, %ax
 589 0765 0F88E304 		js	.L205
 589      0000
 590              	.L271:
 591 076b 663D0001 		cmpw	$256, %ax
 592 076f B9FF0000 		movl	$255, %ecx
 592      00
 593 0774 0F4DC1   		cmovge	%ecx, %eax
 594 0777 6689420C 		movw	%ax, 12(%edx)
 595 077b 0FB7420E 		movzwl	14(%edx), %eax
 596 077f 6685C0   		testw	%ax, %ax
 597 0782 0F88D904 		js	.L207
 597      0000
 598              	.L272:
GAS LISTING /tmp/ccJXpt5V.s 			page 15


 599 0788 663D0001 		cmpw	$256, %ax
 600 078c B9FF0000 		movl	$255, %ecx
 600      00
 601 0791 0F4DC1   		cmovge	%ecx, %eax
 602 0794 6689420E 		movw	%ax, 14(%edx)
 603 0798 5B       		popl	%ebx
 604              		.cfi_remember_state
 605              		.cfi_restore 3
 606 0799 5D       		popl	%ebp
 607              		.cfi_restore 5
 608              		.cfi_def_cfa 4, 4
 609 079a C3       		ret
 610 079b 908D7426 		.p2align 4,,7
 610      00
 611              		.p2align 3
 612              	.L209:
 613              		.cfi_restore_state
 614 07a0 31D2     		xorl	%edx, %edx
 615 07a2 668910   		movw	%dx, (%eax)
 616 07a5 0FB75002 		movzwl	2(%eax), %edx
 617 07a9 6685D2   		testw	%dx, %dx
 618 07ac 0F8983F8 		jns	.L12
 618      FFFF
 619              	.L210:
 620 07b2 31D2     		xorl	%edx, %edx
 621 07b4 66895002 		movw	%dx, 2(%eax)
 622 07b8 0FB75004 		movzwl	4(%eax), %edx
 623 07bc 6685D2   		testw	%dx, %dx
 624 07bf 0F898EF8 		jns	.L15
 624      FFFF
 625              	.L211:
 626 07c5 31D2     		xorl	%edx, %edx
 627 07c7 66895004 		movw	%dx, 4(%eax)
 628 07cb 0FB75006 		movzwl	6(%eax), %edx
 629 07cf 6685D2   		testw	%dx, %dx
 630 07d2 0F8999F8 		jns	.L18
 630      FFFF
 631              	.L212:
 632 07d8 31D2     		xorl	%edx, %edx
 633 07da 66895006 		movw	%dx, 6(%eax)
 634 07de 0FB75008 		movzwl	8(%eax), %edx
 635 07e2 6685D2   		testw	%dx, %dx
 636 07e5 0F89A4F8 		jns	.L21
 636      FFFF
 637              	.L213:
 638 07eb 31D2     		xorl	%edx, %edx
 639 07ed 66895008 		movw	%dx, 8(%eax)
 640 07f1 0FB7500A 		movzwl	10(%eax), %edx
 641 07f5 6685D2   		testw	%dx, %dx
 642 07f8 0F89AFF8 		jns	.L24
 642      FFFF
 643              	.L214:
 644 07fe 31D2     		xorl	%edx, %edx
 645 0800 6689500A 		movw	%dx, 10(%eax)
 646 0804 0FB7500C 		movzwl	12(%eax), %edx
 647 0808 6685D2   		testw	%dx, %dx
 648 080b 0F89BAF8 		jns	.L27
GAS LISTING /tmp/ccJXpt5V.s 			page 16


 648      FFFF
 649              	.L215:
 650 0811 31D2     		xorl	%edx, %edx
 651 0813 6689500C 		movw	%dx, 12(%eax)
 652 0817 0FB7500E 		movzwl	14(%eax), %edx
 653 081b 6685D2   		testw	%dx, %dx
 654 081e 0F89C5F8 		jns	.L30
 654      FFFF
 655              	.L216:
 656 0824 0FB74810 		movzwl	16(%eax), %ecx
 657 0828 31D2     		xorl	%edx, %edx
 658 082a 6689500E 		movw	%dx, 14(%eax)
 659 082e 8D5010   		leal	16(%eax), %edx
 660 0831 6685C9   		testw	%cx, %cx
 661 0834 0F89D0F8 		jns	.L33
 661      FFFF
 662              	.L217:
 663 083a 31C9     		xorl	%ecx, %ecx
 664 083c 66894810 		movw	%cx, 16(%eax)
 665 0840 0FB74A02 		movzwl	2(%edx), %ecx
 666 0844 6685C9   		testw	%cx, %cx
 667 0847 0F89DBF8 		jns	.L36
 667      FFFF
 668              	.L218:
 669 084d 31C9     		xorl	%ecx, %ecx
 670 084f 66894A02 		movw	%cx, 2(%edx)
 671 0853 0FB74A04 		movzwl	4(%edx), %ecx
 672 0857 6685C9   		testw	%cx, %cx
 673 085a 0F89E6F8 		jns	.L39
 673      FFFF
 674              	.L219:
 675 0860 31C9     		xorl	%ecx, %ecx
 676 0862 66894A04 		movw	%cx, 4(%edx)
 677 0866 0FB74A06 		movzwl	6(%edx), %ecx
 678 086a 6685C9   		testw	%cx, %cx
 679 086d 0F89F1F8 		jns	.L42
 679      FFFF
 680              	.L220:
 681 0873 31C9     		xorl	%ecx, %ecx
 682 0875 66894A06 		movw	%cx, 6(%edx)
 683 0879 0FB74A08 		movzwl	8(%edx), %ecx
 684 087d 6685C9   		testw	%cx, %cx
 685 0880 0F89FCF8 		jns	.L45
 685      FFFF
 686              	.L221:
 687 0886 31C9     		xorl	%ecx, %ecx
 688 0888 66894A08 		movw	%cx, 8(%edx)
 689 088c 0FB74A0A 		movzwl	10(%edx), %ecx
 690 0890 6685C9   		testw	%cx, %cx
 691 0893 0F8907F9 		jns	.L48
 691      FFFF
 692              	.L222:
 693 0899 31C9     		xorl	%ecx, %ecx
 694 089b 66894A0A 		movw	%cx, 10(%edx)
 695 089f 0FB74A0C 		movzwl	12(%edx), %ecx
 696 08a3 6685C9   		testw	%cx, %cx
 697 08a6 0F8912F9 		jns	.L51
GAS LISTING /tmp/ccJXpt5V.s 			page 17


 697      FFFF
 698              	.L223:
 699 08ac 31C9     		xorl	%ecx, %ecx
 700 08ae 66894A0C 		movw	%cx, 12(%edx)
 701 08b2 0FB74A0E 		movzwl	14(%edx), %ecx
 702 08b6 6685C9   		testw	%cx, %cx
 703 08b9 0F891DF9 		jns	.L54
 703      FFFF
 704              	.L224:
 705 08bf 31C9     		xorl	%ecx, %ecx
 706 08c1 66894A0E 		movw	%cx, 14(%edx)
 707 08c5 0FB74820 		movzwl	32(%eax), %ecx
 708 08c9 8D5020   		leal	32(%eax), %edx
 709 08cc 6685C9   		testw	%cx, %cx
 710 08cf 0F8928F9 		jns	.L57
 710      FFFF
 711              	.L225:
 712 08d5 31C9     		xorl	%ecx, %ecx
 713 08d7 66894820 		movw	%cx, 32(%eax)
 714 08db 0FB74A02 		movzwl	2(%edx), %ecx
 715 08df 6685C9   		testw	%cx, %cx
 716 08e2 0F8933F9 		jns	.L60
 716      FFFF
 717              	.L226:
 718 08e8 31C9     		xorl	%ecx, %ecx
 719 08ea 66894A02 		movw	%cx, 2(%edx)
 720 08ee 0FB74A04 		movzwl	4(%edx), %ecx
 721 08f2 6685C9   		testw	%cx, %cx
 722 08f5 0F893EF9 		jns	.L63
 722      FFFF
 723              	.L227:
 724 08fb 31C9     		xorl	%ecx, %ecx
 725 08fd 66894A04 		movw	%cx, 4(%edx)
 726 0901 0FB74A06 		movzwl	6(%edx), %ecx
 727 0905 6685C9   		testw	%cx, %cx
 728 0908 0F8949F9 		jns	.L66
 728      FFFF
 729              	.L228:
 730 090e 31C9     		xorl	%ecx, %ecx
 731 0910 66894A06 		movw	%cx, 6(%edx)
 732 0914 0FB74A08 		movzwl	8(%edx), %ecx
 733 0918 6685C9   		testw	%cx, %cx
 734 091b 0F8954F9 		jns	.L69
 734      FFFF
 735              	.L229:
 736 0921 31C9     		xorl	%ecx, %ecx
 737 0923 66894A08 		movw	%cx, 8(%edx)
 738 0927 0FB74A0A 		movzwl	10(%edx), %ecx
 739 092b 6685C9   		testw	%cx, %cx
 740 092e 0F895FF9 		jns	.L72
 740      FFFF
 741              	.L230:
 742 0934 31C9     		xorl	%ecx, %ecx
 743 0936 66894A0A 		movw	%cx, 10(%edx)
 744 093a 0FB74A0C 		movzwl	12(%edx), %ecx
 745 093e 6685C9   		testw	%cx, %cx
 746 0941 0F896AF9 		jns	.L75
GAS LISTING /tmp/ccJXpt5V.s 			page 18


 746      FFFF
 747              	.L231:
 748 0947 31C9     		xorl	%ecx, %ecx
 749 0949 66894A0C 		movw	%cx, 12(%edx)
 750 094d 0FB74A0E 		movzwl	14(%edx), %ecx
 751 0951 6685C9   		testw	%cx, %cx
 752 0954 0F8975F9 		jns	.L78
 752      FFFF
 753              	.L232:
 754 095a 31C9     		xorl	%ecx, %ecx
 755 095c 66894A0E 		movw	%cx, 14(%edx)
 756 0960 0FB74830 		movzwl	48(%eax), %ecx
 757 0964 8D5030   		leal	48(%eax), %edx
 758 0967 6685C9   		testw	%cx, %cx
 759 096a 0F8980F9 		jns	.L81
 759      FFFF
 760              	.L233:
 761 0970 31C9     		xorl	%ecx, %ecx
 762 0972 66894830 		movw	%cx, 48(%eax)
 763 0976 0FB74A02 		movzwl	2(%edx), %ecx
 764 097a 6685C9   		testw	%cx, %cx
 765 097d 0F898BF9 		jns	.L84
 765      FFFF
 766              	.L234:
 767 0983 31C9     		xorl	%ecx, %ecx
 768 0985 66894A02 		movw	%cx, 2(%edx)
 769 0989 0FB74A04 		movzwl	4(%edx), %ecx
 770 098d 6685C9   		testw	%cx, %cx
 771 0990 0F8996F9 		jns	.L87
 771      FFFF
 772              	.L235:
 773 0996 31C9     		xorl	%ecx, %ecx
 774 0998 66894A04 		movw	%cx, 4(%edx)
 775 099c 0FB74A06 		movzwl	6(%edx), %ecx
 776 09a0 6685C9   		testw	%cx, %cx
 777 09a3 0F89A1F9 		jns	.L90
 777      FFFF
 778              	.L236:
 779 09a9 31C9     		xorl	%ecx, %ecx
 780 09ab 66894A06 		movw	%cx, 6(%edx)
 781 09af 0FB74A08 		movzwl	8(%edx), %ecx
 782 09b3 6685C9   		testw	%cx, %cx
 783 09b6 0F89ACF9 		jns	.L93
 783      FFFF
 784              	.L237:
 785 09bc 31C9     		xorl	%ecx, %ecx
 786 09be 66894A08 		movw	%cx, 8(%edx)
 787 09c2 0FB74A0A 		movzwl	10(%edx), %ecx
 788 09c6 6685C9   		testw	%cx, %cx
 789 09c9 0F89B7F9 		jns	.L96
 789      FFFF
 790              	.L238:
 791 09cf 31C9     		xorl	%ecx, %ecx
 792 09d1 66894A0A 		movw	%cx, 10(%edx)
 793 09d5 0FB74A0C 		movzwl	12(%edx), %ecx
 794 09d9 6685C9   		testw	%cx, %cx
 795 09dc 0F89C2F9 		jns	.L99
GAS LISTING /tmp/ccJXpt5V.s 			page 19


 795      FFFF
 796              	.L239:
 797 09e2 31C9     		xorl	%ecx, %ecx
 798 09e4 66894A0C 		movw	%cx, 12(%edx)
 799 09e8 0FB74A0E 		movzwl	14(%edx), %ecx
 800 09ec 6685C9   		testw	%cx, %cx
 801 09ef 0F89CDF9 		jns	.L102
 801      FFFF
 802              	.L240:
 803 09f5 31C9     		xorl	%ecx, %ecx
 804 09f7 66894A0E 		movw	%cx, 14(%edx)
 805 09fb 0FB74840 		movzwl	64(%eax), %ecx
 806 09ff 8D5040   		leal	64(%eax), %edx
 807 0a02 6685C9   		testw	%cx, %cx
 808 0a05 0F89D8F9 		jns	.L105
 808      FFFF
 809              	.L241:
 810 0a0b 31C9     		xorl	%ecx, %ecx
 811 0a0d 66894840 		movw	%cx, 64(%eax)
 812 0a11 0FB74A02 		movzwl	2(%edx), %ecx
 813 0a15 6685C9   		testw	%cx, %cx
 814 0a18 0F89E3F9 		jns	.L108
 814      FFFF
 815              	.L242:
 816 0a1e 31C9     		xorl	%ecx, %ecx
 817 0a20 66894A02 		movw	%cx, 2(%edx)
 818 0a24 0FB74A04 		movzwl	4(%edx), %ecx
 819 0a28 6685C9   		testw	%cx, %cx
 820 0a2b 0F89EEF9 		jns	.L111
 820      FFFF
 821              	.L243:
 822 0a31 31C9     		xorl	%ecx, %ecx
 823 0a33 66894A04 		movw	%cx, 4(%edx)
 824 0a37 0FB74A06 		movzwl	6(%edx), %ecx
 825 0a3b 6685C9   		testw	%cx, %cx
 826 0a3e 0F89F9F9 		jns	.L114
 826      FFFF
 827              	.L244:
 828 0a44 31C9     		xorl	%ecx, %ecx
 829 0a46 66894A06 		movw	%cx, 6(%edx)
 830 0a4a 0FB74A08 		movzwl	8(%edx), %ecx
 831 0a4e 6685C9   		testw	%cx, %cx
 832 0a51 0F8904FA 		jns	.L117
 832      FFFF
 833              	.L245:
 834 0a57 31C9     		xorl	%ecx, %ecx
 835 0a59 66894A08 		movw	%cx, 8(%edx)
 836 0a5d 0FB74A0A 		movzwl	10(%edx), %ecx
 837 0a61 6685C9   		testw	%cx, %cx
 838 0a64 0F890FFA 		jns	.L120
 838      FFFF
 839              	.L246:
 840 0a6a 31C9     		xorl	%ecx, %ecx
 841 0a6c 66894A0A 		movw	%cx, 10(%edx)
 842 0a70 0FB74A0C 		movzwl	12(%edx), %ecx
 843 0a74 6685C9   		testw	%cx, %cx
 844 0a77 0F891AFA 		jns	.L123
GAS LISTING /tmp/ccJXpt5V.s 			page 20


 844      FFFF
 845              	.L247:
 846 0a7d 31C9     		xorl	%ecx, %ecx
 847 0a7f 66894A0C 		movw	%cx, 12(%edx)
 848 0a83 0FB74A0E 		movzwl	14(%edx), %ecx
 849 0a87 6685C9   		testw	%cx, %cx
 850 0a8a 0F8925FA 		jns	.L126
 850      FFFF
 851              	.L248:
 852 0a90 31C9     		xorl	%ecx, %ecx
 853 0a92 66894A0E 		movw	%cx, 14(%edx)
 854 0a96 0FB74850 		movzwl	80(%eax), %ecx
 855 0a9a 8D5050   		leal	80(%eax), %edx
 856 0a9d 6685C9   		testw	%cx, %cx
 857 0aa0 0F8930FA 		jns	.L129
 857      FFFF
 858              	.L249:
 859 0aa6 31C9     		xorl	%ecx, %ecx
 860 0aa8 66894850 		movw	%cx, 80(%eax)
 861 0aac 0FB74A02 		movzwl	2(%edx), %ecx
 862 0ab0 6685C9   		testw	%cx, %cx
 863 0ab3 0F893BFA 		jns	.L132
 863      FFFF
 864              	.L250:
 865 0ab9 31C9     		xorl	%ecx, %ecx
 866 0abb 66894A02 		movw	%cx, 2(%edx)
 867 0abf 0FB74A04 		movzwl	4(%edx), %ecx
 868 0ac3 6685C9   		testw	%cx, %cx
 869 0ac6 0F8946FA 		jns	.L135
 869      FFFF
 870              	.L251:
 871 0acc 31C9     		xorl	%ecx, %ecx
 872 0ace 66894A04 		movw	%cx, 4(%edx)
 873 0ad2 0FB74A06 		movzwl	6(%edx), %ecx
 874 0ad6 6685C9   		testw	%cx, %cx
 875 0ad9 0F8951FA 		jns	.L138
 875      FFFF
 876              	.L252:
 877 0adf 31C9     		xorl	%ecx, %ecx
 878 0ae1 66894A06 		movw	%cx, 6(%edx)
 879 0ae5 0FB74A08 		movzwl	8(%edx), %ecx
 880 0ae9 6685C9   		testw	%cx, %cx
 881 0aec 0F895CFA 		jns	.L141
 881      FFFF
 882              	.L253:
 883 0af2 31C9     		xorl	%ecx, %ecx
 884 0af4 66894A08 		movw	%cx, 8(%edx)
 885 0af8 0FB74A0A 		movzwl	10(%edx), %ecx
 886 0afc 6685C9   		testw	%cx, %cx
 887 0aff 0F8967FA 		jns	.L144
 887      FFFF
 888              	.L254:
 889 0b05 31C9     		xorl	%ecx, %ecx
 890 0b07 66894A0A 		movw	%cx, 10(%edx)
 891 0b0b 0FB74A0C 		movzwl	12(%edx), %ecx
 892 0b0f 6685C9   		testw	%cx, %cx
 893 0b12 0F8972FA 		jns	.L147
GAS LISTING /tmp/ccJXpt5V.s 			page 21


 893      FFFF
 894              	.L255:
 895 0b18 31C9     		xorl	%ecx, %ecx
 896 0b1a 66894A0C 		movw	%cx, 12(%edx)
 897 0b1e 0FB74A0E 		movzwl	14(%edx), %ecx
 898 0b22 6685C9   		testw	%cx, %cx
 899 0b25 0F897DFA 		jns	.L150
 899      FFFF
 900              	.L256:
 901 0b2b 31C9     		xorl	%ecx, %ecx
 902 0b2d 66894A0E 		movw	%cx, 14(%edx)
 903 0b31 0FB74860 		movzwl	96(%eax), %ecx
 904 0b35 8D5060   		leal	96(%eax), %edx
 905 0b38 6685C9   		testw	%cx, %cx
 906 0b3b 0F8988FA 		jns	.L153
 906      FFFF
 907              	.L257:
 908 0b41 31C9     		xorl	%ecx, %ecx
 909 0b43 66894860 		movw	%cx, 96(%eax)
 910 0b47 0FB74A02 		movzwl	2(%edx), %ecx
 911 0b4b 6685C9   		testw	%cx, %cx
 912 0b4e 0F8993FA 		jns	.L156
 912      FFFF
 913              	.L258:
 914 0b54 31C9     		xorl	%ecx, %ecx
 915 0b56 66894A02 		movw	%cx, 2(%edx)
 916 0b5a 0FB74A04 		movzwl	4(%edx), %ecx
 917 0b5e 6685C9   		testw	%cx, %cx
 918 0b61 0F899EFA 		jns	.L159
 918      FFFF
 919              	.L259:
 920 0b67 31C9     		xorl	%ecx, %ecx
 921 0b69 66894A04 		movw	%cx, 4(%edx)
 922 0b6d 0FB74A06 		movzwl	6(%edx), %ecx
 923 0b71 6685C9   		testw	%cx, %cx
 924 0b74 0F89A9FA 		jns	.L162
 924      FFFF
 925              	.L260:
 926 0b7a 31C9     		xorl	%ecx, %ecx
 927 0b7c 66894A06 		movw	%cx, 6(%edx)
 928 0b80 0FB74A08 		movzwl	8(%edx), %ecx
 929 0b84 6685C9   		testw	%cx, %cx
 930 0b87 0F89B4FA 		jns	.L165
 930      FFFF
 931              	.L261:
 932 0b8d 31C9     		xorl	%ecx, %ecx
 933 0b8f 66894A08 		movw	%cx, 8(%edx)
 934 0b93 0FB74A0A 		movzwl	10(%edx), %ecx
 935 0b97 6685C9   		testw	%cx, %cx
 936 0b9a 0F89BFFA 		jns	.L168
 936      FFFF
 937              	.L262:
 938 0ba0 31C9     		xorl	%ecx, %ecx
 939 0ba2 66894A0A 		movw	%cx, 10(%edx)
 940 0ba6 0FB74A0C 		movzwl	12(%edx), %ecx
 941 0baa 6685C9   		testw	%cx, %cx
 942 0bad 0F89CAFA 		jns	.L171
GAS LISTING /tmp/ccJXpt5V.s 			page 22


 942      FFFF
 943              	.L263:
 944 0bb3 31C9     		xorl	%ecx, %ecx
 945 0bb5 66894A0C 		movw	%cx, 12(%edx)
 946 0bb9 0FB74A0E 		movzwl	14(%edx), %ecx
 947 0bbd 6685C9   		testw	%cx, %cx
 948 0bc0 0F89D5FA 		jns	.L174
 948      FFFF
 949              	.L264:
 950 0bc6 31C9     		xorl	%ecx, %ecx
 951 0bc8 66894A0E 		movw	%cx, 14(%edx)
 952 0bcc 0FB74870 		movzwl	112(%eax), %ecx
 953 0bd0 8D5070   		leal	112(%eax), %edx
 954 0bd3 6685C9   		testw	%cx, %cx
 955 0bd6 0F89E0FA 		jns	.L265
 955      FFFF
 956              	.L193:
 957 0bdc 31C9     		xorl	%ecx, %ecx
 958 0bde 66894870 		movw	%cx, 112(%eax)
 959 0be2 0FB74202 		movzwl	2(%edx), %eax
 960 0be6 6685C0   		testw	%ax, %ax
 961 0be9 0F89EBFA 		jns	.L266
 961      FFFF
 962              	.L195:
 963 0bef 31C0     		xorl	%eax, %eax
 964 0bf1 66894202 		movw	%ax, 2(%edx)
 965 0bf5 0FB74204 		movzwl	4(%edx), %eax
 966 0bf9 6685C0   		testw	%ax, %ax
 967 0bfc 0F89F5FA 		jns	.L267
 967      FFFF
 968              	.L197:
 969 0c02 31C0     		xorl	%eax, %eax
 970 0c04 66894204 		movw	%ax, 4(%edx)
 971 0c08 0FB74206 		movzwl	6(%edx), %eax
 972 0c0c 6685C0   		testw	%ax, %ax
 973 0c0f 0F89FFFA 		jns	.L268
 973      FFFF
 974              	.L199:
 975 0c15 31C0     		xorl	%eax, %eax
 976 0c17 66894206 		movw	%ax, 6(%edx)
 977 0c1b 0FB74208 		movzwl	8(%edx), %eax
 978 0c1f 6685C0   		testw	%ax, %ax
 979 0c22 0F8909FB 		jns	.L269
 979      FFFF
 980              	.L201:
 981 0c28 31C0     		xorl	%eax, %eax
 982 0c2a 66894208 		movw	%ax, 8(%edx)
 983 0c2e 0FB7420A 		movzwl	10(%edx), %eax
 984 0c32 6685C0   		testw	%ax, %ax
 985 0c35 0F8913FB 		jns	.L270
 985      FFFF
 986              	.L203:
 987 0c3b 31C0     		xorl	%eax, %eax
 988 0c3d 6689420A 		movw	%ax, 10(%edx)
 989 0c41 0FB7420C 		movzwl	12(%edx), %eax
 990 0c45 6685C0   		testw	%ax, %ax
 991 0c48 0F891DFB 		jns	.L271
GAS LISTING /tmp/ccJXpt5V.s 			page 23


 991      FFFF
 992              	.L205:
 993 0c4e 31C0     		xorl	%eax, %eax
 994 0c50 6689420C 		movw	%ax, 12(%edx)
 995 0c54 0FB7420E 		movzwl	14(%edx), %eax
 996 0c58 6685C0   		testw	%ax, %ax
 997 0c5b 0F8927FB 		jns	.L272
 997      FFFF
 998              	.L207:
 999 0c61 31C0     		xorl	%eax, %eax
 1000 0c63 6689420E 		movw	%ax, 14(%edx)
 1001 0c67 5B       		popl	%ebx
 1002              		.cfi_restore 3
 1003 0c68 5D       		popl	%ebp
 1004              		.cfi_def_cfa 4, 4
 1005              		.cfi_restore 5
 1006 0c69 C3       		ret
 1007              		.cfi_endproc
 1008              	.LFE114:
 1009              		.size	correct_color, .-correct_color
 1010 0c6a 8DB60000 		.p2align 4,,15
 1010      0000
 1011              	.globl write_jpeg
 1012              		.type	write_jpeg, @function
 1013              	write_jpeg:
 1014              	.LFB115:
 1015              		.cfi_startproc
 1016 0c70 55       		pushl	%ebp
 1017              		.cfi_def_cfa_offset 8
 1018 0c71 89E5     		movl	%esp, %ebp
 1019              		.cfi_offset 5, -8
 1020              		.cfi_def_cfa_register 5
 1021 0c73 83EC18   		subl	$24, %esp
 1022 0c76 E8FCFFFF 		call	mcount
 1022      FF
 1023 0c7b A1000000 		movl	_ZL8file_jpg, %eax
 1023      00
 1024 0c80 8944240C 		movl	%eax, 12(%esp)
 1025 0c84 8B450C   		movl	12(%ebp), %eax
 1026 0c87 C7442408 		movl	$1, 8(%esp)
 1026      01000000 
 1027 0c8f 89442404 		movl	%eax, 4(%esp)
 1028 0c93 8B4508   		movl	8(%ebp), %eax
 1029 0c96 890424   		movl	%eax, (%esp)
 1030 0c99 E8FCFFFF 		call	fwrite
 1030      FF
 1031 0c9e C9       		leave
 1032              		.cfi_restore 5
 1033              		.cfi_def_cfa 4, 4
 1034 0c9f C3       		ret
 1035              		.cfi_endproc
 1036              	.LFE115:
 1037              		.size	write_jpeg, .-write_jpeg
 1038              		.p2align 4,,15
 1039              	.globl _Z9subsamplePA16_K3BGRPA8_sS4_
 1040              		.type	_Z9subsamplePA16_K3BGRPA8_sS4_, @function
 1041              	_Z9subsamplePA16_K3BGRPA8_sS4_:
GAS LISTING /tmp/ccJXpt5V.s 			page 24


 1042              	.LFB118:
 1043              		.cfi_startproc
 1044 0ca0 55       		pushl	%ebp
 1045              		.cfi_def_cfa_offset 8
 1046 0ca1 89E5     		movl	%esp, %ebp
 1047              		.cfi_offset 5, -8
 1048              		.cfi_def_cfa_register 5
 1049 0ca3 57       		pushl	%edi
 1050 0ca4 56       		pushl	%esi
 1051 0ca5 53       		pushl	%ebx
 1052 0ca6 83EC10   		subl	$16, %esp
 1053 0ca9 E8FCFFFF 		call	mcount
 1053      FF
 1054 0cae 31C9     		xorl	%ecx, %ecx
 1055 0cb0 C745E800 		movl	$0, -24(%ebp)
 1055      000000
 1056              		.p2align 4,,7
 1057 0cb7 90       		.p2align 3
 1058              	.L275:
 1059 0cb8 8B55E8   		movl	-24(%ebp), %edx
 1060 0cbb 8D0412   		leal	(%edx,%edx), %eax
 1061 0cbe 8D1490   		leal	(%eax,%edx,4), %edx
 1062 0cc1 C1E204   		sall	$4, %edx
 1063 0cc4 035508   		addl	8(%ebp), %edx
 1064 0cc7 8D444003 		leal	3(%eax,%eax,2), %eax
 1065 0ccb C1E004   		sall	$4, %eax
 1066 0cce 0FB61A   		movzbl	(%edx), %ebx
 1067              		.cfi_offset 3, -20
 1068              		.cfi_offset 6, -16
 1069              		.cfi_offset 7, -12
 1070 0cd1 0FB67203 		movzbl	3(%edx), %esi
 1071 0cd5 034508   		addl	8(%ebp), %eax
 1072 0cd8 0FB67A04 		movzbl	4(%edx), %edi
 1073 0cdc 01DE     		addl	%ebx, %esi
 1074 0cde 0FB618   		movzbl	(%eax), %ebx
 1075 0ce1 01DE     		addl	%ebx, %esi
 1076 0ce3 0FB65803 		movzbl	3(%eax), %ebx
 1077 0ce7 8D1C1E   		leal	(%esi,%ebx), %ebx
 1078 0cea 0FB67201 		movzbl	1(%edx), %esi
 1079 0cee C1FB02   		sarl	$2, %ebx
 1080 0cf1 0FB6DB   		movzbl	%bl, %ebx
 1081 0cf4 895DE4   		movl	%ebx, -28(%ebp)
 1082 0cf7 01F7     		addl	%esi, %edi
 1083 0cf9 0FB67001 		movzbl	1(%eax), %esi
 1084 0cfd 01F7     		addl	%esi, %edi
 1085 0cff 0FB67004 		movzbl	4(%eax), %esi
 1086 0d03 8D3437   		leal	(%edi,%esi), %esi
 1087 0d06 0FB67A05 		movzbl	5(%edx), %edi
 1088 0d0a C1FE02   		sarl	$2, %esi
 1089 0d0d 89F3     		movl	%esi, %ebx
 1090 0d0f 0FB6F3   		movzbl	%bl, %esi
 1091 0d12 8975EC   		movl	%esi, -20(%ebp)
 1092 0d15 0FB67002 		movzbl	2(%eax), %esi
 1093 0d19 01F7     		addl	%esi, %edi
 1094 0d1b 0FB67202 		movzbl	2(%edx), %esi
 1095 0d1f 01F7     		addl	%esi, %edi
 1096 0d21 0FB67005 		movzbl	5(%eax), %esi
GAS LISTING /tmp/ccJXpt5V.s 			page 25


 1097 0d25 8D3437   		leal	(%edi,%esi), %esi
 1098 0d28 C1FE02   		sarl	$2, %esi
 1099 0d2b 81E6FF00 		andl	$255, %esi
 1099      0000
 1100 0d31 69FECED4 		imull	$-11058, %esi, %edi
 1100      FFFF
 1101 0d37 897DF0   		movl	%edi, -16(%ebp)
 1102 0d3a 8B5DF0   		movl	-16(%ebp), %ebx
 1103 0d3d 697DEC33 		imull	$-21709, -20(%ebp), %edi
 1103      ABFFFF
 1104 0d44 8DBC3B00 		leal	8421376(%ebx,%edi), %edi
 1104      808000
 1105 0d4b 8B5D0C   		movl	12(%ebp), %ebx
 1106 0d4e 897DF0   		movl	%edi, -16(%ebp)
 1107 0d51 8B7DE4   		movl	-28(%ebp), %edi
 1108 0d54 C1E70F   		sall	$15, %edi
 1109 0d57 2B7DE4   		subl	-28(%ebp), %edi
 1110 0d5a 037DF0   		addl	-16(%ebp), %edi
 1111 0d5d C1FF10   		sarl	$16, %edi
 1112 0d60 6681E7FF 		andw	$255, %di
 1112      00
 1113 0d65 83C780   		addl	$-128, %edi
 1114 0d68 66893C0B 		movw	%di, (%ebx,%ecx)
 1115 0d6c 89F7     		movl	%esi, %edi
 1116 0d6e C1E70F   		sall	$15, %edi
 1117 0d71 29F7     		subl	%esi, %edi
 1118 0d73 6975ECD2 		imull	$-27438, -20(%ebp), %esi
 1118      94FFFF
 1119 0d7a 695DE42F 		imull	$-5329, -28(%ebp), %ebx
 1119      EBFFFF
 1120 0d81 8DB43700 		leal	8421376(%edi,%esi), %esi
 1120      808000
 1121 0d88 8D1C1E   		leal	(%esi,%ebx), %ebx
 1122 0d8b 8B7510   		movl	16(%ebp), %esi
 1123 0d8e C1FB10   		sarl	$16, %ebx
 1124 0d91 0FB6DB   		movzbl	%bl, %ebx
 1125 0d94 83C380   		addl	$-128, %ebx
 1126 0d97 66891C0E 		movw	%bx, (%esi,%ecx)
 1127 0d9b 0FB65A06 		movzbl	6(%edx), %ebx
 1128 0d9f 0FB67209 		movzbl	9(%edx), %esi
 1129 0da3 01DE     		addl	%ebx, %esi
 1130 0da5 0FB65806 		movzbl	6(%eax), %ebx
 1131 0da9 01DE     		addl	%ebx, %esi
 1132 0dab 0FB65809 		movzbl	9(%eax), %ebx
 1133 0daf 8D1C1E   		leal	(%esi,%ebx), %ebx
 1134 0db2 C1FB02   		sarl	$2, %ebx
 1135 0db5 0FB6DB   		movzbl	%bl, %ebx
 1136 0db8 895DE4   		movl	%ebx, -28(%ebp)
 1137 0dbb 0FB67207 		movzbl	7(%edx), %esi
 1138 0dbf 0FB67A0A 		movzbl	10(%edx), %edi
 1139 0dc3 01F7     		addl	%esi, %edi
 1140 0dc5 0FB67007 		movzbl	7(%eax), %esi
 1141 0dc9 01F7     		addl	%esi, %edi
 1142 0dcb 0FB6700A 		movzbl	10(%eax), %esi
 1143 0dcf 8D3437   		leal	(%edi,%esi), %esi
 1144 0dd2 0FB67A0B 		movzbl	11(%edx), %edi
 1145 0dd6 C1FE02   		sarl	$2, %esi
GAS LISTING /tmp/ccJXpt5V.s 			page 26


 1146 0dd9 89F3     		movl	%esi, %ebx
 1147 0ddb 0FB6F3   		movzbl	%bl, %esi
 1148 0dde 8975EC   		movl	%esi, -20(%ebp)
 1149 0de1 0FB67208 		movzbl	8(%edx), %esi
 1150 0de5 01F7     		addl	%esi, %edi
 1151 0de7 0FB67008 		movzbl	8(%eax), %esi
 1152 0deb 01F7     		addl	%esi, %edi
 1153 0ded 0FB6700B 		movzbl	11(%eax), %esi
 1154 0df1 8D3437   		leal	(%edi,%esi), %esi
 1155 0df4 C1FE02   		sarl	$2, %esi
 1156 0df7 81E6FF00 		andl	$255, %esi
 1156      0000
 1157 0dfd 69FECED4 		imull	$-11058, %esi, %edi
 1157      FFFF
 1158 0e03 897DF0   		movl	%edi, -16(%ebp)
 1159 0e06 8B5DF0   		movl	-16(%ebp), %ebx
 1160 0e09 697DEC33 		imull	$-21709, -20(%ebp), %edi
 1160      ABFFFF
 1161 0e10 8DBC3B00 		leal	8421376(%ebx,%edi), %edi
 1161      808000
 1162 0e17 8B5D0C   		movl	12(%ebp), %ebx
 1163 0e1a 897DF0   		movl	%edi, -16(%ebp)
 1164 0e1d 8B7DE4   		movl	-28(%ebp), %edi
 1165 0e20 C1E70F   		sall	$15, %edi
 1166 0e23 2B7DE4   		subl	-28(%ebp), %edi
 1167 0e26 037DF0   		addl	-16(%ebp), %edi
 1168 0e29 C1FF10   		sarl	$16, %edi
 1169 0e2c 6681E7FF 		andw	$255, %di
 1169      00
 1170 0e31 83C780   		addl	$-128, %edi
 1171 0e34 66897C0B 		movw	%di, 2(%ebx,%ecx)
 1171      02
 1172 0e39 89F7     		movl	%esi, %edi
 1173 0e3b C1E70F   		sall	$15, %edi
 1174 0e3e 29F7     		subl	%esi, %edi
 1175 0e40 6975ECD2 		imull	$-27438, -20(%ebp), %esi
 1175      94FFFF
 1176 0e47 695DE42F 		imull	$-5329, -28(%ebp), %ebx
 1176      EBFFFF
 1177 0e4e 8DB43700 		leal	8421376(%edi,%esi), %esi
 1177      808000
 1178 0e55 8D1C1E   		leal	(%esi,%ebx), %ebx
 1179 0e58 8B7510   		movl	16(%ebp), %esi
 1180 0e5b C1FB10   		sarl	$16, %ebx
 1181 0e5e 0FB6DB   		movzbl	%bl, %ebx
 1182 0e61 83C380   		addl	$-128, %ebx
 1183 0e64 66895C0E 		movw	%bx, 2(%esi,%ecx)
 1183      02
 1184 0e69 0FB65A0C 		movzbl	12(%edx), %ebx
 1185 0e6d 0FB6720F 		movzbl	15(%edx), %esi
 1186 0e71 0FB67A10 		movzbl	16(%edx), %edi
 1187 0e75 01DE     		addl	%ebx, %esi
 1188 0e77 0FB6580C 		movzbl	12(%eax), %ebx
 1189 0e7b 01DE     		addl	%ebx, %esi
 1190 0e7d 0FB6580F 		movzbl	15(%eax), %ebx
 1191 0e81 8D1C1E   		leal	(%esi,%ebx), %ebx
 1192 0e84 0FB6720D 		movzbl	13(%edx), %esi
GAS LISTING /tmp/ccJXpt5V.s 			page 27


 1193 0e88 C1FB02   		sarl	$2, %ebx
 1194 0e8b 0FB6DB   		movzbl	%bl, %ebx
 1195 0e8e 895DE4   		movl	%ebx, -28(%ebp)
 1196 0e91 01F7     		addl	%esi, %edi
 1197 0e93 0FB6700D 		movzbl	13(%eax), %esi
 1198 0e97 01F7     		addl	%esi, %edi
 1199 0e99 0FB67010 		movzbl	16(%eax), %esi
 1200 0e9d 8D3437   		leal	(%edi,%esi), %esi
 1201 0ea0 0FB67A11 		movzbl	17(%edx), %edi
 1202 0ea4 C1FE02   		sarl	$2, %esi
 1203 0ea7 89F3     		movl	%esi, %ebx
 1204 0ea9 0FB6F3   		movzbl	%bl, %esi
 1205 0eac 8975EC   		movl	%esi, -20(%ebp)
 1206 0eaf 0FB6720E 		movzbl	14(%edx), %esi
 1207 0eb3 01F7     		addl	%esi, %edi
 1208 0eb5 0FB6700E 		movzbl	14(%eax), %esi
 1209 0eb9 01F7     		addl	%esi, %edi
 1210 0ebb 0FB67011 		movzbl	17(%eax), %esi
 1211 0ebf 8D3437   		leal	(%edi,%esi), %esi
 1212 0ec2 C1FE02   		sarl	$2, %esi
 1213 0ec5 81E6FF00 		andl	$255, %esi
 1213      0000
 1214 0ecb 69FECED4 		imull	$-11058, %esi, %edi
 1214      FFFF
 1215 0ed1 897DF0   		movl	%edi, -16(%ebp)
 1216 0ed4 8B5DF0   		movl	-16(%ebp), %ebx
 1217 0ed7 697DEC33 		imull	$-21709, -20(%ebp), %edi
 1217      ABFFFF
 1218 0ede 8DBC3B00 		leal	8421376(%ebx,%edi), %edi
 1218      808000
 1219 0ee5 8B5D0C   		movl	12(%ebp), %ebx
 1220 0ee8 897DF0   		movl	%edi, -16(%ebp)
 1221 0eeb 8B7DE4   		movl	-28(%ebp), %edi
 1222 0eee C1E70F   		sall	$15, %edi
 1223 0ef1 2B7DE4   		subl	-28(%ebp), %edi
 1224 0ef4 037DF0   		addl	-16(%ebp), %edi
 1225 0ef7 C1FF10   		sarl	$16, %edi
 1226 0efa 6681E7FF 		andw	$255, %di
 1226      00
 1227 0eff 83C780   		addl	$-128, %edi
 1228 0f02 66897C0B 		movw	%di, 4(%ebx,%ecx)
 1228      04
 1229 0f07 89F7     		movl	%esi, %edi
 1230 0f09 C1E70F   		sall	$15, %edi
 1231 0f0c 29F7     		subl	%esi, %edi
 1232 0f0e 6975ECD2 		imull	$-27438, -20(%ebp), %esi
 1232      94FFFF
 1233 0f15 695DE42F 		imull	$-5329, -28(%ebp), %ebx
 1233      EBFFFF
 1234 0f1c 8DB43700 		leal	8421376(%edi,%esi), %esi
 1234      808000
 1235 0f23 8D1C1E   		leal	(%esi,%ebx), %ebx
 1236 0f26 8B7510   		movl	16(%ebp), %esi
 1237 0f29 C1FB10   		sarl	$16, %ebx
 1238 0f2c 0FB6DB   		movzbl	%bl, %ebx
 1239 0f2f 83C380   		addl	$-128, %ebx
 1240 0f32 66895C0E 		movw	%bx, 4(%esi,%ecx)
GAS LISTING /tmp/ccJXpt5V.s 			page 28


 1240      04
 1241 0f37 0FB65A12 		movzbl	18(%edx), %ebx
 1242 0f3b 0FB67215 		movzbl	21(%edx), %esi
 1243 0f3f 0FB67A16 		movzbl	22(%edx), %edi
 1244 0f43 01DE     		addl	%ebx, %esi
 1245 0f45 0FB65812 		movzbl	18(%eax), %ebx
 1246 0f49 01DE     		addl	%ebx, %esi
 1247 0f4b 0FB65815 		movzbl	21(%eax), %ebx
 1248 0f4f 8D1C1E   		leal	(%esi,%ebx), %ebx
 1249 0f52 0FB67213 		movzbl	19(%edx), %esi
 1250 0f56 C1FB02   		sarl	$2, %ebx
 1251 0f59 0FB6DB   		movzbl	%bl, %ebx
 1252 0f5c 895DE4   		movl	%ebx, -28(%ebp)
 1253 0f5f 01F7     		addl	%esi, %edi
 1254 0f61 0FB67013 		movzbl	19(%eax), %esi
 1255 0f65 01F7     		addl	%esi, %edi
 1256 0f67 0FB67016 		movzbl	22(%eax), %esi
 1257 0f6b 8D3437   		leal	(%edi,%esi), %esi
 1258 0f6e 0FB67A17 		movzbl	23(%edx), %edi
 1259 0f72 C1FE02   		sarl	$2, %esi
 1260 0f75 89F3     		movl	%esi, %ebx
 1261 0f77 0FB6F3   		movzbl	%bl, %esi
 1262 0f7a 8975EC   		movl	%esi, -20(%ebp)
 1263 0f7d 0FB67214 		movzbl	20(%edx), %esi
 1264 0f81 01F7     		addl	%esi, %edi
 1265 0f83 0FB67014 		movzbl	20(%eax), %esi
 1266 0f87 01F7     		addl	%esi, %edi
 1267 0f89 0FB67017 		movzbl	23(%eax), %esi
 1268 0f8d 8D3437   		leal	(%edi,%esi), %esi
 1269 0f90 C1FE02   		sarl	$2, %esi
 1270 0f93 81E6FF00 		andl	$255, %esi
 1270      0000
 1271 0f99 69FECED4 		imull	$-11058, %esi, %edi
 1271      FFFF
 1272 0f9f 897DF0   		movl	%edi, -16(%ebp)
 1273 0fa2 8B5DF0   		movl	-16(%ebp), %ebx
 1274 0fa5 697DEC33 		imull	$-21709, -20(%ebp), %edi
 1274      ABFFFF
 1275 0fac 8DBC3B00 		leal	8421376(%ebx,%edi), %edi
 1275      808000
 1276 0fb3 8B5D0C   		movl	12(%ebp), %ebx
 1277 0fb6 897DF0   		movl	%edi, -16(%ebp)
 1278 0fb9 8B7DE4   		movl	-28(%ebp), %edi
 1279 0fbc C1E70F   		sall	$15, %edi
 1280 0fbf 2B7DE4   		subl	-28(%ebp), %edi
 1281 0fc2 037DF0   		addl	-16(%ebp), %edi
 1282 0fc5 C1FF10   		sarl	$16, %edi
 1283 0fc8 6681E7FF 		andw	$255, %di
 1283      00
 1284 0fcd 83C780   		addl	$-128, %edi
 1285 0fd0 66897C0B 		movw	%di, 6(%ebx,%ecx)
 1285      06
 1286 0fd5 89F7     		movl	%esi, %edi
 1287 0fd7 C1E70F   		sall	$15, %edi
 1288 0fda 29F7     		subl	%esi, %edi
 1289 0fdc 6975ECD2 		imull	$-27438, -20(%ebp), %esi
 1289      94FFFF
GAS LISTING /tmp/ccJXpt5V.s 			page 29


 1290 0fe3 695DE42F 		imull	$-5329, -28(%ebp), %ebx
 1290      EBFFFF
 1291 0fea 8DB43700 		leal	8421376(%edi,%esi), %esi
 1291      808000
 1292 0ff1 8D1C1E   		leal	(%esi,%ebx), %ebx
 1293 0ff4 8B7510   		movl	16(%ebp), %esi
 1294 0ff7 C1FB10   		sarl	$16, %ebx
 1295 0ffa 0FB6DB   		movzbl	%bl, %ebx
 1296 0ffd 83C380   		addl	$-128, %ebx
 1297 1000 66895C0E 		movw	%bx, 6(%esi,%ecx)
 1297      06
 1298 1005 0FB65A18 		movzbl	24(%edx), %ebx
 1299 1009 0FB6721B 		movzbl	27(%edx), %esi
 1300 100d 0FB67A1C 		movzbl	28(%edx), %edi
 1301 1011 01DE     		addl	%ebx, %esi
 1302 1013 0FB65818 		movzbl	24(%eax), %ebx
 1303 1017 01DE     		addl	%ebx, %esi
 1304 1019 0FB6581B 		movzbl	27(%eax), %ebx
 1305 101d 8D1C1E   		leal	(%esi,%ebx), %ebx
 1306 1020 0FB67219 		movzbl	25(%edx), %esi
 1307 1024 C1FB02   		sarl	$2, %ebx
 1308 1027 0FB6DB   		movzbl	%bl, %ebx
 1309 102a 895DE4   		movl	%ebx, -28(%ebp)
 1310 102d 01F7     		addl	%esi, %edi
 1311 102f 0FB67019 		movzbl	25(%eax), %esi
 1312 1033 01F7     		addl	%esi, %edi
 1313 1035 0FB6701C 		movzbl	28(%eax), %esi
 1314 1039 8D3437   		leal	(%edi,%esi), %esi
 1315 103c 0FB67A1D 		movzbl	29(%edx), %edi
 1316 1040 C1FE02   		sarl	$2, %esi
 1317 1043 89F3     		movl	%esi, %ebx
 1318 1045 0FB6F3   		movzbl	%bl, %esi
 1319 1048 8975EC   		movl	%esi, -20(%ebp)
 1320 104b 0FB6721A 		movzbl	26(%edx), %esi
 1321 104f 01F7     		addl	%esi, %edi
 1322 1051 0FB6701A 		movzbl	26(%eax), %esi
 1323 1055 01F7     		addl	%esi, %edi
 1324 1057 0FB6701D 		movzbl	29(%eax), %esi
 1325 105b 8D3437   		leal	(%edi,%esi), %esi
 1326 105e C1FE02   		sarl	$2, %esi
 1327 1061 81E6FF00 		andl	$255, %esi
 1327      0000
 1328 1067 69FECED4 		imull	$-11058, %esi, %edi
 1328      FFFF
 1329 106d 897DF0   		movl	%edi, -16(%ebp)
 1330 1070 8B5DF0   		movl	-16(%ebp), %ebx
 1331 1073 697DEC33 		imull	$-21709, -20(%ebp), %edi
 1331      ABFFFF
 1332 107a 8DBC3B00 		leal	8421376(%ebx,%edi), %edi
 1332      808000
 1333 1081 8B5D0C   		movl	12(%ebp), %ebx
 1334 1084 897DF0   		movl	%edi, -16(%ebp)
 1335 1087 8B7DE4   		movl	-28(%ebp), %edi
 1336 108a C1E70F   		sall	$15, %edi
 1337 108d 2B7DE4   		subl	-28(%ebp), %edi
 1338 1090 037DF0   		addl	-16(%ebp), %edi
 1339 1093 C1FF10   		sarl	$16, %edi
GAS LISTING /tmp/ccJXpt5V.s 			page 30


 1340 1096 6681E7FF 		andw	$255, %di
 1340      00
 1341 109b 83C780   		addl	$-128, %edi
 1342 109e 66897C0B 		movw	%di, 8(%ebx,%ecx)
 1342      08
 1343 10a3 89F7     		movl	%esi, %edi
 1344 10a5 C1E70F   		sall	$15, %edi
 1345 10a8 29F7     		subl	%esi, %edi
 1346 10aa 6975ECD2 		imull	$-27438, -20(%ebp), %esi
 1346      94FFFF
 1347 10b1 695DE42F 		imull	$-5329, -28(%ebp), %ebx
 1347      EBFFFF
 1348 10b8 8DB43700 		leal	8421376(%edi,%esi), %esi
 1348      808000
 1349 10bf 8D1C1E   		leal	(%esi,%ebx), %ebx
 1350 10c2 8B7510   		movl	16(%ebp), %esi
 1351 10c5 C1FB10   		sarl	$16, %ebx
 1352 10c8 0FB6DB   		movzbl	%bl, %ebx
 1353 10cb 83C380   		addl	$-128, %ebx
 1354 10ce 66895C0E 		movw	%bx, 8(%esi,%ecx)
 1354      08
 1355 10d3 0FB65A1E 		movzbl	30(%edx), %ebx
 1356 10d7 0FB67221 		movzbl	33(%edx), %esi
 1357 10db 01DE     		addl	%ebx, %esi
 1358 10dd 0FB6581E 		movzbl	30(%eax), %ebx
 1359 10e1 01DE     		addl	%ebx, %esi
 1360 10e3 0FB65821 		movzbl	33(%eax), %ebx
 1361 10e7 8D1C1E   		leal	(%esi,%ebx), %ebx
 1362 10ea C1FB02   		sarl	$2, %ebx
 1363 10ed 0FB6DB   		movzbl	%bl, %ebx
 1364 10f0 895DE4   		movl	%ebx, -28(%ebp)
 1365 10f3 0FB6721F 		movzbl	31(%edx), %esi
 1366 10f7 0FB67A22 		movzbl	34(%edx), %edi
 1367 10fb 01F7     		addl	%esi, %edi
 1368 10fd 0FB6701F 		movzbl	31(%eax), %esi
 1369 1101 01F7     		addl	%esi, %edi
 1370 1103 0FB67022 		movzbl	34(%eax), %esi
 1371 1107 8D3437   		leal	(%edi,%esi), %esi
 1372 110a 0FB67A23 		movzbl	35(%edx), %edi
 1373 110e C1FE02   		sarl	$2, %esi
 1374 1111 89F3     		movl	%esi, %ebx
 1375 1113 0FB6F3   		movzbl	%bl, %esi
 1376 1116 8975EC   		movl	%esi, -20(%ebp)
 1377 1119 0FB67220 		movzbl	32(%edx), %esi
 1378 111d 01F7     		addl	%esi, %edi
 1379 111f 0FB67020 		movzbl	32(%eax), %esi
 1380 1123 01F7     		addl	%esi, %edi
 1381 1125 0FB67023 		movzbl	35(%eax), %esi
 1382 1129 8D3437   		leal	(%edi,%esi), %esi
 1383 112c C1FE02   		sarl	$2, %esi
 1384 112f 81E6FF00 		andl	$255, %esi
 1384      0000
 1385 1135 69FECED4 		imull	$-11058, %esi, %edi
 1385      FFFF
 1386 113b 897DF0   		movl	%edi, -16(%ebp)
 1387 113e 8B5DF0   		movl	-16(%ebp), %ebx
 1388 1141 697DEC33 		imull	$-21709, -20(%ebp), %edi
GAS LISTING /tmp/ccJXpt5V.s 			page 31


 1388      ABFFFF
 1389 1148 8DBC3B00 		leal	8421376(%ebx,%edi), %edi
 1389      808000
 1390 114f 8B5D0C   		movl	12(%ebp), %ebx
 1391 1152 897DF0   		movl	%edi, -16(%ebp)
 1392 1155 8B7DE4   		movl	-28(%ebp), %edi
 1393 1158 C1E70F   		sall	$15, %edi
 1394 115b 2B7DE4   		subl	-28(%ebp), %edi
 1395 115e 037DF0   		addl	-16(%ebp), %edi
 1396 1161 C1FF10   		sarl	$16, %edi
 1397 1164 6681E7FF 		andw	$255, %di
 1397      00
 1398 1169 83C780   		addl	$-128, %edi
 1399 116c 66897C0B 		movw	%di, 10(%ebx,%ecx)
 1399      0A
 1400 1171 89F7     		movl	%esi, %edi
 1401 1173 C1E70F   		sall	$15, %edi
 1402 1176 29F7     		subl	%esi, %edi
 1403 1178 6975ECD2 		imull	$-27438, -20(%ebp), %esi
 1403      94FFFF
 1404 117f 695DE42F 		imull	$-5329, -28(%ebp), %ebx
 1404      EBFFFF
 1405 1186 8DB43700 		leal	8421376(%edi,%esi), %esi
 1405      808000
 1406 118d 8D1C1E   		leal	(%esi,%ebx), %ebx
 1407 1190 8B7510   		movl	16(%ebp), %esi
 1408 1193 C1FB10   		sarl	$16, %ebx
 1409 1196 0FB6DB   		movzbl	%bl, %ebx
 1410 1199 83C380   		addl	$-128, %ebx
 1411 119c 66895C0E 		movw	%bx, 10(%esi,%ecx)
 1411      0A
 1412 11a1 0FB65A24 		movzbl	36(%edx), %ebx
 1413 11a5 0FB67227 		movzbl	39(%edx), %esi
 1414 11a9 0FB67A28 		movzbl	40(%edx), %edi
 1415 11ad 01DE     		addl	%ebx, %esi
 1416 11af 0FB65824 		movzbl	36(%eax), %ebx
 1417 11b3 01DE     		addl	%ebx, %esi
 1418 11b5 0FB65827 		movzbl	39(%eax), %ebx
 1419 11b9 8D1C1E   		leal	(%esi,%ebx), %ebx
 1420 11bc 0FB67225 		movzbl	37(%edx), %esi
 1421 11c0 C1FB02   		sarl	$2, %ebx
 1422 11c3 0FB6DB   		movzbl	%bl, %ebx
 1423 11c6 895DE4   		movl	%ebx, -28(%ebp)
 1424 11c9 01F7     		addl	%esi, %edi
 1425 11cb 0FB67025 		movzbl	37(%eax), %esi
 1426 11cf 01F7     		addl	%esi, %edi
 1427 11d1 0FB67028 		movzbl	40(%eax), %esi
 1428 11d5 8D3437   		leal	(%edi,%esi), %esi
 1429 11d8 0FB67A29 		movzbl	41(%edx), %edi
 1430 11dc C1FE02   		sarl	$2, %esi
 1431 11df 89F3     		movl	%esi, %ebx
 1432 11e1 0FB6F3   		movzbl	%bl, %esi
 1433 11e4 8975EC   		movl	%esi, -20(%ebp)
 1434 11e7 0FB67226 		movzbl	38(%edx), %esi
 1435 11eb 01F7     		addl	%esi, %edi
 1436 11ed 0FB67026 		movzbl	38(%eax), %esi
 1437 11f1 01F7     		addl	%esi, %edi
GAS LISTING /tmp/ccJXpt5V.s 			page 32


 1438 11f3 0FB67029 		movzbl	41(%eax), %esi
 1439 11f7 8D3437   		leal	(%edi,%esi), %esi
 1440 11fa C1FE02   		sarl	$2, %esi
 1441 11fd 81E6FF00 		andl	$255, %esi
 1441      0000
 1442 1203 69FECED4 		imull	$-11058, %esi, %edi
 1442      FFFF
 1443 1209 897DF0   		movl	%edi, -16(%ebp)
 1444 120c 8B5DF0   		movl	-16(%ebp), %ebx
 1445 120f 697DEC33 		imull	$-21709, -20(%ebp), %edi
 1445      ABFFFF
 1446 1216 8DBC3B00 		leal	8421376(%ebx,%edi), %edi
 1446      808000
 1447 121d 8B5D0C   		movl	12(%ebp), %ebx
 1448 1220 897DF0   		movl	%edi, -16(%ebp)
 1449 1223 8B7DE4   		movl	-28(%ebp), %edi
 1450 1226 C1E70F   		sall	$15, %edi
 1451 1229 2B7DE4   		subl	-28(%ebp), %edi
 1452 122c 037DF0   		addl	-16(%ebp), %edi
 1453 122f C1FF10   		sarl	$16, %edi
 1454 1232 6681E7FF 		andw	$255, %di
 1454      00
 1455 1237 83C780   		addl	$-128, %edi
 1456 123a 66897C0B 		movw	%di, 12(%ebx,%ecx)
 1456      0C
 1457 123f 89F7     		movl	%esi, %edi
 1458 1241 C1E70F   		sall	$15, %edi
 1459 1244 29F7     		subl	%esi, %edi
 1460 1246 6975ECD2 		imull	$-27438, -20(%ebp), %esi
 1460      94FFFF
 1461 124d 695DE42F 		imull	$-5329, -28(%ebp), %ebx
 1461      EBFFFF
 1462 1254 8DB43700 		leal	8421376(%edi,%esi), %esi
 1462      808000
 1463 125b 8D1C1E   		leal	(%esi,%ebx), %ebx
 1464 125e 8B7510   		movl	16(%ebp), %esi
 1465 1261 C1FB10   		sarl	$16, %ebx
 1466 1264 0FB6DB   		movzbl	%bl, %ebx
 1467 1267 83C380   		addl	$-128, %ebx
 1468 126a 66895C0E 		movw	%bx, 12(%esi,%ecx)
 1468      0C
 1469 126f 0FB65A2A 		movzbl	42(%edx), %ebx
 1470 1273 0FB6722D 		movzbl	45(%edx), %esi
 1471 1277 0FB67A2E 		movzbl	46(%edx), %edi
 1472 127b 01DE     		addl	%ebx, %esi
 1473 127d 0FB6582A 		movzbl	42(%eax), %ebx
 1474 1281 01DE     		addl	%ebx, %esi
 1475 1283 0FB6582D 		movzbl	45(%eax), %ebx
 1476 1287 8D1C1E   		leal	(%esi,%ebx), %ebx
 1477 128a 0FB6722B 		movzbl	43(%edx), %esi
 1478 128e C1FB02   		sarl	$2, %ebx
 1479 1291 0FB6DB   		movzbl	%bl, %ebx
 1480 1294 01F7     		addl	%esi, %edi
 1481 1296 0FB6702B 		movzbl	43(%eax), %esi
 1482 129a 01F7     		addl	%esi, %edi
 1483 129c 0FB6702E 		movzbl	46(%eax), %esi
 1484 12a0 8D3437   		leal	(%edi,%esi), %esi
GAS LISTING /tmp/ccJXpt5V.s 			page 33


 1485 12a3 0FB67A2F 		movzbl	47(%edx), %edi
 1486 12a7 0FB6522C 		movzbl	44(%edx), %edx
 1487 12ab C1FE02   		sarl	$2, %esi
 1488 12ae 81E6FF00 		andl	$255, %esi
 1488      0000
 1489 12b4 01D7     		addl	%edx, %edi
 1490 12b6 0FB6502C 		movzbl	44(%eax), %edx
 1491 12ba 0FB6402F 		movzbl	47(%eax), %eax
 1492 12be 8D1417   		leal	(%edi,%edx), %edx
 1493 12c1 8D0402   		leal	(%edx,%eax), %eax
 1494 12c4 C1F802   		sarl	$2, %eax
 1495 12c7 0FB6C0   		movzbl	%al, %eax
 1496 12ca 69D633AB 		imull	$-21709, %esi, %edx
 1496      FFFF
 1497 12d0 69F8CED4 		imull	$-11058, %eax, %edi
 1497      FFFF
 1498 12d6 69F6D294 		imull	$-27438, %esi, %esi
 1498      FFFF
 1499 12dc 8DBC1700 		leal	8421376(%edi,%edx), %edi
 1499      808000
 1500 12e3 89DA     		movl	%ebx, %edx
 1501 12e5 C1E20F   		sall	$15, %edx
 1502 12e8 29DA     		subl	%ebx, %edx
 1503 12ea 8D1417   		leal	(%edi,%edx), %edx
 1504 12ed 8B7D0C   		movl	12(%ebp), %edi
 1505 12f0 C1FA10   		sarl	$16, %edx
 1506 12f3 0FB6D2   		movzbl	%dl, %edx
 1507 12f6 83C280   		addl	$-128, %edx
 1508 12f9 6689540F 		movw	%dx, 14(%edi,%ecx)
 1508      0E
 1509 12fe 69DB2FEB 		imull	$-5329, %ebx, %ebx
 1509      FFFF
 1510 1304 89C2     		movl	%eax, %edx
 1511 1306 C1E20F   		sall	$15, %edx
 1512 1309 29C2     		subl	%eax, %edx
 1513 130b 8D843200 		leal	8421376(%edx,%esi), %eax
 1513      808000
 1514 1312 8D1C18   		leal	(%eax,%ebx), %ebx
 1515 1315 8B4510   		movl	16(%ebp), %eax
 1516 1318 C1FB10   		sarl	$16, %ebx
 1517 131b 0FB6DB   		movzbl	%bl, %ebx
 1518 131e 83C380   		addl	$-128, %ebx
 1519 1321 66895C08 		movw	%bx, 14(%eax,%ecx)
 1519      0E
 1520 1326 83C110   		addl	$16, %ecx
 1521 1329 8345E801 		addl	$1, -24(%ebp)
 1522 132d 837DE808 		cmpl	$8, -24(%ebp)
 1523 1331 0F8581F9 		jne	.L275
 1523      FFFF
 1524 1337 83C410   		addl	$16, %esp
 1525 133a 5B       		popl	%ebx
 1526              		.cfi_restore 3
 1527 133b 5E       		popl	%esi
 1528              		.cfi_restore 6
 1529 133c 5F       		popl	%edi
 1530              		.cfi_restore 7
 1531 133d 5D       		popl	%ebp
GAS LISTING /tmp/ccJXpt5V.s 			page 34


 1532              		.cfi_restore 5
 1533              		.cfi_def_cfa 4, 4
 1534 133e C3       		ret
 1535              		.cfi_endproc
 1536              	.LFE118:
 1537              		.size	_Z9subsamplePA16_K3BGRPA8_sS4_, .-_Z9subsamplePA16_K3BGRPA8_sS4_
 1538 133f 90       		.p2align 4,,15
 1539              	.globl _Z10subsample2PA16_K3BGRPA2_A8_A8_sPS3_S7_
 1540              		.type	_Z10subsample2PA16_K3BGRPA2_A8_A8_sPS3_S7_, @function
 1541              	_Z10subsample2PA16_K3BGRPA2_A8_A8_sPS3_S7_:
 1542              	.LFB119:
 1543              		.cfi_startproc
 1544 1340 55       		pushl	%ebp
 1545              		.cfi_def_cfa_offset 8
 1546 1341 89E5     		movl	%esp, %ebp
 1547              		.cfi_offset 5, -8
 1548              		.cfi_def_cfa_register 5
 1549 1343 57       		pushl	%edi
 1550 1344 56       		pushl	%esi
 1551 1345 53       		pushl	%ebx
 1552 1346 83EC44   		subl	$68, %esp
 1553 1349 E8FCFFFF 		call	mcount
 1553      FF
 1554 134e 8B4508   		movl	8(%ebp), %eax
 1555 1351 C745B800 		movl	$0, -72(%ebp)
 1555      000000
 1556 1358 8945E8   		movl	%eax, -24(%ebp)
 1557 135b 908D7426 		.p2align 4,,7
 1557      00
 1558              		.p2align 3
 1559              	.L278:
 1560 1360 8B45B8   		movl	-72(%ebp), %eax
 1561 1363 8B7D10   		movl	16(%ebp), %edi
 1562              		.cfi_offset 3, -20
 1563              		.cfi_offset 6, -16
 1564              		.cfi_offset 7, -12
 1565 1366 8B5DB8   		movl	-72(%ebp), %ebx
 1566 1369 8B75E8   		movl	-24(%ebp), %esi
 1567 136c C1E803   		shrl	$3, %eax
 1568 136f C1E008   		sall	$8, %eax
 1569 1372 03450C   		addl	12(%ebp), %eax
 1570 1375 83E307   		andl	$7, %ebx
 1571 1378 895DC8   		movl	%ebx, -56(%ebp)
 1572 137b 83C630   		addl	$48, %esi
 1573 137e 83C301   		addl	$1, %ebx
 1574 1381 8975E0   		movl	%esi, -32(%ebp)
 1575 1384 8945D4   		movl	%eax, -44(%ebp)
 1576 1387 8B45B8   		movl	-72(%ebp), %eax
 1577 138a 895DC4   		movl	%ebx, -60(%ebp)
 1578 138d C745E400 		movl	$0, -28(%ebp)
 1578      000000
 1579 1394 D1E8     		shrl	%eax
 1580 1396 C1E004   		sall	$4, %eax
 1581 1399 01C7     		addl	%eax, %edi
 1582 139b 034514   		addl	20(%ebp), %eax
 1583 139e 897DC0   		movl	%edi, -64(%ebp)
 1584 13a1 8945BC   		movl	%eax, -68(%ebp)
GAS LISTING /tmp/ccJXpt5V.s 			page 35


 1585 13a4 31C0     		xorl	%eax, %eax
 1586              		.p2align 4,,7
 1587 13a6 6690     		.p2align 3
 1588              	.L279:
 1589 13a8 8B55E4   		movl	-28(%ebp), %edx
 1590 13ab 8B75E4   		movl	-28(%ebp), %esi
 1591 13ae 8B4DE8   		movl	-24(%ebp), %ecx
 1592 13b1 8B5DE8   		movl	-24(%ebp), %ebx
 1593 13b4 83E2F8   		andl	$-8, %edx
 1594 13b7 8955DC   		movl	%edx, -36(%ebp)
 1595 13ba 83E607   		andl	$7, %esi
 1596 13bd 0355C8   		addl	-56(%ebp), %edx
 1597 13c0 C1E203   		sall	$3, %edx
 1598 13c3 8955EC   		movl	%edx, -20(%ebp)
 1599 13c6 01F2     		addl	%esi, %edx
 1600 13c8 8955F0   		movl	%edx, -16(%ebp)
 1601 13cb 0FB64C01 		movzbl	2(%ecx,%eax), %ecx
 1601      02
 1602 13d0 894DD0   		movl	%ecx, -48(%ebp)
 1603 13d3 0FB65C03 		movzbl	1(%ebx,%eax), %ebx
 1603      01
 1604 13d8 69F98B4C 		imull	$19595, %ecx, %edi
 1604      0000
 1605 13de 895DCC   		movl	%ebx, -52(%ebp)
 1606 13e1 69DB4696 		imull	$38470, %ebx, %ebx
 1606      0000
 1607 13e7 8D941F00 		leal	32768(%edi,%ebx), %edx
 1607      800000
 1608 13ee 8B7DE8   		movl	-24(%ebp), %edi
 1609 13f1 8B5DD4   		movl	-44(%ebp), %ebx
 1610 13f4 0FB63C07 		movzbl	(%edi,%eax), %edi
 1611 13f8 897DB4   		movl	%edi, -76(%ebp)
 1612 13fb 69FF2F1D 		imull	$7471, %edi, %edi
 1612      0000
 1613 1401 01D7     		addl	%edx, %edi
 1614 1403 8B55F0   		movl	-16(%ebp), %edx
 1615 1406 C1FF10   		sarl	$16, %edi
 1616 1409 6681E7FF 		andw	$255, %di
 1616      00
 1617 140e 8D4F80   		leal	-128(%edi), %ecx
 1618 1411 66890C53 		movw	%cx, (%ebx,%edx,2)
 1619 1415 8B55E8   		movl	-24(%ebp), %edx
 1620 1418 8B4DD0   		movl	-48(%ebp), %ecx
 1621 141b 8B5DCC   		movl	-52(%ebp), %ebx
 1622 141e 0FB67C02 		movzbl	5(%edx,%eax), %edi
 1622      05
 1623 1423 01F9     		addl	%edi, %ecx
 1624 1425 894DD8   		movl	%ecx, -40(%ebp)
 1625 1428 0FB65402 		movzbl	4(%edx,%eax), %edx
 1625      04
 1626 142d 69FF8B4C 		imull	$19595, %edi, %edi
 1626      0000
 1627 1433 01D3     		addl	%edx, %ebx
 1628 1435 895DD0   		movl	%ebx, -48(%ebp)
 1629 1438 8B5DE8   		movl	-24(%ebp), %ebx
 1630 143b 69D24696 		imull	$38470, %edx, %edx
 1630      0000
GAS LISTING /tmp/ccJXpt5V.s 			page 36


 1631 1441 0FB64C03 		movzbl	3(%ebx,%eax), %ecx
 1631      03
 1632 1446 8D941700 		leal	32768(%edi,%edx), %edx
 1632      800000
 1633 144d 8B5DB4   		movl	-76(%ebp), %ebx
 1634 1450 8B7DD4   		movl	-44(%ebp), %edi
 1635 1453 01CB     		addl	%ecx, %ebx
 1636 1455 69C92F1D 		imull	$7471, %ecx, %ecx
 1636      0000
 1637 145b 895DCC   		movl	%ebx, -52(%ebp)
 1638 145e 8D5E01   		leal	1(%esi), %ebx
 1639 1461 895DF0   		movl	%ebx, -16(%ebp)
 1640 1464 8B5DEC   		movl	-20(%ebp), %ebx
 1641 1467 035DF0   		addl	-16(%ebp), %ebx
 1642 146a 8D0C0A   		leal	(%edx,%ecx), %ecx
 1643 146d C1F910   		sarl	$16, %ecx
 1644 1470 0FB6C9   		movzbl	%cl, %ecx
 1645 1473 83C180   		addl	$-128, %ecx
 1646 1476 66890C5F 		movw	%cx, (%edi,%ebx,2)
 1647 147a 8B55E0   		movl	-32(%ebp), %edx
 1648 147d 8B4DD8   		movl	-40(%ebp), %ecx
 1649 1480 8B7DD0   		movl	-48(%ebp), %edi
 1650 1483 0FB65C02 		movzbl	2(%edx,%eax), %ebx
 1650      02
 1651 1488 01D9     		addl	%ebx, %ecx
 1652 148a 894DEC   		movl	%ecx, -20(%ebp)
 1653 148d 0FB64C02 		movzbl	1(%edx,%eax), %ecx
 1653      01
 1654 1492 69DB8B4C 		imull	$19595, %ebx, %ebx
 1654      0000
 1655 1498 01CF     		addl	%ecx, %edi
 1656 149a 897DD8   		movl	%edi, -40(%ebp)
 1657 149d 8B7DCC   		movl	-52(%ebp), %edi
 1658 14a0 69C94696 		imull	$38470, %ecx, %ecx
 1658      0000
 1659 14a6 0FB61402 		movzbl	(%edx,%eax), %edx
 1660 14aa 8D8C0B00 		leal	32768(%ebx,%ecx), %ecx
 1660      800000
 1661 14b1 8B5DE0   		movl	-32(%ebp), %ebx
 1662 14b4 01D7     		addl	%edx, %edi
 1663 14b6 69D22F1D 		imull	$7471, %edx, %edx
 1663      0000
 1664 14bc 897DD0   		movl	%edi, -48(%ebp)
 1665 14bf 8B7DDC   		movl	-36(%ebp), %edi
 1666 14c2 037DC4   		addl	-60(%ebp), %edi
 1667 14c5 8D1411   		leal	(%ecx,%edx), %edx
 1668 14c8 8B4DD4   		movl	-44(%ebp), %ecx
 1669 14cb C1FA10   		sarl	$16, %edx
 1670 14ce C1E703   		sall	$3, %edi
 1671 14d1 0FB6D2   		movzbl	%dl, %edx
 1672 14d4 01FE     		addl	%edi, %esi
 1673 14d6 83C280   		addl	$-128, %edx
 1674 14d9 897DDC   		movl	%edi, -36(%ebp)
 1675 14dc 8B7DE0   		movl	-32(%ebp), %edi
 1676 14df 66891471 		movw	%dx, (%ecx,%esi,2)
 1677 14e3 8B75EC   		movl	-20(%ebp), %esi
 1678 14e6 0FB65C03 		movzbl	5(%ebx,%eax), %ebx
GAS LISTING /tmp/ccJXpt5V.s 			page 37


 1678      05
 1679 14eb 8B4DD8   		movl	-40(%ebp), %ecx
 1680 14ee 01DE     		addl	%ebx, %esi
 1681 14f0 895DCC   		movl	%ebx, -52(%ebp)
 1682 14f3 8B5DD0   		movl	-48(%ebp), %ebx
 1683 14f6 8975B4   		movl	%esi, -76(%ebp)
 1684 14f9 0FB65407 		movzbl	3(%edi,%eax), %edx
 1684      03
 1685 14fe 0FB67407 		movzbl	4(%edi,%eax), %esi
 1685      04
 1686 1503 8B7DDC   		movl	-36(%ebp), %edi
 1687 1506 01F1     		addl	%esi, %ecx
 1688 1508 01D3     		addl	%edx, %ebx
 1689 150a 037DF0   		addl	-16(%ebp), %edi
 1690 150d 83C006   		addl	$6, %eax
 1691 1510 69F64696 		imull	$38470, %esi, %esi
 1691      0000
 1692 1516 C1E902   		shrl	$2, %ecx
 1693 1519 897DF0   		movl	%edi, -16(%ebp)
 1694 151c 0FB6C9   		movzbl	%cl, %ecx
 1695 151f 697DCC8B 		imull	$19595, -52(%ebp), %edi
 1695      4C0000
 1696 1526 C1EB02   		shrl	$2, %ebx
 1697 1529 0FB6DB   		movzbl	%bl, %ebx
 1698 152c 8DB43700 		leal	32768(%edi,%esi), %esi
 1698      800000
 1699 1533 69FA2F1D 		imull	$7471, %edx, %edi
 1699      0000
 1700 1539 8B55F0   		movl	-16(%ebp), %edx
 1701 153c 01FE     		addl	%edi, %esi
 1702 153e 8B7DD4   		movl	-44(%ebp), %edi
 1703 1541 C1FE10   		sarl	$16, %esi
 1704 1544 6681E6FF 		andw	$255, %si
 1704      00
 1705 1549 83C680   		addl	$-128, %esi
 1706 154c 66893457 		movw	%si, (%edi,%edx,2)
 1707 1550 8B55E4   		movl	-28(%ebp), %edx
 1708 1553 69F133AB 		imull	$-21709, %ecx, %esi
 1708      FFFF
 1709 1559 D1EA     		shrl	%edx
 1710 155b 8955F0   		movl	%edx, -16(%ebp)
 1711 155e C16DB402 		shrl	$2, -76(%ebp)
 1712 1562 0FB655B4 		movzbl	-76(%ebp), %edx
 1713 1566 894DEC   		movl	%ecx, -20(%ebp)
 1714 1569 8B4DF0   		movl	-16(%ebp), %ecx
 1715 156c 69FACED4 		imull	$-11058, %edx, %edi
 1715      FFFF
 1716 1572 8DBC3700 		leal	8421376(%edi,%esi), %edi
 1716      808000
 1717 1579 89DE     		movl	%ebx, %esi
 1718 157b C1E60F   		sall	$15, %esi
 1719 157e 29DE     		subl	%ebx, %esi
 1720 1580 8D3437   		leal	(%edi,%esi), %esi
 1721 1583 8B7DC0   		movl	-64(%ebp), %edi
 1722 1586 C1FE10   		sarl	$16, %esi
 1723 1589 6681E6FF 		andw	$255, %si
 1723      00
GAS LISTING /tmp/ccJXpt5V.s 			page 38


 1724 158e 83C680   		addl	$-128, %esi
 1725 1591 6689344F 		movw	%si, (%edi,%ecx,2)
 1726 1595 69DB2FEB 		imull	$-5329, %ebx, %ebx
 1726      FFFF
 1727 159b 89D6     		movl	%edx, %esi
 1728 159d 694DECD2 		imull	$-27438, -20(%ebp), %ecx
 1728      94FFFF
 1729 15a4 C1E60F   		sall	$15, %esi
 1730 15a7 29D6     		subl	%edx, %esi
 1731 15a9 8D940E00 		leal	8421376(%esi,%ecx), %edx
 1731      808000
 1732 15b0 8B4DBC   		movl	-68(%ebp), %ecx
 1733 15b3 8D1C1A   		leal	(%edx,%ebx), %ebx
 1734 15b6 8B55F0   		movl	-16(%ebp), %edx
 1735 15b9 C1FB10   		sarl	$16, %ebx
 1736 15bc 0FB6DB   		movzbl	%bl, %ebx
 1737 15bf 83C380   		addl	$-128, %ebx
 1738 15c2 66891C51 		movw	%bx, (%ecx,%edx,2)
 1739 15c6 8345E402 		addl	$2, -28(%ebp)
 1740 15ca 837DE410 		cmpl	$16, -28(%ebp)
 1741 15ce 0F85D4FD 		jne	.L279
 1741      FFFF
 1742 15d4 8345B802 		addl	$2, -72(%ebp)
 1743 15d8 8345E860 		addl	$96, -24(%ebp)
 1744 15dc 837DB810 		cmpl	$16, -72(%ebp)
 1745 15e0 0F857AFD 		jne	.L278
 1745      FFFF
 1746 15e6 83C444   		addl	$68, %esp
 1747 15e9 5B       		popl	%ebx
 1748              		.cfi_restore 3
 1749 15ea 5E       		popl	%esi
 1750              		.cfi_restore 6
 1751 15eb 5F       		popl	%edi
 1752              		.cfi_restore 7
 1753 15ec 5D       		popl	%ebp
 1754              		.cfi_restore 5
 1755              		.cfi_def_cfa 4, 4
 1756 15ed C3       		ret
 1757              		.cfi_endproc
 1758              	.LFE119:
 1759              		.size	_Z10subsample2PA16_K3BGRPA2_A8_A8_sPS3_S7_, .-_Z10subsample2PA16_K3BGRPA2_A8_A8_sPS3_S7_
 1760 15ee 6690     		.p2align 4,,15
 1761              	.globl _Z10subsample3PA16_KhS1_S1_PA2_A8_A8_sPS2_S6_
 1762              		.type	_Z10subsample3PA16_KhS1_S1_PA2_A8_A8_sPS2_S6_, @function
 1763              	_Z10subsample3PA16_KhS1_S1_PA2_A8_A8_sPS2_S6_:
 1764              	.LFB120:
 1765              		.cfi_startproc
 1766 15f0 55       		pushl	%ebp
 1767              		.cfi_def_cfa_offset 8
 1768 15f1 89E5     		movl	%esp, %ebp
 1769              		.cfi_offset 5, -8
 1770              		.cfi_def_cfa_register 5
 1771 15f3 57       		pushl	%edi
 1772 15f4 56       		pushl	%esi
 1773 15f5 53       		pushl	%ebx
 1774 15f6 83EC5C   		subl	$92, %esp
 1775 15f9 E8FCFFFF 		call	mcount
GAS LISTING /tmp/ccJXpt5V.s 			page 39


 1775      FF
 1776 15fe 8B4508   		movl	8(%ebp), %eax
 1777 1601 8B550C   		movl	12(%ebp), %edx
 1778 1604 8B4D10   		movl	16(%ebp), %ecx
 1779 1607 C745A800 		movl	$0, -88(%ebp)
 1779      000000
 1780 160e 8945D8   		movl	%eax, -40(%ebp)
 1781 1611 8955D4   		movl	%edx, -44(%ebp)
 1782 1614 894DD0   		movl	%ecx, -48(%ebp)
 1783              		.p2align 4,,7
 1784 1617 90       		.p2align 3
 1785              	.L283:
 1786 1618 8B45A8   		movl	-88(%ebp), %eax
 1787 161b 8B5518   		movl	24(%ebp), %edx
 1788 161e 8B5DA8   		movl	-88(%ebp), %ebx
 1789              		.cfi_offset 3, -20
 1790              		.cfi_offset 6, -16
 1791              		.cfi_offset 7, -12
 1792 1621 8B75D8   		movl	-40(%ebp), %esi
 1793 1624 C1E803   		shrl	$3, %eax
 1794 1627 8B7DD4   		movl	-44(%ebp), %edi
 1795 162a C1E008   		sall	$8, %eax
 1796 162d 034514   		addl	20(%ebp), %eax
 1797 1630 83E307   		andl	$7, %ebx
 1798 1633 895DB8   		movl	%ebx, -72(%ebp)
 1799 1636 83C610   		addl	$16, %esi
 1800 1639 83C301   		addl	$1, %ebx
 1801 163c 83C710   		addl	$16, %edi
 1802 163f 8945DC   		movl	%eax, -36(%ebp)
 1803 1642 8B45D0   		movl	-48(%ebp), %eax
 1804 1645 8975CC   		movl	%esi, -52(%ebp)
 1805 1648 897DC8   		movl	%edi, -56(%ebp)
 1806 164b 895DB4   		movl	%ebx, -76(%ebp)
 1807 164e 83C010   		addl	$16, %eax
 1808 1651 8945C4   		movl	%eax, -60(%ebp)
 1809 1654 8B45A8   		movl	-88(%ebp), %eax
 1810 1657 D1E8     		shrl	%eax
 1811 1659 C1E004   		sall	$4, %eax
 1812 165c 01C2     		addl	%eax, %edx
 1813 165e 03451C   		addl	28(%ebp), %eax
 1814 1661 8955B0   		movl	%edx, -80(%ebp)
 1815 1664 8945AC   		movl	%eax, -84(%ebp)
 1816 1667 31C0     		xorl	%eax, %eax
 1817 1669 8DB42600 		.p2align 4,,7
 1817      000000
 1818              		.p2align 3
 1819              	.L284:
 1820 1670 8B55B8   		movl	-72(%ebp), %edx
 1821 1673 89C3     		movl	%eax, %ebx
 1822 1675 89C6     		movl	%eax, %esi
 1823 1677 8B7DD8   		movl	-40(%ebp), %edi
 1824 167a 83E3F8   		andl	$-8, %ebx
 1825 167d 83E607   		andl	$7, %esi
 1826 1680 895DE8   		movl	%ebx, -24(%ebp)
 1827 1683 01DA     		addl	%ebx, %edx
 1828 1685 8B5DD4   		movl	-44(%ebp), %ebx
 1829 1688 0FB63C07 		movzbl	(%edi,%eax), %edi
GAS LISTING /tmp/ccJXpt5V.s 			page 40


 1830 168c C1E203   		sall	$3, %edx
 1831 168f 8D0C32   		leal	(%edx,%esi), %ecx
 1832 1692 897DEC   		movl	%edi, -20(%ebp)
 1833 1695 0FB61C03 		movzbl	(%ebx,%eax), %ebx
 1834 1699 69FF8B4C 		imull	$19595, %edi, %edi
 1834      0000
 1835 169f 895DE4   		movl	%ebx, -28(%ebp)
 1836 16a2 69DB4696 		imull	$38470, %ebx, %ebx
 1836      0000
 1837 16a8 8DBC1F00 		leal	32768(%edi,%ebx), %edi
 1837      800000
 1838 16af 8B5DD0   		movl	-48(%ebp), %ebx
 1839 16b2 0FB61C03 		movzbl	(%ebx,%eax), %ebx
 1840 16b6 895DE0   		movl	%ebx, -32(%ebp)
 1841 16b9 69DB2F1D 		imull	$7471, %ebx, %ebx
 1841      0000
 1842 16bf 8D1C1F   		leal	(%edi,%ebx), %ebx
 1843 16c2 8B7DDC   		movl	-36(%ebp), %edi
 1844 16c5 C1FB10   		sarl	$16, %ebx
 1845 16c8 0FB6DB   		movzbl	%bl, %ebx
 1846 16cb 83C380   		addl	$-128, %ebx
 1847 16ce 66891C4F 		movw	%bx, (%edi,%ecx,2)
 1848 16d2 8D4E01   		leal	1(%esi), %ecx
 1849 16d5 8B5DD8   		movl	-40(%ebp), %ebx
 1850 16d8 894DF0   		movl	%ecx, -16(%ebp)
 1851 16db 01CA     		addl	%ecx, %edx
 1852 16dd 8B4DD4   		movl	-44(%ebp), %ecx
 1853 16e0 8955C0   		movl	%edx, -64(%ebp)
 1854 16e3 0FB65403 		movzbl	1(%ebx,%eax), %edx
 1854      01
 1855 16e8 0FB64C01 		movzbl	1(%ecx,%eax), %ecx
 1855      01
 1856 16ed 69FA8B4C 		imull	$19595, %edx, %edi
 1856      0000
 1857 16f3 69D94696 		imull	$38470, %ecx, %ebx
 1857      0000
 1858 16f9 894DA4   		movl	%ecx, -92(%ebp)
 1859 16fc 0355EC   		addl	-20(%ebp), %edx
 1860 16ff 8D8C1F00 		leal	32768(%edi,%ebx), %ecx
 1860      800000
 1861 1706 8B5DD0   		movl	-48(%ebp), %ebx
 1862 1709 0FB65C03 		movzbl	1(%ebx,%eax), %ebx
 1862      01
 1863 170e 69FB2F1D 		imull	$7471, %ebx, %edi
 1863      0000
 1864 1714 895D98   		movl	%ebx, -104(%ebp)
 1865 1717 8B5DDC   		movl	-36(%ebp), %ebx
 1866 171a 01CF     		addl	%ecx, %edi
 1867 171c 8B4DC0   		movl	-64(%ebp), %ecx
 1868 171f C1FF10   		sarl	$16, %edi
 1869 1722 6681E7FF 		andw	$255, %di
 1869      00
 1870 1727 83C780   		addl	$-128, %edi
 1871 172a 66893C4B 		movw	%di, (%ebx,%ecx,2)
 1872 172e 8B4DCC   		movl	-52(%ebp), %ecx
 1873 1731 8B5DA4   		movl	-92(%ebp), %ebx
 1874 1734 035DE4   		addl	-28(%ebp), %ebx
GAS LISTING /tmp/ccJXpt5V.s 			page 41


 1875 1737 0FB63C01 		movzbl	(%ecx,%eax), %edi
 1876 173b 8B4DC8   		movl	-56(%ebp), %ecx
 1877 173e 01FA     		addl	%edi, %edx
 1878 1740 8955EC   		movl	%edx, -20(%ebp)
 1879 1743 0FB61401 		movzbl	(%ecx,%eax), %edx
 1880 1747 69FF8B4C 		imull	$19595, %edi, %edi
 1880      0000
 1881 174d 01D3     		addl	%edx, %ebx
 1882 174f 895DE4   		movl	%ebx, -28(%ebp)
 1883 1752 8B5D98   		movl	-104(%ebp), %ebx
 1884 1755 69D24696 		imull	$38470, %edx, %edx
 1884      0000
 1885 175b 035DE0   		addl	-32(%ebp), %ebx
 1886 175e 895DE0   		movl	%ebx, -32(%ebp)
 1887 1761 8B5DC4   		movl	-60(%ebp), %ebx
 1888 1764 8D941700 		leal	32768(%edi,%edx), %edx
 1888      800000
 1889 176b 8B7DDC   		movl	-36(%ebp), %edi
 1890 176e 0FB60C03 		movzbl	(%ebx,%eax), %ecx
 1891 1772 8B5DE0   		movl	-32(%ebp), %ebx
 1892 1775 01CB     		addl	%ecx, %ebx
 1893 1777 69C92F1D 		imull	$7471, %ecx, %ecx
 1893      0000
 1894 177d 895DE0   		movl	%ebx, -32(%ebp)
 1895 1780 8B5DE8   		movl	-24(%ebp), %ebx
 1896 1783 035DB4   		addl	-76(%ebp), %ebx
 1897 1786 8D0C0A   		leal	(%edx,%ecx), %ecx
 1898 1789 8B55CC   		movl	-52(%ebp), %edx
 1899 178c C1F910   		sarl	$16, %ecx
 1900 178f C1E303   		sall	$3, %ebx
 1901 1792 0FB6C9   		movzbl	%cl, %ecx
 1902 1795 01DE     		addl	%ebx, %esi
 1903 1797 83C180   		addl	$-128, %ecx
 1904 179a 895DE8   		movl	%ebx, -24(%ebp)
 1905 179d 8B5DC8   		movl	-56(%ebp), %ebx
 1906 17a0 66890C77 		movw	%cx, (%edi,%esi,2)
 1907 17a4 8B4DEC   		movl	-20(%ebp), %ecx
 1908 17a7 0FB65402 		movzbl	1(%edx,%eax), %edx
 1908      01
 1909 17ac 8B7DC4   		movl	-60(%ebp), %edi
 1910 17af 01D1     		addl	%edx, %ecx
 1911 17b1 894DBC   		movl	%ecx, -68(%ebp)
 1912 17b4 8B4DE4   		movl	-28(%ebp), %ecx
 1913 17b7 8955C0   		movl	%edx, -64(%ebp)
 1914 17ba 0FB67403 		movzbl	1(%ebx,%eax), %esi
 1914      01
 1915 17bf 0FB67C07 		movzbl	1(%edi,%eax), %edi
 1915      01
 1916 17c4 8B5DE0   		movl	-32(%ebp), %ebx
 1917 17c7 8B55E8   		movl	-24(%ebp), %edx
 1918 17ca 01F1     		addl	%esi, %ecx
 1919 17cc 897DEC   		movl	%edi, -20(%ebp)
 1920 17cf 01FB     		addl	%edi, %ebx
 1921 17d1 697DC08B 		imull	$19595, -64(%ebp), %edi
 1921      4C0000
 1922 17d8 69F64696 		imull	$38470, %esi, %esi
 1922      0000
GAS LISTING /tmp/ccJXpt5V.s 			page 42


 1923 17de 0355F0   		addl	-16(%ebp), %edx
 1924 17e1 C1E902   		shrl	$2, %ecx
 1925 17e4 0FB6C9   		movzbl	%cl, %ecx
 1926 17e7 8DB43700 		leal	32768(%edi,%esi), %esi
 1926      800000
 1927 17ee 697DEC2F 		imull	$7471, -20(%ebp), %edi
 1927      1D0000
 1928 17f5 C1EB02   		shrl	$2, %ebx
 1929 17f8 0FB6DB   		movzbl	%bl, %ebx
 1930 17fb 01FE     		addl	%edi, %esi
 1931 17fd 8B7DDC   		movl	-36(%ebp), %edi
 1932 1800 C1FE10   		sarl	$16, %esi
 1933 1803 6681E6FF 		andw	$255, %si
 1933      00
 1934 1808 83C680   		addl	$-128, %esi
 1935 180b 66893457 		movw	%si, (%edi,%edx,2)
 1936 180f 89C2     		movl	%eax, %edx
 1937 1811 83C002   		addl	$2, %eax
 1938 1814 D1EA     		shrl	%edx
 1939 1816 C16DBC02 		shrl	$2, -68(%ebp)
 1940 181a 69F133AB 		imull	$-21709, %ecx, %esi
 1940      FFFF
 1941 1820 8955F0   		movl	%edx, -16(%ebp)
 1942 1823 0FB655BC 		movzbl	-68(%ebp), %edx
 1943 1827 894DEC   		movl	%ecx, -20(%ebp)
 1944 182a 8B4DF0   		movl	-16(%ebp), %ecx
 1945 182d 69FACED4 		imull	$-11058, %edx, %edi
 1945      FFFF
 1946 1833 8DBC3700 		leal	8421376(%edi,%esi), %edi
 1946      808000
 1947 183a 89DE     		movl	%ebx, %esi
 1948 183c C1E60F   		sall	$15, %esi
 1949 183f 29DE     		subl	%ebx, %esi
 1950 1841 8D3437   		leal	(%edi,%esi), %esi
 1951 1844 8B7DB0   		movl	-80(%ebp), %edi
 1952 1847 C1FE10   		sarl	$16, %esi
 1953 184a 6681E6FF 		andw	$255, %si
 1953      00
 1954 184f 83C680   		addl	$-128, %esi
 1955 1852 6689344F 		movw	%si, (%edi,%ecx,2)
 1956 1856 69DB2FEB 		imull	$-5329, %ebx, %ebx
 1956      FFFF
 1957 185c 89D6     		movl	%edx, %esi
 1958 185e 694DECD2 		imull	$-27438, -20(%ebp), %ecx
 1958      94FFFF
 1959 1865 C1E60F   		sall	$15, %esi
 1960 1868 29D6     		subl	%edx, %esi
 1961 186a 8D940E00 		leal	8421376(%esi,%ecx), %edx
 1961      808000
 1962 1871 8B4DAC   		movl	-84(%ebp), %ecx
 1963 1874 8D1C1A   		leal	(%edx,%ebx), %ebx
 1964 1877 8B55F0   		movl	-16(%ebp), %edx
 1965 187a C1FB10   		sarl	$16, %ebx
 1966 187d 0FB6DB   		movzbl	%bl, %ebx
 1967 1880 83C380   		addl	$-128, %ebx
 1968 1883 83F810   		cmpl	$16, %eax
 1969 1886 66891C51 		movw	%bx, (%ecx,%edx,2)
GAS LISTING /tmp/ccJXpt5V.s 			page 43


 1970 188a 0F85E0FD 		jne	.L284
 1970      FFFF
 1971 1890 8345A802 		addl	$2, -88(%ebp)
 1972 1894 8345D820 		addl	$32, -40(%ebp)
 1973 1898 8345D420 		addl	$32, -44(%ebp)
 1974 189c 8345D020 		addl	$32, -48(%ebp)
 1975 18a0 837DA810 		cmpl	$16, -88(%ebp)
 1976 18a4 0F856EFD 		jne	.L283
 1976      FFFF
 1977 18aa 83C45C   		addl	$92, %esp
 1978 18ad 5B       		popl	%ebx
 1979              		.cfi_restore 3
 1980 18ae 5E       		popl	%esi
 1981              		.cfi_restore 6
 1982 18af 5F       		popl	%edi
 1983              		.cfi_restore 7
 1984 18b0 5D       		popl	%ebp
 1985              		.cfi_restore 5
 1986              		.cfi_def_cfa 4, 4
 1987 18b1 C3       		ret
 1988              		.cfi_endproc
 1989              	.LFE120:
 1990              		.size	_Z10subsample3PA16_KhS1_S1_PA2_A8_A8_sPS2_S6_, .-_Z10subsample3PA16_KhS1_S1_PA2_A8_A8_sPS2_S
 1991              		.section	.rodata.str1.4,"aMS",@progbits,1
 1992              		.align 4
 1993              	.LC0:
 1994 0000 55736167 		.string	"Usage: %s file-in.bmp file-out.jpg\n"
 1994      653A2025 
 1994      73206669 
 1994      6C652D69 
 1994      6E2E626D 
 1995              		.section	.rodata.str1.1,"aMS",@progbits,1
 1996              	.LC1:
 1997 0000 726200   		.string	"rb"
 1998              	.LC2:
 1999 0003 4572726F 		.string	"Error: cannot open %s\n"
 1999      723A2063 
 1999      616E6E6F 
 1999      74206F70 
 1999      656E2025 
 2000              	.LC3:
 2001 001a 4572726F 		.string	"Error BitCount != 24\n"
 2001      72204269 
 2001      74436F75 
 2001      6E742021 
 2001      3D203234 
 2002              	.LC4:
 2003 0030 7700     		.string	"w"
 2004              	.LC5:
 2005 0032 4572726F 		.string	"Error: cannot create %s (%s)\n"
 2005      723A2063 
 2005      616E6E6F 
 2005      74206372 
 2005      65617465 
 2006              	.LC6:
 2007 0050 4572726F 		.string	"Error: getBlock(%d,%d)\n"
 2007      723A2067 
GAS LISTING /tmp/ccJXpt5V.s 			page 44


 2007      6574426C 
 2007      6F636B28 
 2007      25642C25 
 2008              		.text
 2009 18b2 8DB42600 		.p2align 4,,15
 2009      0000008D 
 2009      BC270000 
 2009      0000
 2010              	.globl main
 2011              		.type	main, @function
 2012              	main:
 2013              	.LFB121:
 2014              		.cfi_startproc
 2015              		.cfi_personality 0x0,__gxx_personality_v0
 2016              		.cfi_lsda 0x0,.LLSDA121
 2017 18c0 55       		pushl	%ebp
 2018              		.cfi_def_cfa_offset 8
 2019 18c1 89E5     		movl	%esp, %ebp
 2020              		.cfi_offset 5, -8
 2021              		.cfi_def_cfa_register 5
 2022 18c3 83E4F0   		andl	$-16, %esp
 2023 18c6 57       		pushl	%edi
 2024 18c7 56       		pushl	%esi
 2025 18c8 53       		pushl	%ebx
 2026 18c9 81ECD406 		subl	$1748, %esp
 2026      0000
 2027 18cf E8FCFFFF 		call	mcount
 2027      FF
 2028 18d4 BA0E0000 		movl	$14, %edx
 2028      00
 2029 18d9 89D1     		movl	%edx, %ecx
 2030 18db 8B5D0C   		movl	12(%ebp), %ebx
 2031              		.cfi_escape 0x10,0x3,0x8,0x75,0x0,0x9,0xf0,0x1a,0x9,0xf4,0x22
 2032              		.cfi_escape 0x10,0x6,0x8,0x75,0x0,0x9,0xf0,0x1a,0x9,0xf8,0x22
 2033              		.cfi_escape 0x10,0x7,0x8,0x75,0x0,0x9,0xf0,0x1a,0x9,0xfc,0x22
 2034 18de 8D842444 		leal	1348(%esp), %eax
 2034      050000
 2035 18e5 8944243C 		movl	%eax, 60(%esp)
 2036 18e9 8B7C243C 		movl	60(%esp), %edi
 2037 18ed 31C0     		xorl	%eax, %eax
 2038 18ef 837D0802 		cmpl	$2, 8(%ebp)
 2039 18f3 C78424C4 		movl	$0, 1476(%esp)
 2039      05000000 
 2039      000000
 2040 18fe C78424C0 		movl	$0, 1472(%esp)
 2040      05000000 
 2040      000000
 2041 1909 F3AA     		rep stosb
 2042 190b 8D842452 		leal	1362(%esp), %eax
 2042      050000
 2043 1912 89C7     		movl	%eax, %edi
 2044 1914 89442438 		movl	%eax, 56(%esp)
 2045 1918 C78424C8 		movl	$0, 1480(%esp)
 2045      05000000 
 2045      000000
 2046 1923 C78424CC 		movl	$0, 1484(%esp)
 2046      05000000 
GAS LISTING /tmp/ccJXpt5V.s 			page 45


 2046      000000
 2047 192e 89C8     		movl	%ecx, %eax
 2048 1930 89CA     		movl	%ecx, %edx
 2049 1932 66AB     		stosw
 2050 1934 B11A     		movb	$26, %cl
 2051 1936 89D0     		movl	%edx, %eax
 2052 1938 F3AB     		rep stosl
 2053 193a 66AB     		stosw
 2054 193c 0F8E6C05 		jle	.L332
 2054      0000
 2055 1942 C7442404 		movl	$.LC1, 4(%esp)
 2055      00000000 
 2056 194a 8B4304   		movl	4(%ebx), %eax
 2057 194d 890424   		movl	%eax, (%esp)
 2058              	.LEHB0:
 2059 1950 E8FCFFFF 		call	fopen
 2059      FF
 2060 1955 89C6     		movl	%eax, %esi
 2061 1957 8B8424C0 		movl	1472(%esp), %eax
 2061      050000
 2062 195e 85C0     		testl	%eax, %eax
 2063 1960 7408     		je	.L290
 2064 1962 890424   		movl	%eax, (%esp)
 2065 1965 E8FCFFFF 		call	_ZdaPv
 2065      FF
 2066              	.L290:
 2067 196a 8B7C243C 		movl	60(%esp), %edi
 2068 196e BA0E0000 		movl	$14, %edx
 2068      00
 2069 1973 31C0     		xorl	%eax, %eax
 2070 1975 89D1     		movl	%edx, %ecx
 2071 1977 85F6     		testl	%esi, %esi
 2072 1979 C78424C0 		movl	$0, 1472(%esp)
 2072      05000000 
 2072      000000
 2073 1984 C78424C8 		movl	$0, 1480(%esp)
 2073      05000000 
 2073      000000
 2074 198f F3AA     		rep stosb
 2075 1991 8B7C2438 		movl	56(%esp), %edi
 2076 1995 C78424CC 		movl	$0, 1484(%esp)
 2076      05000000 
 2076      000000
 2077 19a0 89C8     		movl	%ecx, %eax
 2078 19a2 89CA     		movl	%ecx, %edx
 2079 19a4 66AB     		stosw
 2080 19a6 B11A     		movb	$26, %cl
 2081 19a8 89D0     		movl	%edx, %eax
 2082 19aa F3AB     		rep stosl
 2083 19ac 66AB     		stosw
 2084 19ae 742F     		je	.L291
 2085 19b0 8D8C2444 		leal	1348(%esp), %ecx
 2085      050000
 2086 19b7 8974240C 		movl	%esi, 12(%esp)
 2087 19bb C7442408 		movl	$1, 8(%esp)
 2087      01000000 
 2088 19c3 C7442404 		movl	$14, 4(%esp)
GAS LISTING /tmp/ccJXpt5V.s 			page 46


 2088      0E000000 
 2089 19cb 890C24   		movl	%ecx, (%esp)
 2090 19ce E8FCFFFF 		call	fread
 2090      FF
 2091 19d3 6681BC24 		cmpw	$19778, 1348(%esp)
 2091      44050000 
 2091      424D
 2092 19dd 7468     		je	.L333
 2093              	.L291:
 2094 19df 8B4304   		movl	4(%ebx), %eax
 2095 19e2 C7442408 		movl	$.LC2, 8(%esp)
 2095      03000000 
 2096 19ea C7442404 		movl	$1, 4(%esp)
 2096      01000000 
 2097 19f2 8944240C 		movl	%eax, 12(%esp)
 2098 19f6 A1000000 		movl	stderr, %eax
 2098      00
 2099 19fb 890424   		movl	%eax, (%esp)
 2100 19fe E8FCFFFF 		call	__fprintf_chk
 2100      FF
 2101              	.L326:
 2102 1a03 83CBFF   		orl	$-1, %ebx
 2103              	.L289:
 2104 1a06 8B8424C0 		movl	1472(%esp), %eax
 2104      050000
 2105 1a0d 85C0     		testl	%eax, %eax
 2106 1a0f 7408     		je	.L304
 2107 1a11 890424   		movl	%eax, (%esp)
 2108 1a14 E8FCFFFF 		call	_ZdaPv
 2108      FF
 2109              	.L304:
 2110 1a19 8B7C243C 		movl	60(%esp), %edi
 2111 1a1d BA0E0000 		movl	$14, %edx
 2111      00
 2112 1a22 31C0     		xorl	%eax, %eax
 2113 1a24 89D1     		movl	%edx, %ecx
 2114 1a26 F3AA     		rep stosb
 2115 1a28 8B7C2438 		movl	56(%esp), %edi
 2116 1a2c 89C8     		movl	%ecx, %eax
 2117 1a2e 89CA     		movl	%ecx, %edx
 2118 1a30 66AB     		stosw
 2119 1a32 B11A     		movb	$26, %cl
 2120 1a34 89D0     		movl	%edx, %eax
 2121 1a36 F3AB     		rep stosl
 2122 1a38 81C4D406 		addl	$1748, %esp
 2122      0000
 2123 1a3e 89D8     		movl	%ebx, %eax
 2124 1a40 5B       		popl	%ebx
 2125              		.cfi_remember_state
 2126              		.cfi_restore 3
 2127 1a41 5E       		popl	%esi
 2128              		.cfi_restore 6
 2129 1a42 5F       		popl	%edi
 2130              		.cfi_restore 7
 2131 1a43 89EC     		movl	%ebp, %esp
 2132              		.cfi_def_cfa_register 4
 2133 1a45 5D       		popl	%ebp
GAS LISTING /tmp/ccJXpt5V.s 			page 47


 2134              		.cfi_restore 5
 2135              		.cfi_def_cfa_offset 4
 2136 1a46 C3       		ret
 2137              	.L333:
 2138              		.cfi_restore_state
 2139 1a47 8D842452 		leal	1362(%esp), %eax
 2139      050000
 2140 1a4e 8974240C 		movl	%esi, 12(%esp)
 2141 1a52 C7442408 		movl	$1, 8(%esp)
 2141      01000000 
 2142 1a5a C7442404 		movl	$108, 4(%esp)
 2142      6C000000 
 2143 1a62 890424   		movl	%eax, (%esp)
 2144 1a65 E8FCFFFF 		call	fread
 2144      FF
 2145 1a6a 6683BC24 		cmpw	$24, 1376(%esp)
 2145      60050000 
 2145      18
 2146 1a73 0F8566FF 		jne	.L291
 2146      FFFF
 2147 1a79 83BC2462 		cmpl	$0, 1378(%esp)
 2147      05000000 
 2148 1a81 0F8558FF 		jne	.L291
 2148      FFFF
 2149 1a87 8B942456 		movl	1366(%esp), %edx
 2149      050000
 2150 1a8e 8B842456 		movl	1366(%esp), %eax
 2150      050000
 2151 1a95 8B8C245A 		movl	1370(%esp), %ecx
 2151      050000
 2152 1a9c C1FA1F   		sarl	$31, %edx
 2153 1a9f 31D0     		xorl	%edx, %eax
 2154 1aa1 29D0     		subl	%edx, %eax
 2155 1aa3 8B94245A 		movl	1370(%esp), %edx
 2155      050000
 2156 1aaa C1F91F   		sarl	$31, %ecx
 2157 1aad 898424C8 		movl	%eax, 1480(%esp)
 2157      050000
 2158 1ab4 31CA     		xorl	%ecx, %edx
 2159 1ab6 29CA     		subl	%ecx, %edx
 2160 1ab8 0FAFC2   		imull	%edx, %eax
 2161 1abb 899424CC 		movl	%edx, 1484(%esp)
 2161      050000
 2162 1ac2 898424C4 		movl	%eax, 1476(%esp)
 2162      050000
 2163 1ac9 8D0440   		leal	(%eax,%eax,2), %eax
 2164 1acc 890424   		movl	%eax, (%esp)
 2165 1acf E8FCFFFF 		call	_Znaj
 2165      FF
 2166 1ad4 898424C0 		movl	%eax, 1472(%esp)
 2166      050000
 2167 1adb 8B84244E 		movl	1358(%esp), %eax
 2167      050000
 2168 1ae2 C7442408 		movl	$0, 8(%esp)
 2168      00000000 
 2169 1aea 893424   		movl	%esi, (%esp)
 2170 1aed 89442404 		movl	%eax, 4(%esp)
GAS LISTING /tmp/ccJXpt5V.s 			page 48


 2171 1af1 E8FCFFFF 		call	fseek
 2171      FF
 2172 1af6 6B8424C4 		imull	$3, 1476(%esp), %eax
 2172      05000003 
 2173 1afe 8974240C 		movl	%esi, 12(%esp)
 2174 1b02 C7442408 		movl	$1, 8(%esp)
 2174      01000000 
 2175 1b0a 89442404 		movl	%eax, 4(%esp)
 2176 1b0e 8B8424C0 		movl	1472(%esp), %eax
 2176      050000
 2177 1b15 890424   		movl	%eax, (%esp)
 2178 1b18 E8FCFFFF 		call	fread
 2178      FF
 2179 1b1d 893424   		movl	%esi, (%esp)
 2180 1b20 E8FCFFFF 		call	fclose
 2180      FF
 2181 1b25 6683BC24 		cmpw	$24, 1376(%esp)
 2181      60050000 
 2181      18
 2182 1b2e 0F85FD03 		jne	.L334
 2182      0000
 2183 1b34 C7442404 		movl	$.LC4, 4(%esp)
 2183      30000000 
 2184 1b3c 8B4308   		movl	8(%ebx), %eax
 2185 1b3f 890424   		movl	%eax, (%esp)
 2186 1b42 E8FCFFFF 		call	fopen
 2186      FF
 2187 1b47 85C0     		testl	%eax, %eax
 2188 1b49 A3000000 		movl	%eax, _ZL8file_jpg
 2188      00
 2189 1b4e 0F84A103 		je	.L335
 2189      0000
 2190 1b54 8B8424C8 		movl	1480(%esp), %eax
 2190      050000
 2191 1b5b 83E0F0   		andl	$-16, %eax
 2192 1b5e 98       		cwtl
 2193 1b5f 89442404 		movl	%eax, 4(%esp)
 2194 1b63 8B8424CC 		movl	1484(%esp), %eax
 2194      050000
 2195 1b6a 83E0F0   		andl	$-16, %eax
 2196 1b6d 98       		cwtl
 2197 1b6e 890424   		movl	%eax, (%esp)
 2198 1b71 E8FCFFFF 		call	huffman_start
 2198      FF
 2199 1b76 8B8C24CC 		movl	1484(%esp), %ecx
 2199      050000
 2200 1b7d 8DB424D0 		leal	1488(%esp), %esi
 2200      050000
 2201 1b84 C7442428 		movl	$0, 40(%esp)
 2201      00000000 
 2202 1b8c 83F90F   		cmpl	$15, %ecx
 2203 1b8f 89CA     		movl	%ecx, %edx
 2204 1b91 0F84E502 		je	.L295
 2204      0000
 2205              		.p2align 4,,7
 2206 1b97 90       		.p2align 3
 2207              	.L319:
GAS LISTING /tmp/ccJXpt5V.s 			page 49


 2208 1b98 8B8424C8 		movl	1480(%esp), %eax
 2208      050000
 2209 1b9f 83F80F   		cmpl	$15, %eax
 2210 1ba2 0F843B03 		je	.L336
 2210      0000
 2211 1ba8 8B5C2428 		movl	40(%esp), %ebx
 2212 1bac 83C310   		addl	$16, %ebx
 2213 1baf 39CB     		cmpl	%ecx, %ebx
 2214 1bb1 895C2430 		movl	%ebx, 48(%esp)
 2215 1bb5 0F871B03 		ja	.L316
 2215      0000
 2216 1bbb 83F80F   		cmpl	$15, %eax
 2217 1bbe 0F861203 		jbe	.L316
 2217      0000
 2218 1bc4 8B4C2428 		movl	40(%esp), %ecx
 2219 1bc8 C7442434 		movl	$0, 52(%esp)
 2219      00000000 
 2220 1bd0 F7D1     		notl	%ecx
 2221 1bd2 894C242C 		movl	%ecx, 44(%esp)
 2222              		.p2align 4,,7
 2223 1bd6 6690     		.p2align 3
 2224              	.L297:
 2225 1bd8 0354242C 		addl	44(%esp), %edx
 2226 1bdc B9100000 		movl	$16, %ecx
 2226      00
 2227 1be1 8D3C40   		leal	(%eax,%eax,2), %edi
 2228 1be4 F7DF     		negl	%edi
 2229 1be6 0FAFD0   		imull	%eax, %edx
 2230 1be9 03542434 		addl	52(%esp), %edx
 2231 1bed 8D0452   		leal	(%edx,%edx,2), %eax
 2232 1bf0 038424C0 		addl	1472(%esp), %eax
 2232      050000
 2233 1bf7 8D542444 		leal	68(%esp), %edx
 2234 1bfb 908D7426 		.p2align 4,,7
 2234      00
 2235              		.p2align 3
 2236              	.L298:
 2237 1c00 0FB718   		movzwl	(%eax), %ebx
 2238 1c03 66891A   		movw	%bx, (%edx)
 2239 1c06 0FB65802 		movzbl	2(%eax), %ebx
 2240 1c0a 885A02   		movb	%bl, 2(%edx)
 2241 1c0d 0FB75803 		movzwl	3(%eax), %ebx
 2242 1c11 66895A03 		movw	%bx, 3(%edx)
 2243 1c15 0FB65805 		movzbl	5(%eax), %ebx
 2244 1c19 885A05   		movb	%bl, 5(%edx)
 2245 1c1c 0FB75806 		movzwl	6(%eax), %ebx
 2246 1c20 66895A06 		movw	%bx, 6(%edx)
 2247 1c24 0FB65808 		movzbl	8(%eax), %ebx
 2248 1c28 885A08   		movb	%bl, 8(%edx)
 2249 1c2b 0FB75809 		movzwl	9(%eax), %ebx
 2250 1c2f 66895A09 		movw	%bx, 9(%edx)
 2251 1c33 0FB6580B 		movzbl	11(%eax), %ebx
 2252 1c37 885A0B   		movb	%bl, 11(%edx)
 2253 1c3a 0FB7580C 		movzwl	12(%eax), %ebx
 2254 1c3e 66895A0C 		movw	%bx, 12(%edx)
 2255 1c42 0FB6580E 		movzbl	14(%eax), %ebx
 2256 1c46 885A0E   		movb	%bl, 14(%edx)
GAS LISTING /tmp/ccJXpt5V.s 			page 50


 2257 1c49 0FB7580F 		movzwl	15(%eax), %ebx
 2258 1c4d 66895A0F 		movw	%bx, 15(%edx)
 2259 1c51 0FB65811 		movzbl	17(%eax), %ebx
 2260 1c55 885A11   		movb	%bl, 17(%edx)
 2261 1c58 0FB75812 		movzwl	18(%eax), %ebx
 2262 1c5c 66895A12 		movw	%bx, 18(%edx)
 2263 1c60 0FB65814 		movzbl	20(%eax), %ebx
 2264 1c64 885A14   		movb	%bl, 20(%edx)
 2265 1c67 0FB75815 		movzwl	21(%eax), %ebx
 2266 1c6b 66895A15 		movw	%bx, 21(%edx)
 2267 1c6f 0FB65817 		movzbl	23(%eax), %ebx
 2268 1c73 885A17   		movb	%bl, 23(%edx)
 2269 1c76 0FB75818 		movzwl	24(%eax), %ebx
 2270 1c7a 66895A18 		movw	%bx, 24(%edx)
 2271 1c7e 0FB6581A 		movzbl	26(%eax), %ebx
 2272 1c82 885A1A   		movb	%bl, 26(%edx)
 2273 1c85 0FB7581B 		movzwl	27(%eax), %ebx
 2274 1c89 66895A1B 		movw	%bx, 27(%edx)
 2275 1c8d 0FB6581D 		movzbl	29(%eax), %ebx
 2276 1c91 885A1D   		movb	%bl, 29(%edx)
 2277 1c94 0FB7581E 		movzwl	30(%eax), %ebx
 2278 1c98 66895A1E 		movw	%bx, 30(%edx)
 2279 1c9c 0FB65820 		movzbl	32(%eax), %ebx
 2280 1ca0 885A20   		movb	%bl, 32(%edx)
 2281 1ca3 0FB75821 		movzwl	33(%eax), %ebx
 2282 1ca7 66895A21 		movw	%bx, 33(%edx)
 2283 1cab 0FB65823 		movzbl	35(%eax), %ebx
 2284 1caf 885A23   		movb	%bl, 35(%edx)
 2285 1cb2 0FB75824 		movzwl	36(%eax), %ebx
 2286 1cb6 66895A24 		movw	%bx, 36(%edx)
 2287 1cba 0FB65826 		movzbl	38(%eax), %ebx
 2288 1cbe 885A26   		movb	%bl, 38(%edx)
 2289 1cc1 0FB75827 		movzwl	39(%eax), %ebx
 2290 1cc5 66895A27 		movw	%bx, 39(%edx)
 2291 1cc9 0FB65829 		movzbl	41(%eax), %ebx
 2292 1ccd 885A29   		movb	%bl, 41(%edx)
 2293 1cd0 0FB7582A 		movzwl	42(%eax), %ebx
 2294 1cd4 66895A2A 		movw	%bx, 42(%edx)
 2295 1cd8 0FB6582C 		movzbl	44(%eax), %ebx
 2296 1cdc 885A2C   		movb	%bl, 44(%edx)
 2297 1cdf 0FB7582D 		movzwl	45(%eax), %ebx
 2298 1ce3 66895A2D 		movw	%bx, 45(%edx)
 2299 1ce7 0FB6582F 		movzbl	47(%eax), %ebx
 2300 1ceb 01F8     		addl	%edi, %eax
 2301 1ced 885A2F   		movb	%bl, 47(%edx)
 2302 1cf0 83C230   		addl	$48, %edx
 2303 1cf3 83E901   		subl	$1, %ecx
 2304 1cf6 0F8504FF 		jne	.L298
 2304      FFFF
 2305 1cfc 8D9C2450 		leal	1616(%esp), %ebx
 2305      060000
 2306 1d03 895C2408 		movl	%ebx, 8(%esp)
 2307 1d07 8D842444 		leal	836(%esp), %eax
 2307      030000
 2308 1d0e 8D4C2444 		leal	68(%esp), %ecx
 2309 1d12 8D9C2444 		leal	836(%esp), %ebx
 2309      030000
GAS LISTING /tmp/ccJXpt5V.s 			page 51


 2310 1d19 8974240C 		movl	%esi, 12(%esp)
 2311 1d1d 89442404 		movl	%eax, 4(%esp)
 2312 1d21 890C24   		movl	%ecx, (%esp)
 2313 1d24 E8FCFFFF 		call	_Z10subsample2PA16_K3BGRPA2_A8_A8_sPS3_S7_
 2313      FF
 2314 1d29 895C2404 		movl	%ebx, 4(%esp)
 2315 1d2d 891C24   		movl	%ebx, (%esp)
 2316 1d30 E8FCFFFF 		call	dct8x8
 2316      FF
 2317 1d35 8D8424C4 		leal	964(%esp), %eax
 2317      030000
 2318 1d3c 89442404 		movl	%eax, 4(%esp)
 2319 1d40 890424   		movl	%eax, (%esp)
 2320 1d43 E8FCFFFF 		call	dct8x8
 2320      FF
 2321 1d48 8D8C2444 		leal	1092(%esp), %ecx
 2321      040000
 2322 1d4f 894C2404 		movl	%ecx, 4(%esp)
 2323 1d53 890C24   		movl	%ecx, (%esp)
 2324 1d56 E8FCFFFF 		call	dct8x8
 2324      FF
 2325 1d5b 8D9C24C4 		leal	1220(%esp), %ebx
 2325      040000
 2326 1d62 895C2404 		movl	%ebx, 4(%esp)
 2327 1d66 891C24   		movl	%ebx, (%esp)
 2328 1d69 E8FCFFFF 		call	dct8x8
 2328      FF
 2329 1d6e 8D842450 		leal	1616(%esp), %eax
 2329      060000
 2330 1d75 89442404 		movl	%eax, 4(%esp)
 2331 1d79 890424   		movl	%eax, (%esp)
 2332 1d7c E8FCFFFF 		call	dct8x8
 2332      FF
 2333 1d81 89742404 		movl	%esi, 4(%esp)
 2334 1d85 893424   		movl	%esi, (%esp)
 2335 1d88 E8FCFFFF 		call	dct8x8
 2335      FF
 2336 1d8d 8D8C2444 		leal	836(%esp), %ecx
 2336      030000
 2337 1d94 894C2404 		movl	%ecx, 4(%esp)
 2338 1d98 C7042400 		movl	$huffman_ctx, (%esp)
 2338      000000
 2339 1d9f E8FCFFFF 		call	huffman_encode
 2339      FF
 2340 1da4 8D8424C4 		leal	964(%esp), %eax
 2340      030000
 2341 1dab 89442404 		movl	%eax, 4(%esp)
 2342 1daf C7042400 		movl	$huffman_ctx, (%esp)
 2342      000000
 2343 1db6 E8FCFFFF 		call	huffman_encode
 2343      FF
 2344 1dbb 8D8C2444 		leal	1092(%esp), %ecx
 2344      040000
 2345 1dc2 894C2404 		movl	%ecx, 4(%esp)
 2346 1dc6 C7042400 		movl	$huffman_ctx, (%esp)
 2346      000000
 2347 1dcd E8FCFFFF 		call	huffman_encode
GAS LISTING /tmp/ccJXpt5V.s 			page 52


 2347      FF
 2348 1dd2 895C2404 		movl	%ebx, 4(%esp)
 2349 1dd6 C7042400 		movl	$huffman_ctx, (%esp)
 2349      000000
 2350 1ddd E8FCFFFF 		call	huffman_encode
 2350      FF
 2351 1de2 8D9C2450 		leal	1616(%esp), %ebx
 2351      060000
 2352 1de9 895C2404 		movl	%ebx, 4(%esp)
 2353 1ded C7042418 		movl	$huffman_ctx+24, (%esp)
 2353      000000
 2354 1df4 E8FCFFFF 		call	huffman_encode
 2354      FF
 2355 1df9 89742404 		movl	%esi, 4(%esp)
 2356 1dfd C7042430 		movl	$huffman_ctx+48, (%esp)
 2356      000000
 2357 1e04 E8FCFFFF 		call	huffman_encode
 2357      FF
 2358 1e09 8B8424C8 		movl	1480(%esp), %eax
 2358      050000
 2359 1e10 83442434 		addl	$16, 52(%esp)
 2359      10
 2360 1e15 8D50F1   		leal	-15(%eax), %edx
 2361 1e18 3B542434 		cmpl	52(%esp), %edx
 2362 1e1c 7640     		jbe	.L331
 2363 1e1e 8B9424CC 		movl	1484(%esp), %edx
 2363      050000
 2364 1e25 3B542430 		cmpl	48(%esp), %edx
 2365 1e29 720F     		jb	.L296
 2366 1e2b 8B4C2434 		movl	52(%esp), %ecx
 2367 1e2f 83C110   		addl	$16, %ecx
 2368 1e32 39C8     		cmpl	%ecx, %eax
 2369 1e34 0F839EFD 		jae	.L297
 2369      FFFF
 2370              	.L296:
 2371 1e3a 8B4C2428 		movl	40(%esp), %ecx
 2372 1e3e 8B5C2434 		movl	52(%esp), %ebx
 2373 1e42 C7442404 		movl	$.LC6, 4(%esp)
 2373      50000000 
 2374 1e4a C7042401 		movl	$1, (%esp)
 2374      000000
 2375 1e51 894C240C 		movl	%ecx, 12(%esp)
 2376 1e55 895C2408 		movl	%ebx, 8(%esp)
 2377 1e59 E8FCFFFF 		call	__printf_chk
 2377      FF
 2378              	.L331:
 2379 1e5e 8B8C24CC 		movl	1484(%esp), %ecx
 2379      050000
 2380 1e65 8B442430 		movl	48(%esp), %eax
 2381              	.L300:
 2382 1e69 89442428 		movl	%eax, 40(%esp)
 2383 1e6d 8D41F1   		leal	-15(%ecx), %eax
 2384 1e70 89CA     		movl	%ecx, %edx
 2385 1e72 3B442428 		cmpl	40(%esp), %eax
 2386 1e76 0F871CFD 		ja	.L319
 2386      FFFF
 2387              	.L295:
GAS LISTING /tmp/ccJXpt5V.s 			page 53


 2388 1e7c E8FCFFFF 		call	huffman_stop
 2388      FF
 2389 1e81 A1000000 		movl	_ZL8file_jpg, %eax
 2389      00
 2390 1e86 890424   		movl	%eax, (%esp)
 2391 1e89 E8FCFFFF 		call	fclose
 2391      FF
 2392              	.LEHE0:
 2393 1e8e 31DB     		xorl	%ebx, %ebx
 2394 1e90 E971FBFF 		jmp	.L289
 2394      FF
 2395              	.L317:
 2396 1e95 89C3     		movl	%eax, %ebx
 2397 1e97 8D8C2444 		leal	1348(%esp), %ecx
 2397      050000
 2398 1e9e 890C24   		movl	%ecx, (%esp)
 2399 1ea1 E8FCFFFF 		call	_ZN7CBitmap7DisposeEv
 2399      FF
 2400 1ea6 891C24   		movl	%ebx, (%esp)
 2401              	.LEHB1:
 2402 1ea9 E8FCFFFF 		call	_Unwind_Resume
 2402      FF
 2403              	.LEHE1:
 2404              	.L332:
 2405 1eae 8B03     		movl	(%ebx), %eax
 2406 1eb0 C7442408 		movl	$.LC0, 8(%esp)
 2406      00000000 
 2407 1eb8 C7442404 		movl	$1, 4(%esp)
 2407      01000000 
 2408 1ec0 8944240C 		movl	%eax, 12(%esp)
 2409 1ec4 A1000000 		movl	stderr, %eax
 2409      00
 2410 1ec9 890424   		movl	%eax, (%esp)
 2411              	.LEHB2:
 2412 1ecc E8FCFFFF 		call	__fprintf_chk
 2412      FF
 2413 1ed1 E92DFBFF 		jmp	.L326
 2413      FF
 2414              	.L316:
 2415 1ed6 C7442434 		movl	$0, 52(%esp)
 2415      00000000 
 2416 1ede E957FFFF 		jmp	.L296
 2416      FF
 2417              	.L336:
 2418 1ee3 8B5C2428 		movl	40(%esp), %ebx
 2419 1ee7 83C310   		addl	$16, %ebx
 2420 1eea 895C2430 		movl	%ebx, 48(%esp)
 2421 1eee 89D8     		movl	%ebx, %eax
 2422 1ef0 E974FFFF 		jmp	.L300
 2422      FF
 2423              	.L335:
 2424 1ef5 E8FCFFFF 		call	__errno_location
 2424      FF
 2425 1efa 8B00     		movl	(%eax), %eax
 2426 1efc 890424   		movl	%eax, (%esp)
 2427 1eff E8FCFFFF 		call	strerror
 2427      FF
GAS LISTING /tmp/ccJXpt5V.s 			page 54


 2428 1f04 89442410 		movl	%eax, 16(%esp)
 2429 1f08 8B4308   		movl	8(%ebx), %eax
 2430 1f0b C7442408 		movl	$.LC5, 8(%esp)
 2430      32000000 
 2431 1f13 C7442404 		movl	$1, 4(%esp)
 2431      01000000 
 2432 1f1b 8944240C 		movl	%eax, 12(%esp)
 2433 1f1f A1000000 		movl	stderr, %eax
 2433      00
 2434 1f24 890424   		movl	%eax, (%esp)
 2435 1f27 E8FCFFFF 		call	__fprintf_chk
 2435      FF
 2436 1f2c E9D2FAFF 		jmp	.L326
 2436      FF
 2437              	.L334:
 2438 1f31 A1000000 		movl	stderr, %eax
 2438      00
 2439 1f36 C7442408 		movl	$21, 8(%esp)
 2439      15000000 
 2440 1f3e C7442404 		movl	$1, 4(%esp)
 2440      01000000 
 2441 1f46 C704241A 		movl	$.LC3, (%esp)
 2441      000000
 2442 1f4d 8944240C 		movl	%eax, 12(%esp)
 2443 1f51 E8FCFFFF 		call	fwrite
 2443      FF
 2444              	.LEHE2:
 2445 1f56 E9A8FAFF 		jmp	.L326
 2445      FF
 2446              		.cfi_endproc
 2447              	.LFE121:
 2448              		.size	main, .-main
 2449              	.globl __gxx_personality_v0
 2450              		.section	.gcc_except_table,"a",@progbits
 2451              	.LLSDA121:
 2452 0000 FF       		.byte	0xff
 2453 0001 FF       		.byte	0xff
 2454 0002 01       		.byte	0x1
 2455 0003 13       		.uleb128 .LLSDACSE121-.LLSDACSB121
 2456              	.LLSDACSB121:
 2457 0004 9001     		.uleb128 .LEHB0-.LFB121
 2458 0006 BE0A     		.uleb128 .LEHE0-.LEHB0
 2459 0008 D50B     		.uleb128 .L317-.LFB121
 2460 000a 00       		.uleb128 0x0
 2461 000b E90B     		.uleb128 .LEHB1-.LFB121
 2462 000d 05       		.uleb128 .LEHE1-.LEHB1
 2463 000e 00       		.uleb128 0x0
 2464 000f 00       		.uleb128 0x0
 2465 0010 8C0C     		.uleb128 .LEHB2-.LFB121
 2466 0012 8A01     		.uleb128 .LEHE2-.LEHB2
 2467 0014 D50B     		.uleb128 .L317-.LFB121
 2468 0016 00       		.uleb128 0x0
 2469              	.LLSDACSE121:
 2470              		.text
 2471              		.local	_ZL8file_jpg
 2472              		.comm	_ZL8file_jpg,4,4
 2473              		.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
GAS LISTING /tmp/ccJXpt5V.s 			page 55


 2474              		.section	.note.GNU-stack,"",@progbits
GAS LISTING /tmp/ccJXpt5V.s 			page 56


DEFINED SYMBOLS
                            *ABS*:0000000000000000 main.cpp
     /tmp/ccJXpt5V.s:7      .text._ZN7CBitmap7DisposeEv:0000000000000000 _ZN7CBitmap7DisposeEv
     /tmp/ccJXpt5V.s:73     .text:0000000000000000 correct_color
     /tmp/ccJXpt5V.s:1013   .text:0000000000000c70 write_jpeg
     /tmp/ccJXpt5V.s:2472   .bss:0000000000000000 _ZL8file_jpg
     /tmp/ccJXpt5V.s:1041   .text:0000000000000ca0 _Z9subsamplePA16_K3BGRPA8_sS4_
     /tmp/ccJXpt5V.s:1541   .text:0000000000001340 _Z10subsample2PA16_K3BGRPA2_A8_A8_sPS3_S7_
     /tmp/ccJXpt5V.s:1763   .text:00000000000015f0 _Z10subsample3PA16_KhS1_S1_PA2_A8_A8_sPS2_S6_
     /tmp/ccJXpt5V.s:2012   .text:00000000000018c0 main

UNDEFINED SYMBOLS
mcount
_ZdaPv
fwrite
__gxx_personality_v0
fopen
fread
stderr
__fprintf_chk
_Znaj
fseek
fclose
huffman_start
dct8x8
huffman_ctx
huffman_encode
__printf_chk
huffman_stop
_Unwind_Resume
__errno_location
strerror
