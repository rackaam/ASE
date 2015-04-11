 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/matthias/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./risc.mm -DVEX -o edge_detect -lvexsimd"
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
.trace 26
	c0    add $r0.1 = $r0.1, (-0xc0)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t209
;;								## 1
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
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 0, line 0,  t559,  0(I32),  t222
;;								## 10
	c0    mov $r0.2 = $r0.3   ## bblock 0, line 0,  t558,  t559
;;								## 11
	c0    mov $r0.5 = (in + 0)   ## bblock 0, line 0,  t555,  addr(in?1.0)(P32)
;;								## 12
	c0    mov $r0.3 = $r0.4   ## t223
;;								## 13
	c0    mov $r0.4 = (y1 + 0)   ## bblock 0, line 0,  t557,  addr(y1?1.0)(P32)
;;								## 14
.trace 14
L0?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 1, line 55,  t579(I1),  t558,  0(SI32)
;;								## 0
	c0    stw 0x60[$r0.1] = $r0.3  ## spill ## t223
;;								## 1
	c0    stw 0x64[$r0.1] = $r0.4  ## spill ## t557
;;								## 2
	c0    stw 0x68[$r0.1] = $r0.5  ## spill ## t555
;;								## 3
	c0    brf $b0.0, L1?3   ## bblock 1, line 55,  t579(I1)
;;								## 4
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 36, line 0,  t315,  0(I32),  t223
;;								## 5
	c0    mov $r0.57 = $r0.3   ## bblock 36, line 0,  t314,  t315
;;								## 6
	c0    mov $r0.62 = $r0.4   ## bblock 36, line 0,  t313,  t557
;;								## 7
	c0    mov $r0.61 = $r0.5   ## bblock 36, line 0,  t312,  t555
;;								## 8
	c0    mov $r0.60 = $r0.0   ## bblock 36, line 56,  t246,  0.000000e+00=0x0(F32)
;;								## 9
	c0    mov $r0.59 = $r0.0   ## bblock 36, line 56,  t244,  0.000000e+00=0x0(F32)
;;								## 10
	c0    mov $r0.58 = $r0.0   ## bblock 36, line 56,  t243,  0.000000e+00=0x0(F32)
;;								## 11
	c0    mov $r0.63 = $r0.2   ## t558
;;								## 12
.trace 3
L2?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 37, line 57,  t603(I1),  t314,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L3?3   ## bblock 37, line 57,  t603(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t243
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 58,  raddr(_r_mul)(P32),  t243,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x28[$r0.1] = $r0.3  ## spill ## t10
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 39, line 58,  t243,  t244
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t244
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 58,  raddr(_r_mul)(P32),  t244,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x2c[$r0.1] = $r0.3  ## spill ## t13
;;								## 10
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t246
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 58,  raddr(_r_mul)(P32),  t246,  1.102090e-01=0x3de1b542(F32)
;;								## 13
	c0    stw 0x30[$r0.1] = $r0.3  ## spill ## t16
;;								## 14
	c0    ldbu $r0.59 = 0[$r0.61]   ## bblock 39, line 58, t31(I8), t312
	      xnop 2
;;								## 17
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 18
.call _r_ilfloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ilfloat   ## bblock 39, line 58,  raddr(_r_ilfloat)(P32),  t31(I8)
;;								## 19
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
;;								## 20
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 58,  raddr(_r_mul)(P32),  t21,  -1.886820e-01=0xbe4135db(F32)
;;								## 21
	c0    stw 0x34[$r0.1] = $r0.3  ## spill ## t23
;;								## 22
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t10
;;								## 23
	c0    ldw $r0.4 = 0x2c[$r0.1]  ## restore ## t13
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 58,  raddr(_r_add)(P32),  t10,  t13
;;								## 26
	c0    ldw $r0.4 = 0x30[$r0.1]  ## restore ## t16
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 58,  raddr(_r_add)(P32),  t207,  t16
;;								## 29
	c0    ldw $r0.4 = 0x34[$r0.1]  ## restore ## t23
	      xnop 1
;;								## 31
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 58,  raddr(_r_add)(P32),  t208,  t23
;;								## 32
	c0    stw 0x38[$r0.1] = $r0.3  ## spill ## t244
;;								## 33
	c0    stw 0[$r0.62] = $r0.3   ## bblock 39, line 58, t313, t244
;;								## 34
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 35
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ufloat   ## bblock 39, line 59,  raddr(_r_ufloat)(P32),  t31(I8)
;;								## 36
	c0    add $r0.61 = $r0.61, 1   ## bblock 39, line 0,  t312,  t312,  1(I32)
;;								## 37
	c0    add $r0.62 = $r0.62, 4   ## bblock 39, line 0,  t313,  t313,  4(I32)
;;								## 38
	c0    add $r0.57 = $r0.57, 1   ## bblock 39, line 0,  t314,  t314,  1(I32)
;;								## 39
	c0    ldw $r0.59 = 0x38[$r0.1]  ## restore ## t244
;;								## 40
	c0    mov $r0.60 = $r0.3   ## t246
;;								## 41
	c0    goto L2?3 ## goto
;;								## 42
.trace 20
L3?3:
	c0    ldw $r0.5 = 0x68[$r0.1]  ## restore ## t555
;;								## 0
	c0    ldw $r0.4 = 0x64[$r0.1]  ## restore ## t557
;;								## 1
	c0    add $r0.2 = $r0.63, 1   ## bblock 38, line 0,  t558,  t558,  1(I32)
;;								## 2
	c0    add $r0.5 = $r0.5, 1050   ## bblock 38, line 0,  t555,  t555,  1050(I32)
;;								## 3
	c0    add $r0.4 = $r0.4, 4200   ## bblock 38, line 0,  t557,  t557,  4200(I32)
;;								## 4
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t223
	      xnop 1
;;								## 6
	c0    goto L0?3 ## goto
;;								## 7
.trace 27
L1?3:
	c0    stw 0x60[$r0.1] = $r0.3  ## spill ## t223
;;								## 0
	c0    ldw $r0.7 = 0x80[$r0.1]  ## restore ## t222
;;								## 1
	c0    mov $r0.6 = (y2 + 0)   ## bblock 2, line 0,  t531,  addr(y2?1.0)(P32)
;;								## 2
	c0    add $r0.5 = $r0.3, -1   ## bblock 2, line 68,  t309,  t223,  -1(SI32)
;;								## 3
	c0    sub $r0.7 = $r0.0, $r0.7   ## bblock 2, line 0,  t534,  0(I32),  t222
;;								## 4
	c0    mov $r0.2 = $r0.7   ## bblock 2, line 0,  t533,  t534
;;								## 5
	c0    mov $r0.4 = (in + 0)   ## bblock 2, line 0,  t532,  addr(in?1.0)(P32)
;;								## 6
.trace 15
L4?3:
	c0    stw 0x6c[$r0.1] = $r0.2  ## spill ## t533
;;								## 0
	c0    stw 0x70[$r0.1] = $r0.4  ## spill ## t532
;;								## 1
	c0    stw 0x74[$r0.1] = $r0.5  ## spill ## t309
;;								## 2
	c0    stw 0x78[$r0.1] = $r0.6  ## spill ## t531
;;								## 3
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 3, line 66,  t580(I1),  t533,  0(SI32)
;;								## 4
	c0    add $r0.62 = $r0.4, $r0.5   ## [spec] bblock 32, line 0,  t335,  t532,  t309
;;								## 5
	c0    brf $b0.0, L5?3   ## bblock 3, line 66,  t580(I1)
;;								## 6
	c0    sh2add $r0.63 = $r0.5, $r0.6   ## bblock 32, line 0,  t334,  t309,  t531
;;								## 7
	c0    mov $r0.61 = $r0.0   ## bblock 32, line 67,  t242,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.60 = $r0.0   ## bblock 32, line 67,  t241,  0.000000e+00=0x0(F32)
;;								## 9
	c0    mov $r0.59 = $r0.0   ## bblock 32, line 67,  t238,  0.000000e+00=0x0(F32)
;;								## 10
	c0    mov $r0.58 = $r0.0   ## bblock 32, line 67,  t237,  0.000000e+00=0x0(F32)
;;								## 11
	c0    mov $r0.57 = $r0.5   ## bblock 32, line 68,  t297,  t309
;;								## 12
.trace 2
L6?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 33, line 68,  t602(I1),  t297,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L7?3   ## bblock 33, line 68,  t602(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t237
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 69,  raddr(_r_mul)(P32),  t237,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x14[$r0.1] = $r0.3  ## spill ## t49
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 35, line 69,  t237,  t238
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t238
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 69,  raddr(_r_mul)(P32),  t238,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x18[$r0.1] = $r0.3  ## spill ## t52
;;								## 10
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t241
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 69,  raddr(_r_mul)(P32),  t241,  -1.886820e-01=0xbe4135db(F32)
;;								## 13
	c0    stw 0x1c[$r0.1] = $r0.3  ## spill ## t55
;;								## 14
	c0    mov $r0.60 = $r0.61   ## bblock 35, line 69,  t241,  t242
;;								## 15
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
;;								## 16
	c0    mov $r0.3 = $r0.61   ## t242
;;								## 17
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 69,  raddr(_r_mul)(P32),  t242,  -1.836820e-01=0xbe3c1722(F32)
;;								## 18
	c0    stw 0x20[$r0.1] = $r0.3  ## spill ## t58
;;								## 19
	c0    ldw $r0.3 = 0x14[$r0.1]  ## restore ## t49
;;								## 20
	c0    ldw $r0.4 = 0x18[$r0.1]  ## restore ## t52
	      xnop 1
;;								## 22
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 69,  raddr(_r_add)(P32),  t49,  t52
;;								## 23
	c0    ldw $r0.4 = 0x1c[$r0.1]  ## restore ## t55
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 69,  raddr(_r_add)(P32),  t205,  t55
;;								## 26
	c0    ldw $r0.4 = 0x20[$r0.1]  ## restore ## t58
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 69,  raddr(_r_add)(P32),  t206,  t58
;;								## 29
	c0    stw 0x24[$r0.1] = $r0.3  ## spill ## t238
;;								## 30
	c0    ldbu $r0.2 = 0[$r0.62]   ## bblock 35, line 71, t67(I8), t335
;;								## 31
	c0    stw 0[$r0.63] = $r0.3   ## bblock 35, line 69, t334, t238
	      xnop 1
;;								## 33
	c0    mov $r0.3 = $r0.2   ## t67(I8)
;;								## 34
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ufloat   ## bblock 35, line 71,  raddr(_r_ufloat)(P32),  t67(I8)
;;								## 35
	c0    add $r0.57 = $r0.57, -1   ## bblock 35, line 68,  t297,  t297,  -1(SI32)
;;								## 36
	c0    add $r0.63 = $r0.63, (~0x3)   ## bblock 35, line 0,  t334,  t334,  (~0x3)(I32)
;;								## 37
	c0    add $r0.62 = $r0.62, (~0x0)   ## bblock 35, line 0,  t335,  t335,  (~0x0)(I32)
;;								## 38
	c0    ldw $r0.59 = 0x24[$r0.1]  ## restore ## t238
;;								## 39
	c0    mov $r0.61 = $r0.3   ## t242
;;								## 40
	c0    goto L6?3 ## goto
;;								## 41
.trace 21
L7?3:
	c0    ldw $r0.6 = 0x78[$r0.1]  ## restore ## t531
;;								## 0
	c0    ldw $r0.4 = 0x70[$r0.1]  ## restore ## t532
;;								## 1
	c0    ldw $r0.2 = 0x6c[$r0.1]  ## restore ## t533
;;								## 2
	c0    add $r0.6 = $r0.6, 4200   ## bblock 34, line 0,  t531,  t531,  4200(I32)
;;								## 3
	c0    add $r0.4 = $r0.4, 1050   ## bblock 34, line 0,  t532,  t532,  1050(I32)
;;								## 4
	c0    add $r0.2 = $r0.2, 1   ## bblock 34, line 0,  t533,  t533,  1(I32)
;;								## 5
	c0    ldw $r0.5 = 0x74[$r0.1]  ## restore ## t309
	      xnop 1
;;								## 7
	c0    goto L4?3 ## goto
;;								## 8
.trace 29
L5?3:
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
;;								## 0
	c0    mov $r0.61 = (t + 0)   ## bblock 4, line 0,  t500,  addr(t?1.0)(P32)
;;								## 1
	c0    mov $r0.59 = (y1 + 0)   ## bblock 4, line 0,  t501,  addr(y1?1.0)(P32)
;;								## 2
	c0    sub $r0.4 = $r0.0, $r0.4   ## bblock 4, line 0,  t504,  0(I32),  t222
;;								## 3
	c0    mov $r0.2 = $r0.4   ## bblock 4, line 0,  t503,  t504
;;								## 4
	c0    mov $r0.58 = (y2 + 0)   ## bblock 4, line 0,  t502,  addr(y2?1.0)(P32)
;;								## 5
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t223
	      xnop 1
;;								## 7
;;								## 8
.trace 16
L8?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 5, line 78,  t581(I1),  t503,  0(SI32)
;;								## 0
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 28, line 0,  t358,  0(I32),  t223
;;								## 1
	c0    brf $b0.0, L9?3   ## bblock 5, line 78,  t581(I1)
;;								## 2
	c0    mov $r0.60 = $r0.4   ## bblock 28, line 0,  t357,  t358
;;								## 3
	c0    mov $r0.57 = $r0.0   ## bblock 28, line 79,  t299,  0(SI32)
;;								## 4
	c0    mov $r0.62 = $r0.2   ## t503
;;								## 5
	c0    mov $r0.63 = $r0.3   ## t223
;;								## 6
.trace 1
L10?3:
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 31, line 80,  t599,  t299,  t502
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 31, line 80, t85, t599
;;								## 1
	c0    sh2add $r0.2 = $r0.57, $r0.59   ## [spec] bblock 31, line 80,  t600,  t299,  t501
;;								## 2
	c0    ldw.d $r0.4 = 0[$r0.2]   ## [spec] bblock 31, line 80, t89, t600
;;								## 3
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 29, line 79,  t598(I1),  t357,  0(SI32)
	      xnop 1
;;								## 5
	c0    brf $b0.0, L11?3   ## bblock 29, line 79,  t598(I1)
;;								## 6
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 31, line 80,  raddr(_r_add)(P32),  t85,  t89
;;								## 7
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 31, line 80,  raddr(_r_mul)(P32),  t90,  1.000000e+00=0x3f800000(F32)
;;								## 9
	c0    sh2add $r0.2 = $r0.57, $r0.61   ## bblock 31, line 80,  t601,  t299,  t500
;;								## 10
	c0    add $r0.57 = $r0.57, 1   ## bblock 31, line 79,  t299,  t299,  1(SI32)
;;								## 11
	c0    add $r0.60 = $r0.60, 1   ## bblock 31, line 0,  t357,  t357,  1(I32)
;;								## 12
	c0    stw 0[$r0.2] = $r0.3   ## bblock 31, line 80, t601, t92
	      ## goto
;;
	c0    goto L10?3 ## goto
;;								## 13
.trace 22
L11?3:
	c0    mov $r0.4 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.61 = $r0.61, $r0.4   ## bblock 30, line 0,  t500,  t500,  4200(I32)
;;								## 1
	c0    add $r0.59 = $r0.59, $r0.4   ## bblock 30, line 0,  t501,  t501,  4200(I32)
;;								## 2
	c0    add $r0.58 = $r0.58, $r0.4   ## bblock 30, line 0,  t502,  t502,  4200(I32)
;;								## 3
	c0    add $r0.2 = $r0.62, 1   ## bblock 30, line 0,  t503,  t503,  1(I32)
;;								## 4
	c0    mov $r0.3 = $r0.63   ## t223
	      ## goto
;;
	c0    goto L8?3 ## goto
;;								## 5
.trace 28
L9?3:
	c0    stw 0x60[$r0.1] = $r0.3  ## spill ## t223
;;								## 0
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 6, line 0,  t481,  0(I32),  t223
;;								## 1
	c0    mov $r0.2 = $r0.3   ## bblock 6, line 0,  t480,  t481
;;								## 2
	c0    mov $r0.63 = (y1 + 0)   ## bblock 6, line 0,  t478,  addr(y1?1.0)(P32)
;;								## 3
	c0    mov $r0.62 = (t + 0)   ## bblock 6, line 0,  t479,  addr(t?1.0)(P32)
;;								## 4
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
	      xnop 1
;;								## 6
;;								## 7
.trace 17
L12?3:
	c0    stw 0x7c[$r0.1] = $r0.2  ## spill ## t480
;;								## 0
	c0    stw 0x80[$r0.1] = $r0.4  ## spill ## t222
;;								## 1
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 7, line 83,  t582(I1),  t480,  0(SI32)
;;								## 2
	c0    sub $r0.4 = $r0.0, $r0.4   ## [spec] bblock 24, line 0,  t373,  0(I32),  t222
;;								## 3
	c0    brf $b0.0, L13?3   ## bblock 7, line 83,  t582(I1)
;;								## 4
	c0    mov $r0.57 = $r0.4   ## bblock 24, line 0,  t372,  t373
;;								## 5
	c0    mov $r0.61 = $r0.0   ## bblock 24, line 0,  t367,  0(I32)
;;								## 6
	c0    mov $r0.60 = $r0.0   ## bblock 24, line 84,  t245,  0.000000e+00=0x0(F32)
;;								## 7
	c0    mov $r0.59 = $r0.0   ## bblock 24, line 84,  t302,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.58 = $r0.0   ## bblock 24, line 84,  t303,  0.000000e+00=0x0(F32)
;;								## 9
.trace 5
L14?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 25, line 85,  t595(I1),  t372,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L15?3   ## bblock 25, line 85,  t595(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t303
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 86,  raddr(_r_mul)(P32),  t303,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x3c[$r0.1] = $r0.3  ## spill ## t106
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 27, line 86,  t303,  t302
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t302
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 86,  raddr(_r_mul)(P32),  t302,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x40[$r0.1] = $r0.3  ## spill ## t109
;;								## 10
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t245
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 86,  raddr(_r_mul)(P32),  t245,  1.102090e-01=0x3de1b542(F32)
;;								## 13
	c0    stw 0x44[$r0.1] = $r0.3  ## spill ## t112
;;								## 14
	c0    sh3add $r0.2 = $r0.61, $r0.62   ## bblock 27, line 86,  t596,  t367,  t479
;;								## 15
	c0    ldw $r0.60 = 0[$r0.2]   ## bblock 27, line 86, t245, t596
;;								## 16
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
	      xnop 1
;;								## 18
	c0    mov $r0.3 = $r0.60   ## t245
;;								## 19
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 86,  raddr(_r_mul)(P32),  t245,  -1.886820e-01=0xbe4135db(F32)
;;								## 20
	c0    stw 0x48[$r0.1] = $r0.3  ## spill ## t118
;;								## 21
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t106
;;								## 22
	c0    ldw $r0.4 = 0x40[$r0.1]  ## restore ## t109
	      xnop 1
;;								## 24
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 86,  raddr(_r_add)(P32),  t106,  t109
;;								## 25
	c0    ldw $r0.4 = 0x44[$r0.1]  ## restore ## t112
	      xnop 1
;;								## 27
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 86,  raddr(_r_add)(P32),  t203,  t112
;;								## 28
	c0    ldw $r0.4 = 0x48[$r0.1]  ## restore ## t118
	      xnop 1
;;								## 30
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 86,  raddr(_r_add)(P32),  t204,  t118
;;								## 31
	c0    sh3add $r0.2 = $r0.61, $r0.63   ## bblock 27, line 86,  t597,  t367,  t478
;;								## 32
	c0    add $r0.61 = $r0.61, 525   ## bblock 27, line 0,  t367,  t367,  525(I32)
;;								## 33
	c0    add $r0.57 = $r0.57, 1   ## bblock 27, line 0,  t372,  t372,  1(I32)
;;								## 34
	c0    mov $r0.59 = $r0.3   ## t302
;;								## 35
	c0    stw 0[$r0.2] = $r0.3   ## bblock 27, line 86, t597, t302
	      ## goto
;;
	c0    goto L14?3 ## goto
;;								## 36
.trace 25
L15?3:
	c0    add $r0.63 = $r0.63, 4   ## bblock 26, line 0,  t478,  t478,  4(I32)
;;								## 0
	c0    add $r0.62 = $r0.62, 4   ## bblock 26, line 0,  t479,  t479,  4(I32)
;;								## 1
	c0    ldw $r0.2 = 0x7c[$r0.1]  ## restore ## t480
;;								## 2
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
	      xnop 1
;;								## 4
	c0    add $r0.2 = $r0.2, 1   ## bblock 26, line 0,  t480,  t480,  1(I32)
	      ## goto
;;
	c0    goto L12?3 ## goto
;;								## 5
.trace 31
L13?3:
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t223
;;								## 0
	c0    mov $r0.4 = (t + 0)   ## bblock 8, line 0,  t457,  addr(t?1.0)(P32)
;;								## 1
	c0    stw 0x4c[$r0.1] = $r0.4  ## spill ## t457
;;								## 2
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 8, line 0,  t460,  0(I32),  t223
;;								## 3
	c0    mov $r0.2 = $r0.3   ## bblock 8, line 0,  t459,  t460
;;								## 4
	c0    mov $r0.63 = (y2 + 0)   ## bblock 8, line 0,  t458,  addr(y2?1.0)(P32)
;;								## 5
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
	      xnop 2
;;								## 8
	c0    add $r0.5 = $r0.4, -1   ## bblock 8, line 96,  t310,  t222,  -1(SI32)
;;								## 9
.trace 18
L16?3:
	c0    stw 0x84[$r0.1] = $r0.2  ## spill ## t459
;;								## 0
	c0    stw 0x88[$r0.1] = $r0.5  ## spill ## t310
;;								## 1
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 9, line 94,  t583(I1),  t459,  0(SI32)
;;								## 2
	c0    mpylu $r0.62 = $r0.5, 525   ## [spec] bblock 20, line 0,  t390,  t310,  525(I32)
;;								## 3
	c0    brf $b0.0, L17?3   ## bblock 9, line 94,  t583(I1)
;;								## 4
	c0    mov $r0.61 = $r0.0   ## bblock 20, line 95,  t240,  0.000000e+00=0x0(F32)
;;								## 5
	c0    mov $r0.60 = $r0.0   ## bblock 20, line 95,  t239,  0.000000e+00=0x0(F32)
;;								## 6
	c0    mov $r0.59 = $r0.0   ## bblock 20, line 95,  t306,  0.000000e+00=0x0(F32)
;;								## 7
	c0    mov $r0.58 = $r0.0   ## bblock 20, line 95,  t305,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.57 = $r0.5   ## bblock 20, line 96,  t307,  t310
;;								## 9
.trace 6
L18?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 21, line 96,  t592(I1),  t307,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L19?3   ## bblock 21, line 96,  t592(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t305
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 97,  raddr(_r_mul)(P32),  t305,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x50[$r0.1] = $r0.3  ## spill ## t143
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 23, line 97,  t305,  t306
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t306
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 97,  raddr(_r_mul)(P32),  t306,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x54[$r0.1] = $r0.3  ## spill ## t146
;;								## 10
	c0    mov $r0.4 = 0x3dea600b   ## 1.144410e-01=0x3dea600b(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t239
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 97,  raddr(_r_mul)(P32),  t239,  1.144410e-01=0x3dea600b(F32)
;;								## 13
	c0    stw 0x58[$r0.1] = $r0.3  ## spill ## t149
;;								## 14
	c0    mov $r0.60 = $r0.61   ## bblock 23, line 97,  t239,  t240
;;								## 15
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
;;								## 16
	c0    mov $r0.3 = $r0.61   ## t240
;;								## 17
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 97,  raddr(_r_mul)(P32),  t240,  -1.836820e-01=0xbe3c1722(F32)
;;								## 18
	c0    stw 0x5c[$r0.1] = $r0.3  ## spill ## t152
;;								## 19
	c0    ldw $r0.3 = 0x50[$r0.1]  ## restore ## t143
;;								## 20
	c0    ldw $r0.4 = 0x54[$r0.1]  ## restore ## t146
	      xnop 1
;;								## 22
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 97,  raddr(_r_add)(P32),  t143,  t146
;;								## 23
	c0    ldw $r0.4 = 0x58[$r0.1]  ## restore ## t149
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 97,  raddr(_r_add)(P32),  t201,  t149
;;								## 26
	c0    ldw $r0.4 = 0x5c[$r0.1]  ## restore ## t152
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 97,  raddr(_r_add)(P32),  t202,  t152
;;								## 29
	c0    sh3add $r0.4 = $r0.62, $r0.63   ## bblock 23, line 97,  t593,  t390,  t458
;;								## 30
	c0    ldw $r0.2 = 0x4c[$r0.1]  ## restore ## t457
;;								## 31
	c0    add $r0.57 = $r0.57, -1   ## bblock 23, line 96,  t307,  t307,  -1(SI32)
;;								## 32
	c0    mov $r0.59 = $r0.3   ## t306
;;								## 33
	c0    sh3add $r0.5 = $r0.62, $r0.2   ## bblock 23, line 99,  t594,  t390,  t457
;;								## 34
	c0    ldw $r0.61 = 0[$r0.5]   ## bblock 23, line 99, t240, t594
;;								## 35
	c0    add $r0.62 = $r0.62, (~0x20c)   ## bblock 23, line 0,  t390,  t390,  (~0x20c)(I32)
;;								## 36
	c0    stw 0[$r0.4] = $r0.3   ## bblock 23, line 97, t593, t306
	      ## goto
;;
	c0    goto L18?3 ## goto
;;								## 37
.trace 24
L19?3:
	c0    ldw $r0.3 = 0x4c[$r0.1]  ## restore ## t457
;;								## 0
	c0    add $r0.63 = $r0.63, 4   ## bblock 22, line 0,  t458,  t458,  4(I32)
;;								## 1
	c0    ldw $r0.2 = 0x84[$r0.1]  ## restore ## t459
;;								## 2
	c0    add $r0.3 = $r0.3, 4   ## bblock 22, line 0,  t457,  t457,  4(I32)
;;								## 3
	c0    stw 0x4c[$r0.1] = $r0.3  ## spill ## t457
;;								## 4
	c0    add $r0.2 = $r0.2, 1   ## bblock 22, line 0,  t459,  t459,  1(I32)
;;								## 5
	c0    ldw $r0.5 = 0x88[$r0.1]  ## restore ## t310
	      xnop 1
;;								## 7
	c0    goto L16?3 ## goto
;;								## 8
.trace 30
L17?3:
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t222
;;								## 0
	c0    mov $r0.61 = (out + 0)   ## bblock 10, line 0,  t426,  addr(out?1.0)(P32)
;;								## 1
	c0    mov $r0.59 = (y1 + 0)   ## bblock 10, line 0,  t428,  addr(y1?1.0)(P32)
;;								## 2
	c0    sub $r0.4 = $r0.0, $r0.4   ## bblock 10, line 0,  t431,  0(I32),  t222
;;								## 3
	c0    mov $r0.2 = $r0.4   ## bblock 10, line 0,  t430,  t431
;;								## 4
	c0    mov $r0.58 = (y2 + 0)   ## bblock 10, line 0,  t429,  addr(y2?1.0)(P32)
;;								## 5
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t223
	      xnop 1
;;								## 7
;;								## 8
.trace 19
L20?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 11, line 106,  t584(I1),  t430,  0(SI32)
;;								## 0
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 13, line 0,  t415,  0(I32),  t223
;;								## 1
	c0    brf $b0.0, L21?3   ## bblock 11, line 106,  t584(I1)
;;								## 2
	c0    mov $r0.60 = $r0.4   ## bblock 13, line 0,  t414,  t415
;;								## 3
	c0    mov $r0.57 = $r0.0   ## bblock 13, line 107,  t308,  0(SI32)
;;								## 4
	c0    mov $r0.62 = $r0.2   ## t430
;;								## 5
	c0    mov $r0.63 = $r0.3   ## t223
;;								## 6
.trace 4
L22?3:
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 16, line 108,  t586,  t308,  t429
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 16, line 108, t178, t586
;;								## 1
	c0    sh2add $r0.5 = $r0.57, $r0.59   ## [spec] bblock 16, line 108,  t587,  t308,  t428
;;								## 2
	c0    ldw.d $r0.4 = 0[$r0.5]   ## [spec] bblock 16, line 108, t182, t587
;;								## 3
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 14, line 107,  t585(I1),  t414,  0(SI32)
	      xnop 1
;;								## 5
	c0    brf $b0.0, L23?3   ## bblock 14, line 107,  t585(I1)
;;								## 6
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 16, line 108,  raddr(_r_add)(P32),  t178,  t182
;;								## 7
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 16, line 108,  raddr(_r_mul)(P32),  t183,  1.000000e+00=0x3f800000(F32)
;;								## 9
.call _r_ufix, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = _r_ufix   ## bblock 16, line 108,  raddr(_r_ufix)(P32),  t185
;;								## 10
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 16, line 108,  t588,  t308,  t426
;;								## 11
	c0    zxtb $r0.4 = $r0.3   ## bblock 16, line 108,  t187(I8),  t186(I8)
;;								## 12
	c0    cmpgt $b0.0 = $r0.4, 25   ## bblock 16, line 109,  t589(I1),  t187(I8),  25(SI32)
;;								## 13
	c0    add $r0.5 = $r0.57, $r0.61   ## [spec] bblock 19, line 110,  t591,  t308,  t426
;;								## 14
	c0    stb 0[$r0.2] = $r0.3   ## bblock 16, line 108, t588, t186(I8)
;;								## 15
	c0    brf $b0.0, L24?3   ## bblock 16, line 109,  t589(I1)
;;								## 16
	c0    add $r0.57 = $r0.57, 1   ## bblock 18, line 107,  t308,  t308,  1(SI32)
;;								## 17
	c0    add $r0.60 = $r0.60, 1   ## bblock 18, line 0,  t414,  t414,  1(I32)
;;								## 18
	c0    stb 0[$r0.5] = $r0.0   ## bblock 19, line 110, t591, 0(I32)
	      ## goto
;;
	c0    goto L22?3 ## goto
;;								## 19
.trace 13
L24?3:
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 17, line 112,  t590,  t308,  t426
;;								## 0
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 1
	c0    add $r0.60 = $r0.60, 1   ## bblock 18, line 0,  t414,  t414,  1(I32)
;;								## 2
	c0    add $r0.57 = $r0.57, 1   ## bblock 18, line 107,  t308,  t308,  1(SI32)
;;								## 3
	c0    stb 0[$r0.2] = $r0.3   ## bblock 17, line 112, t590, 255(I32)
	      ## goto
;;
	c0    goto L22?3 ## goto
;;								## 4
.trace 23
L23?3:
	c0    add $r0.61 = $r0.61, 1050   ## bblock 15, line 0,  t426,  t426,  1050(I32)
;;								## 0
	c0    add $r0.59 = $r0.59, 4200   ## bblock 15, line 0,  t428,  t428,  4200(I32)
;;								## 1
	c0    add $r0.58 = $r0.58, 4200   ## bblock 15, line 0,  t429,  t429,  4200(I32)
;;								## 2
	c0    add $r0.2 = $r0.62, 1   ## bblock 15, line 0,  t430,  t430,  1(I32)
;;								## 3
	c0    mov $r0.3 = $r0.63   ## t223
	      ## goto
;;
	c0    goto L20?3 ## goto
;;								## 4
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
	c0    return $r0.1 = $r0.1, (0xc0), $l0.0   ## bblock 12, line 116,  t210,  ?2.1?2auto_size(I32),  t209
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
 ## Begin deriche_slow
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_slow::
.trace 47
	      ## auto_size == 0
;;								## 0
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t1117,  0(I32),  t226
;;								## 1
	c0    mov $r0.11 = (in + 0)   ## bblock 0, line 0,  t1113,  addr(in?1.0)(P32)
;;								## 2
	c0    mov $r0.19 = $r0.3   ## t226
;;								## 3
	c0    mov $r0.3 = $r0.2   ## bblock 0, line 0,  t1116,  t1117
;;								## 4
	c0    mov $r0.10 = (qy1 + 0)   ## bblock 0, line 0,  t1115,  addr(qy1?1.0)(P32)
;;								## 5
	c0    mov $r0.9 = $r0.4   ## t227
;;								## 6
.trace 17
L25?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 1, line 138,  t1162(I1),  t1116,  0(SI32)
;;								## 0
	c0    sub $r0.12 = 3, $r0.9   ## [spec] bblock 36, line 0,  t519,  3(I32),  t227
;;								## 1
	c0    brf $b0.0, L26?3   ## bblock 1, line 138,  t1162(I1)
;;								## 2
	c0    mov $r0.7 = $r0.12   ## bblock 36, line 0,  t518,  t519
;;								## 3
	c0    mov $r0.8 = $r0.10   ## bblock 36, line 0,  t517,  t1115
;;								## 4
	c0    mov $r0.5 = $r0.0   ## bblock 36, line 139,  t255,  0(SI32)
;;								## 5
	c0    mov $r0.4 = $r0.0   ## bblock 36, line 139,  t256,  0(SI32)
;;								## 6
	c0    mov $r0.2 = $r0.11   ## bblock 36, line 0,  t516,  t1113
;;								## 7
	c0    mov $r0.6 = $r0.0   ## bblock 36, line 139,  t258,  0(SI32)
;;								## 8
	c0    mov $r0.15 = $r0.3   ## t1116
;;								## 9
	c0    mov $r0.16 = $r0.9   ## t227
;;								## 10
	c0    mov $r0.17 = $r0.10   ## t1115
;;								## 11
	c0    mov $r0.18 = $r0.11   ## t1113
;;								## 12
.trace 3
L27?3:
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 39, line 142, t342, t516
;;								## 0
	c0    mpyl $r0.9 = $r0.4, 215   ## [spec] bblock 39, line 144,  t19,  t256,  215(SI32)
;;								## 1
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 39, line 145,  t23,  t255,  -155(SI32)
;;								## 2
	c0    mpyl $r0.10 = $r0.3, -48   ## [spec] bblock 39, line 142,  t28,  t342,  -48(SI32)
;;								## 3
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 39, line 144,  t26(SI24),  t19,  8(SI32)
;;								## 4
	c0    add $r0.10 = $r0.10, $r0.9   ## [spec] bblock 39, line 146,  t1187,  t28,  t26(SI24)
;;								## 5
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 39, line 145,  t25(SI24),  t23,  8(SI32)
;;								## 6
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 39, line 143,  t27,  t258,  28(SI32)
;;								## 7
	c0    cmplt $b0.0 = $r0.7, 3   ## bblock 37, line 140,  t1185(I1),  t518,  3(SI32)
;;								## 8
	c0    add $r0.6 = $r0.6, $r0.5   ## [spec] bblock 39, line 146,  t1186,  t27,  t25(SI24)
;;								## 9
	c0    add $r0.6 = $r0.6, $r0.10   ## [spec] bblock 39, line 146,  t341,  t1186,  t1187
;;								## 10
	c0    brf $b0.0, L28?3   ## bblock 37, line 140,  t1185(I1)
;;								## 11
	c0    cmplt $b0.0 = $r0.7, 2   ## bblock 39, line 140-1,  t1188(I1),  t518,  2(SI32)
;;								## 12
	c0    ldbu.d $r0.9 = 1[$r0.2]   ## [spec] bblock 106, line 142-1, t500, t516
;;								## 13
	c0    mpyl $r0.10 = $r0.6, 215   ## [spec] bblock 106, line 144-1,  t502,  t341,  215(SI32)
;;								## 14
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 106, line 145-1,  t504,  t256,  -155(SI32)
;;								## 15
	c0    mpyl $r0.11 = $r0.9, -48   ## [spec] bblock 106, line 142-1,  t501,  t500,  -48(SI32)
;;								## 16
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 106, line 144-1,  t503(SI24),  t502,  8(SI32)
;;								## 17
	c0    add $r0.11 = $r0.11, $r0.10   ## [spec] bblock 106, line 146-1,  t1226,  t501,  t503(SI24)
;;								## 18
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 106, line 145-1,  t505(SI24),  t504,  8(SI32)
;;								## 19
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 106, line 143-1,  t499,  t342,  28(SI32)
;;								## 20
	c0    cmplt $b0.1 = $r0.7, 1   ## [spec] bblock 106, line 140-2,  t1227(I1),  t518,  1(SI32)
;;								## 21
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 106, line 146-1,  t1225,  t499,  t505(SI24)
;;								## 22
	c0    add $r0.3 = $r0.3, $r0.11   ## [spec] bblock 106, line 146-1,  t507,  t1225,  t1226
;;								## 23
	c0    ldbu.d $r0.10 = 2[$r0.2]   ## [spec] bblock 103, line 142-2, t489, t516
;;								## 24
	c0    mpyl $r0.11 = $r0.3, 215   ## [spec] bblock 103, line 144-2,  t491,  t507,  215(SI32)
;;								## 25
	c0    mpyl $r0.12 = $r0.6, -155   ## [spec] bblock 103, line 145-2,  t493,  t341,  -155(SI32)
;;								## 26
	c0    mpyl $r0.13 = $r0.10, -48   ## [spec] bblock 103, line 142-2,  t490,  t489,  -48(SI32)
;;								## 27
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 103, line 144-2,  t492(SI24),  t491,  8(SI32)
;;								## 28
	c0    add $r0.13 = $r0.13, $r0.11   ## [spec] bblock 103, line 146-2,  t1223,  t490,  t492(SI24)
;;								## 29
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 103, line 145-2,  t494(SI24),  t493,  8(SI32)
;;								## 30
	c0    mpyl $r0.9 = $r0.9, 28   ## [spec] bblock 103, line 143-2,  t488,  t500,  28(SI32)
;;								## 31
	c0    cmplt $b0.2 = $r0.7, $r0.0   ## [spec] bblock 103, line 140-3,  t1224(I1),  t518,  0(SI32)
;;								## 32
	c0    add $r0.9 = $r0.9, $r0.12   ## [spec] bblock 103, line 146-2,  t1222,  t488,  t494(SI24)
;;								## 33
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 103, line 146-2,  t496,  t1222,  t1223
;;								## 34
	c0    ldbu.d $r0.11 = 3[$r0.2]   ## [spec] bblock 100, line 142-3, t258, t516
;;								## 35
	c0    mpyl $r0.12 = $r0.9, 215   ## [spec] bblock 100, line 144-3,  t483,  t496,  215(SI32)
;;								## 36
	c0    mpyl $r0.13 = $r0.3, -155   ## [spec] bblock 100, line 145-3,  t485,  t507,  -155(SI32)
;;								## 37
	c0    mpyl $r0.14 = $r0.11, -48   ## [spec] bblock 100, line 142-3,  t482,  t258,  -48(SI32)
;;								## 38
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 100, line 144-3,  t484(SI24),  t483,  8(SI32)
;;								## 39
	c0    add $r0.14 = $r0.14, $r0.12   ## [spec] bblock 100, line 146-3,  t1221,  t482,  t484(SI24)
;;								## 40
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 100, line 145-3,  t486(SI24),  t485,  8(SI32)
;;								## 41
	c0    mpyl $r0.10 = $r0.10, 28   ## [spec] bblock 100, line 143-3,  t453,  t489,  28(SI32)
;;								## 42
	c0    mov $r0.5 = $r0.9   ## [spec] bblock 100, line 146-2,  t255,  t496
;;								## 43
	c0    add $r0.10 = $r0.10, $r0.13   ## [spec] bblock 100, line 146-3,  t1220,  t453,  t486(SI24)
;;								## 44
	c0    add $r0.4 = $r0.10, $r0.14   ## [spec] bblock 100, line 146-3,  t256,  t1220,  t1221
;;								## 45
	c0    add $r0.2 = $r0.2, 4   ## [spec] bblock 100, line 0,  t516,  t516,  4(I32)
;;								## 46
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 100, line 0,  t518,  t518,  4(I32)
;;								## 47
	c0    stw 0[$r0.8] = $r0.6   ## bblock 39, line 146, t517, t341
;;								## 48
	c0    brf $b0.0, L28?3   ## bblock 39, line 140-1,  t1188(I1)
;;								## 49
	c0    mov $r0.6 = $r0.11   ## [spec] t258
;;								## 50
	c0    stw 4[$r0.8] = $r0.3   ## bblock 106, line 146-1, t517, t507
;;								## 51
	c0    brf $b0.1, L28?3   ## bblock 106, line 140-2,  t1227(I1)
;;								## 52
	c0    stw 8[$r0.8] = $r0.9   ## bblock 103, line 146-2, t517, t496
;;								## 53
	c0    brf $b0.2, L28?3   ## bblock 103, line 140-3,  t1224(I1)
;;								## 54
	c0    stw 12[$r0.8] = $r0.4   ## bblock 100, line 146-3, t517, t256
;;								## 55
	c0    add $r0.8 = $r0.8, 16   ## bblock 100, line 0,  t517,  t517,  16(I32)
	      ## goto
;;
	c0    goto L27?3 ## goto
;;								## 56
.trace 25
L28?3:
	c0    add $r0.11 = $r0.18, 1050   ## bblock 38, line 0,  t1113,  t1113,  1050(I32)
;;								## 0
	c0    add $r0.10 = $r0.17, 4200   ## bblock 38, line 0,  t1115,  t1115,  4200(I32)
;;								## 1
	c0    add $r0.3 = $r0.15, 1   ## bblock 38, line 0,  t1116,  t1116,  1(I32)
;;								## 2
	c0    mov $r0.9 = $r0.16   ## t227
	      ## goto
;;
	c0    goto L25?3 ## goto
;;								## 3
.trace 48
L26?3:
	c0    sub $r0.2 = $r0.0, $r0.19   ## bblock 2, line 0,  t1074,  0(I32),  t226
;;								## 0
	c0    mov $r0.10 = $r0.2   ## bblock 2, line 0,  t1073,  t1074
;;								## 1
	c0    mov $r0.13 = ((qy2 + 0) + (~0xb))   ## bblock 2, line 0,  t1071,  (addr(qy2?1.0)(P32) + 0xfffffff4(I32))(P32)
;;								## 2
	c0    add $r0.12 = $r0.9, -1   ## bblock 2, line 154,  t321,  t227,  -1(SI32)
;;								## 3
	c0    mov $r0.11 = ((in + 0) + (~0x2))   ## bblock 2, line 0,  t1072,  (addr(in?1.0)(P32) + 0xfffffffd(I32))(P32)
;;								## 4
	c0    mov $r0.20 = $r0.19   ## t226
;;								## 5
	c0    mov $r0.21 = $r0.9   ## t227
;;								## 6
.trace 18
L29?3:
	c0    cmplt $b0.0 = $r0.10, $r0.0   ## bblock 3, line 152,  t1163(I1),  t1073,  0(SI32)
;;								## 0
	c0    add $r0.8 = $r0.11, $r0.12   ## [spec] bblock 32, line 0,  t566,  t1072,  t321
;;								## 1
	c0    brf $b0.0, L30?3   ## bblock 3, line 152,  t1163(I1)
;;								## 2
	c0    sh2add $r0.7 = $r0.12, $r0.13   ## bblock 32, line 0,  t565,  t321,  t1071
;;								## 3
	c0    mov $r0.2 = $r0.0   ## bblock 32, line 153,  t344,  0(SI32)
;;								## 4
	c0    mov $r0.4 = $r0.0   ## bblock 32, line 153,  t336,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 32, line 153,  t340,  0(SI32)
;;								## 6
	c0    mov $r0.3 = $r0.0   ## bblock 32, line 153,  t334,  0(SI32)
;;								## 7
	c0    mov $r0.6 = $r0.12   ## bblock 32, line 154,  t333,  t321
;;								## 8
	c0    mov $r0.16 = $r0.10   ## t1073
;;								## 9
	c0    mov $r0.17 = $r0.11   ## t1072
;;								## 10
	c0    mov $r0.18 = $r0.12   ## t321
;;								## 11
	c0    mov $r0.19 = $r0.13   ## t1071
;;								## 12
.trace 2
L31?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 35, line 158,  t476,  t344,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 35, line 155,  t368,  t334,  -47(SI32)
;;								## 1
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 35, line 158,  t475(SI24),  t476,  8(SI32)
;;								## 2
	c0    add $r0.9 = $r0.9, $r0.2   ## [spec] bblock 35, line 159,  t1182,  t368,  t475(SI24)
;;								## 3
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 35, line 157,  t364,  t336,  215(SI32)
;;								## 4
	c0    mpyl $r0.5 = $r0.5, -48   ## [spec] bblock 35, line 156,  t346,  t340,  -48(SI32)
;;								## 5
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 35, line 157,  t367(SI24),  t364,  8(SI32)
;;								## 6
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 35, line 159,  t1183,  t346,  t367(SI24)
;;								## 7
	c0    add $r0.9 = $r0.9, $r0.5   ## [spec] bblock 35, line 159,  t365,  t1182,  t1183
;;								## 8
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 33, line 154,  t1181(I1),  t333,  0(SI32)
;;								## 9
	c0    ldbu.d $r0.10 = 3[$r0.8]   ## [spec] bblock 35, line 161, t361, t566
;;								## 10
	c0    brf $b0.0, L32?3   ## bblock 33, line 154,  t1181(I1)
;;								## 11
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 35, line 154-1,  t1184(I1),  t333,  1(SI32)
;;								## 12
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 96, line 158-1,  t477,  t336,  -155(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.10, -47   ## [spec] bblock 96, line 155-1,  t68,  t361,  -47(SI32)
;;								## 14
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 96, line 158-1,  t65(SI24),  t477,  8(SI32)
;;								## 15
	c0    add $r0.11 = $r0.11, $r0.4   ## [spec] bblock 96, line 159-1,  t1217,  t68,  t65(SI24)
;;								## 16
	c0    mpyl $r0.12 = $r0.9, 215   ## [spec] bblock 96, line 157-1,  t59,  t365,  215(SI32)
;;								## 17
	c0    mpyl $r0.3 = $r0.3, -48   ## [spec] bblock 96, line 156-1,  t67,  t334,  -48(SI32)
;;								## 18
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 96, line 157-1,  t478(SI24),  t59,  8(SI32)
;;								## 19
	c0    add $r0.3 = $r0.3, $r0.12   ## [spec] bblock 96, line 159-1,  t1218,  t67,  t478(SI24)
;;								## 20
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 96, line 159-1,  t250,  t1217,  t1218
;;								## 21
	c0    ldbu.d $r0.12 = 2[$r0.8]   ## [spec] bblock 96, line 161-1, t254, t566
;;								## 22
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 96, line 154-2,  t1219(I1),  t333,  2(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.9, -155   ## [spec] bblock 93, line 158-2,  t63,  t365,  -155(SI32)
;;								## 24
	c0    mpyl $r0.14 = $r0.12, -47   ## [spec] bblock 93, line 155-2,  t332,  t254,  -47(SI32)
;;								## 25
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 93, line 158-2,  t325(SI24),  t63,  8(SI32)
;;								## 26
	c0    add $r0.14 = $r0.14, $r0.13   ## [spec] bblock 93, line 159-2,  t1214,  t332,  t325(SI24)
;;								## 27
	c0    mpyl $r0.13 = $r0.11, 215   ## [spec] bblock 93, line 157-2,  t330,  t250,  215(SI32)
;;								## 28
	c0    mpyl $r0.10 = $r0.10, -48   ## [spec] bblock 93, line 156-2,  t329,  t361,  -48(SI32)
;;								## 29
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 93, line 157-2,  t66(SI24),  t330,  8(SI32)
;;								## 30
	c0    add $r0.10 = $r0.10, $r0.13   ## [spec] bblock 93, line 159-2,  t1215,  t329,  t66(SI24)
;;								## 31
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 93, line 159-2,  t327,  t1214,  t1215
;;								## 32
	c0    ldbu.d $r0.10 = 1[$r0.8]   ## [spec] bblock 93, line 161-2, t323, t566
;;								## 33
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 93, line 154-3,  t1216(I1),  t333,  3(SI32)
;;								## 34
	c0    mpyl $r0.13 = $r0.11, -155   ## [spec] bblock 90, line 158-3,  t337,  t250,  -155(SI32)
;;								## 35
	c0    mpyl $r0.15 = $r0.10, -47   ## [spec] bblock 90, line 155-3,  t481,  t323,  -47(SI32)
;;								## 36
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 90, line 158-3,  t479(SI24),  t337,  8(SI32)
;;								## 37
	c0    add $r0.15 = $r0.15, $r0.13   ## [spec] bblock 90, line 159-3,  t1212,  t481,  t479(SI24)
;;								## 38
	c0    mpyl $r0.13 = $r0.14, 215   ## [spec] bblock 90, line 157-3,  t339,  t327,  215(SI32)
;;								## 39
	c0    mpyl $r0.12 = $r0.12, -48   ## [spec] bblock 90, line 156-3,  t480,  t254,  -48(SI32)
;;								## 40
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 90, line 157-3,  t338(SI24),  t339,  8(SI32)
;;								## 41
	c0    add $r0.12 = $r0.12, $r0.13   ## [spec] bblock 90, line 159-3,  t1213,  t480,  t338(SI24)
;;								## 42
	c0    add $r0.4 = $r0.15, $r0.12   ## [spec] bblock 90, line 159-3,  t336,  t1212,  t1213
;;								## 43
	c0    ldbu.d $r0.3 = 0[$r0.8]   ## [spec] bblock 90, line 161-3, t334, t566
;;								## 44
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 90, line 154-3,  t333,  t333,  -4(SI32)
;;								## 45
	c0    mov $r0.5 = $r0.10   ## [spec] bblock 90, line 161-2,  t340,  t323
;;								## 46
	c0    mov $r0.2 = $r0.14   ## [spec] bblock 90, line 159-2,  t344,  t327
;;								## 47
	c0    add $r0.8 = $r0.8, (~0x3)   ## [spec] bblock 90, line 0,  t566,  t566,  (~0x3)(I32)
;;								## 48
	c0    stw 12[$r0.7] = $r0.9   ## bblock 35, line 159, t565, t365
;;								## 49
	c0    brf $b0.0, L33?3   ## bblock 35, line 154-1,  t1184(I1)
;;								## 50
	c0    stw 8[$r0.7] = $r0.11   ## bblock 96, line 159-1, t565, t250
;;								## 51
	c0    brf $b0.1, L34?3   ## bblock 96, line 154-2,  t1219(I1)
;;								## 52
	c0    stw 4[$r0.7] = $r0.14   ## bblock 93, line 159-2, t565, t327
;;								## 53
	c0    brf $b0.2, L35?3   ## bblock 93, line 154-3,  t1216(I1)
;;								## 54
	c0    stw 0[$r0.7] = $r0.4   ## bblock 90, line 159-3, t565, t336
;;								## 55
	c0    add $r0.7 = $r0.7, (~0xf)   ## bblock 90, line 0,  t565,  t565,  (~0xf)(I32)
	      ## goto
;;
	c0    goto L31?3 ## goto
;;								## 56
.trace 43
L35?3:
	c0    add $r0.13 = $r0.19, 4200   ## bblock 34, line 0,  t1071,  t1071,  4200(I32)
	      ## goto
;;
	c0    goto L36?3 ## goto
;;								## 0
.trace 36
L34?3:
	c0    add $r0.13 = $r0.19, 4200   ## bblock 34, line 0,  t1071,  t1071,  4200(I32)
	      ## goto
;;
	c0    goto L36?3 ## goto
;;								## 0
.trace 30
L33?3:
	c0    add $r0.13 = $r0.19, 4200   ## bblock 34, line 0,  t1071,  t1071,  4200(I32)
	      ## goto
;;
	c0    goto L36?3 ## goto
;;								## 0
.trace 24
L32?3:
	c0    add $r0.13 = $r0.19, 4200   ## bblock 34, line 0,  t1071,  t1071,  4200(I32)
;;								## 0
L36?3:
	c0    add $r0.11 = $r0.17, 1050   ## bblock 34, line 0,  t1072,  t1072,  1050(I32)
;;								## 1
	c0    add $r0.10 = $r0.16, 1   ## bblock 34, line 0,  t1073,  t1073,  1(I32)
;;								## 2
	c0    mov $r0.12 = $r0.18   ## t321
	      ## goto
;;
	c0    goto L29?3 ## goto
;;								## 3
.trace 49
L30?3:
	c0    sub $r0.2 = $r0.0, $r0.20   ## bblock 4, line 0,  t1026,  0(I32),  t226
;;								## 0
	c0    mov $r0.3 = $r0.2   ## bblock 4, line 0,  t1025,  t1026
;;								## 1
	c0    mov $r0.10 = (qy2 + 0)   ## bblock 4, line 0,  t1022,  addr(qy2?1.0)(P32)
;;								## 2
	c0    mov $r0.8 = (qy1 + 0)   ## bblock 4, line 0,  t1023,  addr(qy1?1.0)(P32)
;;								## 3
	c0    mov $r0.7 = (qt + 0)   ## bblock 4, line 0,  t1024,  addr(qt?1.0)(P32)
;;								## 4
	c0    mov $r0.9 = $r0.21   ## t227
;;								## 5
.trace 19
L37?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 5, line 166,  t1164(I1),  t1025,  0(SI32)
;;								## 0
	c0    sub $r0.11 = 3, $r0.9   ## [spec] bblock 28, line 0,  t613,  3(I32),  t227
;;								## 1
	c0    brf $b0.0, L38?3   ## bblock 5, line 166,  t1164(I1)
;;								## 2
	c0    mov $r0.5 = $r0.11   ## bblock 28, line 0,  t612,  t613
;;								## 3
	c0    mov $r0.6 = $r0.7   ## bblock 28, line 0,  t611,  t1024
;;								## 4
	c0    mov $r0.4 = $r0.8   ## bblock 28, line 0,  t610,  t1023
;;								## 5
	c0    mov $r0.2 = $r0.10   ## bblock 28, line 0,  t609,  t1022
;;								## 6
	c0    mov $r0.11 = $r0.3   ## t1025
;;								## 7
	c0    mov $r0.12 = $r0.9   ## t227
;;								## 8
	c0    mov $r0.13 = $r0.7   ## t1024
;;								## 9
	c0    mov $r0.14 = $r0.8   ## t1023
;;								## 10
	c0    mov $r0.15 = $r0.10   ## t1022
;;								## 11
.trace 1
L39?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 31, line 168, t370, t609
;;								## 0
	c0    ldw.d $r0.7 = 0[$r0.4]   ## [spec] bblock 31, line 168, t381, t610
;;								## 1
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 29, line 167,  t1179(I1),  t612,  3(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 31, line 167-1,  t1180(I1),  t612,  2(SI32)
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.7   ## [spec] bblock 31, line 168,  t472,  t370,  t381
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## [spec] bblock 31, line 168,  t471,  t472,  8(I32)
;;								## 5
	c0    shr $r0.3 = $r0.3, 8   ## [spec] bblock 31, line 168,  t380(SI24),  t471,  8(SI32)
;;								## 6
	c0    brf $b0.0, L40?3   ## bblock 29, line 167,  t1179(I1)
;;								## 7
	c0    ldw.d $r0.7 = 4[$r0.2]   ## [spec] bblock 86, line 168-1, t94, t609
;;								## 8
	c0    ldw.d $r0.8 = 4[$r0.4]   ## [spec] bblock 86, line 168-1, t98, t610
;;								## 9
	c0    cmplt $b0.0 = $r0.5, 1   ## [spec] bblock 86, line 167-2,  t1211(I1),  t612,  1(SI32)
;;								## 10
	c0    ldw.d $r0.9 = 8[$r0.2]   ## [spec] bblock 83, line 168-2, t349, t609
;;								## 11
	c0    add $r0.7 = $r0.7, $r0.8   ## [spec] bblock 86, line 168-1,  t99,  t94,  t98
;;								## 12
	c0    shl $r0.7 = $r0.7, 8   ## [spec] bblock 86, line 168-1,  t101,  t99,  8(I32)
;;								## 13
	c0    shr $r0.7 = $r0.7, 8   ## [spec] bblock 86, line 168-1,  t372(SI24),  t101,  8(SI32)
;;								## 14
	c0    ldw.d $r0.8 = 8[$r0.4]   ## [spec] bblock 83, line 168-2, t352, t610
;;								## 15
	c0    cmplt $b0.2 = $r0.5, $r0.0   ## [spec] bblock 83, line 167-3,  t1210(I1),  t612,  0(SI32)
;;								## 16
	c0    ldw.d $r0.10 = 12[$r0.2]   ## [spec] bblock 80, line 168-3, t359, t609
;;								## 17
	c0    add $r0.9 = $r0.9, $r0.8   ## [spec] bblock 83, line 168-2,  t351,  t349,  t352
;;								## 18
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 83, line 168-2,  t350,  t351,  8(I32)
;;								## 19
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 83, line 168-2,  t102(SI24),  t350,  8(SI32)
;;								## 20
	c0    ldw.d $r0.8 = 12[$r0.4]   ## [spec] bblock 80, line 168-3, t358, t610
;;								## 21
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 80, line 0,  t609,  t609,  16(I32)
;;								## 22
	c0    add $r0.4 = $r0.4, 16   ## [spec] bblock 80, line 0,  t610,  t610,  16(I32)
;;								## 23
	c0    add $r0.10 = $r0.10, $r0.8   ## [spec] bblock 80, line 168-3,  t357,  t359,  t358
;;								## 24
	c0    shl $r0.10 = $r0.10, 8   ## [spec] bblock 80, line 168-3,  t356,  t357,  8(I32)
;;								## 25
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 80, line 168-3,  t355(SI24),  t356,  8(SI32)
;;								## 26
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 80, line 0,  t612,  t612,  4(I32)
;;								## 27
	c0    stw 0[$r0.6] = $r0.3   ## bblock 31, line 168, t611, t380(SI24)
;;								## 28
	c0    brf $b0.1, L40?3   ## bblock 31, line 167-1,  t1180(I1)
;;								## 29
	c0    stw 4[$r0.6] = $r0.7   ## bblock 86, line 168-1, t611, t372(SI24)
;;								## 30
	c0    brf $b0.0, L40?3   ## bblock 86, line 167-2,  t1211(I1)
;;								## 31
	c0    stw 8[$r0.6] = $r0.9   ## bblock 83, line 168-2, t611, t102(SI24)
;;								## 32
	c0    brf $b0.2, L40?3   ## bblock 83, line 167-3,  t1210(I1)
;;								## 33
	c0    stw 12[$r0.6] = $r0.10   ## bblock 80, line 168-3, t611, t355(SI24)
;;								## 34
	c0    add $r0.6 = $r0.6, 16   ## bblock 80, line 0,  t611,  t611,  16(I32)
	      ## goto
;;
	c0    goto L39?3 ## goto
;;								## 35
.trace 23
L40?3:
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 30, line 0,  t1022,  t1022,  4200(I32)
;;								## 1
	c0    add $r0.8 = $r0.14, $r0.2   ## bblock 30, line 0,  t1023,  t1023,  4200(I32)
;;								## 2
	c0    add $r0.7 = $r0.13, $r0.2   ## bblock 30, line 0,  t1024,  t1024,  4200(I32)
;;								## 3
	c0    add $r0.3 = $r0.11, 1   ## bblock 30, line 0,  t1025,  t1025,  1(I32)
;;								## 4
	c0    mov $r0.9 = $r0.12   ## t227
	      ## goto
;;
	c0    goto L37?3 ## goto
;;								## 5
.trace 50
L38?3:
	c0    sub $r0.2 = $r0.0, $r0.9   ## bblock 6, line 0,  t991,  0(I32),  t227
;;								## 0
	c0    mov $r0.3 = $r0.2   ## bblock 6, line 0,  t990,  t991
;;								## 1
	c0    mov $r0.12 = (qt + 0)   ## bblock 6, line 0,  t988,  addr(qt?1.0)(P32)
;;								## 2
	c0    mov $r0.11 = (qy1 + 0)   ## bblock 6, line 0,  t989,  addr(qy1?1.0)(P32)
;;								## 3
	c0    mov $r0.10 = $r0.20   ## t226
;;								## 4
	c0    mov $r0.17 = $r0.9   ## t227
;;								## 5
.trace 22
L41?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 7, line 170,  t1165(I1),  t990,  0(SI32)
;;								## 0
	c0    sub $r0.13 = 3, $r0.10   ## [spec] bblock 24, line 0,  t676,  3(I32),  t226
;;								## 1
	c0    brf $b0.0, L42?3   ## bblock 7, line 170,  t1165(I1)
;;								## 2
	c0    mov $r0.7 = $r0.13   ## bblock 24, line 0,  t675,  t676
;;								## 3
	c0    mov $r0.8 = $r0.11   ## bblock 24, line 0,  t674,  t989
;;								## 4
	c0    mov $r0.2 = $r0.12   ## bblock 24, line 0,  t673,  t988
;;								## 5
	c0    mov $r0.6 = $r0.0   ## bblock 24, line 171,  t384,  0(SI32)
;;								## 6
	c0    mov $r0.5 = $r0.0   ## bblock 24, line 171,  t382(SI24),  0(SI32)
;;								## 7
	c0    mov $r0.4 = $r0.0   ## bblock 24, line 171,  t383,  0(SI32)
;;								## 8
	c0    mov $r0.13 = $r0.3   ## t990
;;								## 9
	c0    mov $r0.14 = $r0.10   ## t226
;;								## 10
	c0    mov $r0.15 = $r0.11   ## t989
;;								## 11
	c0    mov $r0.16 = $r0.12   ## t988
;;								## 12
.trace 6
L43?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 27, line 173, t466, t673
;;								## 0
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 27, line 173,  t406,  t383,  -155(SI32)
;;								## 1
	c0    mpyl $r0.9 = $r0.5, 215   ## [spec] bblock 27, line 173,  t387,  t382(SI24),  215(SI32)
;;								## 2
	c0    mpyl $r0.10 = $r0.3, -48   ## [spec] bblock 27, line 173,  t404,  t466,  -48(SI32)
;;								## 3
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 27, line 173,  t401,  t384,  28(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.10   ## [spec] bblock 27, line 173,  t1176,  t406,  t404
;;								## 5
	c0    add $r0.9 = $r0.9, $r0.6   ## [spec] bblock 27, line 173,  t1177,  t387,  t401
;;								## 6
	c0    add $r0.4 = $r0.4, $r0.9   ## [spec] bblock 27, line 173,  t403,  t1176,  t1177
;;								## 7
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 27, line 173,  t1155,  t403,  8(SI32)
;;								## 8
	c0    cmplt $b0.0 = $r0.7, 3   ## bblock 25, line 172,  t1175(I1),  t675,  3(SI32)
;;								## 9
	c0    cmplt $b0.1 = $r0.7, 2   ## [spec] bblock 27, line 172-1,  t1178(I1),  t675,  2(SI32)
;;								## 10
	c0    brf $b0.0, L44?3   ## bblock 25, line 172,  t1175(I1)
;;								## 11
	c0    ldw.d $r0.9 = 4200[$r0.2]   ## [spec] bblock 76, line 173-1, t473, t673
;;								## 12
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 76, line 173-1,  t116,  t382(SI24),  -155(SI32)
;;								## 13
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 76, line 173-1,  t119,  t1155,  215(SI32)
;;								## 14
	c0    mpyl $r0.11 = $r0.9, -48   ## [spec] bblock 76, line 173-1,  t128,  t473,  -48(SI32)
;;								## 15
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 76, line 173-1,  t122,  t466,  28(SI32)
;;								## 16
	c0    add $r0.5 = $r0.5, $r0.11   ## [spec] bblock 76, line 173-1,  t1207,  t116,  t128
;;								## 17
	c0    add $r0.10 = $r0.10, $r0.3   ## [spec] bblock 76, line 173-1,  t1208,  t119,  t122
;;								## 18
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 76, line 173-1,  t129,  t1207,  t1208
;;								## 19
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 76, line 173-1,  t1156,  t129,  8(SI32)
;;								## 20
	c0    cmplt $b0.0 = $r0.7, 1   ## [spec] bblock 76, line 172-2,  t1209(I1),  t675,  1(SI32)
;;								## 21
	c0    ldw.d $r0.3 = 8400[$r0.2]   ## [spec] bblock 73, line 173-2, t257, t673
;;								## 22
	c0    mpyl $r0.10 = $r0.4, -155   ## [spec] bblock 73, line 173-2,  t378,  t1155,  -155(SI32)
;;								## 23
	c0    mpyl $r0.11 = $r0.5, 215   ## [spec] bblock 73, line 173-2,  t376,  t1156,  215(SI32)
;;								## 24
	c0    mpyl $r0.12 = $r0.3, -48   ## [spec] bblock 73, line 173-2,  t375,  t257,  -48(SI32)
;;								## 25
	c0    mpyl $r0.9 = $r0.9, 28   ## [spec] bblock 73, line 173-2,  t470,  t473,  28(SI32)
;;								## 26
	c0    add $r0.10 = $r0.10, $r0.12   ## [spec] bblock 73, line 173-2,  t1204,  t378,  t375
;;								## 27
	c0    add $r0.11 = $r0.11, $r0.9   ## [spec] bblock 73, line 173-2,  t1205,  t376,  t470
;;								## 28
	c0    add $r0.10 = $r0.10, $r0.11   ## [spec] bblock 73, line 173-2,  t374,  t1204,  t1205
;;								## 29
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 73, line 173-2,  t1157,  t374,  8(SI32)
;;								## 30
	c0    cmplt $b0.2 = $r0.7, $r0.0   ## [spec] bblock 73, line 172-3,  t1206(I1),  t675,  0(SI32)
;;								## 31
	c0    ldw.d $r0.6 = 12600[$r0.2]   ## [spec] bblock 70, line 173-3, t384, t673
;;								## 32
	c0    mpyl $r0.9 = $r0.5, -155   ## [spec] bblock 70, line 173-3,  t393,  t1156,  -155(SI32)
;;								## 33
	c0    mpyl $r0.11 = $r0.10, 215   ## [spec] bblock 70, line 173-3,  t392,  t1157,  215(SI32)
;;								## 34
	c0    mpyl $r0.12 = $r0.6, -48   ## [spec] bblock 70, line 173-3,  t386,  t384,  -48(SI32)
;;								## 35
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 70, line 173-3,  t391,  t257,  28(SI32)
;;								## 36
	c0    add $r0.9 = $r0.9, $r0.12   ## [spec] bblock 70, line 173-3,  t1202,  t393,  t386
;;								## 37
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 70, line 173-3,  t1203,  t392,  t391
;;								## 38
	c0    add $r0.9 = $r0.9, $r0.11   ## [spec] bblock 70, line 173-3,  t385,  t1202,  t1203
;;								## 39
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 70, line 173-3,  t382(SI24),  t385,  8(SI32)
;;								## 40
	c0    stw 0[$r0.8] = $r0.4   ## bblock 27, line 173, t674, t1155
;;								## 41
	c0    brf $b0.1, L44?3   ## bblock 27, line 172-1,  t1178(I1)
;;								## 42
	c0    mov $r0.4 = $r0.10   ## [spec] bblock 70, line 173-2,  t383,  t1157
;;								## 43
	c0    add $r0.2 = $r0.2, 16800   ## [spec] bblock 70, line 0,  t673,  t673,  16800(I32)
;;								## 44
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 70, line 0,  t675,  t675,  4(I32)
;;								## 45
	c0    stw 4200[$r0.8] = $r0.5   ## bblock 76, line 173-1, t674, t1156
;;								## 46
	c0    brf $b0.0, L44?3   ## bblock 76, line 172-2,  t1209(I1)
;;								## 47
	c0    mov $r0.5 = $r0.9   ## [spec] t382(SI24)
;;								## 48
	c0    stw 8400[$r0.8] = $r0.10   ## bblock 73, line 173-2, t674, t1157
;;								## 49
	c0    brf $b0.2, L44?3   ## bblock 73, line 172-3,  t1206(I1)
;;								## 50
	c0    stw 12600[$r0.8] = $r0.9   ## bblock 70, line 173-3, t674, t382(SI24)
;;								## 51
	c0    add $r0.8 = $r0.8, 16800   ## bblock 70, line 0,  t674,  t674,  16800(I32)
	      ## goto
;;
	c0    goto L43?3 ## goto
;;								## 52
.trace 27
L44?3:
	c0    add $r0.12 = $r0.16, 4   ## bblock 26, line 0,  t988,  t988,  4(I32)
;;								## 0
	c0    add $r0.11 = $r0.15, 4   ## bblock 26, line 0,  t989,  t989,  4(I32)
;;								## 1
	c0    add $r0.3 = $r0.13, 1   ## bblock 26, line 0,  t990,  t990,  1(I32)
;;								## 2
	c0    mov $r0.10 = $r0.14   ## t226
	      ## goto
;;
	c0    goto L41?3 ## goto
;;								## 3
.trace 51
L42?3:
	c0    sub $r0.2 = $r0.0, $r0.17   ## bblock 8, line 0,  t958,  0(I32),  t227
;;								## 0
	c0    mov $r0.13 = ((qy2 + 0) + (~0x3137))   ## bblock 8, line 0,  t955,  (addr(qy2?1.0)(P32) + 0xffffcec8(I32))(P32)
;;								## 1
	c0    mov $r0.20 = $r0.10   ## t226
;;								## 2
	c0    mov $r0.10 = $r0.2   ## bblock 8, line 0,  t957,  t958
;;								## 3
	c0    mov $r0.12 = ((qt + 0) + (~0x3137))   ## bblock 8, line 0,  t956,  (addr(qt?1.0)(P32) + 0xffffcec8(I32))(P32)
;;								## 4
	c0    add $r0.11 = $r0.20, -1   ## bblock 8, line 181,  t322,  t226,  -1(SI32)
;;								## 5
	c0    mov $r0.19 = $r0.17   ## t227
;;								## 6
.trace 21
L45?3:
	c0    cmplt $b0.0 = $r0.10, $r0.0   ## bblock 9, line 179,  t1166(I1),  t957,  0(SI32)
;;								## 0
	c0    mpylu $r0.14 = $r0.11, 4200   ## [spec] bblock 20, line 0,  t766,  t322,  4200(I32)
;;								## 1
	c0    brf $b0.0, L46?3   ## bblock 9, line 179,  t1166(I1)
;;								## 2
	c0    add $r0.8 = $r0.12, $r0.14   ## bblock 20, line 0,  t756,  t956,  t766
;;								## 3
	c0    add $r0.7 = $r0.13, $r0.14   ## bblock 20, line 0,  t755,  t955,  t766
;;								## 4
	c0    mov $r0.3 = $r0.0   ## bblock 20, line 180,  t412,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 20, line 180,  t411,  0(SI32)
;;								## 6
	c0    mov $r0.4 = $r0.0   ## bblock 20, line 180,  t410(SI24),  0(SI32)
;;								## 7
	c0    mov $r0.2 = $r0.0   ## bblock 20, line 180,  t409,  0(SI32)
;;								## 8
	c0    mov $r0.6 = $r0.11   ## bblock 20, line 181,  t415,  t322
;;								## 9
	c0    mov $r0.15 = $r0.10   ## t957
;;								## 10
	c0    mov $r0.16 = $r0.11   ## t322
;;								## 11
	c0    mov $r0.17 = $r0.12   ## t956
;;								## 12
	c0    mov $r0.18 = $r0.13   ## t955
;;								## 13
.trace 5
L47?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 23, line 182,  t430,  t409,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 23, line 182,  t461,  t412,  -47(SI32)
;;								## 1
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 23, line 182,  t413,  t410(SI24),  215(SI32)
;;								## 2
	c0    add $r0.2 = $r0.2, $r0.9   ## [spec] bblock 23, line 182,  t1172,  t430,  t461
;;								## 3
	c0    mpyl $r0.5 = $r0.5, 29   ## [spec] bblock 23, line 182,  t425,  t411,  29(SI32)
;;								## 4
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 21, line 181,  t1171(I1),  t415,  0(SI32)
;;								## 5
	c0    add $r0.10 = $r0.10, $r0.5   ## [spec] bblock 23, line 182,  t1173,  t413,  t425
;;								## 6
	c0    add $r0.2 = $r0.2, $r0.10   ## [spec] bblock 23, line 182,  t460,  t1172,  t1173
;;								## 7
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 23, line 182,  t1158,  t460,  8(SI32)
;;								## 8
	c0    brf $b0.0, L48?3   ## bblock 21, line 181,  t1171(I1)
;;								## 9
	c0    ldw $r0.9 = 12600[$r0.8]   ## bblock 23, line 184, t424, t756
;;								## 10
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 23, line 181-1,  t1174(I1),  t415,  1(SI32)
;;								## 11
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 66, line 182-1,  t463,  t410(SI24),  -155(SI32)
;;								## 12
	c0    mpyl $r0.10 = $r0.9, -47   ## [spec] bblock 66, line 182-1,  t395,  t424,  -47(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.2, 215   ## [spec] bblock 66, line 182-1,  t157,  t1158,  215(SI32)
;;								## 14
	c0    add $r0.4 = $r0.4, $r0.10   ## [spec] bblock 66, line 182-1,  t1199,  t463,  t395
;;								## 15
	c0    mpyl $r0.3 = $r0.3, 29   ## [spec] bblock 66, line 182-1,  t160,  t412,  29(SI32)
;;								## 16
	c0    ldw.d $r0.10 = 8400[$r0.8]   ## [spec] bblock 66, line 184-1, t252, t756
;;								## 17
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 66, line 182-1,  t1200,  t157,  t160
;;								## 18
	c0    add $r0.4 = $r0.4, $r0.11   ## [spec] bblock 66, line 182-1,  t394,  t1199,  t1200
;;								## 19
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 66, line 182-1,  t1159,  t394,  8(SI32)
;;								## 20
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 66, line 181-2,  t1201(I1),  t415,  2(SI32)
;;								## 21
	c0    mpyl $r0.11 = $r0.2, -155   ## [spec] bblock 63, line 182-2,  t154,  t1158,  -155(SI32)
;;								## 22
	c0    mpyl $r0.12 = $r0.10, -47   ## [spec] bblock 63, line 182-2,  t163,  t252,  -47(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.4, 215   ## [spec] bblock 63, line 182-2,  t408,  t1159,  215(SI32)
;;								## 24
	c0    add $r0.11 = $r0.11, $r0.12   ## [spec] bblock 63, line 182-2,  t1196,  t154,  t163
;;								## 25
	c0    mpyl $r0.9 = $r0.9, 29   ## [spec] bblock 63, line 182-2,  t407,  t424,  29(SI32)
;;								## 26
	c0    ldw.d $r0.12 = 4200[$r0.8]   ## [spec] bblock 63, line 184-2, t398, t756
;;								## 27
	c0    add $r0.13 = $r0.13, $r0.9   ## [spec] bblock 63, line 182-2,  t1197,  t408,  t407
;;								## 28
	c0    add $r0.11 = $r0.11, $r0.13   ## [spec] bblock 63, line 182-2,  t164,  t1196,  t1197
;;								## 29
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 63, line 182-2,  t1160,  t164,  8(SI32)
;;								## 30
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 63, line 181-3,  t1198(I1),  t415,  3(SI32)
;;								## 31
	c0    mpyl $r0.9 = $r0.4, -155   ## [spec] bblock 60, line 182-3,  t421,  t1159,  -155(SI32)
;;								## 32
	c0    mpyl $r0.13 = $r0.12, -47   ## [spec] bblock 60, line 182-3,  t418,  t398,  -47(SI32)
;;								## 33
	c0    mpyl $r0.14 = $r0.11, 215   ## [spec] bblock 60, line 182-3,  t420,  t1160,  215(SI32)
;;								## 34
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 60, line 182-3,  t1194,  t421,  t418
;;								## 35
	c0    mpyl $r0.10 = $r0.10, 29   ## [spec] bblock 60, line 182-3,  t419,  t252,  29(SI32)
;;								## 36
	c0    ldw.d $r0.3 = 0[$r0.8]   ## [spec] bblock 60, line 184-3, t412, t756
;;								## 37
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 60, line 182-3,  t1195,  t420,  t419
;;								## 38
	c0    add $r0.9 = $r0.9, $r0.14   ## [spec] bblock 60, line 182-3,  t417,  t1194,  t1195
;;								## 39
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 60, line 182-3,  t410(SI24),  t417,  8(SI32)
;;								## 40
	c0    stw 12600[$r0.7] = $r0.2   ## bblock 23, line 182, t755, t1158
;;								## 41
	c0    brf $b0.0, L48?3   ## bblock 23, line 181-1,  t1174(I1)
;;								## 42
	c0    mov $r0.2 = $r0.11   ## [spec] bblock 60, line 182-2,  t409,  t1160
;;								## 43
	c0    mov $r0.5 = $r0.12   ## [spec] bblock 60, line 184-2,  t411,  t398
;;								## 44
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 60, line 181-3,  t415,  t415,  -4(SI32)
;;								## 45
	c0    add $r0.8 = $r0.8, (~0x419f)   ## [spec] bblock 60, line 0,  t756,  t756,  (~0x419f)(I32)
;;								## 46
	c0    stw 8400[$r0.7] = $r0.4   ## bblock 66, line 182-1, t755, t1159
;;								## 47
	c0    brf $b0.1, L48?3   ## bblock 66, line 181-2,  t1201(I1)
;;								## 48
	c0    mov $r0.4 = $r0.9   ## [spec] t410(SI24)
;;								## 49
	c0    stw 4200[$r0.7] = $r0.11   ## bblock 63, line 182-2, t755, t1160
;;								## 50
	c0    brf $b0.2, L48?3   ## bblock 63, line 181-3,  t1198(I1)
;;								## 51
	c0    stw 0[$r0.7] = $r0.9   ## bblock 60, line 182-3, t755, t410(SI24)
;;								## 52
	c0    add $r0.7 = $r0.7, (~0x419f)   ## bblock 60, line 0,  t755,  t755,  (~0x419f)(I32)
	      ## goto
;;
	c0    goto L47?3 ## goto
;;								## 53
.trace 26
L48?3:
	c0    add $r0.13 = $r0.18, 4   ## bblock 22, line 0,  t955,  t955,  4(I32)
;;								## 0
	c0    add $r0.12 = $r0.17, 4   ## bblock 22, line 0,  t956,  t956,  4(I32)
;;								## 1
	c0    add $r0.10 = $r0.15, 1   ## bblock 22, line 0,  t957,  t957,  1(I32)
;;								## 2
	c0    mov $r0.11 = $r0.16   ## t322
	      ## goto
;;
	c0    goto L45?3 ## goto
;;								## 3
.trace 52
L46?3:
	c0    sub $r0.20 = $r0.0, $r0.20   ## bblock 10, line 0,  t911,  0(I32),  t226
;;								## 0
	c0    mov $r0.3 = $r0.20   ## bblock 10, line 0,  t910,  t911
;;								## 1
	c0    mov $r0.11 = (qy2 + 0)   ## bblock 10, line 0,  t908,  addr(qy2?1.0)(P32)
;;								## 2
	c0    mov $r0.10 = (qy1 + 0)   ## bblock 10, line 0,  t909,  addr(qy1?1.0)(P32)
;;								## 3
	c0    mov $r0.8 = (out + 0)   ## bblock 10, line 0,  t906,  addr(out?1.0)(P32)
;;								## 4
	c0    mov $r0.9 = $r0.19   ## t227
;;								## 5
.trace 20
L49?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 11, line 189,  t1167(I1),  t910,  0(SI32)
;;								## 0
	c0    sub $r0.12 = 3, $r0.9   ## [spec] bblock 13, line 0,  t837,  3(I32),  t227
;;								## 1
	c0    brf $b0.0, L50?3   ## bblock 11, line 189,  t1167(I1)
;;								## 2
	c0    mov $r0.5 = $r0.12   ## bblock 13, line 0,  t836,  t837
;;								## 3
	c0    mov $r0.7 = $r0.8   ## bblock 13, line 0,  t835,  t906
;;								## 4
	c0    mov $r0.6 = $r0.8   ## bblock 13, line 0,  t834,  t906
;;								## 5
	c0    mov $r0.4 = $r0.10   ## bblock 13, line 0,  t833,  t909
;;								## 6
	c0    mov $r0.2 = $r0.11   ## bblock 13, line 0,  t832,  t908
;;								## 7
	c0    mov $r0.13 = $r0.3   ## t910
;;								## 8
	c0    mov $r0.14 = $r0.9   ## t227
;;								## 9
	c0    mov $r0.15 = $r0.8   ## t906
;;								## 10
	c0    mov $r0.16 = $r0.10   ## t909
;;								## 11
	c0    mov $r0.17 = $r0.11   ## t908
;;								## 12
.trace 4
L51?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 16, line 191, t455, t832
;;								## 0
	c0    ldw.d $r0.8 = 0[$r0.4]   ## [spec] bblock 16, line 191, t454, t833
;;								## 1
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 14, line 190,  t1168(I1),  t836,  3(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 18, line 190-1,  t1170(I1),  t836,  2(SI32)
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.8   ## [spec] bblock 16, line 191,  t445,  t455,  t454
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## [spec] bblock 16, line 191,  t444,  t445,  8(I32)
;;								## 5
	c0    shr $r0.3 = $r0.3, 16   ## [spec] bblock 16, line 191,  t443(SI16),  t444,  16(SI32)
;;								## 6
	c0    brf $b0.0, L52?3   ## bblock 14, line 190,  t1168(I1)
;;								## 7
	c0    zxtb $r0.8 = $r0.3   ## bblock 16, line 191,  t442(I8),  t443(SI16)
;;								## 8
	c0    cmpgt $b0.0 = $r0.8, 25   ## bblock 16, line 192,  t1169(I1),  t442(I8),  25(SI32)
;;								## 9
	c0    ldw.d $r0.9 = 4[$r0.2]   ## [spec] bblock 53, line 191-1, t190, t832
;;								## 10
	c0    ldw.d $r0.8 = 4[$r0.4]   ## [spec] bblock 53, line 191-1, t194, t833
;;								## 11
	c0    cmplt $b0.2 = $r0.5, 1   ## [spec] bblock 55, line 190-2,  t1193(I1),  t836,  1(SI32)
;;								## 12
	c0    ldw.d $r0.10 = 8[$r0.2]   ## [spec] bblock 47, line 191-2, t437, t832
;;								## 13
	c0    add $r0.9 = $r0.9, $r0.8   ## [spec] bblock 53, line 191-1,  t459,  t190,  t194
;;								## 14
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 53, line 191-1,  t458,  t459,  8(I32)
;;								## 15
	c0    shr $r0.9 = $r0.9, 16   ## [spec] bblock 53, line 191-1,  t198(SI16),  t458,  16(SI32)
;;								## 16
	c0    zxtb $r0.8 = $r0.9   ## [spec] bblock 53, line 191-1,  t423(I8),  t198(SI16)
;;								## 17
	c0    cmpgt $b0.3 = $r0.8, 25   ## [spec] bblock 53, line 192-1,  t1192(I1),  t423(I8),  25(SI32)
;;								## 18
	c0    ldw.d $r0.11 = 8[$r0.4]   ## [spec] bblock 47, line 191-2, t433, t833
;;								## 19
	c0    cmplt $b0.4 = $r0.5, $r0.0   ## [spec] bblock 49, line 190-3,  t1191(I1),  t836,  0(SI32)
;;								## 20
	c0    ldw.d $r0.8 = 12[$r0.2]   ## [spec] bblock 41, line 191-3, t450, t832
;;								## 21
	c0    add $r0.10 = $r0.10, $r0.11   ## [spec] bblock 47, line 191-2,  t195,  t437,  t433
;;								## 22
	c0    shl $r0.10 = $r0.10, 8   ## [spec] bblock 47, line 191-2,  t197,  t195,  8(I32)
;;								## 23
	c0    shr $r0.10 = $r0.10, 16   ## [spec] bblock 47, line 191-2,  t431(SI16),  t197,  16(SI32)
;;								## 24
	c0    zxtb $r0.11 = $r0.10   ## [spec] bblock 47, line 191-2,  t206(I8),  t431(SI16)
;;								## 25
	c0    cmpgt $b0.5 = $r0.11, 25   ## [spec] bblock 47, line 192-2,  t1190(I1),  t206(I8),  25(SI32)
;;								## 26
	c0    ldw.d $r0.12 = 12[$r0.4]   ## [spec] bblock 41, line 191-3, t449, t833
;;								## 27
	c0    stb 0[$r0.6] = $r0.3   ## bblock 16, line 191, t834, t443(SI16)
;;								## 28
	c0    brf $b0.0, L53?3   ## bblock 16, line 192,  t1169(I1)
;;								## 29
	c0    add $r0.8 = $r0.8, $r0.12   ## [spec] bblock 41, line 191-3,  t448,  t450,  t449
;;								## 30
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 41, line 191-3,  t447,  t448,  8(I32)
;;								## 31
	c0    shr $r0.8 = $r0.8, 16   ## [spec] bblock 41, line 191-3,  t441(SI16),  t447,  16(SI32)
;;								## 32
	c0    zxtb $r0.3 = $r0.8   ## [spec] bblock 41, line 191-3,  t440(I8),  t441(SI16)
;;								## 33
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 41, line 192-3,  t1189(I1),  t440(I8),  25(SI32)
;;								## 34
	c0    stb 0[$r0.6] = $r0.0   ## bblock 19, line 193, t834, 0(I32)
;;								## 35
L54?3:
	c0    brf $b0.1, L52?3   ## bblock 18, line 190-1,  t1170(I1)
;;								## 36
	c0    stb 1[$r0.6] = $r0.9   ## bblock 53, line 191-1, t834, t198(SI16)
;;								## 37
	c0    brf $b0.3, L55?3   ## bblock 53, line 192-1,  t1192(I1)
;;								## 38
	c0    stb 1[$r0.6] = $r0.0   ## bblock 56, line 193-1, t834, 0(I32)
;;								## 39
L56?3:
	c0    brf $b0.2, L52?3   ## bblock 55, line 190-2,  t1193(I1)
;;								## 40
	c0    stb 2[$r0.6] = $r0.10   ## bblock 47, line 191-2, t834, t431(SI16)
;;								## 41
	c0    brf $b0.5, L57?3   ## bblock 47, line 192-2,  t1190(I1)
;;								## 42
	c0    stb 2[$r0.6] = $r0.0   ## bblock 50, line 193-2, t834, 0(I32)
;;								## 43
L58?3:
	c0    brf $b0.4, L52?3   ## bblock 49, line 190-3,  t1191(I1)
;;								## 44
	c0    stb 3[$r0.6] = $r0.8   ## bblock 41, line 191-3, t834, t441(SI16)
;;								## 45
	c0    brf $b0.0, L59?3   ## bblock 41, line 192-3,  t1189(I1)
;;								## 46
	c0    add $r0.2 = $r0.2, 16   ## bblock 43, line 0,  t832,  t832,  16(I32)
;;								## 47
	c0    add $r0.4 = $r0.4, 16   ## bblock 43, line 0,  t833,  t833,  16(I32)
;;								## 48
	c0    add $r0.7 = $r0.7, 4   ## bblock 43, line 0,  t835,  t835,  4(I32)
;;								## 49
	c0    add $r0.5 = $r0.5, 4   ## bblock 43, line 0,  t836,  t836,  4(I32)
;;								## 50
	c0    stb 3[$r0.6] = $r0.0   ## bblock 44, line 193-3, t834, 0(I32)
;;								## 51
L60?3:
	c0    add $r0.6 = $r0.6, 4   ## bblock 43, line 0,  t834,  t834,  4(I32)
	      ## goto
;;
	c0    goto L51?3 ## goto
;;								## 52
.trace 16
L59?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.5 = $r0.5, 4   ## bblock 43, line 0,  t836,  t836,  4(I32)
;;								## 1
	c0    add $r0.4 = $r0.4, 16   ## bblock 43, line 0,  t833,  t833,  16(I32)
;;								## 2
	c0    add $r0.2 = $r0.2, 16   ## bblock 43, line 0,  t832,  t832,  16(I32)
;;								## 3
	c0    stb 3[$r0.7] = $r0.3   ## bblock 42, line 195-3, t835, 255(I32)
;;								## 4
	c0    add $r0.7 = $r0.7, 4   ## bblock 43, line 0,  t835,  t835,  4(I32)
	      ## goto
;;
	c0    goto L60?3 ## goto
;;								## 5
.trace 28
L52?3:
	c0    add $r0.11 = $r0.17, 4200   ## bblock 15, line 0,  t908,  t908,  4200(I32)
;;								## 0
	c0    add $r0.10 = $r0.16, 4200   ## bblock 15, line 0,  t909,  t909,  4200(I32)
;;								## 1
	c0    add $r0.8 = $r0.15, 1050   ## bblock 15, line 0,  t906,  t906,  1050(I32)
;;								## 2
	c0    add $r0.3 = $r0.13, 1   ## bblock 15, line 0,  t910,  t910,  1(I32)
;;								## 3
	c0    mov $r0.9 = $r0.14   ## t227
	      ## goto
;;
	c0    goto L49?3 ## goto
;;								## 4
.trace 15
L57?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 2[$r0.7] = $r0.3   ## bblock 48, line 195-2, t835, 255(I32)
	      ## goto
;;
	c0    goto L58?3 ## goto
;;								## 1
.trace 14
L55?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 1[$r0.7] = $r0.3   ## bblock 54, line 195-1, t835, 255(I32)
	      ## goto
;;
	c0    goto L56?3 ## goto
;;								## 1
.trace 13
L53?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.8 = $r0.8, $r0.12   ## [spec] bblock 41, line 191-3,  t448,  t450,  t449
;;								## 1
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 41, line 191-3,  t447,  t448,  8(I32)
;;								## 2
	c0    shr $r0.8 = $r0.8, 16   ## [spec] bblock 41, line 191-3,  t441(SI16),  t447,  16(SI32)
;;								## 3
	c0    zxtb $r0.11 = $r0.8   ## [spec] bblock 41, line 191-3,  t440(I8),  t441(SI16)
;;								## 4
	c0    cmpgt $b0.0 = $r0.11, 25   ## [spec] bblock 41, line 192-3,  t1189(I1),  t440(I8),  25(SI32)
;;								## 5
	c0    stb 0[$r0.7] = $r0.3   ## bblock 17, line 195, t835, 255(I32)
	      ## goto
;;
	c0    goto L54?3 ## goto
;;								## 6
.trace 53
L50?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 12, line 199,  t214,  ?2.2?2auto_size(I32),  t213
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.2?2auto_size, 0x0
 ## End deriche_slow
 ## Begin deriche_fused
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_fused::
.trace 27
	      ## auto_size == 0
;;								## 0
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t726,  0(I32),  t202
;;								## 1
	c0    mov $r0.9 = $r0.2   ## bblock 0, line 0,  t725,  t726
;;								## 2
	c0    mov $r0.27 = (in + 0)   ## bblock 0, line 0,  t715,  addr(in?1.0)(P32)
;;								## 3
	c0    mov $r0.26 = (qy1 + 0)   ## bblock 0, line 0,  t717,  addr(qy1?1.0)(P32)
;;								## 4
	c0    mov $r0.25 = (qy2 + 0)   ## bblock 0, line 0,  t718,  addr(qy2?1.0)(P32)
;;								## 5
	c0    mov $r0.24 = (qt + 0)   ## bblock 0, line 0,  t719,  addr(qt?1.0)(P32)
;;								## 6
	c0    mov $r0.12 = ((qy2 + 0) + (~0xb))   ## bblock 0, line 0,  t723,  (addr(qy2?1.0)(P32) + 0xfffffff4(I32))(P32)
;;								## 7
	c0    add $r0.11 = $r0.4, -1   ## bblock 0, line 224,  t291,  t203,  -1(SI32)
;;								## 8
	c0    mov $r0.10 = ((in + 0) + (~0x2))   ## bblock 0, line 0,  t724,  (addr(in?1.0)(P32) + 0xfffffffd(I32))(P32)
;;								## 9
	c0    mov $r0.28 = $r0.3   ## t202
;;								## 10
	c0    mov $r0.23 = $r0.4   ## t203
;;								## 11
.trace 12
L61?3:
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 1, line 222,  t796(I1),  t725,  0(SI32)
;;								## 0
	c0    add $r0.8 = $r0.10, $r0.11   ## [spec] bblock 15, line 0,  t477,  t724,  t291
;;								## 1
	c0    brf $b0.0, L62?3   ## bblock 1, line 222,  t796(I1)
;;								## 2
	c0    sh2add $r0.7 = $r0.11, $r0.12   ## bblock 15, line 0,  t476,  t291,  t723
;;								## 3
	c0    mov $r0.2 = $r0.0   ## bblock 15, line 223,  t225,  0(SI32)
;;								## 4
	c0    mov $r0.4 = $r0.0   ## bblock 15, line 223,  t226,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 15, line 223,  t229,  0(SI32)
;;								## 6
	c0    mov $r0.3 = $r0.0   ## bblock 15, line 223,  t230,  0(SI32)
;;								## 7
	c0    mov $r0.20 = $r0.0   ## bblock 15, line 223,  t234,  0(SI32)
;;								## 8
	c0    mov $r0.21 = $r0.0   ## bblock 15, line 223,  t232,  0(SI32)
;;								## 9
	c0    mov $r0.22 = $r0.0   ## bblock 15, line 223,  t231,  0(SI32)
;;								## 10
	c0    mov $r0.6 = $r0.11   ## bblock 15, line 224,  t344,  t291
;;								## 11
	c0    mov $r0.16 = $r0.9   ## t725
;;								## 12
	c0    mov $r0.17 = $r0.10   ## t724
;;								## 13
	c0    mov $r0.18 = $r0.11   ## t291
;;								## 14
	c0    mov $r0.19 = $r0.12   ## t723
;;								## 15
.trace 2
L63?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 21, line 228,  t412,  t225,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 21, line 225,  t297,  t230,  -47(SI32)
;;								## 1
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 21, line 228,  t411(SI24),  t412,  8(SI32)
;;								## 2
	c0    add $r0.9 = $r0.9, $r0.2   ## [spec] bblock 21, line 229,  t812,  t297,  t411(SI24)
;;								## 3
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 21, line 227,  t17,  t226,  215(SI32)
;;								## 4
	c0    mpyl $r0.5 = $r0.5, -48   ## [spec] bblock 21, line 226,  t25,  t229,  -48(SI32)
;;								## 5
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 21, line 227,  t24(SI24),  t17,  8(SI32)
;;								## 6
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 21, line 229,  t813,  t25,  t24(SI24)
;;								## 7
	c0    add $r0.9 = $r0.9, $r0.5   ## [spec] bblock 21, line 229,  t295,  t812,  t813
;;								## 8
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 16, line 224,  t807(I1),  t344,  0(SI32)
;;								## 9
	c0    ldbu.d $r0.10 = 3[$r0.8]   ## [spec] bblock 21, line 231, t294, t477
;;								## 10
	c0    brf $b0.0, L64?3   ## bblock 16, line 224,  t807(I1)
;;								## 11
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 21, line 224-1,  t814(I1),  t344,  1(SI32)
;;								## 12
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 46, line 228-1,  t21,  t226,  -155(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.10, -47   ## [spec] bblock 46, line 225-1,  t26,  t294,  -47(SI32)
;;								## 14
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 46, line 228-1,  t23(SI24),  t21,  8(SI32)
;;								## 15
	c0    add $r0.11 = $r0.11, $r0.4   ## [spec] bblock 46, line 229-1,  t831,  t26,  t23(SI24)
;;								## 16
	c0    mpyl $r0.12 = $r0.9, 215   ## [spec] bblock 46, line 227-1,  t406,  t295,  215(SI32)
;;								## 17
	c0    mpyl $r0.3 = $r0.3, -48   ## [spec] bblock 46, line 226-1,  t318,  t230,  -48(SI32)
;;								## 18
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 46, line 227-1,  t405(SI24),  t406,  8(SI32)
;;								## 19
	c0    add $r0.3 = $r0.3, $r0.12   ## [spec] bblock 46, line 229-1,  t832,  t318,  t405(SI24)
;;								## 20
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 46, line 229-1,  t313,  t831,  t832
;;								## 21
	c0    ldbu.d $r0.12 = 2[$r0.8]   ## [spec] bblock 46, line 231-1, t404, t477
;;								## 22
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 46, line 224-2,  t833(I1),  t344,  2(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.9, -155   ## [spec] bblock 43, line 228-2,  t338,  t295,  -155(SI32)
;;								## 24
	c0    mpyl $r0.14 = $r0.12, -47   ## [spec] bblock 43, line 225-2,  t343,  t404,  -47(SI32)
;;								## 25
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 43, line 228-2,  t337(SI24),  t338,  8(SI32)
;;								## 26
	c0    add $r0.14 = $r0.14, $r0.13   ## [spec] bblock 43, line 229-2,  t828,  t343,  t337(SI24)
;;								## 27
	c0    mpyl $r0.13 = $r0.11, 215   ## [spec] bblock 43, line 227-2,  t340,  t313,  215(SI32)
;;								## 28
	c0    mpyl $r0.10 = $r0.10, -48   ## [spec] bblock 43, line 226-2,  t342,  t294,  -48(SI32)
;;								## 29
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 43, line 227-2,  t339(SI24),  t340,  8(SI32)
;;								## 30
	c0    add $r0.10 = $r0.10, $r0.13   ## [spec] bblock 43, line 229-2,  t829,  t342,  t339(SI24)
;;								## 31
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 43, line 229-2,  t335,  t828,  t829
;;								## 32
	c0    ldbu.d $r0.10 = 1[$r0.8]   ## [spec] bblock 43, line 231-2, t328, t477
;;								## 33
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 43, line 224-3,  t830(I1),  t344,  3(SI32)
;;								## 34
	c0    mpyl $r0.13 = $r0.11, -155   ## [spec] bblock 40, line 228-3,  t399,  t313,  -155(SI32)
;;								## 35
	c0    mpyl $r0.15 = $r0.10, -47   ## [spec] bblock 40, line 225-3,  t350,  t328,  -47(SI32)
;;								## 36
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 40, line 228-3,  t398(SI24),  t399,  8(SI32)
;;								## 37
	c0    add $r0.15 = $r0.15, $r0.13   ## [spec] bblock 40, line 229-3,  t826,  t350,  t398(SI24)
;;								## 38
	c0    mpyl $r0.13 = $r0.14, 215   ## [spec] bblock 40, line 227-3,  t347,  t335,  215(SI32)
;;								## 39
	c0    mpyl $r0.12 = $r0.12, -48   ## [spec] bblock 40, line 226-3,  t349,  t404,  -48(SI32)
;;								## 40
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 40, line 227-3,  t346(SI24),  t347,  8(SI32)
;;								## 41
	c0    add $r0.12 = $r0.12, $r0.13   ## [spec] bblock 40, line 229-3,  t827,  t349,  t346(SI24)
;;								## 42
	c0    add $r0.4 = $r0.15, $r0.12   ## [spec] bblock 40, line 229-3,  t226,  t826,  t827
;;								## 43
	c0    ldbu.d $r0.3 = 0[$r0.8]   ## [spec] bblock 40, line 231-3, t230, t477
;;								## 44
	c0    mov $r0.2 = $r0.14   ## [spec] bblock 40, line 229-2,  t225,  t335
;;								## 45
	c0    mov $r0.5 = $r0.10   ## [spec] bblock 40, line 231-2,  t229,  t328
;;								## 46
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 40, line 224-3,  t344,  t344,  -4(SI32)
;;								## 47
	c0    add $r0.8 = $r0.8, (~0x3)   ## [spec] bblock 40, line 0,  t477,  t477,  (~0x3)(I32)
;;								## 48
	c0    stw 12[$r0.7] = $r0.9   ## bblock 21, line 229, t476, t295
;;								## 49
	c0    brf $b0.0, L65?3   ## bblock 21, line 224-1,  t814(I1)
;;								## 50
	c0    stw 8[$r0.7] = $r0.11   ## bblock 46, line 229-1, t476, t313
;;								## 51
	c0    brf $b0.1, L66?3   ## bblock 46, line 224-2,  t833(I1)
;;								## 52
	c0    stw 4[$r0.7] = $r0.14   ## bblock 43, line 229-2, t476, t335
;;								## 53
	c0    brf $b0.2, L67?3   ## bblock 43, line 224-3,  t830(I1)
;;								## 54
	c0    stw 0[$r0.7] = $r0.4   ## bblock 40, line 229-3, t476, t226
;;								## 55
	c0    add $r0.7 = $r0.7, (~0xf)   ## bblock 40, line 0,  t476,  t476,  (~0xf)(I32)
	      ## goto
;;
	c0    goto L63?3 ## goto
;;								## 56
.trace 24
L67?3:
	c0    sub $r0.3 = 2, $r0.23   ## bblock 17, line 0,  t423,  2(I32),  t203
	      ## goto
;;
	c0    goto L68?3 ## goto
;;								## 0
.trace 4
L69?3:
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 20, line 237, t327, t418
;;								## 0
	c0    mpyl $r0.11 = $r0.4, 215   ## [spec] bblock 20, line 239,  t409,  t232,  215(SI32)
;;								## 1
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 20, line 240,  t325,  t231,  -155(SI32)
;;								## 2
	c0    mpyl $r0.12 = $r0.3, -48   ## [spec] bblock 20, line 237,  t410,  t327,  -48(SI32)
;;								## 3
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 20, line 239,  t326(SI24),  t409,  8(SI32)
;;								## 4
	c0    add $r0.12 = $r0.12, $r0.11   ## [spec] bblock 20, line 241,  t810,  t410,  t326(SI24)
;;								## 5
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 20, line 240,  t324(SI24),  t325,  8(SI32)
;;								## 6
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 20, line 238,  t64,  t234,  28(SI32)
;;								## 7
	c0    ldw.d $r0.11 = 0[$r0.7]   ## [spec] bblock 20, line 245, t321, t420
;;								## 8
	c0    add $r0.6 = $r0.6, $r0.5   ## [spec] bblock 20, line 241,  t809,  t64,  t324(SI24)
;;								## 9
	c0    add $r0.6 = $r0.6, $r0.12   ## [spec] bblock 20, line 241,  t322,  t809,  t810
;;								## 10
	c0    add $r0.11 = $r0.6, $r0.11   ## [spec] bblock 20, line 245,  t320,  t322,  t321
;;								## 11
	c0    shl $r0.11 = $r0.11, 8   ## [spec] bblock 20, line 245,  t408,  t320,  8(I32)
;;								## 12
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 20, line 245,  t407(SI24),  t408,  8(SI32)
;;								## 13
	c0    cmplt $b0.0 = $r0.8, 2   ## bblock 18, line 235,  t808(I1),  t422,  2(SI32)
;;								## 14
	c0    cmplt $b0.1 = $r0.8, 1   ## [spec] bblock 20, line 235-1,  t811(I1),  t422,  1(SI32)
;;								## 15
	c0    brf $b0.0, L70?3   ## bblock 18, line 235,  t808(I1)
;;								## 16
	c0    ldbu.d $r0.12 = 1[$r0.2]   ## [spec] bblock 53, line 237-1, t301, t418
;;								## 17
	c0    mpyl $r0.13 = $r0.6, 215   ## [spec] bblock 53, line 239-1,  t56,  t322,  215(SI32)
;;								## 18
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 53, line 240-1,  t60,  t232,  -155(SI32)
;;								## 19
	c0    mpyl $r0.14 = $r0.12, -48   ## [spec] bblock 53, line 237-1,  t65,  t301,  -48(SI32)
;;								## 20
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 53, line 239-1,  t63(SI24),  t56,  8(SI32)
;;								## 21
	c0    add $r0.14 = $r0.14, $r0.13   ## [spec] bblock 53, line 241-1,  t837,  t65,  t63(SI24)
;;								## 22
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 53, line 240-1,  t62(SI24),  t60,  8(SI32)
;;								## 23
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 53, line 238-1,  t302,  t327,  28(SI32)
;;								## 24
	c0    ldw.d $r0.13 = 4[$r0.7]   ## [spec] bblock 53, line 245-1, t82, t420
;;								## 25
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 53, line 241-1,  t836,  t302,  t62(SI24)
;;								## 26
	c0    add $r0.3 = $r0.3, $r0.14   ## [spec] bblock 53, line 241-1,  t299,  t836,  t837
;;								## 27
	c0    add $r0.13 = $r0.3, $r0.13   ## [spec] bblock 53, line 245-1,  t87,  t299,  t82
;;								## 28
	c0    shl $r0.13 = $r0.13, 8   ## [spec] bblock 53, line 245-1,  t89,  t87,  8(I32)
;;								## 29
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 53, line 245-1,  t90(SI24),  t89,  8(SI32)
;;								## 30
	c0    cmplt $b0.0 = $r0.8, $r0.0   ## [spec] bblock 53, line 235-2,  t838(I1),  t422,  0(SI32)
;;								## 31
	c0    ldbu.d $r0.14 = 2[$r0.2]   ## [spec] bblock 50, line 237-2, t234, t418
;;								## 32
	c0    mpyl $r0.15 = $r0.3, 215   ## [spec] bblock 50, line 239-2,  t402,  t299,  215(SI32)
;;								## 33
	c0    mpyl $r0.16 = $r0.6, -155   ## [spec] bblock 50, line 240-2,  t310,  t322,  -155(SI32)
;;								## 34
	c0    mpyl $r0.17 = $r0.14, -48   ## [spec] bblock 50, line 237-2,  t403,  t234,  -48(SI32)
;;								## 35
	c0    shr $r0.15 = $r0.15, 8   ## [spec] bblock 50, line 239-2,  t311(SI24),  t402,  8(SI32)
;;								## 36
	c0    add $r0.17 = $r0.17, $r0.15   ## [spec] bblock 50, line 241-2,  t835,  t403,  t311(SI24)
;;								## 37
	c0    shr $r0.16 = $r0.16, 8   ## [spec] bblock 50, line 240-2,  t309(SI24),  t310,  8(SI32)
;;								## 38
	c0    mpyl $r0.12 = $r0.12, 28   ## [spec] bblock 50, line 238-2,  t304,  t301,  28(SI32)
;;								## 39
	c0    ldw.d $r0.15 = 8[$r0.7]   ## [spec] bblock 50, line 245-2, t308, t420
;;								## 40
	c0    add $r0.12 = $r0.12, $r0.16   ## [spec] bblock 50, line 241-2,  t834,  t304,  t309(SI24)
;;								## 41
	c0    add $r0.4 = $r0.12, $r0.17   ## [spec] bblock 50, line 241-2,  t232,  t834,  t835
;;								## 42
	c0    add $r0.15 = $r0.4, $r0.15   ## [spec] bblock 50, line 245-2,  t307,  t232,  t308
;;								## 43
	c0    shl $r0.15 = $r0.15, 8   ## [spec] bblock 50, line 245-2,  t306,  t307,  8(I32)
;;								## 44
	c0    shr $r0.15 = $r0.15, 8   ## [spec] bblock 50, line 245-2,  t305(SI24),  t306,  8(SI32)
;;								## 45
	c0    mov $r0.5 = $r0.3   ## [spec] bblock 50, line 241-1,  t231,  t299
;;								## 46
	c0    add $r0.2 = $r0.2, 3   ## [spec] bblock 50, line 0,  t418,  t418,  3(I32)
;;								## 47
	c0    add $r0.7 = $r0.7, 12   ## [spec] bblock 50, line 0,  t420,  t420,  12(I32)
;;								## 48
	c0    add $r0.8 = $r0.8, 3   ## [spec] bblock 50, line 0,  t422,  t422,  3(I32)
;;								## 49
	c0    stw 0[$r0.10] = $r0.6   ## bblock 20, line 241, t419, t322
;;								## 50
	c0    mov $r0.6 = $r0.14   ## [spec] t234
;;								## 51
	c0    stw 0[$r0.9] = $r0.11   ## bblock 20, line 245, t421, t407(SI24)
;;								## 52
	c0    brf $b0.1, L70?3   ## bblock 20, line 235-1,  t811(I1)
;;								## 53
	c0    stw 4[$r0.10] = $r0.3   ## bblock 53, line 241-1, t419, t299
;;								## 54
	c0    stw 4[$r0.9] = $r0.13   ## bblock 53, line 245-1, t421, t90(SI24)
;;								## 55
	c0    brf $b0.0, L70?3   ## bblock 53, line 235-2,  t838(I1)
;;								## 56
	c0    stw 8[$r0.10] = $r0.4   ## bblock 50, line 241-2, t419, t232
;;								## 57
	c0    add $r0.10 = $r0.10, 12   ## bblock 50, line 0,  t419,  t419,  12(I32)
;;								## 58
	c0    stw 8[$r0.9] = $r0.15   ## bblock 50, line 245-2, t421, t305(SI24)
;;								## 59
	c0    add $r0.9 = $r0.9, 12   ## bblock 50, line 0,  t421,  t421,  12(I32)
	      ## goto
;;
	c0    goto L69?3 ## goto
;;								## 60
.trace 16
L70?3:
	c0    add $r0.27 = $r0.27, 1050   ## bblock 19, line 0,  t715,  t715,  1050(I32)
;;								## 0
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 1
	c0    add $r0.26 = $r0.26, $r0.2   ## bblock 19, line 0,  t717,  t717,  4200(I32)
;;								## 2
	c0    add $r0.25 = $r0.25, $r0.2   ## bblock 19, line 0,  t718,  t718,  4200(I32)
;;								## 3
	c0    add $r0.24 = $r0.24, $r0.2   ## bblock 19, line 0,  t719,  t719,  4200(I32)
;;								## 4
	c0    add $r0.12 = $r0.19, $r0.2   ## bblock 19, line 0,  t723,  t723,  4200(I32)
;;								## 5
	c0    add $r0.10 = $r0.20, 1050   ## bblock 19, line 0,  t724,  t724,  1050(I32)
;;								## 6
	c0    add $r0.9 = $r0.21, 1   ## bblock 19, line 0,  t725,  t725,  1(I32)
;;								## 7
	c0    mov $r0.11 = $r0.18   ## t291
	      ## goto
;;
	c0    goto L61?3 ## goto
;;								## 8
.trace 23
L66?3:
	c0    sub $r0.3 = 2, $r0.23   ## bblock 17, line 0,  t423,  2(I32),  t203
	      ## goto
;;
	c0    goto L68?3 ## goto
;;								## 0
.trace 20
L65?3:
	c0    sub $r0.3 = 2, $r0.23   ## bblock 17, line 0,  t423,  2(I32),  t203
	      ## goto
;;
	c0    goto L68?3 ## goto
;;								## 0
.trace 14
L64?3:
	c0    sub $r0.3 = 2, $r0.23   ## bblock 17, line 0,  t423,  2(I32),  t203
;;								## 0
L68?3:
	c0    mov $r0.8 = $r0.3   ## bblock 17, line 0,  t422,  t423
;;								## 1
	c0    mov $r0.9 = $r0.24   ## bblock 17, line 0,  t421,  t719
;;								## 2
	c0    mov $r0.7 = $r0.25   ## bblock 17, line 0,  t420,  t718
;;								## 3
	c0    mov $r0.10 = $r0.26   ## bblock 17, line 0,  t419,  t717
;;								## 4
	c0    mov $r0.2 = $r0.27   ## bblock 17, line 0,  t418,  t715
;;								## 5
	c0    mov $r0.6 = $r0.20   ## t234
;;								## 6
	c0    mov $r0.4 = $r0.21   ## t232
;;								## 7
	c0    mov $r0.5 = $r0.22   ## t231
;;								## 8
	c0    mov $r0.20 = $r0.17   ## t724
;;								## 9
	c0    mov $r0.21 = $r0.16   ## t725
	      ## goto
;;
	c0    goto L69?3 ## goto
;;								## 10
.trace 26
L62?3:
	c0    sub $r0.23 = $r0.0, $r0.23   ## bblock 2, line 0,  t665,  0(I32),  t203
;;								## 0
	c0    mov $r0.9 = $r0.23   ## bblock 2, line 0,  t664,  t665
;;								## 1
	c0    mov $r0.26 = (qt + 0)   ## bblock 2, line 0,  t655,  addr(qt?1.0)(P32)
;;								## 2
	c0    mov $r0.25 = (qy1 + 0)   ## bblock 2, line 0,  t656,  addr(qy1?1.0)(P32)
;;								## 3
	c0    mov $r0.24 = (qy2 + 0)   ## bblock 2, line 0,  t657,  addr(qy2?1.0)(P32)
;;								## 4
	c0    mov $r0.23 = (out + 0)   ## bblock 2, line 0,  t658,  addr(out?1.0)(P32)
;;								## 5
	c0    mov $r0.12 = ((qy2 + 0) + (~0x3137))   ## bblock 2, line 0,  t662,  (addr(qy2?1.0)(P32) + 0xffffcec8(I32))(P32)
;;								## 6
	c0    mov $r0.11 = ((qt + 0) + (~0x3137))   ## bblock 2, line 0,  t663,  (addr(qt?1.0)(P32) + 0xffffcec8(I32))(P32)
;;								## 7
	c0    add $r0.10 = $r0.28, -1   ## bblock 2, line 251,  t292,  t202,  -1(SI32)
;;								## 8
	c0    mov $r0.22 = $r0.28   ## t202
;;								## 9
.trace 11
L71?3:
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 3, line 249,  t797(I1),  t664,  0(SI32)
;;								## 0
	c0    mpylu $r0.13 = $r0.10, 4200   ## [spec] bblock 5, line 0,  t598,  t292,  4200(I32)
;;								## 1
	c0    brf $b0.0, L72?3   ## bblock 3, line 249,  t797(I1)
;;								## 2
	c0    add $r0.8 = $r0.11, $r0.13   ## bblock 5, line 0,  t588,  t663,  t598
;;								## 3
	c0    add $r0.7 = $r0.12, $r0.13   ## bblock 5, line 0,  t587,  t662,  t598
;;								## 4
	c0    mov $r0.3 = $r0.0   ## bblock 5, line 250,  t228,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 5, line 250,  t331,  0(SI32)
;;								## 6
	c0    mov $r0.4 = $r0.0   ## bblock 5, line 250,  t286(SI24),  0(SI32)
;;								## 7
	c0    mov $r0.2 = $r0.0   ## bblock 5, line 250,  t330,  0(SI32)
;;								## 8
	c0    mov $r0.19 = $r0.0   ## bblock 5, line 250,  t289(SI24),  0(SI32)
;;								## 9
	c0    mov $r0.20 = $r0.0   ## bblock 5, line 250,  t287,  0(SI32)
;;								## 10
	c0    mov $r0.21 = $r0.0   ## bblock 5, line 250,  t233,  0(SI32)
;;								## 11
	c0    mov $r0.6 = $r0.10   ## bblock 5, line 251,  t288,  t292
;;								## 12
	c0    mov $r0.15 = $r0.9   ## t664
;;								## 13
	c0    mov $r0.16 = $r0.10   ## t292
;;								## 14
	c0    mov $r0.17 = $r0.11   ## t663
;;								## 15
	c0    mov $r0.18 = $r0.12   ## t662
;;								## 16
.trace 1
L73?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 14, line 252,  t354,  t330,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 14, line 252,  t401,  t228,  -47(SI32)
;;								## 1
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 14, line 252,  t333,  t286(SI24),  215(SI32)
;;								## 2
	c0    add $r0.2 = $r0.2, $r0.9   ## [spec] bblock 14, line 252,  t804,  t354,  t401
;;								## 3
	c0    mpyl $r0.5 = $r0.5, 29   ## [spec] bblock 14, line 252,  t111,  t331,  29(SI32)
;;								## 4
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 6, line 251,  t798(I1),  t288,  0(SI32)
;;								## 5
	c0    add $r0.10 = $r0.10, $r0.5   ## [spec] bblock 14, line 252,  t805,  t333,  t111
;;								## 6
	c0    add $r0.2 = $r0.2, $r0.10   ## [spec] bblock 14, line 252,  t400,  t804,  t805
;;								## 7
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 14, line 252,  t792,  t400,  8(SI32)
;;								## 8
	c0    brf $b0.0, L74?3   ## bblock 6, line 251,  t798(I1)
;;								## 9
	c0    ldw $r0.9 = 12600[$r0.8]   ## bblock 14, line 254, t351, t588
;;								## 10
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 14, line 251-1,  t806(I1),  t288,  1(SI32)
;;								## 11
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 29, line 252-1,  t362,  t286(SI24),  -155(SI32)
;;								## 12
	c0    mpyl $r0.10 = $r0.9, -47   ## [spec] bblock 29, line 252-1,  t114,  t351,  -47(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.2, 215   ## [spec] bblock 29, line 252-1,  t359,  t792,  215(SI32)
;;								## 14
	c0    add $r0.4 = $r0.4, $r0.10   ## [spec] bblock 29, line 252-1,  t820,  t362,  t114
;;								## 15
	c0    mpyl $r0.3 = $r0.3, 29   ## [spec] bblock 29, line 252-1,  t360,  t228,  29(SI32)
;;								## 16
	c0    ldw.d $r0.10 = 8400[$r0.8]   ## [spec] bblock 29, line 254-1, t356, t588
;;								## 17
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 29, line 252-1,  t821,  t359,  t360
;;								## 18
	c0    add $r0.4 = $r0.4, $r0.11   ## [spec] bblock 29, line 252-1,  t389,  t820,  t821
;;								## 19
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 29, line 252-1,  t793,  t389,  8(SI32)
;;								## 20
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 29, line 251-2,  t822(I1),  t288,  2(SI32)
;;								## 21
	c0    mpyl $r0.11 = $r0.2, -155   ## [spec] bblock 26, line 252-2,  t105,  t792,  -155(SI32)
;;								## 22
	c0    mpyl $r0.12 = $r0.10, -47   ## [spec] bblock 26, line 252-2,  t392,  t356,  -47(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.4, 215   ## [spec] bblock 26, line 252-2,  t108,  t793,  215(SI32)
;;								## 24
	c0    add $r0.11 = $r0.11, $r0.12   ## [spec] bblock 26, line 252-2,  t817,  t105,  t392
;;								## 25
	c0    mpyl $r0.9 = $r0.9, 29   ## [spec] bblock 26, line 252-2,  t369,  t351,  29(SI32)
;;								## 26
	c0    ldw.d $r0.12 = 4200[$r0.8]   ## [spec] bblock 26, line 254-2, t363, t588
;;								## 27
	c0    add $r0.13 = $r0.13, $r0.9   ## [spec] bblock 26, line 252-2,  t818,  t108,  t369
;;								## 28
	c0    add $r0.11 = $r0.11, $r0.13   ## [spec] bblock 26, line 252-2,  t391,  t817,  t818
;;								## 29
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 26, line 252-2,  t794,  t391,  8(SI32)
;;								## 30
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 26, line 251-3,  t819(I1),  t288,  3(SI32)
;;								## 31
	c0    mpyl $r0.9 = $r0.4, -155   ## [spec] bblock 23, line 252-3,  t385,  t793,  -155(SI32)
;;								## 32
	c0    mpyl $r0.13 = $r0.12, -47   ## [spec] bblock 23, line 252-3,  t382,  t363,  -47(SI32)
;;								## 33
	c0    mpyl $r0.14 = $r0.11, 215   ## [spec] bblock 23, line 252-3,  t384,  t794,  215(SI32)
;;								## 34
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 23, line 252-3,  t815,  t385,  t382
;;								## 35
	c0    mpyl $r0.10 = $r0.10, 29   ## [spec] bblock 23, line 252-3,  t383,  t356,  29(SI32)
;;								## 36
	c0    ldw.d $r0.3 = 0[$r0.8]   ## [spec] bblock 23, line 254-3, t228, t588
;;								## 37
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 23, line 252-3,  t816,  t384,  t383
;;								## 38
	c0    add $r0.9 = $r0.9, $r0.14   ## [spec] bblock 23, line 252-3,  t115,  t815,  t816
;;								## 39
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 23, line 252-3,  t286(SI24),  t115,  8(SI32)
;;								## 40
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 23, line 251-3,  t288,  t288,  -4(SI32)
;;								## 41
	c0    stw 12600[$r0.7] = $r0.2   ## bblock 14, line 252, t587, t792
;;								## 42
	c0    brf $b0.0, L74?3   ## bblock 14, line 251-1,  t806(I1)
;;								## 43
	c0    mov $r0.2 = $r0.11   ## [spec] bblock 23, line 252-2,  t330,  t794
;;								## 44
	c0    mov $r0.5 = $r0.12   ## [spec] bblock 23, line 254-2,  t331,  t363
;;								## 45
	c0    add $r0.8 = $r0.8, (~0x419f)   ## [spec] bblock 23, line 0,  t588,  t588,  (~0x419f)(I32)
;;								## 46
	c0    stw 8400[$r0.7] = $r0.4   ## bblock 29, line 252-1, t587, t793
;;								## 47
	c0    brf $b0.1, L74?3   ## bblock 29, line 251-2,  t822(I1)
;;								## 48
	c0    mov $r0.4 = $r0.9   ## [spec] t286(SI24)
;;								## 49
	c0    stw 4200[$r0.7] = $r0.11   ## bblock 26, line 252-2, t587, t794
;;								## 50
	c0    brf $b0.2, L74?3   ## bblock 26, line 251-3,  t819(I1)
;;								## 51
	c0    stw 0[$r0.7] = $r0.9   ## bblock 23, line 252-3, t587, t286(SI24)
;;								## 52
	c0    add $r0.7 = $r0.7, (~0x419f)   ## bblock 23, line 0,  t587,  t587,  (~0x419f)(I32)
	      ## goto
;;
	c0    goto L73?3 ## goto
;;								## 53
.trace 13
L74?3:
	c0    sub $r0.3 = 1, $r0.22   ## bblock 7, line 0,  t523,  1(I32),  t202
;;								## 0
	c0    mov $r0.8 = $r0.3   ## bblock 7, line 0,  t522,  t523
;;								## 1
	c0    mov $r0.9 = $r0.23   ## bblock 7, line 0,  t521,  t658
;;								## 2
	c0    mov $r0.7 = $r0.24   ## bblock 7, line 0,  t520,  t657
;;								## 3
	c0    mov $r0.10 = $r0.25   ## bblock 7, line 0,  t519,  t656
;;								## 4
	c0    mov $r0.2 = $r0.26   ## bblock 7, line 0,  t518,  t655
;;								## 5
	c0    mov $r0.4 = $r0.20   ## t287
;;								## 6
	c0    mov $r0.5 = $r0.19   ## t289(SI24)
;;								## 7
	c0    mov $r0.6 = $r0.21   ## t233
;;								## 8
	c0    mov $r0.11 = 8400   ## 8400(I32)
;;								## 9
	c0    mov $r0.19 = $r0.17   ## t663
;;								## 10
	c0    mov $r0.17 = $r0.16   ## t292
;;								## 11
	c0    mov $r0.20 = $r0.15   ## t664
;;								## 12
.trace 3
L75?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 10, line 259, t377, t518
;;								## 0
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 10, line 259,  t381,  t287,  -155(SI32)
;;								## 1
	c0    mpyl $r0.12 = $r0.5, 215   ## [spec] bblock 10, line 259,  t396,  t289(SI24),  215(SI32)
;;								## 2
	c0    mpyl $r0.13 = $r0.3, -48   ## [spec] bblock 10, line 259,  t376,  t377,  -48(SI32)
;;								## 3
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 10, line 259,  t395,  t233,  28(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.13   ## [spec] bblock 10, line 259,  t800,  t381,  t376
;;								## 5
	c0    add $r0.12 = $r0.12, $r0.6   ## [spec] bblock 10, line 259,  t801,  t396,  t395
;;								## 6
	c0    add $r0.4 = $r0.4, $r0.12   ## [spec] bblock 10, line 259,  t394,  t800,  t801
;;								## 7
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 10, line 259,  t393(SI24),  t394,  8(SI32)
;;								## 8
	c0    ldw.d $r0.12 = 0[$r0.7]   ## [spec] bblock 10, line 263, t375, t520
;;								## 9
	c0    cmplt $b0.0 = $r0.8, 1   ## bblock 8, line 258,  t799(I1),  t522,  1(SI32)
;;								## 10
	c0    cmplt $b0.1 = $r0.8, $r0.0   ## [spec] bblock 12, line 258-1,  t803(I1),  t522,  0(SI32)
;;								## 11
	c0    add $r0.12 = $r0.4, $r0.12   ## [spec] bblock 10, line 263,  t374,  t393(SI24),  t375
;;								## 12
	c0    shl $r0.12 = $r0.12, 8   ## [spec] bblock 10, line 263,  t373,  t374,  8(I32)
;;								## 13
	c0    shr $r0.12 = $r0.12, 16   ## [spec] bblock 10, line 263,  t372(SI16),  t373,  16(SI32)
;;								## 14
	c0    brf $b0.0, L76?3   ## bblock 8, line 258,  t799(I1)
;;								## 15
	c0    zxtb $r0.13 = $r0.12   ## bblock 10, line 263,  t371(I8),  t372(SI16)
;;								## 16
	c0    cmpgt $b0.0 = $r0.13, 25   ## bblock 10, line 264,  t802(I1),  t371(I8),  25(SI32)
;;								## 17
	c0    ldw.d $r0.6 = 4200[$r0.2]   ## [spec] bblock 33, line 259-1, t233, t518
;;								## 18
	c0    mpyl $r0.13 = $r0.5, -155   ## [spec] bblock 33, line 259-1,  t136,  t289(SI24),  -155(SI32)
;;								## 19
	c0    mpyl $r0.14 = $r0.4, 215   ## [spec] bblock 33, line 259-1,  t139,  t393(SI24),  215(SI32)
;;								## 20
	c0    mpyl $r0.15 = $r0.6, -48   ## [spec] bblock 33, line 259-1,  t148,  t233,  -48(SI32)
;;								## 21
	c0    mpyl $r0.16 = $r0.3, 28   ## [spec] bblock 33, line 259-1,  t142,  t377,  28(SI32)
;;								## 22
	c0    add $r0.13 = $r0.13, $r0.15   ## [spec] bblock 33, line 259-1,  t823,  t136,  t148
;;								## 23
	c0    add $r0.14 = $r0.14, $r0.16   ## [spec] bblock 33, line 259-1,  t824,  t139,  t142
;;								## 24
	c0    add $r0.13 = $r0.13, $r0.14   ## [spec] bblock 33, line 259-1,  t149,  t823,  t824
;;								## 25
	c0    ldw.d $r0.14 = 4200[$r0.7]   ## [spec] bblock 33, line 263-1, t166, t520
;;								## 26
	c0    mov $r0.15 = $r0.4   ## [spec] bblock 33, line 259-1,  t287,  t393(SI24)
;;								## 27
	c0    stb 0[$r0.9] = $r0.12   ## bblock 10, line 263, t521, t372(SI16)
;;								## 28
	c0    stw 0[$r0.10] = $r0.4   ## bblock 10, line 259, t519, t393(SI24)
;;								## 29
	c0    brf $b0.0, L77?3   ## bblock 10, line 264,  t802(I1)
;;								## 30
	c0    shr $r0.5 = $r0.13, 8   ## [spec] bblock 33, line 259-1,  t289(SI24),  t149,  8(SI32)
;;								## 31
	c0    add $r0.14 = $r0.5, $r0.14   ## [spec] bblock 33, line 263-1,  t171,  t289(SI24),  t166
;;								## 32
	c0    shl $r0.14 = $r0.14, 8   ## [spec] bblock 33, line 263-1,  t173,  t171,  8(I32)
;;								## 33
	c0    shr $r0.14 = $r0.14, 16   ## [spec] bblock 33, line 263-1,  t174(SI16),  t173,  16(SI32)
;;								## 34
	c0    zxtb $r0.3 = $r0.14   ## [spec] bblock 33, line 263-1,  t182(I8),  t174(SI16)
;;								## 35
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 33, line 264-1,  t825(I1),  t182(I8),  25(SI32)
;;								## 36
	c0    mov $r0.4 = $r0.15   ## [spec] t287
;;								## 37
	c0    stb 0[$r0.9] = $r0.0   ## bblock 13, line 265, t521, 0(I32)
;;								## 38
L78?3:
	c0    brf $b0.1, L76?3   ## bblock 12, line 258-1,  t803(I1)
;;								## 39
	c0    stw 4200[$r0.10] = $r0.5   ## bblock 33, line 259-1, t519, t289(SI24)
;;								## 40
	c0    stb 1050[$r0.9] = $r0.14   ## bblock 33, line 263-1, t521, t174(SI16)
;;								## 41
	c0    brf $b0.0, L79?3   ## bblock 33, line 264-1,  t825(I1)
;;								## 42
	c0    add $r0.2 = $r0.2, $r0.11   ## bblock 35, line 0,  t518,  t518,  8400(I32)
;;								## 43
	c0    add $r0.10 = $r0.10, $r0.11   ## bblock 35, line 0,  t519,  t519,  8400(I32)
;;								## 44
	c0    add $r0.7 = $r0.7, $r0.11   ## bblock 35, line 0,  t520,  t520,  8400(I32)
;;								## 45
	c0    add $r0.8 = $r0.8, 2   ## bblock 35, line 0,  t522,  t522,  2(I32)
;;								## 46
	c0    stb 1050[$r0.9] = $r0.0   ## bblock 36, line 265-1, t521, 0(I32)
;;								## 47
L80?3:
	c0    add $r0.9 = $r0.9, 2100   ## bblock 35, line 0,  t521,  t521,  2100(I32)
	      ## goto
;;
	c0    goto L75?3 ## goto
;;								## 48
.trace 10
L79?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.8 = $r0.8, 2   ## bblock 35, line 0,  t522,  t522,  2(I32)
;;								## 1
	c0    add $r0.7 = $r0.7, $r0.11   ## bblock 35, line 0,  t520,  t520,  8400(I32)
;;								## 2
	c0    add $r0.10 = $r0.10, $r0.11   ## bblock 35, line 0,  t519,  t519,  8400(I32)
;;								## 3
	c0    add $r0.2 = $r0.2, $r0.11   ## bblock 35, line 0,  t518,  t518,  8400(I32)
;;								## 4
	c0    stb 1050[$r0.9] = $r0.3   ## bblock 34, line 267-1, t521, 255(I32)
	      ## goto
;;
	c0    goto L80?3 ## goto
;;								## 5
.trace 15
L76?3:
	c0    add $r0.26 = $r0.26, 4   ## bblock 9, line 0,  t655,  t655,  4(I32)
;;								## 0
	c0    add $r0.25 = $r0.25, 4   ## bblock 9, line 0,  t656,  t656,  4(I32)
;;								## 1
	c0    add $r0.24 = $r0.24, 4   ## bblock 9, line 0,  t657,  t657,  4(I32)
;;								## 2
	c0    add $r0.23 = $r0.23, 1   ## bblock 9, line 0,  t658,  t658,  1(I32)
;;								## 3
	c0    add $r0.12 = $r0.18, 4   ## bblock 9, line 0,  t662,  t662,  4(I32)
;;								## 4
	c0    add $r0.11 = $r0.19, 4   ## bblock 9, line 0,  t663,  t663,  4(I32)
;;								## 5
	c0    add $r0.9 = $r0.20, 1   ## bblock 9, line 0,  t664,  t664,  1(I32)
;;								## 6
	c0    mov $r0.10 = $r0.17   ## t292
	      ## goto
;;
	c0    goto L71?3 ## goto
;;								## 7
.trace 9
L77?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    shr $r0.5 = $r0.13, 8   ## [spec] bblock 33, line 259-1,  t289(SI24),  t149,  8(SI32)
;;								## 1
	c0    add $r0.14 = $r0.5, $r0.14   ## [spec] bblock 33, line 263-1,  t171,  t289(SI24),  t166
;;								## 2
	c0    shl $r0.14 = $r0.14, 8   ## [spec] bblock 33, line 263-1,  t173,  t171,  8(I32)
;;								## 3
	c0    shr $r0.14 = $r0.14, 16   ## [spec] bblock 33, line 263-1,  t174(SI16),  t173,  16(SI32)
;;								## 4
	c0    zxtb $r0.12 = $r0.14   ## [spec] bblock 33, line 263-1,  t182(I8),  t174(SI16)
;;								## 5
	c0    cmpgt $b0.0 = $r0.12, 25   ## [spec] bblock 33, line 264-1,  t825(I1),  t182(I8),  25(SI32)
;;								## 6
	c0    mov $r0.4 = $r0.15   ## t287
;;								## 7
	c0    stb 0[$r0.9] = $r0.3   ## bblock 11, line 267, t521, 255(I32)
	      ## goto
;;
	c0    goto L78?3 ## goto
;;								## 8
.trace 28
L72?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 4, line 271,  t190,  ?2.3?2auto_size(I32),  t189
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.3?2auto_size, 0x0
 ## End deriche_fused
 ## Begin deriche_array
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_array::
.trace 27
	      ## auto_size == 0
;;								## 0
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t657,  0(I32),  t190
;;								## 1
	c0    mov $r0.9 = $r0.2   ## bblock 0, line 0,  t656,  t657
;;								## 2
	c0    mov $r0.24 = (in + 0)   ## bblock 0, line 0,  t649,  addr(in?1.0)(P32)
;;								## 3
	c0    mov $r0.23 = (at + 0)   ## bblock 0, line 0,  t651,  addr(at?1.0)(P32)
;;								## 4
	c0    add $r0.11 = $r0.4, -1   ## bblock 0, line 296,  t255,  t191,  -1(SI32)
;;								## 5
	c0    mov $r0.10 = ((in + 0) + (~0x2))   ## bblock 0, line 0,  t655,  (addr(in?1.0)(P32) + 0xfffffffd(I32))(P32)
;;								## 6
	c0    mov $r0.25 = $r0.3   ## t190
;;								## 7
	c0    mov $r0.13 = $r0.4   ## t191
;;								## 8
.trace 12
L81?3:
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 1, line 294,  t712(I1),  t656,  0(SI32)
;;								## 0
	c0    add $r0.8 = $r0.10, $r0.11   ## [spec] bblock 15, line 0,  t437,  t655,  t255
;;								## 1
	c0    brf $b0.0, L82?3   ## bblock 1, line 294,  t712(I1)
;;								## 2
	c0    sh2add $r0.7 = $r0.13, (((ay2 + 0) + (~0xb)) + (~0x3))   ## bblock 15, line 0,  t436,  t191,  ((addr(ay2?1.0)(P32) + 0xfffffff4(I32))(P32) + 0xfffffffc(I32))(P32)
;;								## 3
	c0    mov $r0.2 = $r0.0   ## bblock 15, line 295,  t213,  0(SI32)
;;								## 4
	c0    mov $r0.4 = $r0.0   ## bblock 15, line 295,  t214,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 15, line 295,  t217,  0(SI32)
;;								## 6
	c0    mov $r0.3 = $r0.0   ## bblock 15, line 295,  t218,  0(SI32)
;;								## 7
	c0    mov $r0.20 = $r0.0   ## bblock 15, line 295,  t222,  0(SI32)
;;								## 8
	c0    mov $r0.21 = $r0.0   ## bblock 15, line 295,  t220,  0(SI32)
;;								## 9
	c0    mov $r0.22 = $r0.0   ## bblock 15, line 295,  t219,  0(SI32)
;;								## 10
	c0    mov $r0.6 = $r0.11   ## bblock 15, line 296,  t247,  t255
;;								## 11
	c0    mov $r0.16 = $r0.9   ## t656
;;								## 12
	c0    mov $r0.17 = $r0.10   ## t655
;;								## 13
	c0    mov $r0.18 = $r0.11   ## t255
;;								## 14
	c0    mov $r0.19 = $r0.13   ## t191
;;								## 15
.trace 2
L83?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 21, line 300,  t21,  t213,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 21, line 297,  t26,  t218,  -47(SI32)
;;								## 1
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 21, line 300,  t23(SI24),  t21,  8(SI32)
;;								## 2
	c0    add $r0.9 = $r0.9, $r0.2   ## [spec] bblock 21, line 301,  t728,  t26,  t23(SI24)
;;								## 3
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 21, line 299,  t17,  t214,  215(SI32)
;;								## 4
	c0    mpyl $r0.5 = $r0.5, -48   ## [spec] bblock 21, line 298,  t25,  t217,  -48(SI32)
;;								## 5
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 21, line 299,  t24(SI24),  t17,  8(SI32)
;;								## 6
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 21, line 301,  t729,  t25,  t24(SI24)
;;								## 7
	c0    add $r0.9 = $r0.9, $r0.5   ## [spec] bblock 21, line 301,  t266,  t728,  t729
;;								## 8
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 16, line 296,  t723(I1),  t247,  0(SI32)
;;								## 9
	c0    ldbu.d $r0.10 = 3[$r0.8]   ## [spec] bblock 21, line 303, t375, t437
;;								## 10
	c0    brf $b0.0, L84?3   ## bblock 16, line 296,  t723(I1)
;;								## 11
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 21, line 296-1,  t730(I1),  t247,  1(SI32)
;;								## 12
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 46, line 300-1,  t279,  t214,  -155(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.10, -47   ## [spec] bblock 46, line 297-1,  t288,  t375,  -47(SI32)
;;								## 14
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 46, line 300-1,  t282(SI24),  t279,  8(SI32)
;;								## 15
	c0    add $r0.11 = $r0.11, $r0.4   ## [spec] bblock 46, line 301-1,  t747,  t288,  t282(SI24)
;;								## 16
	c0    mpyl $r0.12 = $r0.9, 215   ## [spec] bblock 46, line 299-1,  t285,  t266,  215(SI32)
;;								## 17
	c0    mpyl $r0.3 = $r0.3, -48   ## [spec] bblock 46, line 298-1,  t287,  t218,  -48(SI32)
;;								## 18
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 46, line 299-1,  t284(SI24),  t285,  8(SI32)
;;								## 19
	c0    add $r0.3 = $r0.3, $r0.12   ## [spec] bblock 46, line 301-1,  t748,  t287,  t284(SI24)
;;								## 20
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 46, line 301-1,  t280,  t747,  t748
;;								## 21
	c0    ldbu.d $r0.12 = 2[$r0.8]   ## [spec] bblock 46, line 303-1, t278, t437
;;								## 22
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 46, line 296-2,  t749(I1),  t247,  2(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.9, -155   ## [spec] bblock 43, line 300-2,  t283,  t266,  -155(SI32)
;;								## 24
	c0    mpyl $r0.14 = $r0.12, -47   ## [spec] bblock 43, line 297-2,  t297,  t278,  -47(SI32)
;;								## 25
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 43, line 300-2,  t292(SI24),  t283,  8(SI32)
;;								## 26
	c0    add $r0.14 = $r0.14, $r0.13   ## [spec] bblock 43, line 301-2,  t744,  t297,  t292(SI24)
;;								## 27
	c0    mpyl $r0.13 = $r0.11, 215   ## [spec] bblock 43, line 299-2,  t293,  t280,  215(SI32)
;;								## 28
	c0    mpyl $r0.10 = $r0.10, -48   ## [spec] bblock 43, line 298-2,  t296,  t375,  -48(SI32)
;;								## 29
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 43, line 299-2,  t294(SI24),  t293,  8(SI32)
;;								## 30
	c0    add $r0.10 = $r0.10, $r0.13   ## [spec] bblock 43, line 301-2,  t745,  t296,  t294(SI24)
;;								## 31
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 43, line 301-2,  t371,  t744,  t745
;;								## 32
	c0    ldbu.d $r0.10 = 1[$r0.8]   ## [spec] bblock 43, line 303-2, t290, t437
;;								## 33
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 43, line 296-3,  t746(I1),  t247,  3(SI32)
;;								## 34
	c0    mpyl $r0.13 = $r0.11, -155   ## [spec] bblock 40, line 300-3,  t315,  t280,  -155(SI32)
;;								## 35
	c0    mpyl $r0.15 = $r0.10, -47   ## [spec] bblock 40, line 297-3,  t319,  t290,  -47(SI32)
;;								## 36
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 40, line 300-3,  t312(SI24),  t315,  8(SI32)
;;								## 37
	c0    add $r0.15 = $r0.15, $r0.13   ## [spec] bblock 40, line 301-3,  t742,  t319,  t312(SI24)
;;								## 38
	c0    mpyl $r0.13 = $r0.14, 215   ## [spec] bblock 40, line 299-3,  t317,  t371,  215(SI32)
;;								## 39
	c0    mpyl $r0.12 = $r0.12, -48   ## [spec] bblock 40, line 298-3,  t318,  t278,  -48(SI32)
;;								## 40
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 40, line 299-3,  t316(SI24),  t317,  8(SI32)
;;								## 41
	c0    add $r0.12 = $r0.12, $r0.13   ## [spec] bblock 40, line 301-3,  t743,  t318,  t316(SI24)
;;								## 42
	c0    add $r0.4 = $r0.15, $r0.12   ## [spec] bblock 40, line 301-3,  t214,  t742,  t743
;;								## 43
	c0    ldbu.d $r0.3 = 0[$r0.8]   ## [spec] bblock 40, line 303-3, t218, t437
;;								## 44
	c0    mov $r0.2 = $r0.14   ## [spec] bblock 40, line 301-2,  t213,  t371
;;								## 45
	c0    mov $r0.5 = $r0.10   ## [spec] bblock 40, line 303-2,  t217,  t290
;;								## 46
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 40, line 296-3,  t247,  t247,  -4(SI32)
;;								## 47
	c0    add $r0.8 = $r0.8, (~0x3)   ## [spec] bblock 40, line 0,  t437,  t437,  (~0x3)(I32)
;;								## 48
	c0    stw 12[$r0.7] = $r0.9   ## bblock 21, line 301, t436, t266
;;								## 49
	c0    brf $b0.0, L85?3   ## bblock 21, line 296-1,  t730(I1)
;;								## 50
	c0    stw 8[$r0.7] = $r0.11   ## bblock 46, line 301-1, t436, t280
;;								## 51
	c0    brf $b0.1, L86?3   ## bblock 46, line 296-2,  t749(I1)
;;								## 52
	c0    stw 4[$r0.7] = $r0.14   ## bblock 43, line 301-2, t436, t371
;;								## 53
	c0    brf $b0.2, L87?3   ## bblock 43, line 296-3,  t746(I1)
;;								## 54
	c0    stw 0[$r0.7] = $r0.4   ## bblock 40, line 301-3, t436, t214
;;								## 55
	c0    add $r0.7 = $r0.7, (~0xf)   ## bblock 40, line 0,  t436,  t436,  (~0xf)(I32)
	      ## goto
;;
	c0    goto L83?3 ## goto
;;								## 56
.trace 24
L87?3:
	c0    sub $r0.3 = 2, $r0.19   ## bblock 17, line 0,  t387,  2(I32),  t191
	      ## goto
;;
	c0    goto L88?3 ## goto
;;								## 0
.trace 4
L89?3:
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 20, line 309, t308, t382
;;								## 0
	c0    mpyl $r0.11 = $r0.4, 215   ## [spec] bblock 20, line 311,  t373,  t220,  215(SI32)
;;								## 1
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 20, line 312,  t306,  t219,  -155(SI32)
;;								## 2
	c0    mpyl $r0.12 = $r0.3, -48   ## [spec] bblock 20, line 309,  t374,  t308,  -48(SI32)
;;								## 3
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 20, line 311,  t307(SI24),  t373,  8(SI32)
;;								## 4
	c0    add $r0.12 = $r0.12, $r0.11   ## [spec] bblock 20, line 313,  t726,  t374,  t307(SI24)
;;								## 5
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 20, line 312,  t305(SI24),  t306,  8(SI32)
;;								## 6
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 20, line 310,  t269,  t222,  28(SI32)
;;								## 7
	c0    ldw.d $r0.11 = 0[$r0.7]   ## [spec] bblock 20, line 317, t302, t385
;;								## 8
	c0    add $r0.6 = $r0.6, $r0.5   ## [spec] bblock 20, line 313,  t725,  t269,  t305(SI24)
;;								## 9
	c0    add $r0.6 = $r0.6, $r0.12   ## [spec] bblock 20, line 313,  t303,  t725,  t726
;;								## 10
	c0    add $r0.11 = $r0.6, $r0.11   ## [spec] bblock 20, line 317,  t301,  t303,  t302
;;								## 11
	c0    shl $r0.11 = $r0.11, 8   ## [spec] bblock 20, line 317,  t300,  t301,  8(I32)
;;								## 12
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 20, line 317,  t299(SI24),  t300,  8(SI32)
;;								## 13
	c0    cmplt $b0.0 = $r0.8, 2   ## bblock 18, line 307,  t724(I1),  t386,  2(SI32)
;;								## 14
	c0    cmplt $b0.1 = $r0.8, 1   ## [spec] bblock 20, line 307-1,  t727(I1),  t386,  1(SI32)
;;								## 15
	c0    brf $b0.0, L90?3   ## bblock 18, line 307,  t724(I1)
;;								## 16
	c0    ldbu.d $r0.12 = 1[$r0.2]   ## [spec] bblock 53, line 309-1, t262, t382
;;								## 17
	c0    mpyl $r0.13 = $r0.6, 215   ## [spec] bblock 53, line 311-1,  t54,  t303,  215(SI32)
;;								## 18
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 53, line 312-1,  t58,  t220,  -155(SI32)
;;								## 19
	c0    mpyl $r0.14 = $r0.12, -48   ## [spec] bblock 53, line 309-1,  t261,  t262,  -48(SI32)
;;								## 20
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 53, line 311-1,  t61(SI24),  t54,  8(SI32)
;;								## 21
	c0    add $r0.14 = $r0.14, $r0.13   ## [spec] bblock 53, line 313-1,  t753,  t261,  t61(SI24)
;;								## 22
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 53, line 312-1,  t60(SI24),  t58,  8(SI32)
;;								## 23
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 53, line 310-1,  t62,  t308,  28(SI32)
;;								## 24
	c0    ldw.d $r0.13 = 4[$r0.7]   ## [spec] bblock 53, line 317-1, t77, t385
;;								## 25
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 53, line 313-1,  t752,  t62,  t60(SI24)
;;								## 26
	c0    add $r0.3 = $r0.3, $r0.14   ## [spec] bblock 53, line 313-1,  t259,  t752,  t753
;;								## 27
	c0    add $r0.13 = $r0.3, $r0.13   ## [spec] bblock 53, line 317-1,  t81,  t259,  t77
;;								## 28
	c0    shl $r0.13 = $r0.13, 8   ## [spec] bblock 53, line 317-1,  t83,  t81,  8(I32)
;;								## 29
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 53, line 317-1,  t84(SI24),  t83,  8(SI32)
;;								## 30
	c0    cmplt $b0.0 = $r0.8, $r0.0   ## [spec] bblock 53, line 307-2,  t754(I1),  t386,  0(SI32)
;;								## 31
	c0    ldbu.d $r0.14 = 2[$r0.2]   ## [spec] bblock 50, line 309-2, t222, t382
;;								## 32
	c0    mpyl $r0.15 = $r0.3, 215   ## [spec] bblock 50, line 311-2,  t274,  t259,  215(SI32)
;;								## 33
	c0    mpyl $r0.16 = $r0.6, -155   ## [spec] bblock 50, line 312-2,  t272,  t303,  -155(SI32)
;;								## 34
	c0    mpyl $r0.17 = $r0.14, -48   ## [spec] bblock 50, line 309-2,  t63,  t222,  -48(SI32)
;;								## 35
	c0    shr $r0.15 = $r0.15, 8   ## [spec] bblock 50, line 311-2,  t273(SI24),  t274,  8(SI32)
;;								## 36
	c0    add $r0.17 = $r0.17, $r0.15   ## [spec] bblock 50, line 313-2,  t751,  t63,  t273(SI24)
;;								## 37
	c0    shr $r0.16 = $r0.16, 8   ## [spec] bblock 50, line 312-2,  t370(SI24),  t272,  8(SI32)
;;								## 38
	c0    mpyl $r0.12 = $r0.12, 28   ## [spec] bblock 50, line 310-2,  t275,  t262,  28(SI32)
;;								## 39
	c0    ldw.d $r0.15 = 8[$r0.7]   ## [spec] bblock 50, line 317-2, t271, t385
;;								## 40
	c0    add $r0.12 = $r0.12, $r0.16   ## [spec] bblock 50, line 313-2,  t750,  t275,  t370(SI24)
;;								## 41
	c0    add $r0.4 = $r0.12, $r0.17   ## [spec] bblock 50, line 313-2,  t220,  t750,  t751
;;								## 42
	c0    add $r0.15 = $r0.4, $r0.15   ## [spec] bblock 50, line 317-2,  t268,  t220,  t271
;;								## 43
	c0    shl $r0.15 = $r0.15, 8   ## [spec] bblock 50, line 317-2,  t267,  t268,  8(I32)
;;								## 44
	c0    shr $r0.15 = $r0.15, 8   ## [spec] bblock 50, line 317-2,  t263(SI24),  t267,  8(SI32)
;;								## 45
	c0    mov $r0.5 = $r0.3   ## [spec] bblock 50, line 313-1,  t219,  t259
;;								## 46
	c0    add $r0.2 = $r0.2, 3   ## [spec] bblock 50, line 0,  t382,  t382,  3(I32)
;;								## 47
	c0    add $r0.7 = $r0.7, 12   ## [spec] bblock 50, line 0,  t385,  t385,  12(I32)
;;								## 48
	c0    add $r0.8 = $r0.8, 3   ## [spec] bblock 50, line 0,  t386,  t386,  3(I32)
;;								## 49
	c0    stw 0[$r0.10] = $r0.6   ## bblock 20, line 313, t384, t303
;;								## 50
	c0    mov $r0.6 = $r0.14   ## [spec] t222
;;								## 51
	c0    stw 0[$r0.9] = $r0.11   ## bblock 20, line 317, t383, t299(SI24)
;;								## 52
	c0    brf $b0.1, L90?3   ## bblock 20, line 307-1,  t727(I1)
;;								## 53
	c0    stw 4[$r0.10] = $r0.3   ## bblock 53, line 313-1, t384, t259
;;								## 54
	c0    stw 4[$r0.9] = $r0.13   ## bblock 53, line 317-1, t383, t84(SI24)
;;								## 55
	c0    brf $b0.0, L90?3   ## bblock 53, line 307-2,  t754(I1)
;;								## 56
	c0    stw 8[$r0.10] = $r0.4   ## bblock 50, line 313-2, t384, t220
;;								## 57
	c0    add $r0.10 = $r0.10, 12   ## bblock 50, line 0,  t384,  t384,  12(I32)
;;								## 58
	c0    stw 8[$r0.9] = $r0.15   ## bblock 50, line 317-2, t383, t263(SI24)
;;								## 59
	c0    add $r0.9 = $r0.9, 12   ## bblock 50, line 0,  t383,  t383,  12(I32)
	      ## goto
;;
	c0    goto L89?3 ## goto
;;								## 60
.trace 16
L90?3:
	c0    add $r0.24 = $r0.24, 1050   ## bblock 19, line 0,  t649,  t649,  1050(I32)
;;								## 0
	c0    add $r0.23 = $r0.23, 4200   ## bblock 19, line 0,  t651,  t651,  4200(I32)
;;								## 1
	c0    add $r0.10 = $r0.19, 1050   ## bblock 19, line 0,  t655,  t655,  1050(I32)
;;								## 2
	c0    add $r0.9 = $r0.20, 1   ## bblock 19, line 0,  t656,  t656,  1(I32)
;;								## 3
	c0    mov $r0.13 = $r0.21   ## t191
;;								## 4
	c0    mov $r0.11 = $r0.18   ## t255
	      ## goto
;;
	c0    goto L81?3 ## goto
;;								## 5
.trace 23
L86?3:
	c0    sub $r0.3 = 2, $r0.19   ## bblock 17, line 0,  t387,  2(I32),  t191
	      ## goto
;;
	c0    goto L88?3 ## goto
;;								## 0
.trace 21
L85?3:
	c0    sub $r0.3 = 2, $r0.19   ## bblock 17, line 0,  t387,  2(I32),  t191
	      ## goto
;;
	c0    goto L88?3 ## goto
;;								## 0
.trace 14
L84?3:
	c0    sub $r0.3 = 2, $r0.19   ## bblock 17, line 0,  t387,  2(I32),  t191
;;								## 0
L88?3:
	c0    mov $r0.8 = $r0.3   ## bblock 17, line 0,  t386,  t387
;;								## 1
	c0    mov $r0.9 = $r0.23   ## bblock 17, line 0,  t383,  t651
;;								## 2
	c0    mov $r0.7 = (ay2 + 0)   ## bblock 17, line 0,  t385,  addr(ay2?1.0)(P32)
;;								## 3
	c0    mov $r0.10 = (ay1 + 0)   ## bblock 17, line 0,  t384,  addr(ay1?1.0)(P32)
;;								## 4
	c0    mov $r0.2 = $r0.24   ## bblock 17, line 0,  t382,  t649
;;								## 5
	c0    mov $r0.6 = $r0.20   ## t222
;;								## 6
	c0    mov $r0.4 = $r0.21   ## t220
;;								## 7
	c0    mov $r0.5 = $r0.22   ## t219
;;								## 8
	c0    mov $r0.20 = $r0.16   ## t656
;;								## 9
	c0    mov $r0.21 = $r0.19   ## t191
;;								## 10
	c0    mov $r0.19 = $r0.17   ## t655
	      ## goto
;;
	c0    goto L89?3 ## goto
;;								## 11
.trace 26
L82?3:
	c0    sub $r0.13 = $r0.0, $r0.13   ## bblock 2, line 0,  t614,  0(I32),  t191
;;								## 0
	c0    mov $r0.9 = $r0.13   ## bblock 2, line 0,  t613,  t614
;;								## 1
	c0    mov $r0.23 = (at + 0)   ## bblock 2, line 0,  t607,  addr(at?1.0)(P32)
;;								## 2
	c0    mov $r0.22 = (out + 0)   ## bblock 2, line 0,  t608,  addr(out?1.0)(P32)
;;								## 3
	c0    mov $r0.11 = ((at + 0) + (~0x3137))   ## bblock 2, line 0,  t612,  (addr(at?1.0)(P32) + 0xffffcec8(I32))(P32)
;;								## 4
	c0    add $r0.10 = $r0.25, -1   ## bblock 2, line 323,  t256,  t190,  -1(SI32)
;;								## 5
	c0    mov $r0.12 = $r0.25   ## t190
;;								## 6
.trace 11
L91?3:
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 3, line 321,  t713(I1),  t613,  0(SI32)
;;								## 0
	c0    mpylu $r0.13 = $r0.10, 4200   ## [spec] bblock 5, line 0,  t545,  t256,  4200(I32)
;;								## 1
	c0    brf $b0.0, L92?3   ## bblock 3, line 321,  t713(I1)
;;								## 2
	c0    add $r0.8 = $r0.11, $r0.13   ## bblock 5, line 0,  t542,  t612,  t545
;;								## 3
	c0    sh2add $r0.7 = $r0.12, (((ay2 + 0) + (~0xb)) + (~0x3))   ## bblock 5, line 0,  t541,  t190,  ((addr(ay2?1.0)(P32) + 0xfffffff4(I32))(P32) + 0xfffffffc(I32))(P32)
;;								## 4
	c0    mov $r0.3 = $r0.0   ## bblock 5, line 322,  t310,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 5, line 322,  t215,  0(SI32)
;;								## 6
	c0    mov $r0.4 = $r0.0   ## bblock 5, line 322,  t250(SI24),  0(SI32)
;;								## 7
	c0    mov $r0.2 = $r0.0   ## bblock 5, line 322,  t311,  0(SI32)
;;								## 8
	c0    mov $r0.19 = $r0.0   ## bblock 5, line 322,  t253(SI24),  0(SI32)
;;								## 9
	c0    mov $r0.20 = $r0.0   ## bblock 5, line 322,  t251,  0(SI32)
;;								## 10
	c0    mov $r0.21 = $r0.0   ## bblock 5, line 322,  t221,  0(SI32)
;;								## 11
	c0    mov $r0.6 = $r0.10   ## bblock 5, line 323,  t252,  t256
;;								## 12
	c0    mov $r0.15 = $r0.9   ## t613
;;								## 13
	c0    mov $r0.16 = $r0.10   ## t256
;;								## 14
	c0    mov $r0.17 = $r0.11   ## t612
;;								## 15
	c0    mov $r0.18 = $r0.12   ## t190
;;								## 16
.trace 1
L93?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 14, line 324,  t323,  t311,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 14, line 324,  t108,  t310,  -47(SI32)
;;								## 1
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 14, line 324,  t313,  t250(SI24),  215(SI32)
;;								## 2
	c0    add $r0.2 = $r0.2, $r0.9   ## [spec] bblock 14, line 324,  t720,  t323,  t108
;;								## 3
	c0    mpyl $r0.5 = $r0.5, 29   ## [spec] bblock 14, line 324,  t105,  t215,  29(SI32)
;;								## 4
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 6, line 323,  t714(I1),  t252,  0(SI32)
;;								## 5
	c0    add $r0.10 = $r0.10, $r0.5   ## [spec] bblock 14, line 324,  t721,  t313,  t105
;;								## 6
	c0    add $r0.2 = $r0.2, $r0.10   ## [spec] bblock 14, line 324,  t109,  t720,  t721
;;								## 7
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 14, line 324,  t708,  t109,  8(SI32)
;;								## 8
	c0    brf $b0.0, L94?3   ## bblock 6, line 323,  t714(I1)
;;								## 9
	c0    ldw $r0.9 = 12600[$r0.8]   ## bblock 14, line 326, t369, t542
;;								## 10
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 14, line 323-1,  t722(I1),  t252,  1(SI32)
;;								## 11
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 29, line 324-1,  t335,  t250(SI24),  -155(SI32)
;;								## 12
	c0    mpyl $r0.10 = $r0.9, -47   ## [spec] bblock 29, line 324-1,  t330,  t369,  -47(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.2, 215   ## [spec] bblock 29, line 324-1,  t333,  t708,  215(SI32)
;;								## 14
	c0    add $r0.4 = $r0.4, $r0.10   ## [spec] bblock 29, line 324-1,  t736,  t335,  t330
;;								## 15
	c0    mpyl $r0.3 = $r0.3, 29   ## [spec] bblock 29, line 324-1,  t332,  t310,  29(SI32)
;;								## 16
	c0    ldw.d $r0.10 = 8400[$r0.8]   ## [spec] bblock 29, line 326-1, t216, t542
;;								## 17
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 29, line 324-1,  t737,  t333,  t332
;;								## 18
	c0    add $r0.4 = $r0.4, $r0.11   ## [spec] bblock 29, line 324-1,  t329,  t736,  t737
;;								## 19
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 29, line 324-1,  t709,  t329,  8(SI32)
;;								## 20
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 29, line 323-2,  t738(I1),  t252,  2(SI32)
;;								## 21
	c0    mpyl $r0.11 = $r0.2, -155   ## [spec] bblock 26, line 324-2,  t99,  t708,  -155(SI32)
;;								## 22
	c0    mpyl $r0.12 = $r0.10, -47   ## [spec] bblock 26, line 324-2,  t341,  t216,  -47(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.4, 215   ## [spec] bblock 26, line 324-2,  t102,  t709,  215(SI32)
;;								## 24
	c0    add $r0.11 = $r0.11, $r0.12   ## [spec] bblock 26, line 324-2,  t733,  t99,  t341
;;								## 25
	c0    mpyl $r0.9 = $r0.9, 29   ## [spec] bblock 26, line 324-2,  t343,  t369,  29(SI32)
;;								## 26
	c0    ldw.d $r0.12 = 4200[$r0.8]   ## [spec] bblock 26, line 326-2, t336, t542
;;								## 27
	c0    add $r0.13 = $r0.13, $r0.9   ## [spec] bblock 26, line 324-2,  t734,  t102,  t343
;;								## 28
	c0    add $r0.11 = $r0.11, $r0.13   ## [spec] bblock 26, line 324-2,  t340,  t733,  t734
;;								## 29
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 26, line 324-2,  t710,  t340,  8(SI32)
;;								## 30
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 26, line 323-3,  t735(I1),  t252,  3(SI32)
;;								## 31
	c0    mpyl $r0.9 = $r0.4, -155   ## [spec] bblock 23, line 324-3,  t359,  t709,  -155(SI32)
;;								## 32
	c0    mpyl $r0.13 = $r0.12, -47   ## [spec] bblock 23, line 324-3,  t345,  t336,  -47(SI32)
;;								## 33
	c0    mpyl $r0.14 = $r0.11, 215   ## [spec] bblock 23, line 324-3,  t358,  t710,  215(SI32)
;;								## 34
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 23, line 324-3,  t731,  t359,  t345
;;								## 35
	c0    mpyl $r0.10 = $r0.10, 29   ## [spec] bblock 23, line 324-3,  t357,  t216,  29(SI32)
;;								## 36
	c0    ldw.d $r0.3 = 0[$r0.8]   ## [spec] bblock 23, line 326-3, t310, t542
;;								## 37
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 23, line 324-3,  t732,  t358,  t357
;;								## 38
	c0    add $r0.9 = $r0.9, $r0.14   ## [spec] bblock 23, line 324-3,  t344,  t731,  t732
;;								## 39
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 23, line 324-3,  t250(SI24),  t344,  8(SI32)
;;								## 40
	c0    mov $r0.5 = $r0.12   ## [spec] bblock 23, line 326-2,  t215,  t336
;;								## 41
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 23, line 323-3,  t252,  t252,  -4(SI32)
;;								## 42
	c0    stw 12[$r0.7] = $r0.2   ## bblock 14, line 324, t541, t708
;;								## 43
	c0    brf $b0.0, L94?3   ## bblock 14, line 323-1,  t722(I1)
;;								## 44
	c0    mov $r0.2 = $r0.11   ## [spec] bblock 23, line 324-2,  t311,  t710
;;								## 45
	c0    add $r0.8 = $r0.8, (~0x419f)   ## [spec] bblock 23, line 0,  t542,  t542,  (~0x419f)(I32)
;;								## 46
	c0    stw 8[$r0.7] = $r0.4   ## bblock 29, line 324-1, t541, t709
;;								## 47
	c0    brf $b0.1, L94?3   ## bblock 29, line 323-2,  t738(I1)
;;								## 48
	c0    mov $r0.4 = $r0.9   ## [spec] t250(SI24)
;;								## 49
	c0    stw 4[$r0.7] = $r0.11   ## bblock 26, line 324-2, t541, t710
;;								## 50
	c0    brf $b0.2, L94?3   ## bblock 26, line 323-3,  t735(I1)
;;								## 51
	c0    stw 0[$r0.7] = $r0.9   ## bblock 23, line 324-3, t541, t250(SI24)
;;								## 52
	c0    add $r0.7 = $r0.7, (~0xf)   ## bblock 23, line 0,  t541,  t541,  (~0xf)(I32)
	      ## goto
;;
	c0    goto L93?3 ## goto
;;								## 53
.trace 13
L94?3:
	c0    sub $r0.3 = 1, $r0.18   ## bblock 7, line 0,  t481,  1(I32),  t190
;;								## 0
	c0    mov $r0.8 = $r0.3   ## bblock 7, line 0,  t480,  t481
;;								## 1
	c0    mov $r0.9 = $r0.22   ## bblock 7, line 0,  t479,  t608
;;								## 2
	c0    mov $r0.7 = (ay2 + 0)   ## bblock 7, line 0,  t478,  addr(ay2?1.0)(P32)
;;								## 3
	c0    mov $r0.10 = (ay1 + 0)   ## bblock 7, line 0,  t477,  addr(ay1?1.0)(P32)
;;								## 4
	c0    mov $r0.2 = $r0.23   ## bblock 7, line 0,  t476,  t607
;;								## 5
	c0    mov $r0.4 = $r0.20   ## t251
;;								## 6
	c0    mov $r0.5 = $r0.19   ## t253(SI24)
;;								## 7
	c0    mov $r0.6 = $r0.21   ## t221
;;								## 8
	c0    mov $r0.19 = $r0.18   ## t190
;;								## 9
	c0    mov $r0.18 = $r0.15   ## t613
;;								## 10
.trace 3
L95?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 10, line 331, t352, t476
;;								## 0
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 10, line 331,  t356,  t251,  -155(SI32)
;;								## 1
	c0    mpyl $r0.11 = $r0.5, 215   ## [spec] bblock 10, line 331,  t366,  t253(SI24),  215(SI32)
;;								## 2
	c0    mpyl $r0.12 = $r0.3, -48   ## [spec] bblock 10, line 331,  t351,  t352,  -48(SI32)
;;								## 3
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 10, line 331,  t365,  t221,  28(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.12   ## [spec] bblock 10, line 331,  t716,  t356,  t351
;;								## 5
	c0    add $r0.11 = $r0.11, $r0.6   ## [spec] bblock 10, line 331,  t717,  t366,  t365
;;								## 6
	c0    add $r0.4 = $r0.4, $r0.11   ## [spec] bblock 10, line 331,  t364,  t716,  t717
;;								## 7
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 10, line 331,  t363(SI24),  t364,  8(SI32)
;;								## 8
	c0    ldw.d $r0.11 = 0[$r0.7]   ## [spec] bblock 10, line 335, t350, t478
;;								## 9
	c0    cmplt $b0.0 = $r0.8, 1   ## bblock 8, line 330,  t715(I1),  t480,  1(SI32)
;;								## 10
	c0    cmplt $b0.1 = $r0.8, $r0.0   ## [spec] bblock 12, line 330-1,  t719(I1),  t480,  0(SI32)
;;								## 11
	c0    add $r0.11 = $r0.4, $r0.11   ## [spec] bblock 10, line 335,  t349,  t363(SI24),  t350
;;								## 12
	c0    shl $r0.11 = $r0.11, 8   ## [spec] bblock 10, line 335,  t348,  t349,  8(I32)
;;								## 13
	c0    shr $r0.11 = $r0.11, 16   ## [spec] bblock 10, line 335,  t347(SI16),  t348,  16(SI32)
;;								## 14
	c0    brf $b0.0, L96?3   ## bblock 8, line 330,  t715(I1)
;;								## 15
	c0    zxtb $r0.12 = $r0.11   ## bblock 10, line 335,  t346(I8),  t347(SI16)
;;								## 16
	c0    cmpgt $b0.0 = $r0.12, 25   ## bblock 10, line 336,  t718(I1),  t346(I8),  25(SI32)
;;								## 17
	c0    ldw.d $r0.6 = 4200[$r0.2]   ## [spec] bblock 33, line 331-1, t221, t476
;;								## 18
	c0    mpyl $r0.12 = $r0.5, -155   ## [spec] bblock 33, line 331-1,  t128,  t253(SI24),  -155(SI32)
;;								## 19
	c0    mpyl $r0.13 = $r0.4, 215   ## [spec] bblock 33, line 331-1,  t131,  t363(SI24),  215(SI32)
;;								## 20
	c0    mpyl $r0.14 = $r0.6, -48   ## [spec] bblock 33, line 331-1,  t140,  t221,  -48(SI32)
;;								## 21
	c0    mpyl $r0.15 = $r0.3, 28   ## [spec] bblock 33, line 331-1,  t134,  t352,  28(SI32)
;;								## 22
	c0    add $r0.12 = $r0.12, $r0.14   ## [spec] bblock 33, line 331-1,  t739,  t128,  t140
;;								## 23
	c0    add $r0.13 = $r0.13, $r0.15   ## [spec] bblock 33, line 331-1,  t740,  t131,  t134
;;								## 24
	c0    add $r0.12 = $r0.12, $r0.13   ## [spec] bblock 33, line 331-1,  t141,  t739,  t740
;;								## 25
	c0    ldw.d $r0.13 = 4[$r0.7]   ## [spec] bblock 33, line 335-1, t155, t478
;;								## 26
	c0    mov $r0.14 = $r0.4   ## [spec] bblock 33, line 331-1,  t251,  t363(SI24)
;;								## 27
	c0    stb 0[$r0.9] = $r0.11   ## bblock 10, line 335, t479, t347(SI16)
;;								## 28
	c0    stw 0[$r0.10] = $r0.4   ## bblock 10, line 331, t477, t363(SI24)
;;								## 29
	c0    brf $b0.0, L97?3   ## bblock 10, line 336,  t718(I1)
;;								## 30
	c0    shr $r0.5 = $r0.12, 8   ## [spec] bblock 33, line 331-1,  t253(SI24),  t141,  8(SI32)
;;								## 31
	c0    add $r0.13 = $r0.5, $r0.13   ## [spec] bblock 33, line 335-1,  t159,  t253(SI24),  t155
;;								## 32
	c0    shl $r0.13 = $r0.13, 8   ## [spec] bblock 33, line 335-1,  t161,  t159,  8(I32)
;;								## 33
	c0    shr $r0.13 = $r0.13, 16   ## [spec] bblock 33, line 335-1,  t162(SI16),  t161,  16(SI32)
;;								## 34
	c0    zxtb $r0.3 = $r0.13   ## [spec] bblock 33, line 335-1,  t170(I8),  t162(SI16)
;;								## 35
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 33, line 336-1,  t741(I1),  t170(I8),  25(SI32)
;;								## 36
	c0    mov $r0.4 = $r0.14   ## [spec] t251
;;								## 37
	c0    stb 0[$r0.9] = $r0.0   ## bblock 13, line 337, t479, 0(I32)
;;								## 38
L98?3:
	c0    brf $b0.1, L96?3   ## bblock 12, line 330-1,  t719(I1)
;;								## 39
	c0    stw 4[$r0.10] = $r0.5   ## bblock 33, line 331-1, t477, t253(SI24)
;;								## 40
	c0    stb 1050[$r0.9] = $r0.13   ## bblock 33, line 335-1, t479, t162(SI16)
;;								## 41
	c0    brf $b0.0, L99?3   ## bblock 33, line 336-1,  t741(I1)
;;								## 42
	c0    add $r0.2 = $r0.2, 8400   ## bblock 35, line 0,  t476,  t476,  8400(I32)
;;								## 43
	c0    add $r0.10 = $r0.10, 8   ## bblock 35, line 0,  t477,  t477,  8(I32)
;;								## 44
	c0    add $r0.7 = $r0.7, 8   ## bblock 35, line 0,  t478,  t478,  8(I32)
;;								## 45
	c0    add $r0.8 = $r0.8, 2   ## bblock 35, line 0,  t480,  t480,  2(I32)
;;								## 46
	c0    stb 1050[$r0.9] = $r0.0   ## bblock 36, line 337-1, t479, 0(I32)
;;								## 47
L100?3:
	c0    add $r0.9 = $r0.9, 2100   ## bblock 35, line 0,  t479,  t479,  2100(I32)
	      ## goto
;;
	c0    goto L95?3 ## goto
;;								## 48
.trace 10
L99?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.8 = $r0.8, 2   ## bblock 35, line 0,  t480,  t480,  2(I32)
;;								## 1
	c0    add $r0.7 = $r0.7, 8   ## bblock 35, line 0,  t478,  t478,  8(I32)
;;								## 2
	c0    add $r0.10 = $r0.10, 8   ## bblock 35, line 0,  t477,  t477,  8(I32)
;;								## 3
	c0    add $r0.2 = $r0.2, 8400   ## bblock 35, line 0,  t476,  t476,  8400(I32)
;;								## 4
	c0    stb 1050[$r0.9] = $r0.3   ## bblock 34, line 339-1, t479, 255(I32)
	      ## goto
;;
	c0    goto L100?3 ## goto
;;								## 5
.trace 15
L96?3:
	c0    add $r0.23 = $r0.23, 4   ## bblock 9, line 0,  t607,  t607,  4(I32)
;;								## 0
	c0    add $r0.22 = $r0.22, 1   ## bblock 9, line 0,  t608,  t608,  1(I32)
;;								## 1
	c0    add $r0.11 = $r0.17, 4   ## bblock 9, line 0,  t612,  t612,  4(I32)
;;								## 2
	c0    add $r0.9 = $r0.18, 1   ## bblock 9, line 0,  t613,  t613,  1(I32)
;;								## 3
	c0    mov $r0.10 = $r0.16   ## t256
;;								## 4
	c0    mov $r0.12 = $r0.19   ## t190
	      ## goto
;;
	c0    goto L91?3 ## goto
;;								## 5
.trace 9
L97?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    shr $r0.5 = $r0.12, 8   ## [spec] bblock 33, line 331-1,  t253(SI24),  t141,  8(SI32)
;;								## 1
	c0    add $r0.13 = $r0.5, $r0.13   ## [spec] bblock 33, line 335-1,  t159,  t253(SI24),  t155
;;								## 2
	c0    shl $r0.13 = $r0.13, 8   ## [spec] bblock 33, line 335-1,  t161,  t159,  8(I32)
;;								## 3
	c0    shr $r0.13 = $r0.13, 16   ## [spec] bblock 33, line 335-1,  t162(SI16),  t161,  16(SI32)
;;								## 4
	c0    zxtb $r0.11 = $r0.13   ## [spec] bblock 33, line 335-1,  t170(I8),  t162(SI16)
;;								## 5
	c0    cmpgt $b0.0 = $r0.11, 25   ## [spec] bblock 33, line 336-1,  t741(I1),  t170(I8),  25(SI32)
;;								## 6
	c0    mov $r0.4 = $r0.14   ## t251
;;								## 7
	c0    stb 0[$r0.9] = $r0.3   ## bblock 11, line 339, t479, 255(I32)
	      ## goto
;;
	c0    goto L98?3 ## goto
;;								## 8
.trace 28
L92?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 4, line 343,  t178,  ?2.4?2auto_size(I32),  t177
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.4?2auto_size, 0x0
 ## End deriche_array
 ## Begin deriche_short
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_short::
.trace 25
	      ## auto_size == 0
;;								## 0
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t609,  0(I32),  t203
;;								## 1
	c0    mov $r0.9 = $r0.2   ## bblock 0, line 0,  t608,  t609
;;								## 2
	c0    mov $r0.24 = (in + 0)   ## bblock 0, line 0,  t602,  addr(in?1.0)(P32)
;;								## 3
	c0    mov $r0.23 = (s_at + 0)   ## bblock 0, line 0,  t604,  addr(s_at?1.0)(P32)
;;								## 4
	c0    add $r0.11 = $r0.4, -1   ## bblock 0, line 368,  t268,  t204,  -1(SI32)
;;								## 5
	c0    mov $r0.10 = ((in + 0) + (~0x1))   ## bblock 0, line 0,  t607,  (addr(in?1.0)(P32) + 0xfffffffe(I32))(P32)
;;								## 6
	c0    mov $r0.25 = $r0.3   ## t203
;;								## 7
	c0    mov $r0.12 = $r0.4   ## t204
;;								## 8
.trace 11
L101?3:
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 1, line 366,  t651(I1),  t608,  0(SI32)
;;								## 0
	c0    add $r0.8 = $r0.10, $r0.11   ## [spec] bblock 15, line 0,  t419,  t607,  t268
;;								## 1
	c0    brf $b0.0, L102?3   ## bblock 1, line 366,  t651(I1)
;;								## 2
	c0    sh1add $r0.7 = $r0.12, (((s_ay2 + 0) + (~0x3)) + (~0x1))   ## bblock 15, line 0,  t418,  t204,  ((addr(s_ay2?1.0)(P32) + 0xfffffffc(I32))(P32) + 0xfffffffe(I32))(P32)
;;								## 3
	c0    mov $r0.2 = $r0.0   ## bblock 15, line 367,  t226(SI16),  0(SI32)
;;								## 4
	c0    mov $r0.4 = $r0.0   ## bblock 15, line 367,  t227(SI16),  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 15, line 367,  t270(SI16),  0(SI32)
;;								## 6
	c0    mov $r0.3 = $r0.0   ## bblock 15, line 367,  t231(SI16),  0(SI32)
;;								## 7
	c0    mov $r0.20 = $r0.0   ## bblock 15, line 367,  t235(SI16),  0(SI32)
;;								## 8
	c0    mov $r0.21 = $r0.0   ## bblock 15, line 367,  t233(SI16),  0(SI32)
;;								## 9
	c0    mov $r0.22 = $r0.0   ## bblock 15, line 367,  t232(SI16),  0(SI32)
;;								## 10
	c0    mov $r0.6 = $r0.11   ## bblock 15, line 368,  t309,  t268
;;								## 11
	c0    mov $r0.16 = $r0.9   ## t608
;;								## 12
	c0    mov $r0.17 = $r0.10   ## t607
;;								## 13
	c0    mov $r0.18 = $r0.11   ## t268
;;								## 14
	c0    mov $r0.19 = $r0.12   ## t204
;;								## 15
.trace 2
L103?3:
	c0    mpyl $r0.2 = $r0.2, -77   ## [spec] bblock 21, line 372,  t24,  t226(SI16),  -77(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -23   ## [spec] bblock 21, line 369,  t11,  t231(SI16),  -23(SI32)
;;								## 1
	c0    shr $r0.2 = $r0.2, 7   ## [spec] bblock 21, line 372,  t25(SI25),  t24,  7(SI32)
;;								## 2
	c0    sxth $r0.2 = $r0.2   ## [spec] bblock 21, line 372,  t27(SI16),  t25(SI25)
;;								## 3
	c0    sxth $r0.9 = $r0.9   ## [spec] bblock 21, line 369,  t30(SI16),  t11
;;								## 4
	c0    add $r0.9 = $r0.9, $r0.2   ## [spec] bblock 21, line 373,  t667,  t30(SI16),  t27(SI16)
;;								## 5
	c0    mpyl $r0.10 = $r0.4, 107   ## [spec] bblock 21, line 371,  t19,  t227(SI16),  107(SI32)
;;								## 6
	c0    mpyl $r0.5 = $r0.5, -24   ## [spec] bblock 21, line 370,  t15,  t270(SI16),  -24(SI32)
;;								## 7
	c0    shr $r0.10 = $r0.10, 7   ## [spec] bblock 21, line 371,  t20(SI25),  t19,  7(SI32)
;;								## 8
	c0    sxth $r0.10 = $r0.10   ## [spec] bblock 21, line 371,  t28(SI16),  t20(SI25)
;;								## 9
	c0    sxth $r0.5 = $r0.5   ## [spec] bblock 21, line 370,  t273(SI16),  t15
;;								## 10
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 21, line 373,  t668,  t273(SI16),  t28(SI16)
;;								## 11
	c0    add $r0.9 = $r0.9, $r0.5   ## [spec] bblock 21, line 373,  t369,  t667,  t668
;;								## 12
	c0    sxth $r0.10 = $r0.9   ## [spec] bblock 21, line 373,  t272(SI16),  t369
;;								## 13
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 16, line 368,  t662(I1),  t309,  0(SI32)
;;								## 14
	c0    ldbu.d $r0.11 = 2[$r0.8]   ## [spec] bblock 21, line 375, t271(SI16), t419
;;								## 15
	c0    brf $b0.0, L104?3   ## bblock 16, line 368,  t662(I1)
;;								## 16
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 21, line 368-1,  t669(I1),  t309,  1(SI32)
;;								## 17
	c0    mpyl $r0.4 = $r0.4, -77   ## [spec] bblock 40, line 372-1,  t283,  t227(SI16),  -77(SI32)
;;								## 18
	c0    mpyl $r0.12 = $r0.11, -23   ## [spec] bblock 40, line 369-1,  t303,  t271(SI16),  -23(SI32)
;;								## 19
	c0    shr $r0.4 = $r0.4, 7   ## [spec] bblock 40, line 372-1,  t365(SI25),  t283,  7(SI32)
;;								## 20
	c0    sxth $r0.4 = $r0.4   ## [spec] bblock 40, line 372-1,  t364(SI16),  t365(SI25)
;;								## 21
	c0    sxth $r0.12 = $r0.12   ## [spec] bblock 40, line 369-1,  t305(SI16),  t303
;;								## 22
	c0    add $r0.12 = $r0.12, $r0.4   ## [spec] bblock 40, line 373-1,  t680,  t305(SI16),  t364(SI16)
;;								## 23
	c0    mpyl $r0.13 = $r0.10, 107   ## [spec] bblock 40, line 371-1,  t284,  t272(SI16),  107(SI32)
;;								## 24
	c0    mpyl $r0.3 = $r0.3, -24   ## [spec] bblock 40, line 370-1,  t304,  t231(SI16),  -24(SI32)
;;								## 25
	c0    shr $r0.13 = $r0.13, 7   ## [spec] bblock 40, line 371-1,  t285(SI25),  t284,  7(SI32)
;;								## 26
	c0    sxth $r0.13 = $r0.13   ## [spec] bblock 40, line 371-1,  t275(SI16),  t285(SI25)
;;								## 27
	c0    sxth $r0.3 = $r0.3   ## [spec] bblock 40, line 370-1,  t29(SI16),  t304
;;								## 28
	c0    add $r0.3 = $r0.3, $r0.13   ## [spec] bblock 40, line 373-1,  t681,  t29(SI16),  t275(SI16)
;;								## 29
	c0    add $r0.12 = $r0.12, $r0.3   ## [spec] bblock 40, line 373-1,  t31,  t680,  t681
;;								## 30
	c0    sxth $r0.13 = $r0.12   ## [spec] bblock 40, line 373-1,  t281(SI16),  t31
;;								## 31
	c0    ldbu.d $r0.14 = 1[$r0.8]   ## [spec] bblock 40, line 375-1, t279(SI16), t419
;;								## 32
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 40, line 368-2,  t682(I1),  t309,  2(SI32)
;;								## 33
	c0    mpyl $r0.10 = $r0.10, -77   ## [spec] bblock 37, line 372-2,  t314,  t272(SI16),  -77(SI32)
;;								## 34
	c0    mpyl $r0.15 = $r0.14, -23   ## [spec] bblock 37, line 369-2,  t321,  t279(SI16),  -23(SI32)
;;								## 35
	c0    shr $r0.10 = $r0.10, 7   ## [spec] bblock 37, line 372-2,  t313(SI25),  t314,  7(SI32)
;;								## 36
	c0    sxth $r0.10 = $r0.10   ## [spec] bblock 37, line 372-2,  t312(SI16),  t313(SI25)
;;								## 37
	c0    sxth $r0.15 = $r0.15   ## [spec] bblock 37, line 369-2,  t320(SI16),  t321
;;								## 38
	c0    add $r0.15 = $r0.15, $r0.10   ## [spec] bblock 37, line 373-2,  t678,  t320(SI16),  t312(SI16)
;;								## 39
	c0    mpyl $r0.10 = $r0.13, 107   ## [spec] bblock 37, line 371-2,  t317,  t281(SI16),  107(SI32)
;;								## 40
	c0    mpyl $r0.11 = $r0.11, -24   ## [spec] bblock 37, line 370-2,  t319,  t271(SI16),  -24(SI32)
;;								## 41
	c0    shr $r0.10 = $r0.10, 7   ## [spec] bblock 37, line 371-2,  t316(SI25),  t317,  7(SI32)
;;								## 42
	c0    sxth $r0.10 = $r0.10   ## [spec] bblock 37, line 371-2,  t315(SI16),  t316(SI25)
;;								## 43
	c0    sxth $r0.11 = $r0.11   ## [spec] bblock 37, line 370-2,  t318(SI16),  t319
;;								## 44
	c0    add $r0.11 = $r0.11, $r0.10   ## [spec] bblock 37, line 373-2,  t679,  t318(SI16),  t315(SI16)
;;								## 45
	c0    add $r0.15 = $r0.15, $r0.11   ## [spec] bblock 37, line 373-2,  t311,  t678,  t679
;;								## 46
	c0    sxth $r0.4 = $r0.15   ## [spec] bblock 37, line 373-2,  t227(SI16),  t311
;;								## 47
	c0    ldbu.d $r0.3 = 0[$r0.8]   ## [spec] bblock 37, line 375-2, t231(SI16), t419
;;								## 48
	c0    mov $r0.2 = $r0.13   ## [spec] bblock 37, line 373-1,  t226(SI16),  t281(SI16)
;;								## 49
	c0    mov $r0.5 = $r0.14   ## [spec] bblock 37, line 375-1,  t270(SI16),  t279(SI16)
;;								## 50
	c0    add $r0.6 = $r0.6, -3   ## [spec] bblock 37, line 368-2,  t309,  t309,  -3(SI32)
;;								## 51
	c0    add $r0.8 = $r0.8, (~0x2)   ## [spec] bblock 37, line 0,  t419,  t419,  (~0x2)(I32)
;;								## 52
	c0    sth 4[$r0.7] = $r0.9   ## bblock 21, line 373, t418, t369
;;								## 53
	c0    brf $b0.0, L105?3   ## bblock 21, line 368-1,  t669(I1)
;;								## 54
	c0    sth 2[$r0.7] = $r0.12   ## bblock 40, line 373-1, t418, t31
;;								## 55
	c0    brf $b0.1, L106?3   ## bblock 40, line 368-2,  t682(I1)
;;								## 56
	c0    sth 0[$r0.7] = $r0.15   ## bblock 37, line 373-2, t418, t311
;;								## 57
	c0    add $r0.7 = $r0.7, (~0x5)   ## bblock 37, line 0,  t418,  t418,  (~0x5)(I32)
	      ## goto
;;
	c0    goto L103?3 ## goto
;;								## 58
.trace 22
L106?3:
	c0    sub $r0.3 = 1, $r0.19   ## bblock 17, line 0,  t378,  1(I32),  t204
	      ## goto
;;
	c0    goto L107?3 ## goto
;;								## 0
.trace 4
L108?3:
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 20, line 380, t367(SI16), t373
;;								## 0
	c0    mpyl $r0.11 = $r0.4, 107   ## [spec] bblock 20, line 382,  t300,  t233(SI16),  107(SI32)
;;								## 1
	c0    mpyl $r0.5 = $r0.5, -77   ## [spec] bblock 20, line 383,  t297,  t232(SI16),  -77(SI32)
;;								## 2
	c0    mpyl $r0.12 = $r0.3, -24   ## [spec] bblock 20, line 380,  t366,  t367(SI16),  -24(SI32)
;;								## 3
	c0    shr $r0.11 = $r0.11, 7   ## [spec] bblock 20, line 382,  t299(SI25),  t300,  7(SI32)
;;								## 4
	c0    sxth $r0.12 = $r0.12   ## [spec] bblock 20, line 380,  t301(SI16),  t366
;;								## 5
	c0    sxth $r0.11 = $r0.11   ## [spec] bblock 20, line 382,  t298(SI16),  t299(SI25)
;;								## 6
	c0    add $r0.12 = $r0.12, $r0.11   ## [spec] bblock 20, line 384,  t665,  t301(SI16),  t298(SI16)
;;								## 7
	c0    shr $r0.5 = $r0.5, 7   ## [spec] bblock 20, line 383,  t296(SI25),  t297,  7(SI32)
;;								## 8
	c0    sxth $r0.5 = $r0.5   ## [spec] bblock 20, line 383,  t295(SI16),  t296(SI25)
;;								## 9
	c0    mpyl $r0.6 = $r0.6, 14   ## [spec] bblock 20, line 381,  t57,  t235(SI16),  14(SI32)
;;								## 10
	c0    ldh.d $r0.11 = 0[$r0.7]   ## [spec] bblock 20, line 388, t291(SI16), t376
;;								## 11
	c0    sxth $r0.6 = $r0.6   ## [spec] bblock 20, line 381,  t302(SI16),  t57
;;								## 12
	c0    add $r0.6 = $r0.6, $r0.5   ## [spec] bblock 20, line 384,  t664,  t302(SI16),  t295(SI16)
;;								## 13
	c0    add $r0.6 = $r0.6, $r0.12   ## [spec] bblock 20, line 384,  t294,  t664,  t665
;;								## 14
	c0    sxth $r0.12 = $r0.6   ## [spec] bblock 20, line 384,  t292(SI16),  t294
;;								## 15
	c0    add $r0.11 = $r0.12, $r0.11   ## [spec] bblock 20, line 388,  t290,  t292(SI16),  t291(SI16)
;;								## 16
	c0    shl $r0.11 = $r0.11, 7   ## [spec] bblock 20, line 388,  t289,  t290,  7(I32)
;;								## 17
	c0    shr $r0.11 = $r0.11, 7   ## [spec] bblock 20, line 388,  t286(SI25),  t289,  7(SI32)
;;								## 18
	c0    cmplt $b0.0 = $r0.8, 1   ## bblock 18, line 379,  t663(I1),  t377,  1(SI32)
;;								## 19
	c0    cmplt $b0.1 = $r0.8, $r0.0   ## [spec] bblock 20, line 379-1,  t666(I1),  t377,  0(SI32)
;;								## 20
	c0    brf $b0.0, L109?3   ## bblock 18, line 379,  t663(I1)
;;								## 21
	c0    ldbu.d $r0.13 = 1[$r0.2]   ## [spec] bblock 44, line 380-1, t235(SI16), t373
;;								## 22
	c0    mpyl $r0.14 = $r0.12, 107   ## [spec] bblock 44, line 382-1,  t61,  t292(SI16),  107(SI32)
;;								## 23
	c0    mpyl $r0.4 = $r0.4, -77   ## [spec] bblock 44, line 383-1,  t66,  t233(SI16),  -77(SI32)
;;								## 24
	c0    mpyl $r0.15 = $r0.13, -24   ## [spec] bblock 44, line 380-1,  t53,  t235(SI16),  -24(SI32)
;;								## 25
	c0    shr $r0.14 = $r0.14, 7   ## [spec] bblock 44, line 382-1,  t62(SI25),  t61,  7(SI32)
;;								## 26
	c0    sxth $r0.15 = $r0.15   ## [spec] bblock 44, line 380-1,  t72(SI16),  t53
;;								## 27
	c0    sxth $r0.14 = $r0.14   ## [spec] bblock 44, line 382-1,  t70(SI16),  t62(SI25)
;;								## 28
	c0    add $r0.15 = $r0.15, $r0.14   ## [spec] bblock 44, line 384-1,  t684,  t72(SI16),  t70(SI16)
;;								## 29
	c0    shr $r0.4 = $r0.4, 7   ## [spec] bblock 44, line 383-1,  t67(SI25),  t66,  7(SI32)
;;								## 30
	c0    sxth $r0.4 = $r0.4   ## [spec] bblock 44, line 383-1,  t69(SI16),  t67(SI25)
;;								## 31
	c0    mpyl $r0.3 = $r0.3, 14   ## [spec] bblock 44, line 381-1,  t276,  t367(SI16),  14(SI32)
;;								## 32
	c0    ldh.d $r0.14 = 2[$r0.7]   ## [spec] bblock 44, line 388-1, t87(SI16), t376
;;								## 33
	c0    sxth $r0.3 = $r0.3   ## [spec] bblock 44, line 381-1,  t71(SI16),  t276
;;								## 34
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 44, line 384-1,  t683,  t71(SI16),  t69(SI16)
;;								## 35
	c0    add $r0.3 = $r0.3, $r0.15   ## [spec] bblock 44, line 384-1,  t73,  t683,  t684
;;								## 36
	c0    sxth $r0.4 = $r0.3   ## [spec] bblock 44, line 384-1,  t233(SI16),  t73
;;								## 37
	c0    add $r0.14 = $r0.4, $r0.14   ## [spec] bblock 44, line 388-1,  t91,  t233(SI16),  t87(SI16)
;;								## 38
	c0    shl $r0.14 = $r0.14, 7   ## [spec] bblock 44, line 388-1,  t93,  t91,  7(I32)
;;								## 39
	c0    shr $r0.14 = $r0.14, 7   ## [spec] bblock 44, line 388-1,  t94(SI25),  t93,  7(SI32)
;;								## 40
	c0    mov $r0.5 = $r0.12   ## [spec] bblock 44, line 384,  t232(SI16),  t292(SI16)
;;								## 41
	c0    add $r0.2 = $r0.2, 2   ## [spec] bblock 44, line 0,  t373,  t373,  2(I32)
;;								## 42
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 44, line 0,  t376,  t376,  4(I32)
;;								## 43
	c0    add $r0.8 = $r0.8, 2   ## [spec] bblock 44, line 0,  t377,  t377,  2(I32)
;;								## 44
	c0    sth 0[$r0.10] = $r0.6   ## bblock 20, line 384, t375, t294
;;								## 45
	c0    mov $r0.6 = $r0.13   ## [spec] t235(SI16)
;;								## 46
	c0    sth 0[$r0.9] = $r0.11   ## bblock 20, line 388, t374, t286(SI25)
;;								## 47
	c0    brf $b0.1, L109?3   ## bblock 20, line 379-1,  t666(I1)
;;								## 48
	c0    sth 2[$r0.10] = $r0.3   ## bblock 44, line 384-1, t375, t73
;;								## 49
	c0    add $r0.10 = $r0.10, 4   ## bblock 44, line 0,  t375,  t375,  4(I32)
;;								## 50
	c0    sth 2[$r0.9] = $r0.14   ## bblock 44, line 388-1, t374, t94(SI25)
;;								## 51
	c0    add $r0.9 = $r0.9, 4   ## bblock 44, line 0,  t374,  t374,  4(I32)
	      ## goto
;;
	c0    goto L108?3 ## goto
;;								## 52
.trace 16
L109?3:
	c0    add $r0.24 = $r0.24, 1050   ## bblock 19, line 0,  t602,  t602,  1050(I32)
;;								## 0
	c0    add $r0.23 = $r0.23, 2100   ## bblock 19, line 0,  t604,  t604,  2100(I32)
;;								## 1
	c0    add $r0.10 = $r0.17, 1050   ## bblock 19, line 0,  t607,  t607,  1050(I32)
;;								## 2
	c0    add $r0.9 = $r0.16, 1   ## bblock 19, line 0,  t608,  t608,  1(I32)
;;								## 3
	c0    mov $r0.12 = $r0.19   ## t204
;;								## 4
	c0    mov $r0.11 = $r0.18   ## t268
	      ## goto
;;
	c0    goto L101?3 ## goto
;;								## 5
.trace 19
L105?3:
	c0    sub $r0.3 = 1, $r0.19   ## bblock 17, line 0,  t378,  1(I32),  t204
	      ## goto
;;
	c0    goto L107?3 ## goto
;;								## 0
.trace 14
L104?3:
	c0    sub $r0.3 = 1, $r0.19   ## bblock 17, line 0,  t378,  1(I32),  t204
;;								## 0
L107?3:
	c0    mov $r0.8 = $r0.3   ## bblock 17, line 0,  t377,  t378
;;								## 1
	c0    mov $r0.9 = $r0.23   ## bblock 17, line 0,  t374,  t604
;;								## 2
	c0    mov $r0.7 = (s_ay2 + 0)   ## bblock 17, line 0,  t376,  addr(s_ay2?1.0)(P32)
;;								## 3
	c0    mov $r0.10 = (s_ay1 + 0)   ## bblock 17, line 0,  t375,  addr(s_ay1?1.0)(P32)
;;								## 4
	c0    mov $r0.2 = $r0.24   ## bblock 17, line 0,  t373,  t602
;;								## 5
	c0    mov $r0.6 = $r0.20   ## t235(SI16)
;;								## 6
	c0    mov $r0.4 = $r0.21   ## t233(SI16)
;;								## 7
	c0    mov $r0.5 = $r0.22   ## t232(SI16)
	      ## goto
;;
	c0    goto L108?3 ## goto
;;								## 8
.trace 23
L102?3:
	c0    sub $r0.12 = $r0.0, $r0.12   ## bblock 2, line 0,  t571,  0(I32),  t204
;;								## 0
	c0    mov $r0.9 = $r0.12   ## bblock 2, line 0,  t570,  t571
;;								## 1
	c0    mov $r0.23 = (s_at + 0)   ## bblock 2, line 0,  t565,  addr(s_at?1.0)(P32)
;;								## 2
	c0    mov $r0.22 = (out + 0)   ## bblock 2, line 0,  t566,  addr(out?1.0)(P32)
;;								## 3
	c0    mov $r0.11 = ((s_at + 0) + (~0x1067))   ## bblock 2, line 0,  t569,  (addr(s_at?1.0)(P32) + 0xffffef98(I32))(P32)
;;								## 4
	c0    add $r0.10 = $r0.25, -1   ## bblock 2, line 394,  t269,  t203,  -1(SI32)
;;								## 5
	c0    mov $r0.12 = $r0.25   ## t203
;;								## 6
.trace 12
L110?3:
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 3, line 392,  t652(I1),  t570,  0(SI32)
;;								## 0
	c0    mpylu $r0.13 = $r0.10, 2100   ## [spec] bblock 5, line 0,  t517,  t269,  2100(I32)
;;								## 1
	c0    brf $b0.0, L111?3   ## bblock 3, line 392,  t652(I1)
;;								## 2
	c0    add $r0.8 = $r0.11, $r0.13   ## bblock 5, line 0,  t514,  t569,  t517
;;								## 3
	c0    sh1add $r0.7 = $r0.12, (((s_by2 + 0) + (~0x3)) + (~0x1))   ## bblock 5, line 0,  t513,  t203,  ((addr(s_by2?1.0)(P32) + 0xfffffffc(I32))(P32) + 0xfffffffe(I32))(P32)
;;								## 4
	c0    mov $r0.3 = $r0.0   ## bblock 5, line 393,  t229(SI16),  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 5, line 393,  t228(SI16),  0(SI32)
;;								## 6
	c0    mov $r0.4 = $r0.0   ## bblock 5, line 393,  t307(SI16),  0(SI32)
;;								## 7
	c0    mov $r0.2 = $r0.0   ## bblock 5, line 393,  t306(SI16),  0(SI32)
;;								## 8
	c0    mov $r0.19 = $r0.0   ## bblock 5, line 393,  t266(SI16),  0(SI32)
;;								## 9
	c0    mov $r0.20 = $r0.0   ## bblock 5, line 393,  t264(SI16),  0(SI32)
;;								## 10
	c0    mov $r0.21 = $r0.0   ## bblock 5, line 393,  t234(SI16),  0(SI32)
;;								## 11
	c0    mov $r0.6 = $r0.10   ## bblock 5, line 394,  t265,  t269
;;								## 12
	c0    mov $r0.15 = $r0.9   ## t570
;;								## 13
	c0    mov $r0.16 = $r0.10   ## t269
;;								## 14
	c0    mov $r0.17 = $r0.11   ## t569
;;								## 15
	c0    mov $r0.18 = $r0.12   ## t203
;;								## 16
.trace 1
L112?3:
	c0    mpyl $r0.2 = $r0.2, -77   ## [spec] bblock 14, line 395,  t325,  t306(SI16),  -77(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -23   ## [spec] bblock 14, line 395,  t119,  t229(SI16),  -23(SI32)
;;								## 1
	c0    mpyl $r0.10 = $r0.4, 107   ## [spec] bblock 14, line 395,  t113,  t307(SI16),  107(SI32)
;;								## 2
	c0    add $r0.2 = $r0.2, $r0.9   ## [spec] bblock 14, line 395,  t659,  t325,  t119
;;								## 3
	c0    mpyl $r0.5 = $r0.5, 14   ## [spec] bblock 14, line 395,  t116,  t228(SI16),  14(SI32)
;;								## 4
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 6, line 394,  t653(I1),  t265,  0(SI32)
;;								## 5
	c0    add $r0.10 = $r0.10, $r0.5   ## [spec] bblock 14, line 395,  t660,  t113,  t116
;;								## 6
	c0    add $r0.2 = $r0.2, $r0.10   ## [spec] bblock 14, line 395,  t120,  t659,  t660
;;								## 7
	c0    shr $r0.2 = $r0.2, 7   ## [spec] bblock 14, line 395,  t121(SI25),  t120,  7(SI32)
;;								## 8
	c0    sxth $r0.9 = $r0.2   ## [spec] bblock 14, line 395,  t323(SI16),  t121(SI25)
;;								## 9
	c0    brf $b0.0, L113?3   ## bblock 6, line 394,  t653(I1)
;;								## 10
	c0    ldh $r0.10 = 4200[$r0.8]   ## bblock 14, line 397, t362(SI16), t514
;;								## 11
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 14, line 394-1,  t661(I1),  t265,  1(SI32)
;;								## 12
	c0    mpyl $r0.4 = $r0.4, -77   ## [spec] bblock 26, line 395-1,  t110,  t307(SI16),  -77(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.10, -23   ## [spec] bblock 26, line 395-1,  t332,  t362(SI16),  -23(SI32)
;;								## 14
	c0    mpyl $r0.12 = $r0.9, 107   ## [spec] bblock 26, line 395-1,  t331,  t323(SI16),  107(SI32)
;;								## 15
	c0    add $r0.4 = $r0.4, $r0.11   ## [spec] bblock 26, line 395-1,  t672,  t110,  t332
;;								## 16
	c0    mpyl $r0.3 = $r0.3, 14   ## [spec] bblock 26, line 395-1,  t334,  t229(SI16),  14(SI32)
;;								## 17
	c0    ldh.d $r0.11 = 2100[$r0.8]   ## [spec] bblock 26, line 397-1, t328(SI16), t514
;;								## 18
	c0    add $r0.12 = $r0.12, $r0.3   ## [spec] bblock 26, line 395-1,  t673,  t331,  t334
;;								## 19
	c0    add $r0.4 = $r0.4, $r0.12   ## [spec] bblock 26, line 395-1,  t329,  t672,  t673
;;								## 20
	c0    shr $r0.4 = $r0.4, 7   ## [spec] bblock 26, line 395-1,  t330(SI25),  t329,  7(SI32)
;;								## 21
	c0    sxth $r0.12 = $r0.4   ## [spec] bblock 26, line 395-1,  t263(SI16),  t330(SI25)
;;								## 22
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 26, line 394-2,  t674(I1),  t265,  2(SI32)
;;								## 23
	c0    mpyl $r0.9 = $r0.9, -77   ## [spec] bblock 23, line 395-2,  t352,  t323(SI16),  -77(SI32)
;;								## 24
	c0    mpyl $r0.13 = $r0.11, -23   ## [spec] bblock 23, line 395-2,  t338,  t328(SI16),  -23(SI32)
;;								## 25
	c0    mpyl $r0.14 = $r0.12, 107   ## [spec] bblock 23, line 395-2,  t351,  t263(SI16),  107(SI32)
;;								## 26
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 23, line 395-2,  t670,  t352,  t338
;;								## 27
	c0    mpyl $r0.10 = $r0.10, 14   ## [spec] bblock 23, line 395-2,  t350,  t362(SI16),  14(SI32)
;;								## 28
	c0    ldh.d $r0.3 = 0[$r0.8]   ## [spec] bblock 23, line 397-2, t229(SI16), t514
;;								## 29
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 23, line 395-2,  t671,  t351,  t350
;;								## 30
	c0    add $r0.9 = $r0.9, $r0.14   ## [spec] bblock 23, line 395-2,  t337,  t670,  t671
;;								## 31
	c0    shr $r0.9 = $r0.9, 7   ## [spec] bblock 23, line 395-2,  t336(SI25),  t337,  7(SI32)
;;								## 32
	c0    mov $r0.5 = $r0.11   ## [spec] bblock 23, line 397-1,  t228(SI16),  t328(SI16)
;;								## 33
	c0    add $r0.6 = $r0.6, -3   ## [spec] bblock 23, line 394-2,  t265,  t265,  -3(SI32)
;;								## 34
	c0    sth 4[$r0.7] = $r0.2   ## bblock 14, line 395, t513, t121(SI25)
;;								## 35
	c0    brf $b0.0, L113?3   ## bblock 14, line 394-1,  t661(I1)
;;								## 36
	c0    sth 2[$r0.7] = $r0.4   ## bblock 26, line 395-1, t513, t330(SI25)
;;								## 37
	c0    brf $b0.1, L113?3   ## bblock 26, line 394-2,  t674(I1)
;;								## 38
	c0    sxth $r0.4 = $r0.9   ## bblock 23, line 395-2,  t307(SI16),  t336(SI25)
;;								## 39
	c0    mov $r0.2 = $r0.12   ## bblock 23, line 395-1,  t306(SI16),  t263(SI16)
;;								## 40
	c0    add $r0.8 = $r0.8, (~0x189b)   ## bblock 23, line 0,  t514,  t514,  (~0x189b)(I32)
;;								## 41
	c0    sth 0[$r0.7] = $r0.9   ## bblock 23, line 395-2, t513, t336(SI25)
;;								## 42
	c0    add $r0.7 = $r0.7, (~0x5)   ## bblock 23, line 0,  t513,  t513,  (~0x5)(I32)
	      ## goto
;;
	c0    goto L112?3 ## goto
;;								## 43
.trace 13
L113?3:
	c0    sub $r0.3 = 1, $r0.18   ## bblock 7, line 0,  t456,  1(I32),  t203
;;								## 0
	c0    mov $r0.8 = $r0.3   ## bblock 7, line 0,  t455,  t456
;;								## 1
	c0    mov $r0.9 = $r0.22   ## bblock 7, line 0,  t454,  t566
;;								## 2
	c0    mov $r0.7 = (s_by2 + 0)   ## bblock 7, line 0,  t453,  addr(s_by2?1.0)(P32)
;;								## 3
	c0    mov $r0.10 = (s_by1 + 0)   ## bblock 7, line 0,  t452,  addr(s_by1?1.0)(P32)
;;								## 4
	c0    mov $r0.2 = $r0.23   ## bblock 7, line 0,  t451,  t565
;;								## 5
	c0    mov $r0.4 = $r0.20   ## t264(SI16)
;;								## 6
	c0    mov $r0.5 = $r0.19   ## t266(SI16)
;;								## 7
	c0    mov $r0.6 = $r0.21   ## t234(SI16)
;;								## 8
	c0    mov $r0.11 = 2100   ## 2100(I32)
;;								## 9
	c0    mov $r0.19 = $r0.17   ## t569
;;								## 10
	c0    mov $r0.21 = $r0.18   ## t203
;;								## 11
	c0    mov $r0.18 = $r0.16   ## t269
;;								## 12
	c0    mov $r0.20 = $r0.15   ## t570
;;								## 13
.trace 3
L114?3:
	c0    ldh.d $r0.3 = 0[$r0.2]   ## [spec] bblock 10, line 402, t345(SI16), t451
;;								## 0
	c0    mpyl $r0.4 = $r0.4, -77   ## [spec] bblock 10, line 402,  t349,  t264(SI16),  -77(SI32)
;;								## 1
	c0    mpyl $r0.12 = $r0.5, 107   ## [spec] bblock 10, line 402,  t360,  t266(SI16),  107(SI32)
;;								## 2
	c0    mpyl $r0.13 = $r0.3, -24   ## [spec] bblock 10, line 402,  t152,  t345(SI16),  -24(SI32)
;;								## 3
	c0    mpyl $r0.6 = $r0.6, 14   ## [spec] bblock 10, line 402,  t359,  t234(SI16),  14(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.13   ## [spec] bblock 10, line 402,  t655,  t349,  t152
;;								## 5
	c0    add $r0.12 = $r0.12, $r0.6   ## [spec] bblock 10, line 402,  t656,  t360,  t359
;;								## 6
	c0    add $r0.4 = $r0.4, $r0.12   ## [spec] bblock 10, line 402,  t358,  t655,  t656
;;								## 7
	c0    shr $r0.4 = $r0.4, 7   ## [spec] bblock 10, line 402,  t357(SI25),  t358,  7(SI32)
;;								## 8
	c0    sxth $r0.12 = $r0.4   ## [spec] bblock 10, line 402,  t344(SI16),  t357(SI25)
;;								## 9
	c0    ldh.d $r0.13 = 0[$r0.7]   ## [spec] bblock 10, line 406, t343(SI16), t453
;;								## 10
	c0    cmplt $b0.0 = $r0.8, 1   ## bblock 8, line 401,  t654(I1),  t455,  1(SI32)
;;								## 11
	c0    cmplt $b0.1 = $r0.8, $r0.0   ## [spec] bblock 12, line 401-1,  t658(I1),  t455,  0(SI32)
;;								## 12
	c0    add $r0.13 = $r0.12, $r0.13   ## [spec] bblock 10, line 406,  t342,  t344(SI16),  t343(SI16)
;;								## 13
	c0    shl $r0.13 = $r0.13, 7   ## [spec] bblock 10, line 406,  t341,  t342,  7(I32)
;;								## 14
	c0    shr $r0.13 = $r0.13, 14   ## [spec] bblock 10, line 406,  t340(SI18),  t341,  14(SI32)
;;								## 15
	c0    brf $b0.0, L115?3   ## bblock 8, line 401,  t654(I1)
;;								## 16
	c0    zxtb $r0.14 = $r0.13   ## bblock 10, line 406,  t339(I8),  t340(SI18)
;;								## 17
	c0    cmpgt $b0.0 = $r0.14, 25   ## bblock 10, line 407,  t657(I1),  t339(I8),  25(SI32)
;;								## 18
	c0    ldh.d $r0.6 = 2100[$r0.2]   ## [spec] bblock 30, line 402-1, t234(SI16), t451
;;								## 19
	c0    mpyl $r0.14 = $r0.5, -77   ## [spec] bblock 30, line 402-1,  t140,  t266(SI16),  -77(SI32)
;;								## 20
	c0    mpyl $r0.15 = $r0.12, 107   ## [spec] bblock 30, line 402-1,  t143,  t344(SI16),  107(SI32)
;;								## 21
	c0    mpyl $r0.16 = $r0.6, -24   ## [spec] bblock 30, line 402-1,  t354,  t234(SI16),  -24(SI32)
;;								## 22
	c0    mpyl $r0.17 = $r0.3, 14   ## [spec] bblock 30, line 402-1,  t146,  t345(SI16),  14(SI32)
;;								## 23
	c0    add $r0.14 = $r0.14, $r0.16   ## [spec] bblock 30, line 402-1,  t675,  t140,  t354
;;								## 24
	c0    add $r0.15 = $r0.15, $r0.17   ## [spec] bblock 30, line 402-1,  t676,  t143,  t146
;;								## 25
	c0    add $r0.14 = $r0.14, $r0.15   ## [spec] bblock 30, line 402-1,  t153,  t675,  t676
;;								## 26
	c0    shr $r0.14 = $r0.14, 7   ## [spec] bblock 30, line 402-1,  t154(SI25),  t153,  7(SI32)
;;								## 27
	c0    ldh.d $r0.15 = 2[$r0.7]   ## [spec] bblock 30, line 406-1, t168(SI16), t453
;;								## 28
	c0    sth 0[$r0.10] = $r0.4   ## bblock 10, line 402, t452, t357(SI25)
;;								## 29
	c0    mov $r0.4 = $r0.12   ## [spec] bblock 30, line 402-1,  t264(SI16),  t344(SI16)
;;								## 30
	c0    stb 0[$r0.9] = $r0.13   ## bblock 10, line 406, t454, t340(SI18)
;;								## 31
	c0    brf $b0.0, L116?3   ## bblock 10, line 407,  t657(I1)
;;								## 32
	c0    sxth $r0.5 = $r0.14   ## [spec] bblock 30, line 402-1,  t266(SI16),  t154(SI25)
;;								## 33
	c0    add $r0.15 = $r0.5, $r0.15   ## [spec] bblock 30, line 406-1,  t172,  t266(SI16),  t168(SI16)
;;								## 34
	c0    shl $r0.15 = $r0.15, 7   ## [spec] bblock 30, line 406-1,  t174,  t172,  7(I32)
;;								## 35
	c0    shr $r0.15 = $r0.15, 14   ## [spec] bblock 30, line 406-1,  t175(SI18),  t174,  14(SI32)
;;								## 36
	c0    zxtb $r0.3 = $r0.15   ## [spec] bblock 30, line 406-1,  t183(I8),  t175(SI18)
;;								## 37
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 30, line 407-1,  t677(I1),  t183(I8),  25(SI32)
;;								## 38
	c0    stb 0[$r0.9] = $r0.0   ## bblock 13, line 408, t454, 0(I32)
;;								## 39
L117?3:
	c0    brf $b0.1, L115?3   ## bblock 12, line 401-1,  t658(I1)
;;								## 40
	c0    sth 2[$r0.10] = $r0.14   ## bblock 30, line 402-1, t452, t154(SI25)
;;								## 41
	c0    stb 1050[$r0.9] = $r0.15   ## bblock 30, line 406-1, t454, t175(SI18)
;;								## 42
	c0    brf $b0.0, L118?3   ## bblock 30, line 407-1,  t677(I1)
;;								## 43
	c0    add $r0.2 = $r0.2, 4200   ## bblock 32, line 0,  t451,  t451,  4200(I32)
;;								## 44
	c0    add $r0.10 = $r0.10, 4   ## bblock 32, line 0,  t452,  t452,  4(I32)
;;								## 45
	c0    add $r0.7 = $r0.7, 4   ## bblock 32, line 0,  t453,  t453,  4(I32)
;;								## 46
	c0    add $r0.8 = $r0.8, 2   ## bblock 32, line 0,  t455,  t455,  2(I32)
;;								## 47
	c0    stb 1050[$r0.9] = $r0.0   ## bblock 33, line 408-1, t454, 0(I32)
;;								## 48
L119?3:
	c0    add $r0.9 = $r0.9, $r0.11   ## bblock 32, line 0,  t454,  t454,  2100(I32)
	      ## goto
;;
	c0    goto L114?3 ## goto
;;								## 49
.trace 10
L118?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.8 = $r0.8, 2   ## bblock 32, line 0,  t455,  t455,  2(I32)
;;								## 1
	c0    add $r0.7 = $r0.7, 4   ## bblock 32, line 0,  t453,  t453,  4(I32)
;;								## 2
	c0    add $r0.10 = $r0.10, 4   ## bblock 32, line 0,  t452,  t452,  4(I32)
;;								## 3
	c0    add $r0.2 = $r0.2, 4200   ## bblock 32, line 0,  t451,  t451,  4200(I32)
;;								## 4
	c0    stb 1050[$r0.9] = $r0.3   ## bblock 31, line 410-1, t454, 255(I32)
	      ## goto
;;
	c0    goto L119?3 ## goto
;;								## 5
.trace 15
L115?3:
	c0    add $r0.23 = $r0.23, 2   ## bblock 9, line 0,  t565,  t565,  2(I32)
;;								## 0
	c0    add $r0.22 = $r0.22, 1   ## bblock 9, line 0,  t566,  t566,  1(I32)
;;								## 1
	c0    add $r0.11 = $r0.19, 2   ## bblock 9, line 0,  t569,  t569,  2(I32)
;;								## 2
	c0    add $r0.9 = $r0.20, 1   ## bblock 9, line 0,  t570,  t570,  1(I32)
;;								## 3
	c0    mov $r0.10 = $r0.18   ## t269
;;								## 4
	c0    mov $r0.12 = $r0.21   ## t203
	      ## goto
;;
	c0    goto L110?3 ## goto
;;								## 5
.trace 9
L116?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    sxth $r0.5 = $r0.14   ## [spec] bblock 30, line 402-1,  t266(SI16),  t154(SI25)
;;								## 1
	c0    add $r0.15 = $r0.5, $r0.15   ## [spec] bblock 30, line 406-1,  t172,  t266(SI16),  t168(SI16)
;;								## 2
	c0    shl $r0.15 = $r0.15, 7   ## [spec] bblock 30, line 406-1,  t174,  t172,  7(I32)
;;								## 3
	c0    shr $r0.15 = $r0.15, 14   ## [spec] bblock 30, line 406-1,  t175(SI18),  t174,  14(SI32)
;;								## 4
	c0    zxtb $r0.12 = $r0.15   ## [spec] bblock 30, line 406-1,  t183(I8),  t175(SI18)
;;								## 5
	c0    cmpgt $b0.0 = $r0.12, 25   ## [spec] bblock 30, line 407-1,  t677(I1),  t183(I8),  25(SI32)
;;								## 6
	c0    stb 0[$r0.9] = $r0.3   ## bblock 11, line 410, t454, 255(I32)
	      ## goto
;;
	c0    goto L117?3 ## goto
;;								## 7
.trace 24
L111?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 4, line 414,  t191,  ?2.5?2auto_size(I32),  t190
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.5?2auto_size, 0x0
 ## End deriche_short
.equ _?1TEMPLATEPACKET.5, 0x0
 ## Begin deriche_simd
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_simd::
.trace 23
	      ## auto_size == 0
;;								## 0
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t613,  0(I32),  t209
;;								## 1
	c0    mov $r0.11 = $r0.2   ## bblock 0, line 0,  t612,  t613
;;								## 2
	c0    mov $r0.2 = -23   ## -23(SI32)
;;								## 3
	c0    asm,6 $r0.5 = $r0.2, 14   ## bblock 0, line 439,  t214,  -23(SI32),  14(SI32)
;;								## 4
	c0    mov $r0.6 = -24   ## -24(SI32)
;;								## 5
	c0    asm,6 $r0.27 = $r0.6, 14   ## bblock 0, line 438,  t211,  -24(SI32),  14(SI32)
;;								## 6
	c0    asm,6 $r0.7 = $r0.2, -24   ## bblock 0, line 437,  t212,  -23(SI32),  -24(SI32)
;;								## 7
	c0    mov $r0.2 = 107   ## 107(SI32)
;;								## 8
	c0    mov $r0.26 = (in + 0)   ## bblock 0, line 0,  t606,  addr(in?1.0)(P32)
;;								## 9
	c0    mov $r0.14 = $r0.4   ## t210
;;								## 10
	c0    asm,6 $r0.4 = $r0.2, -77   ## bblock 0, line 440,  t213,  107(SI32),  -77(SI32)
;;								## 11
	c0    mov $r0.25 = (s_at + 0)   ## bblock 0, line 0,  t608,  addr(s_at?1.0)(P32)
;;								## 12
	c0    add $r0.13 = $r0.14, -1   ## bblock 0, line 444,  t274,  t210,  -1(SI32)
;;								## 13
	c0    mov $r0.12 = ((in + 0) + (~0x1))   ## bblock 0, line 0,  t611,  (addr(in?1.0)(P32) + 0xfffffffe(I32))(P32)
;;								## 14
	c0    mov $r0.28 = $r0.3   ## t209
;;								## 15
.trace 11
L120?3:
	c0    cmplt $b0.0 = $r0.11, $r0.0   ## bblock 1, line 442,  t655(I1),  t612,  0(SI32)
;;								## 0
	c0    add $r0.10 = $r0.12, $r0.13   ## [spec] bblock 15, line 0,  t423,  t611,  t274
;;								## 1
	c0    brf $b0.0, L121?3   ## bblock 1, line 442,  t655(I1)
;;								## 2
	c0    sh1add $r0.9 = $r0.14, (((s_ay2 + 0) + (~0x3)) + (~0x1))   ## bblock 15, line 0,  t422,  t210,  ((addr(s_ay2?1.0)(P32) + 0xfffffffc(I32))(P32) + 0xfffffffe(I32))(P32)
;;								## 3
	c0    mov $r0.3 = $r0.0   ## bblock 15, line 443,  t231(SI16),  0(SI32)
;;								## 4
	c0    mov $r0.2 = $r0.0   ## bblock 15, line 443,  t232(SI16),  0(SI32)
;;								## 5
	c0    mov $r0.6 = $r0.0   ## bblock 15, line 443,  t276(SI16),  0(SI32)
;;								## 6
	c0    mov $r0.5 = $r0.0   ## bblock 15, line 443,  t236(SI16),  0(SI32)
;;								## 7
	c0    mov $r0.22 = $r0.0   ## bblock 15, line 443,  t240(SI16),  0(SI32)
;;								## 8
	c0    mov $r0.23 = $r0.0   ## bblock 15, line 443,  t238(SI16),  0(SI32)
;;								## 9
	c0    mov $r0.24 = $r0.0   ## bblock 15, line 443,  t237(SI16),  0(SI32)
;;								## 10
	c0    mov $r0.8 = $r0.13   ## bblock 15, line 444,  t309,  t274
;;								## 11
	c0    mov $r0.18 = $r0.11   ## t612
;;								## 12
	c0    mov $r0.19 = $r0.12   ## t611
;;								## 13
	c0    mov $r0.20 = $r0.13   ## t274
;;								## 14
	c0    mov $r0.21 = $r0.14   ## t210
;;								## 15
.trace 2
L122?3:
	c0    shr $r0.2 = $r0.2, 7   ## [spec] bblock 21, line 446,  t277(SI25),  t232(SI16),  7(SI32)
;;								## 0
	c0    shr $r0.3 = $r0.3, 7   ## [spec] bblock 21, line 446,  t27(SI25),  t231(SI16),  7(SI32)
;;								## 1
	c0    asm,6 $r0.3 = $r0.2, $r0.3   ## [spec] bblock 21, line 446,  t33,  t277(SI25),  t27(SI25)
;;								## 2
	c0    asm,65 $r0.3 = $r0.4, $r0.3   ## [spec] bblock 21, line 447,  t34,  t213,  t33
;;								## 3
	c0    asm,6 $r0.6 = $r0.5, $r0.6   ## [spec] bblock 21, line 445,  t30,  t236(SI16),  t276(SI16)
;;								## 4
	c0    asm,65 $r0.6 = $r0.7, $r0.6   ## [spec] bblock 21, line 447,  t31,  t212,  t30
;;								## 5
	c0    cmpge $b0.0 = $r0.8, $r0.0   ## bblock 16, line 444,  t666(I1),  t309,  0(SI32)
;;								## 6
	c0    asm,1 $r0.6 = $r0.6, $r0.3   ## [spec] bblock 21, line 447,  t38,  t31,  t34
;;								## 7
	c0    asm,7 $r0.11 = $r0.6, $r0.0   ## [spec] bblock 21, line 448,  t37,  t38,  0(SI32)
;;								## 8
	c0    asm,7 $r0.6 = $r0.6, 1   ## [spec] bblock 21, line 448,  t39,  t38,  1(SI32)
;;								## 9
	c0    add $r0.11 = $r0.11, $r0.6   ## [spec] bblock 21, line 448,  t373,  t37,  t39
;;								## 10
	c0    sxth $r0.12 = $r0.11   ## [spec] bblock 21, line 448,  t372(SI16),  t373
;;								## 11
	c0    brf $b0.0, L123?3   ## bblock 16, line 444,  t666(I1)
;;								## 12
	c0    ldbu $r0.13 = 2[$r0.10]   ## bblock 21, line 450, t279(SI16), t423
;;								## 13
	c0    cmpge $b0.0 = $r0.8, 1   ## bblock 21, line 444-1,  t669(I1),  t309,  1(SI32)
;;								## 14
	c0    shr $r0.12 = $r0.12, 7   ## [spec] bblock 40, line 446-1,  t25(SI25),  t372(SI16),  7(SI32)
;;								## 15
	c0    asm,6 $r0.2 = $r0.12, $r0.2   ## [spec] bblock 40, line 446-1,  t292,  t25(SI25),  t277(SI25)
;;								## 16
	c0    asm,65 $r0.2 = $r0.4, $r0.2   ## [spec] bblock 40, line 447-1,  t369,  t213,  t292
;;								## 17
	c0    asm,6 $r0.5 = $r0.13, $r0.5   ## [spec] bblock 40, line 445-1,  t308,  t279(SI16),  t236(SI16)
;;								## 18
	c0    asm,65 $r0.5 = $r0.7, $r0.5   ## [spec] bblock 40, line 447-1,  t290,  t212,  t308
;;								## 19
	c0    ldbu.d $r0.14 = 1[$r0.10]   ## [spec] bblock 40, line 450-1, t285(SI16), t423
;;								## 20
	c0    asm,1 $r0.5 = $r0.5, $r0.2   ## [spec] bblock 40, line 447-1,  t368,  t290,  t369
;;								## 21
	c0    asm,7 $r0.15 = $r0.5, $r0.0   ## [spec] bblock 40, line 448-1,  t289,  t368,  0(SI32)
;;								## 22
	c0    asm,7 $r0.5 = $r0.5, 1   ## [spec] bblock 40, line 448-1,  t288,  t368,  1(SI32)
;;								## 23
	c0    add $r0.15 = $r0.15, $r0.5   ## [spec] bblock 40, line 448-1,  t40,  t289,  t288
;;								## 24
	c0    sxth $r0.16 = $r0.15   ## [spec] bblock 40, line 448-1,  t287(SI16),  t40
;;								## 25
	c0    cmpge $b0.1 = $r0.8, 2   ## [spec] bblock 40, line 444-2,  t678(I1),  t309,  2(SI32)
;;								## 26
	c0    shr $r0.17 = $r0.16, 7   ## [spec] bblock 37, line 446-2,  t321(SI25),  t287(SI16),  7(SI32)
;;								## 27
	c0    asm,6 $r0.17 = $r0.17, $r0.12   ## [spec] bblock 37, line 446-2,  t319,  t321(SI25),  t25(SI25)
;;								## 28
	c0    asm,65 $r0.17 = $r0.4, $r0.17   ## [spec] bblock 37, line 447-2,  t317,  t213,  t319
;;								## 29
	c0    asm,6 $r0.13 = $r0.14, $r0.13   ## [spec] bblock 37, line 445-2,  t322,  t285(SI16),  t279(SI16)
;;								## 30
	c0    asm,65 $r0.13 = $r0.7, $r0.13   ## [spec] bblock 37, line 447-2,  t318,  t212,  t322
;;								## 31
	c0    ldbu.d $r0.5 = 0[$r0.10]   ## [spec] bblock 37, line 450-2, t236(SI16), t423
;;								## 32
	c0    asm,1 $r0.13 = $r0.13, $r0.17   ## [spec] bblock 37, line 447-2,  t316,  t318,  t317
;;								## 33
	c0    asm,7 $r0.12 = $r0.13, $r0.0   ## [spec] bblock 37, line 448-2,  t315,  t316,  0(SI32)
;;								## 34
	c0    asm,7 $r0.13 = $r0.13, 1   ## [spec] bblock 37, line 448-2,  t314,  t316,  1(SI32)
;;								## 35
	c0    add $r0.12 = $r0.12, $r0.13   ## [spec] bblock 37, line 448-2,  t313,  t315,  t314
;;								## 36
	c0    sxth $r0.2 = $r0.12   ## [spec] bblock 37, line 448-2,  t232(SI16),  t313
;;								## 37
	c0    mov $r0.3 = $r0.16   ## [spec] bblock 37, line 448-1,  t231(SI16),  t287(SI16)
;;								## 38
	c0    mov $r0.6 = $r0.14   ## [spec] bblock 37, line 450-1,  t276(SI16),  t285(SI16)
;;								## 39
	c0    add $r0.8 = $r0.8, -3   ## [spec] bblock 37, line 444-2,  t309,  t309,  -3(SI32)
;;								## 40
	c0    add $r0.10 = $r0.10, (~0x2)   ## [spec] bblock 37, line 0,  t423,  t423,  (~0x2)(I32)
;;								## 41
	c0    sth 4[$r0.9] = $r0.11   ## bblock 21, line 448, t422, t373
;;								## 42
	c0    brf $b0.0, L123?3   ## bblock 21, line 444-1,  t669(I1)
;;								## 43
	c0    sth 2[$r0.9] = $r0.15   ## bblock 40, line 448-1, t422, t40
;;								## 44
	c0    brf $b0.1, L123?3   ## bblock 40, line 444-2,  t678(I1)
;;								## 45
	c0    sth 0[$r0.9] = $r0.12   ## bblock 37, line 448-2, t422, t313
;;								## 46
	c0    add $r0.9 = $r0.9, (~0x5)   ## bblock 37, line 0,  t422,  t422,  (~0x5)(I32)
	      ## goto
;;
	c0    goto L122?3 ## goto
;;								## 47
.trace 13
L123?3:
	c0    sub $r0.3 = 1, $r0.21   ## bblock 17, line 0,  t382,  1(I32),  t210
;;								## 0
	c0    mov $r0.11 = $r0.3   ## bblock 17, line 0,  t381,  t382
;;								## 1
	c0    mov $r0.12 = $r0.25   ## bblock 17, line 0,  t378,  t608
;;								## 2
	c0    mov $r0.10 = (s_ay2 + 0)   ## bblock 17, line 0,  t380,  addr(s_ay2?1.0)(P32)
;;								## 3
	c0    mov $r0.13 = (s_ay1 + 0)   ## bblock 17, line 0,  t379,  addr(s_ay1?1.0)(P32)
;;								## 4
	c0    mov $r0.2 = $r0.26   ## bblock 17, line 0,  t377,  t606
;;								## 5
	c0    mov $r0.5 = $r0.22   ## t240(SI16)
;;								## 6
	c0    mov $r0.8 = $r0.23   ## t238(SI16)
;;								## 7
	c0    mov $r0.9 = $r0.24   ## t237(SI16)
;;								## 8
	c0    mov $r0.22 = $r0.21   ## t210
;;								## 9
	c0    mov $r0.21 = $r0.18   ## t612
;;								## 10
	c0    mov $r0.6 = $r0.27   ## t211
;;								## 11
.trace 4
L124?3:
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 20, line 455, t265(SI16), t377
;;								## 0
	c0    shr $r0.8 = $r0.8, 7   ## [spec] bblock 20, line 456,  t370(SI25),  t238(SI16),  7(SI32)
;;								## 1
	c0    shr $r0.9 = $r0.9, 7   ## [spec] bblock 20, line 456,  t306(SI25),  t237(SI16),  7(SI32)
;;								## 2
	c0    asm,6 $r0.5 = $r0.3, $r0.5   ## [spec] bblock 20, line 455,  t307,  t265(SI16),  t240(SI16)
;;								## 3
	c0    asm,65 $r0.5 = $r0.6, $r0.5   ## [spec] bblock 20, line 457,  t303,  t211,  t307
;;								## 4
	c0    asm,6 $r0.9 = $r0.8, $r0.9   ## [spec] bblock 20, line 456,  t305,  t370(SI25),  t306(SI25)
;;								## 5
	c0    asm,65 $r0.9 = $r0.4, $r0.9   ## [spec] bblock 20, line 457,  t302,  t213,  t305
;;								## 6
	c0    ldh.d $r0.14 = 0[$r0.10]   ## [spec] bblock 20, line 462, t296(SI16), t380
;;								## 7
	c0    asm,1 $r0.5 = $r0.5, $r0.9   ## [spec] bblock 20, line 457,  t301,  t303,  t302
;;								## 8
	c0    asm,7 $r0.15 = $r0.5, $r0.0   ## [spec] bblock 20, line 458,  t300,  t301,  0(SI32)
;;								## 9
	c0    asm,7 $r0.5 = $r0.5, 1   ## [spec] bblock 20, line 458,  t299,  t301,  1(SI32)
;;								## 10
	c0    add $r0.15 = $r0.15, $r0.5   ## [spec] bblock 20, line 458,  t298,  t300,  t299
;;								## 11
	c0    sxth $r0.16 = $r0.15   ## [spec] bblock 20, line 458,  t297(SI16),  t298
;;								## 12
	c0    add $r0.14 = $r0.16, $r0.14   ## [spec] bblock 20, line 462,  t295,  t297(SI16),  t296(SI16)
;;								## 13
	c0    shl $r0.14 = $r0.14, 7   ## [spec] bblock 20, line 462,  t294,  t295,  7(I32)
;;								## 14
	c0    shr $r0.14 = $r0.14, 7   ## [spec] bblock 20, line 462,  t100(SI25),  t294,  7(SI32)
;;								## 15
	c0    cmplt $b0.0 = $r0.11, 1   ## bblock 18, line 454,  t667(I1),  t381,  1(SI32)
;;								## 16
	c0    cmplt $b0.1 = $r0.11, $r0.0   ## [spec] bblock 20, line 454-1,  t668(I1),  t381,  0(SI32)
;;								## 17
	c0    brf $b0.0, L125?3   ## bblock 18, line 454,  t667(I1)
;;								## 18
	c0    ldbu.d $r0.5 = 1[$r0.2]   ## [spec] bblock 44, line 455-1, t240(SI16), t377
;;								## 19
	c0    shr $r0.17 = $r0.16, 7   ## [spec] bblock 44, line 456-1,  t64(SI25),  t297(SI16),  7(SI32)
;;								## 20
	c0    asm,6 $r0.17 = $r0.17, $r0.8   ## [spec] bblock 44, line 456-1,  t72,  t64(SI25),  t370(SI25)
;;								## 21
	c0    asm,6 $r0.3 = $r0.5, $r0.3   ## [spec] bblock 44, line 455-1,  t69,  t240(SI16),  t265(SI16)
;;								## 22
	c0    asm,65 $r0.3 = $r0.6, $r0.3   ## [spec] bblock 44, line 457-1,  t70,  t211,  t69
;;								## 23
	c0    asm,65 $r0.17 = $r0.4, $r0.17   ## [spec] bblock 44, line 457-1,  t73,  t213,  t72
;;								## 24
	c0    ldh.d $r0.18 = 2[$r0.10]   ## [spec] bblock 44, line 462-1, t93(SI16), t380
;;								## 25
	c0    asm,1 $r0.3 = $r0.3, $r0.17   ## [spec] bblock 44, line 457-1,  t77,  t70,  t73
;;								## 26
	c0    asm,7 $r0.17 = $r0.3, $r0.0   ## [spec] bblock 44, line 458-1,  t76,  t77,  0(SI32)
;;								## 27
	c0    asm,7 $r0.3 = $r0.3, 1   ## [spec] bblock 44, line 458-1,  t78,  t77,  1(SI32)
;;								## 28
	c0    add $r0.17 = $r0.17, $r0.3   ## [spec] bblock 44, line 458-1,  t79,  t76,  t78
;;								## 29
	c0    sxth $r0.8 = $r0.17   ## [spec] bblock 44, line 458-1,  t238(SI16),  t79
;;								## 30
	c0    add $r0.18 = $r0.8, $r0.18   ## [spec] bblock 44, line 462-1,  t97,  t238(SI16),  t93(SI16)
;;								## 31
	c0    shl $r0.18 = $r0.18, 7   ## [spec] bblock 44, line 462-1,  t99,  t97,  7(I32)
;;								## 32
	c0    shr $r0.18 = $r0.18, 7   ## [spec] bblock 44, line 462-1,  t367(SI25),  t99,  7(SI32)
;;								## 33
	c0    mov $r0.9 = $r0.16   ## [spec] bblock 44, line 458,  t237(SI16),  t297(SI16)
;;								## 34
	c0    add $r0.2 = $r0.2, 2   ## [spec] bblock 44, line 0,  t377,  t377,  2(I32)
;;								## 35
	c0    add $r0.10 = $r0.10, 4   ## [spec] bblock 44, line 0,  t380,  t380,  4(I32)
;;								## 36
	c0    add $r0.11 = $r0.11, 2   ## [spec] bblock 44, line 0,  t381,  t381,  2(I32)
;;								## 37
	c0    sth 0[$r0.12] = $r0.14   ## bblock 20, line 462, t378, t100(SI25)
;;								## 38
	c0    sth 0[$r0.13] = $r0.15   ## bblock 20, line 458, t379, t298
;;								## 39
	c0    brf $b0.1, L125?3   ## bblock 20, line 454-1,  t668(I1)
;;								## 40
	c0    sth 2[$r0.13] = $r0.17   ## bblock 44, line 458-1, t379, t79
;;								## 41
	c0    add $r0.13 = $r0.13, 4   ## bblock 44, line 0,  t379,  t379,  4(I32)
;;								## 42
	c0    sth 2[$r0.12] = $r0.18   ## bblock 44, line 462-1, t378, t367(SI25)
;;								## 43
	c0    add $r0.12 = $r0.12, 4   ## bblock 44, line 0,  t378,  t378,  4(I32)
	      ## goto
;;
	c0    goto L124?3 ## goto
;;								## 44
.trace 16
L125?3:
	c0    add $r0.26 = $r0.26, 1050   ## bblock 19, line 0,  t606,  t606,  1050(I32)
;;								## 0
	c0    add $r0.25 = $r0.25, 2100   ## bblock 19, line 0,  t608,  t608,  2100(I32)
;;								## 1
	c0    add $r0.12 = $r0.19, 1050   ## bblock 19, line 0,  t611,  t611,  1050(I32)
;;								## 2
	c0    add $r0.11 = $r0.21, 1   ## bblock 19, line 0,  t612,  t612,  1(I32)
;;								## 3
	c0    mov $r0.14 = $r0.22   ## t210
;;								## 4
	c0    mov $r0.13 = $r0.20   ## t274
;;								## 5
	c0    mov $r0.27 = $r0.6   ## t211
	      ## goto
;;
	c0    goto L120?3 ## goto
;;								## 6
.trace 24
L121?3:
	c0    sub $r0.14 = $r0.0, $r0.14   ## bblock 2, line 0,  t575,  0(I32),  t210
;;								## 0
	c0    mov $r0.9 = $r0.14   ## bblock 2, line 0,  t574,  t575
;;								## 1
	c0    mov $r0.23 = (s_at + 0)   ## bblock 2, line 0,  t569,  addr(s_at?1.0)(P32)
;;								## 2
	c0    mov $r0.22 = (out + 0)   ## bblock 2, line 0,  t570,  addr(out?1.0)(P32)
;;								## 3
	c0    mov $r0.11 = ((s_at + 0) + (~0x1067))   ## bblock 2, line 0,  t573,  (addr(s_at?1.0)(P32) + 0xffffef98(I32))(P32)
;;								## 4
	c0    add $r0.10 = $r0.28, -1   ## bblock 2, line 468,  t275,  t209,  -1(SI32)
;;								## 5
	c0    mov $r0.12 = $r0.28   ## t209
;;								## 6
.trace 12
L126?3:
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 3, line 466,  t656(I1),  t574,  0(SI32)
;;								## 0
	c0    mpylu $r0.13 = $r0.10, 2100   ## [spec] bblock 5, line 0,  t521,  t275,  2100(I32)
;;								## 1
	c0    brf $b0.0, L127?3   ## bblock 3, line 466,  t656(I1)
;;								## 2
	c0    add $r0.8 = $r0.11, $r0.13   ## bblock 5, line 0,  t518,  t573,  t521
;;								## 3
	c0    sh1add $r0.7 = $r0.12, (((s_by2 + 0) + (~0x3)) + (~0x1))   ## bblock 5, line 0,  t517,  t209,  ((addr(s_by2?1.0)(P32) + 0xfffffffc(I32))(P32) + 0xfffffffe(I32))(P32)
;;								## 4
	c0    mov $r0.3 = $r0.0   ## bblock 5, line 467,  t234(SI16),  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 5, line 467,  t233(SI16),  0(SI32)
;;								## 6
	c0    mov $r0.4 = $r0.0   ## bblock 5, line 467,  t269(SI16),  0(SI32)
;;								## 7
	c0    mov $r0.2 = $r0.0   ## bblock 5, line 467,  t310(SI16),  0(SI32)
;;								## 8
	c0    mov $r0.19 = $r0.0   ## bblock 5, line 467,  t272(SI16),  0(SI32)
;;								## 9
	c0    mov $r0.20 = $r0.0   ## bblock 5, line 467,  t270(SI16),  0(SI32)
;;								## 10
	c0    mov $r0.21 = $r0.0   ## bblock 5, line 467,  t239(SI16),  0(SI32)
;;								## 11
	c0    mov $r0.6 = $r0.10   ## bblock 5, line 468,  t327,  t275
;;								## 12
	c0    mov $r0.15 = $r0.9   ## t574
;;								## 13
	c0    mov $r0.16 = $r0.10   ## t275
;;								## 14
	c0    mov $r0.17 = $r0.11   ## t573
;;								## 15
	c0    mov $r0.18 = $r0.12   ## t209
;;								## 16
.trace 1
L128?3:
	c0    mpyl $r0.2 = $r0.2, -77   ## [spec] bblock 14, line 469,  t326,  t310(SI16),  -77(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -23   ## [spec] bblock 14, line 469,  t324,  t234(SI16),  -23(SI32)
;;								## 1
	c0    mpyl $r0.10 = $r0.4, 107   ## [spec] bblock 14, line 469,  t119,  t269(SI16),  107(SI32)
;;								## 2
	c0    add $r0.2 = $r0.2, $r0.9   ## [spec] bblock 14, line 469,  t663,  t326,  t324
;;								## 3
	c0    mpyl $r0.5 = $r0.5, 14   ## [spec] bblock 14, line 469,  t122,  t233(SI16),  14(SI32)
;;								## 4
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 6, line 468,  t657(I1),  t327,  0(SI32)
;;								## 5
	c0    add $r0.10 = $r0.10, $r0.5   ## [spec] bblock 14, line 469,  t664,  t119,  t122
;;								## 6
	c0    add $r0.2 = $r0.2, $r0.10   ## [spec] bblock 14, line 469,  t126,  t663,  t664
;;								## 7
	c0    shr $r0.2 = $r0.2, 7   ## [spec] bblock 14, line 469,  t127(SI25),  t126,  7(SI32)
;;								## 8
	c0    sxth $r0.9 = $r0.2   ## [spec] bblock 14, line 469,  t323(SI16),  t127(SI25)
;;								## 9
	c0    brf $b0.0, L129?3   ## bblock 6, line 468,  t657(I1)
;;								## 10
	c0    ldh $r0.10 = 4200[$r0.8]   ## bblock 14, line 471, t364(SI16), t518
;;								## 11
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 14, line 468-1,  t665(I1),  t327,  1(SI32)
;;								## 12
	c0    mpyl $r0.4 = $r0.4, -77   ## [spec] bblock 26, line 469-1,  t116,  t269(SI16),  -77(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.10, -23   ## [spec] bblock 26, line 469-1,  t125,  t364(SI16),  -23(SI32)
;;								## 14
	c0    mpyl $r0.12 = $r0.9, 107   ## [spec] bblock 26, line 469-1,  t335,  t323(SI16),  107(SI32)
;;								## 15
	c0    add $r0.4 = $r0.4, $r0.11   ## [spec] bblock 26, line 469-1,  t672,  t116,  t125
;;								## 16
	c0    mpyl $r0.3 = $r0.3, 14   ## [spec] bblock 26, line 469-1,  t332,  t234(SI16),  14(SI32)
;;								## 17
	c0    ldh.d $r0.11 = 2100[$r0.8]   ## [spec] bblock 26, line 471-1, t329(SI16), t518
;;								## 18
	c0    add $r0.12 = $r0.12, $r0.3   ## [spec] bblock 26, line 469-1,  t673,  t335,  t332
;;								## 19
	c0    add $r0.4 = $r0.4, $r0.12   ## [spec] bblock 26, line 469-1,  t331,  t672,  t673
;;								## 20
	c0    shr $r0.4 = $r0.4, 7   ## [spec] bblock 26, line 469-1,  t358(SI25),  t331,  7(SI32)
;;								## 21
	c0    sxth $r0.12 = $r0.4   ## [spec] bblock 26, line 469-1,  t357(SI16),  t358(SI25)
;;								## 22
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 26, line 468-2,  t674(I1),  t327,  2(SI32)
;;								## 23
	c0    mpyl $r0.9 = $r0.9, -77   ## [spec] bblock 23, line 469-2,  t354,  t323(SI16),  -77(SI32)
;;								## 24
	c0    mpyl $r0.13 = $r0.11, -23   ## [spec] bblock 23, line 469-2,  t340,  t329(SI16),  -23(SI32)
;;								## 25
	c0    mpyl $r0.14 = $r0.12, 107   ## [spec] bblock 23, line 469-2,  t353,  t357(SI16),  107(SI32)
;;								## 26
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 23, line 469-2,  t670,  t354,  t340
;;								## 27
	c0    mpyl $r0.10 = $r0.10, 14   ## [spec] bblock 23, line 469-2,  t352,  t364(SI16),  14(SI32)
;;								## 28
	c0    ldh.d $r0.3 = 0[$r0.8]   ## [spec] bblock 23, line 471-2, t234(SI16), t518
;;								## 29
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 23, line 469-2,  t671,  t353,  t352
;;								## 30
	c0    add $r0.9 = $r0.9, $r0.14   ## [spec] bblock 23, line 469-2,  t339,  t670,  t671
;;								## 31
	c0    shr $r0.9 = $r0.9, 7   ## [spec] bblock 23, line 469-2,  t338(SI25),  t339,  7(SI32)
;;								## 32
	c0    mov $r0.5 = $r0.11   ## [spec] bblock 23, line 471-1,  t233(SI16),  t329(SI16)
;;								## 33
	c0    sth 4[$r0.7] = $r0.2   ## bblock 14, line 469, t517, t127(SI25)
;;								## 34
	c0    brf $b0.0, L129?3   ## bblock 14, line 468-1,  t665(I1)
;;								## 35
	c0    sth 2[$r0.7] = $r0.4   ## bblock 26, line 469-1, t517, t358(SI25)
;;								## 36
	c0    brf $b0.1, L129?3   ## bblock 26, line 468-2,  t674(I1)
;;								## 37
	c0    sxth $r0.4 = $r0.9   ## bblock 23, line 469-2,  t269(SI16),  t338(SI25)
;;								## 38
	c0    mov $r0.2 = $r0.12   ## bblock 23, line 469-1,  t310(SI16),  t357(SI16)
;;								## 39
	c0    add $r0.6 = $r0.6, -3   ## bblock 23, line 468-2,  t327,  t327,  -3(SI32)
;;								## 40
	c0    add $r0.8 = $r0.8, (~0x189b)   ## bblock 23, line 0,  t518,  t518,  (~0x189b)(I32)
;;								## 41
	c0    sth 0[$r0.7] = $r0.9   ## bblock 23, line 469-2, t517, t338(SI25)
;;								## 42
	c0    add $r0.7 = $r0.7, (~0x5)   ## bblock 23, line 0,  t517,  t517,  (~0x5)(I32)
	      ## goto
;;
	c0    goto L128?3 ## goto
;;								## 43
.trace 14
L129?3:
	c0    sub $r0.3 = 1, $r0.18   ## bblock 7, line 0,  t460,  1(I32),  t209
;;								## 0
	c0    mov $r0.8 = $r0.3   ## bblock 7, line 0,  t459,  t460
;;								## 1
	c0    mov $r0.9 = $r0.22   ## bblock 7, line 0,  t458,  t570
;;								## 2
	c0    mov $r0.7 = (s_by2 + 0)   ## bblock 7, line 0,  t457,  addr(s_by2?1.0)(P32)
;;								## 3
	c0    mov $r0.10 = (s_by1 + 0)   ## bblock 7, line 0,  t456,  addr(s_by1?1.0)(P32)
;;								## 4
	c0    mov $r0.2 = $r0.23   ## bblock 7, line 0,  t455,  t569
;;								## 5
	c0    mov $r0.4 = $r0.20   ## t270(SI16)
;;								## 6
	c0    mov $r0.5 = $r0.19   ## t272(SI16)
;;								## 7
	c0    mov $r0.6 = $r0.21   ## t239(SI16)
;;								## 8
	c0    mov $r0.11 = 2100   ## 2100(I32)
;;								## 9
	c0    mov $r0.19 = $r0.17   ## t573
;;								## 10
	c0    mov $r0.21 = $r0.18   ## t209
;;								## 11
	c0    mov $r0.18 = $r0.16   ## t275
;;								## 12
	c0    mov $r0.20 = $r0.15   ## t574
;;								## 13
.trace 3
L130?3:
	c0    ldh.d $r0.3 = 0[$r0.2]   ## [spec] bblock 10, line 476, t348(SI16), t455
;;								## 0
	c0    mpyl $r0.4 = $r0.4, -77   ## [spec] bblock 10, line 476,  t351,  t270(SI16),  -77(SI32)
;;								## 1
	c0    mpyl $r0.12 = $r0.5, 107   ## [spec] bblock 10, line 476,  t362,  t272(SI16),  107(SI32)
;;								## 2
	c0    mpyl $r0.13 = $r0.3, -24   ## [spec] bblock 10, line 476,  t347,  t348(SI16),  -24(SI32)
;;								## 3
	c0    mpyl $r0.6 = $r0.6, 14   ## [spec] bblock 10, line 476,  t361,  t239(SI16),  14(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.13   ## [spec] bblock 10, line 476,  t659,  t351,  t347
;;								## 5
	c0    add $r0.12 = $r0.12, $r0.6   ## [spec] bblock 10, line 476,  t660,  t362,  t361
;;								## 6
	c0    add $r0.4 = $r0.4, $r0.12   ## [spec] bblock 10, line 476,  t360,  t659,  t660
;;								## 7
	c0    shr $r0.4 = $r0.4, 7   ## [spec] bblock 10, line 476,  t359(SI25),  t360,  7(SI32)
;;								## 8
	c0    sxth $r0.12 = $r0.4   ## [spec] bblock 10, line 476,  t346(SI16),  t359(SI25)
;;								## 9
	c0    ldh.d $r0.13 = 0[$r0.7]   ## [spec] bblock 10, line 480, t345(SI16), t457
;;								## 10
	c0    cmplt $b0.0 = $r0.8, 1   ## bblock 8, line 475,  t658(I1),  t459,  1(SI32)
;;								## 11
	c0    cmplt $b0.1 = $r0.8, $r0.0   ## [spec] bblock 12, line 475-1,  t662(I1),  t459,  0(SI32)
;;								## 12
	c0    add $r0.13 = $r0.12, $r0.13   ## [spec] bblock 10, line 480,  t344,  t346(SI16),  t345(SI16)
;;								## 13
	c0    shl $r0.13 = $r0.13, 7   ## [spec] bblock 10, line 480,  t343,  t344,  7(I32)
;;								## 14
	c0    shr $r0.13 = $r0.13, 14   ## [spec] bblock 10, line 480,  t342(SI18),  t343,  14(SI32)
;;								## 15
	c0    brf $b0.0, L131?3   ## bblock 8, line 475,  t658(I1)
;;								## 16
	c0    zxtb $r0.14 = $r0.13   ## bblock 10, line 480,  t341(I8),  t342(SI18)
;;								## 17
	c0    cmpgt $b0.0 = $r0.14, 25   ## bblock 10, line 481,  t661(I1),  t341(I8),  25(SI32)
;;								## 18
	c0    ldh.d $r0.6 = 2100[$r0.2]   ## [spec] bblock 30, line 476-1, t239(SI16), t455
;;								## 19
	c0    mpyl $r0.14 = $r0.5, -77   ## [spec] bblock 30, line 476-1,  t146,  t272(SI16),  -77(SI32)
;;								## 20
	c0    mpyl $r0.15 = $r0.12, 107   ## [spec] bblock 30, line 476-1,  t149,  t346(SI16),  107(SI32)
;;								## 21
	c0    mpyl $r0.16 = $r0.6, -24   ## [spec] bblock 30, line 476-1,  t158,  t239(SI16),  -24(SI32)
;;								## 22
	c0    mpyl $r0.17 = $r0.3, 14   ## [spec] bblock 30, line 476-1,  t152,  t348(SI16),  14(SI32)
;;								## 23
	c0    add $r0.14 = $r0.14, $r0.16   ## [spec] bblock 30, line 476-1,  t675,  t146,  t158
;;								## 24
	c0    add $r0.15 = $r0.15, $r0.17   ## [spec] bblock 30, line 476-1,  t676,  t149,  t152
;;								## 25
	c0    add $r0.14 = $r0.14, $r0.15   ## [spec] bblock 30, line 476-1,  t159,  t675,  t676
;;								## 26
	c0    shr $r0.14 = $r0.14, 7   ## [spec] bblock 30, line 476-1,  t160(SI25),  t159,  7(SI32)
;;								## 27
	c0    ldh.d $r0.15 = 2[$r0.7]   ## [spec] bblock 30, line 480-1, t174(SI16), t457
;;								## 28
	c0    sth 0[$r0.10] = $r0.4   ## bblock 10, line 476, t456, t359(SI25)
;;								## 29
	c0    mov $r0.4 = $r0.12   ## [spec] bblock 30, line 476-1,  t270(SI16),  t346(SI16)
;;								## 30
	c0    stb 0[$r0.9] = $r0.13   ## bblock 10, line 480, t458, t342(SI18)
;;								## 31
	c0    brf $b0.0, L132?3   ## bblock 10, line 481,  t661(I1)
;;								## 32
	c0    sxth $r0.5 = $r0.14   ## [spec] bblock 30, line 476-1,  t272(SI16),  t160(SI25)
;;								## 33
	c0    add $r0.15 = $r0.5, $r0.15   ## [spec] bblock 30, line 480-1,  t178,  t272(SI16),  t174(SI16)
;;								## 34
	c0    shl $r0.15 = $r0.15, 7   ## [spec] bblock 30, line 480-1,  t180,  t178,  7(I32)
;;								## 35
	c0    shr $r0.15 = $r0.15, 14   ## [spec] bblock 30, line 480-1,  t181(SI18),  t180,  14(SI32)
;;								## 36
	c0    zxtb $r0.3 = $r0.15   ## [spec] bblock 30, line 480-1,  t189(I8),  t181(SI18)
;;								## 37
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 30, line 481-1,  t677(I1),  t189(I8),  25(SI32)
;;								## 38
	c0    stb 0[$r0.9] = $r0.0   ## bblock 13, line 482, t458, 0(I32)
;;								## 39
L133?3:
	c0    brf $b0.1, L131?3   ## bblock 12, line 475-1,  t662(I1)
;;								## 40
	c0    sth 2[$r0.10] = $r0.14   ## bblock 30, line 476-1, t456, t160(SI25)
;;								## 41
	c0    stb 1050[$r0.9] = $r0.15   ## bblock 30, line 480-1, t458, t181(SI18)
;;								## 42
	c0    brf $b0.0, L134?3   ## bblock 30, line 481-1,  t677(I1)
;;								## 43
	c0    add $r0.2 = $r0.2, 4200   ## bblock 32, line 0,  t455,  t455,  4200(I32)
;;								## 44
	c0    add $r0.10 = $r0.10, 4   ## bblock 32, line 0,  t456,  t456,  4(I32)
;;								## 45
	c0    add $r0.7 = $r0.7, 4   ## bblock 32, line 0,  t457,  t457,  4(I32)
;;								## 46
	c0    add $r0.8 = $r0.8, 2   ## bblock 32, line 0,  t459,  t459,  2(I32)
;;								## 47
	c0    stb 1050[$r0.9] = $r0.0   ## bblock 33, line 482-1, t458, 0(I32)
;;								## 48
L135?3:
	c0    add $r0.9 = $r0.9, $r0.11   ## bblock 32, line 0,  t458,  t458,  2100(I32)
	      ## goto
;;
	c0    goto L130?3 ## goto
;;								## 49
.trace 10
L134?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.8 = $r0.8, 2   ## bblock 32, line 0,  t459,  t459,  2(I32)
;;								## 1
	c0    add $r0.7 = $r0.7, 4   ## bblock 32, line 0,  t457,  t457,  4(I32)
;;								## 2
	c0    add $r0.10 = $r0.10, 4   ## bblock 32, line 0,  t456,  t456,  4(I32)
;;								## 3
	c0    add $r0.2 = $r0.2, 4200   ## bblock 32, line 0,  t455,  t455,  4200(I32)
;;								## 4
	c0    stb 1050[$r0.9] = $r0.3   ## bblock 31, line 484-1, t458, 255(I32)
	      ## goto
;;
	c0    goto L135?3 ## goto
;;								## 5
.trace 15
L131?3:
	c0    add $r0.23 = $r0.23, 2   ## bblock 9, line 0,  t569,  t569,  2(I32)
;;								## 0
	c0    add $r0.22 = $r0.22, 1   ## bblock 9, line 0,  t570,  t570,  1(I32)
;;								## 1
	c0    add $r0.11 = $r0.19, 2   ## bblock 9, line 0,  t573,  t573,  2(I32)
;;								## 2
	c0    add $r0.9 = $r0.20, 1   ## bblock 9, line 0,  t574,  t574,  1(I32)
;;								## 3
	c0    mov $r0.10 = $r0.18   ## t275
;;								## 4
	c0    mov $r0.12 = $r0.21   ## t209
	      ## goto
;;
	c0    goto L126?3 ## goto
;;								## 5
.trace 9
L132?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    sxth $r0.5 = $r0.14   ## [spec] bblock 30, line 476-1,  t272(SI16),  t160(SI25)
;;								## 1
	c0    add $r0.15 = $r0.5, $r0.15   ## [spec] bblock 30, line 480-1,  t178,  t272(SI16),  t174(SI16)
;;								## 2
	c0    shl $r0.15 = $r0.15, 7   ## [spec] bblock 30, line 480-1,  t180,  t178,  7(I32)
;;								## 3
	c0    shr $r0.15 = $r0.15, 14   ## [spec] bblock 30, line 480-1,  t181(SI18),  t180,  14(SI32)
;;								## 4
	c0    zxtb $r0.12 = $r0.15   ## [spec] bblock 30, line 480-1,  t189(I8),  t181(SI18)
;;								## 5
	c0    cmpgt $b0.0 = $r0.12, 25   ## [spec] bblock 30, line 481-1,  t677(I1),  t189(I8),  25(SI32)
;;								## 6
	c0    stb 0[$r0.9] = $r0.3   ## bblock 11, line 484, t458, 255(I32)
	      ## goto
;;
	c0    goto L133?3 ## goto
;;								## 7
.trace 25
L127?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 4, line 488,  t197,  ?2.6?2auto_size(I32),  t196
;;								## 0
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.6?2auto_size, 0x0
 ## End deriche_simd
.section .bss
.section .data
.section .data
.import out
.type out,@object
.import in
.type in,@object
.comm s_at, 0x3010b0, 4
.comm s_by2, 0xbb8, 4
.comm s_by1, 0xbb8, 4
.comm s_ay2, 0x834, 4
.comm s_ay1, 0x834, 4
.comm at, 0x602160, 4
.comm ay2, 0x1068, 4
.comm ay1, 0x1068, 4
.comm qt, 0x602160, 4
.comm qy2, 0x602160, 4
.comm qy1, 0x602160, 4
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
