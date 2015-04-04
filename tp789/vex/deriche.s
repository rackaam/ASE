 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/matthias/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./vliw4.mm -DVEX -o edge_detect"
.sversion 3.43
.rta 2
.section .bss
.align 32
.section .data
.align 32
 ## Begin deriche_float
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-192, arg($r0.3:s32,$r0.4:s32)
deriche_float::
.trace 27
	c0    add $r0.1 = $r0.1, (-0xc0)
	c0    sub $r0.7 = $r0.0, $r0.3   ## bblock 0, line 0,  t559,  0(I32),  t222
;;								## 0
	c0    mov $r0.2 = $r0.7   ## bblock 0, line 0,  t558,  t559
	c0    mov $r0.6 = (in + 0)   ## bblock 0, line 0,  t555,  addr(in?1.0)(P32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t209
;;								## 1
	c0    mov $r0.5 = (y1 + 0)   ## bblock 0, line 0,  t557,  addr(y1?1.0)(P32)
	c0    stw 0x8c[$r0.1] = $r0.57  ## spill ## t213
;;								## 2
	c0    stw 0x90[$r0.1] = $r0.58  ## spill ## t214
;;								## 3
	c0    stw 0x94[$r0.1] = $r0.59  ## spill ## t215
;;								## 4
	c0    stw 0x98[$r0.1] = $r0.60  ## spill ## t216
;;								## 5
	c0    stw 0x9c[$r0.1] = $r0.61  ## spill ## t217
;;								## 6
	c0    stw 0xa0[$r0.1] = $r0.62  ## spill ## t218
;;								## 7
	c0    stw 0xa4[$r0.1] = $r0.63  ## spill ## t219
;;								## 8
	c0    stw 0x80[$r0.1] = $r0.3  ## spill ## t222
;;								## 9
	c0    mov $r0.3 = $r0.4   ## t223
;;								## 10
.trace 14
L0?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 1, line 38,  t579(I1),  t558,  0(SI32)
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 36, line 0,  t315,  0(I32),  t223
	c0    mov $r0.62 = $r0.5   ## [spec] bblock 36, line 0,  t313,  t557
	c0    stw 0x60[$r0.1] = $r0.3  ## spill ## t223
;;								## 0
	c0    mov $r0.60 = $r0.0   ## [spec] bblock 36, line 39,  t246,  0.000000e+00=0x0(F32)
	c0    mov $r0.57 = $r0.4   ## [spec] bblock 36, line 0,  t314,  t315
	c0    mov $r0.61 = $r0.6   ## [spec] bblock 36, line 0,  t312,  t555
	c0    stw 0x64[$r0.1] = $r0.5  ## spill ## t557
;;								## 1
	c0    mov $r0.59 = $r0.0   ## [spec] bblock 36, line 39,  t244,  0.000000e+00=0x0(F32)
	c0    mov $r0.58 = $r0.0   ## [spec] bblock 36, line 39,  t243,  0.000000e+00=0x0(F32)
	c0    stw 0x68[$r0.1] = $r0.6  ## spill ## t555
	c0    brf $b0.0, L1?3   ## bblock 1, line 38,  t579(I1)
;;								## 2
	c0    mov $r0.63 = $r0.2   ## t558
;;								## 3
.trace 3
L2?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 37, line 40,  t603(I1),  t314,  0(SI32)
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
	c0    mov $r0.3 = $r0.58   ## t243
	      xnop 1
;;								## 1
	c0    brf $b0.0, L3?3   ## bblock 37, line 40,  t603(I1)
;;								## 2
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 41,  raddr(_r_mul)(P32),  t243,  -6.065310e-01=0xbf1b459e(F32)
;;								## 3
	c0    mov $r0.58 = $r0.59   ## bblock 39, line 41,  t243,  t244
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
	c0    stw 0x28[$r0.1] = $r0.3  ## spill ## t10
;;								## 4
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 41,  raddr(_r_mul)(P32),  t244,  8.408960e-01=0x3f5744f6(F32)
	c0    mov $r0.3 = $r0.59   ## t244
;;								## 5
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
	c0    stw 0x2c[$r0.1] = $r0.3  ## spill ## t13
;;								## 6
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 41,  raddr(_r_mul)(P32),  t246,  1.102090e-01=0x3de1b542(F32)
	c0    mov $r0.3 = $r0.60   ## t246
;;								## 7
	c0    stw 0x30[$r0.1] = $r0.3  ## spill ## t16
;;								## 8
	c0    ldbu $r0.59 = 0[$r0.61]   ## bblock 39, line 41, t31(I8), t312
	      xnop 2
;;								## 11
.call _r_ilfloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ilfloat   ## bblock 39, line 41,  raddr(_r_ilfloat)(P32),  t31(I8)
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 41,  raddr(_r_mul)(P32),  t21,  -1.886820e-01=0xbe4135db(F32)
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
;;								## 13
	c0    stw 0x34[$r0.1] = $r0.3  ## spill ## t23
;;								## 14
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t10
;;								## 15
	c0    ldw $r0.4 = 0x2c[$r0.1]  ## restore ## t13
	      xnop 1
;;								## 17
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 41,  raddr(_r_add)(P32),  t10,  t13
;;								## 18
	c0    ldw $r0.4 = 0x30[$r0.1]  ## restore ## t16
	      xnop 1
;;								## 20
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 41,  raddr(_r_add)(P32),  t207,  t16
;;								## 21
	c0    ldw $r0.4 = 0x34[$r0.1]  ## restore ## t23
	      xnop 1
;;								## 23
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 41,  raddr(_r_add)(P32),  t208,  t23
;;								## 24
	c0    stw 0x38[$r0.1] = $r0.3  ## spill ## t244
;;								## 25
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    stw 0[$r0.62] = $r0.3   ## bblock 39, line 41, t313, t244
	c0    call $l0.0 = _r_ufloat   ## bblock 39, line 42,  raddr(_r_ufloat)(P32),  t31(I8)
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 26
	c0    add $r0.57 = $r0.57, 1   ## bblock 39, line 0,  t314,  t314,  1(I32)
	c0    add $r0.62 = $r0.62, 4   ## bblock 39, line 0,  t313,  t313,  4(I32)
	c0    add $r0.61 = $r0.61, 1   ## bblock 39, line 0,  t312,  t312,  1(I32)
	c0    ldw $r0.59 = 0x38[$r0.1]  ## restore ## t244
;;								## 27
	c0    mov $r0.60 = $r0.3   ## t246
;;								## 28
	c0    goto L2?3 ## goto
;;								## 29
.trace 20
L3?3:
	c0    add $r0.2 = $r0.63, 1   ## bblock 38, line 0,  t558,  t558,  1(I32)
	c0    ldw $r0.6 = 0x68[$r0.1]  ## restore ## t555
;;								## 0
	c0    ldw $r0.5 = 0x64[$r0.1]  ## restore ## t557
;;								## 1
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t223
;;								## 2
	c0    add $r0.6 = $r0.6, 1050   ## bblock 38, line 0,  t555,  t555,  1050(I32)
;;								## 3
	c0    add $r0.5 = $r0.5, 4200   ## bblock 38, line 0,  t557,  t557,  4200(I32)
	c0    goto L0?3 ## goto
;;								## 4
.trace 26
L1?3:
	c0    mov $r0.6 = (y2 + 0)   ## bblock 2, line 0,  t531,  addr(y2?1.0)(P32)
	c0    ldw $r0.3 = 0x80[$r0.1]  ## restore ## t222
;;								## 0
	c0    mov $r0.4 = (in + 0)   ## bblock 2, line 0,  t532,  addr(in?1.0)(P32)
	c0    ldw $r0.7 = 0x60[$r0.1]  ## restore ## t223
	      xnop 1
;;								## 2
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 2, line 0,  t534,  0(I32),  t222
;;								## 3
	c0    add $r0.5 = $r0.7, -1   ## bblock 2, line 56,  t309,  t223,  -1(SI32)
	c0    mov $r0.2 = $r0.3   ## bblock 2, line 0,  t533,  t534
;;								## 4
.trace 15
L4?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 3, line 54,  t580(I1),  t533,  0(SI32)
	c0    add $r0.62 = $r0.4, $r0.5   ## [spec] bblock 32, line 0,  t335,  t532,  t309
	c0    sh2add $r0.63 = $r0.5, $r0.6   ## [spec] bblock 32, line 0,  t334,  t309,  t531
	c0    stw 0x6c[$r0.1] = $r0.2  ## spill ## t533
;;								## 0
	c0    mov $r0.59 = $r0.0   ## [spec] bblock 32, line 55,  t238,  0.000000e+00=0x0(F32)
	c0    mov $r0.61 = $r0.0   ## [spec] bblock 32, line 55,  t242,  0.000000e+00=0x0(F32)
	c0    mov $r0.60 = $r0.0   ## [spec] bblock 32, line 55,  t241,  0.000000e+00=0x0(F32)
	c0    stw 0x70[$r0.1] = $r0.4  ## spill ## t532
;;								## 1
	c0    mov $r0.58 = $r0.0   ## [spec] bblock 32, line 55,  t237,  0.000000e+00=0x0(F32)
	c0    mov $r0.57 = $r0.5   ## [spec] bblock 32, line 56,  t297,  t309
	c0    stw 0x74[$r0.1] = $r0.5  ## spill ## t309
	c0    brf $b0.0, L5?3   ## bblock 3, line 54,  t580(I1)
;;								## 2
	c0    stw 0x78[$r0.1] = $r0.6  ## spill ## t531
;;								## 3
.trace 2
L6?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 33, line 56,  t602(I1),  t297,  0(SI32)
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
	c0    mov $r0.3 = $r0.58   ## t237
	      xnop 1
;;								## 1
	c0    brf $b0.0, L7?3   ## bblock 33, line 56,  t602(I1)
;;								## 2
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 57,  raddr(_r_mul)(P32),  t237,  -6.065310e-01=0xbf1b459e(F32)
;;								## 3
	c0    mov $r0.58 = $r0.59   ## bblock 35, line 57,  t237,  t238
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
	c0    stw 0x14[$r0.1] = $r0.3  ## spill ## t49
;;								## 4
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 57,  raddr(_r_mul)(P32),  t238,  8.408960e-01=0x3f5744f6(F32)
	c0    mov $r0.3 = $r0.59   ## t238
;;								## 5
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
	c0    stw 0x18[$r0.1] = $r0.3  ## spill ## t52
;;								## 6
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 57,  raddr(_r_mul)(P32),  t241,  -1.886820e-01=0xbe4135db(F32)
	c0    mov $r0.3 = $r0.60   ## t241
;;								## 7
	c0    mov $r0.60 = $r0.61   ## bblock 35, line 57,  t241,  t242
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
	c0    stw 0x1c[$r0.1] = $r0.3  ## spill ## t55
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 57,  raddr(_r_mul)(P32),  t242,  -1.836820e-01=0xbe3c1722(F32)
	c0    mov $r0.3 = $r0.61   ## t242
;;								## 9
	c0    stw 0x20[$r0.1] = $r0.3  ## spill ## t58
;;								## 10
	c0    ldw $r0.3 = 0x14[$r0.1]  ## restore ## t49
;;								## 11
	c0    ldw $r0.4 = 0x18[$r0.1]  ## restore ## t52
	      xnop 1
;;								## 13
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 57,  raddr(_r_add)(P32),  t49,  t52
;;								## 14
	c0    ldw $r0.4 = 0x1c[$r0.1]  ## restore ## t55
	      xnop 1
;;								## 16
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 57,  raddr(_r_add)(P32),  t205,  t55
;;								## 17
	c0    ldw $r0.4 = 0x20[$r0.1]  ## restore ## t58
	      xnop 1
;;								## 19
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 57,  raddr(_r_add)(P32),  t206,  t58
;;								## 20
	c0    stw 0x24[$r0.1] = $r0.3  ## spill ## t238
;;								## 21
	c0    ldbu $r0.2 = 0[$r0.62]   ## bblock 35, line 59, t67(I8), t335
;;								## 22
	c0    stw 0[$r0.63] = $r0.3   ## bblock 35, line 57, t334, t238
	      xnop 1
;;								## 24
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ufloat   ## bblock 35, line 59,  raddr(_r_ufloat)(P32),  t67(I8)
	c0    mov $r0.3 = $r0.2   ## t67(I8)
;;								## 25
	c0    add $r0.63 = $r0.63, (~0x3)   ## bblock 35, line 0,  t334,  t334,  (~0x3)(I32)
	c0    add $r0.62 = $r0.62, (~0x0)   ## bblock 35, line 0,  t335,  t335,  (~0x0)(I32)
	c0    add $r0.57 = $r0.57, -1   ## bblock 35, line 56,  t297,  t297,  -1(SI32)
	c0    ldw $r0.59 = 0x24[$r0.1]  ## restore ## t238
;;								## 26
	c0    mov $r0.61 = $r0.3   ## t242
;;								## 27
	c0    goto L6?3 ## goto
;;								## 28
.trace 21
L7?3:
	c0    ldw $r0.6 = 0x78[$r0.1]  ## restore ## t531
;;								## 0
	c0    ldw $r0.4 = 0x70[$r0.1]  ## restore ## t532
;;								## 1
	c0    ldw $r0.2 = 0x6c[$r0.1]  ## restore ## t533
;;								## 2
	c0    add $r0.6 = $r0.6, 4200   ## bblock 34, line 0,  t531,  t531,  4200(I32)
	c0    ldw $r0.5 = 0x74[$r0.1]  ## restore ## t309
;;								## 3
	c0    add $r0.4 = $r0.4, 1050   ## bblock 34, line 0,  t532,  t532,  1050(I32)
;;								## 4
	c0    add $r0.2 = $r0.2, 1   ## bblock 34, line 0,  t533,  t533,  1(I32)
	c0    goto L4?3 ## goto
;;								## 5
.trace 29
L5?3:
	c0    mov $r0.61 = (t + 0)   ## bblock 4, line 0,  t500,  addr(t?1.0)(P32)
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
;;								## 0
	c0    mov $r0.58 = (y2 + 0)   ## bblock 4, line 0,  t502,  addr(y2?1.0)(P32)
	c0    mov $r0.59 = (y1 + 0)   ## bblock 4, line 0,  t501,  addr(y1?1.0)(P32)
;;								## 1
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t223
;;								## 2
	c0    sub $r0.4 = $r0.0, $r0.4   ## bblock 4, line 0,  t504,  0(I32),  t222
;;								## 3
	c0    mov $r0.2 = $r0.4   ## bblock 4, line 0,  t503,  t504
;;								## 4
.trace 16
L8?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 5, line 71,  t581(I1),  t503,  0(SI32)
	c0    mov $r0.57 = $r0.0   ## [spec] bblock 28, line 72,  t299,  0(SI32)
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 28, line 0,  t358,  0(I32),  t223
	c0    mov $r0.62 = $r0.2   ## t503
;;								## 0
	c0    mov $r0.60 = $r0.4   ## [spec] bblock 28, line 0,  t357,  t358
	c0    mov $r0.63 = $r0.3   ## t223
;;								## 1
	c0    brf $b0.0, L9?3   ## bblock 5, line 71,  t581(I1)
;;								## 2
.trace 1
L10?3:
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 29, line 72,  t598(I1),  t357,  0(SI32)
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 31, line 73,  t599,  t299,  t502
	c0    sh2add $r0.5 = $r0.57, $r0.59   ## [spec] bblock 31, line 73,  t600,  t299,  t501
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 31, line 73, t85, t599
;;								## 1
	c0    ldw.d $r0.4 = 0[$r0.5]   ## [spec] bblock 31, line 73, t89, t600
	c0    brf $b0.0, L11?3   ## bblock 29, line 72,  t598(I1)
;;								## 2
;;								## 3
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 31, line 73,  raddr(_r_add)(P32),  t85,  t89
;;								## 4
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 31, line 73,  raddr(_r_mul)(P32),  t90,  1.000000e+00=0x3f800000(F32)
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 5
	c0    sh2add $r0.2 = $r0.57, $r0.61   ## bblock 31, line 73,  t601,  t299,  t500
	c0    add $r0.60 = $r0.60, 1   ## bblock 31, line 0,  t357,  t357,  1(I32)
	c0    add $r0.57 = $r0.57, 1   ## bblock 31, line 72,  t299,  t299,  1(SI32)
;;								## 6
	c0    stw 0[$r0.2] = $r0.3   ## bblock 31, line 73, t601, t92
	c0    goto L10?3 ## goto
;;								## 7
.trace 22
L11?3:
	c0    add $r0.2 = $r0.62, 1   ## bblock 30, line 0,  t503,  t503,  1(I32)
	c0    mov $r0.5 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.58 = $r0.58, $r0.5   ## bblock 30, line 0,  t502,  t502,  4200(I32)
	c0    add $r0.59 = $r0.59, $r0.5   ## bblock 30, line 0,  t501,  t501,  4200(I32)
	c0    add $r0.61 = $r0.61, $r0.5   ## bblock 30, line 0,  t500,  t500,  4200(I32)
	c0    mov $r0.3 = $r0.63   ## t223
	      ## goto
;;
	c0    goto L8?3 ## goto
;;								## 1
.trace 28
L9?3:
	c0    sub $r0.3 = $r0.0, $r0.63   ## bblock 6, line 0,  t481,  0(I32),  t223
	c0    mov $r0.62 = (t + 0)   ## bblock 6, line 0,  t479,  addr(t?1.0)(P32)
	c0    stw 0x60[$r0.1] = $r0.63  ## spill ## t223
;;								## 0
	c0    mov $r0.2 = $r0.3   ## bblock 6, line 0,  t480,  t481
	c0    mov $r0.63 = (y1 + 0)   ## bblock 6, line 0,  t478,  addr(y1?1.0)(P32)
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
	      xnop 1
;;								## 2
;;								## 3
.trace 17
L12?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 7, line 82,  t582(I1),  t480,  0(SI32)
	c0    sub $r0.5 = $r0.0, $r0.4   ## [spec] bblock 24, line 0,  t373,  0(I32),  t222
	c0    mov $r0.61 = $r0.0   ## [spec] bblock 24, line 0,  t367,  0(I32)
	c0    stw 0x7c[$r0.1] = $r0.2  ## spill ## t480
;;								## 0
	c0    mov $r0.60 = $r0.0   ## [spec] bblock 24, line 83,  t245,  0.000000e+00=0x0(F32)
	c0    mov $r0.59 = $r0.0   ## [spec] bblock 24, line 83,  t302,  0.000000e+00=0x0(F32)
	c0    mov $r0.57 = $r0.5   ## [spec] bblock 24, line 0,  t372,  t373
	c0    stw 0x80[$r0.1] = $r0.4  ## spill ## t222
;;								## 1
	c0    mov $r0.58 = $r0.0   ## [spec] bblock 24, line 83,  t303,  0.000000e+00=0x0(F32)
	c0    brf $b0.0, L13?3   ## bblock 7, line 82,  t582(I1)
;;								## 2
.trace 6
L14?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 25, line 84,  t595(I1),  t372,  0(SI32)
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
	c0    mov $r0.3 = $r0.58   ## t303
	      xnop 1
;;								## 1
	c0    brf $b0.0, L15?3   ## bblock 25, line 84,  t595(I1)
;;								## 2
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 85,  raddr(_r_mul)(P32),  t303,  -6.065310e-01=0xbf1b459e(F32)
;;								## 3
	c0    mov $r0.58 = $r0.59   ## bblock 27, line 85,  t303,  t302
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
	c0    stw 0x3c[$r0.1] = $r0.3  ## spill ## t106
;;								## 4
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 85,  raddr(_r_mul)(P32),  t302,  8.408960e-01=0x3f5744f6(F32)
	c0    mov $r0.3 = $r0.59   ## t302
;;								## 5
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
	c0    stw 0x40[$r0.1] = $r0.3  ## spill ## t109
;;								## 6
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 85,  raddr(_r_mul)(P32),  t245,  1.102090e-01=0x3de1b542(F32)
	c0    mov $r0.3 = $r0.60   ## t245
;;								## 7
	c0    sh3add $r0.2 = $r0.61, $r0.62   ## bblock 27, line 85,  t596,  t367,  t479
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
	c0    stw 0x44[$r0.1] = $r0.3  ## spill ## t112
;;								## 8
	c0    ldw $r0.60 = 0[$r0.2]   ## bblock 27, line 85, t245, t596
	      xnop 2
;;								## 11
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 85,  raddr(_r_mul)(P32),  t245,  -1.886820e-01=0xbe4135db(F32)
	c0    mov $r0.3 = $r0.60   ## t245
;;								## 12
	c0    stw 0x48[$r0.1] = $r0.3  ## spill ## t118
;;								## 13
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t106
;;								## 14
	c0    ldw $r0.4 = 0x40[$r0.1]  ## restore ## t109
	      xnop 1
;;								## 16
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 85,  raddr(_r_add)(P32),  t106,  t109
;;								## 17
	c0    ldw $r0.4 = 0x44[$r0.1]  ## restore ## t112
	      xnop 1
;;								## 19
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 85,  raddr(_r_add)(P32),  t203,  t112
;;								## 20
	c0    ldw $r0.4 = 0x48[$r0.1]  ## restore ## t118
	      xnop 1
;;								## 22
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 85,  raddr(_r_add)(P32),  t204,  t118
;;								## 23
	c0    sh3add $r0.2 = $r0.61, $r0.63   ## bblock 27, line 85,  t597,  t367,  t478
	c0    add $r0.57 = $r0.57, 1   ## bblock 27, line 0,  t372,  t372,  1(I32)
	c0    add $r0.61 = $r0.61, 525   ## bblock 27, line 0,  t367,  t367,  525(I32)
;;								## 24
	c0    stw 0[$r0.2] = $r0.3   ## bblock 27, line 85, t597, t302
	c0    mov $r0.59 = $r0.3   ## t302
	c0    goto L14?3 ## goto
;;								## 25
.trace 25
L15?3:
	c0    add $r0.62 = $r0.62, 4   ## bblock 26, line 0,  t479,  t479,  4(I32)
	c0    add $r0.63 = $r0.63, 4   ## bblock 26, line 0,  t478,  t478,  4(I32)
	c0    ldw $r0.2 = 0x7c[$r0.1]  ## restore ## t480
;;								## 0
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
	      xnop 1
;;								## 2
	c0    add $r0.2 = $r0.2, 1   ## bblock 26, line 0,  t480,  t480,  1(I32)
	c0    goto L12?3 ## goto
;;								## 3
.trace 30
L13?3:
	c0    mov $r0.4 = (t + 0)   ## bblock 8, line 0,  t457,  addr(t?1.0)(P32)
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t223
;;								## 0
	c0    mov $r0.63 = (y2 + 0)   ## bblock 8, line 0,  t458,  addr(y2?1.0)(P32)
	c0    stw 0x4c[$r0.1] = $r0.4  ## spill ## t457
;;								## 1
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
;;								## 2
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 8, line 0,  t460,  0(I32),  t223
;;								## 3
	c0    mov $r0.2 = $r0.3   ## bblock 8, line 0,  t459,  t460
;;								## 4
	c0    add $r0.5 = $r0.4, -1   ## bblock 8, line 100,  t310,  t222,  -1(SI32)
;;								## 5
.trace 18
L16?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 9, line 98,  t583(I1),  t459,  0(SI32)
	c0    mpylu $r0.62 = $r0.5, 525   ## [spec] bblock 20, line 0,  t390,  t310,  525(I32)
	c0    stw 0x84[$r0.1] = $r0.2  ## spill ## t459
;;								## 0
	c0    mov $r0.61 = $r0.0   ## [spec] bblock 20, line 99,  t240,  0.000000e+00=0x0(F32)
	c0    mov $r0.60 = $r0.0   ## [spec] bblock 20, line 99,  t239,  0.000000e+00=0x0(F32)
	c0    mov $r0.59 = $r0.0   ## [spec] bblock 20, line 99,  t306,  0.000000e+00=0x0(F32)
	c0    stw 0x88[$r0.1] = $r0.5  ## spill ## t310
;;								## 1
	c0    mov $r0.58 = $r0.0   ## [spec] bblock 20, line 99,  t305,  0.000000e+00=0x0(F32)
	c0    mov $r0.57 = $r0.5   ## [spec] bblock 20, line 100,  t307,  t310
	c0    brf $b0.0, L17?3   ## bblock 9, line 98,  t583(I1)
;;								## 2
.trace 7
L18?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 21, line 100,  t592(I1),  t307,  0(SI32)
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
	c0    mov $r0.3 = $r0.58   ## t305
	      xnop 1
;;								## 1
	c0    brf $b0.0, L19?3   ## bblock 21, line 100,  t592(I1)
;;								## 2
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 101,  raddr(_r_mul)(P32),  t305,  -6.065310e-01=0xbf1b459e(F32)
;;								## 3
	c0    mov $r0.58 = $r0.59   ## bblock 23, line 101,  t305,  t306
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
	c0    stw 0x50[$r0.1] = $r0.3  ## spill ## t143
;;								## 4
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 101,  raddr(_r_mul)(P32),  t306,  8.408960e-01=0x3f5744f6(F32)
	c0    mov $r0.3 = $r0.59   ## t306
;;								## 5
	c0    mov $r0.4 = 0x3dea600b   ## 1.144410e-01=0x3dea600b(F32)
	c0    stw 0x54[$r0.1] = $r0.3  ## spill ## t146
;;								## 6
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 101,  raddr(_r_mul)(P32),  t239,  1.144410e-01=0x3dea600b(F32)
	c0    mov $r0.3 = $r0.60   ## t239
;;								## 7
	c0    mov $r0.60 = $r0.61   ## bblock 23, line 101,  t239,  t240
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
	c0    stw 0x58[$r0.1] = $r0.3  ## spill ## t149
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 101,  raddr(_r_mul)(P32),  t240,  -1.836820e-01=0xbe3c1722(F32)
	c0    mov $r0.3 = $r0.61   ## t240
;;								## 9
	c0    stw 0x5c[$r0.1] = $r0.3  ## spill ## t152
;;								## 10
	c0    ldw $r0.3 = 0x50[$r0.1]  ## restore ## t143
;;								## 11
	c0    ldw $r0.4 = 0x54[$r0.1]  ## restore ## t146
	      xnop 1
;;								## 13
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 101,  raddr(_r_add)(P32),  t143,  t146
;;								## 14
	c0    ldw $r0.4 = 0x58[$r0.1]  ## restore ## t149
	      xnop 1
;;								## 16
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 101,  raddr(_r_add)(P32),  t201,  t149
;;								## 17
	c0    ldw $r0.4 = 0x5c[$r0.1]  ## restore ## t152
	      xnop 1
;;								## 19
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 101,  raddr(_r_add)(P32),  t202,  t152
;;								## 20
	c0    sh3add $r0.4 = $r0.62, $r0.63   ## bblock 23, line 101,  t593,  t390,  t458
	c0    add $r0.57 = $r0.57, -1   ## bblock 23, line 100,  t307,  t307,  -1(SI32)
	c0    ldw $r0.2 = 0x4c[$r0.1]  ## restore ## t457
	c0    mov $r0.59 = $r0.3   ## t306
;;								## 21
	c0    stw 0[$r0.4] = $r0.3   ## bblock 23, line 101, t593, t306
	      xnop 1
;;								## 23
	c0    sh3add $r0.3 = $r0.62, $r0.2   ## bblock 23, line 103,  t594,  t390,  t457
	c0    add $r0.62 = $r0.62, (~0x20c)   ## bblock 23, line 0,  t390,  t390,  (~0x20c)(I32)
;;								## 24
	c0    ldw $r0.61 = 0[$r0.3]   ## bblock 23, line 103, t240, t594
	      xnop 1
;;								## 26
	c0    goto L18?3 ## goto
;;								## 27
.trace 24
L19?3:
	c0    add $r0.63 = $r0.63, 4   ## bblock 22, line 0,  t458,  t458,  4(I32)
	c0    ldw $r0.3 = 0x4c[$r0.1]  ## restore ## t457
;;								## 0
	c0    ldw $r0.2 = 0x84[$r0.1]  ## restore ## t459
;;								## 1
	c0    ldw $r0.5 = 0x88[$r0.1]  ## restore ## t310
;;								## 2
	c0    add $r0.3 = $r0.3, 4   ## bblock 22, line 0,  t457,  t457,  4(I32)
;;								## 3
	c0    add $r0.2 = $r0.2, 1   ## bblock 22, line 0,  t459,  t459,  1(I32)
	c0    stw 0x4c[$r0.1] = $r0.3  ## spill ## t457
	c0    goto L16?3 ## goto
;;								## 4
.trace 31
L17?3:
	c0    mov $r0.61 = (out + 0)   ## bblock 10, line 0,  t426,  addr(out?1.0)(P32)
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
;;								## 0
	c0    mov $r0.58 = (y2 + 0)   ## bblock 10, line 0,  t429,  addr(y2?1.0)(P32)
	c0    mov $r0.59 = (y1 + 0)   ## bblock 10, line 0,  t428,  addr(y1?1.0)(P32)
;;								## 1
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t223
;;								## 2
	c0    sub $r0.4 = $r0.0, $r0.4   ## bblock 10, line 0,  t431,  0(I32),  t222
;;								## 3
	c0    mov $r0.2 = $r0.4   ## bblock 10, line 0,  t430,  t431
;;								## 4
.trace 19
L20?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 11, line 115,  t584(I1),  t430,  0(SI32)
	c0    mov $r0.57 = $r0.0   ## [spec] bblock 13, line 116,  t308,  0(SI32)
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 13, line 0,  t415,  0(I32),  t223
	c0    mov $r0.62 = $r0.2   ## t430
;;								## 0
	c0    mov $r0.60 = $r0.4   ## [spec] bblock 13, line 0,  t414,  t415
	c0    mov $r0.63 = $r0.3   ## t223
;;								## 1
	c0    brf $b0.0, L21?3   ## bblock 11, line 115,  t584(I1)
;;								## 2
.trace 4
L22?3:
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 14, line 116,  t585(I1),  t414,  0(SI32)
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 16, line 117,  t586,  t308,  t429
	c0    sh2add $r0.5 = $r0.57, $r0.59   ## [spec] bblock 16, line 117,  t587,  t308,  t428
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 16, line 117, t178, t586
;;								## 1
	c0    ldw.d $r0.4 = 0[$r0.5]   ## [spec] bblock 16, line 117, t182, t587
	c0    brf $b0.0, L23?3   ## bblock 14, line 116,  t585(I1)
;;								## 2
;;								## 3
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 16, line 117,  raddr(_r_add)(P32),  t178,  t182
;;								## 4
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 16, line 117,  raddr(_r_mul)(P32),  t183,  1.000000e+00=0x3f800000(F32)
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 5
.call _r_ufix, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = _r_ufix   ## bblock 16, line 117,  raddr(_r_ufix)(P32),  t185
;;								## 6
	c0    zxtb $r0.4 = $r0.3   ## bblock 16, line 117,  t187(I8),  t186(I8)
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 16, line 117,  t588,  t308,  t426
	c0    add $r0.5 = $r0.57, $r0.61   ## [spec] bblock 19, line 119,  t591,  t308,  t426
;;								## 7
	c0    stb 0[$r0.2] = $r0.3   ## bblock 16, line 117, t588, t186(I8)
	c0    cmpgt $b0.0 = $r0.4, 25   ## bblock 16, line 118,  t589(I1),  t187(I8),  25(SI32)
	      xnop 1
;;								## 9
	c0    brf $b0.0, L24?3   ## bblock 16, line 118,  t589(I1)
;;								## 10
	c0    stb 0[$r0.5] = $r0.0   ## bblock 19, line 119, t591, 0(I32)
	c0    add $r0.60 = $r0.60, 1   ## bblock 18, line 0,  t414,  t414,  1(I32)
	c0    add $r0.57 = $r0.57, 1   ## bblock 18, line 116,  t308,  t308,  1(SI32)
	c0    goto L22?3 ## goto
;;								## 11
.trace 13
L24?3:
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 17, line 121,  t590,  t308,  t426
	c0    add $r0.60 = $r0.60, 1   ## bblock 18, line 0,  t414,  t414,  1(I32)
	c0    add $r0.57 = $r0.57, 1   ## bblock 18, line 116,  t308,  t308,  1(SI32)
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 0[$r0.2] = $r0.3   ## bblock 17, line 121, t590, 255(I32)
	c0    goto L22?3 ## goto
;;								## 1
.trace 23
L23?3:
	c0    add $r0.59 = $r0.59, 4200   ## bblock 15, line 0,  t428,  t428,  4200(I32)
	c0    add $r0.61 = $r0.61, 1050   ## bblock 15, line 0,  t426,  t426,  1050(I32)
;;								## 0
	c0    add $r0.2 = $r0.62, 1   ## bblock 15, line 0,  t430,  t430,  1(I32)
	c0    add $r0.58 = $r0.58, 4200   ## bblock 15, line 0,  t429,  t429,  4200(I32)
	c0    mov $r0.3 = $r0.63   ## t223
	      ## goto
;;
	c0    goto L20?3 ## goto
;;								## 1
.trace 32
L21?3:
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t209
;;								## 0
	c0    ldw $r0.63 = 0xa4[$r0.1]  ## restore ## t219
;;								## 1
	c0    ldw $r0.62 = 0xa0[$r0.1]  ## restore ## t218
;;								## 2
	c0    ldw $r0.61 = 0x9c[$r0.1]  ## restore ## t217
;;								## 3
	c0    ldw $r0.60 = 0x98[$r0.1]  ## restore ## t216
;;								## 4
	c0    ldw $r0.59 = 0x94[$r0.1]  ## restore ## t215
;;								## 5
	c0    ldw $r0.58 = 0x90[$r0.1]  ## restore ## t214
;;								## 6
	c0    ldw $r0.57 = 0x8c[$r0.1]  ## restore ## t213
	      xnop 1
;;								## 8
.return ret()
	c0    return $r0.1 = $r0.1, (0xc0), $l0.0   ## bblock 12, line 131,  t210,  ?2.1?2auto_size(I32),  t209
;;								## 9
.endp
.section .bss
.section .data
.equ ?2.1?2scratch.0, 0x0
.equ ?2.1?2ras_p, 0x10
.equ ?2.1?2spill_p, 0x14
.section .data
.section .text
.equ ?2.1?2auto_size, 0xc0
 ## End deriche_float
 ## Begin deriche_array
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_array::
.trace 35
	      ## auto_size == 0
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t909,  0(I32),  t248
	c0    add $r0.18 = $r0.4, -1   ## bblock 0, line 161,  t309,  t249,  -1(SI32)
;;								## 0
	c0    mov $r0.17 = ((in + 0) + (~0x0))   ## bblock 0, line 0,  t905,  (addr(in?1.0)(P32) + 0xffffffff(I32))(P32)
	c0    mov $r0.20 = ((ay2 + 0) + (~0x3))   ## bblock 0, line 0,  t900,  (addr(ay2?1.0)(P32) + 0xfffffffc(I32))(P32)
;;								## 1
	c0    mov $r0.3 = $r0.2   ## bblock 0, line 0,  t908,  t909
	c0    mov $r0.22 = (in + 0)   ## bblock 0, line 0,  t907,  addr(in?1.0)(P32)
	c0    mov $r0.30 = $r0.3   ## t248
;;								## 2
	c0    mov $r0.21 = (ay1 + 0)   ## bblock 0, line 0,  t902,  addr(ay1?1.0)(P32)
	c0    mov $r0.5 = $r0.4   ## t249
;;								## 3
.trace 15
L25?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 1, line 159,  t968(I1),  t908,  0(SI32)
	c0    sub $r0.16 = 1, $r0.5   ## [spec] bblock 24, line 0,  t425,  1(I32),  t249
	c0    add $r0.15 = $r0.17, $r0.18   ## [spec] bblock 24, line 0,  t423,  t905,  t309
	c0    sh2add $r0.14 = $r0.18, $r0.20   ## [spec] bblock 24, line 0,  t422,  t309,  t900
;;								## 0
	c0    mov $r0.8 = $r0.16   ## [spec] bblock 24, line 0,  t424,  t425
	c0    mov $r0.12 = $r0.0   ## [spec] bblock 24, line 160,  t272,  0(SI32)
	c0    mov $r0.10 = $r0.0   ## [spec] bblock 24, line 160,  t271,  0(SI32)
	c0    mov $r0.13 = $r0.0   ## [spec] bblock 24, line 160,  t275,  0(SI32)
;;								## 1
	c0    mov $r0.6 = $r0.0   ## [spec] bblock 24, line 160,  t277,  0(SI32)
	c0    mov $r0.11 = $r0.0   ## [spec] bblock 24, line 160,  t276,  0(SI32)
	c0    mov $r0.9 = $r0.21   ## [spec] bblock 24, line 0,  t421,  t902
	c0    brf $b0.0, L26?3   ## bblock 1, line 159,  t968(I1)
;;								## 2
	c0    mov $r0.4 = $r0.0   ## bblock 24, line 160,  t278,  0(SI32)
	c0    mov $r0.7 = $r0.0   ## bblock 24, line 160,  t280,  0(SI32)
	c0    mov $r0.2 = $r0.22   ## bblock 24, line 0,  t420,  t907
	c0    mov $r0.23 = $r0.3   ## t908
;;								## 3
	c0    mov $r0.24 = $r0.5   ## t249
	c0    mov $r0.25 = $r0.17   ## t905
	c0    mov $r0.26 = $r0.18   ## t309
	c0    mov $r0.27 = $r0.20   ## t900
;;								## 4
	c0    mov $r0.28 = $r0.21   ## t902
	c0    mov $r0.29 = $r0.22   ## t907
;;								## 5
.trace 2
L27?3:
	c0    cmplt $b0.0 = $r0.8, 1   ## bblock 25, line 161,  t983(I1),  t424,  1(SI32)
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 27, line 163, t327, t420
	c0    mpyl $r0.5 = $r0.4, 215   ## [spec] bblock 27, line 165,  t23,  t278,  215(SI32)
	c0    mpyl $r0.6 = $r0.6, -155   ## [spec] bblock 27, line 166,  t27,  t277,  -155(SI32)
;;								## 0
	c0    mpyl $r0.7 = $r0.7, 28   ## [spec] bblock 27, line 164,  t31,  t280,  28(SI32)
	c0    mpyl $r0.10 = $r0.10, -155   ## [spec] bblock 27, line 176,  t320,  t271,  -155(SI32)
	c0    ldbu.d $r0.16 = 1[$r0.15]   ## [spec] bblock 27, line 179, t314, t423
	c0    cmplt $b0.1 = $r0.8, $r0.0   ## [spec] bblock 27, line 161-1,  t988(I1),  t424,  0(SI32)
;;								## 1
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 27, line 165,  t30(SI24),  t23,  8(SI32)
	c0    shr $r0.6 = $r0.6, 8   ## [spec] bblock 27, line 166,  t326(SI24),  t27,  8(SI32)
	c0    mpyl $r0.17 = $r0.11, -47   ## [spec] bblock 27, line 173,  t322,  t276,  -47(SI32)
	c0    brf $b0.0, L28?3   ## bblock 25, line 161,  t983(I1)
;;								## 2
	c0    mpyl $r0.18 = $r0.3, -48   ## bblock 27, line 163,  t32,  t327,  -48(SI32)
	c0    add $r0.7 = $r0.7, $r0.6   ## bblock 27, line 168,  t984,  t31,  t326(SI24)
	c0    mpyl $r0.19 = $r0.12, 215   ## bblock 27, line 175,  t409,  t272,  215(SI32)
	c0    shr $r0.10 = $r0.10, 8   ## bblock 27, line 176,  t319(SI24),  t320,  8(SI32)
;;								## 3
	c0    mpyl $r0.13 = $r0.13, -48   ## bblock 27, line 174,  t317,  t275,  -48(SI32)
	c0    add $r0.17 = $r0.17, $r0.10   ## bblock 27, line 177,  t986,  t322,  t319(SI24)
	c0    ldbu.d $r0.20 = 1[$r0.2]   ## [spec] bblock 62, line 163-1, t280, t420
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 62, line 166-1,  t328,  t278,  -155(SI32)
;;								## 4
	c0    add $r0.18 = $r0.18, $r0.5   ## bblock 27, line 168,  t985,  t32,  t30(SI24)
	c0    shr $r0.19 = $r0.19, 8   ## bblock 27, line 175,  t408(SI24),  t409,  8(SI32)
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 62, line 164-1,  t332,  t327,  28(SI32)
	c0    mpyl $r0.12 = $r0.12, -155   ## [spec] bblock 62, line 176-1,  t62,  t272,  -155(SI32)
;;								## 5
	c0    add $r0.7 = $r0.7, $r0.18   ## bblock 27, line 168,  t324,  t984,  t985
	c0    add $r0.13 = $r0.13, $r0.19   ## bblock 27, line 177,  t987,  t317,  t408(SI24)
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 62, line 166-1,  t29(SI24),  t328,  8(SI32)
	c0    mpyl $r0.5 = $r0.16, -47   ## [spec] bblock 62, line 173-1,  t67,  t314,  -47(SI32)
;;								## 6
	c0    add $r0.17 = $r0.17, $r0.13   ## bblock 27, line 177,  t311,  t986,  t987
	c0    mpyl $r0.18 = $r0.20, -48   ## [spec] bblock 62, line 163-1,  t331,  t280,  -48(SI32)
	c0    mpyl $r0.19 = $r0.7, 215   ## [spec] bblock 62, line 165-1,  t330,  t324,  215(SI32)
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 62, line 168-1,  t1000,  t332,  t29(SI24)
;;								## 7
	c0    mpyl $r0.11 = $r0.11, -48   ## [spec] bblock 62, line 174-1,  t66,  t276,  -48(SI32)
	c0    mpyl $r0.21 = $r0.17, 215   ## [spec] bblock 62, line 175-1,  t58,  t311,  215(SI32)
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 62, line 176-1,  t64(SI24),  t62,  8(SI32)
	c0    ldbu.d $r0.22 = 0[$r0.15]   ## [spec] bblock 62, line 179-1, t276, t423
;;								## 8
	c0    shr $r0.19 = $r0.19, 8   ## [spec] bblock 62, line 165-1,  t329(SI24),  t330,  8(SI32)
	c0    mov $r0.13 = $r0.16   ## [spec] bblock 62, line 179,  t275,  t314
	c0    mov $r0.10 = $r0.17   ## [spec] bblock 62, line 177,  t271,  t311
	c0    add $r0.5 = $r0.5, $r0.12   ## [spec] bblock 62, line 177-1,  t1002,  t67,  t64(SI24)
;;								## 9
	c0    mov $r0.6 = $r0.7   ## [spec] bblock 62, line 168,  t277,  t324
	c0    add $r0.18 = $r0.18, $r0.19   ## [spec] bblock 62, line 168-1,  t1001,  t331,  t329(SI24)
	c0    shr $r0.21 = $r0.21, 8   ## [spec] bblock 62, line 175-1,  t65(SI24),  t58,  8(SI32)
	c0    add $r0.2 = $r0.2, 2   ## [spec] bblock 62, line 0,  t420,  t420,  2(I32)
;;								## 10
	c0    add $r0.4 = $r0.3, $r0.18   ## [spec] bblock 62, line 168-1,  t278,  t1000,  t1001
	c0    add $r0.11 = $r0.11, $r0.21   ## [spec] bblock 62, line 177-1,  t1003,  t66,  t65(SI24)
	c0    add $r0.15 = $r0.15, (~0x1)   ## [spec] bblock 62, line 0,  t423,  t423,  (~0x1)(I32)
	c0    add $r0.8 = $r0.8, 2   ## [spec] bblock 62, line 0,  t424,  t424,  2(I32)
;;								## 11
	c0    stw 0[$r0.9] = $r0.7   ## bblock 27, line 168, t421, t324
	c0    add $r0.12 = $r0.5, $r0.11   ## [spec] bblock 62, line 177-1,  t272,  t1002,  t1003
	c0    mov $r0.11 = $r0.22   ## [spec] t276
;;								## 12
	c0    stw 4[$r0.14] = $r0.17   ## bblock 27, line 177, t422, t311
	c0    mov $r0.7 = $r0.20   ## [spec] t280
	c0    brf $b0.1, L29?3   ## bblock 27, line 161-1,  t988(I1)
;;								## 13
	c0    stw 4[$r0.9] = $r0.4   ## bblock 62, line 168-1, t421, t278
	c0    add $r0.9 = $r0.9, 8   ## bblock 62, line 0,  t421,  t421,  8(I32)
;;								## 14
	c0    stw 0[$r0.14] = $r0.12   ## bblock 62, line 177-1, t422, t272
	c0    add $r0.14 = $r0.14, (~0x7)   ## bblock 62, line 0,  t422,  t422,  (~0x7)(I32)
	c0    goto L27?3 ## goto
;;								## 15
.trace 21
L29?3:
	c0    add $r0.22 = $r0.29, 1050   ## bblock 26, line 0,  t907,  t907,  1050(I32)
	c0    add $r0.20 = $r0.27, 6000   ## bblock 26, line 0,  t900,  t900,  6000(I32)
	      ## goto
;;
	c0    goto L30?3 ## goto
;;								## 0
.trace 17
L28?3:
	c0    add $r0.22 = $r0.29, 1050   ## bblock 26, line 0,  t907,  t907,  1050(I32)
	c0    add $r0.20 = $r0.27, 6000   ## bblock 26, line 0,  t900,  t900,  6000(I32)
;;								## 0
L30?3:
	c0    add $r0.17 = $r0.25, 1050   ## bblock 26, line 0,  t905,  t905,  1050(I32)
	c0    add $r0.21 = $r0.28, 6000   ## bblock 26, line 0,  t902,  t902,  6000(I32)
;;								## 1
	c0    add $r0.3 = $r0.23, 1   ## bblock 26, line 0,  t908,  t908,  1(I32)
	c0    mov $r0.5 = $r0.24   ## t249
	c0    mov $r0.18 = $r0.26   ## t309
	c0    goto L25?3 ## goto
;;								## 2
.trace 34
L26?3:
	c0    sub $r0.2 = $r0.0, $r0.30   ## bblock 2, line 0,  t857,  0(I32),  t248
	c0    mov $r0.11 = (ay2 + 0)   ## bblock 2, line 0,  t853,  addr(ay2?1.0)(P32)
	c0    mov $r0.19 = $r0.30   ## t248
;;								## 0
	c0    mov $r0.3 = $r0.2   ## bblock 2, line 0,  t856,  t857
	c0    mov $r0.10 = (ay1 + 0)   ## bblock 2, line 0,  t854,  addr(ay1?1.0)(P32)
	c0    mov $r0.7 = $r0.5   ## t249
;;								## 1
	c0    mov $r0.9 = (at + 0)   ## bblock 2, line 0,  t855,  addr(at?1.0)(P32)
;;								## 2
.trace 13
L31?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 3, line 185,  t969(I1),  t856,  0(SI32)
	c0    sub $r0.8 = 3, $r0.7   ## [spec] bblock 20, line 0,  t496,  3(I32),  t249
	c0    mov $r0.6 = $r0.9   ## [spec] bblock 20, line 0,  t494,  t855
	c0    mov $r0.4 = $r0.10   ## [spec] bblock 20, line 0,  t493,  t854
;;								## 0
	c0    mov $r0.5 = $r0.8   ## [spec] bblock 20, line 0,  t495,  t496
	c0    mov $r0.2 = $r0.11   ## [spec] bblock 20, line 0,  t492,  t853
	c0    mov $r0.12 = $r0.3   ## t856
	c0    mov $r0.13 = $r0.7   ## t249
;;								## 1
	c0    mov $r0.14 = $r0.9   ## t855
	c0    mov $r0.15 = $r0.10   ## t854
	c0    mov $r0.16 = $r0.11   ## t853
	c0    brf $b0.0, L32?3   ## bblock 3, line 185,  t969(I1)
;;								## 2
.trace 3
L33?3:
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 21, line 186,  t981(I1),  t495,  3(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 23, line 187, t99, t492
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 23, line 186-1,  t982(I1),  t495,  2(SI32)
	c0    cmplt $b0.2 = $r0.5, 1   ## [spec] bblock 58, line 186-2,  t999(I1),  t495,  1(SI32)
;;								## 0
	c0    ldw.d $r0.7 = 0[$r0.4]   ## [spec] bblock 23, line 187, t340, t493
	c0    cmplt $b0.3 = $r0.5, $r0.0   ## [spec] bblock 55, line 186-3,  t998(I1),  t495,  0(SI32)
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 52, line 0,  t495,  t495,  4(I32)
;;								## 1
	c0    ldw.d $r0.8 = 4[$r0.2]   ## [spec] bblock 58, line 187-1, t334, t492
	c0    brf $b0.0, L34?3   ## bblock 21, line 186,  t981(I1)
;;								## 2
	c0    ldw.d $r0.9 = 4[$r0.4]   ## [spec] bblock 58, line 187-1, t105, t493
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.7   ## bblock 23, line 187,  t339,  t99,  t340
	c0    ldw.d $r0.7 = 8[$r0.2]   ## [spec] bblock 55, line 187-2, t347, t492
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## bblock 23, line 187,  t338,  t339,  8(I32)
	c0    ldw.d $r0.10 = 8[$r0.4]   ## [spec] bblock 55, line 187-2, t344, t493
;;								## 5
	c0    shr $r0.3 = $r0.3, 8   ## bblock 23, line 187,  t337(SI24),  t338,  8(SI32)
	c0    add $r0.8 = $r0.8, $r0.9   ## [spec] bblock 58, line 187-1,  t106,  t334,  t105
	c0    ldw.d $r0.9 = 12[$r0.2]   ## [spec] bblock 52, line 187-3, t353, t492
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 52, line 0,  t492,  t492,  16(I32)
;;								## 6
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 58, line 187-1,  t108,  t106,  8(I32)
	c0    ldw.d $r0.11 = 12[$r0.4]   ## [spec] bblock 52, line 187-3, t352, t493
	c0    add $r0.4 = $r0.4, 16   ## [spec] bblock 52, line 0,  t493,  t493,  16(I32)
;;								## 7
	c0    stw 0[$r0.6] = $r0.3   ## bblock 23, line 187, t494, t337(SI24)
	c0    shr $r0.8 = $r0.8, 8   ## [spec] bblock 58, line 187-1,  t109(SI24),  t108,  8(SI32)
	c0    add $r0.7 = $r0.7, $r0.10   ## [spec] bblock 55, line 187-2,  t343,  t347,  t344
	c0    brf $b0.1, L35?3   ## bblock 23, line 186-1,  t982(I1)
;;								## 8
	c0    stw 4[$r0.6] = $r0.8   ## bblock 58, line 187-1, t494, t109(SI24)
	c0    shl $r0.7 = $r0.7, 8   ## [spec] bblock 55, line 187-2,  t342,  t343,  8(I32)
	c0    brf $b0.2, L36?3   ## bblock 58, line 186-2,  t999(I1)
;;								## 9
	c0    shr $r0.7 = $r0.7, 8   ## bblock 55, line 187-2,  t385(SI24),  t342,  8(SI32)
	c0    add $r0.9 = $r0.9, $r0.11   ## [spec] bblock 52, line 187-3,  t351,  t353,  t352
;;								## 10
	c0    stw 8[$r0.6] = $r0.7   ## bblock 55, line 187-2, t494, t385(SI24)
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 52, line 187-3,  t350,  t351,  8(I32)
	c0    brf $b0.3, L37?3   ## bblock 55, line 186-3,  t998(I1)
;;								## 11
	c0    shr $r0.9 = $r0.9, 8   ## bblock 52, line 187-3,  t349(SI24),  t350,  8(SI32)
;;								## 12
	c0    stw 12[$r0.6] = $r0.9   ## bblock 52, line 187-3, t494, t349(SI24)
	c0    add $r0.6 = $r0.6, 16   ## bblock 52, line 0,  t494,  t494,  16(I32)
	c0    goto L33?3 ## goto
;;								## 13
.trace 27
L37?3:
	c0    add $r0.3 = $r0.12, 1   ## bblock 22, line 0,  t856,  t856,  1(I32)
	c0    mov $r0.7 = $r0.13   ## t249
	c0    mov $r0.2 = 6000   ## 6000(I32)
;;								## 0
	c0    add $r0.9 = $r0.14, $r0.2   ## bblock 22, line 0,  t855,  t855,  6000(I32)
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 22, line 0,  t854,  t854,  6000(I32)
	c0    add $r0.11 = $r0.16, $r0.2   ## bblock 22, line 0,  t853,  t853,  6000(I32)
	c0    goto L31?3 ## goto
;;								## 1
.trace 25
L36?3:
	c0    add $r0.3 = $r0.12, 1   ## bblock 22, line 0,  t856,  t856,  1(I32)
	c0    mov $r0.7 = $r0.13   ## t249
	c0    mov $r0.2 = 6000   ## 6000(I32)
;;								## 0
	c0    add $r0.9 = $r0.14, $r0.2   ## bblock 22, line 0,  t855,  t855,  6000(I32)
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 22, line 0,  t854,  t854,  6000(I32)
	c0    add $r0.11 = $r0.16, $r0.2   ## bblock 22, line 0,  t853,  t853,  6000(I32)
	c0    goto L31?3 ## goto
;;								## 1
.trace 23
L35?3:
	c0    add $r0.3 = $r0.12, 1   ## bblock 22, line 0,  t856,  t856,  1(I32)
	c0    mov $r0.7 = $r0.13   ## t249
	c0    mov $r0.2 = 6000   ## 6000(I32)
;;								## 0
	c0    add $r0.9 = $r0.14, $r0.2   ## bblock 22, line 0,  t855,  t855,  6000(I32)
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 22, line 0,  t854,  t854,  6000(I32)
	c0    add $r0.11 = $r0.16, $r0.2   ## bblock 22, line 0,  t853,  t853,  6000(I32)
	c0    goto L31?3 ## goto
;;								## 1
.trace 19
L34?3:
	c0    add $r0.3 = $r0.12, 1   ## bblock 22, line 0,  t856,  t856,  1(I32)
	c0    mov $r0.2 = 6000   ## 6000(I32)
;;								## 0
	c0    add $r0.9 = $r0.14, $r0.2   ## bblock 22, line 0,  t855,  t855,  6000(I32)
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 22, line 0,  t854,  t854,  6000(I32)
	c0    add $r0.11 = $r0.16, $r0.2   ## bblock 22, line 0,  t853,  t853,  6000(I32)
	c0    mov $r0.7 = $r0.13   ## t249
	      ## goto
;;
	c0    goto L31?3 ## goto
;;								## 1
.trace 33
L32?3:
	c0    add $r0.6 = $r0.19, -1   ## bblock 4, line 191,  t310,  t248,  -1(SI32)
	c0    sub $r0.2 = $r0.0, $r0.13   ## bblock 4, line 0,  t815,  0(I32),  t249
	c0    mov $r0.18 = ((ay2 + 0) + (~0x176f))   ## bblock 4, line 0,  t809,  (addr(ay2?1.0)(P32) + 0xffffe890(I32))(P32)
;;								## 0
	c0    mov $r0.3 = $r0.2   ## bblock 4, line 0,  t814,  t815
	c0    mov $r0.17 = ((at + 0) + (~0x176f))   ## bblock 4, line 0,  t810,  (addr(at?1.0)(P32) + 0xffffe890(I32))(P32)
	c0    mov $r0.27 = $r0.13   ## t249
;;								## 1
	c0    mov $r0.21 = (ay1 + 0)   ## bblock 4, line 0,  t813,  addr(ay1?1.0)(P32)
	c0    mov $r0.22 = (at + 0)   ## bblock 4, line 0,  t812,  addr(at?1.0)(P32)
;;								## 2
.trace 14
L38?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 5, line 189,  t970(I1),  t814,  0(SI32)
	c0    sub $r0.20 = 1, $r0.19   ## [spec] bblock 16, line 0,  t560,  1(I32),  t248
	c0    mpylu $r0.16 = $r0.6, 6000   ## [spec] bblock 16, line 0,  t609,  t310,  6000(I32)
;;								## 0
	c0    mov $r0.8 = $r0.20   ## [spec] bblock 16, line 0,  t559,  t560
	c0    mov $r0.11 = $r0.0   ## [spec] bblock 16, line 190,  t274,  0(SI32)
	c0    mov $r0.13 = $r0.0   ## [spec] bblock 16, line 190,  t273,  0(SI32)
	c0    mov $r0.12 = $r0.0   ## [spec] bblock 16, line 190,  t305(SI24),  0(SI32)
;;								## 1
	c0    mov $r0.10 = $r0.0   ## [spec] bblock 16, line 190,  t304,  0(SI32)
	c0    add $r0.15 = $r0.17, $r0.16   ## [spec] bblock 16, line 0,  t558,  t810,  t609
	c0    add $r0.14 = $r0.18, $r0.16   ## [spec] bblock 16, line 0,  t557,  t809,  t609
	c0    brf $b0.0, L39?3   ## bblock 5, line 189,  t970(I1)
;;								## 2
	c0    mov $r0.7 = $r0.0   ## bblock 16, line 190,  t279,  0(SI32)
	c0    mov $r0.5 = $r0.0   ## bblock 16, line 190,  t307(SI24),  0(SI32)
	c0    mov $r0.9 = $r0.21   ## bblock 16, line 0,  t556,  t813
	c0    mov $r0.2 = $r0.22   ## bblock 16, line 0,  t555,  t812
;;								## 3
	c0    mov $r0.4 = $r0.0   ## bblock 16, line 190,  t306,  0(SI32)
	c0    mov $r0.20 = $r0.3   ## t814
	c0    mov $r0.23 = $r0.18   ## t809
	c0    mov $r0.24 = $r0.19   ## t248
;;								## 4
	c0    mov $r0.21 = $r0.6   ## t310
	c0    mov $r0.22 = $r0.17   ## t810
	c0    mov $r0.25 = $r0.21   ## t813
	c0    mov $r0.26 = $r0.22   ## t812
;;								## 5
.trace 1
L40?3:
	c0    cmplt $b0.0 = $r0.8, 1   ## bblock 17, line 191,  t975(I1),  t559,  1(SI32)
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 19, line 192,  t129,  t306,  -155(SI32)
	c0    mpyl $r0.6 = $r0.5, 215   ## [spec] bblock 19, line 192,  t132,  t307(SI24),  215(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 19, line 192, t374, t555
;;								## 0
	c0    mpyl $r0.7 = $r0.7, 28   ## [spec] bblock 19, line 192,  t380,  t279,  28(SI32)
	c0    mpyl $r0.10 = $r0.10, -155   ## [spec] bblock 19, line 197,  t376,  t304,  -155(SI32)
	c0    ldw.d $r0.16 = 6000[$r0.15]   ## [spec] bblock 19, line 199, t358, t558
;;								## 1
	c0    mpyl $r0.18 = $r0.12, 215   ## [spec] bblock 19, line 197,  t375,  t305(SI24),  215(SI32)
	c0    mpyl $r0.17 = $r0.11, -47   ## [spec] bblock 19, line 197,  t371,  t274,  -47(SI32)
	c0    cmplt $b0.0 = $r0.8, $r0.0   ## [spec] bblock 19, line 191-1,  t980(I1),  t559,  0(SI32)
	c0    brf $b0.0, L41?3   ## bblock 17, line 191,  t975(I1)
;;								## 2
	c0    mpyl $r0.19 = $r0.3, -48   ## bblock 19, line 192,  t379,  t374,  -48(SI32)
	c0    add $r0.6 = $r0.6, $r0.7   ## bblock 19, line 192,  t977,  t132,  t380
	c0    mpyl $r0.13 = $r0.13, 29   ## bblock 19, line 197,  t373,  t273,  29(SI32)
	c0    add $r0.8 = $r0.8, 2   ## [spec] bblock 48, line 0,  t559,  t559,  2(I32)
;;								## 3
	c0    add $r0.10 = $r0.10, $r0.17   ## bblock 19, line 197,  t978,  t376,  t371
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 48, line 192-1,  t359,  t307(SI24),  -155(SI32)
	c0    ldw.d $r0.7 = 6000[$r0.2]   ## [spec] bblock 48, line 192-1, t279, t555
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.19   ## bblock 19, line 192,  t976,  t129,  t379
	c0    add $r0.18 = $r0.18, $r0.13   ## bblock 19, line 197,  t979,  t375,  t373
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 48, line 192-1,  t135,  t374,  28(SI32)
	c0    mpyl $r0.12 = $r0.12, -155   ## [spec] bblock 48, line 197-1,  t166,  t305(SI24),  -155(SI32)
;;								## 5
	c0    add $r0.4 = $r0.4, $r0.6   ## bblock 19, line 192,  t378,  t976,  t977
	c0    add $r0.10 = $r0.10, $r0.18   ## bblock 19, line 197,  t370,  t978,  t979
	c0    mpyl $r0.11 = $r0.11, 29   ## [spec] bblock 48, line 197-1,  t172,  t274,  29(SI32)
	c0    mpyl $r0.6 = $r0.16, -47   ## [spec] bblock 48, line 197-1,  t175,  t358,  -47(SI32)
;;								## 6
	c0    shr $r0.4 = $r0.4, 8   ## bblock 19, line 192,  t965,  t378,  8(SI32)
	c0    shr $r0.10 = $r0.10, 8   ## bblock 19, line 197,  t966,  t370,  8(SI32)
	c0    mpyl $r0.17 = $r0.7, -48   ## [spec] bblock 48, line 192-1,  t143,  t279,  -48(SI32)
	c0    ldw.d $r0.18 = 0[$r0.15]   ## [spec] bblock 48, line 199-1, t274, t558
;;								## 7
	c0    mpyl $r0.19 = $r0.4, 215   ## [spec] bblock 48, line 192-1,  t357,  t965,  215(SI32)
	c0    mpyl $r0.6 = $r0.10, 215   ## [spec] bblock 48, line 197-1,  t169,  t966,  215(SI32)
	c0    mov $r0.13 = $r0.16   ## [spec] bblock 48, line 199,  t273,  t358
	c0    add $r0.12 = $r0.12, $r0.6   ## [spec] bblock 48, line 197-1,  t996,  t166,  t175
;;								## 8
	c0    stw 0[$r0.9] = $r0.4   ## bblock 19, line 192, t556, t965
	c0    mov $r0.17 = $r0.4   ## [spec] bblock 48, line 192,  t306,  t965
	c0    add $r0.5 = $r0.5, $r0.17   ## [spec] bblock 48, line 192-1,  t994,  t359,  t143
	c0    mov $r0.16 = $r0.10   ## [spec] bblock 48, line 197,  t304,  t966
;;								## 9
	c0    add $r0.19 = $r0.19, $r0.3   ## [spec] bblock 48, line 192-1,  t995,  t357,  t135
	c0    add $r0.6 = $r0.6, $r0.11   ## [spec] bblock 48, line 197-1,  t997,  t169,  t172
	c0    add $r0.2 = $r0.2, 12000   ## [spec] bblock 48, line 0,  t555,  t555,  12000(I32)
;;								## 10
	c0    add $r0.5 = $r0.5, $r0.19   ## [spec] bblock 48, line 192-1,  t144,  t994,  t995
	c0    add $r0.12 = $r0.12, $r0.6   ## [spec] bblock 48, line 197-1,  t176,  t996,  t997
	c0    add $r0.15 = $r0.15, (~0x2edf)   ## [spec] bblock 48, line 0,  t558,  t558,  (~0x2edf)(I32)
;;								## 11
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 48, line 192-1,  t307(SI24),  t144,  8(SI32)
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 48, line 197-1,  t305(SI24),  t176,  8(SI32)
	c0    mov $r0.11 = $r0.18   ## [spec] t274
	c0    mov $r0.4 = $r0.17   ## [spec] t306
;;								## 12
	c0    stw 6000[$r0.14] = $r0.10   ## bblock 19, line 197, t557, t966
	c0    mov $r0.10 = $r0.16   ## [spec] t304
	c0    brf $b0.0, L42?3   ## bblock 19, line 191-1,  t980(I1)
;;								## 13
	c0    stw 6000[$r0.9] = $r0.5   ## bblock 48, line 192-1, t556, t307(SI24)
	c0    add $r0.9 = $r0.9, 12000   ## bblock 48, line 0,  t556,  t556,  12000(I32)
;;								## 14
	c0    stw 0[$r0.14] = $r0.12   ## bblock 48, line 197-1, t557, t305(SI24)
	c0    add $r0.14 = $r0.14, (~0x2edf)   ## bblock 48, line 0,  t557,  t557,  (~0x2edf)(I32)
	c0    goto L40?3 ## goto
;;								## 15
.trace 22
L42?3:
	c0    add $r0.3 = $r0.20, 1   ## bblock 18, line 0,  t814,  t814,  1(I32)
	c0    mov $r0.6 = $r0.21   ## t310
	c0    mov $r0.19 = $r0.24   ## t248
	c0    goto L43?3 ## goto
;;								## 0
.trace 18
L41?3:
	c0    add $r0.3 = $r0.20, 1   ## bblock 18, line 0,  t814,  t814,  1(I32)
	c0    mov $r0.19 = $r0.24   ## t248
	c0    mov $r0.6 = $r0.21   ## t310
;;								## 0
L43?3:
	c0    add $r0.21 = $r0.25, 4   ## bblock 18, line 0,  t813,  t813,  4(I32)
	c0    add $r0.17 = $r0.22, 4   ## bblock 18, line 0,  t810,  t810,  4(I32)
	c0    add $r0.18 = $r0.23, 4   ## bblock 18, line 0,  t809,  t809,  4(I32)
;;								## 1
	c0    add $r0.22 = $r0.26, 4   ## bblock 18, line 0,  t812,  t812,  4(I32)
	c0    goto L38?3 ## goto
;;								## 2
.trace 32
L39?3:
	c0    sub $r0.19 = $r0.0, $r0.19   ## bblock 6, line 0,  t749,  0(I32),  t248
	c0    mov $r0.12 = (ay2 + 0)   ## bblock 6, line 0,  t746,  addr(ay2?1.0)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.19   ## bblock 6, line 0,  t748,  t749
	c0    mov $r0.11 = (ay1 + 0)   ## bblock 6, line 0,  t747,  addr(ay1?1.0)(P32)
;;								## 1
	c0    mov $r0.10 = (out + 0)   ## bblock 6, line 0,  t740,  addr(out?1.0)(P32)
	c0    mov $r0.8 = $r0.27   ## t249
;;								## 2
.trace 16
L44?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 7, line 205,  t971(I1),  t748,  0(SI32)
	c0    sub $r0.9 = 3, $r0.8   ## [spec] bblock 9, line 0,  t656,  3(I32),  t249
	c0    mov $r0.7 = $r0.10   ## [spec] bblock 9, line 0,  t654,  t740
	c0    mov $r0.6 = $r0.10   ## [spec] bblock 9, line 0,  t653,  t740
;;								## 0
	c0    mov $r0.5 = $r0.9   ## [spec] bblock 9, line 0,  t655,  t656
	c0    mov $r0.4 = $r0.11   ## [spec] bblock 9, line 0,  t652,  t747
	c0    mov $r0.2 = $r0.12   ## [spec] bblock 9, line 0,  t651,  t746
	c0    mov $r0.14 = $r0.3   ## t748
;;								## 1
	c0    mov $r0.15 = $r0.8   ## t249
	c0    mov $r0.16 = $r0.10   ## t740
	c0    mov $r0.17 = $r0.11   ## t747
	c0    brf $b0.0, L45?3   ## bblock 7, line 205,  t971(I1)
;;								## 2
	c0    mov $r0.18 = $r0.12   ## t746
;;								## 3
.trace 4
L46?3:
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 10, line 206,  t972(I1),  t655,  3(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 12, line 207, t406, t651
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 14, line 206-1,  t974(I1),  t655,  2(SI32)
	c0    cmplt $b0.2 = $r0.5, 1   ## [spec] bblock 43, line 206-2,  t993(I1),  t655,  1(SI32)
;;								## 0
	c0    ldw.d $r0.8 = 0[$r0.4]   ## [spec] bblock 12, line 207, t405, t652
	c0    cmplt $b0.3 = $r0.5, $r0.0   ## [spec] bblock 37, line 206-3,  t991(I1),  t655,  0(SI32)
;;								## 1
	c0    ldw.d $r0.9 = 4[$r0.2]   ## [spec] bblock 41, line 207-1, t363, t651
	c0    brf $b0.0, L47?3   ## bblock 10, line 206,  t972(I1)
;;								## 2
	c0    ldw.d $r0.10 = 4[$r0.4]   ## [spec] bblock 41, line 207-1, t362, t652
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.8   ## bblock 12, line 207,  t400,  t406,  t405
	c0    ldw.d $r0.11 = 8[$r0.2]   ## [spec] bblock 35, line 207-2, t210, t651
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## bblock 12, line 207,  t399,  t400,  8(I32)
	c0    ldw.d $r0.8 = 8[$r0.4]   ## [spec] bblock 35, line 207-2, t216, t652
;;								## 5
	c0    shr $r0.3 = $r0.3, 16   ## bblock 12, line 207,  t398(SI16),  t399,  16(SI32)
	c0    add $r0.9 = $r0.9, $r0.10   ## [spec] bblock 41, line 207-1,  t361,  t363,  t362
	c0    ldw.d $r0.12 = 12[$r0.2]   ## [spec] bblock 29, line 207-3, t403, t651
;;								## 6
	c0    zxtb $r0.10 = $r0.3   ## bblock 12, line 207,  t397(I8),  t398(SI16)
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 41, line 207-1,  t219,  t361,  8(I32)
	c0    ldw.d $r0.13 = 12[$r0.4]   ## [spec] bblock 29, line 207-3, t402, t652
;;								## 7
	c0    stb 0[$r0.6] = $r0.3   ## bblock 12, line 207, t653, t398(SI16)
	c0    cmpgt $b0.0 = $r0.10, 25   ## bblock 12, line 208,  t973(I1),  t397(I8),  25(SI32)
	c0    shr $r0.9 = $r0.9, 16   ## [spec] bblock 41, line 207-1,  t220(SI16),  t219,  16(SI32)
	c0    add $r0.11 = $r0.11, $r0.8   ## [spec] bblock 35, line 207-2,  t217,  t210,  t216
;;								## 8
	c0    zxtb $r0.3 = $r0.9   ## [spec] bblock 41, line 207-1,  t228(I8),  t220(SI16)
	c0    shl $r0.11 = $r0.11, 8   ## [spec] bblock 35, line 207-2,  t390,  t217,  8(I32)
;;								## 9
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 41, line 208-1,  t992(I1),  t228(I8),  25(SI32)
	c0    shr $r0.11 = $r0.11, 16   ## [spec] bblock 35, line 207-2,  t389(SI16),  t390,  16(SI32)
	c0    add $r0.12 = $r0.12, $r0.13   ## [spec] bblock 29, line 207-3,  t396,  t403,  t402
	c0    brf $b0.0, L48?3   ## bblock 12, line 208,  t973(I1)
;;								## 10
	c0    stb 0[$r0.6] = $r0.0   ## bblock 15, line 209, t653, 0(I32)
	c0    zxtb $r0.8 = $r0.11   ## [spec] bblock 35, line 207-2,  t388(I8),  t389(SI16)
	c0    shl $r0.12 = $r0.12, 8   ## [spec] bblock 29, line 207-3,  t395,  t396,  8(I32)
	c0    brf $b0.1, L49?3   ## bblock 14, line 206-1,  t974(I1)
;;								## 11
L50?3:
	c0    stb 1[$r0.6] = $r0.9   ## bblock 41, line 207-1, t653, t220(SI16)
	c0    cmpgt $b0.1 = $r0.8, 25   ## [spec] bblock 35, line 208-2,  t990(I1),  t388(I8),  25(SI32)
	c0    shr $r0.12 = $r0.12, 16   ## [spec] bblock 29, line 207-3,  t394(SI16),  t395,  16(SI32)
	c0    brf $b0.0, L51?3   ## bblock 41, line 208-1,  t992(I1)
;;								## 12
	c0    stb 1[$r0.6] = $r0.0   ## bblock 44, line 209-1, t653, 0(I32)
	c0    zxtb $r0.3 = $r0.12   ## [spec] bblock 29, line 207-3,  t393(I8),  t394(SI16)
	c0    brf $b0.2, L52?3   ## bblock 43, line 206-2,  t993(I1)
;;								## 13
L53?3:
	c0    stb 2[$r0.6] = $r0.11   ## bblock 35, line 207-2, t653, t389(SI16)
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 29, line 208-3,  t989(I1),  t393(I8),  25(SI32)
	c0    brf $b0.1, L54?3   ## bblock 35, line 208-2,  t990(I1)
;;								## 14
	c0    stb 2[$r0.6] = $r0.0   ## bblock 38, line 209-2, t653, 0(I32)
	c0    brf $b0.3, L55?3   ## bblock 37, line 206-3,  t991(I1)
;;								## 15
L56?3:
	c0    stb 3[$r0.6] = $r0.12   ## bblock 29, line 207-3, t653, t394(SI16)
	c0    brf $b0.0, L57?3   ## bblock 29, line 208-3,  t989(I1)
;;								## 16
	c0    add $r0.5 = $r0.5, 4   ## bblock 31, line 0,  t655,  t655,  4(I32)
	c0    add $r0.7 = $r0.7, 4   ## bblock 31, line 0,  t654,  t654,  4(I32)
	c0    add $r0.4 = $r0.4, 16   ## bblock 31, line 0,  t652,  t652,  16(I32)
	c0    add $r0.2 = $r0.2, 16   ## bblock 31, line 0,  t651,  t651,  16(I32)
;;								## 17
	c0    stb 3[$r0.6] = $r0.0   ## bblock 32, line 209-3, t653, 0(I32)
;;								## 18
L58?3:
	c0    add $r0.6 = $r0.6, 4   ## bblock 31, line 0,  t653,  t653,  4(I32)
	c0    goto L46?3 ## goto
;;								## 19
.trace 12
L57?3:
	c0    add $r0.5 = $r0.5, 4   ## bblock 31, line 0,  t655,  t655,  4(I32)
	c0    add $r0.4 = $r0.4, 16   ## bblock 31, line 0,  t652,  t652,  16(I32)
	c0    add $r0.2 = $r0.2, 16   ## bblock 31, line 0,  t651,  t651,  16(I32)
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 3[$r0.7] = $r0.3   ## bblock 30, line 211-3, t654, 255(I32)
	c0    add $r0.7 = $r0.7, 4   ## bblock 31, line 0,  t654,  t654,  4(I32)
	c0    goto L58?3 ## goto
;;								## 1
.trace 28
L55?3:
	c0    add $r0.3 = $r0.14, 1   ## bblock 11, line 0,  t748,  t748,  1(I32)
	c0    add $r0.11 = $r0.17, 6000   ## bblock 11, line 0,  t747,  t747,  6000(I32)
	c0    mov $r0.8 = $r0.15   ## t249
;;								## 0
	c0    add $r0.12 = $r0.18, 6000   ## bblock 11, line 0,  t746,  t746,  6000(I32)
	c0    add $r0.10 = $r0.16, 1050   ## bblock 11, line 0,  t740,  t740,  1050(I32)
	      ## goto
;;
	c0    goto L44?3 ## goto
;;								## 1
.trace 11
L54?3:
	c0    zxtb $r0.8 = $r0.12   ## [spec] bblock 29, line 207-3,  t393(I8),  t394(SI16)
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 2[$r0.7] = $r0.3   ## bblock 36, line 211-2, t654, 255(I32)
	c0    cmpgt $b0.0 = $r0.8, 25   ## [spec] bblock 29, line 208-3,  t989(I1),  t393(I8),  25(SI32)
	c0    brf $b0.3, L59?3   ## bblock 37, line 206-3,  t991(I1)
;;								## 1
	c0    goto L56?3 ## goto
;;								## 2
.trace 31
L59?3:
	c0    goto L55?3 ## goto
;;								## 0
.trace 26
L52?3:
	c0    add $r0.3 = $r0.14, 1   ## bblock 11, line 0,  t748,  t748,  1(I32)
	c0    add $r0.11 = $r0.17, 6000   ## bblock 11, line 0,  t747,  t747,  6000(I32)
	c0    mov $r0.8 = $r0.15   ## t249
;;								## 0
	c0    add $r0.12 = $r0.18, 6000   ## bblock 11, line 0,  t746,  t746,  6000(I32)
	c0    add $r0.10 = $r0.16, 1050   ## bblock 11, line 0,  t740,  t740,  1050(I32)
	      ## goto
;;
	c0    goto L44?3 ## goto
;;								## 1
.trace 10
L51?3:
	c0    zxtb $r0.10 = $r0.11   ## [spec] bblock 35, line 207-2,  t388(I8),  t389(SI16)
	c0    ldw.d $r0.9 = 12[$r0.2]   ## [spec] bblock 29, line 207-3, t403, t651
	c0    mov $r0.8 = 255   ## 255(I32)
;;								## 0
	c0    stb 1[$r0.7] = $r0.8   ## bblock 42, line 211-1, t654, 255(I32)
	c0    cmpgt $b0.1 = $r0.10, 25   ## [spec] bblock 35, line 208-2,  t990(I1),  t388(I8),  25(SI32)
	c0    brf $b0.2, L60?3   ## bblock 43, line 206-2,  t993(I1)
;;								## 1
;;								## 2
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 29, line 207-3,  t396,  t403,  t402
;;								## 3
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 29, line 207-3,  t395,  t396,  8(I32)
;;								## 4
	c0    shr $r0.12 = $r0.9, 16   ## [spec] bblock 29, line 207-3,  t394(SI16),  t395,  16(SI32)
;;								## 5
	c0    zxtb $r0.3 = $r0.12   ## [spec] bblock 29, line 207-3,  t393(I8),  t394(SI16)
	c0    goto L53?3 ## goto
;;								## 6
.trace 30
L60?3:
	c0    goto L52?3 ## goto
;;								## 0
.trace 24
L49?3:
	c0    add $r0.3 = $r0.14, 1   ## bblock 11, line 0,  t748,  t748,  1(I32)
	c0    add $r0.11 = $r0.17, 6000   ## bblock 11, line 0,  t747,  t747,  6000(I32)
	c0    mov $r0.8 = $r0.15   ## t249
;;								## 0
	c0    add $r0.12 = $r0.18, 6000   ## bblock 11, line 0,  t746,  t746,  6000(I32)
	c0    add $r0.10 = $r0.16, 1050   ## bblock 11, line 0,  t740,  t740,  1050(I32)
	      ## goto
;;
	c0    goto L44?3 ## goto
;;								## 1
.trace 9
L48?3:
	c0    zxtb $r0.8 = $r0.11   ## [spec] bblock 35, line 207-2,  t388(I8),  t389(SI16)
	c0    shl $r0.12 = $r0.12, 8   ## [spec] bblock 29, line 207-3,  t395,  t396,  8(I32)
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 0[$r0.7] = $r0.3   ## bblock 13, line 211, t654, 255(I32)
	c0    brf $b0.1, L49?3   ## bblock 14, line 206-1,  t974(I1)
	      ## goto
;;
	c0    goto L50?3 ## goto
;;								## 1
.trace 20
L47?3:
	c0    add $r0.11 = $r0.17, 6000   ## bblock 11, line 0,  t747,  t747,  6000(I32)
	c0    add $r0.12 = $r0.18, 6000   ## bblock 11, line 0,  t746,  t746,  6000(I32)
;;								## 0
	c0    add $r0.3 = $r0.14, 1   ## bblock 11, line 0,  t748,  t748,  1(I32)
	c0    add $r0.10 = $r0.16, 1050   ## bblock 11, line 0,  t740,  t740,  1050(I32)
	c0    mov $r0.8 = $r0.15   ## t249
	      ## goto
;;
	c0    goto L44?3 ## goto
;;								## 1
.trace 36
L45?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 8, line 215,  t236,  ?2.2?2auto_size(I32),  t235
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.2?2auto_size, 0x0
 ## End deriche_array
 ## Begin deriche_fused
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_fused::
.trace 27
	      ## auto_size == 0
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t726,  0(I32),  t202
	c0    add $r0.11 = $r0.4, -1   ## bblock 0, line 243,  t291,  t203,  -1(SI32)
;;								## 0
	c0    mov $r0.28 = (qy1 + 0)   ## bblock 0, line 0,  t717,  addr(qy1?1.0)(P32)
	c0    mov $r0.29 = (in + 0)   ## bblock 0, line 0,  t715,  addr(in?1.0)(P32)
;;								## 1
	c0    mov $r0.4 = $r0.2   ## bblock 0, line 0,  t725,  t726
	c0    mov $r0.27 = (qy2 + 0)   ## bblock 0, line 0,  t718,  addr(qy2?1.0)(P32)
	c0    mov $r0.25 = $r0.4   ## t203
;;								## 2
	c0    mov $r0.26 = (qt + 0)   ## bblock 0, line 0,  t719,  addr(qt?1.0)(P32)
	c0    mov $r0.12 = ((qy2 + 0) + (~0xb))   ## bblock 0, line 0,  t723,  (addr(qy2?1.0)(P32) + 0xfffffff4(I32))(P32)
;;								## 3
	c0    mov $r0.10 = ((in + 0) + (~0x2))   ## bblock 0, line 0,  t724,  (addr(in?1.0)(P32) + 0xfffffffd(I32))(P32)
	c0    mov $r0.30 = $r0.3   ## t202
;;								## 4
.trace 11
L61?3:
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 1, line 241,  t796(I1),  t725,  0(SI32)
	c0    add $r0.9 = $r0.10, $r0.11   ## [spec] bblock 15, line 0,  t477,  t724,  t291
	c0    mov $r0.2 = $r0.0   ## [spec] bblock 15, line 242,  t225,  0(SI32)
	c0    sh2add $r0.8 = $r0.11, $r0.12   ## [spec] bblock 15, line 0,  t476,  t291,  t723
;;								## 0
	c0    mov $r0.22 = $r0.0   ## [spec] bblock 15, line 242,  t234,  0(SI32)
	c0    mov $r0.5 = $r0.0   ## [spec] bblock 15, line 242,  t226,  0(SI32)
	c0    mov $r0.3 = $r0.0   ## [spec] bblock 15, line 242,  t230,  0(SI32)
	c0    mov $r0.6 = $r0.0   ## [spec] bblock 15, line 242,  t229,  0(SI32)
;;								## 1
	c0    mov $r0.23 = $r0.0   ## [spec] bblock 15, line 242,  t232,  0(SI32)
	c0    mov $r0.24 = $r0.0   ## [spec] bblock 15, line 242,  t231,  0(SI32)
	c0    mov $r0.7 = $r0.11   ## [spec] bblock 15, line 243,  t344,  t291
	c0    brf $b0.0, L62?3   ## bblock 1, line 241,  t796(I1)
;;								## 2
	c0    mov $r0.18 = $r0.4   ## t725
	c0    mov $r0.19 = $r0.10   ## t724
	c0    mov $r0.20 = $r0.11   ## t291
	c0    mov $r0.21 = $r0.12   ## t723
;;								## 3
.trace 2
L63?3:
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## bblock 16, line 243,  t807(I1),  t344,  0(SI32)
	c0    mpyl $r0.4 = $r0.3, -47   ## [spec] bblock 21, line 244,  t297,  t230,  -47(SI32)
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 21, line 247,  t412,  t225,  -155(SI32)
	c0    ldbu.d $r0.10 = 3[$r0.9]   ## [spec] bblock 21, line 250, t294, t477
;;								## 0
	c0    mpyl $r0.6 = $r0.6, -48   ## [spec] bblock 21, line 245,  t25,  t229,  -48(SI32)
	c0    mpyl $r0.11 = $r0.5, 215   ## [spec] bblock 21, line 246,  t17,  t226,  215(SI32)
	c0    cmpge $b0.1 = $r0.7, 1   ## [spec] bblock 21, line 243-1,  t814(I1),  t344,  1(SI32)
	c0    ldbu.d $r0.12 = 2[$r0.9]   ## [spec] bblock 46, line 250-1, t404, t477
;;								## 1
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 21, line 247,  t411(SI24),  t412,  8(SI32)
	c0    mpyl $r0.3 = $r0.3, -48   ## [spec] bblock 46, line 245-1,  t318,  t230,  -48(SI32)
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 46, line 247-1,  t21,  t226,  -155(SI32)
	c0    brf $b0.0, L64?3   ## bblock 16, line 243,  t807(I1)
;;								## 2
	c0    shr $r0.11 = $r0.11, 8   ## bblock 21, line 246,  t24(SI24),  t17,  8(SI32)
	c0    add $r0.4 = $r0.4, $r0.2   ## bblock 21, line 248,  t812,  t297,  t411(SI24)
	c0    mpyl $r0.13 = $r0.10, -47   ## [spec] bblock 46, line 244-1,  t26,  t294,  -47(SI32)
	c0    cmpge $b0.0 = $r0.7, 2   ## [spec] bblock 46, line 243-2,  t833(I1),  t344,  2(SI32)
;;								## 3
	c0    add $r0.6 = $r0.6, $r0.11   ## bblock 21, line 248,  t813,  t25,  t24(SI24)
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 46, line 247-1,  t23(SI24),  t21,  8(SI32)
	c0    mpyl $r0.11 = $r0.12, -47   ## [spec] bblock 43, line 244-2,  t343,  t404,  -47(SI32)
	c0    mpyl $r0.10 = $r0.10, -48   ## [spec] bblock 43, line 245-2,  t342,  t294,  -48(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.6   ## bblock 21, line 248,  t295,  t812,  t813
	c0    add $r0.13 = $r0.13, $r0.5   ## [spec] bblock 46, line 248-1,  t831,  t26,  t23(SI24)
	c0    ldbu.d $r0.14 = 1[$r0.9]   ## [spec] bblock 43, line 250-2, t328, t477
	c0    cmpge $b0.2 = $r0.7, 3   ## [spec] bblock 43, line 243-3,  t830(I1),  t344,  3(SI32)
;;								## 5
	c0    mpyl $r0.15 = $r0.4, 215   ## [spec] bblock 46, line 246-1,  t406,  t295,  215(SI32)
	c0    mpyl $r0.16 = $r0.4, -155   ## [spec] bblock 43, line 247-2,  t338,  t295,  -155(SI32)
	c0    ldbu.d $r0.17 = 0[$r0.9]   ## [spec] bblock 40, line 250-3, t230, t477
	c0    add $r0.7 = $r0.7, -4   ## [spec] bblock 40, line 243-3,  t344,  t344,  -4(SI32)
;;								## 6
	c0    stw 12[$r0.8] = $r0.4   ## bblock 21, line 248, t476, t295
	c0    mpyl $r0.12 = $r0.12, -48   ## [spec] bblock 40, line 245-3,  t349,  t404,  -48(SI32)
	c0    add $r0.9 = $r0.9, (~0x3)   ## [spec] bblock 40, line 0,  t477,  t477,  (~0x3)(I32)
	c0    brf $b0.1, L65?3   ## bblock 21, line 243-1,  t814(I1)
;;								## 7
	c0    shr $r0.15 = $r0.15, 8   ## bblock 46, line 246-1,  t405(SI24),  t406,  8(SI32)
	c0    shr $r0.16 = $r0.16, 8   ## [spec] bblock 43, line 247-2,  t337(SI24),  t338,  8(SI32)
	c0    mov $r0.6 = $r0.14   ## [spec] bblock 40, line 250-2,  t229,  t328
	c0    mpyl $r0.4 = $r0.14, -47   ## [spec] bblock 40, line 244-3,  t350,  t328,  -47(SI32)
;;								## 8
	c0    add $r0.3 = $r0.3, $r0.15   ## bblock 46, line 248-1,  t832,  t318,  t405(SI24)
	c0    add $r0.11 = $r0.11, $r0.16   ## [spec] bblock 43, line 248-2,  t828,  t343,  t337(SI24)
;;								## 9
	c0    add $r0.13 = $r0.13, $r0.3   ## bblock 46, line 248-1,  t313,  t831,  t832
	c0    mov $r0.3 = $r0.17   ## [spec] t230
;;								## 10
	c0    stw 8[$r0.8] = $r0.13   ## bblock 46, line 248-1, t476, t313
	c0    mpyl $r0.14 = $r0.13, 215   ## [spec] bblock 43, line 246-2,  t340,  t313,  215(SI32)
	c0    mpyl $r0.15 = $r0.13, -155   ## [spec] bblock 40, line 247-3,  t399,  t313,  -155(SI32)
	c0    brf $b0.0, L66?3   ## bblock 46, line 243-2,  t833(I1)
;;								## 11
;;								## 12
	c0    shr $r0.14 = $r0.14, 8   ## bblock 43, line 246-2,  t339(SI24),  t340,  8(SI32)
	c0    shr $r0.15 = $r0.15, 8   ## [spec] bblock 40, line 247-3,  t398(SI24),  t399,  8(SI32)
;;								## 13
	c0    add $r0.10 = $r0.10, $r0.14   ## bblock 43, line 248-2,  t829,  t342,  t339(SI24)
	c0    add $r0.4 = $r0.4, $r0.15   ## [spec] bblock 40, line 248-3,  t826,  t350,  t398(SI24)
;;								## 14
	c0    add $r0.11 = $r0.11, $r0.10   ## bblock 43, line 248-2,  t335,  t828,  t829
;;								## 15
	c0    stw 4[$r0.8] = $r0.11   ## bblock 43, line 248-2, t476, t335
	c0    mov $r0.2 = $r0.11   ## [spec] bblock 40, line 248-2,  t225,  t335
	c0    mpyl $r0.10 = $r0.11, 215   ## [spec] bblock 40, line 246-3,  t347,  t335,  215(SI32)
	c0    brf $b0.2, L67?3   ## bblock 43, line 243-3,  t830(I1)
;;								## 16
;;								## 17
	c0    shr $r0.10 = $r0.10, 8   ## bblock 40, line 246-3,  t346(SI24),  t347,  8(SI32)
;;								## 18
	c0    add $r0.12 = $r0.12, $r0.10   ## bblock 40, line 248-3,  t827,  t349,  t346(SI24)
;;								## 19
	c0    add $r0.5 = $r0.4, $r0.12   ## bblock 40, line 248-3,  t226,  t826,  t827
;;								## 20
	c0    stw 0[$r0.8] = $r0.5   ## bblock 40, line 248-3, t476, t226
	c0    add $r0.8 = $r0.8, (~0xf)   ## bblock 40, line 0,  t476,  t476,  (~0xf)(I32)
	c0    goto L63?3 ## goto
;;								## 21
.trace 26
L67?3:
	c0    sub $r0.13 = 2, $r0.25   ## bblock 17, line 0,  t423,  2(I32),  t203
	c0    mov $r0.8 = $r0.27   ## bblock 17, line 0,  t420,  t718
	c0    mov $r0.11 = $r0.28   ## bblock 17, line 0,  t419,  t717
;;								## 0
	c0    mov $r0.10 = $r0.26   ## bblock 17, line 0,  t421,  t719
	c0    goto L68?3 ## goto
;;								## 1
.trace 4
L69?3:
	c0    cmplt $b0.0 = $r0.9, 2   ## bblock 18, line 254,  t808(I1),  t422,  2(SI32)
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 20, line 256, t327, t418
	c0    mpyl $r0.5 = $r0.4, 215   ## [spec] bblock 20, line 258,  t409,  t232,  215(SI32)
	c0    mpyl $r0.6 = $r0.6, -155   ## [spec] bblock 20, line 259,  t325,  t231,  -155(SI32)
;;								## 0
	c0    mpyl $r0.7 = $r0.7, 28   ## [spec] bblock 20, line 257,  t64,  t234,  28(SI32)
	c0    ldw.d $r0.12 = 0[$r0.8]   ## [spec] bblock 20, line 264, t321, t420
	c0    cmplt $b0.1 = $r0.9, 1   ## [spec] bblock 20, line 254-1,  t811(I1),  t422,  1(SI32)
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 53, line 259-1,  t60,  t232,  -155(SI32)
;;								## 1
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 20, line 258,  t326(SI24),  t409,  8(SI32)
	c0    shr $r0.6 = $r0.6, 8   ## [spec] bblock 20, line 259,  t324(SI24),  t325,  8(SI32)
	c0    ldbu.d $r0.13 = 1[$r0.2]   ## [spec] bblock 53, line 256-1, t301, t418
	c0    brf $b0.0, L70?3   ## bblock 18, line 254,  t808(I1)
;;								## 2
	c0    mpyl $r0.14 = $r0.3, -48   ## bblock 20, line 256,  t410,  t327,  -48(SI32)
	c0    add $r0.7 = $r0.7, $r0.6   ## bblock 20, line 260,  t809,  t64,  t324(SI24)
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 53, line 257-1,  t302,  t327,  28(SI32)
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 53, line 259-1,  t62(SI24),  t60,  8(SI32)
;;								## 3
	c0    ldw.d $r0.15 = 4[$r0.8]   ## [spec] bblock 53, line 264-1, t82, t420
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## [spec] bblock 53, line 254-2,  t838(I1),  t422,  0(SI32)
	c0    add $r0.9 = $r0.9, 3   ## [spec] bblock 50, line 0,  t422,  t422,  3(I32)
;;								## 4
	c0    add $r0.14 = $r0.14, $r0.5   ## bblock 20, line 260,  t810,  t410,  t326(SI24)
	c0    mpyl $r0.5 = $r0.13, -48   ## [spec] bblock 53, line 256-1,  t65,  t301,  -48(SI32)
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 53, line 260-1,  t836,  t302,  t62(SI24)
	c0    ldbu.d $r0.16 = 2[$r0.2]   ## [spec] bblock 50, line 256-2, t234, t418
;;								## 5
	c0    add $r0.7 = $r0.7, $r0.14   ## bblock 20, line 260,  t322,  t809,  t810
	c0    mpyl $r0.13 = $r0.13, 28   ## [spec] bblock 50, line 257-2,  t304,  t301,  28(SI32)
	c0    ldw.d $r0.14 = 8[$r0.8]   ## [spec] bblock 50, line 264-2, t308, t420
	c0    add $r0.2 = $r0.2, 3   ## [spec] bblock 50, line 0,  t418,  t418,  3(I32)
;;								## 6
	c0    add $r0.12 = $r0.7, $r0.12   ## bblock 20, line 264,  t320,  t322,  t321
	c0    mpyl $r0.17 = $r0.7, 215   ## [spec] bblock 53, line 258-1,  t56,  t322,  215(SI32)
	c0    mpyl $r0.18 = $r0.7, -155   ## [spec] bblock 50, line 259-2,  t310,  t322,  -155(SI32)
	c0    add $r0.8 = $r0.8, 12   ## [spec] bblock 50, line 0,  t420,  t420,  12(I32)
;;								## 7
	c0    stw 0[$r0.11] = $r0.7   ## bblock 20, line 260, t419, t322
	c0    shl $r0.12 = $r0.12, 8   ## bblock 20, line 264,  t408,  t320,  8(I32)
	c0    mpyl $r0.19 = $r0.16, -48   ## [spec] bblock 50, line 256-2,  t403,  t234,  -48(SI32)
;;								## 8
	c0    shr $r0.12 = $r0.12, 8   ## bblock 20, line 264,  t407(SI24),  t408,  8(SI32)
	c0    shr $r0.17 = $r0.17, 8   ## [spec] bblock 53, line 258-1,  t63(SI24),  t56,  8(SI32)
	c0    shr $r0.18 = $r0.18, 8   ## [spec] bblock 50, line 259-2,  t309(SI24),  t310,  8(SI32)
	c0    mov $r0.7 = $r0.16   ## [spec] t234
;;								## 9
	c0    stw 0[$r0.10] = $r0.12   ## bblock 20, line 264, t421, t407(SI24)
	c0    add $r0.5 = $r0.5, $r0.17   ## [spec] bblock 53, line 260-1,  t837,  t65,  t63(SI24)
	c0    add $r0.13 = $r0.13, $r0.18   ## [spec] bblock 50, line 260-2,  t834,  t304,  t309(SI24)
	c0    brf $b0.1, L71?3   ## bblock 20, line 254-1,  t811(I1)
;;								## 10
	c0    add $r0.3 = $r0.3, $r0.5   ## bblock 53, line 260-1,  t299,  t836,  t837
;;								## 11
	c0    stw 4[$r0.11] = $r0.3   ## bblock 53, line 260-1, t419, t299
	c0    add $r0.15 = $r0.3, $r0.15   ## bblock 53, line 264-1,  t87,  t299,  t82
	c0    mov $r0.6 = $r0.3   ## [spec] bblock 50, line 260-1,  t231,  t299
	c0    mpyl $r0.5 = $r0.3, 215   ## [spec] bblock 50, line 258-2,  t402,  t299,  215(SI32)
;;								## 12
	c0    shl $r0.15 = $r0.15, 8   ## bblock 53, line 264-1,  t89,  t87,  8(I32)
;;								## 13
	c0    shr $r0.15 = $r0.15, 8   ## bblock 53, line 264-1,  t90(SI24),  t89,  8(SI32)
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 50, line 258-2,  t311(SI24),  t402,  8(SI32)
;;								## 14
	c0    stw 4[$r0.10] = $r0.15   ## bblock 53, line 264-1, t421, t90(SI24)
	c0    add $r0.19 = $r0.19, $r0.5   ## [spec] bblock 50, line 260-2,  t835,  t403,  t311(SI24)
	c0    brf $b0.0, L72?3   ## bblock 53, line 254-2,  t838(I1)
;;								## 15
	c0    add $r0.4 = $r0.13, $r0.19   ## bblock 50, line 260-2,  t232,  t834,  t835
;;								## 16
	c0    stw 8[$r0.11] = $r0.4   ## bblock 50, line 260-2, t419, t232
	c0    add $r0.14 = $r0.4, $r0.14   ## bblock 50, line 264-2,  t307,  t232,  t308
	c0    add $r0.11 = $r0.11, 12   ## bblock 50, line 0,  t419,  t419,  12(I32)
;;								## 17
	c0    shl $r0.14 = $r0.14, 8   ## bblock 50, line 264-2,  t306,  t307,  8(I32)
;;								## 18
	c0    shr $r0.14 = $r0.14, 8   ## bblock 50, line 264-2,  t305(SI24),  t306,  8(SI32)
;;								## 19
	c0    stw 8[$r0.10] = $r0.14   ## bblock 50, line 264-2, t421, t305(SI24)
	c0    add $r0.10 = $r0.10, 12   ## bblock 50, line 0,  t421,  t421,  12(I32)
	c0    goto L69?3 ## goto
;;								## 20
.trace 20
L72?3:
	c0    add $r0.29 = $r0.29, 1050   ## bblock 19, line 0,  t715,  t715,  1050(I32)
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.26 = $r0.26, $r0.2   ## bblock 19, line 0,  t719,  t719,  4200(I32)
	c0    add $r0.12 = $r0.21, $r0.2   ## bblock 19, line 0,  t723,  t723,  4200(I32)
	c0    add $r0.27 = $r0.27, $r0.2   ## bblock 19, line 0,  t718,  t718,  4200(I32)
	c0    add $r0.28 = $r0.28, $r0.2   ## bblock 19, line 0,  t717,  t717,  4200(I32)
	      ## goto
;;
	c0    goto L73?3 ## goto
;;								## 1
.trace 19
L71?3:
	c0    add $r0.29 = $r0.29, 1050   ## bblock 19, line 0,  t715,  t715,  1050(I32)
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.26 = $r0.26, $r0.2   ## bblock 19, line 0,  t719,  t719,  4200(I32)
	c0    add $r0.12 = $r0.21, $r0.2   ## bblock 19, line 0,  t723,  t723,  4200(I32)
	c0    add $r0.27 = $r0.27, $r0.2   ## bblock 19, line 0,  t718,  t718,  4200(I32)
	c0    add $r0.28 = $r0.28, $r0.2   ## bblock 19, line 0,  t717,  t717,  4200(I32)
	      ## goto
;;
	c0    goto L73?3 ## goto
;;								## 1
.trace 16
L70?3:
	c0    add $r0.29 = $r0.29, 1050   ## bblock 19, line 0,  t715,  t715,  1050(I32)
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.26 = $r0.26, $r0.2   ## bblock 19, line 0,  t719,  t719,  4200(I32)
	c0    add $r0.12 = $r0.21, $r0.2   ## bblock 19, line 0,  t723,  t723,  4200(I32)
	c0    add $r0.27 = $r0.27, $r0.2   ## bblock 19, line 0,  t718,  t718,  4200(I32)
	c0    add $r0.28 = $r0.28, $r0.2   ## bblock 19, line 0,  t717,  t717,  4200(I32)
;;								## 1
L73?3:
	c0    add $r0.4 = $r0.23, 1   ## bblock 19, line 0,  t725,  t725,  1(I32)
	c0    add $r0.10 = $r0.22, 1050   ## bblock 19, line 0,  t724,  t724,  1050(I32)
	c0    mov $r0.11 = $r0.20   ## t291
	      ## goto
;;
	c0    goto L61?3 ## goto
;;								## 2
.trace 24
L66?3:
	c0    sub $r0.13 = 2, $r0.25   ## bblock 17, line 0,  t423,  2(I32),  t203
	c0    mov $r0.10 = $r0.26   ## bblock 17, line 0,  t421,  t719
	c0    mov $r0.8 = $r0.27   ## bblock 17, line 0,  t420,  t718
	c0    mov $r0.11 = $r0.28   ## bblock 17, line 0,  t419,  t717
	      ## goto
;;
	c0    goto L68?3 ## goto
;;								## 0
.trace 22
L65?3:
	c0    sub $r0.13 = 2, $r0.25   ## bblock 17, line 0,  t423,  2(I32),  t203
	c0    mov $r0.10 = $r0.26   ## bblock 17, line 0,  t421,  t719
	c0    mov $r0.8 = $r0.27   ## bblock 17, line 0,  t420,  t718
	c0    mov $r0.11 = $r0.28   ## bblock 17, line 0,  t419,  t717
	      ## goto
;;
	c0    goto L68?3 ## goto
;;								## 0
.trace 14
L64?3:
	c0    sub $r0.13 = 2, $r0.25   ## bblock 17, line 0,  t423,  2(I32),  t203
	c0    mov $r0.10 = $r0.26   ## bblock 17, line 0,  t421,  t719
	c0    mov $r0.8 = $r0.27   ## bblock 17, line 0,  t420,  t718
	c0    mov $r0.11 = $r0.28   ## bblock 17, line 0,  t419,  t717
;;								## 0
L68?3:
	c0    mov $r0.9 = $r0.13   ## bblock 17, line 0,  t422,  t423
	c0    mov $r0.2 = $r0.29   ## bblock 17, line 0,  t418,  t715
	c0    mov $r0.7 = $r0.22   ## t234
	c0    mov $r0.4 = $r0.23   ## t232
;;								## 1
	c0    mov $r0.22 = $r0.19   ## t724
	c0    mov $r0.23 = $r0.18   ## t725
	c0    mov $r0.6 = $r0.24   ## t231
	c0    goto L69?3 ## goto
;;								## 2
.trace 28
L62?3:
	c0    add $r0.10 = $r0.30, -1   ## bblock 2, line 270,  t292,  t202,  -1(SI32)
	c0    sub $r0.25 = $r0.0, $r0.25   ## bblock 2, line 0,  t665,  0(I32),  t203
	c0    mov $r0.28 = (qt + 0)   ## bblock 2, line 0,  t655,  addr(qt?1.0)(P32)
;;								## 0
	c0    mov $r0.4 = $r0.25   ## bblock 2, line 0,  t664,  t665
	c0    mov $r0.27 = (qy1 + 0)   ## bblock 2, line 0,  t656,  addr(qy1?1.0)(P32)
	c0    mov $r0.24 = $r0.30   ## t202
;;								## 1
	c0    mov $r0.25 = (out + 0)   ## bblock 2, line 0,  t658,  addr(out?1.0)(P32)
	c0    mov $r0.26 = (qy2 + 0)   ## bblock 2, line 0,  t657,  addr(qy2?1.0)(P32)
;;								## 2
	c0    mov $r0.13 = ((qy2 + 0) + (~0x3137))   ## bblock 2, line 0,  t662,  (addr(qy2?1.0)(P32) + 0xffffcec8(I32))(P32)
	c0    mov $r0.12 = ((qt + 0) + (~0x3137))   ## bblock 2, line 0,  t663,  (addr(qt?1.0)(P32) + 0xffffcec8(I32))(P32)
;;								## 3
.trace 12
L74?3:
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 3, line 268,  t797(I1),  t664,  0(SI32)
	c0    mpylu $r0.11 = $r0.10, 4200   ## [spec] bblock 5, line 0,  t598,  t292,  4200(I32)
	c0    mov $r0.3 = $r0.0   ## [spec] bblock 5, line 269,  t228,  0(SI32)
;;								## 0
	c0    mov $r0.21 = $r0.0   ## [spec] bblock 5, line 269,  t289(SI24),  0(SI32)
	c0    mov $r0.6 = $r0.0   ## [spec] bblock 5, line 269,  t331,  0(SI32)
	c0    mov $r0.5 = $r0.0   ## [spec] bblock 5, line 269,  t286(SI24),  0(SI32)
	c0    mov $r0.2 = $r0.0   ## [spec] bblock 5, line 269,  t330,  0(SI32)
;;								## 1
	c0    add $r0.9 = $r0.12, $r0.11   ## [spec] bblock 5, line 0,  t588,  t663,  t598
	c0    mov $r0.22 = $r0.0   ## [spec] bblock 5, line 269,  t287,  0(SI32)
	c0    add $r0.8 = $r0.13, $r0.11   ## [spec] bblock 5, line 0,  t587,  t662,  t598
	c0    brf $b0.0, L75?3   ## bblock 3, line 268,  t797(I1)
;;								## 2
	c0    mov $r0.23 = $r0.0   ## bblock 5, line 269,  t233,  0(SI32)
	c0    mov $r0.7 = $r0.10   ## bblock 5, line 270,  t288,  t292
	c0    mov $r0.17 = $r0.4   ## t664
	c0    mov $r0.18 = $r0.10   ## t292
;;								## 3
	c0    mov $r0.19 = $r0.12   ## t663
	c0    mov $r0.20 = $r0.13   ## t662
;;								## 4
.trace 1
L76?3:
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## bblock 6, line 270,  t798(I1),  t288,  0(SI32)
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 14, line 271,  t354,  t330,  -155(SI32)
	c0    mpyl $r0.4 = $r0.3, -47   ## [spec] bblock 14, line 271,  t401,  t228,  -47(SI32)
	c0    cmpge $b0.1 = $r0.7, 1   ## [spec] bblock 14, line 270-1,  t806(I1),  t288,  1(SI32)
;;								## 0
	c0    mpyl $r0.10 = $r0.5, 215   ## [spec] bblock 14, line 271,  t333,  t286(SI24),  215(SI32)
	c0    mpyl $r0.6 = $r0.6, 29   ## [spec] bblock 14, line 271,  t111,  t331,  29(SI32)
	c0    ldw.d $r0.11 = 12600[$r0.9]   ## [spec] bblock 14, line 273, t351, t588
;;								## 1
	c0    add $r0.2 = $r0.2, $r0.4   ## [spec] bblock 14, line 271,  t804,  t354,  t401
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 29, line 271-1,  t362,  t286(SI24),  -155(SI32)
	c0    mpyl $r0.3 = $r0.3, 29   ## [spec] bblock 29, line 271-1,  t360,  t228,  29(SI32)
	c0    brf $b0.0, L77?3   ## bblock 6, line 270,  t798(I1)
;;								## 2
	c0    add $r0.10 = $r0.10, $r0.6   ## bblock 14, line 271,  t805,  t333,  t111
	c0    ldw.d $r0.4 = 8400[$r0.9]   ## [spec] bblock 29, line 273-1, t356, t588
	c0    cmpge $b0.0 = $r0.7, 2   ## [spec] bblock 29, line 270-2,  t822(I1),  t288,  2(SI32)
;;								## 3
	c0    add $r0.2 = $r0.2, $r0.10   ## bblock 14, line 271,  t400,  t804,  t805
	c0    mpyl $r0.10 = $r0.11, -47   ## [spec] bblock 29, line 271-1,  t114,  t351,  -47(SI32)
	c0    mpyl $r0.11 = $r0.11, 29   ## [spec] bblock 26, line 271-2,  t369,  t351,  29(SI32)
	c0    cmpge $b0.2 = $r0.7, 3   ## [spec] bblock 26, line 270-3,  t819(I1),  t288,  3(SI32)
;;								## 4
	c0    shr $r0.2 = $r0.2, 8   ## bblock 14, line 271,  t792,  t400,  8(SI32)
	c0    ldw.d $r0.12 = 4200[$r0.9]   ## [spec] bblock 26, line 273-2, t363, t588
	c0    add $r0.7 = $r0.7, -4   ## [spec] bblock 23, line 270-3,  t288,  t288,  -4(SI32)
;;								## 5
	c0    mpyl $r0.10 = $r0.2, 215   ## [spec] bblock 29, line 271-1,  t359,  t792,  215(SI32)
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 29, line 271-1,  t820,  t362,  t114
	c0    mpyl $r0.13 = $r0.2, -155   ## [spec] bblock 26, line 271-2,  t105,  t792,  -155(SI32)
	c0    ldw.d $r0.14 = 0[$r0.9]   ## [spec] bblock 23, line 273-3, t228, t588
;;								## 6
	c0    mpyl $r0.15 = $r0.4, -47   ## [spec] bblock 26, line 271-2,  t392,  t356,  -47(SI32)
	c0    mpyl $r0.4 = $r0.4, 29   ## [spec] bblock 23, line 271-3,  t383,  t356,  29(SI32)
	c0    add $r0.9 = $r0.9, (~0x419f)   ## [spec] bblock 23, line 0,  t588,  t588,  (~0x419f)(I32)
;;								## 7
	c0    add $r0.10 = $r0.10, $r0.3   ## [spec] bblock 29, line 271-1,  t821,  t359,  t360
	c0    mov $r0.6 = $r0.12   ## [spec] bblock 23, line 273-2,  t331,  t363
	c0    mpyl $r0.16 = $r0.12, -47   ## [spec] bblock 23, line 271-3,  t382,  t363,  -47(SI32)
;;								## 8
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 29, line 271-1,  t389,  t820,  t821
	c0    add $r0.13 = $r0.13, $r0.15   ## [spec] bblock 26, line 271-2,  t817,  t105,  t392
	c0    mov $r0.3 = $r0.14   ## [spec] t228
;;								## 9
	c0    stw 12600[$r0.8] = $r0.2   ## bblock 14, line 271, t587, t792
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 29, line 271-1,  t793,  t389,  8(SI32)
	c0    brf $b0.1, L78?3   ## bblock 14, line 270-1,  t806(I1)
;;								## 10
	c0    stw 8400[$r0.8] = $r0.5   ## bblock 29, line 271-1, t587, t793
	c0    mpyl $r0.10 = $r0.5, 215   ## [spec] bblock 26, line 271-2,  t108,  t793,  215(SI32)
	c0    mpyl $r0.12 = $r0.5, -155   ## [spec] bblock 23, line 271-3,  t385,  t793,  -155(SI32)
;;								## 11
	c0    brf $b0.0, L79?3   ## bblock 29, line 270-2,  t822(I1)
;;								## 12
	c0    add $r0.10 = $r0.10, $r0.11   ## bblock 26, line 271-2,  t818,  t108,  t369
	c0    add $r0.12 = $r0.12, $r0.16   ## [spec] bblock 23, line 271-3,  t815,  t385,  t382
;;								## 13
	c0    add $r0.13 = $r0.13, $r0.10   ## bblock 26, line 271-2,  t391,  t817,  t818
;;								## 14
	c0    shr $r0.13 = $r0.13, 8   ## bblock 26, line 271-2,  t794,  t391,  8(SI32)
;;								## 15
	c0    stw 4200[$r0.8] = $r0.13   ## bblock 26, line 271-2, t587, t794
	c0    mov $r0.2 = $r0.13   ## [spec] bblock 23, line 271-2,  t330,  t794
	c0    mpyl $r0.10 = $r0.13, 215   ## [spec] bblock 23, line 271-3,  t384,  t794,  215(SI32)
;;								## 16
	c0    brf $b0.2, L80?3   ## bblock 26, line 270-3,  t819(I1)
;;								## 17
	c0    add $r0.10 = $r0.10, $r0.4   ## bblock 23, line 271-3,  t816,  t384,  t383
;;								## 18
	c0    add $r0.12 = $r0.12, $r0.10   ## bblock 23, line 271-3,  t115,  t815,  t816
;;								## 19
	c0    shr $r0.5 = $r0.12, 8   ## bblock 23, line 271-3,  t286(SI24),  t115,  8(SI32)
;;								## 20
	c0    stw 0[$r0.8] = $r0.5   ## bblock 23, line 271-3, t587, t286(SI24)
	c0    add $r0.8 = $r0.8, (~0x419f)   ## bblock 23, line 0,  t587,  t587,  (~0x419f)(I32)
	c0    goto L76?3 ## goto
;;								## 21
.trace 25
L80?3:
	c0    sub $r0.6 = 1, $r0.24   ## bblock 7, line 0,  t523,  1(I32),  t202
	c0    mov $r0.10 = $r0.25   ## bblock 7, line 0,  t521,  t658
	c0    mov $r0.8 = $r0.26   ## bblock 7, line 0,  t520,  t657
	c0    mov $r0.2 = $r0.28   ## bblock 7, line 0,  t518,  t655
	      ## goto
;;
	c0    goto L81?3 ## goto
;;								## 0
.trace 3
L82?3:
	c0    cmplt $b0.0 = $r0.9, 1   ## bblock 8, line 277,  t799(I1),  t522,  1(SI32)
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 10, line 278,  t381,  t287,  -155(SI32)
	c0    mpyl $r0.6 = $r0.5, 215   ## [spec] bblock 10, line 278,  t396,  t289(SI24),  215(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 10, line 278, t377, t518
;;								## 0
	c0    mpyl $r0.7 = $r0.7, 28   ## [spec] bblock 10, line 278,  t395,  t233,  28(SI32)
	c0    ldw.d $r0.13 = 0[$r0.8]   ## [spec] bblock 10, line 282, t375, t520
	c0    cmplt $b0.1 = $r0.9, $r0.0   ## [spec] bblock 12, line 277-1,  t803(I1),  t522,  0(SI32)
	c0    mpyl $r0.14 = $r0.5, -155   ## [spec] bblock 33, line 278-1,  t136,  t289(SI24),  -155(SI32)
;;								## 1
	c0    ldw.d $r0.15 = 4200[$r0.2]   ## [spec] bblock 33, line 278-1, t233, t518
	c0    brf $b0.0, L83?3   ## bblock 8, line 277,  t799(I1)
;;								## 2
	c0    mpyl $r0.16 = $r0.3, -48   ## bblock 10, line 278,  t376,  t377,  -48(SI32)
	c0    add $r0.6 = $r0.6, $r0.7   ## bblock 10, line 278,  t801,  t396,  t395
	c0    mpyl $r0.17 = $r0.3, 28   ## [spec] bblock 33, line 278-1,  t142,  t377,  28(SI32)
;;								## 3
	c0    ldw.d $r0.18 = 4200[$r0.8]   ## [spec] bblock 33, line 282-1, t166, t520
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.16   ## bblock 10, line 278,  t800,  t381,  t376
	c0    mpyl $r0.19 = $r0.15, -48   ## [spec] bblock 33, line 278-1,  t148,  t233,  -48(SI32)
	c0    mov $r0.7 = $r0.15   ## [spec] t233
;;								## 5
	c0    add $r0.4 = $r0.4, $r0.6   ## bblock 10, line 278,  t394,  t800,  t801
;;								## 6
	c0    shr $r0.4 = $r0.4, 8   ## bblock 10, line 278,  t393(SI24),  t394,  8(SI32)
	c0    add $r0.14 = $r0.14, $r0.19   ## [spec] bblock 33, line 278-1,  t823,  t136,  t148
;;								## 7
	c0    stw 0[$r0.11] = $r0.4   ## bblock 10, line 278, t519, t393(SI24)
	c0    add $r0.13 = $r0.4, $r0.13   ## bblock 10, line 282,  t374,  t393(SI24),  t375
	c0    mov $r0.15 = $r0.4   ## [spec] bblock 33, line 278-1,  t287,  t393(SI24)
	c0    mpyl $r0.6 = $r0.4, 215   ## [spec] bblock 33, line 278-1,  t139,  t393(SI24),  215(SI32)
;;								## 8
	c0    shl $r0.13 = $r0.13, 8   ## bblock 10, line 282,  t373,  t374,  8(I32)
	c0    mov $r0.16 = $r0.4   ## t393(SI24)
;;								## 9
	c0    shr $r0.13 = $r0.13, 16   ## bblock 10, line 282,  t372(SI16),  t373,  16(SI32)
	c0    add $r0.6 = $r0.6, $r0.17   ## [spec] bblock 33, line 278-1,  t824,  t139,  t142
	c0    mov $r0.4 = $r0.15   ## [spec] t287
;;								## 10
	c0    zxtb $r0.15 = $r0.13   ## bblock 10, line 282,  t371(I8),  t372(SI16)
	c0    stb 0[$r0.10] = $r0.13   ## bblock 10, line 282, t521, t372(SI16)
	c0    add $r0.14 = $r0.14, $r0.6   ## [spec] bblock 33, line 278-1,  t149,  t823,  t824
;;								## 11
	c0    cmpgt $b0.0 = $r0.15, 25   ## bblock 10, line 283,  t802(I1),  t371(I8),  25(SI32)
	      xnop 1
;;								## 13
	c0    brf $b0.0, L84?3   ## bblock 10, line 283,  t802(I1)
;;								## 14
	c0    stb 0[$r0.10] = $r0.0   ## bblock 13, line 284, t521, 0(I32)
	c0    shr $r0.5 = $r0.14, 8   ## [spec] bblock 33, line 278-1,  t289(SI24),  t149,  8(SI32)
	c0    brf $b0.1, L85?3   ## bblock 12, line 277-1,  t803(I1)
;;								## 15
L86?3:
	c0    stw 4200[$r0.11] = $r0.5   ## bblock 33, line 278-1, t519, t289(SI24)
	c0    add $r0.18 = $r0.5, $r0.18   ## bblock 33, line 282-1,  t171,  t289(SI24),  t166
;;								## 16
	c0    shl $r0.18 = $r0.18, 8   ## bblock 33, line 282-1,  t173,  t171,  8(I32)
;;								## 17
	c0    shr $r0.18 = $r0.18, 16   ## bblock 33, line 282-1,  t174(SI16),  t173,  16(SI32)
;;								## 18
	c0    zxtb $r0.3 = $r0.18   ## bblock 33, line 282-1,  t182(I8),  t174(SI16)
	c0    stb 1050[$r0.10] = $r0.18   ## bblock 33, line 282-1, t521, t174(SI16)
;;								## 19
	c0    cmpgt $b0.0 = $r0.3, 25   ## bblock 33, line 283-1,  t825(I1),  t182(I8),  25(SI32)
	      xnop 1
;;								## 21
	c0    brf $b0.0, L87?3   ## bblock 33, line 283-1,  t825(I1)
;;								## 22
	c0    add $r0.9 = $r0.9, 2   ## bblock 35, line 0,  t522,  t522,  2(I32)
	c0    add $r0.8 = $r0.8, $r0.12   ## bblock 35, line 0,  t520,  t520,  8400(I32)
	c0    add $r0.11 = $r0.11, $r0.12   ## bblock 35, line 0,  t519,  t519,  8400(I32)
	c0    add $r0.2 = $r0.2, $r0.12   ## bblock 35, line 0,  t518,  t518,  8400(I32)
;;								## 23
	c0    stb 1050[$r0.10] = $r0.0   ## bblock 36, line 284-1, t521, 0(I32)
;;								## 24
L88?3:
	c0    add $r0.10 = $r0.10, 2100   ## bblock 35, line 0,  t521,  t521,  2100(I32)
	c0    goto L82?3 ## goto
;;								## 25
.trace 10
L87?3:
	c0    add $r0.9 = $r0.9, 2   ## bblock 35, line 0,  t522,  t522,  2(I32)
	c0    add $r0.8 = $r0.8, $r0.12   ## bblock 35, line 0,  t520,  t520,  8400(I32)
	c0    add $r0.11 = $r0.11, $r0.12   ## bblock 35, line 0,  t519,  t519,  8400(I32)
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 1050[$r0.10] = $r0.3   ## bblock 34, line 286-1, t521, 255(I32)
	c0    add $r0.2 = $r0.2, $r0.12   ## bblock 35, line 0,  t518,  t518,  8400(I32)
	c0    goto L88?3 ## goto
;;								## 1
.trace 17
L85?3:
	c0    add $r0.4 = $r0.23, 1   ## bblock 9, line 0,  t664,  t664,  1(I32)
	c0    add $r0.25 = $r0.25, 1   ## bblock 9, line 0,  t658,  t658,  1(I32)
	c0    add $r0.13 = $r0.21, 4   ## bblock 9, line 0,  t662,  t662,  4(I32)
	c0    add $r0.26 = $r0.26, 4   ## bblock 9, line 0,  t657,  t657,  4(I32)
;;								## 0
	c0    add $r0.27 = $r0.27, 4   ## bblock 9, line 0,  t656,  t656,  4(I32)
	c0    add $r0.12 = $r0.22, 4   ## bblock 9, line 0,  t663,  t663,  4(I32)
	c0    add $r0.28 = $r0.28, 4   ## bblock 9, line 0,  t655,  t655,  4(I32)
	c0    mov $r0.10 = $r0.20   ## t292
	      ## goto
;;
	c0    goto L74?3 ## goto
;;								## 1
.trace 9
L84?3:
	c0    shr $r0.5 = $r0.14, 8   ## [spec] bblock 33, line 278-1,  t289(SI24),  t149,  8(SI32)
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 0[$r0.10] = $r0.3   ## bblock 11, line 286, t521, 255(I32)
	c0    brf $b0.1, L85?3   ## bblock 12, line 277-1,  t803(I1)
	      ## goto
;;
	c0    goto L86?3 ## goto
;;								## 1
.trace 15
L83?3:
	c0    add $r0.25 = $r0.25, 1   ## bblock 9, line 0,  t658,  t658,  1(I32)
	c0    add $r0.26 = $r0.26, 4   ## bblock 9, line 0,  t657,  t657,  4(I32)
	c0    add $r0.27 = $r0.27, 4   ## bblock 9, line 0,  t656,  t656,  4(I32)
	c0    add $r0.28 = $r0.28, 4   ## bblock 9, line 0,  t655,  t655,  4(I32)
;;								## 0
	c0    add $r0.4 = $r0.23, 1   ## bblock 9, line 0,  t664,  t664,  1(I32)
	c0    add $r0.13 = $r0.21, 4   ## bblock 9, line 0,  t662,  t662,  4(I32)
	c0    add $r0.12 = $r0.22, 4   ## bblock 9, line 0,  t663,  t663,  4(I32)
	c0    mov $r0.10 = $r0.20   ## t292
	      ## goto
;;
	c0    goto L74?3 ## goto
;;								## 1
.trace 23
L79?3:
	c0    sub $r0.6 = 1, $r0.24   ## bblock 7, line 0,  t523,  1(I32),  t202
	c0    mov $r0.10 = $r0.25   ## bblock 7, line 0,  t521,  t658
	c0    mov $r0.8 = $r0.26   ## bblock 7, line 0,  t520,  t657
	c0    mov $r0.2 = $r0.28   ## bblock 7, line 0,  t518,  t655
	      ## goto
;;
	c0    goto L81?3 ## goto
;;								## 0
.trace 21
L78?3:
	c0    sub $r0.6 = 1, $r0.24   ## bblock 7, line 0,  t523,  1(I32),  t202
	c0    mov $r0.10 = $r0.25   ## bblock 7, line 0,  t521,  t658
	c0    mov $r0.8 = $r0.26   ## bblock 7, line 0,  t520,  t657
	c0    mov $r0.2 = $r0.28   ## bblock 7, line 0,  t518,  t655
	      ## goto
;;
	c0    goto L81?3 ## goto
;;								## 0
.trace 13
L77?3:
	c0    sub $r0.6 = 1, $r0.24   ## bblock 7, line 0,  t523,  1(I32),  t202
	c0    mov $r0.10 = $r0.25   ## bblock 7, line 0,  t521,  t658
	c0    mov $r0.8 = $r0.26   ## bblock 7, line 0,  t520,  t657
	c0    mov $r0.2 = $r0.28   ## bblock 7, line 0,  t518,  t655
;;								## 0
L81?3:
	c0    mov $r0.9 = $r0.6   ## bblock 7, line 0,  t522,  t523
	c0    mov $r0.11 = $r0.27   ## bblock 7, line 0,  t519,  t656
	c0    mov $r0.4 = $r0.22   ## t287
	c0    mov $r0.5 = $r0.21   ## t289(SI24)
;;								## 1
	c0    mov $r0.21 = $r0.20   ## t662
	c0    mov $r0.7 = $r0.23   ## t233
	c0    mov $r0.12 = 8400   ## 8400(I32)
;;								## 2
	c0    mov $r0.20 = $r0.18   ## t292
	c0    mov $r0.22 = $r0.19   ## t663
	c0    mov $r0.23 = $r0.17   ## t664
	c0    goto L82?3 ## goto
;;								## 3
.trace 29
L75?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 4, line 290,  t190,  ?2.3?2auto_size(I32),  t189
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.3?2auto_size, 0x0
 ## End deriche_fused
 ## Begin deriche_slow
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_slow::
.trace 50
	      ## auto_size == 0
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t1117,  0(I32),  t226
	c0    mov $r0.5 = $r0.4   ## t227
;;								## 0
	c0    mov $r0.11 = (qy1 + 0)   ## bblock 0, line 0,  t1115,  addr(qy1?1.0)(P32)
	c0    mov $r0.12 = (in + 0)   ## bblock 0, line 0,  t1113,  addr(in?1.0)(P32)
;;								## 1
	c0    mov $r0.3 = $r0.2   ## bblock 0, line 0,  t1116,  t1117
	c0    mov $r0.20 = $r0.3   ## t226
;;								## 2
;;								## 3
.trace 17
L89?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 1, line 313,  t1162(I1),  t1116,  0(SI32)
	c0    sub $r0.10 = 3, $r0.5   ## [spec] bblock 36, line 0,  t519,  3(I32),  t227
	c0    mov $r0.6 = $r0.0   ## [spec] bblock 36, line 314,  t255,  0(SI32)
	c0    mov $r0.9 = $r0.11   ## [spec] bblock 36, line 0,  t517,  t1115
;;								## 0
	c0    mov $r0.8 = $r0.10   ## [spec] bblock 36, line 0,  t518,  t519
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 36, line 314,  t256,  0(SI32)
	c0    mov $r0.7 = $r0.0   ## [spec] bblock 36, line 314,  t258,  0(SI32)
	c0    mov $r0.2 = $r0.12   ## [spec] bblock 36, line 0,  t516,  t1113
;;								## 1
	c0    mov $r0.16 = $r0.3   ## t1116
	c0    mov $r0.17 = $r0.5   ## t227
	c0    mov $r0.18 = $r0.11   ## t1115
	c0    brf $b0.0, L90?3   ## bblock 1, line 313,  t1162(I1)
;;								## 2
	c0    mov $r0.19 = $r0.12   ## t1113
;;								## 3
.trace 3
L91?3:
	c0    cmplt $b0.0 = $r0.8, 3   ## bblock 37, line 315,  t1185(I1),  t518,  3(SI32)
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 39, line 317, t342, t516
	c0    mpyl $r0.5 = $r0.4, 215   ## [spec] bblock 39, line 319,  t19,  t256,  215(SI32)
	c0    mpyl $r0.6 = $r0.6, -155   ## [spec] bblock 39, line 320,  t23,  t255,  -155(SI32)
;;								## 0
	c0    mpyl $r0.7 = $r0.7, 28   ## [spec] bblock 39, line 318,  t27,  t258,  28(SI32)
	c0    cmplt $b0.1 = $r0.8, 2   ## [spec] bblock 39, line 315-1,  t1188(I1),  t518,  2(SI32)
	c0    ldbu.d $r0.10 = 1[$r0.2]   ## [spec] bblock 106, line 317-1, t500, t516
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 106, line 320-1,  t504,  t256,  -155(SI32)
;;								## 1
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 39, line 319,  t26(SI24),  t19,  8(SI32)
	c0    shr $r0.6 = $r0.6, 8   ## [spec] bblock 39, line 320,  t25(SI24),  t23,  8(SI32)
	c0    cmplt $b0.0 = $r0.8, 1   ## [spec] bblock 106, line 315-2,  t1227(I1),  t518,  1(SI32)
	c0    brf $b0.0, L92?3   ## bblock 37, line 315,  t1185(I1)
;;								## 2
	c0    mpyl $r0.11 = $r0.3, -48   ## bblock 39, line 317,  t28,  t342,  -48(SI32)
	c0    add $r0.7 = $r0.7, $r0.6   ## bblock 39, line 321,  t1186,  t27,  t25(SI24)
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 106, line 318-1,  t499,  t342,  28(SI32)
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 106, line 320-1,  t505(SI24),  t504,  8(SI32)
;;								## 3
	c0    mpyl $r0.12 = $r0.10, -48   ## [spec] bblock 106, line 317-1,  t501,  t500,  -48(SI32)
	c0    mpyl $r0.10 = $r0.10, 28   ## [spec] bblock 103, line 318-2,  t488,  t500,  28(SI32)
	c0    ldbu.d $r0.13 = 2[$r0.2]   ## [spec] bblock 103, line 317-2, t489, t516
	c0    cmplt $b0.2 = $r0.8, $r0.0   ## [spec] bblock 103, line 315-3,  t1224(I1),  t518,  0(SI32)
;;								## 4
	c0    add $r0.11 = $r0.11, $r0.5   ## bblock 39, line 321,  t1187,  t28,  t26(SI24)
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 106, line 321-1,  t1225,  t499,  t505(SI24)
	c0    ldbu.d $r0.5 = 3[$r0.2]   ## [spec] bblock 100, line 317-3, t258, t516
	c0    add $r0.2 = $r0.2, 4   ## [spec] bblock 100, line 0,  t516,  t516,  4(I32)
;;								## 5
	c0    add $r0.7 = $r0.7, $r0.11   ## bblock 39, line 321,  t341,  t1186,  t1187
	c0    add $r0.8 = $r0.8, 4   ## [spec] bblock 100, line 0,  t518,  t518,  4(I32)
;;								## 6
	c0    stw 0[$r0.9] = $r0.7   ## bblock 39, line 321, t517, t341
	c0    mpyl $r0.11 = $r0.7, 215   ## [spec] bblock 106, line 319-1,  t502,  t341,  215(SI32)
	c0    mpyl $r0.14 = $r0.13, -48   ## [spec] bblock 103, line 317-2,  t490,  t489,  -48(SI32)
	c0    brf $b0.1, L93?3   ## bblock 39, line 315-1,  t1188(I1)
;;								## 7
	c0    mpyl $r0.7 = $r0.7, -155   ## [spec] bblock 103, line 320-2,  t493,  t341,  -155(SI32)
	c0    mpyl $r0.15 = $r0.5, -48   ## [spec] bblock 100, line 317-3,  t482,  t258,  -48(SI32)
;;								## 8
	c0    shr $r0.11 = $r0.11, 8   ## bblock 106, line 319-1,  t503(SI24),  t502,  8(SI32)
	c0    mpyl $r0.13 = $r0.13, 28   ## [spec] bblock 100, line 318-3,  t453,  t489,  28(SI32)
;;								## 9
	c0    add $r0.12 = $r0.12, $r0.11   ## bblock 106, line 321-1,  t1226,  t501,  t503(SI24)
	c0    shr $r0.7 = $r0.7, 8   ## [spec] bblock 103, line 320-2,  t494(SI24),  t493,  8(SI32)
;;								## 10
	c0    add $r0.3 = $r0.3, $r0.12   ## bblock 106, line 321-1,  t507,  t1225,  t1226
	c0    add $r0.10 = $r0.10, $r0.7   ## [spec] bblock 103, line 321-2,  t1222,  t488,  t494(SI24)
	c0    mov $r0.7 = $r0.5   ## [spec] t258
;;								## 11
	c0    stw 4[$r0.9] = $r0.3   ## bblock 106, line 321-1, t517, t507
	c0    mpyl $r0.5 = $r0.3, 215   ## [spec] bblock 103, line 319-2,  t491,  t507,  215(SI32)
	c0    mpyl $r0.11 = $r0.3, -155   ## [spec] bblock 100, line 320-3,  t485,  t507,  -155(SI32)
	c0    brf $b0.0, L94?3   ## bblock 106, line 315-2,  t1227(I1)
;;								## 12
;;								## 13
	c0    shr $r0.5 = $r0.5, 8   ## bblock 103, line 319-2,  t492(SI24),  t491,  8(SI32)
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 100, line 320-3,  t486(SI24),  t485,  8(SI32)
;;								## 14
	c0    add $r0.14 = $r0.14, $r0.5   ## bblock 103, line 321-2,  t1223,  t490,  t492(SI24)
	c0    add $r0.13 = $r0.13, $r0.11   ## [spec] bblock 100, line 321-3,  t1220,  t453,  t486(SI24)
;;								## 15
	c0    add $r0.10 = $r0.10, $r0.14   ## bblock 103, line 321-2,  t496,  t1222,  t1223
;;								## 16
	c0    stw 8[$r0.9] = $r0.10   ## bblock 103, line 321-2, t517, t496
	c0    mov $r0.6 = $r0.10   ## [spec] bblock 100, line 321-2,  t255,  t496
	c0    mpyl $r0.3 = $r0.10, 215   ## [spec] bblock 100, line 319-3,  t483,  t496,  215(SI32)
	c0    brf $b0.2, L95?3   ## bblock 103, line 315-3,  t1224(I1)
;;								## 17
;;								## 18
	c0    shr $r0.3 = $r0.3, 8   ## bblock 100, line 319-3,  t484(SI24),  t483,  8(SI32)
;;								## 19
	c0    add $r0.15 = $r0.15, $r0.3   ## bblock 100, line 321-3,  t1221,  t482,  t484(SI24)
;;								## 20
	c0    add $r0.4 = $r0.13, $r0.15   ## bblock 100, line 321-3,  t256,  t1220,  t1221
;;								## 21
	c0    stw 12[$r0.9] = $r0.4   ## bblock 100, line 321-3, t517, t256
	c0    add $r0.9 = $r0.9, 16   ## bblock 100, line 0,  t517,  t517,  16(I32)
	c0    goto L91?3 ## goto
;;								## 22
.trace 42
L95?3:
	c0    add $r0.11 = $r0.18, 4200   ## bblock 38, line 0,  t1115,  t1115,  4200(I32)
	c0    add $r0.12 = $r0.19, 1050   ## bblock 38, line 0,  t1113,  t1113,  1050(I32)
	      ## goto
;;
	c0    goto L96?3 ## goto
;;								## 0
.trace 37
L94?3:
	c0    add $r0.12 = $r0.19, 1050   ## bblock 38, line 0,  t1113,  t1113,  1050(I32)
;;								## 0
	c0    add $r0.11 = $r0.18, 4200   ## bblock 38, line 0,  t1115,  t1115,  4200(I32)
	c0    goto L96?3 ## goto
;;								## 1
.trace 30
L93?3:
	c0    add $r0.12 = $r0.19, 1050   ## bblock 38, line 0,  t1113,  t1113,  1050(I32)
;;								## 0
	c0    add $r0.11 = $r0.18, 4200   ## bblock 38, line 0,  t1115,  t1115,  4200(I32)
	c0    goto L96?3 ## goto
;;								## 1
.trace 25
L92?3:
	c0    add $r0.11 = $r0.18, 4200   ## bblock 38, line 0,  t1115,  t1115,  4200(I32)
	c0    add $r0.12 = $r0.19, 1050   ## bblock 38, line 0,  t1113,  t1113,  1050(I32)
;;								## 0
L96?3:
	c0    add $r0.3 = $r0.16, 1   ## bblock 38, line 0,  t1116,  t1116,  1(I32)
	c0    mov $r0.5 = $r0.17   ## t227
	c0    goto L89?3 ## goto
;;								## 1
.trace 51
L90?3:
	c0    add $r0.11 = $r0.17, -1   ## bblock 2, line 336,  t321,  t227,  -1(SI32)
	c0    sub $r0.2 = $r0.0, $r0.20   ## bblock 2, line 0,  t1074,  0(I32),  t226
	c0    mov $r0.12 = ((qy2 + 0) + (~0xb))   ## bblock 2, line 0,  t1071,  (addr(qy2?1.0)(P32) + 0xfffffff4(I32))(P32)
;;								## 0
	c0    mov $r0.4 = $r0.2   ## bblock 2, line 0,  t1073,  t1074
	c0    mov $r0.10 = ((in + 0) + (~0x2))   ## bblock 2, line 0,  t1072,  (addr(in?1.0)(P32) + 0xfffffffd(I32))(P32)
	c0    mov $r0.22 = $r0.20   ## t226
;;								## 1
	c0    mov $r0.23 = $r0.17   ## t227
;;								## 2
.trace 18
L97?3:
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 3, line 334,  t1163(I1),  t1073,  0(SI32)
	c0    add $r0.9 = $r0.10, $r0.11   ## [spec] bblock 32, line 0,  t566,  t1072,  t321
	c0    mov $r0.2 = $r0.0   ## [spec] bblock 32, line 335,  t344,  0(SI32)
	c0    sh2add $r0.8 = $r0.11, $r0.12   ## [spec] bblock 32, line 0,  t565,  t321,  t1071
;;								## 0
	c0    mov $r0.5 = $r0.0   ## [spec] bblock 32, line 335,  t336,  0(SI32)
	c0    mov $r0.3 = $r0.0   ## [spec] bblock 32, line 335,  t334,  0(SI32)
	c0    mov $r0.6 = $r0.0   ## [spec] bblock 32, line 335,  t340,  0(SI32)
	c0    mov $r0.7 = $r0.11   ## [spec] bblock 32, line 336,  t333,  t321
;;								## 1
	c0    mov $r0.18 = $r0.4   ## t1073
	c0    mov $r0.19 = $r0.10   ## t1072
	c0    mov $r0.20 = $r0.11   ## t321
	c0    brf $b0.0, L98?3   ## bblock 3, line 334,  t1163(I1)
;;								## 2
	c0    mov $r0.21 = $r0.12   ## t1071
;;								## 3
.trace 2
L99?3:
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## bblock 33, line 336,  t1181(I1),  t333,  0(SI32)
	c0    mpyl $r0.4 = $r0.3, -47   ## [spec] bblock 35, line 337,  t368,  t334,  -47(SI32)
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 35, line 340,  t476,  t344,  -155(SI32)
	c0    ldbu.d $r0.10 = 3[$r0.9]   ## [spec] bblock 35, line 343, t361, t566
;;								## 0
	c0    mpyl $r0.6 = $r0.6, -48   ## [spec] bblock 35, line 338,  t346,  t340,  -48(SI32)
	c0    mpyl $r0.11 = $r0.5, 215   ## [spec] bblock 35, line 339,  t364,  t336,  215(SI32)
	c0    cmpge $b0.1 = $r0.7, 1   ## [spec] bblock 35, line 336-1,  t1184(I1),  t333,  1(SI32)
	c0    ldbu.d $r0.12 = 2[$r0.9]   ## [spec] bblock 96, line 343-1, t254, t566
;;								## 1
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 35, line 340,  t475(SI24),  t476,  8(SI32)
	c0    mpyl $r0.3 = $r0.3, -48   ## [spec] bblock 96, line 338-1,  t67,  t334,  -48(SI32)
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 96, line 340-1,  t477,  t336,  -155(SI32)
	c0    brf $b0.0, L100?3   ## bblock 33, line 336,  t1181(I1)
;;								## 2
	c0    shr $r0.11 = $r0.11, 8   ## bblock 35, line 339,  t367(SI24),  t364,  8(SI32)
	c0    add $r0.4 = $r0.4, $r0.2   ## bblock 35, line 341,  t1182,  t368,  t475(SI24)
	c0    mpyl $r0.13 = $r0.10, -47   ## [spec] bblock 96, line 337-1,  t68,  t361,  -47(SI32)
	c0    cmpge $b0.0 = $r0.7, 2   ## [spec] bblock 96, line 336-2,  t1219(I1),  t333,  2(SI32)
;;								## 3
	c0    add $r0.6 = $r0.6, $r0.11   ## bblock 35, line 341,  t1183,  t346,  t367(SI24)
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 96, line 340-1,  t65(SI24),  t477,  8(SI32)
	c0    mpyl $r0.11 = $r0.12, -47   ## [spec] bblock 93, line 337-2,  t332,  t254,  -47(SI32)
	c0    mpyl $r0.10 = $r0.10, -48   ## [spec] bblock 93, line 338-2,  t329,  t361,  -48(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.6   ## bblock 35, line 341,  t365,  t1182,  t1183
	c0    add $r0.13 = $r0.13, $r0.5   ## [spec] bblock 96, line 341-1,  t1217,  t68,  t65(SI24)
	c0    ldbu.d $r0.14 = 1[$r0.9]   ## [spec] bblock 93, line 343-2, t323, t566
	c0    cmpge $b0.2 = $r0.7, 3   ## [spec] bblock 93, line 336-3,  t1216(I1),  t333,  3(SI32)
;;								## 5
	c0    mpyl $r0.15 = $r0.4, 215   ## [spec] bblock 96, line 339-1,  t59,  t365,  215(SI32)
	c0    mpyl $r0.16 = $r0.4, -155   ## [spec] bblock 93, line 340-2,  t63,  t365,  -155(SI32)
	c0    ldbu.d $r0.17 = 0[$r0.9]   ## [spec] bblock 90, line 343-3, t334, t566
	c0    add $r0.7 = $r0.7, -4   ## [spec] bblock 90, line 336-3,  t333,  t333,  -4(SI32)
;;								## 6
	c0    stw 12[$r0.8] = $r0.4   ## bblock 35, line 341, t565, t365
	c0    mpyl $r0.12 = $r0.12, -48   ## [spec] bblock 90, line 338-3,  t480,  t254,  -48(SI32)
	c0    add $r0.9 = $r0.9, (~0x3)   ## [spec] bblock 90, line 0,  t566,  t566,  (~0x3)(I32)
	c0    brf $b0.1, L101?3   ## bblock 35, line 336-1,  t1184(I1)
;;								## 7
	c0    shr $r0.15 = $r0.15, 8   ## bblock 96, line 339-1,  t478(SI24),  t59,  8(SI32)
	c0    shr $r0.16 = $r0.16, 8   ## [spec] bblock 93, line 340-2,  t325(SI24),  t63,  8(SI32)
	c0    mov $r0.6 = $r0.14   ## [spec] bblock 90, line 343-2,  t340,  t323
	c0    mpyl $r0.4 = $r0.14, -47   ## [spec] bblock 90, line 337-3,  t481,  t323,  -47(SI32)
;;								## 8
	c0    add $r0.3 = $r0.3, $r0.15   ## bblock 96, line 341-1,  t1218,  t67,  t478(SI24)
	c0    add $r0.11 = $r0.11, $r0.16   ## [spec] bblock 93, line 341-2,  t1214,  t332,  t325(SI24)
;;								## 9
	c0    add $r0.13 = $r0.13, $r0.3   ## bblock 96, line 341-1,  t250,  t1217,  t1218
	c0    mov $r0.3 = $r0.17   ## [spec] t334
;;								## 10
	c0    stw 8[$r0.8] = $r0.13   ## bblock 96, line 341-1, t565, t250
	c0    mpyl $r0.14 = $r0.13, 215   ## [spec] bblock 93, line 339-2,  t330,  t250,  215(SI32)
	c0    mpyl $r0.15 = $r0.13, -155   ## [spec] bblock 90, line 340-3,  t337,  t250,  -155(SI32)
	c0    brf $b0.0, L102?3   ## bblock 96, line 336-2,  t1219(I1)
;;								## 11
;;								## 12
	c0    shr $r0.14 = $r0.14, 8   ## bblock 93, line 339-2,  t66(SI24),  t330,  8(SI32)
	c0    shr $r0.15 = $r0.15, 8   ## [spec] bblock 90, line 340-3,  t479(SI24),  t337,  8(SI32)
;;								## 13
	c0    add $r0.10 = $r0.10, $r0.14   ## bblock 93, line 341-2,  t1215,  t329,  t66(SI24)
	c0    add $r0.4 = $r0.4, $r0.15   ## [spec] bblock 90, line 341-3,  t1212,  t481,  t479(SI24)
;;								## 14
	c0    add $r0.11 = $r0.11, $r0.10   ## bblock 93, line 341-2,  t327,  t1214,  t1215
;;								## 15
	c0    stw 4[$r0.8] = $r0.11   ## bblock 93, line 341-2, t565, t327
	c0    mov $r0.2 = $r0.11   ## [spec] bblock 90, line 341-2,  t344,  t327
	c0    mpyl $r0.10 = $r0.11, 215   ## [spec] bblock 90, line 339-3,  t339,  t327,  215(SI32)
	c0    brf $b0.2, L103?3   ## bblock 93, line 336-3,  t1216(I1)
;;								## 16
;;								## 17
	c0    shr $r0.10 = $r0.10, 8   ## bblock 90, line 339-3,  t338(SI24),  t339,  8(SI32)
;;								## 18
	c0    add $r0.12 = $r0.12, $r0.10   ## bblock 90, line 341-3,  t1213,  t480,  t338(SI24)
;;								## 19
	c0    add $r0.5 = $r0.4, $r0.12   ## bblock 90, line 341-3,  t336,  t1212,  t1213
;;								## 20
	c0    stw 0[$r0.8] = $r0.5   ## bblock 90, line 341-3, t565, t336
	c0    add $r0.8 = $r0.8, (~0xf)   ## bblock 90, line 0,  t565,  t565,  (~0xf)(I32)
	c0    goto L99?3 ## goto
;;								## 21
.trace 44
L103?3:
	c0    add $r0.4 = $r0.18, 1   ## bblock 34, line 0,  t1073,  t1073,  1(I32)
	c0    mov $r0.11 = $r0.20   ## t321
;;								## 0
	c0    add $r0.10 = $r0.19, 1050   ## bblock 34, line 0,  t1072,  t1072,  1050(I32)
	c0    goto L104?3 ## goto
;;								## 1
.trace 36
L102?3:
	c0    add $r0.4 = $r0.18, 1   ## bblock 34, line 0,  t1073,  t1073,  1(I32)
	c0    add $r0.10 = $r0.19, 1050   ## bblock 34, line 0,  t1072,  t1072,  1050(I32)
	c0    mov $r0.11 = $r0.20   ## t321
	      ## goto
;;
	c0    goto L104?3 ## goto
;;								## 0
.trace 31
L101?3:
	c0    add $r0.4 = $r0.18, 1   ## bblock 34, line 0,  t1073,  t1073,  1(I32)
	c0    add $r0.10 = $r0.19, 1050   ## bblock 34, line 0,  t1072,  t1072,  1050(I32)
	c0    mov $r0.11 = $r0.20   ## t321
	      ## goto
;;
	c0    goto L104?3 ## goto
;;								## 0
.trace 24
L100?3:
	c0    add $r0.4 = $r0.18, 1   ## bblock 34, line 0,  t1073,  t1073,  1(I32)
	c0    add $r0.10 = $r0.19, 1050   ## bblock 34, line 0,  t1072,  t1072,  1050(I32)
	c0    mov $r0.11 = $r0.20   ## t321
;;								## 0
L104?3:
	c0    add $r0.12 = $r0.21, 4200   ## bblock 34, line 0,  t1071,  t1071,  4200(I32)
	c0    goto L97?3 ## goto
;;								## 1
.trace 53
L98?3:
	c0    sub $r0.2 = $r0.0, $r0.22   ## bblock 4, line 0,  t1026,  0(I32),  t226
	c0    mov $r0.11 = (qy2 + 0)   ## bblock 4, line 0,  t1022,  addr(qy2?1.0)(P32)
	c0    mov $r0.17 = $r0.22   ## t226
;;								## 0
	c0    mov $r0.3 = $r0.2   ## bblock 4, line 0,  t1025,  t1026
	c0    mov $r0.10 = (qy1 + 0)   ## bblock 4, line 0,  t1023,  addr(qy1?1.0)(P32)
	c0    mov $r0.7 = $r0.23   ## t227
;;								## 1
	c0    mov $r0.9 = (qt + 0)   ## bblock 4, line 0,  t1024,  addr(qt?1.0)(P32)
;;								## 2
.trace 19
L105?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 5, line 355,  t1164(I1),  t1025,  0(SI32)
	c0    sub $r0.8 = 3, $r0.7   ## [spec] bblock 28, line 0,  t613,  3(I32),  t227
	c0    mov $r0.6 = $r0.9   ## [spec] bblock 28, line 0,  t611,  t1024
	c0    mov $r0.4 = $r0.10   ## [spec] bblock 28, line 0,  t610,  t1023
;;								## 0
	c0    mov $r0.5 = $r0.8   ## [spec] bblock 28, line 0,  t612,  t613
	c0    mov $r0.2 = $r0.11   ## [spec] bblock 28, line 0,  t609,  t1022
	c0    mov $r0.12 = $r0.3   ## t1025
	c0    mov $r0.13 = $r0.7   ## t227
;;								## 1
	c0    mov $r0.14 = $r0.9   ## t1024
	c0    mov $r0.15 = $r0.10   ## t1023
	c0    mov $r0.16 = $r0.11   ## t1022
	c0    brf $b0.0, L106?3   ## bblock 5, line 355,  t1164(I1)
;;								## 2
.trace 1
L107?3:
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 29, line 356,  t1179(I1),  t612,  3(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 31, line 357, t370, t609
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 31, line 356-1,  t1180(I1),  t612,  2(SI32)
	c0    cmplt $b0.2 = $r0.5, 1   ## [spec] bblock 86, line 356-2,  t1211(I1),  t612,  1(SI32)
;;								## 0
	c0    ldw.d $r0.7 = 0[$r0.4]   ## [spec] bblock 31, line 357, t381, t610
	c0    cmplt $b0.3 = $r0.5, $r0.0   ## [spec] bblock 83, line 356-3,  t1210(I1),  t612,  0(SI32)
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 80, line 0,  t612,  t612,  4(I32)
;;								## 1
	c0    ldw.d $r0.8 = 4[$r0.2]   ## [spec] bblock 86, line 357-1, t94, t609
	c0    brf $b0.0, L108?3   ## bblock 29, line 356,  t1179(I1)
;;								## 2
	c0    ldw.d $r0.9 = 4[$r0.4]   ## [spec] bblock 86, line 357-1, t98, t610
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.7   ## bblock 31, line 357,  t472,  t370,  t381
	c0    ldw.d $r0.7 = 8[$r0.2]   ## [spec] bblock 83, line 357-2, t349, t609
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## bblock 31, line 357,  t471,  t472,  8(I32)
	c0    ldw.d $r0.10 = 8[$r0.4]   ## [spec] bblock 83, line 357-2, t352, t610
;;								## 5
	c0    shr $r0.3 = $r0.3, 8   ## bblock 31, line 357,  t380(SI24),  t471,  8(SI32)
	c0    add $r0.8 = $r0.8, $r0.9   ## [spec] bblock 86, line 357-1,  t99,  t94,  t98
	c0    ldw.d $r0.9 = 12[$r0.2]   ## [spec] bblock 80, line 357-3, t359, t609
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 80, line 0,  t609,  t609,  16(I32)
;;								## 6
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 86, line 357-1,  t101,  t99,  8(I32)
	c0    ldw.d $r0.11 = 12[$r0.4]   ## [spec] bblock 80, line 357-3, t358, t610
	c0    add $r0.4 = $r0.4, 16   ## [spec] bblock 80, line 0,  t610,  t610,  16(I32)
;;								## 7
	c0    stw 0[$r0.6] = $r0.3   ## bblock 31, line 357, t611, t380(SI24)
	c0    shr $r0.8 = $r0.8, 8   ## [spec] bblock 86, line 357-1,  t372(SI24),  t101,  8(SI32)
	c0    add $r0.7 = $r0.7, $r0.10   ## [spec] bblock 83, line 357-2,  t351,  t349,  t352
	c0    brf $b0.1, L109?3   ## bblock 31, line 356-1,  t1180(I1)
;;								## 8
	c0    stw 4[$r0.6] = $r0.8   ## bblock 86, line 357-1, t611, t372(SI24)
	c0    shl $r0.7 = $r0.7, 8   ## [spec] bblock 83, line 357-2,  t350,  t351,  8(I32)
	c0    brf $b0.2, L110?3   ## bblock 86, line 356-2,  t1211(I1)
;;								## 9
	c0    shr $r0.7 = $r0.7, 8   ## bblock 83, line 357-2,  t102(SI24),  t350,  8(SI32)
	c0    add $r0.9 = $r0.9, $r0.11   ## [spec] bblock 80, line 357-3,  t357,  t359,  t358
;;								## 10
	c0    stw 8[$r0.6] = $r0.7   ## bblock 83, line 357-2, t611, t102(SI24)
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 80, line 357-3,  t356,  t357,  8(I32)
	c0    brf $b0.3, L111?3   ## bblock 83, line 356-3,  t1210(I1)
;;								## 11
	c0    shr $r0.9 = $r0.9, 8   ## bblock 80, line 357-3,  t355(SI24),  t356,  8(SI32)
;;								## 12
	c0    stw 12[$r0.6] = $r0.9   ## bblock 80, line 357-3, t611, t355(SI24)
	c0    add $r0.6 = $r0.6, 16   ## bblock 80, line 0,  t611,  t611,  16(I32)
	c0    goto L107?3 ## goto
;;								## 13
.trace 43
L111?3:
	c0    add $r0.3 = $r0.12, 1   ## bblock 30, line 0,  t1025,  t1025,  1(I32)
	c0    mov $r0.7 = $r0.13   ## t227
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.9 = $r0.14, $r0.2   ## bblock 30, line 0,  t1024,  t1024,  4200(I32)
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 30, line 0,  t1023,  t1023,  4200(I32)
	c0    add $r0.11 = $r0.16, $r0.2   ## bblock 30, line 0,  t1022,  t1022,  4200(I32)
	c0    goto L105?3 ## goto
;;								## 1
.trace 38
L110?3:
	c0    add $r0.3 = $r0.12, 1   ## bblock 30, line 0,  t1025,  t1025,  1(I32)
	c0    mov $r0.7 = $r0.13   ## t227
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.9 = $r0.14, $r0.2   ## bblock 30, line 0,  t1024,  t1024,  4200(I32)
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 30, line 0,  t1023,  t1023,  4200(I32)
	c0    add $r0.11 = $r0.16, $r0.2   ## bblock 30, line 0,  t1022,  t1022,  4200(I32)
	c0    goto L105?3 ## goto
;;								## 1
.trace 29
L109?3:
	c0    add $r0.3 = $r0.12, 1   ## bblock 30, line 0,  t1025,  t1025,  1(I32)
	c0    mov $r0.7 = $r0.13   ## t227
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.9 = $r0.14, $r0.2   ## bblock 30, line 0,  t1024,  t1024,  4200(I32)
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 30, line 0,  t1023,  t1023,  4200(I32)
	c0    add $r0.11 = $r0.16, $r0.2   ## bblock 30, line 0,  t1022,  t1022,  4200(I32)
	c0    goto L105?3 ## goto
;;								## 1
.trace 23
L108?3:
	c0    add $r0.3 = $r0.12, 1   ## bblock 30, line 0,  t1025,  t1025,  1(I32)
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.9 = $r0.14, $r0.2   ## bblock 30, line 0,  t1024,  t1024,  4200(I32)
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 30, line 0,  t1023,  t1023,  4200(I32)
	c0    add $r0.11 = $r0.16, $r0.2   ## bblock 30, line 0,  t1022,  t1022,  4200(I32)
	c0    mov $r0.7 = $r0.13   ## t227
	      ## goto
;;
	c0    goto L105?3 ## goto
;;								## 1
.trace 52
L106?3:
	c0    sub $r0.2 = $r0.0, $r0.13   ## bblock 6, line 0,  t991,  0(I32),  t227
	c0    mov $r0.12 = (qt + 0)   ## bblock 6, line 0,  t988,  addr(qt?1.0)(P32)
	c0    mov $r0.19 = $r0.13   ## t227
;;								## 0
	c0    mov $r0.3 = $r0.2   ## bblock 6, line 0,  t990,  t991
	c0    mov $r0.11 = (qy1 + 0)   ## bblock 6, line 0,  t989,  addr(qy1?1.0)(P32)
	c0    mov $r0.6 = $r0.17   ## t226
;;								## 1
.trace 22
L112?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 7, line 365,  t1165(I1),  t990,  0(SI32)
	c0    sub $r0.10 = 3, $r0.6   ## [spec] bblock 24, line 0,  t676,  3(I32),  t226
	c0    mov $r0.9 = $r0.11   ## [spec] bblock 24, line 0,  t674,  t989
	c0    mov $r0.2 = $r0.12   ## [spec] bblock 24, line 0,  t673,  t988
;;								## 0
	c0    mov $r0.8 = $r0.10   ## [spec] bblock 24, line 0,  t675,  t676
	c0    mov $r0.7 = $r0.0   ## [spec] bblock 24, line 366,  t384,  0(SI32)
	c0    mov $r0.5 = $r0.0   ## [spec] bblock 24, line 366,  t382(SI24),  0(SI32)
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 24, line 366,  t383,  0(SI32)
;;								## 1
	c0    mov $r0.15 = $r0.3   ## t990
	c0    mov $r0.16 = $r0.6   ## t226
	c0    mov $r0.17 = $r0.11   ## t989
	c0    brf $b0.0, L113?3   ## bblock 7, line 365,  t1165(I1)
;;								## 2
	c0    mov $r0.18 = $r0.12   ## t988
;;								## 3
.trace 6
L114?3:
	c0    cmplt $b0.0 = $r0.8, 3   ## bblock 25, line 367,  t1175(I1),  t675,  3(SI32)
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 27, line 368,  t406,  t383,  -155(SI32)
	c0    mpyl $r0.6 = $r0.5, 215   ## [spec] bblock 27, line 368,  t387,  t382(SI24),  215(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 27, line 368, t466, t673
;;								## 0
	c0    mpyl $r0.7 = $r0.7, 28   ## [spec] bblock 27, line 368,  t401,  t384,  28(SI32)
	c0    cmplt $b0.1 = $r0.8, 2   ## [spec] bblock 27, line 367-1,  t1178(I1),  t675,  2(SI32)
	c0    ldw.d $r0.10 = 4200[$r0.2]   ## [spec] bblock 76, line 368-1, t473, t673
;;								## 1
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 76, line 368-1,  t116,  t382(SI24),  -155(SI32)
	c0    cmplt $b0.0 = $r0.8, 1   ## [spec] bblock 76, line 367-2,  t1209(I1),  t675,  1(SI32)
	c0    cmplt $b0.2 = $r0.8, $r0.0   ## [spec] bblock 73, line 367-3,  t1206(I1),  t675,  0(SI32)
	c0    brf $b0.0, L115?3   ## bblock 25, line 367,  t1175(I1)
;;								## 2
	c0    mpyl $r0.11 = $r0.3, -48   ## bblock 27, line 368,  t404,  t466,  -48(SI32)
	c0    add $r0.6 = $r0.6, $r0.7   ## bblock 27, line 368,  t1177,  t387,  t401
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 76, line 368-1,  t122,  t466,  28(SI32)
	c0    add $r0.8 = $r0.8, 4   ## [spec] bblock 70, line 0,  t675,  t675,  4(I32)
;;								## 3
	c0    mpyl $r0.12 = $r0.10, -48   ## [spec] bblock 76, line 368-1,  t128,  t473,  -48(SI32)
	c0    mpyl $r0.10 = $r0.10, 28   ## [spec] bblock 73, line 368-2,  t470,  t473,  28(SI32)
	c0    ldw.d $r0.13 = 8400[$r0.2]   ## [spec] bblock 73, line 368-2, t257, t673
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.11   ## bblock 27, line 368,  t1176,  t406,  t404
	c0    ldw.d $r0.7 = 12600[$r0.2]   ## [spec] bblock 70, line 368-3, t384, t673
;;								## 5
	c0    add $r0.4 = $r0.4, $r0.6   ## bblock 27, line 368,  t403,  t1176,  t1177
	c0    add $r0.5 = $r0.5, $r0.12   ## [spec] bblock 76, line 368-1,  t1207,  t116,  t128
	c0    add $r0.2 = $r0.2, 16800   ## [spec] bblock 70, line 0,  t673,  t673,  16800(I32)
;;								## 6
	c0    shr $r0.4 = $r0.4, 8   ## bblock 27, line 368,  t1155,  t403,  8(SI32)
	c0    mpyl $r0.6 = $r0.13, -48   ## [spec] bblock 73, line 368-2,  t375,  t257,  -48(SI32)
	c0    mpyl $r0.13 = $r0.13, 28   ## [spec] bblock 70, line 368-3,  t391,  t257,  28(SI32)
;;								## 7
	c0    stw 0[$r0.9] = $r0.4   ## bblock 27, line 368, t674, t1155
	c0    mpyl $r0.11 = $r0.4, 215   ## [spec] bblock 76, line 368-1,  t119,  t1155,  215(SI32)
	c0    mpyl $r0.12 = $r0.4, -155   ## [spec] bblock 73, line 368-2,  t378,  t1155,  -155(SI32)
	c0    brf $b0.1, L116?3   ## bblock 27, line 367-1,  t1178(I1)
;;								## 8
	c0    mpyl $r0.14 = $r0.7, -48   ## [spec] bblock 70, line 368-3,  t386,  t384,  -48(SI32)
;;								## 9
	c0    add $r0.11 = $r0.11, $r0.3   ## bblock 76, line 368-1,  t1208,  t119,  t122
	c0    add $r0.12 = $r0.12, $r0.6   ## [spec] bblock 73, line 368-2,  t1204,  t378,  t375
;;								## 10
	c0    add $r0.5 = $r0.5, $r0.11   ## bblock 76, line 368-1,  t129,  t1207,  t1208
;;								## 11
	c0    shr $r0.5 = $r0.5, 8   ## bblock 76, line 368-1,  t1156,  t129,  8(SI32)
;;								## 12
	c0    stw 4200[$r0.9] = $r0.5   ## bblock 76, line 368-1, t674, t1156
	c0    mpyl $r0.3 = $r0.5, 215   ## [spec] bblock 73, line 368-2,  t376,  t1156,  215(SI32)
	c0    mpyl $r0.6 = $r0.5, -155   ## [spec] bblock 70, line 368-3,  t393,  t1156,  -155(SI32)
;;								## 13
	c0    brf $b0.0, L117?3   ## bblock 76, line 367-2,  t1209(I1)
;;								## 14
	c0    add $r0.3 = $r0.3, $r0.10   ## bblock 73, line 368-2,  t1205,  t376,  t470
	c0    add $r0.6 = $r0.6, $r0.14   ## [spec] bblock 70, line 368-3,  t1202,  t393,  t386
;;								## 15
	c0    add $r0.12 = $r0.12, $r0.3   ## bblock 73, line 368-2,  t374,  t1204,  t1205
;;								## 16
	c0    shr $r0.12 = $r0.12, 8   ## bblock 73, line 368-2,  t1157,  t374,  8(SI32)
;;								## 17
	c0    stw 8400[$r0.9] = $r0.12   ## bblock 73, line 368-2, t674, t1157
	c0    mov $r0.4 = $r0.12   ## [spec] bblock 70, line 368-2,  t383,  t1157
	c0    mpyl $r0.3 = $r0.12, 215   ## [spec] bblock 70, line 368-3,  t392,  t1157,  215(SI32)
;;								## 18
	c0    brf $b0.2, L118?3   ## bblock 73, line 367-3,  t1206(I1)
;;								## 19
	c0    add $r0.3 = $r0.3, $r0.13   ## bblock 70, line 368-3,  t1203,  t392,  t391
;;								## 20
	c0    add $r0.6 = $r0.6, $r0.3   ## bblock 70, line 368-3,  t385,  t1202,  t1203
;;								## 21
	c0    shr $r0.5 = $r0.6, 8   ## bblock 70, line 368-3,  t382(SI24),  t385,  8(SI32)
;;								## 22
	c0    stw 12600[$r0.9] = $r0.5   ## bblock 70, line 368-3, t674, t382(SI24)
	c0    add $r0.9 = $r0.9, 16800   ## bblock 70, line 0,  t674,  t674,  16800(I32)
	      ## goto
;;
	c0    goto L114?3 ## goto
;;								## 23
.trace 46
L118?3:
	c0    add $r0.3 = $r0.15, 1   ## bblock 26, line 0,  t990,  t990,  1(I32)
	c0    add $r0.11 = $r0.17, 4   ## bblock 26, line 0,  t989,  t989,  4(I32)
	c0    add $r0.12 = $r0.18, 4   ## bblock 26, line 0,  t988,  t988,  4(I32)
	c0    mov $r0.6 = $r0.16   ## t226
	      ## goto
;;
	c0    goto L112?3 ## goto
;;								## 0
.trace 40
L117?3:
	c0    add $r0.3 = $r0.15, 1   ## bblock 26, line 0,  t990,  t990,  1(I32)
	c0    add $r0.11 = $r0.17, 4   ## bblock 26, line 0,  t989,  t989,  4(I32)
	c0    add $r0.12 = $r0.18, 4   ## bblock 26, line 0,  t988,  t988,  4(I32)
	c0    mov $r0.6 = $r0.16   ## t226
	      ## goto
;;
	c0    goto L112?3 ## goto
;;								## 0
.trace 34
L116?3:
	c0    add $r0.3 = $r0.15, 1   ## bblock 26, line 0,  t990,  t990,  1(I32)
	c0    mov $r0.6 = $r0.16   ## t226
;;								## 0
	c0    add $r0.11 = $r0.17, 4   ## bblock 26, line 0,  t989,  t989,  4(I32)
	c0    add $r0.12 = $r0.18, 4   ## bblock 26, line 0,  t988,  t988,  4(I32)
	c0    goto L112?3 ## goto
;;								## 1
.trace 26
L115?3:
	c0    add $r0.3 = $r0.15, 1   ## bblock 26, line 0,  t990,  t990,  1(I32)
	c0    add $r0.11 = $r0.17, 4   ## bblock 26, line 0,  t989,  t989,  4(I32)
	c0    add $r0.12 = $r0.18, 4   ## bblock 26, line 0,  t988,  t988,  4(I32)
	c0    mov $r0.6 = $r0.16   ## t226
	      ## goto
;;
	c0    goto L112?3 ## goto
;;								## 0
.trace 55
L113?3:
	c0    add $r0.10 = $r0.16, -1   ## bblock 8, line 383,  t322,  t226,  -1(SI32)
	c0    sub $r0.2 = $r0.0, $r0.19   ## bblock 8, line 0,  t958,  0(I32),  t227
	c0    mov $r0.13 = ((qy2 + 0) + (~0x3137))   ## bblock 8, line 0,  t955,  (addr(qy2?1.0)(P32) + 0xffffcec8(I32))(P32)
;;								## 0
	c0    mov $r0.4 = $r0.2   ## bblock 8, line 0,  t957,  t958
	c0    mov $r0.12 = ((qt + 0) + (~0x3137))   ## bblock 8, line 0,  t956,  (addr(qt?1.0)(P32) + 0xffffcec8(I32))(P32)
	c0    mov $r0.21 = $r0.16   ## t226
;;								## 1
	c0    mov $r0.22 = $r0.19   ## t227
;;								## 2
.trace 21
L119?3:
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## bblock 9, line 381,  t1166(I1),  t957,  0(SI32)
	c0    mpylu $r0.11 = $r0.10, 4200   ## [spec] bblock 20, line 0,  t766,  t322,  4200(I32)
	c0    mov $r0.3 = $r0.0   ## [spec] bblock 20, line 382,  t412,  0(SI32)
;;								## 0
	c0    mov $r0.6 = $r0.0   ## [spec] bblock 20, line 382,  t411,  0(SI32)
	c0    mov $r0.5 = $r0.0   ## [spec] bblock 20, line 382,  t410(SI24),  0(SI32)
	c0    mov $r0.2 = $r0.0   ## [spec] bblock 20, line 382,  t409,  0(SI32)
	c0    mov $r0.7 = $r0.10   ## [spec] bblock 20, line 383,  t415,  t322
;;								## 1
	c0    add $r0.9 = $r0.12, $r0.11   ## [spec] bblock 20, line 0,  t756,  t956,  t766
	c0    add $r0.8 = $r0.13, $r0.11   ## [spec] bblock 20, line 0,  t755,  t955,  t766
	c0    mov $r0.17 = $r0.4   ## t957
	c0    brf $b0.0, L120?3   ## bblock 9, line 381,  t1166(I1)
;;								## 2
	c0    mov $r0.18 = $r0.10   ## t322
	c0    mov $r0.19 = $r0.12   ## t956
	c0    mov $r0.20 = $r0.13   ## t955
;;								## 3
.trace 5
L121?3:
	c0    cmpge $b0.0 = $r0.7, $r0.0   ## bblock 21, line 383,  t1171(I1),  t415,  0(SI32)
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 23, line 384,  t430,  t409,  -155(SI32)
	c0    mpyl $r0.4 = $r0.3, -47   ## [spec] bblock 23, line 384,  t461,  t412,  -47(SI32)
	c0    cmpge $b0.1 = $r0.7, 1   ## [spec] bblock 23, line 383-1,  t1174(I1),  t415,  1(SI32)
;;								## 0
	c0    mpyl $r0.10 = $r0.5, 215   ## [spec] bblock 23, line 384,  t413,  t410(SI24),  215(SI32)
	c0    mpyl $r0.6 = $r0.6, 29   ## [spec] bblock 23, line 384,  t425,  t411,  29(SI32)
	c0    ldw.d $r0.11 = 12600[$r0.9]   ## [spec] bblock 23, line 386, t424, t756
;;								## 1
	c0    add $r0.2 = $r0.2, $r0.4   ## [spec] bblock 23, line 384,  t1172,  t430,  t461
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 66, line 384-1,  t463,  t410(SI24),  -155(SI32)
	c0    mpyl $r0.3 = $r0.3, 29   ## [spec] bblock 66, line 384-1,  t160,  t412,  29(SI32)
	c0    brf $b0.0, L122?3   ## bblock 21, line 383,  t1171(I1)
;;								## 2
	c0    add $r0.10 = $r0.10, $r0.6   ## bblock 23, line 384,  t1173,  t413,  t425
	c0    ldw.d $r0.4 = 8400[$r0.9]   ## [spec] bblock 66, line 386-1, t252, t756
	c0    cmpge $b0.0 = $r0.7, 2   ## [spec] bblock 66, line 383-2,  t1201(I1),  t415,  2(SI32)
;;								## 3
	c0    add $r0.2 = $r0.2, $r0.10   ## bblock 23, line 384,  t460,  t1172,  t1173
	c0    mpyl $r0.10 = $r0.11, -47   ## [spec] bblock 66, line 384-1,  t395,  t424,  -47(SI32)
	c0    mpyl $r0.11 = $r0.11, 29   ## [spec] bblock 63, line 384-2,  t407,  t424,  29(SI32)
	c0    cmpge $b0.2 = $r0.7, 3   ## [spec] bblock 63, line 383-3,  t1198(I1),  t415,  3(SI32)
;;								## 4
	c0    shr $r0.2 = $r0.2, 8   ## bblock 23, line 384,  t1158,  t460,  8(SI32)
	c0    ldw.d $r0.12 = 4200[$r0.9]   ## [spec] bblock 63, line 386-2, t398, t756
	c0    add $r0.7 = $r0.7, -4   ## [spec] bblock 60, line 383-3,  t415,  t415,  -4(SI32)
;;								## 5
	c0    mpyl $r0.10 = $r0.2, 215   ## [spec] bblock 66, line 384-1,  t157,  t1158,  215(SI32)
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 66, line 384-1,  t1199,  t463,  t395
	c0    mpyl $r0.13 = $r0.2, -155   ## [spec] bblock 63, line 384-2,  t154,  t1158,  -155(SI32)
	c0    ldw.d $r0.14 = 0[$r0.9]   ## [spec] bblock 60, line 386-3, t412, t756
;;								## 6
	c0    mpyl $r0.15 = $r0.4, -47   ## [spec] bblock 63, line 384-2,  t163,  t252,  -47(SI32)
	c0    mpyl $r0.4 = $r0.4, 29   ## [spec] bblock 60, line 384-3,  t419,  t252,  29(SI32)
	c0    add $r0.9 = $r0.9, (~0x419f)   ## [spec] bblock 60, line 0,  t756,  t756,  (~0x419f)(I32)
;;								## 7
	c0    add $r0.10 = $r0.10, $r0.3   ## [spec] bblock 66, line 384-1,  t1200,  t157,  t160
	c0    mov $r0.6 = $r0.12   ## [spec] bblock 60, line 386-2,  t411,  t398
	c0    mpyl $r0.16 = $r0.12, -47   ## [spec] bblock 60, line 384-3,  t418,  t398,  -47(SI32)
;;								## 8
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 66, line 384-1,  t394,  t1199,  t1200
	c0    add $r0.13 = $r0.13, $r0.15   ## [spec] bblock 63, line 384-2,  t1196,  t154,  t163
	c0    mov $r0.3 = $r0.14   ## [spec] t412
;;								## 9
	c0    stw 12600[$r0.8] = $r0.2   ## bblock 23, line 384, t755, t1158
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 66, line 384-1,  t1159,  t394,  8(SI32)
	c0    brf $b0.1, L123?3   ## bblock 23, line 383-1,  t1174(I1)
;;								## 10
	c0    stw 8400[$r0.8] = $r0.5   ## bblock 66, line 384-1, t755, t1159
	c0    mpyl $r0.10 = $r0.5, 215   ## [spec] bblock 63, line 384-2,  t408,  t1159,  215(SI32)
	c0    mpyl $r0.12 = $r0.5, -155   ## [spec] bblock 60, line 384-3,  t421,  t1159,  -155(SI32)
;;								## 11
	c0    brf $b0.0, L124?3   ## bblock 66, line 383-2,  t1201(I1)
;;								## 12
	c0    add $r0.10 = $r0.10, $r0.11   ## bblock 63, line 384-2,  t1197,  t408,  t407
	c0    add $r0.12 = $r0.12, $r0.16   ## [spec] bblock 60, line 384-3,  t1194,  t421,  t418
;;								## 13
	c0    add $r0.13 = $r0.13, $r0.10   ## bblock 63, line 384-2,  t164,  t1196,  t1197
;;								## 14
	c0    shr $r0.13 = $r0.13, 8   ## bblock 63, line 384-2,  t1160,  t164,  8(SI32)
;;								## 15
	c0    stw 4200[$r0.8] = $r0.13   ## bblock 63, line 384-2, t755, t1160
	c0    mov $r0.2 = $r0.13   ## [spec] bblock 60, line 384-2,  t409,  t1160
	c0    mpyl $r0.10 = $r0.13, 215   ## [spec] bblock 60, line 384-3,  t420,  t1160,  215(SI32)
;;								## 16
	c0    brf $b0.2, L125?3   ## bblock 63, line 383-3,  t1198(I1)
;;								## 17
	c0    add $r0.10 = $r0.10, $r0.4   ## bblock 60, line 384-3,  t1195,  t420,  t419
;;								## 18
	c0    add $r0.12 = $r0.12, $r0.10   ## bblock 60, line 384-3,  t417,  t1194,  t1195
;;								## 19
	c0    shr $r0.5 = $r0.12, 8   ## bblock 60, line 384-3,  t410(SI24),  t417,  8(SI32)
;;								## 20
	c0    stw 0[$r0.8] = $r0.5   ## bblock 60, line 384-3, t755, t410(SI24)
	c0    add $r0.8 = $r0.8, (~0x419f)   ## bblock 60, line 0,  t755,  t755,  (~0x419f)(I32)
	c0    goto L121?3 ## goto
;;								## 21
.trace 45
L125?3:
	c0    add $r0.4 = $r0.17, 1   ## bblock 22, line 0,  t957,  t957,  1(I32)
	c0    add $r0.12 = $r0.19, 4   ## bblock 22, line 0,  t956,  t956,  4(I32)
	c0    add $r0.13 = $r0.20, 4   ## bblock 22, line 0,  t955,  t955,  4(I32)
	c0    mov $r0.10 = $r0.18   ## t322
	      ## goto
;;
	c0    goto L119?3 ## goto
;;								## 0
.trace 39
L124?3:
	c0    add $r0.4 = $r0.17, 1   ## bblock 22, line 0,  t957,  t957,  1(I32)
	c0    add $r0.12 = $r0.19, 4   ## bblock 22, line 0,  t956,  t956,  4(I32)
	c0    add $r0.13 = $r0.20, 4   ## bblock 22, line 0,  t955,  t955,  4(I32)
	c0    mov $r0.10 = $r0.18   ## t322
	      ## goto
;;
	c0    goto L119?3 ## goto
;;								## 0
.trace 32
L123?3:
	c0    add $r0.4 = $r0.17, 1   ## bblock 22, line 0,  t957,  t957,  1(I32)
	c0    add $r0.12 = $r0.19, 4   ## bblock 22, line 0,  t956,  t956,  4(I32)
	c0    add $r0.13 = $r0.20, 4   ## bblock 22, line 0,  t955,  t955,  4(I32)
	c0    mov $r0.10 = $r0.18   ## t322
	      ## goto
;;
	c0    goto L119?3 ## goto
;;								## 0
.trace 27
L122?3:
	c0    add $r0.4 = $r0.17, 1   ## bblock 22, line 0,  t957,  t957,  1(I32)
	c0    add $r0.12 = $r0.19, 4   ## bblock 22, line 0,  t956,  t956,  4(I32)
	c0    add $r0.13 = $r0.20, 4   ## bblock 22, line 0,  t955,  t955,  4(I32)
	c0    mov $r0.10 = $r0.18   ## t322
	      ## goto
;;
	c0    goto L119?3 ## goto
;;								## 0
.trace 54
L120?3:
	c0    sub $r0.21 = $r0.0, $r0.21   ## bblock 10, line 0,  t911,  0(I32),  t226
	c0    mov $r0.12 = (qy2 + 0)   ## bblock 10, line 0,  t908,  addr(qy2?1.0)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.21   ## bblock 10, line 0,  t910,  t911
	c0    mov $r0.11 = (qy1 + 0)   ## bblock 10, line 0,  t909,  addr(qy1?1.0)(P32)
;;								## 1
	c0    mov $r0.10 = (out + 0)   ## bblock 10, line 0,  t906,  addr(out?1.0)(P32)
	c0    mov $r0.8 = $r0.22   ## t227
;;								## 2
.trace 20
L126?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 11, line 399,  t1167(I1),  t910,  0(SI32)
	c0    sub $r0.9 = 3, $r0.8   ## [spec] bblock 13, line 0,  t837,  3(I32),  t227
	c0    mov $r0.7 = $r0.10   ## [spec] bblock 13, line 0,  t835,  t906
	c0    mov $r0.6 = $r0.10   ## [spec] bblock 13, line 0,  t834,  t906
;;								## 0
	c0    mov $r0.5 = $r0.9   ## [spec] bblock 13, line 0,  t836,  t837
	c0    mov $r0.4 = $r0.11   ## [spec] bblock 13, line 0,  t833,  t909
	c0    mov $r0.2 = $r0.12   ## [spec] bblock 13, line 0,  t832,  t908
	c0    mov $r0.14 = $r0.3   ## t910
;;								## 1
	c0    mov $r0.15 = $r0.8   ## t227
	c0    mov $r0.16 = $r0.10   ## t906
	c0    mov $r0.17 = $r0.11   ## t909
	c0    brf $b0.0, L127?3   ## bblock 11, line 399,  t1167(I1)
;;								## 2
	c0    mov $r0.18 = $r0.12   ## t908
;;								## 3
.trace 4
L128?3:
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 14, line 400,  t1168(I1),  t836,  3(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 16, line 401, t455, t832
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 18, line 400-1,  t1170(I1),  t836,  2(SI32)
	c0    cmplt $b0.2 = $r0.5, 1   ## [spec] bblock 55, line 400-2,  t1193(I1),  t836,  1(SI32)
;;								## 0
	c0    ldw.d $r0.8 = 0[$r0.4]   ## [spec] bblock 16, line 401, t454, t833
	c0    cmplt $b0.3 = $r0.5, $r0.0   ## [spec] bblock 49, line 400-3,  t1191(I1),  t836,  0(SI32)
;;								## 1
	c0    ldw.d $r0.9 = 4[$r0.2]   ## [spec] bblock 53, line 401-1, t190, t832
	c0    brf $b0.0, L129?3   ## bblock 14, line 400,  t1168(I1)
;;								## 2
	c0    ldw.d $r0.10 = 4[$r0.4]   ## [spec] bblock 53, line 401-1, t194, t833
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.8   ## bblock 16, line 401,  t445,  t455,  t454
	c0    ldw.d $r0.11 = 8[$r0.2]   ## [spec] bblock 47, line 401-2, t437, t832
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## bblock 16, line 401,  t444,  t445,  8(I32)
	c0    ldw.d $r0.8 = 8[$r0.4]   ## [spec] bblock 47, line 401-2, t433, t833
;;								## 5
	c0    shr $r0.3 = $r0.3, 16   ## bblock 16, line 401,  t443(SI16),  t444,  16(SI32)
	c0    add $r0.9 = $r0.9, $r0.10   ## [spec] bblock 53, line 401-1,  t459,  t190,  t194
	c0    ldw.d $r0.12 = 12[$r0.2]   ## [spec] bblock 41, line 401-3, t450, t832
;;								## 6
	c0    zxtb $r0.10 = $r0.3   ## bblock 16, line 401,  t442(I8),  t443(SI16)
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 53, line 401-1,  t458,  t459,  8(I32)
	c0    ldw.d $r0.13 = 12[$r0.4]   ## [spec] bblock 41, line 401-3, t449, t833
;;								## 7
	c0    stb 0[$r0.6] = $r0.3   ## bblock 16, line 401, t834, t443(SI16)
	c0    cmpgt $b0.0 = $r0.10, 25   ## bblock 16, line 402,  t1169(I1),  t442(I8),  25(SI32)
	c0    shr $r0.9 = $r0.9, 16   ## [spec] bblock 53, line 401-1,  t198(SI16),  t458,  16(SI32)
	c0    add $r0.11 = $r0.11, $r0.8   ## [spec] bblock 47, line 401-2,  t195,  t437,  t433
;;								## 8
	c0    zxtb $r0.3 = $r0.9   ## [spec] bblock 53, line 401-1,  t423(I8),  t198(SI16)
	c0    shl $r0.11 = $r0.11, 8   ## [spec] bblock 47, line 401-2,  t197,  t195,  8(I32)
;;								## 9
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 53, line 402-1,  t1192(I1),  t423(I8),  25(SI32)
	c0    shr $r0.11 = $r0.11, 16   ## [spec] bblock 47, line 401-2,  t431(SI16),  t197,  16(SI32)
	c0    add $r0.12 = $r0.12, $r0.13   ## [spec] bblock 41, line 401-3,  t448,  t450,  t449
	c0    brf $b0.0, L130?3   ## bblock 16, line 402,  t1169(I1)
;;								## 10
	c0    stb 0[$r0.6] = $r0.0   ## bblock 19, line 403, t834, 0(I32)
	c0    zxtb $r0.8 = $r0.11   ## [spec] bblock 47, line 401-2,  t206(I8),  t431(SI16)
	c0    shl $r0.12 = $r0.12, 8   ## [spec] bblock 41, line 401-3,  t447,  t448,  8(I32)
	c0    brf $b0.1, L131?3   ## bblock 18, line 400-1,  t1170(I1)
;;								## 11
L132?3:
	c0    stb 1[$r0.6] = $r0.9   ## bblock 53, line 401-1, t834, t198(SI16)
	c0    cmpgt $b0.1 = $r0.8, 25   ## [spec] bblock 47, line 402-2,  t1190(I1),  t206(I8),  25(SI32)
	c0    shr $r0.12 = $r0.12, 16   ## [spec] bblock 41, line 401-3,  t441(SI16),  t447,  16(SI32)
	c0    brf $b0.0, L133?3   ## bblock 53, line 402-1,  t1192(I1)
;;								## 12
	c0    stb 1[$r0.6] = $r0.0   ## bblock 56, line 403-1, t834, 0(I32)
	c0    zxtb $r0.3 = $r0.12   ## [spec] bblock 41, line 401-3,  t440(I8),  t441(SI16)
	c0    brf $b0.2, L134?3   ## bblock 55, line 400-2,  t1193(I1)
;;								## 13
L135?3:
	c0    stb 2[$r0.6] = $r0.11   ## bblock 47, line 401-2, t834, t431(SI16)
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 41, line 402-3,  t1189(I1),  t440(I8),  25(SI32)
	c0    brf $b0.1, L136?3   ## bblock 47, line 402-2,  t1190(I1)
;;								## 14
	c0    stb 2[$r0.6] = $r0.0   ## bblock 50, line 403-2, t834, 0(I32)
	c0    brf $b0.3, L137?3   ## bblock 49, line 400-3,  t1191(I1)
;;								## 15
L138?3:
	c0    stb 3[$r0.6] = $r0.12   ## bblock 41, line 401-3, t834, t441(SI16)
	c0    brf $b0.0, L139?3   ## bblock 41, line 402-3,  t1189(I1)
;;								## 16
	c0    add $r0.5 = $r0.5, 4   ## bblock 43, line 0,  t836,  t836,  4(I32)
	c0    add $r0.7 = $r0.7, 4   ## bblock 43, line 0,  t835,  t835,  4(I32)
	c0    add $r0.4 = $r0.4, 16   ## bblock 43, line 0,  t833,  t833,  16(I32)
	c0    add $r0.2 = $r0.2, 16   ## bblock 43, line 0,  t832,  t832,  16(I32)
;;								## 17
	c0    stb 3[$r0.6] = $r0.0   ## bblock 44, line 403-3, t834, 0(I32)
;;								## 18
L140?3:
	c0    add $r0.6 = $r0.6, 4   ## bblock 43, line 0,  t834,  t834,  4(I32)
	c0    goto L128?3 ## goto
;;								## 19
.trace 16
L139?3:
	c0    add $r0.5 = $r0.5, 4   ## bblock 43, line 0,  t836,  t836,  4(I32)
	c0    add $r0.4 = $r0.4, 16   ## bblock 43, line 0,  t833,  t833,  16(I32)
	c0    add $r0.2 = $r0.2, 16   ## bblock 43, line 0,  t832,  t832,  16(I32)
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 3[$r0.7] = $r0.3   ## bblock 42, line 405-3, t835, 255(I32)
	c0    add $r0.7 = $r0.7, 4   ## bblock 43, line 0,  t835,  t835,  4(I32)
	c0    goto L140?3 ## goto
;;								## 1
.trace 47
L137?3:
	c0    add $r0.3 = $r0.14, 1   ## bblock 15, line 0,  t910,  t910,  1(I32)
	c0    add $r0.11 = $r0.17, 4200   ## bblock 15, line 0,  t909,  t909,  4200(I32)
	c0    mov $r0.8 = $r0.15   ## t227
;;								## 0
	c0    add $r0.12 = $r0.18, 4200   ## bblock 15, line 0,  t908,  t908,  4200(I32)
	c0    add $r0.10 = $r0.16, 1050   ## bblock 15, line 0,  t906,  t906,  1050(I32)
	      ## goto
;;
	c0    goto L126?3 ## goto
;;								## 1
.trace 15
L136?3:
	c0    zxtb $r0.8 = $r0.12   ## [spec] bblock 41, line 401-3,  t440(I8),  t441(SI16)
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 2[$r0.7] = $r0.3   ## bblock 48, line 405-2, t835, 255(I32)
	c0    cmpgt $b0.0 = $r0.8, 25   ## [spec] bblock 41, line 402-3,  t1189(I1),  t440(I8),  25(SI32)
	c0    brf $b0.3, L141?3   ## bblock 49, line 400-3,  t1191(I1)
;;								## 1
	c0    goto L138?3 ## goto
;;								## 2
.trace 49
L141?3:
	c0    goto L137?3 ## goto
;;								## 0
.trace 41
L134?3:
	c0    add $r0.3 = $r0.14, 1   ## bblock 15, line 0,  t910,  t910,  1(I32)
	c0    add $r0.11 = $r0.17, 4200   ## bblock 15, line 0,  t909,  t909,  4200(I32)
	c0    mov $r0.8 = $r0.15   ## t227
;;								## 0
	c0    add $r0.12 = $r0.18, 4200   ## bblock 15, line 0,  t908,  t908,  4200(I32)
	c0    add $r0.10 = $r0.16, 1050   ## bblock 15, line 0,  t906,  t906,  1050(I32)
	      ## goto
;;
	c0    goto L126?3 ## goto
;;								## 1
.trace 14
L133?3:
	c0    zxtb $r0.10 = $r0.11   ## [spec] bblock 47, line 401-2,  t206(I8),  t431(SI16)
	c0    ldw.d $r0.9 = 12[$r0.2]   ## [spec] bblock 41, line 401-3, t450, t832
	c0    mov $r0.8 = 255   ## 255(I32)
;;								## 0
	c0    stb 1[$r0.7] = $r0.8   ## bblock 54, line 405-1, t835, 255(I32)
	c0    cmpgt $b0.1 = $r0.10, 25   ## [spec] bblock 47, line 402-2,  t1190(I1),  t206(I8),  25(SI32)
	c0    brf $b0.2, L142?3   ## bblock 55, line 400-2,  t1193(I1)
;;								## 1
;;								## 2
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 41, line 401-3,  t448,  t450,  t449
;;								## 3
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 41, line 401-3,  t447,  t448,  8(I32)
;;								## 4
	c0    shr $r0.12 = $r0.9, 16   ## [spec] bblock 41, line 401-3,  t441(SI16),  t447,  16(SI32)
;;								## 5
	c0    zxtb $r0.3 = $r0.12   ## [spec] bblock 41, line 401-3,  t440(I8),  t441(SI16)
	c0    goto L135?3 ## goto
;;								## 6
.trace 48
L142?3:
	c0    goto L134?3 ## goto
;;								## 0
.trace 33
L131?3:
	c0    add $r0.3 = $r0.14, 1   ## bblock 15, line 0,  t910,  t910,  1(I32)
	c0    add $r0.11 = $r0.17, 4200   ## bblock 15, line 0,  t909,  t909,  4200(I32)
	c0    mov $r0.8 = $r0.15   ## t227
;;								## 0
	c0    add $r0.12 = $r0.18, 4200   ## bblock 15, line 0,  t908,  t908,  4200(I32)
	c0    add $r0.10 = $r0.16, 1050   ## bblock 15, line 0,  t906,  t906,  1050(I32)
	      ## goto
;;
	c0    goto L126?3 ## goto
;;								## 1
.trace 13
L130?3:
	c0    zxtb $r0.8 = $r0.11   ## [spec] bblock 47, line 401-2,  t206(I8),  t431(SI16)
	c0    shl $r0.12 = $r0.12, 8   ## [spec] bblock 41, line 401-3,  t447,  t448,  8(I32)
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 0[$r0.7] = $r0.3   ## bblock 17, line 405, t835, 255(I32)
	c0    brf $b0.1, L131?3   ## bblock 18, line 400-1,  t1170(I1)
	      ## goto
;;
	c0    goto L132?3 ## goto
;;								## 1
.trace 28
L129?3:
	c0    add $r0.11 = $r0.17, 4200   ## bblock 15, line 0,  t909,  t909,  4200(I32)
	c0    add $r0.12 = $r0.18, 4200   ## bblock 15, line 0,  t908,  t908,  4200(I32)
;;								## 0
	c0    add $r0.3 = $r0.14, 1   ## bblock 15, line 0,  t910,  t910,  1(I32)
	c0    add $r0.10 = $r0.16, 1050   ## bblock 15, line 0,  t906,  t906,  1050(I32)
	c0    mov $r0.8 = $r0.15   ## t227
	      ## goto
;;
	c0    goto L126?3 ## goto
;;								## 1
.trace 56
L127?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 12, line 415,  t214,  ?2.4?2auto_size(I32),  t213
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.4?2auto_size, 0x0
 ## End deriche_slow
.section .bss
.section .data
.section .data
.import out
.type out,@object
.import in
.type in,@object
.comm qt, 0x602160, 4
.comm qy2, 0x602160, 4
.comm qy1, 0x602160, 4
.comm at, 0x602160, 4
.comm ay2, 0x602160, 4
.comm ay1, 0x602160, 4
.comm t, 0x602160, 4
.comm y2, 0x602160, 4
.comm y1, 0x602160, 4
.section .text
.import _r_ilfloat
.type _r_ilfloat,@function
.import _r_ufloat
.type _r_ufloat,@function
.import _r_ufix
.type _r_ufix,@function
.import _r_mul
.type _r_mul,@function
.import _r_add
.type _r_add,@function
