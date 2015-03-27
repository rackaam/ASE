 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /opt/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./risc.mm -DVEX -o edge_detect"
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 1, line 39,  t579(I1),  t558,  0(SI32)
;;								## 0
	c0    stw 0x60[$r0.1] = $r0.3  ## spill ## t223
;;								## 1
	c0    stw 0x64[$r0.1] = $r0.4  ## spill ## t557
;;								## 2
	c0    stw 0x68[$r0.1] = $r0.5  ## spill ## t555
;;								## 3
	c0    brf $b0.0, L1?3   ## bblock 1, line 39,  t579(I1)
;;								## 4
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 36, line 0,  t315,  0(I32),  t223
;;								## 5
	c0    mov $r0.57 = $r0.3   ## bblock 36, line 0,  t314,  t315
;;								## 6
	c0    mov $r0.62 = $r0.4   ## bblock 36, line 0,  t313,  t557
;;								## 7
	c0    mov $r0.61 = $r0.5   ## bblock 36, line 0,  t312,  t555
;;								## 8
	c0    mov $r0.60 = $r0.0   ## bblock 36, line 40,  t246,  0.000000e+00=0x0(F32)
;;								## 9
	c0    mov $r0.59 = $r0.0   ## bblock 36, line 40,  t244,  0.000000e+00=0x0(F32)
;;								## 10
	c0    mov $r0.58 = $r0.0   ## bblock 36, line 40,  t243,  0.000000e+00=0x0(F32)
;;								## 11
	c0    mov $r0.63 = $r0.2   ## t558
;;								## 12
.trace 3
L2?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 37, line 41,  t603(I1),  t314,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L3?3   ## bblock 37, line 41,  t603(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t243
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 42,  raddr(_r_mul)(P32),  t243,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x28[$r0.1] = $r0.3  ## spill ## t10
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 39, line 42,  t243,  t244
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t244
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 42,  raddr(_r_mul)(P32),  t244,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x2c[$r0.1] = $r0.3  ## spill ## t13
;;								## 10
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t246
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 42,  raddr(_r_mul)(P32),  t246,  1.102090e-01=0x3de1b542(F32)
;;								## 13
	c0    stw 0x30[$r0.1] = $r0.3  ## spill ## t16
;;								## 14
	c0    ldbu $r0.59 = 0[$r0.61]   ## bblock 39, line 42, t31(I8), t312
	      xnop 2
;;								## 17
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 18
.call _r_ilfloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ilfloat   ## bblock 39, line 42,  raddr(_r_ilfloat)(P32),  t31(I8)
;;								## 19
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
;;								## 20
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 42,  raddr(_r_mul)(P32),  t21,  -1.886820e-01=0xbe4135db(F32)
;;								## 21
	c0    stw 0x34[$r0.1] = $r0.3  ## spill ## t23
;;								## 22
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t10
;;								## 23
	c0    ldw $r0.4 = 0x2c[$r0.1]  ## restore ## t13
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 42,  raddr(_r_add)(P32),  t10,  t13
;;								## 26
	c0    ldw $r0.4 = 0x30[$r0.1]  ## restore ## t16
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 42,  raddr(_r_add)(P32),  t207,  t16
;;								## 29
	c0    ldw $r0.4 = 0x34[$r0.1]  ## restore ## t23
	      xnop 1
;;								## 31
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 42,  raddr(_r_add)(P32),  t208,  t23
;;								## 32
	c0    stw 0x38[$r0.1] = $r0.3  ## spill ## t244
;;								## 33
	c0    stw 0[$r0.62] = $r0.3   ## bblock 39, line 42, t313, t244
;;								## 34
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 35
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ufloat   ## bblock 39, line 43,  raddr(_r_ufloat)(P32),  t31(I8)
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
	c0    add $r0.5 = $r0.3, -1   ## bblock 2, line 52,  t309,  t223,  -1(SI32)
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 3, line 50,  t580(I1),  t533,  0(SI32)
;;								## 4
	c0    add $r0.62 = $r0.4, $r0.5   ## [spec] bblock 32, line 0,  t335,  t532,  t309
;;								## 5
	c0    brf $b0.0, L5?3   ## bblock 3, line 50,  t580(I1)
;;								## 6
	c0    sh2add $r0.63 = $r0.5, $r0.6   ## bblock 32, line 0,  t334,  t309,  t531
;;								## 7
	c0    mov $r0.61 = $r0.0   ## bblock 32, line 51,  t242,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.60 = $r0.0   ## bblock 32, line 51,  t241,  0.000000e+00=0x0(F32)
;;								## 9
	c0    mov $r0.59 = $r0.0   ## bblock 32, line 51,  t238,  0.000000e+00=0x0(F32)
;;								## 10
	c0    mov $r0.58 = $r0.0   ## bblock 32, line 51,  t237,  0.000000e+00=0x0(F32)
;;								## 11
	c0    mov $r0.57 = $r0.5   ## bblock 32, line 52,  t297,  t309
;;								## 12
.trace 2
L6?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 33, line 52,  t602(I1),  t297,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L7?3   ## bblock 33, line 52,  t602(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t237
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 53,  raddr(_r_mul)(P32),  t237,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x14[$r0.1] = $r0.3  ## spill ## t49
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 35, line 53,  t237,  t238
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t238
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 53,  raddr(_r_mul)(P32),  t238,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x18[$r0.1] = $r0.3  ## spill ## t52
;;								## 10
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t241
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 53,  raddr(_r_mul)(P32),  t241,  -1.886820e-01=0xbe4135db(F32)
;;								## 13
	c0    stw 0x1c[$r0.1] = $r0.3  ## spill ## t55
;;								## 14
	c0    mov $r0.60 = $r0.61   ## bblock 35, line 53,  t241,  t242
;;								## 15
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
;;								## 16
	c0    mov $r0.3 = $r0.61   ## t242
;;								## 17
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 53,  raddr(_r_mul)(P32),  t242,  -1.836820e-01=0xbe3c1722(F32)
;;								## 18
	c0    stw 0x20[$r0.1] = $r0.3  ## spill ## t58
;;								## 19
	c0    ldw $r0.3 = 0x14[$r0.1]  ## restore ## t49
;;								## 20
	c0    ldw $r0.4 = 0x18[$r0.1]  ## restore ## t52
	      xnop 1
;;								## 22
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 53,  raddr(_r_add)(P32),  t49,  t52
;;								## 23
	c0    ldw $r0.4 = 0x1c[$r0.1]  ## restore ## t55
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 53,  raddr(_r_add)(P32),  t205,  t55
;;								## 26
	c0    ldw $r0.4 = 0x20[$r0.1]  ## restore ## t58
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 53,  raddr(_r_add)(P32),  t206,  t58
;;								## 29
	c0    stw 0x24[$r0.1] = $r0.3  ## spill ## t238
;;								## 30
	c0    ldbu $r0.2 = 0[$r0.62]   ## bblock 35, line 55, t67(I8), t335
;;								## 31
	c0    stw 0[$r0.63] = $r0.3   ## bblock 35, line 53, t334, t238
	      xnop 1
;;								## 33
	c0    mov $r0.3 = $r0.2   ## t67(I8)
;;								## 34
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ufloat   ## bblock 35, line 55,  raddr(_r_ufloat)(P32),  t67(I8)
;;								## 35
	c0    add $r0.57 = $r0.57, -1   ## bblock 35, line 52,  t297,  t297,  -1(SI32)
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 5, line 62,  t581(I1),  t503,  0(SI32)
;;								## 0
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 28, line 0,  t358,  0(I32),  t223
;;								## 1
	c0    brf $b0.0, L9?3   ## bblock 5, line 62,  t581(I1)
;;								## 2
	c0    mov $r0.60 = $r0.4   ## bblock 28, line 0,  t357,  t358
;;								## 3
	c0    mov $r0.57 = $r0.0   ## bblock 28, line 63,  t299,  0(SI32)
;;								## 4
	c0    mov $r0.62 = $r0.2   ## t503
;;								## 5
	c0    mov $r0.63 = $r0.3   ## t223
;;								## 6
.trace 1
L10?3:
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 31, line 64,  t599,  t299,  t502
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 31, line 64, t85, t599
;;								## 1
	c0    sh2add $r0.2 = $r0.57, $r0.59   ## [spec] bblock 31, line 64,  t600,  t299,  t501
;;								## 2
	c0    ldw.d $r0.4 = 0[$r0.2]   ## [spec] bblock 31, line 64, t89, t600
;;								## 3
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 29, line 63,  t598(I1),  t357,  0(SI32)
	      xnop 1
;;								## 5
	c0    brf $b0.0, L11?3   ## bblock 29, line 63,  t598(I1)
;;								## 6
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 31, line 64,  raddr(_r_add)(P32),  t85,  t89
;;								## 7
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 31, line 64,  raddr(_r_mul)(P32),  t90,  1.000000e+00=0x3f800000(F32)
;;								## 9
	c0    sh2add $r0.2 = $r0.57, $r0.61   ## bblock 31, line 64,  t601,  t299,  t500
;;								## 10
	c0    add $r0.57 = $r0.57, 1   ## bblock 31, line 63,  t299,  t299,  1(SI32)
;;								## 11
	c0    add $r0.60 = $r0.60, 1   ## bblock 31, line 0,  t357,  t357,  1(I32)
;;								## 12
	c0    stw 0[$r0.2] = $r0.3   ## bblock 31, line 64, t601, t92
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 7, line 66,  t582(I1),  t480,  0(SI32)
;;								## 2
	c0    sub $r0.4 = $r0.0, $r0.4   ## [spec] bblock 24, line 0,  t373,  0(I32),  t222
;;								## 3
	c0    brf $b0.0, L13?3   ## bblock 7, line 66,  t582(I1)
;;								## 4
	c0    mov $r0.57 = $r0.4   ## bblock 24, line 0,  t372,  t373
;;								## 5
	c0    mov $r0.61 = $r0.0   ## bblock 24, line 0,  t367,  0(I32)
;;								## 6
	c0    mov $r0.60 = $r0.0   ## bblock 24, line 67,  t245,  0.000000e+00=0x0(F32)
;;								## 7
	c0    mov $r0.59 = $r0.0   ## bblock 24, line 67,  t302,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.58 = $r0.0   ## bblock 24, line 67,  t303,  0.000000e+00=0x0(F32)
;;								## 9
.trace 5
L14?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 25, line 68,  t595(I1),  t372,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L15?3   ## bblock 25, line 68,  t595(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t303
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 69,  raddr(_r_mul)(P32),  t303,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x3c[$r0.1] = $r0.3  ## spill ## t106
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 27, line 69,  t303,  t302
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t302
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 69,  raddr(_r_mul)(P32),  t302,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x40[$r0.1] = $r0.3  ## spill ## t109
;;								## 10
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t245
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 69,  raddr(_r_mul)(P32),  t245,  1.102090e-01=0x3de1b542(F32)
;;								## 13
	c0    stw 0x44[$r0.1] = $r0.3  ## spill ## t112
;;								## 14
	c0    sh3add $r0.2 = $r0.61, $r0.62   ## bblock 27, line 69,  t596,  t367,  t479
;;								## 15
	c0    ldw $r0.60 = 0[$r0.2]   ## bblock 27, line 69, t245, t596
;;								## 16
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
	      xnop 1
;;								## 18
	c0    mov $r0.3 = $r0.60   ## t245
;;								## 19
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 69,  raddr(_r_mul)(P32),  t245,  -1.886820e-01=0xbe4135db(F32)
;;								## 20
	c0    stw 0x48[$r0.1] = $r0.3  ## spill ## t118
;;								## 21
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t106
;;								## 22
	c0    ldw $r0.4 = 0x40[$r0.1]  ## restore ## t109
	      xnop 1
;;								## 24
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 69,  raddr(_r_add)(P32),  t106,  t109
;;								## 25
	c0    ldw $r0.4 = 0x44[$r0.1]  ## restore ## t112
	      xnop 1
;;								## 27
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 69,  raddr(_r_add)(P32),  t203,  t112
;;								## 28
	c0    ldw $r0.4 = 0x48[$r0.1]  ## restore ## t118
	      xnop 1
;;								## 30
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 69,  raddr(_r_add)(P32),  t204,  t118
;;								## 31
	c0    sh3add $r0.2 = $r0.61, $r0.63   ## bblock 27, line 69,  t597,  t367,  t478
;;								## 32
	c0    add $r0.61 = $r0.61, 525   ## bblock 27, line 0,  t367,  t367,  525(I32)
;;								## 33
	c0    add $r0.57 = $r0.57, 1   ## bblock 27, line 0,  t372,  t372,  1(I32)
;;								## 34
	c0    mov $r0.59 = $r0.3   ## t302
;;								## 35
	c0    stw 0[$r0.2] = $r0.3   ## bblock 27, line 69, t597, t302
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
	c0    add $r0.5 = $r0.4, -1   ## bblock 8, line 78,  t310,  t222,  -1(SI32)
;;								## 9
.trace 18
L16?3:
	c0    stw 0x84[$r0.1] = $r0.2  ## spill ## t459
;;								## 0
	c0    stw 0x88[$r0.1] = $r0.5  ## spill ## t310
;;								## 1
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 9, line 76,  t583(I1),  t459,  0(SI32)
;;								## 2
	c0    mpylu $r0.62 = $r0.5, 525   ## [spec] bblock 20, line 0,  t390,  t310,  525(I32)
;;								## 3
	c0    brf $b0.0, L17?3   ## bblock 9, line 76,  t583(I1)
;;								## 4
	c0    mov $r0.61 = $r0.0   ## bblock 20, line 77,  t240,  0.000000e+00=0x0(F32)
;;								## 5
	c0    mov $r0.60 = $r0.0   ## bblock 20, line 77,  t239,  0.000000e+00=0x0(F32)
;;								## 6
	c0    mov $r0.59 = $r0.0   ## bblock 20, line 77,  t306,  0.000000e+00=0x0(F32)
;;								## 7
	c0    mov $r0.58 = $r0.0   ## bblock 20, line 77,  t305,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.57 = $r0.5   ## bblock 20, line 78,  t307,  t310
;;								## 9
.trace 6
L18?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 21, line 78,  t592(I1),  t307,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L19?3   ## bblock 21, line 78,  t592(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t305
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 79,  raddr(_r_mul)(P32),  t305,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x50[$r0.1] = $r0.3  ## spill ## t143
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 23, line 79,  t305,  t306
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t306
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 79,  raddr(_r_mul)(P32),  t306,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x54[$r0.1] = $r0.3  ## spill ## t146
;;								## 10
	c0    mov $r0.4 = 0x3dea600b   ## 1.144410e-01=0x3dea600b(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t239
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 79,  raddr(_r_mul)(P32),  t239,  1.144410e-01=0x3dea600b(F32)
;;								## 13
	c0    stw 0x58[$r0.1] = $r0.3  ## spill ## t149
;;								## 14
	c0    mov $r0.60 = $r0.61   ## bblock 23, line 79,  t239,  t240
;;								## 15
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
;;								## 16
	c0    mov $r0.3 = $r0.61   ## t240
;;								## 17
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 79,  raddr(_r_mul)(P32),  t240,  -1.836820e-01=0xbe3c1722(F32)
;;								## 18
	c0    stw 0x5c[$r0.1] = $r0.3  ## spill ## t152
;;								## 19
	c0    ldw $r0.3 = 0x50[$r0.1]  ## restore ## t143
;;								## 20
	c0    ldw $r0.4 = 0x54[$r0.1]  ## restore ## t146
	      xnop 1
;;								## 22
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 79,  raddr(_r_add)(P32),  t143,  t146
;;								## 23
	c0    ldw $r0.4 = 0x58[$r0.1]  ## restore ## t149
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 79,  raddr(_r_add)(P32),  t201,  t149
;;								## 26
	c0    ldw $r0.4 = 0x5c[$r0.1]  ## restore ## t152
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 79,  raddr(_r_add)(P32),  t202,  t152
;;								## 29
	c0    sh3add $r0.4 = $r0.62, $r0.63   ## bblock 23, line 79,  t593,  t390,  t458
;;								## 30
	c0    ldw $r0.2 = 0x4c[$r0.1]  ## restore ## t457
;;								## 31
	c0    add $r0.57 = $r0.57, -1   ## bblock 23, line 78,  t307,  t307,  -1(SI32)
;;								## 32
	c0    mov $r0.59 = $r0.3   ## t306
;;								## 33
	c0    sh3add $r0.5 = $r0.62, $r0.2   ## bblock 23, line 81,  t594,  t390,  t457
;;								## 34
	c0    ldw $r0.61 = 0[$r0.5]   ## bblock 23, line 81, t240, t594
;;								## 35
	c0    add $r0.62 = $r0.62, (~0x20c)   ## bblock 23, line 0,  t390,  t390,  (~0x20c)(I32)
;;								## 36
	c0    stw 0[$r0.4] = $r0.3   ## bblock 23, line 79, t593, t306
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 11, line 87,  t584(I1),  t430,  0(SI32)
;;								## 0
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 13, line 0,  t415,  0(I32),  t223
;;								## 1
	c0    brf $b0.0, L21?3   ## bblock 11, line 87,  t584(I1)
;;								## 2
	c0    mov $r0.60 = $r0.4   ## bblock 13, line 0,  t414,  t415
;;								## 3
	c0    mov $r0.57 = $r0.0   ## bblock 13, line 88,  t308,  0(SI32)
;;								## 4
	c0    mov $r0.62 = $r0.2   ## t430
;;								## 5
	c0    mov $r0.63 = $r0.3   ## t223
;;								## 6
.trace 4
L22?3:
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 16, line 89,  t586,  t308,  t429
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 16, line 89, t178, t586
;;								## 1
	c0    sh2add $r0.5 = $r0.57, $r0.59   ## [spec] bblock 16, line 89,  t587,  t308,  t428
;;								## 2
	c0    ldw.d $r0.4 = 0[$r0.5]   ## [spec] bblock 16, line 89, t182, t587
;;								## 3
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 14, line 88,  t585(I1),  t414,  0(SI32)
	      xnop 1
;;								## 5
	c0    brf $b0.0, L23?3   ## bblock 14, line 88,  t585(I1)
;;								## 6
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 16, line 89,  raddr(_r_add)(P32),  t178,  t182
;;								## 7
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 16, line 89,  raddr(_r_mul)(P32),  t183,  1.000000e+00=0x3f800000(F32)
;;								## 9
.call _r_ufix, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = _r_ufix   ## bblock 16, line 89,  raddr(_r_ufix)(P32),  t185
;;								## 10
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 16, line 89,  t588,  t308,  t426
;;								## 11
	c0    zxtb $r0.4 = $r0.3   ## bblock 16, line 89,  t187(I8),  t186(I8)
;;								## 12
	c0    cmpgt $b0.0 = $r0.4, 25   ## bblock 16, line 90,  t589(I1),  t187(I8),  25(SI32)
;;								## 13
	c0    add $r0.5 = $r0.57, $r0.61   ## [spec] bblock 19, line 91,  t591,  t308,  t426
;;								## 14
	c0    stb 0[$r0.2] = $r0.3   ## bblock 16, line 89, t588, t186(I8)
;;								## 15
	c0    brf $b0.0, L24?3   ## bblock 16, line 90,  t589(I1)
;;								## 16
	c0    add $r0.57 = $r0.57, 1   ## bblock 18, line 88,  t308,  t308,  1(SI32)
;;								## 17
	c0    add $r0.60 = $r0.60, 1   ## bblock 18, line 0,  t414,  t414,  1(I32)
;;								## 18
	c0    stb 0[$r0.5] = $r0.0   ## bblock 19, line 91, t591, 0(I32)
	      ## goto
;;
	c0    goto L22?3 ## goto
;;								## 19
.trace 13
L24?3:
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 17, line 93,  t590,  t308,  t426
;;								## 0
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 1
	c0    add $r0.60 = $r0.60, 1   ## bblock 18, line 0,  t414,  t414,  1(I32)
;;								## 2
	c0    add $r0.57 = $r0.57, 1   ## bblock 18, line 88,  t308,  t308,  1(SI32)
;;								## 3
	c0    stb 0[$r0.2] = $r0.3   ## bblock 17, line 93, t590, 255(I32)
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
	c0    return $r0.1 = $r0.1, (0xc0), $l0.0   ## bblock 12, line 98,  t210,  ?2.1?2auto_size(I32),  t209
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
 ## Begin deriche_fused
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_fused::
.trace 1
	      ## auto_size == 0
;;								## 0
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 127,  t1,  ?2.2?2auto_size(I32),  t0
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.2?2auto_size, 0x0
 ## End deriche_fused
 ## Begin deriche_slow
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_slow::
.trace 1
	      ## auto_size == 0
;;								## 0
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 149,  t1,  ?2.3?2auto_size(I32),  t0
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.3?2auto_size, 0x0
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
