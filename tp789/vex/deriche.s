 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/matthias/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./risc.mm -DVEX -o edge_detect"
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 1, line 38,  t579(I1),  t558,  0(SI32)
;;								## 0
	c0    stw 0x60[$r0.1] = $r0.3  ## spill ## t223
;;								## 1
	c0    stw 0x64[$r0.1] = $r0.4  ## spill ## t557
;;								## 2
	c0    stw 0x68[$r0.1] = $r0.5  ## spill ## t555
;;								## 3
	c0    brf $b0.0, L1?3   ## bblock 1, line 38,  t579(I1)
;;								## 4
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 36, line 0,  t315,  0(I32),  t223
;;								## 5
	c0    mov $r0.57 = $r0.3   ## bblock 36, line 0,  t314,  t315
;;								## 6
	c0    mov $r0.62 = $r0.4   ## bblock 36, line 0,  t313,  t557
;;								## 7
	c0    mov $r0.61 = $r0.5   ## bblock 36, line 0,  t312,  t555
;;								## 8
	c0    mov $r0.60 = $r0.0   ## bblock 36, line 39,  t246,  0.000000e+00=0x0(F32)
;;								## 9
	c0    mov $r0.59 = $r0.0   ## bblock 36, line 39,  t244,  0.000000e+00=0x0(F32)
;;								## 10
	c0    mov $r0.58 = $r0.0   ## bblock 36, line 39,  t243,  0.000000e+00=0x0(F32)
;;								## 11
	c0    mov $r0.63 = $r0.2   ## t558
;;								## 12
.trace 3
L2?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 37, line 40,  t603(I1),  t314,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L3?3   ## bblock 37, line 40,  t603(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t243
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 41,  raddr(_r_mul)(P32),  t243,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x28[$r0.1] = $r0.3  ## spill ## t10
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 39, line 41,  t243,  t244
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t244
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 41,  raddr(_r_mul)(P32),  t244,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x2c[$r0.1] = $r0.3  ## spill ## t13
;;								## 10
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t246
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 41,  raddr(_r_mul)(P32),  t246,  1.102090e-01=0x3de1b542(F32)
;;								## 13
	c0    stw 0x30[$r0.1] = $r0.3  ## spill ## t16
;;								## 14
	c0    ldbu $r0.59 = 0[$r0.61]   ## bblock 39, line 41, t31(I8), t312
	      xnop 2
;;								## 17
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 18
.call _r_ilfloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ilfloat   ## bblock 39, line 41,  raddr(_r_ilfloat)(P32),  t31(I8)
;;								## 19
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
;;								## 20
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 39, line 41,  raddr(_r_mul)(P32),  t21,  -1.886820e-01=0xbe4135db(F32)
;;								## 21
	c0    stw 0x34[$r0.1] = $r0.3  ## spill ## t23
;;								## 22
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t10
;;								## 23
	c0    ldw $r0.4 = 0x2c[$r0.1]  ## restore ## t13
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 41,  raddr(_r_add)(P32),  t10,  t13
;;								## 26
	c0    ldw $r0.4 = 0x30[$r0.1]  ## restore ## t16
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 41,  raddr(_r_add)(P32),  t207,  t16
;;								## 29
	c0    ldw $r0.4 = 0x34[$r0.1]  ## restore ## t23
	      xnop 1
;;								## 31
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 39, line 41,  raddr(_r_add)(P32),  t208,  t23
;;								## 32
	c0    stw 0x38[$r0.1] = $r0.3  ## spill ## t244
;;								## 33
	c0    stw 0[$r0.62] = $r0.3   ## bblock 39, line 41, t313, t244
;;								## 34
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 35
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ufloat   ## bblock 39, line 42,  raddr(_r_ufloat)(P32),  t31(I8)
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
	c0    add $r0.5 = $r0.3, -1   ## bblock 2, line 56,  t309,  t223,  -1(SI32)
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 3, line 54,  t580(I1),  t533,  0(SI32)
;;								## 4
	c0    add $r0.62 = $r0.4, $r0.5   ## [spec] bblock 32, line 0,  t335,  t532,  t309
;;								## 5
	c0    brf $b0.0, L5?3   ## bblock 3, line 54,  t580(I1)
;;								## 6
	c0    sh2add $r0.63 = $r0.5, $r0.6   ## bblock 32, line 0,  t334,  t309,  t531
;;								## 7
	c0    mov $r0.61 = $r0.0   ## bblock 32, line 55,  t242,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.60 = $r0.0   ## bblock 32, line 55,  t241,  0.000000e+00=0x0(F32)
;;								## 9
	c0    mov $r0.59 = $r0.0   ## bblock 32, line 55,  t238,  0.000000e+00=0x0(F32)
;;								## 10
	c0    mov $r0.58 = $r0.0   ## bblock 32, line 55,  t237,  0.000000e+00=0x0(F32)
;;								## 11
	c0    mov $r0.57 = $r0.5   ## bblock 32, line 56,  t297,  t309
;;								## 12
.trace 2
L6?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 33, line 56,  t602(I1),  t297,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L7?3   ## bblock 33, line 56,  t602(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t237
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 57,  raddr(_r_mul)(P32),  t237,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x14[$r0.1] = $r0.3  ## spill ## t49
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 35, line 57,  t237,  t238
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t238
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 57,  raddr(_r_mul)(P32),  t238,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x18[$r0.1] = $r0.3  ## spill ## t52
;;								## 10
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t241
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 57,  raddr(_r_mul)(P32),  t241,  -1.886820e-01=0xbe4135db(F32)
;;								## 13
	c0    stw 0x1c[$r0.1] = $r0.3  ## spill ## t55
;;								## 14
	c0    mov $r0.60 = $r0.61   ## bblock 35, line 57,  t241,  t242
;;								## 15
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
;;								## 16
	c0    mov $r0.3 = $r0.61   ## t242
;;								## 17
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 35, line 57,  raddr(_r_mul)(P32),  t242,  -1.836820e-01=0xbe3c1722(F32)
;;								## 18
	c0    stw 0x20[$r0.1] = $r0.3  ## spill ## t58
;;								## 19
	c0    ldw $r0.3 = 0x14[$r0.1]  ## restore ## t49
;;								## 20
	c0    ldw $r0.4 = 0x18[$r0.1]  ## restore ## t52
	      xnop 1
;;								## 22
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 57,  raddr(_r_add)(P32),  t49,  t52
;;								## 23
	c0    ldw $r0.4 = 0x1c[$r0.1]  ## restore ## t55
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 57,  raddr(_r_add)(P32),  t205,  t55
;;								## 26
	c0    ldw $r0.4 = 0x20[$r0.1]  ## restore ## t58
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 35, line 57,  raddr(_r_add)(P32),  t206,  t58
;;								## 29
	c0    stw 0x24[$r0.1] = $r0.3  ## spill ## t238
;;								## 30
	c0    ldbu $r0.2 = 0[$r0.62]   ## bblock 35, line 59, t67(I8), t335
;;								## 31
	c0    stw 0[$r0.63] = $r0.3   ## bblock 35, line 57, t334, t238
	      xnop 1
;;								## 33
	c0    mov $r0.3 = $r0.2   ## t67(I8)
;;								## 34
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ufloat   ## bblock 35, line 59,  raddr(_r_ufloat)(P32),  t67(I8)
;;								## 35
	c0    add $r0.57 = $r0.57, -1   ## bblock 35, line 56,  t297,  t297,  -1(SI32)
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 5, line 71,  t581(I1),  t503,  0(SI32)
;;								## 0
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 28, line 0,  t358,  0(I32),  t223
;;								## 1
	c0    brf $b0.0, L9?3   ## bblock 5, line 71,  t581(I1)
;;								## 2
	c0    mov $r0.60 = $r0.4   ## bblock 28, line 0,  t357,  t358
;;								## 3
	c0    mov $r0.57 = $r0.0   ## bblock 28, line 72,  t299,  0(SI32)
;;								## 4
	c0    mov $r0.62 = $r0.2   ## t503
;;								## 5
	c0    mov $r0.63 = $r0.3   ## t223
;;								## 6
.trace 1
L10?3:
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 31, line 73,  t599,  t299,  t502
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 31, line 73, t85, t599
;;								## 1
	c0    sh2add $r0.2 = $r0.57, $r0.59   ## [spec] bblock 31, line 73,  t600,  t299,  t501
;;								## 2
	c0    ldw.d $r0.4 = 0[$r0.2]   ## [spec] bblock 31, line 73, t89, t600
;;								## 3
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 29, line 72,  t598(I1),  t357,  0(SI32)
	      xnop 1
;;								## 5
	c0    brf $b0.0, L11?3   ## bblock 29, line 72,  t598(I1)
;;								## 6
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 31, line 73,  raddr(_r_add)(P32),  t85,  t89
;;								## 7
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 31, line 73,  raddr(_r_mul)(P32),  t90,  1.000000e+00=0x3f800000(F32)
;;								## 9
	c0    sh2add $r0.2 = $r0.57, $r0.61   ## bblock 31, line 73,  t601,  t299,  t500
;;								## 10
	c0    add $r0.57 = $r0.57, 1   ## bblock 31, line 72,  t299,  t299,  1(SI32)
;;								## 11
	c0    add $r0.60 = $r0.60, 1   ## bblock 31, line 0,  t357,  t357,  1(I32)
;;								## 12
	c0    stw 0[$r0.2] = $r0.3   ## bblock 31, line 73, t601, t92
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 7, line 82,  t582(I1),  t480,  0(SI32)
;;								## 2
	c0    sub $r0.4 = $r0.0, $r0.4   ## [spec] bblock 24, line 0,  t373,  0(I32),  t222
;;								## 3
	c0    brf $b0.0, L13?3   ## bblock 7, line 82,  t582(I1)
;;								## 4
	c0    mov $r0.57 = $r0.4   ## bblock 24, line 0,  t372,  t373
;;								## 5
	c0    mov $r0.61 = $r0.0   ## bblock 24, line 0,  t367,  0(I32)
;;								## 6
	c0    mov $r0.60 = $r0.0   ## bblock 24, line 83,  t245,  0.000000e+00=0x0(F32)
;;								## 7
	c0    mov $r0.59 = $r0.0   ## bblock 24, line 83,  t302,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.58 = $r0.0   ## bblock 24, line 83,  t303,  0.000000e+00=0x0(F32)
;;								## 9
.trace 5
L14?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 25, line 84,  t595(I1),  t372,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L15?3   ## bblock 25, line 84,  t595(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t303
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 85,  raddr(_r_mul)(P32),  t303,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x3c[$r0.1] = $r0.3  ## spill ## t106
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 27, line 85,  t303,  t302
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t302
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 85,  raddr(_r_mul)(P32),  t302,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x40[$r0.1] = $r0.3  ## spill ## t109
;;								## 10
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t245
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 85,  raddr(_r_mul)(P32),  t245,  1.102090e-01=0x3de1b542(F32)
;;								## 13
	c0    stw 0x44[$r0.1] = $r0.3  ## spill ## t112
;;								## 14
	c0    sh3add $r0.2 = $r0.61, $r0.62   ## bblock 27, line 85,  t596,  t367,  t479
;;								## 15
	c0    ldw $r0.60 = 0[$r0.2]   ## bblock 27, line 85, t245, t596
;;								## 16
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
	      xnop 1
;;								## 18
	c0    mov $r0.3 = $r0.60   ## t245
;;								## 19
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 27, line 85,  raddr(_r_mul)(P32),  t245,  -1.886820e-01=0xbe4135db(F32)
;;								## 20
	c0    stw 0x48[$r0.1] = $r0.3  ## spill ## t118
;;								## 21
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t106
;;								## 22
	c0    ldw $r0.4 = 0x40[$r0.1]  ## restore ## t109
	      xnop 1
;;								## 24
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 85,  raddr(_r_add)(P32),  t106,  t109
;;								## 25
	c0    ldw $r0.4 = 0x44[$r0.1]  ## restore ## t112
	      xnop 1
;;								## 27
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 85,  raddr(_r_add)(P32),  t203,  t112
;;								## 28
	c0    ldw $r0.4 = 0x48[$r0.1]  ## restore ## t118
	      xnop 1
;;								## 30
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 27, line 85,  raddr(_r_add)(P32),  t204,  t118
;;								## 31
	c0    sh3add $r0.2 = $r0.61, $r0.63   ## bblock 27, line 85,  t597,  t367,  t478
;;								## 32
	c0    add $r0.61 = $r0.61, 525   ## bblock 27, line 0,  t367,  t367,  525(I32)
;;								## 33
	c0    add $r0.57 = $r0.57, 1   ## bblock 27, line 0,  t372,  t372,  1(I32)
;;								## 34
	c0    mov $r0.59 = $r0.3   ## t302
;;								## 35
	c0    stw 0[$r0.2] = $r0.3   ## bblock 27, line 85, t597, t302
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
	c0    add $r0.5 = $r0.4, -1   ## bblock 8, line 100,  t310,  t222,  -1(SI32)
;;								## 9
.trace 18
L16?3:
	c0    stw 0x84[$r0.1] = $r0.2  ## spill ## t459
;;								## 0
	c0    stw 0x88[$r0.1] = $r0.5  ## spill ## t310
;;								## 1
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 9, line 98,  t583(I1),  t459,  0(SI32)
;;								## 2
	c0    mpylu $r0.62 = $r0.5, 525   ## [spec] bblock 20, line 0,  t390,  t310,  525(I32)
;;								## 3
	c0    brf $b0.0, L17?3   ## bblock 9, line 98,  t583(I1)
;;								## 4
	c0    mov $r0.61 = $r0.0   ## bblock 20, line 99,  t240,  0.000000e+00=0x0(F32)
;;								## 5
	c0    mov $r0.60 = $r0.0   ## bblock 20, line 99,  t239,  0.000000e+00=0x0(F32)
;;								## 6
	c0    mov $r0.59 = $r0.0   ## bblock 20, line 99,  t306,  0.000000e+00=0x0(F32)
;;								## 7
	c0    mov $r0.58 = $r0.0   ## bblock 20, line 99,  t305,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.57 = $r0.5   ## bblock 20, line 100,  t307,  t310
;;								## 9
.trace 6
L18?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 21, line 100,  t592(I1),  t307,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L19?3   ## bblock 21, line 100,  t592(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t305
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 101,  raddr(_r_mul)(P32),  t305,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x50[$r0.1] = $r0.3  ## spill ## t143
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 23, line 101,  t305,  t306
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t306
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 101,  raddr(_r_mul)(P32),  t306,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x54[$r0.1] = $r0.3  ## spill ## t146
;;								## 10
	c0    mov $r0.4 = 0x3dea600b   ## 1.144410e-01=0x3dea600b(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t239
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 101,  raddr(_r_mul)(P32),  t239,  1.144410e-01=0x3dea600b(F32)
;;								## 13
	c0    stw 0x58[$r0.1] = $r0.3  ## spill ## t149
;;								## 14
	c0    mov $r0.60 = $r0.61   ## bblock 23, line 101,  t239,  t240
;;								## 15
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
;;								## 16
	c0    mov $r0.3 = $r0.61   ## t240
;;								## 17
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 23, line 101,  raddr(_r_mul)(P32),  t240,  -1.836820e-01=0xbe3c1722(F32)
;;								## 18
	c0    stw 0x5c[$r0.1] = $r0.3  ## spill ## t152
;;								## 19
	c0    ldw $r0.3 = 0x50[$r0.1]  ## restore ## t143
;;								## 20
	c0    ldw $r0.4 = 0x54[$r0.1]  ## restore ## t146
	      xnop 1
;;								## 22
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 101,  raddr(_r_add)(P32),  t143,  t146
;;								## 23
	c0    ldw $r0.4 = 0x58[$r0.1]  ## restore ## t149
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 101,  raddr(_r_add)(P32),  t201,  t149
;;								## 26
	c0    ldw $r0.4 = 0x5c[$r0.1]  ## restore ## t152
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 23, line 101,  raddr(_r_add)(P32),  t202,  t152
;;								## 29
	c0    sh3add $r0.4 = $r0.62, $r0.63   ## bblock 23, line 101,  t593,  t390,  t458
;;								## 30
	c0    ldw $r0.2 = 0x4c[$r0.1]  ## restore ## t457
;;								## 31
	c0    add $r0.57 = $r0.57, -1   ## bblock 23, line 100,  t307,  t307,  -1(SI32)
;;								## 32
	c0    mov $r0.59 = $r0.3   ## t306
;;								## 33
	c0    sh3add $r0.5 = $r0.62, $r0.2   ## bblock 23, line 103,  t594,  t390,  t457
;;								## 34
	c0    ldw $r0.61 = 0[$r0.5]   ## bblock 23, line 103, t240, t594
;;								## 35
	c0    add $r0.62 = $r0.62, (~0x20c)   ## bblock 23, line 0,  t390,  t390,  (~0x20c)(I32)
;;								## 36
	c0    stw 0[$r0.4] = $r0.3   ## bblock 23, line 101, t593, t306
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
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 11, line 115,  t584(I1),  t430,  0(SI32)
;;								## 0
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 13, line 0,  t415,  0(I32),  t223
;;								## 1
	c0    brf $b0.0, L21?3   ## bblock 11, line 115,  t584(I1)
;;								## 2
	c0    mov $r0.60 = $r0.4   ## bblock 13, line 0,  t414,  t415
;;								## 3
	c0    mov $r0.57 = $r0.0   ## bblock 13, line 116,  t308,  0(SI32)
;;								## 4
	c0    mov $r0.62 = $r0.2   ## t430
;;								## 5
	c0    mov $r0.63 = $r0.3   ## t223
;;								## 6
.trace 4
L22?3:
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 16, line 117,  t586,  t308,  t429
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 16, line 117, t178, t586
;;								## 1
	c0    sh2add $r0.5 = $r0.57, $r0.59   ## [spec] bblock 16, line 117,  t587,  t308,  t428
;;								## 2
	c0    ldw.d $r0.4 = 0[$r0.5]   ## [spec] bblock 16, line 117, t182, t587
;;								## 3
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 14, line 116,  t585(I1),  t414,  0(SI32)
	      xnop 1
;;								## 5
	c0    brf $b0.0, L23?3   ## bblock 14, line 116,  t585(I1)
;;								## 6
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 16, line 117,  raddr(_r_add)(P32),  t178,  t182
;;								## 7
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 16, line 117,  raddr(_r_mul)(P32),  t183,  1.000000e+00=0x3f800000(F32)
;;								## 9
.call _r_ufix, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = _r_ufix   ## bblock 16, line 117,  raddr(_r_ufix)(P32),  t185
;;								## 10
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 16, line 117,  t588,  t308,  t426
;;								## 11
	c0    zxtb $r0.4 = $r0.3   ## bblock 16, line 117,  t187(I8),  t186(I8)
;;								## 12
	c0    cmpgt $b0.0 = $r0.4, 25   ## bblock 16, line 118,  t589(I1),  t187(I8),  25(SI32)
;;								## 13
	c0    add $r0.5 = $r0.57, $r0.61   ## [spec] bblock 19, line 119,  t591,  t308,  t426
;;								## 14
	c0    stb 0[$r0.2] = $r0.3   ## bblock 16, line 117, t588, t186(I8)
;;								## 15
	c0    brf $b0.0, L24?3   ## bblock 16, line 118,  t589(I1)
;;								## 16
	c0    add $r0.57 = $r0.57, 1   ## bblock 18, line 116,  t308,  t308,  1(SI32)
;;								## 17
	c0    add $r0.60 = $r0.60, 1   ## bblock 18, line 0,  t414,  t414,  1(I32)
;;								## 18
	c0    stb 0[$r0.5] = $r0.0   ## bblock 19, line 119, t591, 0(I32)
	      ## goto
;;
	c0    goto L22?3 ## goto
;;								## 19
.trace 13
L24?3:
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 17, line 121,  t590,  t308,  t426
;;								## 0
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 1
	c0    add $r0.60 = $r0.60, 1   ## bblock 18, line 0,  t414,  t414,  1(I32)
;;								## 2
	c0    add $r0.57 = $r0.57, 1   ## bblock 18, line 116,  t308,  t308,  1(SI32)
;;								## 3
	c0    stb 0[$r0.2] = $r0.3   ## bblock 17, line 121, t590, 255(I32)
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
 ## Begin deriche_fused
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
deriche_fused::
.trace 29
	      ## auto_size == 0
;;								## 0
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t842,  0(I32),  t216
;;								## 1
	c0    mov $r0.19 = ((qy2 + 0) + (~0x3))   ## bblock 0, line 0,  t836,  (addr(qy2?1.0)(P32) + 0xfffffffc(I32))(P32)
;;								## 2
	c0    mov $r0.27 = $r0.3   ## t216
;;								## 3
	c0    mov $r0.3 = $r0.2   ## bblock 0, line 0,  t841,  t842
;;								## 4
	c0    add $r0.17 = $r0.4, -1   ## bblock 0, line 161,  t309,  t217,  -1(SI32)
;;								## 5
	c0    mov $r0.16 = ((in + 0) + (~0x0))   ## bblock 0, line 0,  t837,  (addr(in?1.0)(P32) + 0xffffffff(I32))(P32)
;;								## 6
	c0    mov $r0.21 = (in + 0)   ## bblock 0, line 0,  t839,  addr(in?1.0)(P32)
;;								## 7
	c0    mov $r0.20 = (qy1 + 0)   ## bblock 0, line 0,  t840,  addr(qy1?1.0)(P32)
;;								## 8
	c0    mov $r0.15 = $r0.4   ## t217
;;								## 9
.trace 15
L25?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 1, line 159,  t888(I1),  t841,  0(SI32)
;;								## 0
	c0    sub $r0.22 = 1, $r0.15   ## [spec] bblock 24, line 0,  t416,  1(I32),  t217
;;								## 1
	c0    brf $b0.0, L26?3   ## bblock 1, line 159,  t888(I1)
;;								## 2
	c0    mov $r0.7 = $r0.22   ## bblock 24, line 0,  t415,  t416
;;								## 3
	c0    add $r0.14 = $r0.16, $r0.17   ## bblock 24, line 0,  t414,  t837,  t309
;;								## 4
	c0    sh2add $r0.13 = $r0.17, $r0.19   ## bblock 24, line 0,  t413,  t309,  t836
;;								## 5
	c0    mov $r0.9 = $r0.0   ## bblock 24, line 160,  t239,  0(SI32)
;;								## 6
	c0    mov $r0.11 = $r0.0   ## bblock 24, line 160,  t240,  0(SI32)
;;								## 7
	c0    mov $r0.12 = $r0.0   ## bblock 24, line 160,  t243,  0(SI32)
;;								## 8
	c0    mov $r0.10 = $r0.0   ## bblock 24, line 160,  t244,  0(SI32)
;;								## 9
	c0    mov $r0.8 = $r0.20   ## bblock 24, line 0,  t412,  t840
;;								## 10
	c0    mov $r0.5 = $r0.0   ## bblock 24, line 160,  t245,  0(SI32)
;;								## 11
	c0    mov $r0.4 = $r0.0   ## bblock 24, line 160,  t246,  0(SI32)
;;								## 12
	c0    mov $r0.2 = $r0.21   ## bblock 24, line 0,  t411,  t839
;;								## 13
	c0    mov $r0.6 = $r0.0   ## bblock 24, line 160,  t248,  0(SI32)
;;								## 14
	c0    mov $r0.22 = $r0.16   ## t837
;;								## 15
	c0    mov $r0.25 = $r0.20   ## t840
;;								## 16
	c0    mov $r0.20 = $r0.3   ## t841
;;								## 17
	c0    mov $r0.26 = $r0.21   ## t839
;;								## 18
	c0    mov $r0.21 = $r0.15   ## t217
;;								## 19
	c0    mov $r0.23 = $r0.17   ## t309
;;								## 20
	c0    mov $r0.24 = $r0.19   ## t836
;;								## 21
.trace 2
L27?3:
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 27, line 163, t320, t411
;;								## 0
	c0    mpyl $r0.15 = $r0.4, 215   ## [spec] bblock 27, line 165,  t23,  t246,  215(SI32)
;;								## 1
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 27, line 166,  t27,  t245,  -155(SI32)
;;								## 2
	c0    mpyl $r0.16 = $r0.3, -48   ## [spec] bblock 27, line 163,  t32,  t320,  -48(SI32)
;;								## 3
	c0    shr $r0.15 = $r0.15, 8   ## [spec] bblock 27, line 165,  t30(SI24),  t23,  8(SI32)
;;								## 4
	c0    add $r0.16 = $r0.16, $r0.15   ## [spec] bblock 27, line 168,  t905,  t32,  t30(SI24)
;;								## 5
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 27, line 166,  t404(SI24),  t27,  8(SI32)
;;								## 6
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 27, line 164,  t31,  t248,  28(SI32)
;;								## 7
	c0    cmplt $b0.0 = $r0.7, 1   ## bblock 25, line 161,  t903(I1),  t415,  1(SI32)
;;								## 8
	c0    add $r0.6 = $r0.6, $r0.5   ## [spec] bblock 27, line 168,  t904,  t31,  t404(SI24)
;;								## 9
	c0    add $r0.6 = $r0.6, $r0.16   ## [spec] bblock 27, line 168,  t319,  t904,  t905
;;								## 10
	c0    brf $b0.0, L28?3   ## bblock 25, line 161,  t903(I1)
;;								## 11
	c0    mpyl $r0.9 = $r0.9, -155   ## bblock 27, line 176,  t402,  t239,  -155(SI32)
;;								## 12
	c0    mpyl $r0.15 = $r0.10, -47   ## bblock 27, line 173,  t63,  t244,  -47(SI32)
;;								## 13
	c0    shr $r0.9 = $r0.9, 8   ## bblock 27, line 176,  t401(SI24),  t402,  8(SI32)
;;								## 14
	c0    add $r0.15 = $r0.15, $r0.9   ## bblock 27, line 177,  t906,  t63,  t401(SI24)
;;								## 15
	c0    mpyl $r0.16 = $r0.11, 215   ## bblock 27, line 175,  t54,  t240,  215(SI32)
;;								## 16
	c0    mpyl $r0.12 = $r0.12, -48   ## bblock 27, line 174,  t317,  t243,  -48(SI32)
;;								## 17
	c0    shr $r0.16 = $r0.16, 8   ## bblock 27, line 175,  t316(SI24),  t54,  8(SI32)
;;								## 18
	c0    add $r0.12 = $r0.12, $r0.16   ## bblock 27, line 177,  t907,  t317,  t316(SI24)
;;								## 19
	c0    add $r0.15 = $r0.15, $r0.12   ## bblock 27, line 177,  t314,  t906,  t907
;;								## 20
	c0    ldbu $r0.16 = 1[$r0.14]   ## bblock 27, line 179, t312, t414
;;								## 21
	c0    cmplt $b0.0 = $r0.7, $r0.0   ## bblock 27, line 161-1,  t908(I1),  t415,  0(SI32)
;;								## 22
	c0    ldbu.d $r0.17 = 1[$r0.2]   ## [spec] bblock 62, line 163-1, t248, t411
;;								## 23
	c0    mpyl $r0.18 = $r0.6, 215   ## [spec] bblock 62, line 165-1,  t395,  t319,  215(SI32)
;;								## 24
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 62, line 166-1,  t322,  t246,  -155(SI32)
;;								## 25
	c0    mpyl $r0.19 = $r0.17, -48   ## [spec] bblock 62, line 163-1,  t396,  t248,  -48(SI32)
;;								## 26
	c0    shr $r0.18 = $r0.18, 8   ## [spec] bblock 62, line 165-1,  t323(SI24),  t395,  8(SI32)
;;								## 27
	c0    add $r0.19 = $r0.19, $r0.18   ## [spec] bblock 62, line 168-1,  t921,  t396,  t323(SI24)
;;								## 28
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 62, line 166-1,  t29(SI24),  t322,  8(SI32)
;;								## 29
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 62, line 164-1,  t324,  t320,  28(SI32)
;;								## 30
	c0    mpyl $r0.11 = $r0.11, -155   ## [spec] bblock 62, line 176-1,  t58,  t240,  -155(SI32)
;;								## 31
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 62, line 168-1,  t920,  t324,  t29(SI24)
;;								## 32
	c0    add $r0.4 = $r0.3, $r0.19   ## [spec] bblock 62, line 168-1,  t246,  t920,  t921
;;								## 33
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 62, line 176-1,  t60(SI24),  t58,  8(SI32)
;;								## 34
	c0    mpyl $r0.3 = $r0.16, -47   ## [spec] bblock 62, line 173-1,  t321,  t312,  -47(SI32)
;;								## 35
	c0    mpyl $r0.18 = $r0.15, 215   ## [spec] bblock 62, line 175-1,  t399,  t314,  215(SI32)
;;								## 36
	c0    add $r0.3 = $r0.3, $r0.11   ## [spec] bblock 62, line 177-1,  t922,  t321,  t60(SI24)
;;								## 37
	c0    shr $r0.18 = $r0.18, 8   ## [spec] bblock 62, line 175-1,  t61(SI24),  t399,  8(SI32)
;;								## 38
	c0    mpyl $r0.10 = $r0.10, -48   ## [spec] bblock 62, line 174-1,  t62,  t244,  -48(SI32)
;;								## 39
	c0    ldbu.d $r0.19 = 0[$r0.14]   ## [spec] bblock 62, line 179-1, t244, t414
;;								## 40
	c0    add $r0.10 = $r0.10, $r0.18   ## [spec] bblock 62, line 177-1,  t923,  t62,  t61(SI24)
;;								## 41
	c0    add $r0.11 = $r0.3, $r0.10   ## [spec] bblock 62, line 177-1,  t240,  t922,  t923
;;								## 42
	c0    mov $r0.9 = $r0.15   ## [spec] bblock 62, line 177,  t239,  t314
;;								## 43
	c0    mov $r0.12 = $r0.16   ## [spec] bblock 62, line 179,  t243,  t312
;;								## 44
	c0    mov $r0.5 = $r0.6   ## [spec] bblock 62, line 168,  t245,  t319
;;								## 45
	c0    add $r0.2 = $r0.2, 2   ## [spec] bblock 62, line 0,  t411,  t411,  2(I32)
;;								## 46
	c0    add $r0.14 = $r0.14, (~0x1)   ## [spec] bblock 62, line 0,  t414,  t414,  (~0x1)(I32)
;;								## 47
	c0    add $r0.7 = $r0.7, 2   ## [spec] bblock 62, line 0,  t415,  t415,  2(I32)
;;								## 48
	c0    stw 0[$r0.8] = $r0.6   ## bblock 27, line 168, t412, t319
;;								## 49
	c0    mov $r0.6 = $r0.17   ## [spec] t248
;;								## 50
	c0    mov $r0.10 = $r0.19   ## [spec] t244
;;								## 51
	c0    stw 4[$r0.13] = $r0.15   ## bblock 27, line 177, t413, t314
;;								## 52
	c0    brf $b0.0, L28?3   ## bblock 27, line 161-1,  t908(I1)
;;								## 53
	c0    stw 4[$r0.8] = $r0.4   ## bblock 62, line 168-1, t412, t246
;;								## 54
	c0    add $r0.8 = $r0.8, 8   ## bblock 62, line 0,  t412,  t412,  8(I32)
;;								## 55
	c0    stw 0[$r0.13] = $r0.11   ## bblock 62, line 177-1, t413, t240
;;								## 56
	c0    add $r0.13 = $r0.13, (~0x7)   ## bblock 62, line 0,  t413,  t413,  (~0x7)(I32)
	      ## goto
;;
	c0    goto L27?3 ## goto
;;								## 57
.trace 17
L28?3:
	c0    add $r0.19 = $r0.24, 4200   ## bblock 26, line 0,  t836,  t836,  4200(I32)
;;								## 0
	c0    add $r0.16 = $r0.22, 1050   ## bblock 26, line 0,  t837,  t837,  1050(I32)
;;								## 1
	c0    mov $r0.3 = $r0.20   ## t841
;;								## 2
	c0    mov $r0.15 = $r0.21   ## t217
;;								## 3
	c0    add $r0.21 = $r0.26, 1050   ## bblock 26, line 0,  t839,  t839,  1050(I32)
;;								## 4
	c0    add $r0.20 = $r0.25, 4200   ## bblock 26, line 0,  t840,  t840,  4200(I32)
;;								## 5
	c0    add $r0.3 = $r0.3, 1   ## bblock 26, line 0,  t841,  t841,  1(I32)
;;								## 6
	c0    mov $r0.17 = $r0.23   ## t309
	      ## goto
;;
	c0    goto L25?3 ## goto
;;								## 7
.trace 30
L26?3:
	c0    sub $r0.2 = $r0.0, $r0.27   ## bblock 2, line 0,  t793,  0(I32),  t216
;;								## 0
	c0    mov $r0.3 = $r0.2   ## bblock 2, line 0,  t792,  t793
;;								## 1
	c0    mov $r0.10 = (qy2 + 0)   ## bblock 2, line 0,  t789,  addr(qy2?1.0)(P32)
;;								## 2
	c0    mov $r0.9 = (qy1 + 0)   ## bblock 2, line 0,  t790,  addr(qy1?1.0)(P32)
;;								## 3
	c0    mov $r0.8 = (qt + 0)   ## bblock 2, line 0,  t791,  addr(qt?1.0)(P32)
;;								## 4
	c0    mov $r0.7 = $r0.15   ## t217
;;								## 5
.trace 13
L29?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 3, line 185,  t889(I1),  t792,  0(SI32)
;;								## 0
	c0    sub $r0.11 = 3, $r0.7   ## [spec] bblock 20, line 0,  t473,  3(I32),  t217
;;								## 1
	c0    brf $b0.0, L30?3   ## bblock 3, line 185,  t889(I1)
;;								## 2
	c0    mov $r0.5 = $r0.11   ## bblock 20, line 0,  t472,  t473
;;								## 3
	c0    mov $r0.6 = $r0.8   ## bblock 20, line 0,  t471,  t791
;;								## 4
	c0    mov $r0.4 = $r0.9   ## bblock 20, line 0,  t470,  t790
;;								## 5
	c0    mov $r0.2 = $r0.10   ## bblock 20, line 0,  t469,  t789
;;								## 6
	c0    mov $r0.11 = $r0.3   ## t792
;;								## 7
	c0    mov $r0.12 = $r0.7   ## t217
;;								## 8
	c0    mov $r0.13 = $r0.8   ## t791
;;								## 9
	c0    mov $r0.14 = $r0.9   ## t790
;;								## 10
	c0    mov $r0.15 = $r0.10   ## t789
;;								## 11
.trace 3
L31?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 23, line 187, t89, t469
;;								## 0
	c0    ldw.d $r0.7 = 0[$r0.4]   ## [spec] bblock 23, line 187, t328, t470
;;								## 1
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 21, line 186,  t901(I1),  t472,  3(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 23, line 186-1,  t902(I1),  t472,  2(SI32)
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.7   ## [spec] bblock 23, line 187,  t398,  t89,  t328
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## [spec] bblock 23, line 187,  t397,  t398,  8(I32)
;;								## 5
	c0    shr $r0.3 = $r0.3, 8   ## [spec] bblock 23, line 187,  t327(SI24),  t397,  8(SI32)
;;								## 6
	c0    brf $b0.0, L32?3   ## bblock 21, line 186,  t901(I1)
;;								## 7
	c0    ldw.d $r0.7 = 4[$r0.2]   ## [spec] bblock 58, line 187-1, t329, t469
;;								## 8
	c0    ldw.d $r0.8 = 4[$r0.4]   ## [spec] bblock 58, line 187-1, t93, t470
;;								## 9
	c0    cmplt $b0.0 = $r0.5, 1   ## [spec] bblock 58, line 186-2,  t919(I1),  t472,  1(SI32)
;;								## 10
	c0    ldw.d $r0.9 = 8[$r0.2]   ## [spec] bblock 55, line 187-2, t340, t469
;;								## 11
	c0    add $r0.7 = $r0.7, $r0.8   ## [spec] bblock 58, line 187-1,  t94,  t329,  t93
;;								## 12
	c0    shl $r0.7 = $r0.7, 8   ## [spec] bblock 58, line 187-1,  t96,  t94,  8(I32)
;;								## 13
	c0    shr $r0.7 = $r0.7, 8   ## [spec] bblock 58, line 187-1,  t97(SI24),  t96,  8(SI32)
;;								## 14
	c0    ldw.d $r0.8 = 8[$r0.4]   ## [spec] bblock 55, line 187-2, t339, t470
;;								## 15
	c0    cmplt $b0.2 = $r0.5, $r0.0   ## [spec] bblock 55, line 186-3,  t918(I1),  t472,  0(SI32)
;;								## 16
	c0    ldw.d $r0.10 = 12[$r0.2]   ## [spec] bblock 52, line 187-3, t344, t469
;;								## 17
	c0    add $r0.9 = $r0.9, $r0.8   ## [spec] bblock 55, line 187-2,  t338,  t340,  t339
;;								## 18
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 55, line 187-2,  t337,  t338,  8(I32)
;;								## 19
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 55, line 187-2,  t336(SI24),  t337,  8(SI32)
;;								## 20
	c0    ldw.d $r0.8 = 12[$r0.4]   ## [spec] bblock 52, line 187-3, t343, t470
;;								## 21
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 52, line 0,  t469,  t469,  16(I32)
;;								## 22
	c0    add $r0.4 = $r0.4, 16   ## [spec] bblock 52, line 0,  t470,  t470,  16(I32)
;;								## 23
	c0    add $r0.10 = $r0.10, $r0.8   ## [spec] bblock 52, line 187-3,  t342,  t344,  t343
;;								## 24
	c0    shl $r0.10 = $r0.10, 8   ## [spec] bblock 52, line 187-3,  t388,  t342,  8(I32)
;;								## 25
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 52, line 187-3,  t387(SI24),  t388,  8(SI32)
;;								## 26
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 52, line 0,  t472,  t472,  4(I32)
;;								## 27
	c0    stw 0[$r0.6] = $r0.3   ## bblock 23, line 187, t471, t327(SI24)
;;								## 28
	c0    brf $b0.1, L32?3   ## bblock 23, line 186-1,  t902(I1)
;;								## 29
	c0    stw 4[$r0.6] = $r0.7   ## bblock 58, line 187-1, t471, t97(SI24)
;;								## 30
	c0    brf $b0.0, L32?3   ## bblock 58, line 186-2,  t919(I1)
;;								## 31
	c0    stw 8[$r0.6] = $r0.9   ## bblock 55, line 187-2, t471, t336(SI24)
;;								## 32
	c0    brf $b0.2, L32?3   ## bblock 55, line 186-3,  t918(I1)
;;								## 33
	c0    stw 12[$r0.6] = $r0.10   ## bblock 52, line 187-3, t471, t387(SI24)
;;								## 34
	c0    add $r0.6 = $r0.6, 16   ## bblock 52, line 0,  t471,  t471,  16(I32)
	      ## goto
;;
	c0    goto L31?3 ## goto
;;								## 35
.trace 19
L32?3:
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 22, line 0,  t789,  t789,  4200(I32)
;;								## 1
	c0    add $r0.9 = $r0.14, $r0.2   ## bblock 22, line 0,  t790,  t790,  4200(I32)
;;								## 2
	c0    add $r0.8 = $r0.13, $r0.2   ## bblock 22, line 0,  t791,  t791,  4200(I32)
;;								## 3
	c0    add $r0.3 = $r0.11, 1   ## bblock 22, line 0,  t792,  t792,  1(I32)
;;								## 4
	c0    mov $r0.7 = $r0.12   ## t217
	      ## goto
;;
	c0    goto L29?3 ## goto
;;								## 5
.trace 32
L30?3:
	c0    sub $r0.2 = $r0.0, $r0.7   ## bblock 4, line 0,  t751,  0(I32),  t217
;;								## 0
	c0    mov $r0.3 = $r0.2   ## bblock 4, line 0,  t750,  t751
;;								## 1
	c0    mov $r0.20 = (qt + 0)   ## bblock 4, line 0,  t745,  addr(qt?1.0)(P32)
;;								## 2
	c0    mov $r0.19 = (qy1 + 0)   ## bblock 4, line 0,  t746,  addr(qy1?1.0)(P32)
;;								## 3
	c0    mov $r0.17 = ((qy2 + 0) + (~0x1067))   ## bblock 4, line 0,  t748,  (addr(qy2?1.0)(P32) + 0xffffef98(I32))(P32)
;;								## 4
	c0    mov $r0.16 = ((qt + 0) + (~0x1067))   ## bblock 4, line 0,  t749,  (addr(qt?1.0)(P32) + 0xffffef98(I32))(P32)
;;								## 5
	c0    add $r0.15 = $r0.27, -1   ## bblock 4, line 191,  t310,  t216,  -1(SI32)
;;								## 6
	c0    mov $r0.18 = $r0.27   ## t216
;;								## 7
	c0    mov $r0.25 = $r0.7   ## t217
;;								## 8
.trace 14
L33?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 5, line 189,  t890(I1),  t750,  0(SI32)
;;								## 0
	c0    mpylu $r0.21 = $r0.15, 4200   ## [spec] bblock 16, line 0,  t546,  t310,  4200(I32)
;;								## 1
	c0    brf $b0.0, L34?3   ## bblock 5, line 189,  t890(I1)
;;								## 2
	c0    add $r0.14 = $r0.16, $r0.21   ## bblock 16, line 0,  t533,  t749,  t546
;;								## 3
	c0    add $r0.13 = $r0.17, $r0.21   ## bblock 16, line 0,  t532,  t748,  t546
;;								## 4
	c0    sub $r0.21 = 1, $r0.18   ## bblock 16, line 0,  t573,  1(I32),  t216
;;								## 5
	c0    mov $r0.7 = $r0.21   ## bblock 16, line 0,  t536,  t573
;;								## 6
	c0    mov $r0.10 = $r0.0   ## bblock 16, line 190,  t242,  0(SI32)
;;								## 7
	c0    mov $r0.12 = $r0.0   ## bblock 16, line 190,  t241,  0(SI32)
;;								## 8
	c0    mov $r0.11 = $r0.0   ## bblock 16, line 190,  t305(SI24),  0(SI32)
;;								## 9
	c0    mov $r0.9 = $r0.0   ## bblock 16, line 190,  t304,  0(SI32)
;;								## 10
	c0    mov $r0.8 = $r0.19   ## bblock 16, line 0,  t535,  t746
;;								## 11
	c0    mov $r0.2 = $r0.20   ## bblock 16, line 0,  t534,  t745
;;								## 12
	c0    mov $r0.6 = $r0.0   ## bblock 16, line 190,  t247,  0(SI32)
;;								## 13
	c0    mov $r0.5 = $r0.0   ## bblock 16, line 190,  t307(SI24),  0(SI32)
;;								## 14
	c0    mov $r0.4 = $r0.0   ## bblock 16, line 190,  t306,  0(SI32)
;;								## 15
	c0    mov $r0.21 = $r0.17   ## t748
;;								## 16
	c0    mov $r0.22 = $r0.18   ## t216
;;								## 17
	c0    mov $r0.18 = $r0.3   ## t750
;;								## 18
	c0    mov $r0.23 = $r0.19   ## t746
;;								## 19
	c0    mov $r0.19 = $r0.15   ## t310
;;								## 20
	c0    mov $r0.24 = $r0.20   ## t745
;;								## 21
	c0    mov $r0.20 = $r0.16   ## t749
;;								## 22
.trace 1
L35?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 19, line 192, t358, t534
;;								## 0
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 19, line 192,  t115,  t306,  -155(SI32)
;;								## 1
	c0    mpyl $r0.15 = $r0.5, 215   ## [spec] bblock 19, line 192,  t118,  t307(SI24),  215(SI32)
;;								## 2
	c0    mpyl $r0.16 = $r0.3, -48   ## [spec] bblock 19, line 192,  t361,  t358,  -48(SI32)
;;								## 3
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 19, line 192,  t362,  t247,  28(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.16   ## [spec] bblock 19, line 192,  t896,  t115,  t361
;;								## 5
	c0    add $r0.15 = $r0.15, $r0.6   ## [spec] bblock 19, line 192,  t897,  t118,  t362
;;								## 6
	c0    add $r0.4 = $r0.4, $r0.15   ## [spec] bblock 19, line 192,  t394,  t896,  t897
;;								## 7
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 19, line 192,  t885,  t394,  8(SI32)
;;								## 8
	c0    cmplt $b0.0 = $r0.7, 1   ## bblock 17, line 191,  t895(I1),  t536,  1(SI32)
;;								## 9
	c0    mpyl $r0.9 = $r0.9, -155   ## [spec] bblock 19, line 197,  t360,  t304,  -155(SI32)
;;								## 10
	c0    brf $b0.0, L36?3   ## bblock 17, line 191,  t895(I1)
;;								## 11
	c0    mpyl $r0.15 = $r0.10, -47   ## bblock 19, line 197,  t355,  t242,  -47(SI32)
;;								## 12
	c0    mpyl $r0.16 = $r0.11, 215   ## bblock 19, line 197,  t359,  t305(SI24),  215(SI32)
;;								## 13
	c0    add $r0.9 = $r0.9, $r0.15   ## bblock 19, line 197,  t898,  t360,  t355
;;								## 14
	c0    mpyl $r0.12 = $r0.12, 29   ## bblock 19, line 197,  t357,  t241,  29(SI32)
;;								## 15
	c0    ldw $r0.15 = 4200[$r0.14]   ## bblock 19, line 199, t346, t533
;;								## 16
	c0    add $r0.16 = $r0.16, $r0.12   ## bblock 19, line 197,  t899,  t359,  t357
;;								## 17
	c0    add $r0.9 = $r0.9, $r0.16   ## bblock 19, line 197,  t392,  t898,  t899
;;								## 18
	c0    shr $r0.9 = $r0.9, 8   ## bblock 19, line 197,  t886,  t392,  8(SI32)
;;								## 19
	c0    cmplt $b0.0 = $r0.7, $r0.0   ## bblock 19, line 191-1,  t900(I1),  t536,  0(SI32)
;;								## 20
	c0    ldw.d $r0.6 = 4200[$r0.2]   ## [spec] bblock 48, line 192-1, t247, t534
;;								## 21
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 48, line 192-1,  t350,  t307(SI24),  -155(SI32)
;;								## 22
	c0    mpyl $r0.16 = $r0.4, 215   ## [spec] bblock 48, line 192-1,  t349,  t885,  215(SI32)
;;								## 23
	c0    mpyl $r0.17 = $r0.6, -48   ## [spec] bblock 48, line 192-1,  t127,  t247,  -48(SI32)
;;								## 24
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 48, line 192-1,  t121,  t358,  28(SI32)
;;								## 25
	c0    add $r0.5 = $r0.5, $r0.17   ## [spec] bblock 48, line 192-1,  t914,  t350,  t127
;;								## 26
	c0    add $r0.16 = $r0.16, $r0.3   ## [spec] bblock 48, line 192-1,  t915,  t349,  t121
;;								## 27
	c0    add $r0.5 = $r0.5, $r0.16   ## [spec] bblock 48, line 192-1,  t128,  t914,  t915
;;								## 28
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 48, line 192-1,  t307(SI24),  t128,  8(SI32)
;;								## 29
	c0    mpyl $r0.11 = $r0.11, -155   ## [spec] bblock 48, line 197-1,  t144,  t305(SI24),  -155(SI32)
;;								## 30
	c0    mpyl $r0.3 = $r0.15, -47   ## [spec] bblock 48, line 197-1,  t153,  t346,  -47(SI32)
;;								## 31
	c0    mpyl $r0.16 = $r0.9, 215   ## [spec] bblock 48, line 197-1,  t147,  t886,  215(SI32)
;;								## 32
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 48, line 197-1,  t916,  t144,  t153
;;								## 33
	c0    mpyl $r0.10 = $r0.10, 29   ## [spec] bblock 48, line 197-1,  t150,  t242,  29(SI32)
;;								## 34
	c0    ldw.d $r0.3 = 0[$r0.14]   ## [spec] bblock 48, line 199-1, t242, t533
;;								## 35
	c0    add $r0.16 = $r0.16, $r0.10   ## [spec] bblock 48, line 197-1,  t917,  t147,  t150
;;								## 36
	c0    add $r0.11 = $r0.11, $r0.16   ## [spec] bblock 48, line 197-1,  t154,  t916,  t917
;;								## 37
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 48, line 197-1,  t305(SI24),  t154,  8(SI32)
;;								## 38
	c0    mov $r0.12 = $r0.15   ## [spec] bblock 48, line 199,  t241,  t346
;;								## 39
	c0    mov $r0.15 = $r0.9   ## [spec] bblock 48, line 197,  t304,  t886
;;								## 40
	c0    mov $r0.16 = $r0.4   ## [spec] bblock 48, line 192,  t306,  t885
;;								## 41
	c0    add $r0.14 = $r0.14, (~0x20cf)   ## [spec] bblock 48, line 0,  t533,  t533,  (~0x20cf)(I32)
;;								## 42
	c0    add $r0.2 = $r0.2, 8400   ## [spec] bblock 48, line 0,  t534,  t534,  8400(I32)
;;								## 43
	c0    add $r0.7 = $r0.7, 2   ## [spec] bblock 48, line 0,  t536,  t536,  2(I32)
;;								## 44
	c0    stw 0[$r0.8] = $r0.4   ## bblock 19, line 192, t535, t885
;;								## 45
	c0    mov $r0.4 = $r0.16   ## [spec] t306
;;								## 46
	c0    stw 4200[$r0.13] = $r0.9   ## bblock 19, line 197, t532, t886
;;								## 47
	c0    brf $b0.0, L36?3   ## bblock 19, line 191-1,  t900(I1)
;;								## 48
	c0    mov $r0.9 = $r0.15   ## [spec] t304
;;								## 49
	c0    mov $r0.10 = $r0.3   ## [spec] t242
;;								## 50
	c0    stw 4200[$r0.8] = $r0.5   ## bblock 48, line 192-1, t535, t307(SI24)
;;								## 51
	c0    add $r0.8 = $r0.8, 8400   ## bblock 48, line 0,  t535,  t535,  8400(I32)
;;								## 52
	c0    stw 0[$r0.13] = $r0.11   ## bblock 48, line 197-1, t532, t305(SI24)
;;								## 53
	c0    add $r0.13 = $r0.13, (~0x20cf)   ## bblock 48, line 0,  t532,  t532,  (~0x20cf)(I32)
	      ## goto
;;
	c0    goto L35?3 ## goto
;;								## 54
.trace 18
L36?3:
	c0    add $r0.17 = $r0.21, 4   ## bblock 18, line 0,  t748,  t748,  4(I32)
;;								## 0
	c0    mov $r0.16 = $r0.20   ## t749
;;								## 1
	c0    add $r0.20 = $r0.24, 4   ## bblock 18, line 0,  t745,  t745,  4(I32)
;;								## 2
	c0    mov $r0.15 = $r0.19   ## t310
;;								## 3
	c0    add $r0.19 = $r0.23, 4   ## bblock 18, line 0,  t746,  t746,  4(I32)
;;								## 4
	c0    add $r0.16 = $r0.16, 4   ## bblock 18, line 0,  t749,  t749,  4(I32)
;;								## 5
	c0    add $r0.3 = $r0.18, 1   ## bblock 18, line 0,  t750,  t750,  1(I32)
;;								## 6
	c0    mov $r0.18 = $r0.22   ## t216
	      ## goto
;;
	c0    goto L33?3 ## goto
;;								## 7
.trace 31
L34?3:
	c0    sub $r0.18 = $r0.0, $r0.18   ## bblock 6, line 0,  t703,  0(I32),  t216
;;								## 0
	c0    mov $r0.3 = $r0.18   ## bblock 6, line 0,  t702,  t703
;;								## 1
	c0    mov $r0.11 = (qy2 + 0)   ## bblock 6, line 0,  t700,  addr(qy2?1.0)(P32)
;;								## 2
	c0    mov $r0.10 = (qy1 + 0)   ## bblock 6, line 0,  t701,  addr(qy1?1.0)(P32)
;;								## 3
	c0    mov $r0.9 = (out + 0)   ## bblock 6, line 0,  t698,  addr(out?1.0)(P32)
;;								## 4
	c0    mov $r0.8 = $r0.25   ## t217
;;								## 5
.trace 16
L37?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 7, line 205,  t891(I1),  t702,  0(SI32)
;;								## 0
	c0    sub $r0.12 = 3, $r0.8   ## [spec] bblock 9, line 0,  t629,  3(I32),  t217
;;								## 1
	c0    brf $b0.0, L38?3   ## bblock 7, line 205,  t891(I1)
;;								## 2
	c0    mov $r0.5 = $r0.12   ## bblock 9, line 0,  t628,  t629
;;								## 3
	c0    mov $r0.7 = $r0.9   ## bblock 9, line 0,  t627,  t698
;;								## 4
	c0    mov $r0.6 = $r0.9   ## bblock 9, line 0,  t626,  t698
;;								## 5
	c0    mov $r0.4 = $r0.10   ## bblock 9, line 0,  t625,  t701
;;								## 6
	c0    mov $r0.2 = $r0.11   ## bblock 9, line 0,  t624,  t700
;;								## 7
	c0    mov $r0.13 = $r0.3   ## t702
;;								## 8
	c0    mov $r0.14 = $r0.8   ## t217
;;								## 9
	c0    mov $r0.15 = $r0.9   ## t698
;;								## 10
	c0    mov $r0.16 = $r0.10   ## t701
;;								## 11
	c0    mov $r0.17 = $r0.11   ## t700
;;								## 12
.trace 4
L39?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 12, line 207, t384, t624
;;								## 0
	c0    ldw.d $r0.8 = 0[$r0.4]   ## [spec] bblock 12, line 207, t383, t625
;;								## 1
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 10, line 206,  t892(I1),  t628,  3(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 14, line 206-1,  t894(I1),  t628,  2(SI32)
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.8   ## [spec] bblock 12, line 207,  t375,  t384,  t383
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## [spec] bblock 12, line 207,  t374,  t375,  8(I32)
;;								## 5
	c0    shr $r0.3 = $r0.3, 16   ## [spec] bblock 12, line 207,  t373(SI16),  t374,  16(SI32)
;;								## 6
	c0    brf $b0.0, L40?3   ## bblock 10, line 206,  t892(I1)
;;								## 7
	c0    zxtb $r0.8 = $r0.3   ## bblock 12, line 207,  t372(I8),  t373(SI16)
;;								## 8
	c0    cmpgt $b0.0 = $r0.8, 25   ## bblock 12, line 208,  t893(I1),  t372(I8),  25(SI32)
;;								## 9
	c0    ldw.d $r0.9 = 4[$r0.2]   ## [spec] bblock 41, line 207-1, t180, t624
;;								## 10
	c0    ldw.d $r0.8 = 4[$r0.4]   ## [spec] bblock 41, line 207-1, t332, t625
;;								## 11
	c0    cmplt $b0.2 = $r0.5, 1   ## [spec] bblock 43, line 206-2,  t913(I1),  t628,  1(SI32)
;;								## 12
	c0    ldw.d $r0.10 = 8[$r0.2]   ## [spec] bblock 35, line 207-2, t364, t624
;;								## 13
	c0    add $r0.9 = $r0.9, $r0.8   ## [spec] bblock 41, line 207-1,  t331,  t180,  t332
;;								## 14
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 41, line 207-1,  t390,  t331,  8(I32)
;;								## 15
	c0    shr $r0.9 = $r0.9, 16   ## [spec] bblock 41, line 207-1,  t389(SI16),  t390,  16(SI32)
;;								## 16
	c0    zxtb $r0.8 = $r0.9   ## [spec] bblock 41, line 207-1,  t196(I8),  t389(SI16)
;;								## 17
	c0    cmpgt $b0.3 = $r0.8, 25   ## [spec] bblock 41, line 208-1,  t912(I1),  t196(I8),  25(SI32)
;;								## 18
	c0    ldw.d $r0.11 = 8[$r0.4]   ## [spec] bblock 35, line 207-2, t184, t625
;;								## 19
	c0    cmplt $b0.4 = $r0.5, $r0.0   ## [spec] bblock 37, line 206-3,  t911(I1),  t628,  0(SI32)
;;								## 20
	c0    ldw.d $r0.8 = 12[$r0.2]   ## [spec] bblock 29, line 207-3, t380, t624
;;								## 21
	c0    add $r0.10 = $r0.10, $r0.11   ## [spec] bblock 35, line 207-2,  t185,  t364,  t184
;;								## 22
	c0    shl $r0.10 = $r0.10, 8   ## [spec] bblock 35, line 207-2,  t187,  t185,  8(I32)
;;								## 23
	c0    shr $r0.10 = $r0.10, 16   ## [spec] bblock 35, line 207-2,  t188(SI16),  t187,  16(SI32)
;;								## 24
	c0    zxtb $r0.11 = $r0.10   ## [spec] bblock 35, line 207-2,  t368(I8),  t188(SI16)
;;								## 25
	c0    cmpgt $b0.5 = $r0.11, 25   ## [spec] bblock 35, line 208-2,  t910(I1),  t368(I8),  25(SI32)
;;								## 26
	c0    ldw.d $r0.12 = 12[$r0.4]   ## [spec] bblock 29, line 207-3, t379, t625
;;								## 27
	c0    stb 0[$r0.6] = $r0.3   ## bblock 12, line 207, t626, t373(SI16)
;;								## 28
	c0    brf $b0.0, L41?3   ## bblock 12, line 208,  t893(I1)
;;								## 29
	c0    add $r0.8 = $r0.8, $r0.12   ## [spec] bblock 29, line 207-3,  t378,  t380,  t379
;;								## 30
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 29, line 207-3,  t377,  t378,  8(I32)
;;								## 31
	c0    shr $r0.8 = $r0.8, 16   ## [spec] bblock 29, line 207-3,  t371(SI16),  t377,  16(SI32)
;;								## 32
	c0    zxtb $r0.3 = $r0.8   ## [spec] bblock 29, line 207-3,  t370(I8),  t371(SI16)
;;								## 33
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 29, line 208-3,  t909(I1),  t370(I8),  25(SI32)
;;								## 34
	c0    stb 0[$r0.6] = $r0.0   ## bblock 15, line 209, t626, 0(I32)
;;								## 35
L42?3:
	c0    brf $b0.1, L40?3   ## bblock 14, line 206-1,  t894(I1)
;;								## 36
	c0    stb 1[$r0.6] = $r0.9   ## bblock 41, line 207-1, t626, t389(SI16)
;;								## 37
	c0    brf $b0.3, L43?3   ## bblock 41, line 208-1,  t912(I1)
;;								## 38
	c0    stb 1[$r0.6] = $r0.0   ## bblock 44, line 209-1, t626, 0(I32)
;;								## 39
L44?3:
	c0    brf $b0.2, L40?3   ## bblock 43, line 206-2,  t913(I1)
;;								## 40
	c0    stb 2[$r0.6] = $r0.10   ## bblock 35, line 207-2, t626, t188(SI16)
;;								## 41
	c0    brf $b0.5, L45?3   ## bblock 35, line 208-2,  t910(I1)
;;								## 42
	c0    stb 2[$r0.6] = $r0.0   ## bblock 38, line 209-2, t626, 0(I32)
;;								## 43
L46?3:
	c0    brf $b0.4, L40?3   ## bblock 37, line 206-3,  t911(I1)
;;								## 44
	c0    stb 3[$r0.6] = $r0.8   ## bblock 29, line 207-3, t626, t371(SI16)
;;								## 45
	c0    brf $b0.0, L47?3   ## bblock 29, line 208-3,  t909(I1)
;;								## 46
	c0    add $r0.2 = $r0.2, 16   ## bblock 31, line 0,  t624,  t624,  16(I32)
;;								## 47
	c0    add $r0.4 = $r0.4, 16   ## bblock 31, line 0,  t625,  t625,  16(I32)
;;								## 48
	c0    add $r0.7 = $r0.7, 4   ## bblock 31, line 0,  t627,  t627,  4(I32)
;;								## 49
	c0    add $r0.5 = $r0.5, 4   ## bblock 31, line 0,  t628,  t628,  4(I32)
;;								## 50
	c0    stb 3[$r0.6] = $r0.0   ## bblock 32, line 209-3, t626, 0(I32)
;;								## 51
L48?3:
	c0    add $r0.6 = $r0.6, 4   ## bblock 31, line 0,  t626,  t626,  4(I32)
	      ## goto
;;
	c0    goto L39?3 ## goto
;;								## 52
.trace 12
L47?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.5 = $r0.5, 4   ## bblock 31, line 0,  t628,  t628,  4(I32)
;;								## 1
	c0    add $r0.4 = $r0.4, 16   ## bblock 31, line 0,  t625,  t625,  16(I32)
;;								## 2
	c0    add $r0.2 = $r0.2, 16   ## bblock 31, line 0,  t624,  t624,  16(I32)
;;								## 3
	c0    stb 3[$r0.7] = $r0.3   ## bblock 30, line 211-3, t627, 255(I32)
;;								## 4
	c0    add $r0.7 = $r0.7, 4   ## bblock 31, line 0,  t627,  t627,  4(I32)
	      ## goto
;;
	c0    goto L48?3 ## goto
;;								## 5
.trace 20
L40?3:
	c0    add $r0.11 = $r0.17, 4200   ## bblock 11, line 0,  t700,  t700,  4200(I32)
;;								## 0
	c0    add $r0.10 = $r0.16, 4200   ## bblock 11, line 0,  t701,  t701,  4200(I32)
;;								## 1
	c0    add $r0.9 = $r0.15, 1050   ## bblock 11, line 0,  t698,  t698,  1050(I32)
;;								## 2
	c0    add $r0.3 = $r0.13, 1   ## bblock 11, line 0,  t702,  t702,  1(I32)
;;								## 3
	c0    mov $r0.8 = $r0.14   ## t217
	      ## goto
;;
	c0    goto L37?3 ## goto
;;								## 4
.trace 11
L45?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 2[$r0.7] = $r0.3   ## bblock 36, line 211-2, t627, 255(I32)
	      ## goto
;;
	c0    goto L46?3 ## goto
;;								## 1
.trace 10
L43?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 1[$r0.7] = $r0.3   ## bblock 42, line 211-1, t627, 255(I32)
	      ## goto
;;
	c0    goto L44?3 ## goto
;;								## 1
.trace 9
L41?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.8 = $r0.8, $r0.12   ## [spec] bblock 29, line 207-3,  t378,  t380,  t379
;;								## 1
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 29, line 207-3,  t377,  t378,  8(I32)
;;								## 2
	c0    shr $r0.8 = $r0.8, 16   ## [spec] bblock 29, line 207-3,  t371(SI16),  t377,  16(SI32)
;;								## 3
	c0    zxtb $r0.11 = $r0.8   ## [spec] bblock 29, line 207-3,  t370(I8),  t371(SI16)
;;								## 4
	c0    cmpgt $b0.0 = $r0.11, 25   ## [spec] bblock 29, line 208-3,  t909(I1),  t370(I8),  25(SI32)
;;								## 5
	c0    stb 0[$r0.7] = $r0.3   ## bblock 13, line 211, t627, 255(I32)
	      ## goto
;;
	c0    goto L42?3 ## goto
;;								## 6
.trace 33
L38?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 8, line 215,  t204,  ?2.2?2auto_size(I32),  t203
;;								## 0
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
L49?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 1, line 237,  t1162(I1),  t1116,  0(SI32)
;;								## 0
	c0    sub $r0.12 = 3, $r0.9   ## [spec] bblock 36, line 0,  t519,  3(I32),  t227
;;								## 1
	c0    brf $b0.0, L50?3   ## bblock 1, line 237,  t1162(I1)
;;								## 2
	c0    mov $r0.7 = $r0.12   ## bblock 36, line 0,  t518,  t519
;;								## 3
	c0    mov $r0.8 = $r0.10   ## bblock 36, line 0,  t517,  t1115
;;								## 4
	c0    mov $r0.5 = $r0.0   ## bblock 36, line 238,  t255,  0(SI32)
;;								## 5
	c0    mov $r0.4 = $r0.0   ## bblock 36, line 238,  t256,  0(SI32)
;;								## 6
	c0    mov $r0.2 = $r0.11   ## bblock 36, line 0,  t516,  t1113
;;								## 7
	c0    mov $r0.6 = $r0.0   ## bblock 36, line 238,  t258,  0(SI32)
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
L51?3:
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 39, line 241, t342, t516
;;								## 0
	c0    mpyl $r0.9 = $r0.4, 215   ## [spec] bblock 39, line 243,  t19,  t256,  215(SI32)
;;								## 1
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 39, line 244,  t23,  t255,  -155(SI32)
;;								## 2
	c0    mpyl $r0.10 = $r0.3, -48   ## [spec] bblock 39, line 241,  t28,  t342,  -48(SI32)
;;								## 3
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 39, line 243,  t26(SI24),  t19,  8(SI32)
;;								## 4
	c0    add $r0.10 = $r0.10, $r0.9   ## [spec] bblock 39, line 245,  t1187,  t28,  t26(SI24)
;;								## 5
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 39, line 244,  t25(SI24),  t23,  8(SI32)
;;								## 6
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 39, line 242,  t27,  t258,  28(SI32)
;;								## 7
	c0    cmplt $b0.0 = $r0.7, 3   ## bblock 37, line 239,  t1185(I1),  t518,  3(SI32)
;;								## 8
	c0    add $r0.6 = $r0.6, $r0.5   ## [spec] bblock 39, line 245,  t1186,  t27,  t25(SI24)
;;								## 9
	c0    add $r0.6 = $r0.6, $r0.10   ## [spec] bblock 39, line 245,  t341,  t1186,  t1187
;;								## 10
	c0    brf $b0.0, L52?3   ## bblock 37, line 239,  t1185(I1)
;;								## 11
	c0    cmplt $b0.0 = $r0.7, 2   ## bblock 39, line 239-1,  t1188(I1),  t518,  2(SI32)
;;								## 12
	c0    ldbu.d $r0.9 = 1[$r0.2]   ## [spec] bblock 106, line 241-1, t500, t516
;;								## 13
	c0    mpyl $r0.10 = $r0.6, 215   ## [spec] bblock 106, line 243-1,  t502,  t341,  215(SI32)
;;								## 14
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 106, line 244-1,  t504,  t256,  -155(SI32)
;;								## 15
	c0    mpyl $r0.11 = $r0.9, -48   ## [spec] bblock 106, line 241-1,  t501,  t500,  -48(SI32)
;;								## 16
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 106, line 243-1,  t503(SI24),  t502,  8(SI32)
;;								## 17
	c0    add $r0.11 = $r0.11, $r0.10   ## [spec] bblock 106, line 245-1,  t1226,  t501,  t503(SI24)
;;								## 18
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 106, line 244-1,  t505(SI24),  t504,  8(SI32)
;;								## 19
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 106, line 242-1,  t499,  t342,  28(SI32)
;;								## 20
	c0    cmplt $b0.1 = $r0.7, 1   ## [spec] bblock 106, line 239-2,  t1227(I1),  t518,  1(SI32)
;;								## 21
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 106, line 245-1,  t1225,  t499,  t505(SI24)
;;								## 22
	c0    add $r0.3 = $r0.3, $r0.11   ## [spec] bblock 106, line 245-1,  t507,  t1225,  t1226
;;								## 23
	c0    ldbu.d $r0.10 = 2[$r0.2]   ## [spec] bblock 103, line 241-2, t489, t516
;;								## 24
	c0    mpyl $r0.11 = $r0.3, 215   ## [spec] bblock 103, line 243-2,  t491,  t507,  215(SI32)
;;								## 25
	c0    mpyl $r0.12 = $r0.6, -155   ## [spec] bblock 103, line 244-2,  t493,  t341,  -155(SI32)
;;								## 26
	c0    mpyl $r0.13 = $r0.10, -48   ## [spec] bblock 103, line 241-2,  t490,  t489,  -48(SI32)
;;								## 27
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 103, line 243-2,  t492(SI24),  t491,  8(SI32)
;;								## 28
	c0    add $r0.13 = $r0.13, $r0.11   ## [spec] bblock 103, line 245-2,  t1223,  t490,  t492(SI24)
;;								## 29
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 103, line 244-2,  t494(SI24),  t493,  8(SI32)
;;								## 30
	c0    mpyl $r0.9 = $r0.9, 28   ## [spec] bblock 103, line 242-2,  t488,  t500,  28(SI32)
;;								## 31
	c0    cmplt $b0.2 = $r0.7, $r0.0   ## [spec] bblock 103, line 239-3,  t1224(I1),  t518,  0(SI32)
;;								## 32
	c0    add $r0.9 = $r0.9, $r0.12   ## [spec] bblock 103, line 245-2,  t1222,  t488,  t494(SI24)
;;								## 33
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 103, line 245-2,  t496,  t1222,  t1223
;;								## 34
	c0    ldbu.d $r0.11 = 3[$r0.2]   ## [spec] bblock 100, line 241-3, t258, t516
;;								## 35
	c0    mpyl $r0.12 = $r0.9, 215   ## [spec] bblock 100, line 243-3,  t483,  t496,  215(SI32)
;;								## 36
	c0    mpyl $r0.13 = $r0.3, -155   ## [spec] bblock 100, line 244-3,  t485,  t507,  -155(SI32)
;;								## 37
	c0    mpyl $r0.14 = $r0.11, -48   ## [spec] bblock 100, line 241-3,  t482,  t258,  -48(SI32)
;;								## 38
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 100, line 243-3,  t484(SI24),  t483,  8(SI32)
;;								## 39
	c0    add $r0.14 = $r0.14, $r0.12   ## [spec] bblock 100, line 245-3,  t1221,  t482,  t484(SI24)
;;								## 40
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 100, line 244-3,  t486(SI24),  t485,  8(SI32)
;;								## 41
	c0    mpyl $r0.10 = $r0.10, 28   ## [spec] bblock 100, line 242-3,  t453,  t489,  28(SI32)
;;								## 42
	c0    mov $r0.5 = $r0.9   ## [spec] bblock 100, line 245-2,  t255,  t496
;;								## 43
	c0    add $r0.10 = $r0.10, $r0.13   ## [spec] bblock 100, line 245-3,  t1220,  t453,  t486(SI24)
;;								## 44
	c0    add $r0.4 = $r0.10, $r0.14   ## [spec] bblock 100, line 245-3,  t256,  t1220,  t1221
;;								## 45
	c0    add $r0.2 = $r0.2, 4   ## [spec] bblock 100, line 0,  t516,  t516,  4(I32)
;;								## 46
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 100, line 0,  t518,  t518,  4(I32)
;;								## 47
	c0    stw 0[$r0.8] = $r0.6   ## bblock 39, line 245, t517, t341
;;								## 48
	c0    brf $b0.0, L52?3   ## bblock 39, line 239-1,  t1188(I1)
;;								## 49
	c0    mov $r0.6 = $r0.11   ## [spec] t258
;;								## 50
	c0    stw 4[$r0.8] = $r0.3   ## bblock 106, line 245-1, t517, t507
;;								## 51
	c0    brf $b0.1, L52?3   ## bblock 106, line 239-2,  t1227(I1)
;;								## 52
	c0    stw 8[$r0.8] = $r0.9   ## bblock 103, line 245-2, t517, t496
;;								## 53
	c0    brf $b0.2, L52?3   ## bblock 103, line 239-3,  t1224(I1)
;;								## 54
	c0    stw 12[$r0.8] = $r0.4   ## bblock 100, line 245-3, t517, t256
;;								## 55
	c0    add $r0.8 = $r0.8, 16   ## bblock 100, line 0,  t517,  t517,  16(I32)
	      ## goto
;;
	c0    goto L51?3 ## goto
;;								## 56
.trace 25
L52?3:
	c0    add $r0.11 = $r0.18, 1050   ## bblock 38, line 0,  t1113,  t1113,  1050(I32)
;;								## 0
	c0    add $r0.10 = $r0.17, 4200   ## bblock 38, line 0,  t1115,  t1115,  4200(I32)
;;								## 1
	c0    add $r0.3 = $r0.15, 1   ## bblock 38, line 0,  t1116,  t1116,  1(I32)
;;								## 2
	c0    mov $r0.9 = $r0.16   ## t227
	      ## goto
;;
	c0    goto L49?3 ## goto
;;								## 3
.trace 48
L50?3:
	c0    sub $r0.2 = $r0.0, $r0.19   ## bblock 2, line 0,  t1074,  0(I32),  t226
;;								## 0
	c0    mov $r0.10 = $r0.2   ## bblock 2, line 0,  t1073,  t1074
;;								## 1
	c0    mov $r0.13 = ((qy2 + 0) + (~0xb))   ## bblock 2, line 0,  t1071,  (addr(qy2?1.0)(P32) + 0xfffffff4(I32))(P32)
;;								## 2
	c0    add $r0.12 = $r0.9, -1   ## bblock 2, line 260,  t321,  t227,  -1(SI32)
;;								## 3
	c0    mov $r0.11 = ((in + 0) + (~0x2))   ## bblock 2, line 0,  t1072,  (addr(in?1.0)(P32) + 0xfffffffd(I32))(P32)
;;								## 4
	c0    mov $r0.20 = $r0.19   ## t226
;;								## 5
	c0    mov $r0.21 = $r0.9   ## t227
;;								## 6
.trace 18
L53?3:
	c0    cmplt $b0.0 = $r0.10, $r0.0   ## bblock 3, line 258,  t1163(I1),  t1073,  0(SI32)
;;								## 0
	c0    add $r0.8 = $r0.11, $r0.12   ## [spec] bblock 32, line 0,  t566,  t1072,  t321
;;								## 1
	c0    brf $b0.0, L54?3   ## bblock 3, line 258,  t1163(I1)
;;								## 2
	c0    sh2add $r0.7 = $r0.12, $r0.13   ## bblock 32, line 0,  t565,  t321,  t1071
;;								## 3
	c0    mov $r0.2 = $r0.0   ## bblock 32, line 259,  t344,  0(SI32)
;;								## 4
	c0    mov $r0.4 = $r0.0   ## bblock 32, line 259,  t336,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 32, line 259,  t340,  0(SI32)
;;								## 6
	c0    mov $r0.3 = $r0.0   ## bblock 32, line 259,  t334,  0(SI32)
;;								## 7
	c0    mov $r0.6 = $r0.12   ## bblock 32, line 260,  t333,  t321
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
L55?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 35, line 264,  t476,  t344,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 35, line 261,  t368,  t334,  -47(SI32)
;;								## 1
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 35, line 264,  t475(SI24),  t476,  8(SI32)
;;								## 2
	c0    add $r0.9 = $r0.9, $r0.2   ## [spec] bblock 35, line 265,  t1182,  t368,  t475(SI24)
;;								## 3
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 35, line 263,  t364,  t336,  215(SI32)
;;								## 4
	c0    mpyl $r0.5 = $r0.5, -48   ## [spec] bblock 35, line 262,  t346,  t340,  -48(SI32)
;;								## 5
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 35, line 263,  t367(SI24),  t364,  8(SI32)
;;								## 6
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 35, line 265,  t1183,  t346,  t367(SI24)
;;								## 7
	c0    add $r0.9 = $r0.9, $r0.5   ## [spec] bblock 35, line 265,  t365,  t1182,  t1183
;;								## 8
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 33, line 260,  t1181(I1),  t333,  0(SI32)
;;								## 9
	c0    ldbu.d $r0.10 = 3[$r0.8]   ## [spec] bblock 35, line 267, t361, t566
;;								## 10
	c0    brf $b0.0, L56?3   ## bblock 33, line 260,  t1181(I1)
;;								## 11
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 35, line 260-1,  t1184(I1),  t333,  1(SI32)
;;								## 12
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 96, line 264-1,  t477,  t336,  -155(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.10, -47   ## [spec] bblock 96, line 261-1,  t68,  t361,  -47(SI32)
;;								## 14
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 96, line 264-1,  t65(SI24),  t477,  8(SI32)
;;								## 15
	c0    add $r0.11 = $r0.11, $r0.4   ## [spec] bblock 96, line 265-1,  t1217,  t68,  t65(SI24)
;;								## 16
	c0    mpyl $r0.12 = $r0.9, 215   ## [spec] bblock 96, line 263-1,  t59,  t365,  215(SI32)
;;								## 17
	c0    mpyl $r0.3 = $r0.3, -48   ## [spec] bblock 96, line 262-1,  t67,  t334,  -48(SI32)
;;								## 18
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 96, line 263-1,  t478(SI24),  t59,  8(SI32)
;;								## 19
	c0    add $r0.3 = $r0.3, $r0.12   ## [spec] bblock 96, line 265-1,  t1218,  t67,  t478(SI24)
;;								## 20
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 96, line 265-1,  t250,  t1217,  t1218
;;								## 21
	c0    ldbu.d $r0.12 = 2[$r0.8]   ## [spec] bblock 96, line 267-1, t254, t566
;;								## 22
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 96, line 260-2,  t1219(I1),  t333,  2(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.9, -155   ## [spec] bblock 93, line 264-2,  t63,  t365,  -155(SI32)
;;								## 24
	c0    mpyl $r0.14 = $r0.12, -47   ## [spec] bblock 93, line 261-2,  t332,  t254,  -47(SI32)
;;								## 25
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 93, line 264-2,  t325(SI24),  t63,  8(SI32)
;;								## 26
	c0    add $r0.14 = $r0.14, $r0.13   ## [spec] bblock 93, line 265-2,  t1214,  t332,  t325(SI24)
;;								## 27
	c0    mpyl $r0.13 = $r0.11, 215   ## [spec] bblock 93, line 263-2,  t330,  t250,  215(SI32)
;;								## 28
	c0    mpyl $r0.10 = $r0.10, -48   ## [spec] bblock 93, line 262-2,  t329,  t361,  -48(SI32)
;;								## 29
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 93, line 263-2,  t66(SI24),  t330,  8(SI32)
;;								## 30
	c0    add $r0.10 = $r0.10, $r0.13   ## [spec] bblock 93, line 265-2,  t1215,  t329,  t66(SI24)
;;								## 31
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 93, line 265-2,  t327,  t1214,  t1215
;;								## 32
	c0    ldbu.d $r0.10 = 1[$r0.8]   ## [spec] bblock 93, line 267-2, t323, t566
;;								## 33
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 93, line 260-3,  t1216(I1),  t333,  3(SI32)
;;								## 34
	c0    mpyl $r0.13 = $r0.11, -155   ## [spec] bblock 90, line 264-3,  t337,  t250,  -155(SI32)
;;								## 35
	c0    mpyl $r0.15 = $r0.10, -47   ## [spec] bblock 90, line 261-3,  t481,  t323,  -47(SI32)
;;								## 36
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 90, line 264-3,  t479(SI24),  t337,  8(SI32)
;;								## 37
	c0    add $r0.15 = $r0.15, $r0.13   ## [spec] bblock 90, line 265-3,  t1212,  t481,  t479(SI24)
;;								## 38
	c0    mpyl $r0.13 = $r0.14, 215   ## [spec] bblock 90, line 263-3,  t339,  t327,  215(SI32)
;;								## 39
	c0    mpyl $r0.12 = $r0.12, -48   ## [spec] bblock 90, line 262-3,  t480,  t254,  -48(SI32)
;;								## 40
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 90, line 263-3,  t338(SI24),  t339,  8(SI32)
;;								## 41
	c0    add $r0.12 = $r0.12, $r0.13   ## [spec] bblock 90, line 265-3,  t1213,  t480,  t338(SI24)
;;								## 42
	c0    add $r0.4 = $r0.15, $r0.12   ## [spec] bblock 90, line 265-3,  t336,  t1212,  t1213
;;								## 43
	c0    ldbu.d $r0.3 = 0[$r0.8]   ## [spec] bblock 90, line 267-3, t334, t566
;;								## 44
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 90, line 260-3,  t333,  t333,  -4(SI32)
;;								## 45
	c0    mov $r0.5 = $r0.10   ## [spec] bblock 90, line 267-2,  t340,  t323
;;								## 46
	c0    mov $r0.2 = $r0.14   ## [spec] bblock 90, line 265-2,  t344,  t327
;;								## 47
	c0    add $r0.8 = $r0.8, (~0x3)   ## [spec] bblock 90, line 0,  t566,  t566,  (~0x3)(I32)
;;								## 48
	c0    stw 12[$r0.7] = $r0.9   ## bblock 35, line 265, t565, t365
;;								## 49
	c0    brf $b0.0, L57?3   ## bblock 35, line 260-1,  t1184(I1)
;;								## 50
	c0    stw 8[$r0.7] = $r0.11   ## bblock 96, line 265-1, t565, t250
;;								## 51
	c0    brf $b0.1, L58?3   ## bblock 96, line 260-2,  t1219(I1)
;;								## 52
	c0    stw 4[$r0.7] = $r0.14   ## bblock 93, line 265-2, t565, t327
;;								## 53
	c0    brf $b0.2, L59?3   ## bblock 93, line 260-3,  t1216(I1)
;;								## 54
	c0    stw 0[$r0.7] = $r0.4   ## bblock 90, line 265-3, t565, t336
;;								## 55
	c0    add $r0.7 = $r0.7, (~0xf)   ## bblock 90, line 0,  t565,  t565,  (~0xf)(I32)
	      ## goto
;;
	c0    goto L55?3 ## goto
;;								## 56
.trace 43
L59?3:
	c0    add $r0.13 = $r0.19, 4200   ## bblock 34, line 0,  t1071,  t1071,  4200(I32)
	      ## goto
;;
	c0    goto L60?3 ## goto
;;								## 0
.trace 36
L58?3:
	c0    add $r0.13 = $r0.19, 4200   ## bblock 34, line 0,  t1071,  t1071,  4200(I32)
	      ## goto
;;
	c0    goto L60?3 ## goto
;;								## 0
.trace 30
L57?3:
	c0    add $r0.13 = $r0.19, 4200   ## bblock 34, line 0,  t1071,  t1071,  4200(I32)
	      ## goto
;;
	c0    goto L60?3 ## goto
;;								## 0
.trace 24
L56?3:
	c0    add $r0.13 = $r0.19, 4200   ## bblock 34, line 0,  t1071,  t1071,  4200(I32)
;;								## 0
L60?3:
	c0    add $r0.11 = $r0.17, 1050   ## bblock 34, line 0,  t1072,  t1072,  1050(I32)
;;								## 1
	c0    add $r0.10 = $r0.16, 1   ## bblock 34, line 0,  t1073,  t1073,  1(I32)
;;								## 2
	c0    mov $r0.12 = $r0.18   ## t321
	      ## goto
;;
	c0    goto L53?3 ## goto
;;								## 3
.trace 49
L54?3:
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
L61?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 5, line 279,  t1164(I1),  t1025,  0(SI32)
;;								## 0
	c0    sub $r0.11 = 3, $r0.9   ## [spec] bblock 28, line 0,  t613,  3(I32),  t227
;;								## 1
	c0    brf $b0.0, L62?3   ## bblock 5, line 279,  t1164(I1)
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
L63?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 31, line 281, t370, t609
;;								## 0
	c0    ldw.d $r0.7 = 0[$r0.4]   ## [spec] bblock 31, line 281, t381, t610
;;								## 1
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 29, line 280,  t1179(I1),  t612,  3(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 31, line 280-1,  t1180(I1),  t612,  2(SI32)
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.7   ## [spec] bblock 31, line 281,  t472,  t370,  t381
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## [spec] bblock 31, line 281,  t471,  t472,  8(I32)
;;								## 5
	c0    shr $r0.3 = $r0.3, 8   ## [spec] bblock 31, line 281,  t380(SI24),  t471,  8(SI32)
;;								## 6
	c0    brf $b0.0, L64?3   ## bblock 29, line 280,  t1179(I1)
;;								## 7
	c0    ldw.d $r0.7 = 4[$r0.2]   ## [spec] bblock 86, line 281-1, t94, t609
;;								## 8
	c0    ldw.d $r0.8 = 4[$r0.4]   ## [spec] bblock 86, line 281-1, t98, t610
;;								## 9
	c0    cmplt $b0.0 = $r0.5, 1   ## [spec] bblock 86, line 280-2,  t1211(I1),  t612,  1(SI32)
;;								## 10
	c0    ldw.d $r0.9 = 8[$r0.2]   ## [spec] bblock 83, line 281-2, t349, t609
;;								## 11
	c0    add $r0.7 = $r0.7, $r0.8   ## [spec] bblock 86, line 281-1,  t99,  t94,  t98
;;								## 12
	c0    shl $r0.7 = $r0.7, 8   ## [spec] bblock 86, line 281-1,  t101,  t99,  8(I32)
;;								## 13
	c0    shr $r0.7 = $r0.7, 8   ## [spec] bblock 86, line 281-1,  t372(SI24),  t101,  8(SI32)
;;								## 14
	c0    ldw.d $r0.8 = 8[$r0.4]   ## [spec] bblock 83, line 281-2, t352, t610
;;								## 15
	c0    cmplt $b0.2 = $r0.5, $r0.0   ## [spec] bblock 83, line 280-3,  t1210(I1),  t612,  0(SI32)
;;								## 16
	c0    ldw.d $r0.10 = 12[$r0.2]   ## [spec] bblock 80, line 281-3, t359, t609
;;								## 17
	c0    add $r0.9 = $r0.9, $r0.8   ## [spec] bblock 83, line 281-2,  t351,  t349,  t352
;;								## 18
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 83, line 281-2,  t350,  t351,  8(I32)
;;								## 19
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 83, line 281-2,  t102(SI24),  t350,  8(SI32)
;;								## 20
	c0    ldw.d $r0.8 = 12[$r0.4]   ## [spec] bblock 80, line 281-3, t358, t610
;;								## 21
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 80, line 0,  t609,  t609,  16(I32)
;;								## 22
	c0    add $r0.4 = $r0.4, 16   ## [spec] bblock 80, line 0,  t610,  t610,  16(I32)
;;								## 23
	c0    add $r0.10 = $r0.10, $r0.8   ## [spec] bblock 80, line 281-3,  t357,  t359,  t358
;;								## 24
	c0    shl $r0.10 = $r0.10, 8   ## [spec] bblock 80, line 281-3,  t356,  t357,  8(I32)
;;								## 25
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 80, line 281-3,  t355(SI24),  t356,  8(SI32)
;;								## 26
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 80, line 0,  t612,  t612,  4(I32)
;;								## 27
	c0    stw 0[$r0.6] = $r0.3   ## bblock 31, line 281, t611, t380(SI24)
;;								## 28
	c0    brf $b0.1, L64?3   ## bblock 31, line 280-1,  t1180(I1)
;;								## 29
	c0    stw 4[$r0.6] = $r0.7   ## bblock 86, line 281-1, t611, t372(SI24)
;;								## 30
	c0    brf $b0.0, L64?3   ## bblock 86, line 280-2,  t1211(I1)
;;								## 31
	c0    stw 8[$r0.6] = $r0.9   ## bblock 83, line 281-2, t611, t102(SI24)
;;								## 32
	c0    brf $b0.2, L64?3   ## bblock 83, line 280-3,  t1210(I1)
;;								## 33
	c0    stw 12[$r0.6] = $r0.10   ## bblock 80, line 281-3, t611, t355(SI24)
;;								## 34
	c0    add $r0.6 = $r0.6, 16   ## bblock 80, line 0,  t611,  t611,  16(I32)
	      ## goto
;;
	c0    goto L63?3 ## goto
;;								## 35
.trace 23
L64?3:
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
	c0    goto L61?3 ## goto
;;								## 5
.trace 50
L62?3:
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
L65?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 7, line 289,  t1165(I1),  t990,  0(SI32)
;;								## 0
	c0    sub $r0.13 = 3, $r0.10   ## [spec] bblock 24, line 0,  t676,  3(I32),  t226
;;								## 1
	c0    brf $b0.0, L66?3   ## bblock 7, line 289,  t1165(I1)
;;								## 2
	c0    mov $r0.7 = $r0.13   ## bblock 24, line 0,  t675,  t676
;;								## 3
	c0    mov $r0.8 = $r0.11   ## bblock 24, line 0,  t674,  t989
;;								## 4
	c0    mov $r0.2 = $r0.12   ## bblock 24, line 0,  t673,  t988
;;								## 5
	c0    mov $r0.6 = $r0.0   ## bblock 24, line 290,  t384,  0(SI32)
;;								## 6
	c0    mov $r0.5 = $r0.0   ## bblock 24, line 290,  t382(SI24),  0(SI32)
;;								## 7
	c0    mov $r0.4 = $r0.0   ## bblock 24, line 290,  t383,  0(SI32)
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
L67?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 27, line 292, t466, t673
;;								## 0
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 27, line 292,  t406,  t383,  -155(SI32)
;;								## 1
	c0    mpyl $r0.9 = $r0.5, 215   ## [spec] bblock 27, line 292,  t387,  t382(SI24),  215(SI32)
;;								## 2
	c0    mpyl $r0.10 = $r0.3, -48   ## [spec] bblock 27, line 292,  t404,  t466,  -48(SI32)
;;								## 3
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 27, line 292,  t401,  t384,  28(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.10   ## [spec] bblock 27, line 292,  t1176,  t406,  t404
;;								## 5
	c0    add $r0.9 = $r0.9, $r0.6   ## [spec] bblock 27, line 292,  t1177,  t387,  t401
;;								## 6
	c0    add $r0.4 = $r0.4, $r0.9   ## [spec] bblock 27, line 292,  t403,  t1176,  t1177
;;								## 7
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 27, line 292,  t1155,  t403,  8(SI32)
;;								## 8
	c0    cmplt $b0.0 = $r0.7, 3   ## bblock 25, line 291,  t1175(I1),  t675,  3(SI32)
;;								## 9
	c0    cmplt $b0.1 = $r0.7, 2   ## [spec] bblock 27, line 291-1,  t1178(I1),  t675,  2(SI32)
;;								## 10
	c0    brf $b0.0, L68?3   ## bblock 25, line 291,  t1175(I1)
;;								## 11
	c0    ldw.d $r0.9 = 4200[$r0.2]   ## [spec] bblock 76, line 292-1, t473, t673
;;								## 12
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 76, line 292-1,  t116,  t382(SI24),  -155(SI32)
;;								## 13
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 76, line 292-1,  t119,  t1155,  215(SI32)
;;								## 14
	c0    mpyl $r0.11 = $r0.9, -48   ## [spec] bblock 76, line 292-1,  t128,  t473,  -48(SI32)
;;								## 15
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 76, line 292-1,  t122,  t466,  28(SI32)
;;								## 16
	c0    add $r0.5 = $r0.5, $r0.11   ## [spec] bblock 76, line 292-1,  t1207,  t116,  t128
;;								## 17
	c0    add $r0.10 = $r0.10, $r0.3   ## [spec] bblock 76, line 292-1,  t1208,  t119,  t122
;;								## 18
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 76, line 292-1,  t129,  t1207,  t1208
;;								## 19
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 76, line 292-1,  t1156,  t129,  8(SI32)
;;								## 20
	c0    cmplt $b0.0 = $r0.7, 1   ## [spec] bblock 76, line 291-2,  t1209(I1),  t675,  1(SI32)
;;								## 21
	c0    ldw.d $r0.3 = 8400[$r0.2]   ## [spec] bblock 73, line 292-2, t257, t673
;;								## 22
	c0    mpyl $r0.10 = $r0.4, -155   ## [spec] bblock 73, line 292-2,  t378,  t1155,  -155(SI32)
;;								## 23
	c0    mpyl $r0.11 = $r0.5, 215   ## [spec] bblock 73, line 292-2,  t376,  t1156,  215(SI32)
;;								## 24
	c0    mpyl $r0.12 = $r0.3, -48   ## [spec] bblock 73, line 292-2,  t375,  t257,  -48(SI32)
;;								## 25
	c0    mpyl $r0.9 = $r0.9, 28   ## [spec] bblock 73, line 292-2,  t470,  t473,  28(SI32)
;;								## 26
	c0    add $r0.10 = $r0.10, $r0.12   ## [spec] bblock 73, line 292-2,  t1204,  t378,  t375
;;								## 27
	c0    add $r0.11 = $r0.11, $r0.9   ## [spec] bblock 73, line 292-2,  t1205,  t376,  t470
;;								## 28
	c0    add $r0.10 = $r0.10, $r0.11   ## [spec] bblock 73, line 292-2,  t374,  t1204,  t1205
;;								## 29
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 73, line 292-2,  t1157,  t374,  8(SI32)
;;								## 30
	c0    cmplt $b0.2 = $r0.7, $r0.0   ## [spec] bblock 73, line 291-3,  t1206(I1),  t675,  0(SI32)
;;								## 31
	c0    ldw.d $r0.6 = 12600[$r0.2]   ## [spec] bblock 70, line 292-3, t384, t673
;;								## 32
	c0    mpyl $r0.9 = $r0.5, -155   ## [spec] bblock 70, line 292-3,  t393,  t1156,  -155(SI32)
;;								## 33
	c0    mpyl $r0.11 = $r0.10, 215   ## [spec] bblock 70, line 292-3,  t392,  t1157,  215(SI32)
;;								## 34
	c0    mpyl $r0.12 = $r0.6, -48   ## [spec] bblock 70, line 292-3,  t386,  t384,  -48(SI32)
;;								## 35
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 70, line 292-3,  t391,  t257,  28(SI32)
;;								## 36
	c0    add $r0.9 = $r0.9, $r0.12   ## [spec] bblock 70, line 292-3,  t1202,  t393,  t386
;;								## 37
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 70, line 292-3,  t1203,  t392,  t391
;;								## 38
	c0    add $r0.9 = $r0.9, $r0.11   ## [spec] bblock 70, line 292-3,  t385,  t1202,  t1203
;;								## 39
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 70, line 292-3,  t382(SI24),  t385,  8(SI32)
;;								## 40
	c0    stw 0[$r0.8] = $r0.4   ## bblock 27, line 292, t674, t1155
;;								## 41
	c0    brf $b0.1, L68?3   ## bblock 27, line 291-1,  t1178(I1)
;;								## 42
	c0    mov $r0.4 = $r0.10   ## [spec] bblock 70, line 292-2,  t383,  t1157
;;								## 43
	c0    add $r0.2 = $r0.2, 16800   ## [spec] bblock 70, line 0,  t673,  t673,  16800(I32)
;;								## 44
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 70, line 0,  t675,  t675,  4(I32)
;;								## 45
	c0    stw 4200[$r0.8] = $r0.5   ## bblock 76, line 292-1, t674, t1156
;;								## 46
	c0    brf $b0.0, L68?3   ## bblock 76, line 291-2,  t1209(I1)
;;								## 47
	c0    mov $r0.5 = $r0.9   ## [spec] t382(SI24)
;;								## 48
	c0    stw 8400[$r0.8] = $r0.10   ## bblock 73, line 292-2, t674, t1157
;;								## 49
	c0    brf $b0.2, L68?3   ## bblock 73, line 291-3,  t1206(I1)
;;								## 50
	c0    stw 12600[$r0.8] = $r0.9   ## bblock 70, line 292-3, t674, t382(SI24)
;;								## 51
	c0    add $r0.8 = $r0.8, 16800   ## bblock 70, line 0,  t674,  t674,  16800(I32)
	      ## goto
;;
	c0    goto L67?3 ## goto
;;								## 52
.trace 27
L68?3:
	c0    add $r0.12 = $r0.16, 4   ## bblock 26, line 0,  t988,  t988,  4(I32)
;;								## 0
	c0    add $r0.11 = $r0.15, 4   ## bblock 26, line 0,  t989,  t989,  4(I32)
;;								## 1
	c0    add $r0.3 = $r0.13, 1   ## bblock 26, line 0,  t990,  t990,  1(I32)
;;								## 2
	c0    mov $r0.10 = $r0.14   ## t226
	      ## goto
;;
	c0    goto L65?3 ## goto
;;								## 3
.trace 51
L66?3:
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
	c0    add $r0.11 = $r0.20, -1   ## bblock 8, line 307,  t322,  t226,  -1(SI32)
;;								## 5
	c0    mov $r0.19 = $r0.17   ## t227
;;								## 6
.trace 21
L69?3:
	c0    cmplt $b0.0 = $r0.10, $r0.0   ## bblock 9, line 305,  t1166(I1),  t957,  0(SI32)
;;								## 0
	c0    mpylu $r0.14 = $r0.11, 4200   ## [spec] bblock 20, line 0,  t766,  t322,  4200(I32)
;;								## 1
	c0    brf $b0.0, L70?3   ## bblock 9, line 305,  t1166(I1)
;;								## 2
	c0    add $r0.8 = $r0.12, $r0.14   ## bblock 20, line 0,  t756,  t956,  t766
;;								## 3
	c0    add $r0.7 = $r0.13, $r0.14   ## bblock 20, line 0,  t755,  t955,  t766
;;								## 4
	c0    mov $r0.3 = $r0.0   ## bblock 20, line 306,  t412,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 20, line 306,  t411,  0(SI32)
;;								## 6
	c0    mov $r0.4 = $r0.0   ## bblock 20, line 306,  t410(SI24),  0(SI32)
;;								## 7
	c0    mov $r0.2 = $r0.0   ## bblock 20, line 306,  t409,  0(SI32)
;;								## 8
	c0    mov $r0.6 = $r0.11   ## bblock 20, line 307,  t415,  t322
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
L71?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 23, line 308,  t430,  t409,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 23, line 308,  t461,  t412,  -47(SI32)
;;								## 1
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 23, line 308,  t413,  t410(SI24),  215(SI32)
;;								## 2
	c0    add $r0.2 = $r0.2, $r0.9   ## [spec] bblock 23, line 308,  t1172,  t430,  t461
;;								## 3
	c0    mpyl $r0.5 = $r0.5, 29   ## [spec] bblock 23, line 308,  t425,  t411,  29(SI32)
;;								## 4
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 21, line 307,  t1171(I1),  t415,  0(SI32)
;;								## 5
	c0    add $r0.10 = $r0.10, $r0.5   ## [spec] bblock 23, line 308,  t1173,  t413,  t425
;;								## 6
	c0    add $r0.2 = $r0.2, $r0.10   ## [spec] bblock 23, line 308,  t460,  t1172,  t1173
;;								## 7
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 23, line 308,  t1158,  t460,  8(SI32)
;;								## 8
	c0    brf $b0.0, L72?3   ## bblock 21, line 307,  t1171(I1)
;;								## 9
	c0    ldw $r0.9 = 12600[$r0.8]   ## bblock 23, line 310, t424, t756
;;								## 10
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 23, line 307-1,  t1174(I1),  t415,  1(SI32)
;;								## 11
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 66, line 308-1,  t463,  t410(SI24),  -155(SI32)
;;								## 12
	c0    mpyl $r0.10 = $r0.9, -47   ## [spec] bblock 66, line 308-1,  t395,  t424,  -47(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.2, 215   ## [spec] bblock 66, line 308-1,  t157,  t1158,  215(SI32)
;;								## 14
	c0    add $r0.4 = $r0.4, $r0.10   ## [spec] bblock 66, line 308-1,  t1199,  t463,  t395
;;								## 15
	c0    mpyl $r0.3 = $r0.3, 29   ## [spec] bblock 66, line 308-1,  t160,  t412,  29(SI32)
;;								## 16
	c0    ldw.d $r0.10 = 8400[$r0.8]   ## [spec] bblock 66, line 310-1, t252, t756
;;								## 17
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 66, line 308-1,  t1200,  t157,  t160
;;								## 18
	c0    add $r0.4 = $r0.4, $r0.11   ## [spec] bblock 66, line 308-1,  t394,  t1199,  t1200
;;								## 19
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 66, line 308-1,  t1159,  t394,  8(SI32)
;;								## 20
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 66, line 307-2,  t1201(I1),  t415,  2(SI32)
;;								## 21
	c0    mpyl $r0.11 = $r0.2, -155   ## [spec] bblock 63, line 308-2,  t154,  t1158,  -155(SI32)
;;								## 22
	c0    mpyl $r0.12 = $r0.10, -47   ## [spec] bblock 63, line 308-2,  t163,  t252,  -47(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.4, 215   ## [spec] bblock 63, line 308-2,  t408,  t1159,  215(SI32)
;;								## 24
	c0    add $r0.11 = $r0.11, $r0.12   ## [spec] bblock 63, line 308-2,  t1196,  t154,  t163
;;								## 25
	c0    mpyl $r0.9 = $r0.9, 29   ## [spec] bblock 63, line 308-2,  t407,  t424,  29(SI32)
;;								## 26
	c0    ldw.d $r0.12 = 4200[$r0.8]   ## [spec] bblock 63, line 310-2, t398, t756
;;								## 27
	c0    add $r0.13 = $r0.13, $r0.9   ## [spec] bblock 63, line 308-2,  t1197,  t408,  t407
;;								## 28
	c0    add $r0.11 = $r0.11, $r0.13   ## [spec] bblock 63, line 308-2,  t164,  t1196,  t1197
;;								## 29
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 63, line 308-2,  t1160,  t164,  8(SI32)
;;								## 30
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 63, line 307-3,  t1198(I1),  t415,  3(SI32)
;;								## 31
	c0    mpyl $r0.9 = $r0.4, -155   ## [spec] bblock 60, line 308-3,  t421,  t1159,  -155(SI32)
;;								## 32
	c0    mpyl $r0.13 = $r0.12, -47   ## [spec] bblock 60, line 308-3,  t418,  t398,  -47(SI32)
;;								## 33
	c0    mpyl $r0.14 = $r0.11, 215   ## [spec] bblock 60, line 308-3,  t420,  t1160,  215(SI32)
;;								## 34
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 60, line 308-3,  t1194,  t421,  t418
;;								## 35
	c0    mpyl $r0.10 = $r0.10, 29   ## [spec] bblock 60, line 308-3,  t419,  t252,  29(SI32)
;;								## 36
	c0    ldw.d $r0.3 = 0[$r0.8]   ## [spec] bblock 60, line 310-3, t412, t756
;;								## 37
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 60, line 308-3,  t1195,  t420,  t419
;;								## 38
	c0    add $r0.9 = $r0.9, $r0.14   ## [spec] bblock 60, line 308-3,  t417,  t1194,  t1195
;;								## 39
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 60, line 308-3,  t410(SI24),  t417,  8(SI32)
;;								## 40
	c0    stw 12600[$r0.7] = $r0.2   ## bblock 23, line 308, t755, t1158
;;								## 41
	c0    brf $b0.0, L72?3   ## bblock 23, line 307-1,  t1174(I1)
;;								## 42
	c0    mov $r0.2 = $r0.11   ## [spec] bblock 60, line 308-2,  t409,  t1160
;;								## 43
	c0    mov $r0.5 = $r0.12   ## [spec] bblock 60, line 310-2,  t411,  t398
;;								## 44
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 60, line 307-3,  t415,  t415,  -4(SI32)
;;								## 45
	c0    add $r0.8 = $r0.8, (~0x419f)   ## [spec] bblock 60, line 0,  t756,  t756,  (~0x419f)(I32)
;;								## 46
	c0    stw 8400[$r0.7] = $r0.4   ## bblock 66, line 308-1, t755, t1159
;;								## 47
	c0    brf $b0.1, L72?3   ## bblock 66, line 307-2,  t1201(I1)
;;								## 48
	c0    mov $r0.4 = $r0.9   ## [spec] t410(SI24)
;;								## 49
	c0    stw 4200[$r0.7] = $r0.11   ## bblock 63, line 308-2, t755, t1160
;;								## 50
	c0    brf $b0.2, L72?3   ## bblock 63, line 307-3,  t1198(I1)
;;								## 51
	c0    stw 0[$r0.7] = $r0.9   ## bblock 60, line 308-3, t755, t410(SI24)
;;								## 52
	c0    add $r0.7 = $r0.7, (~0x419f)   ## bblock 60, line 0,  t755,  t755,  (~0x419f)(I32)
	      ## goto
;;
	c0    goto L71?3 ## goto
;;								## 53
.trace 26
L72?3:
	c0    add $r0.13 = $r0.18, 4   ## bblock 22, line 0,  t955,  t955,  4(I32)
;;								## 0
	c0    add $r0.12 = $r0.17, 4   ## bblock 22, line 0,  t956,  t956,  4(I32)
;;								## 1
	c0    add $r0.10 = $r0.15, 1   ## bblock 22, line 0,  t957,  t957,  1(I32)
;;								## 2
	c0    mov $r0.11 = $r0.16   ## t322
	      ## goto
;;
	c0    goto L69?3 ## goto
;;								## 3
.trace 52
L70?3:
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
L73?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 11, line 323,  t1167(I1),  t910,  0(SI32)
;;								## 0
	c0    sub $r0.12 = 3, $r0.9   ## [spec] bblock 13, line 0,  t837,  3(I32),  t227
;;								## 1
	c0    brf $b0.0, L74?3   ## bblock 11, line 323,  t1167(I1)
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
L75?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 16, line 325, t455, t832
;;								## 0
	c0    ldw.d $r0.8 = 0[$r0.4]   ## [spec] bblock 16, line 325, t454, t833
;;								## 1
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 14, line 324,  t1168(I1),  t836,  3(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 18, line 324-1,  t1170(I1),  t836,  2(SI32)
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.8   ## [spec] bblock 16, line 325,  t445,  t455,  t454
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## [spec] bblock 16, line 325,  t444,  t445,  8(I32)
;;								## 5
	c0    shr $r0.3 = $r0.3, 16   ## [spec] bblock 16, line 325,  t443(SI16),  t444,  16(SI32)
;;								## 6
	c0    brf $b0.0, L76?3   ## bblock 14, line 324,  t1168(I1)
;;								## 7
	c0    zxtb $r0.8 = $r0.3   ## bblock 16, line 325,  t442(I8),  t443(SI16)
;;								## 8
	c0    cmpgt $b0.0 = $r0.8, 25   ## bblock 16, line 326,  t1169(I1),  t442(I8),  25(SI32)
;;								## 9
	c0    ldw.d $r0.9 = 4[$r0.2]   ## [spec] bblock 53, line 325-1, t190, t832
;;								## 10
	c0    ldw.d $r0.8 = 4[$r0.4]   ## [spec] bblock 53, line 325-1, t194, t833
;;								## 11
	c0    cmplt $b0.2 = $r0.5, 1   ## [spec] bblock 55, line 324-2,  t1193(I1),  t836,  1(SI32)
;;								## 12
	c0    ldw.d $r0.10 = 8[$r0.2]   ## [spec] bblock 47, line 325-2, t437, t832
;;								## 13
	c0    add $r0.9 = $r0.9, $r0.8   ## [spec] bblock 53, line 325-1,  t459,  t190,  t194
;;								## 14
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 53, line 325-1,  t458,  t459,  8(I32)
;;								## 15
	c0    shr $r0.9 = $r0.9, 16   ## [spec] bblock 53, line 325-1,  t198(SI16),  t458,  16(SI32)
;;								## 16
	c0    zxtb $r0.8 = $r0.9   ## [spec] bblock 53, line 325-1,  t423(I8),  t198(SI16)
;;								## 17
	c0    cmpgt $b0.3 = $r0.8, 25   ## [spec] bblock 53, line 326-1,  t1192(I1),  t423(I8),  25(SI32)
;;								## 18
	c0    ldw.d $r0.11 = 8[$r0.4]   ## [spec] bblock 47, line 325-2, t433, t833
;;								## 19
	c0    cmplt $b0.4 = $r0.5, $r0.0   ## [spec] bblock 49, line 324-3,  t1191(I1),  t836,  0(SI32)
;;								## 20
	c0    ldw.d $r0.8 = 12[$r0.2]   ## [spec] bblock 41, line 325-3, t450, t832
;;								## 21
	c0    add $r0.10 = $r0.10, $r0.11   ## [spec] bblock 47, line 325-2,  t195,  t437,  t433
;;								## 22
	c0    shl $r0.10 = $r0.10, 8   ## [spec] bblock 47, line 325-2,  t197,  t195,  8(I32)
;;								## 23
	c0    shr $r0.10 = $r0.10, 16   ## [spec] bblock 47, line 325-2,  t431(SI16),  t197,  16(SI32)
;;								## 24
	c0    zxtb $r0.11 = $r0.10   ## [spec] bblock 47, line 325-2,  t206(I8),  t431(SI16)
;;								## 25
	c0    cmpgt $b0.5 = $r0.11, 25   ## [spec] bblock 47, line 326-2,  t1190(I1),  t206(I8),  25(SI32)
;;								## 26
	c0    ldw.d $r0.12 = 12[$r0.4]   ## [spec] bblock 41, line 325-3, t449, t833
;;								## 27
	c0    stb 0[$r0.6] = $r0.3   ## bblock 16, line 325, t834, t443(SI16)
;;								## 28
	c0    brf $b0.0, L77?3   ## bblock 16, line 326,  t1169(I1)
;;								## 29
	c0    add $r0.8 = $r0.8, $r0.12   ## [spec] bblock 41, line 325-3,  t448,  t450,  t449
;;								## 30
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 41, line 325-3,  t447,  t448,  8(I32)
;;								## 31
	c0    shr $r0.8 = $r0.8, 16   ## [spec] bblock 41, line 325-3,  t441(SI16),  t447,  16(SI32)
;;								## 32
	c0    zxtb $r0.3 = $r0.8   ## [spec] bblock 41, line 325-3,  t440(I8),  t441(SI16)
;;								## 33
	c0    cmpgt $b0.0 = $r0.3, 25   ## [spec] bblock 41, line 326-3,  t1189(I1),  t440(I8),  25(SI32)
;;								## 34
	c0    stb 0[$r0.6] = $r0.0   ## bblock 19, line 327, t834, 0(I32)
;;								## 35
L78?3:
	c0    brf $b0.1, L76?3   ## bblock 18, line 324-1,  t1170(I1)
;;								## 36
	c0    stb 1[$r0.6] = $r0.9   ## bblock 53, line 325-1, t834, t198(SI16)
;;								## 37
	c0    brf $b0.3, L79?3   ## bblock 53, line 326-1,  t1192(I1)
;;								## 38
	c0    stb 1[$r0.6] = $r0.0   ## bblock 56, line 327-1, t834, 0(I32)
;;								## 39
L80?3:
	c0    brf $b0.2, L76?3   ## bblock 55, line 324-2,  t1193(I1)
;;								## 40
	c0    stb 2[$r0.6] = $r0.10   ## bblock 47, line 325-2, t834, t431(SI16)
;;								## 41
	c0    brf $b0.5, L81?3   ## bblock 47, line 326-2,  t1190(I1)
;;								## 42
	c0    stb 2[$r0.6] = $r0.0   ## bblock 50, line 327-2, t834, 0(I32)
;;								## 43
L82?3:
	c0    brf $b0.4, L76?3   ## bblock 49, line 324-3,  t1191(I1)
;;								## 44
	c0    stb 3[$r0.6] = $r0.8   ## bblock 41, line 325-3, t834, t441(SI16)
;;								## 45
	c0    brf $b0.0, L83?3   ## bblock 41, line 326-3,  t1189(I1)
;;								## 46
	c0    add $r0.2 = $r0.2, 16   ## bblock 43, line 0,  t832,  t832,  16(I32)
;;								## 47
	c0    add $r0.4 = $r0.4, 16   ## bblock 43, line 0,  t833,  t833,  16(I32)
;;								## 48
	c0    add $r0.7 = $r0.7, 4   ## bblock 43, line 0,  t835,  t835,  4(I32)
;;								## 49
	c0    add $r0.5 = $r0.5, 4   ## bblock 43, line 0,  t836,  t836,  4(I32)
;;								## 50
	c0    stb 3[$r0.6] = $r0.0   ## bblock 44, line 327-3, t834, 0(I32)
;;								## 51
L84?3:
	c0    add $r0.6 = $r0.6, 4   ## bblock 43, line 0,  t834,  t834,  4(I32)
	      ## goto
;;
	c0    goto L75?3 ## goto
;;								## 52
.trace 16
L83?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.5 = $r0.5, 4   ## bblock 43, line 0,  t836,  t836,  4(I32)
;;								## 1
	c0    add $r0.4 = $r0.4, 16   ## bblock 43, line 0,  t833,  t833,  16(I32)
;;								## 2
	c0    add $r0.2 = $r0.2, 16   ## bblock 43, line 0,  t832,  t832,  16(I32)
;;								## 3
	c0    stb 3[$r0.7] = $r0.3   ## bblock 42, line 329-3, t835, 255(I32)
;;								## 4
	c0    add $r0.7 = $r0.7, 4   ## bblock 43, line 0,  t835,  t835,  4(I32)
	      ## goto
;;
	c0    goto L84?3 ## goto
;;								## 5
.trace 28
L76?3:
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
	c0    goto L73?3 ## goto
;;								## 4
.trace 15
L81?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 2[$r0.7] = $r0.3   ## bblock 48, line 329-2, t835, 255(I32)
	      ## goto
;;
	c0    goto L82?3 ## goto
;;								## 1
.trace 14
L79?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 1[$r0.7] = $r0.3   ## bblock 54, line 329-1, t835, 255(I32)
	      ## goto
;;
	c0    goto L80?3 ## goto
;;								## 1
.trace 13
L77?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.8 = $r0.8, $r0.12   ## [spec] bblock 41, line 325-3,  t448,  t450,  t449
;;								## 1
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 41, line 325-3,  t447,  t448,  8(I32)
;;								## 2
	c0    shr $r0.8 = $r0.8, 16   ## [spec] bblock 41, line 325-3,  t441(SI16),  t447,  16(SI32)
;;								## 3
	c0    zxtb $r0.11 = $r0.8   ## [spec] bblock 41, line 325-3,  t440(I8),  t441(SI16)
;;								## 4
	c0    cmpgt $b0.0 = $r0.11, 25   ## [spec] bblock 41, line 326-3,  t1189(I1),  t440(I8),  25(SI32)
;;								## 5
	c0    stb 0[$r0.7] = $r0.3   ## bblock 17, line 329, t835, 255(I32)
	      ## goto
;;
	c0    goto L78?3 ## goto
;;								## 6
.trace 53
L74?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 12, line 339,  t214,  ?2.3?2auto_size(I32),  t213
;;								## 0
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
