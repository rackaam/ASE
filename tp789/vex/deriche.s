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
.trace 38
	c0    add $r0.1 = $r0.1, (-0xc0)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t314
;;								## 1
	c0    stw 0x8c[$r0.1] = $r0.57  ## spill ## t318
;;								## 2
	c0    stw 0x90[$r0.1] = $r0.58  ## spill ## t319
;;								## 3
	c0    stw 0x94[$r0.1] = $r0.59  ## spill ## t320
;;								## 4
	c0    stw 0x98[$r0.1] = $r0.60  ## spill ## t321
;;								## 5
	c0    stw 0x9c[$r0.1] = $r0.61  ## spill ## t322
;;								## 6
	c0    stw 0xa0[$r0.1] = $r0.62  ## spill ## t323
;;								## 7
	c0    stw 0xa4[$r0.1] = $r0.63  ## spill ## t324
;;								## 8
	c0    stw 0x80[$r0.1] = $r0.3  ## spill ## t327
;;								## 9
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 0, line 0,  t766,  0(I32),  t327
;;								## 10
	c0    mov $r0.2 = $r0.3   ## bblock 0, line 0,  t765,  t766
;;								## 11
	c0    mov $r0.5 = (in + 0)   ## bblock 0, line 0,  t762,  addr(in?1.0)(P32)
;;								## 12
	c0    mov $r0.3 = $r0.4   ## t328
;;								## 13
	c0    mov $r0.4 = (y1 + 0)   ## bblock 0, line 0,  t764,  addr(y1?1.0)(P32)
;;								## 14
.trace 15
L0?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 1, line 42,  t786(I1),  t765,  0(SI32)
;;								## 0
	c0    stw 0x60[$r0.1] = $r0.3  ## spill ## t328
;;								## 1
	c0    stw 0x64[$r0.1] = $r0.4  ## spill ## t764
;;								## 2
	c0    stw 0x68[$r0.1] = $r0.5  ## spill ## t762
;;								## 3
	c0    brf $b0.0, L1?3   ## bblock 1, line 42,  t786(I1)
;;								## 4
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 72, line 0,  t438,  0(I32),  t328
;;								## 5
	c0    mov $r0.57 = $r0.3   ## bblock 72, line 0,  t437,  t438
;;								## 6
	c0    mov $r0.62 = $r0.4   ## bblock 72, line 0,  t436,  t764
;;								## 7
	c0    mov $r0.61 = $r0.5   ## bblock 72, line 0,  t435,  t762
;;								## 8
	c0    mov $r0.60 = $r0.0   ## bblock 72, line 43,  t351,  0.000000e+00=0x0(F32)
;;								## 9
	c0    mov $r0.59 = $r0.0   ## bblock 72, line 43,  t349,  0.000000e+00=0x0(F32)
;;								## 10
	c0    mov $r0.58 = $r0.0   ## bblock 72, line 43,  t348,  0.000000e+00=0x0(F32)
;;								## 11
	c0    mov $r0.63 = $r0.2   ## t765
;;								## 12
.trace 2
L2?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 73, line 44,  t816(I1),  t437,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L3?3   ## bblock 73, line 44,  t816(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t348
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 75, line 45,  raddr(_r_mul)(P32),  t348,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x28[$r0.1] = $r0.3  ## spill ## t10
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 75, line 45,  t348,  t349
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t349
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 75, line 45,  raddr(_r_mul)(P32),  t349,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x2c[$r0.1] = $r0.3  ## spill ## t13
;;								## 10
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t351
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 75, line 45,  raddr(_r_mul)(P32),  t351,  1.102090e-01=0x3de1b542(F32)
;;								## 13
	c0    stw 0x30[$r0.1] = $r0.3  ## spill ## t16
;;								## 14
	c0    ldbu $r0.59 = 0[$r0.61]   ## bblock 75, line 45, t31(I8), t435
	      xnop 2
;;								## 17
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 18
.call _r_ilfloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ilfloat   ## bblock 75, line 45,  raddr(_r_ilfloat)(P32),  t31(I8)
;;								## 19
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
;;								## 20
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 75, line 45,  raddr(_r_mul)(P32),  t21,  -1.886820e-01=0xbe4135db(F32)
;;								## 21
	c0    stw 0x34[$r0.1] = $r0.3  ## spill ## t23
;;								## 22
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t10
;;								## 23
	c0    ldw $r0.4 = 0x2c[$r0.1]  ## restore ## t13
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 75, line 45,  raddr(_r_add)(P32),  t10,  t13
;;								## 26
	c0    ldw $r0.4 = 0x30[$r0.1]  ## restore ## t16
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 75, line 45,  raddr(_r_add)(P32),  t302,  t16
;;								## 29
	c0    ldw $r0.4 = 0x34[$r0.1]  ## restore ## t23
	      xnop 1
;;								## 31
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 75, line 45,  raddr(_r_add)(P32),  t303,  t23
;;								## 32
	c0    stw 0x38[$r0.1] = $r0.3  ## spill ## t349
;;								## 33
	c0    stw 0[$r0.62] = $r0.3   ## bblock 75, line 45, t436, t349
;;								## 34
	c0    mov $r0.3 = $r0.59   ## t31(I8)
;;								## 35
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ufloat   ## bblock 75, line 46,  raddr(_r_ufloat)(P32),  t31(I8)
;;								## 36
	c0    add $r0.61 = $r0.61, 1   ## bblock 75, line 0,  t435,  t435,  1(I32)
;;								## 37
	c0    add $r0.62 = $r0.62, 4   ## bblock 75, line 0,  t436,  t436,  4(I32)
;;								## 38
	c0    add $r0.57 = $r0.57, 1   ## bblock 75, line 0,  t437,  t437,  1(I32)
;;								## 39
	c0    ldw $r0.59 = 0x38[$r0.1]  ## restore ## t349
;;								## 40
	c0    mov $r0.60 = $r0.3   ## t351
;;								## 41
	c0    goto L2?3 ## goto
;;								## 42
.trace 27
L3?3:
	c0    ldw $r0.5 = 0x68[$r0.1]  ## restore ## t762
;;								## 0
	c0    ldw $r0.4 = 0x64[$r0.1]  ## restore ## t764
;;								## 1
	c0    add $r0.2 = $r0.63, 1   ## bblock 74, line 0,  t765,  t765,  1(I32)
;;								## 2
	c0    add $r0.5 = $r0.5, 1050   ## bblock 74, line 0,  t762,  t762,  1050(I32)
;;								## 3
	c0    add $r0.4 = $r0.4, 4200   ## bblock 74, line 0,  t764,  t764,  4200(I32)
;;								## 4
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t328
	      xnop 1
;;								## 6
	c0    goto L0?3 ## goto
;;								## 7
.trace 39
L1?3:
	c0    stw 0x60[$r0.1] = $r0.3  ## spill ## t328
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 1
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 2, line 52,  raddr(printf)(P32),  addr(_?1STRINGVAR.1)(P32)
;;								## 2
	c0    mov $r0.57 = ((y1 + 0) + 58820)   ## bblock 3, line 0,  t748,  (addr(y1?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 3
	c0    mov $r0.58 = (~0xa)   ## bblock 3, line 0,  t749,  (~0xa)(I32)
;;								## 4
	c0    ldw $r0.59 = 0x60[$r0.1]  ## restore ## t328
	      xnop 1
;;								## 6
;;								## 7
.trace 14
L4?3:
	c0    ldw.d $r0.3 = 0[$r0.57]   ## [spec] bblock 70, line 54, t49, t748
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 4, line 53,  t787(I1),  t749,  0(SI32)
	      xnop 1
;;								## 2
	c0    brf $b0.0, L5?3   ## bblock 4, line 53,  t787(I1)
;;								## 3
.call _d_r, caller, arg($r0.3:u32), ret($r0.3:u32,$r0.4:u32)
	c0    call $l0.0 = _d_r   ## bblock 70, line 54,  raddr(_d_r)(P32),  t49
;;								## 4
	c0    mov $r0.5 = $r0.3   ## t312
;;								## 5
	c0    mov $r0.3 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
;;								## 6
	c0    mov $r0.6 = $r0.4   ## t313
;;								## 7
	c0    mov $r0.4 = $r0.0   ## 0(I32)
;;								## 8
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 70, line 54,  raddr(printf)(P32),  addr(_?1STRINGVAR.2)(P32),  0(I32),  t312,  t313
;;								## 9
	c0    add $r0.57 = $r0.57, 4200   ## bblock 71, line 0,  t748,  t748,  4200(I32)
;;								## 10
	c0    add $r0.58 = $r0.58, 1   ## bblock 71, line 0,  t749,  t749,  1(I32)
	      ## goto
;;
	c0    goto L4?3 ## goto
;;								## 11
.trace 40
L5?3:
	c0    stw 0x60[$r0.1] = $r0.59  ## spill ## t328
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.3 + 0)   ## addr(_?1STRINGVAR.3)(P32)
;;								## 1
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 5, line 55,  raddr(printf)(P32),  addr(_?1STRINGVAR.3)(P32)
;;								## 2
	c0    ldw $r0.3 = 0x80[$r0.1]  ## restore ## t327
;;								## 3
	c0    mov $r0.6 = (y2 + 0)   ## bblock 6, line 0,  t724,  addr(y2?1.0)(P32)
;;								## 4
	c0    add $r0.5 = $r0.59, -1   ## bblock 6, line 60,  t432,  t328,  -1(SI32)
;;								## 5
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 6, line 0,  t727,  0(I32),  t327
;;								## 6
	c0    mov $r0.2 = $r0.3   ## bblock 6, line 0,  t726,  t727
;;								## 7
	c0    mov $r0.4 = (in + 0)   ## bblock 6, line 0,  t725,  addr(in?1.0)(P32)
;;								## 8
.trace 16
L6?3:
	c0    stw 0x6c[$r0.1] = $r0.2  ## spill ## t726
;;								## 0
	c0    stw 0x70[$r0.1] = $r0.4  ## spill ## t725
;;								## 1
	c0    stw 0x74[$r0.1] = $r0.5  ## spill ## t432
;;								## 2
	c0    stw 0x78[$r0.1] = $r0.6  ## spill ## t724
;;								## 3
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 7, line 58,  t788(I1),  t726,  0(SI32)
;;								## 4
	c0    add $r0.62 = $r0.4, $r0.5   ## [spec] bblock 66, line 0,  t458,  t725,  t432
;;								## 5
	c0    brf $b0.0, L7?3   ## bblock 7, line 58,  t788(I1)
;;								## 6
	c0    sh2add $r0.63 = $r0.5, $r0.6   ## bblock 66, line 0,  t457,  t432,  t724
;;								## 7
	c0    mov $r0.61 = $r0.0   ## bblock 66, line 59,  t347,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.60 = $r0.0   ## bblock 66, line 59,  t346,  0.000000e+00=0x0(F32)
;;								## 9
	c0    mov $r0.59 = $r0.0   ## bblock 66, line 59,  t343,  0.000000e+00=0x0(F32)
;;								## 10
	c0    mov $r0.58 = $r0.0   ## bblock 66, line 59,  t342,  0.000000e+00=0x0(F32)
;;								## 11
	c0    mov $r0.57 = $r0.5   ## bblock 66, line 60,  t415,  t432
;;								## 12
.trace 1
L8?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 67, line 60,  t815(I1),  t415,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L9?3   ## bblock 67, line 60,  t815(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t342
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 69, line 61,  raddr(_r_mul)(P32),  t342,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x14[$r0.1] = $r0.3  ## spill ## t65
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 69, line 61,  t342,  t343
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t343
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 69, line 61,  raddr(_r_mul)(P32),  t343,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x18[$r0.1] = $r0.3  ## spill ## t68
;;								## 10
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t346
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 69, line 61,  raddr(_r_mul)(P32),  t346,  -1.886820e-01=0xbe4135db(F32)
;;								## 13
	c0    stw 0x1c[$r0.1] = $r0.3  ## spill ## t71
;;								## 14
	c0    mov $r0.60 = $r0.61   ## bblock 69, line 61,  t346,  t347
;;								## 15
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
;;								## 16
	c0    mov $r0.3 = $r0.61   ## t347
;;								## 17
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 69, line 61,  raddr(_r_mul)(P32),  t347,  -1.836820e-01=0xbe3c1722(F32)
;;								## 18
	c0    stw 0x20[$r0.1] = $r0.3  ## spill ## t74
;;								## 19
	c0    ldw $r0.3 = 0x14[$r0.1]  ## restore ## t65
;;								## 20
	c0    ldw $r0.4 = 0x18[$r0.1]  ## restore ## t68
	      xnop 1
;;								## 22
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 69, line 61,  raddr(_r_add)(P32),  t65,  t68
;;								## 23
	c0    ldw $r0.4 = 0x1c[$r0.1]  ## restore ## t71
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 69, line 61,  raddr(_r_add)(P32),  t300,  t71
;;								## 26
	c0    ldw $r0.4 = 0x20[$r0.1]  ## restore ## t74
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 69, line 61,  raddr(_r_add)(P32),  t301,  t74
;;								## 29
	c0    stw 0x24[$r0.1] = $r0.3  ## spill ## t343
;;								## 30
	c0    ldbu $r0.2 = 0[$r0.62]   ## bblock 69, line 63, t83(I8), t458
;;								## 31
	c0    stw 0[$r0.63] = $r0.3   ## bblock 69, line 61, t457, t343
	      xnop 1
;;								## 33
	c0    mov $r0.3 = $r0.2   ## t83(I8)
;;								## 34
.call _r_ufloat, caller, arg($r0.3:s32), ret($r0.3:u32)
	c0    call $l0.0 = _r_ufloat   ## bblock 69, line 63,  raddr(_r_ufloat)(P32),  t83(I8)
;;								## 35
	c0    add $r0.57 = $r0.57, -1   ## bblock 69, line 60,  t415,  t415,  -1(SI32)
;;								## 36
	c0    add $r0.63 = $r0.63, (~0x3)   ## bblock 69, line 0,  t457,  t457,  (~0x3)(I32)
;;								## 37
	c0    add $r0.62 = $r0.62, (~0x0)   ## bblock 69, line 0,  t458,  t458,  (~0x0)(I32)
;;								## 38
	c0    ldw $r0.59 = 0x24[$r0.1]  ## restore ## t343
;;								## 39
	c0    mov $r0.61 = $r0.3   ## t347
;;								## 40
	c0    goto L8?3 ## goto
;;								## 41
.trace 26
L9?3:
	c0    ldw $r0.6 = 0x78[$r0.1]  ## restore ## t724
;;								## 0
	c0    ldw $r0.4 = 0x70[$r0.1]  ## restore ## t725
;;								## 1
	c0    ldw $r0.2 = 0x6c[$r0.1]  ## restore ## t726
;;								## 2
	c0    add $r0.6 = $r0.6, 4200   ## bblock 68, line 0,  t724,  t724,  4200(I32)
;;								## 3
	c0    add $r0.4 = $r0.4, 1050   ## bblock 68, line 0,  t725,  t725,  1050(I32)
;;								## 4
	c0    add $r0.2 = $r0.2, 1   ## bblock 68, line 0,  t726,  t726,  1(I32)
;;								## 5
	c0    ldw $r0.5 = 0x74[$r0.1]  ## restore ## t432
	      xnop 1
;;								## 7
	c0    goto L6?3 ## goto
;;								## 8
.trace 41
L7?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.4 + 0)   ## addr(_?1STRINGVAR.4)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 8, line 69,  raddr(printf)(P32),  addr(_?1STRINGVAR.4)(P32)
;;								## 1
	c0    mov $r0.57 = ((y2 + 0) + 58820)   ## bblock 9, line 0,  t709,  (addr(y2?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 2
	c0    mov $r0.58 = (~0xa)   ## bblock 9, line 0,  t710,  (~0xa)(I32)
;;								## 3
.trace 18
L10?3:
	c0    ldw.d $r0.3 = 0[$r0.57]   ## [spec] bblock 64, line 71, t101, t709
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 10, line 70,  t789(I1),  t710,  0(SI32)
	      xnop 1
;;								## 2
	c0    brf $b0.0, L11?3   ## bblock 10, line 70,  t789(I1)
;;								## 3
.call _d_r, caller, arg($r0.3:u32), ret($r0.3:u32,$r0.4:u32)
	c0    call $l0.0 = _d_r   ## bblock 64, line 71,  raddr(_d_r)(P32),  t101
;;								## 4
	c0    mov $r0.5 = $r0.3   ## t310
;;								## 5
	c0    mov $r0.3 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
;;								## 6
	c0    mov $r0.6 = $r0.4   ## t311
;;								## 7
	c0    mov $r0.4 = $r0.0   ## 0(I32)
;;								## 8
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 64, line 71,  raddr(printf)(P32),  addr(_?1STRINGVAR.5)(P32),  0(I32),  t310,  t311
;;								## 9
	c0    add $r0.57 = $r0.57, 4200   ## bblock 65, line 0,  t709,  t709,  4200(I32)
;;								## 10
	c0    add $r0.58 = $r0.58, 1   ## bblock 65, line 0,  t710,  t710,  1(I32)
	      ## goto
;;
	c0    goto L10?3 ## goto
;;								## 11
.trace 42
L11?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.6 + 0)   ## addr(_?1STRINGVAR.6)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 11, line 72,  raddr(printf)(P32),  addr(_?1STRINGVAR.6)(P32)
;;								## 1
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t327
;;								## 2
	c0    mov $r0.61 = (t + 0)   ## bblock 12, line 0,  t679,  addr(t?1.0)(P32)
;;								## 3
	c0    mov $r0.59 = (y1 + 0)   ## bblock 12, line 0,  t680,  addr(y1?1.0)(P32)
;;								## 4
	c0    sub $r0.4 = $r0.0, $r0.4   ## bblock 12, line 0,  t683,  0(I32),  t327
;;								## 5
	c0    mov $r0.2 = $r0.4   ## bblock 12, line 0,  t682,  t683
;;								## 6
	c0    mov $r0.58 = (y2 + 0)   ## bblock 12, line 0,  t681,  addr(y2?1.0)(P32)
;;								## 7
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t328
	      xnop 1
;;								## 9
;;								## 10
.trace 17
L12?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 13, line 75,  t790(I1),  t682,  0(SI32)
;;								## 0
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 60, line 0,  t481,  0(I32),  t328
;;								## 1
	c0    brf $b0.0, L13?3   ## bblock 13, line 75,  t790(I1)
;;								## 2
	c0    mov $r0.60 = $r0.4   ## bblock 60, line 0,  t480,  t481
;;								## 3
	c0    mov $r0.57 = $r0.0   ## bblock 60, line 76,  t418,  0(SI32)
;;								## 4
	c0    mov $r0.62 = $r0.2   ## t682
;;								## 5
	c0    mov $r0.63 = $r0.3   ## t328
;;								## 6
.trace 4
L14?3:
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 63, line 77,  t812,  t418,  t681
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 63, line 77, t117, t812
;;								## 1
	c0    sh2add $r0.2 = $r0.57, $r0.59   ## [spec] bblock 63, line 77,  t813,  t418,  t680
;;								## 2
	c0    ldw.d $r0.4 = 0[$r0.2]   ## [spec] bblock 63, line 77, t121, t813
;;								## 3
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 61, line 76,  t811(I1),  t480,  0(SI32)
	      xnop 1
;;								## 5
	c0    brf $b0.0, L15?3   ## bblock 61, line 76,  t811(I1)
;;								## 6
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 63, line 77,  raddr(_r_add)(P32),  t117,  t121
;;								## 7
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 63, line 77,  raddr(_r_mul)(P32),  t122,  1.000000e+00=0x3f800000(F32)
;;								## 9
	c0    sh2add $r0.2 = $r0.57, $r0.61   ## bblock 63, line 77,  t814,  t418,  t679
;;								## 10
	c0    add $r0.57 = $r0.57, 1   ## bblock 63, line 76,  t418,  t418,  1(SI32)
;;								## 11
	c0    add $r0.60 = $r0.60, 1   ## bblock 63, line 0,  t480,  t480,  1(I32)
;;								## 12
	c0    stw 0[$r0.2] = $r0.3   ## bblock 63, line 77, t814, t124
	      ## goto
;;
	c0    goto L14?3 ## goto
;;								## 13
.trace 30
L15?3:
	c0    mov $r0.4 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.61 = $r0.61, $r0.4   ## bblock 62, line 0,  t679,  t679,  4200(I32)
;;								## 1
	c0    add $r0.59 = $r0.59, $r0.4   ## bblock 62, line 0,  t680,  t680,  4200(I32)
;;								## 2
	c0    add $r0.58 = $r0.58, $r0.4   ## bblock 62, line 0,  t681,  t681,  4200(I32)
;;								## 3
	c0    add $r0.2 = $r0.62, 1   ## bblock 62, line 0,  t682,  t682,  1(I32)
;;								## 4
	c0    mov $r0.3 = $r0.63   ## t328
	      ## goto
;;
	c0    goto L12?3 ## goto
;;								## 5
.trace 43
L13?3:
	c0    stw 0x60[$r0.1] = $r0.3  ## spill ## t328
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.7 + 0)   ## addr(_?1STRINGVAR.7)(P32)
;;								## 1
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 14, line 79,  raddr(printf)(P32),  addr(_?1STRINGVAR.7)(P32)
;;								## 2
	c0    mov $r0.57 = ((t + 0) + 58820)   ## bblock 15, line 0,  t664,  (addr(t?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 3
	c0    mov $r0.58 = (~0xa)   ## bblock 15, line 0,  t665,  (~0xa)(I32)
;;								## 4
	c0    ldw $r0.59 = 0x60[$r0.1]  ## restore ## t328
	      xnop 1
;;								## 6
;;								## 7
.trace 19
L16?3:
	c0    ldw.d $r0.3 = 0[$r0.57]   ## [spec] bblock 58, line 81, t139, t664
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 16, line 80,  t791(I1),  t665,  0(SI32)
	      xnop 1
;;								## 2
	c0    brf $b0.0, L17?3   ## bblock 16, line 80,  t791(I1)
;;								## 3
.call _d_r, caller, arg($r0.3:u32), ret($r0.3:u32,$r0.4:u32)
	c0    call $l0.0 = _d_r   ## bblock 58, line 81,  raddr(_d_r)(P32),  t139
;;								## 4
	c0    mov $r0.5 = $r0.3   ## t308
;;								## 5
	c0    mov $r0.3 = (_?1STRINGPACKET.8 + 0)   ## addr(_?1STRINGVAR.8)(P32)
;;								## 6
	c0    mov $r0.6 = $r0.4   ## t309
;;								## 7
	c0    mov $r0.4 = $r0.0   ## 0(I32)
;;								## 8
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 58, line 81,  raddr(printf)(P32),  addr(_?1STRINGVAR.8)(P32),  0(I32),  t308,  t309
;;								## 9
	c0    add $r0.57 = $r0.57, 4200   ## bblock 59, line 0,  t664,  t664,  4200(I32)
;;								## 10
	c0    add $r0.58 = $r0.58, 1   ## bblock 59, line 0,  t665,  t665,  1(I32)
	      ## goto
;;
	c0    goto L16?3 ## goto
;;								## 11
.trace 44
L17?3:
	c0    stw 0x60[$r0.1] = $r0.59  ## spill ## t328
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.9 + 0)   ## addr(_?1STRINGVAR.9)(P32)
;;								## 1
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 17, line 82,  raddr(printf)(P32),  addr(_?1STRINGVAR.9)(P32)
;;								## 2
	c0    sub $r0.59 = $r0.0, $r0.59   ## bblock 18, line 0,  t646,  0(I32),  t328
;;								## 3
	c0    mov $r0.2 = $r0.59   ## bblock 18, line 0,  t645,  t646
;;								## 4
	c0    mov $r0.63 = (y1 + 0)   ## bblock 18, line 0,  t643,  addr(y1?1.0)(P32)
;;								## 5
	c0    mov $r0.62 = (t + 0)   ## bblock 18, line 0,  t644,  addr(t?1.0)(P32)
;;								## 6
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t327
	      xnop 1
;;								## 8
;;								## 9
.trace 21
L18?3:
	c0    stw 0x7c[$r0.1] = $r0.2  ## spill ## t645
;;								## 0
	c0    stw 0x80[$r0.1] = $r0.4  ## spill ## t327
;;								## 1
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 19, line 85,  t792(I1),  t645,  0(SI32)
;;								## 2
	c0    sub $r0.4 = $r0.0, $r0.4   ## [spec] bblock 54, line 0,  t496,  0(I32),  t327
;;								## 3
	c0    brf $b0.0, L19?3   ## bblock 19, line 85,  t792(I1)
;;								## 4
	c0    mov $r0.57 = $r0.4   ## bblock 54, line 0,  t495,  t496
;;								## 5
	c0    mov $r0.61 = $r0.0   ## bblock 54, line 0,  t490,  0(I32)
;;								## 6
	c0    mov $r0.60 = $r0.0   ## bblock 54, line 86,  t350,  0.000000e+00=0x0(F32)
;;								## 7
	c0    mov $r0.59 = $r0.0   ## bblock 54, line 86,  t422,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.58 = $r0.0   ## bblock 54, line 86,  t423,  0.000000e+00=0x0(F32)
;;								## 9
.trace 3
L20?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 55, line 87,  t808(I1),  t495,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L21?3   ## bblock 55, line 87,  t808(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t423
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 57, line 88,  raddr(_r_mul)(P32),  t423,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x3c[$r0.1] = $r0.3  ## spill ## t154
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 57, line 88,  t423,  t422
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t422
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 57, line 88,  raddr(_r_mul)(P32),  t422,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x40[$r0.1] = $r0.3  ## spill ## t157
;;								## 10
	c0    mov $r0.4 = 0x3de1b542   ## 1.102090e-01=0x3de1b542(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t350
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 57, line 88,  raddr(_r_mul)(P32),  t350,  1.102090e-01=0x3de1b542(F32)
;;								## 13
	c0    stw 0x44[$r0.1] = $r0.3  ## spill ## t160
;;								## 14
	c0    sh3add $r0.2 = $r0.61, $r0.62   ## bblock 57, line 88,  t809,  t490,  t644
;;								## 15
	c0    ldw $r0.60 = 0[$r0.2]   ## bblock 57, line 88, t350, t809
;;								## 16
	c0    mov $r0.4 = 0xbe4135db   ## -1.886820e-01=0xbe4135db(F32)
	      xnop 1
;;								## 18
	c0    mov $r0.3 = $r0.60   ## t350
;;								## 19
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 57, line 88,  raddr(_r_mul)(P32),  t350,  -1.886820e-01=0xbe4135db(F32)
;;								## 20
	c0    stw 0x48[$r0.1] = $r0.3  ## spill ## t166
;;								## 21
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t154
;;								## 22
	c0    ldw $r0.4 = 0x40[$r0.1]  ## restore ## t157
	      xnop 1
;;								## 24
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 57, line 88,  raddr(_r_add)(P32),  t154,  t157
;;								## 25
	c0    ldw $r0.4 = 0x44[$r0.1]  ## restore ## t160
	      xnop 1
;;								## 27
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 57, line 88,  raddr(_r_add)(P32),  t298,  t160
;;								## 28
	c0    ldw $r0.4 = 0x48[$r0.1]  ## restore ## t166
	      xnop 1
;;								## 30
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 57, line 88,  raddr(_r_add)(P32),  t299,  t166
;;								## 31
	c0    sh3add $r0.2 = $r0.61, $r0.63   ## bblock 57, line 88,  t810,  t490,  t643
;;								## 32
	c0    add $r0.61 = $r0.61, 525   ## bblock 57, line 0,  t490,  t490,  525(I32)
;;								## 33
	c0    add $r0.57 = $r0.57, 1   ## bblock 57, line 0,  t495,  t495,  1(I32)
;;								## 34
	c0    mov $r0.59 = $r0.3   ## t422
;;								## 35
	c0    stw 0[$r0.2] = $r0.3   ## bblock 57, line 88, t810, t422
	      ## goto
;;
	c0    goto L20?3 ## goto
;;								## 36
.trace 29
L21?3:
	c0    add $r0.63 = $r0.63, 4   ## bblock 56, line 0,  t643,  t643,  4(I32)
;;								## 0
	c0    add $r0.62 = $r0.62, 4   ## bblock 56, line 0,  t644,  t644,  4(I32)
;;								## 1
	c0    ldw $r0.2 = 0x7c[$r0.1]  ## restore ## t645
;;								## 2
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t327
	      xnop 1
;;								## 4
	c0    add $r0.2 = $r0.2, 1   ## bblock 56, line 0,  t645,  t645,  1(I32)
	      ## goto
;;
	c0    goto L18?3 ## goto
;;								## 5
.trace 47
L19?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.10 + 0)   ## addr(_?1STRINGVAR.10)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 20, line 95,  raddr(printf)(P32),  addr(_?1STRINGVAR.10)(P32)
;;								## 1
	c0    mov $r0.57 = ((y1 + 0) + 58820)   ## bblock 21, line 0,  t629,  (addr(y1?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 2
	c0    mov $r0.58 = (~0xa)   ## bblock 21, line 0,  t630,  (~0xa)(I32)
;;								## 3
	c0    ldw $r0.60 = 0x80[$r0.1]  ## restore ## t327
;;								## 4
	c0    ldw $r0.59 = 0x60[$r0.1]  ## restore ## t328
	      xnop 1
;;								## 6
;;								## 7
.trace 20
L22?3:
	c0    ldw.d $r0.3 = 0[$r0.57]   ## [spec] bblock 52, line 97, t191, t629
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 22, line 96,  t793(I1),  t630,  0(SI32)
	      xnop 1
;;								## 2
	c0    brf $b0.0, L23?3   ## bblock 22, line 96,  t793(I1)
;;								## 3
.call _d_r, caller, arg($r0.3:u32), ret($r0.3:u32,$r0.4:u32)
	c0    call $l0.0 = _d_r   ## bblock 52, line 97,  raddr(_d_r)(P32),  t191
;;								## 4
	c0    mov $r0.5 = $r0.3   ## t306
;;								## 5
	c0    mov $r0.3 = (_?1STRINGPACKET.11 + 0)   ## addr(_?1STRINGVAR.11)(P32)
;;								## 6
	c0    mov $r0.6 = $r0.4   ## t307
;;								## 7
	c0    mov $r0.4 = $r0.0   ## 0(I32)
;;								## 8
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 52, line 97,  raddr(printf)(P32),  addr(_?1STRINGVAR.11)(P32),  0(I32),  t306,  t307
;;								## 9
	c0    add $r0.57 = $r0.57, 4200   ## bblock 53, line 0,  t629,  t629,  4200(I32)
;;								## 10
	c0    add $r0.58 = $r0.58, 1   ## bblock 53, line 0,  t630,  t630,  1(I32)
	      ## goto
;;
	c0    goto L22?3 ## goto
;;								## 11
.trace 46
L23?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.12 + 0)   ## addr(_?1STRINGVAR.12)(P32)
;;								## 0
	c0    stw 0x60[$r0.1] = $r0.59  ## spill ## t328
;;								## 1
	c0    stw 0x80[$r0.1] = $r0.60  ## spill ## t327
;;								## 2
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 23, line 98,  raddr(printf)(P32),  addr(_?1STRINGVAR.12)(P32)
;;								## 3
	c0    sub $r0.59 = $r0.0, $r0.59   ## bblock 24, line 0,  t611,  0(I32),  t328
;;								## 4
	c0    mov $r0.2 = $r0.59   ## bblock 24, line 0,  t610,  t611
;;								## 5
	c0    mov $r0.3 = (t + 0)   ## bblock 24, line 0,  t608,  addr(t?1.0)(P32)
;;								## 6
	c0    stw 0x4c[$r0.1] = $r0.3  ## spill ## t608
;;								## 7
	c0    mov $r0.63 = (y2 + 0)   ## bblock 24, line 0,  t609,  addr(y2?1.0)(P32)
;;								## 8
	c0    add $r0.5 = $r0.60, -1   ## bblock 24, line 103,  t433,  t327,  -1(SI32)
;;								## 9
.trace 22
L24?3:
	c0    stw 0x84[$r0.1] = $r0.2  ## spill ## t610
;;								## 0
	c0    stw 0x88[$r0.1] = $r0.5  ## spill ## t433
;;								## 1
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 25, line 101,  t794(I1),  t610,  0(SI32)
;;								## 2
	c0    mpylu $r0.62 = $r0.5, 525   ## [spec] bblock 48, line 0,  t513,  t433,  525(I32)
;;								## 3
	c0    brf $b0.0, L25?3   ## bblock 25, line 101,  t794(I1)
;;								## 4
	c0    mov $r0.61 = $r0.0   ## bblock 48, line 102,  t345,  0.000000e+00=0x0(F32)
;;								## 5
	c0    mov $r0.60 = $r0.0   ## bblock 48, line 102,  t344,  0.000000e+00=0x0(F32)
;;								## 6
	c0    mov $r0.59 = $r0.0   ## bblock 48, line 102,  t427,  0.000000e+00=0x0(F32)
;;								## 7
	c0    mov $r0.58 = $r0.0   ## bblock 48, line 102,  t426,  0.000000e+00=0x0(F32)
;;								## 8
	c0    mov $r0.57 = $r0.5   ## bblock 48, line 103,  t428,  t433
;;								## 9
.trace 5
L26?3:
	c0    cmpge $b0.0 = $r0.57, $r0.0   ## bblock 49, line 103,  t805(I1),  t428,  0(SI32)
;;								## 0
	c0    mov $r0.4 = 0xbf1b459e   ## -6.065310e-01=0xbf1b459e(F32)
;;								## 1
	c0    brf $b0.0, L27?3   ## bblock 49, line 103,  t805(I1)
;;								## 2
	c0    mov $r0.3 = $r0.58   ## t426
;;								## 3
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 51, line 104,  raddr(_r_mul)(P32),  t426,  -6.065310e-01=0xbf1b459e(F32)
;;								## 4
	c0    stw 0x50[$r0.1] = $r0.3  ## spill ## t207
;;								## 5
	c0    mov $r0.58 = $r0.59   ## bblock 51, line 104,  t426,  t427
;;								## 6
	c0    mov $r0.4 = 0x3f5744f6   ## 8.408960e-01=0x3f5744f6(F32)
;;								## 7
	c0    mov $r0.3 = $r0.59   ## t427
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 51, line 104,  raddr(_r_mul)(P32),  t427,  8.408960e-01=0x3f5744f6(F32)
;;								## 9
	c0    stw 0x54[$r0.1] = $r0.3  ## spill ## t210
;;								## 10
	c0    mov $r0.4 = 0x3dea600b   ## 1.144410e-01=0x3dea600b(F32)
;;								## 11
	c0    mov $r0.3 = $r0.60   ## t344
;;								## 12
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 51, line 104,  raddr(_r_mul)(P32),  t344,  1.144410e-01=0x3dea600b(F32)
;;								## 13
	c0    stw 0x58[$r0.1] = $r0.3  ## spill ## t213
;;								## 14
	c0    mov $r0.60 = $r0.61   ## bblock 51, line 104,  t344,  t345
;;								## 15
	c0    mov $r0.4 = 0xbe3c1722   ## -1.836820e-01=0xbe3c1722(F32)
;;								## 16
	c0    mov $r0.3 = $r0.61   ## t345
;;								## 17
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 51, line 104,  raddr(_r_mul)(P32),  t345,  -1.836820e-01=0xbe3c1722(F32)
;;								## 18
	c0    stw 0x5c[$r0.1] = $r0.3  ## spill ## t216
;;								## 19
	c0    ldw $r0.3 = 0x50[$r0.1]  ## restore ## t207
;;								## 20
	c0    ldw $r0.4 = 0x54[$r0.1]  ## restore ## t210
	      xnop 1
;;								## 22
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 51, line 104,  raddr(_r_add)(P32),  t207,  t210
;;								## 23
	c0    ldw $r0.4 = 0x58[$r0.1]  ## restore ## t213
	      xnop 1
;;								## 25
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 51, line 104,  raddr(_r_add)(P32),  t296,  t213
;;								## 26
	c0    ldw $r0.4 = 0x5c[$r0.1]  ## restore ## t216
	      xnop 1
;;								## 28
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 51, line 104,  raddr(_r_add)(P32),  t297,  t216
;;								## 29
	c0    sh3add $r0.4 = $r0.62, $r0.63   ## bblock 51, line 104,  t806,  t513,  t609
;;								## 30
	c0    ldw $r0.2 = 0x4c[$r0.1]  ## restore ## t608
;;								## 31
	c0    add $r0.57 = $r0.57, -1   ## bblock 51, line 103,  t428,  t428,  -1(SI32)
;;								## 32
	c0    mov $r0.59 = $r0.3   ## t427
;;								## 33
	c0    sh3add $r0.5 = $r0.62, $r0.2   ## bblock 51, line 106,  t807,  t513,  t608
;;								## 34
	c0    ldw $r0.61 = 0[$r0.5]   ## bblock 51, line 106, t345, t807
;;								## 35
	c0    add $r0.62 = $r0.62, (~0x20c)   ## bblock 51, line 0,  t513,  t513,  (~0x20c)(I32)
;;								## 36
	c0    stw 0[$r0.4] = $r0.3   ## bblock 51, line 104, t806, t427
	      ## goto
;;
	c0    goto L26?3 ## goto
;;								## 37
.trace 35
L27?3:
	c0    ldw $r0.3 = 0x4c[$r0.1]  ## restore ## t608
;;								## 0
	c0    add $r0.63 = $r0.63, 4   ## bblock 50, line 0,  t609,  t609,  4(I32)
;;								## 1
	c0    ldw $r0.2 = 0x84[$r0.1]  ## restore ## t610
;;								## 2
	c0    add $r0.3 = $r0.3, 4   ## bblock 50, line 0,  t608,  t608,  4(I32)
;;								## 3
	c0    stw 0x4c[$r0.1] = $r0.3  ## spill ## t608
;;								## 4
	c0    add $r0.2 = $r0.2, 1   ## bblock 50, line 0,  t610,  t610,  1(I32)
;;								## 5
	c0    ldw $r0.5 = 0x88[$r0.1]  ## restore ## t433
	      xnop 1
;;								## 7
	c0    goto L24?3 ## goto
;;								## 8
.trace 45
L25?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.13 + 0)   ## addr(_?1STRINGVAR.13)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 26, line 112,  raddr(printf)(P32),  addr(_?1STRINGVAR.13)(P32)
;;								## 1
	c0    mov $r0.57 = ((y2 + 0) + 58820)   ## bblock 27, line 0,  t594,  (addr(y2?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 2
	c0    mov $r0.58 = (~0xa)   ## bblock 27, line 0,  t595,  (~0xa)(I32)
;;								## 3
.trace 23
L28?3:
	c0    ldw.d $r0.3 = 0[$r0.57]   ## [spec] bblock 46, line 114, t242, t594
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 28, line 113,  t795(I1),  t595,  0(SI32)
	      xnop 1
;;								## 2
	c0    brf $b0.0, L29?3   ## bblock 28, line 113,  t795(I1)
;;								## 3
.call _d_r, caller, arg($r0.3:u32), ret($r0.3:u32,$r0.4:u32)
	c0    call $l0.0 = _d_r   ## bblock 46, line 114,  raddr(_d_r)(P32),  t242
;;								## 4
	c0    mov $r0.5 = $r0.3   ## t304
;;								## 5
	c0    mov $r0.3 = (_?1STRINGPACKET.14 + 0)   ## addr(_?1STRINGVAR.14)(P32)
;;								## 6
	c0    mov $r0.6 = $r0.4   ## t305
;;								## 7
	c0    mov $r0.4 = $r0.0   ## 0(I32)
;;								## 8
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 46, line 114,  raddr(printf)(P32),  addr(_?1STRINGVAR.14)(P32),  0(I32),  t304,  t305
;;								## 9
	c0    add $r0.57 = $r0.57, 4200   ## bblock 47, line 0,  t594,  t594,  4200(I32)
;;								## 10
	c0    add $r0.58 = $r0.58, 1   ## bblock 47, line 0,  t595,  t595,  1(I32)
	      ## goto
;;
	c0    goto L28?3 ## goto
;;								## 11
.trace 49
L29?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.15 + 0)   ## addr(_?1STRINGVAR.15)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 29, line 115,  raddr(printf)(P32),  addr(_?1STRINGVAR.15)(P32)
;;								## 1
	c0    ldw $r0.4 = 0x80[$r0.1]  ## restore ## t327
;;								## 2
	c0    mov $r0.61 = (out + 0)   ## bblock 30, line 0,  t563,  addr(out?1.0)(P32)
;;								## 3
	c0    mov $r0.59 = (y1 + 0)   ## bblock 30, line 0,  t565,  addr(y1?1.0)(P32)
;;								## 4
	c0    sub $r0.4 = $r0.0, $r0.4   ## bblock 30, line 0,  t568,  0(I32),  t327
;;								## 5
	c0    mov $r0.2 = $r0.4   ## bblock 30, line 0,  t567,  t568
;;								## 6
	c0    mov $r0.58 = (y2 + 0)   ## bblock 30, line 0,  t566,  addr(y2?1.0)(P32)
;;								## 7
	c0    ldw $r0.3 = 0x60[$r0.1]  ## restore ## t328
	      xnop 1
;;								## 9
;;								## 10
.trace 24
L30?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 31, line 118,  t796(I1),  t567,  0(SI32)
;;								## 0
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 39, line 0,  t538,  0(I32),  t328
;;								## 1
	c0    brf $b0.0, L31?3   ## bblock 31, line 118,  t796(I1)
;;								## 2
	c0    mov $r0.60 = $r0.4   ## bblock 39, line 0,  t537,  t538
;;								## 3
	c0    mov $r0.57 = $r0.0   ## bblock 39, line 119,  t431,  0(SI32)
;;								## 4
	c0    mov $r0.62 = $r0.2   ## t567
;;								## 5
	c0    mov $r0.63 = $r0.3   ## t328
;;								## 6
.trace 6
L32?3:
	c0    sh2add $r0.2 = $r0.57, $r0.58   ## [spec] bblock 42, line 120,  t799,  t431,  t566
;;								## 0
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 42, line 120, t258, t799
;;								## 1
	c0    sh2add $r0.5 = $r0.57, $r0.59   ## [spec] bblock 42, line 120,  t800,  t431,  t565
;;								## 2
	c0    ldw.d $r0.4 = 0[$r0.5]   ## [spec] bblock 42, line 120, t262, t800
;;								## 3
	c0    cmplt $b0.0 = $r0.60, $r0.0   ## bblock 40, line 119,  t798(I1),  t537,  0(SI32)
	      xnop 1
;;								## 5
	c0    brf $b0.0, L33?3   ## bblock 40, line 119,  t798(I1)
;;								## 6
.call _r_add, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_add   ## bblock 42, line 120,  raddr(_r_add)(P32),  t258,  t262
;;								## 7
	c0    mov $r0.4 = 0x3f800000   ## 1.000000e+00=0x3f800000(F32)
;;								## 8
.call _r_mul, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = _r_mul   ## bblock 42, line 120,  raddr(_r_mul)(P32),  t263,  1.000000e+00=0x3f800000(F32)
;;								## 9
.call _r_ufix, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = _r_ufix   ## bblock 42, line 120,  raddr(_r_ufix)(P32),  t265
;;								## 10
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 42, line 120,  t801,  t431,  t563
;;								## 11
	c0    zxtb $r0.4 = $r0.3   ## bblock 42, line 120,  t267(I8),  t266(I8)
;;								## 12
	c0    cmpgt $b0.0 = $r0.4, 25   ## bblock 42, line 121,  t802(I1),  t267(I8),  25(SI32)
;;								## 13
	c0    add $r0.5 = $r0.57, $r0.61   ## [spec] bblock 45, line 122,  t804,  t431,  t563
;;								## 14
	c0    stb 0[$r0.2] = $r0.3   ## bblock 42, line 120, t801, t266(I8)
;;								## 15
	c0    brf $b0.0, L34?3   ## bblock 42, line 121,  t802(I1)
;;								## 16
	c0    add $r0.57 = $r0.57, 1   ## bblock 44, line 119,  t431,  t431,  1(SI32)
;;								## 17
	c0    add $r0.60 = $r0.60, 1   ## bblock 44, line 0,  t537,  t537,  1(I32)
;;								## 18
	c0    stb 0[$r0.5] = $r0.0   ## bblock 45, line 122, t804, 0(I32)
	      ## goto
;;
	c0    goto L32?3 ## goto
;;								## 19
.trace 13
L34?3:
	c0    add $r0.2 = $r0.57, $r0.61   ## bblock 43, line 124,  t803,  t431,  t563
;;								## 0
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 1
	c0    add $r0.60 = $r0.60, 1   ## bblock 44, line 0,  t537,  t537,  1(I32)
;;								## 2
	c0    add $r0.57 = $r0.57, 1   ## bblock 44, line 119,  t431,  t431,  1(SI32)
;;								## 3
	c0    stb 0[$r0.2] = $r0.3   ## bblock 43, line 124, t803, 255(I32)
	      ## goto
;;
	c0    goto L32?3 ## goto
;;								## 4
.trace 34
L33?3:
	c0    add $r0.61 = $r0.61, 1050   ## bblock 41, line 0,  t563,  t563,  1050(I32)
;;								## 0
	c0    add $r0.59 = $r0.59, 4200   ## bblock 41, line 0,  t565,  t565,  4200(I32)
;;								## 1
	c0    add $r0.58 = $r0.58, 4200   ## bblock 41, line 0,  t566,  t566,  4200(I32)
;;								## 2
	c0    add $r0.2 = $r0.62, 1   ## bblock 41, line 0,  t567,  t567,  1(I32)
;;								## 3
	c0    mov $r0.3 = $r0.63   ## t328
	      ## goto
;;
	c0    goto L30?3 ## goto
;;								## 4
.trace 48
L31?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.16 + 0)   ## addr(_?1STRINGVAR.16)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 32, line 129,  raddr(printf)(P32),  addr(_?1STRINGVAR.16)(P32)
;;								## 1
	c0    mov $r0.57 = ((out + 0) + 14705)   ## bblock 33, line 0,  t549,  (addr(out?1.0)(P32) + 0x3971(I32))(P32)
;;								## 2
	c0    mov $r0.58 = (~0xa)   ## bblock 33, line 0,  t550,  (~0xa)(I32)
;;								## 3
.trace 25
L35?3:
	c0    ldbu.d $r0.4 = 0[$r0.57]   ## [spec] bblock 37, line 131, t292(I8), t549
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 34, line 130,  t797(I1),  t550,  0(SI32)
;;								## 1
	c0    mov $r0.3 = (_?1STRINGPACKET.17 + 0)   ## addr(_?1STRINGVAR.17)(P32)
;;								## 2
	c0    brf $b0.0, L36?3   ## bblock 34, line 130,  t797(I1)
;;								## 3
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 37, line 131,  raddr(printf)(P32),  addr(_?1STRINGVAR.17)(P32),  t292(I8)
;;								## 4
	c0    add $r0.57 = $r0.57, 1050   ## bblock 38, line 0,  t549,  t549,  1050(I32)
;;								## 5
	c0    add $r0.58 = $r0.58, 1   ## bblock 38, line 0,  t550,  t550,  1(I32)
	      ## goto
;;
	c0    goto L35?3 ## goto
;;								## 6
.trace 50
L36?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.18 + 0)   ## addr(_?1STRINGVAR.18)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 35, line 132,  raddr(printf)(P32),  addr(_?1STRINGVAR.18)(P32)
;;								## 1
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t314
;;								## 2
	c0    ldw $r0.63 = 0xa4[$r0.1]  ## restore ## t324
;;								## 3
	c0    ldw $r0.62 = 0xa0[$r0.1]  ## restore ## t323
;;								## 4
	c0    ldw $r0.61 = 0x9c[$r0.1]  ## restore ## t322
;;								## 5
	c0    ldw $r0.60 = 0x98[$r0.1]  ## restore ## t321
;;								## 6
	c0    ldw $r0.59 = 0x94[$r0.1]  ## restore ## t320
;;								## 7
	c0    ldw $r0.58 = 0x90[$r0.1]  ## restore ## t319
;;								## 8
	c0    ldw $r0.57 = 0x8c[$r0.1]  ## restore ## t318
	      xnop 1
;;								## 10
.return ret()
	c0    return $r0.1 = $r0.1, (0xc0), $l0.0   ## bblock 36, line 133,  t315,  ?2.1?2auto_size(I32),  t314
;;								## 11
.endp
.section .bss
.section .data
_?1STRINGPACKET.1:
    .data1 10
    .data1 10
    .data1 76
    .data1 49
    .data1 32
    .data1 121
    .data1 49
    .data1 32
    .data1 102
    .data1 108
    .data1 111
    .data1 97
    .data1 116
    .data1 58
    .data1 10
    .data1 0
_?1STRINGPACKET.2:
    .data1 37
    .data1 46
    .data1 48
    .data1 102
    .data1 32
    .data1 0
.skip 2
_?1STRINGPACKET.4:
    .data1 76
    .data1 50
    .data1 32
    .data1 121
    .data1 50
    .data1 32
    .data1 102
    .data1 108
    .data1 111
    .data1 97
    .data1 116
    .data1 58
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.5:
    .data1 37
    .data1 46
    .data1 48
    .data1 102
    .data1 32
    .data1 0
.skip 2
_?1STRINGPACKET.7:
    .data1 76
    .data1 51
    .data1 32
    .data1 116
    .data1 32
    .data1 102
    .data1 108
    .data1 111
    .data1 97
    .data1 116
    .data1 58
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.8:
    .data1 37
    .data1 46
    .data1 48
    .data1 102
    .data1 32
    .data1 0
.skip 2
_?1STRINGPACKET.10:
    .data1 76
    .data1 52
    .data1 32
    .data1 121
    .data1 49
    .data1 32
    .data1 102
    .data1 108
    .data1 111
    .data1 97
    .data1 116
    .data1 58
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.11:
    .data1 37
    .data1 46
    .data1 48
    .data1 102
    .data1 32
    .data1 0
.skip 2
_?1STRINGPACKET.13:
    .data1 76
    .data1 53
    .data1 32
    .data1 121
    .data1 50
    .data1 32
    .data1 102
    .data1 108
    .data1 111
    .data1 97
    .data1 116
    .data1 58
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.14:
    .data1 37
    .data1 46
    .data1 48
    .data1 102
    .data1 32
    .data1 0
.skip 2
_?1STRINGPACKET.16:
    .data1 76
    .data1 54
    .data1 32
    .data1 111
    .data1 117
    .data1 116
    .data1 32
    .data1 102
    .data1 108
    .data1 111
    .data1 97
    .data1 116
    .data1 58
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.3:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.6:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.9:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.12:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.15:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.17:
    .data1 37
    .data1 100
    .data1 32
    .data1 0
_?1STRINGPACKET.18:
    .data1 10
    .data1 10
    .data1 0
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
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg($r0.3:s32,$r0.4:s32)
deriche_fused::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t3
;;								## 1
	c0    mov $r0.3 = (_?1STRINGPACKET.19 + 0)   ## addr(_?1STRINGVAR.19)(P32)
;;								## 2
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 0, line 161,  raddr(printf)(P32),  addr(_?1STRINGVAR.19)(P32)
;;								## 3
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t3
	      xnop 3
;;								## 7
.return ret()
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 162,  t4,  ?2.2?2auto_size(I32),  t3
;;								## 8
.endp
.section .bss
.section .data
.skip 1
_?1STRINGPACKET.19:
    .data1 10
    .data1 102
    .data1 105
    .data1 120
    .data1 101
    .data1 100
    .data1 32
    .data1 102
    .data1 97
    .data1 115
    .data1 116
    .data1 10
    .data1 0
.equ ?2.2?2scratch.0, 0x0
.equ ?2.2?2ras_p, 0x10
.section .data
.section .text
.equ ?2.2?2auto_size, 0x20
 ## End deriche_fused
 ## Begin deriche_slow
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:s32,$r0.4:s32)
deriche_slow::
.trace 59
	c0    add $r0.1 = $r0.1, (-0x40)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t308
;;								## 1
	c0    sub $r0.2 = $r0.0, $r0.3   ## bblock 0, line 0,  t1314,  0(I32),  t321
;;								## 2
	c0    mov $r0.11 = (in + 0)   ## bblock 0, line 0,  t1310,  addr(in?1.0)(P32)
;;								## 3
	c0    mov $r0.19 = $r0.3   ## t321
;;								## 4
	c0    mov $r0.3 = $r0.2   ## bblock 0, line 0,  t1313,  t1314
;;								## 5
	c0    mov $r0.10 = (fy1 + 0)   ## bblock 0, line 0,  t1312,  addr(fy1?1.0)(P32)
;;								## 6
	c0    mov $r0.9 = $r0.4   ## t322
;;								## 7
	c0    mov $r0.20 = $l0.0   ## t308
;;								## 8
.trace 18
L37?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 1, line 184,  t1359(I1),  t1313,  0(SI32)
;;								## 0
	c0    sub $r0.12 = 3, $r0.9   ## [spec] bblock 72, line 0,  t632,  3(I32),  t322
;;								## 1
	c0    brf $b0.0, L38?3   ## bblock 1, line 184,  t1359(I1)
;;								## 2
	c0    mov $r0.7 = $r0.12   ## bblock 72, line 0,  t631,  t632
;;								## 3
	c0    mov $r0.8 = $r0.10   ## bblock 72, line 0,  t630,  t1312
;;								## 4
	c0    mov $r0.5 = $r0.0   ## bblock 72, line 185,  t350,  0(SI32)
;;								## 5
	c0    mov $r0.4 = $r0.0   ## bblock 72, line 185,  t351,  0(SI32)
;;								## 6
	c0    mov $r0.2 = $r0.11   ## bblock 72, line 0,  t629,  t1310
;;								## 7
	c0    mov $r0.6 = $r0.0   ## bblock 72, line 185,  t353,  0(SI32)
;;								## 8
	c0    mov $r0.15 = $r0.3   ## t1313
;;								## 9
	c0    mov $r0.16 = $r0.9   ## t322
;;								## 10
	c0    mov $r0.17 = $r0.10   ## t1312
;;								## 11
	c0    mov $r0.18 = $r0.11   ## t1310
;;								## 12
.trace 2
L39?3:
	c0    ldbu.d $r0.3 = 0[$r0.2]   ## [spec] bblock 75, line 188, t452, t629
;;								## 0
	c0    mpyl $r0.9 = $r0.4, 215   ## [spec] bblock 75, line 190,  t621,  t351,  215(SI32)
;;								## 1
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 75, line 191,  t455,  t350,  -155(SI32)
;;								## 2
	c0    mpyl $r0.10 = $r0.3, -48   ## [spec] bblock 75, line 188,  t456,  t452,  -48(SI32)
;;								## 3
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 75, line 190,  t620(SI24),  t621,  8(SI32)
;;								## 4
	c0    add $r0.10 = $r0.10, $r0.9   ## [spec] bblock 75, line 192,  t1390,  t456,  t620(SI24)
;;								## 5
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 75, line 191,  t454(SI24),  t455,  8(SI32)
;;								## 6
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 75, line 189,  t27,  t353,  28(SI32)
;;								## 7
	c0    cmplt $b0.0 = $r0.7, 3   ## bblock 73, line 186,  t1388(I1),  t631,  3(SI32)
;;								## 8
	c0    add $r0.6 = $r0.6, $r0.5   ## [spec] bblock 75, line 192,  t1389,  t27,  t454(SI24)
;;								## 9
	c0    add $r0.6 = $r0.6, $r0.10   ## [spec] bblock 75, line 192,  t451,  t1389,  t1390
;;								## 10
	c0    brf $b0.0, L40?3   ## bblock 73, line 186,  t1388(I1)
;;								## 11
	c0    cmplt $b0.0 = $r0.7, 2   ## bblock 75, line 186-1,  t1391(I1),  t631,  2(SI32)
;;								## 12
	c0    ldbu.d $r0.9 = 1[$r0.2]   ## [spec] bblock 148, line 188-1, t440, t629
;;								## 13
	c0    mpyl $r0.10 = $r0.6, 215   ## [spec] bblock 148, line 190-1,  t19,  t451,  215(SI32)
;;								## 14
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 148, line 191-1,  t23,  t351,  -155(SI32)
;;								## 15
	c0    mpyl $r0.11 = $r0.9, -48   ## [spec] bblock 148, line 188-1,  t28,  t440,  -48(SI32)
;;								## 16
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 148, line 190-1,  t26(SI24),  t19,  8(SI32)
;;								## 17
	c0    add $r0.11 = $r0.11, $r0.10   ## [spec] bblock 148, line 192-1,  t1429,  t28,  t26(SI24)
;;								## 18
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 148, line 191-1,  t25(SI24),  t23,  8(SI32)
;;								## 19
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 148, line 189-1,  t441,  t452,  28(SI32)
;;								## 20
	c0    cmplt $b0.1 = $r0.7, 1   ## [spec] bblock 148, line 186-2,  t1430(I1),  t631,  1(SI32)
;;								## 21
	c0    add $r0.3 = $r0.3, $r0.4   ## [spec] bblock 148, line 192-1,  t1428,  t441,  t25(SI24)
;;								## 22
	c0    add $r0.3 = $r0.3, $r0.11   ## [spec] bblock 148, line 192-1,  t437,  t1428,  t1429
;;								## 23
	c0    ldbu.d $r0.10 = 2[$r0.2]   ## [spec] bblock 145, line 188-2, t449, t629
;;								## 24
	c0    mpyl $r0.11 = $r0.3, 215   ## [spec] bblock 145, line 190-2,  t447,  t437,  215(SI32)
;;								## 25
	c0    mpyl $r0.12 = $r0.6, -155   ## [spec] bblock 145, line 191-2,  t617,  t451,  -155(SI32)
;;								## 26
	c0    mpyl $r0.13 = $r0.10, -48   ## [spec] bblock 145, line 188-2,  t448,  t449,  -48(SI32)
;;								## 27
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 145, line 190-2,  t618(SI24),  t447,  8(SI32)
;;								## 28
	c0    add $r0.13 = $r0.13, $r0.11   ## [spec] bblock 145, line 192-2,  t1426,  t448,  t618(SI24)
;;								## 29
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 145, line 191-2,  t446(SI24),  t617,  8(SI32)
;;								## 30
	c0    mpyl $r0.9 = $r0.9, 28   ## [spec] bblock 145, line 189-2,  t450,  t440,  28(SI32)
;;								## 31
	c0    cmplt $b0.2 = $r0.7, $r0.0   ## [spec] bblock 145, line 186-3,  t1427(I1),  t631,  0(SI32)
;;								## 32
	c0    add $r0.9 = $r0.9, $r0.12   ## [spec] bblock 145, line 192-2,  t1425,  t450,  t446(SI24)
;;								## 33
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 145, line 192-2,  t444,  t1425,  t1426
;;								## 34
	c0    ldbu.d $r0.11 = 3[$r0.2]   ## [spec] bblock 142, line 188-3, t353, t629
;;								## 35
	c0    mpyl $r0.12 = $r0.9, 215   ## [spec] bblock 142, line 190-3,  t461,  t444,  215(SI32)
;;								## 36
	c0    mpyl $r0.13 = $r0.3, -155   ## [spec] bblock 142, line 191-3,  t459,  t437,  -155(SI32)
;;								## 37
	c0    mpyl $r0.14 = $r0.11, -48   ## [spec] bblock 142, line 188-3,  t616,  t353,  -48(SI32)
;;								## 38
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 142, line 190-3,  t460(SI24),  t461,  8(SI32)
;;								## 39
	c0    add $r0.14 = $r0.14, $r0.12   ## [spec] bblock 142, line 192-3,  t1424,  t616,  t460(SI24)
;;								## 40
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 142, line 191-3,  t458(SI24),  t459,  8(SI32)
;;								## 41
	c0    mpyl $r0.10 = $r0.10, 28   ## [spec] bblock 142, line 189-3,  t457,  t449,  28(SI32)
;;								## 42
	c0    mov $r0.5 = $r0.9   ## [spec] bblock 142, line 192-2,  t350,  t444
;;								## 43
	c0    add $r0.10 = $r0.10, $r0.13   ## [spec] bblock 142, line 192-3,  t1423,  t457,  t458(SI24)
;;								## 44
	c0    add $r0.4 = $r0.10, $r0.14   ## [spec] bblock 142, line 192-3,  t351,  t1423,  t1424
;;								## 45
	c0    add $r0.2 = $r0.2, 4   ## [spec] bblock 142, line 0,  t629,  t629,  4(I32)
;;								## 46
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 142, line 0,  t631,  t631,  4(I32)
;;								## 47
	c0    stw 0[$r0.8] = $r0.6   ## bblock 75, line 192, t630, t451
;;								## 48
	c0    brf $b0.0, L40?3   ## bblock 75, line 186-1,  t1391(I1)
;;								## 49
	c0    mov $r0.6 = $r0.11   ## [spec] t353
;;								## 50
	c0    stw 4[$r0.8] = $r0.3   ## bblock 148, line 192-1, t630, t437
;;								## 51
	c0    brf $b0.1, L40?3   ## bblock 148, line 186-2,  t1430(I1)
;;								## 52
	c0    stw 8[$r0.8] = $r0.9   ## bblock 145, line 192-2, t630, t444
;;								## 53
	c0    brf $b0.2, L40?3   ## bblock 145, line 186-3,  t1427(I1)
;;								## 54
	c0    stw 12[$r0.8] = $r0.4   ## bblock 142, line 192-3, t630, t351
;;								## 55
	c0    add $r0.8 = $r0.8, 16   ## bblock 142, line 0,  t630,  t630,  16(I32)
	      ## goto
;;
	c0    goto L39?3 ## goto
;;								## 56
.trace 36
L40?3:
	c0    add $r0.11 = $r0.18, 1050   ## bblock 74, line 0,  t1310,  t1310,  1050(I32)
;;								## 0
	c0    add $r0.10 = $r0.17, 4200   ## bblock 74, line 0,  t1312,  t1312,  4200(I32)
;;								## 1
	c0    add $r0.3 = $r0.15, 1   ## bblock 74, line 0,  t1313,  t1313,  1(I32)
;;								## 2
	c0    mov $r0.9 = $r0.16   ## t322
	      ## goto
;;
	c0    goto L37?3 ## goto
;;								## 3
.trace 60
L38?3:
	c0    stw 0x10[$r0.1] = $r0.20  ## spill ## t308
;;								## 0
	c0    stw 0x14[$r0.1] = $r0.57  ## spill ## t312
;;								## 1
	c0    stw 0x18[$r0.1] = $r0.58  ## spill ## t313
;;								## 2
	c0    stw 0x1c[$r0.1] = $r0.19  ## spill ## t321
;;								## 3
	c0    stw 0x20[$r0.1] = $r0.9  ## spill ## t322
;;								## 4
	c0    mov $r0.3 = (_?1STRINGPACKET.20 + 0)   ## addr(_?1STRINGVAR.20)(P32)
;;								## 5
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 2, line 199,  raddr(printf)(P32),  addr(_?1STRINGVAR.20)(P32)
;;								## 6
	c0    mov $r0.57 = ((fy1 + 0) + 58820)   ## bblock 3, line 0,  t1293,  (addr(fy1?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 7
	c0    mov $r0.58 = (~0xa)   ## bblock 3, line 0,  t1294,  (~0xa)(I32)
;;								## 8
.trace 19
L41?3:
	c0    ldw.d $r0.2 = 0[$r0.57]   ## [spec] bblock 70, line 201, t53, t1293
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 4, line 200,  t1360(I1),  t1294,  0(SI32)
;;								## 1
	c0    mov $r0.3 = (_?1STRINGPACKET.21 + 0)   ## addr(_?1STRINGVAR.21)(P32)
;;								## 2
	c0    shr $r0.4 = $r0.2, 8   ## [spec] bblock 70, line 201,  t54(SI24),  t53,  8(SI32)
;;								## 3
	c0    brf $b0.0, L42?3   ## bblock 4, line 200,  t1360(I1)
;;								## 4
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 70, line 201,  raddr(printf)(P32),  addr(_?1STRINGVAR.21)(P32),  t54(SI24)
;;								## 5
	c0    add $r0.57 = $r0.57, 4200   ## bblock 71, line 0,  t1293,  t1293,  4200(I32)
;;								## 6
	c0    add $r0.58 = $r0.58, 1   ## bblock 71, line 0,  t1294,  t1294,  1(I32)
	      ## goto
;;
	c0    goto L41?3 ## goto
;;								## 7
.trace 61
L42?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.22 + 0)   ## addr(_?1STRINGVAR.22)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 5, line 202,  raddr(printf)(P32),  addr(_?1STRINGVAR.22)(P32)
;;								## 1
	c0    ldw $r0.2 = 0x1c[$r0.1]  ## restore ## t321
;;								## 2
	c0    mov $r0.12 = ((fy2 + 0) + (~0xb))   ## bblock 6, line 0,  t1254,  (addr(fy2?1.0)(P32) + 0xfffffff4(I32))(P32)
;;								## 3
	c0    ldw $r0.3 = 0x20[$r0.1]  ## restore ## t322
;;								## 4
	c0    sub $r0.2 = $r0.0, $r0.2   ## bblock 6, line 0,  t1257,  0(I32),  t321
;;								## 5
	c0    mov $r0.9 = $r0.2   ## bblock 6, line 0,  t1256,  t1257
;;								## 6
	c0    add $r0.11 = $r0.3, -1   ## bblock 6, line 207,  t434,  t322,  -1(SI32)
;;								## 7
	c0    mov $r0.10 = ((in + 0) + (~0x2))   ## bblock 6, line 0,  t1255,  (addr(in?1.0)(P32) + 0xfffffffd(I32))(P32)
;;								## 8
.trace 17
L43?3:
	c0    cmplt $b0.0 = $r0.9, $r0.0   ## bblock 7, line 205,  t1361(I1),  t1256,  0(SI32)
;;								## 0
	c0    add $r0.8 = $r0.10, $r0.11   ## [spec] bblock 66, line 0,  t679,  t1255,  t434
;;								## 1
	c0    brf $b0.0, L44?3   ## bblock 7, line 205,  t1361(I1)
;;								## 2
	c0    sh2add $r0.7 = $r0.11, $r0.12   ## bblock 66, line 0,  t678,  t434,  t1254
;;								## 3
	c0    mov $r0.2 = $r0.0   ## bblock 66, line 206,  t344,  0(SI32)
;;								## 4
	c0    mov $r0.4 = $r0.0   ## bblock 66, line 206,  t345,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 66, line 206,  t348,  0(SI32)
;;								## 6
	c0    mov $r0.3 = $r0.0   ## bblock 66, line 206,  t463,  0(SI32)
;;								## 7
	c0    mov $r0.6 = $r0.11   ## bblock 66, line 207,  t592,  t434
;;								## 8
	c0    mov $r0.16 = $r0.9   ## t1256
;;								## 9
	c0    mov $r0.17 = $r0.10   ## t1255
;;								## 10
	c0    mov $r0.18 = $r0.11   ## t434
;;								## 11
	c0    mov $r0.19 = $r0.12   ## t1254
;;								## 12
.trace 1
L45?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 69, line 211,  t615,  t344,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 69, line 208,  t490,  t463,  -47(SI32)
;;								## 1
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 69, line 211,  t614(SI24),  t615,  8(SI32)
;;								## 2
	c0    add $r0.9 = $r0.9, $r0.2   ## [spec] bblock 69, line 212,  t1385,  t490,  t614(SI24)
;;								## 3
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 69, line 210,  t486,  t345,  215(SI32)
;;								## 4
	c0    mpyl $r0.5 = $r0.5, -48   ## [spec] bblock 69, line 209,  t83,  t348,  -48(SI32)
;;								## 5
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 69, line 210,  t489(SI24),  t486,  8(SI32)
;;								## 6
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 69, line 212,  t1386,  t83,  t489(SI24)
;;								## 7
	c0    add $r0.9 = $r0.9, $r0.5   ## [spec] bblock 69, line 212,  t487,  t1385,  t1386
;;								## 8
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 67, line 207,  t1384(I1),  t592,  0(SI32)
;;								## 9
	c0    ldbu.d $r0.10 = 3[$r0.8]   ## [spec] bblock 69, line 214, t482, t679
;;								## 10
	c0    brf $b0.0, L46?3   ## bblock 67, line 207,  t1384(I1)
;;								## 11
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 69, line 207-1,  t1387(I1),  t592,  1(SI32)
;;								## 12
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 138, line 211-1,  t79,  t345,  -155(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.10, -47   ## [spec] bblock 138, line 208-1,  t84,  t482,  -47(SI32)
;;								## 14
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 138, line 211-1,  t81(SI24),  t79,  8(SI32)
;;								## 15
	c0    add $r0.11 = $r0.11, $r0.4   ## [spec] bblock 138, line 212-1,  t1420,  t84,  t81(SI24)
;;								## 16
	c0    mpyl $r0.12 = $r0.9, 215   ## [spec] bblock 138, line 210-1,  t468,  t487,  215(SI32)
;;								## 17
	c0    mpyl $r0.3 = $r0.3, -48   ## [spec] bblock 138, line 209-1,  t469,  t463,  -48(SI32)
;;								## 18
	c0    shr $r0.12 = $r0.12, 8   ## [spec] bblock 138, line 210-1,  t82(SI24),  t468,  8(SI32)
;;								## 19
	c0    add $r0.3 = $r0.3, $r0.12   ## [spec] bblock 138, line 212-1,  t1421,  t469,  t82(SI24)
;;								## 20
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 138, line 212-1,  t465,  t1420,  t1421
;;								## 21
	c0    ldbu.d $r0.12 = 2[$r0.8]   ## [spec] bblock 138, line 214-1, t349, t679
;;								## 22
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 138, line 207-2,  t1422(I1),  t592,  2(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.9, -155   ## [spec] bblock 135, line 211-2,  t476,  t487,  -155(SI32)
;;								## 24
	c0    mpyl $r0.14 = $r0.12, -47   ## [spec] bblock 135, line 208-2,  t481,  t349,  -47(SI32)
;;								## 25
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 135, line 211-2,  t475(SI24),  t476,  8(SI32)
;;								## 26
	c0    add $r0.14 = $r0.14, $r0.13   ## [spec] bblock 135, line 212-2,  t1417,  t481,  t475(SI24)
;;								## 27
	c0    mpyl $r0.13 = $r0.11, 215   ## [spec] bblock 135, line 210-2,  t478,  t465,  215(SI32)
;;								## 28
	c0    mpyl $r0.10 = $r0.10, -48   ## [spec] bblock 135, line 209-2,  t480,  t482,  -48(SI32)
;;								## 29
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 135, line 210-2,  t477(SI24),  t478,  8(SI32)
;;								## 30
	c0    add $r0.10 = $r0.10, $r0.13   ## [spec] bblock 135, line 212-2,  t1418,  t480,  t477(SI24)
;;								## 31
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 135, line 212-2,  t473,  t1417,  t1418
;;								## 32
	c0    ldbu.d $r0.10 = 1[$r0.8]   ## [spec] bblock 135, line 214-2, t471, t679
;;								## 33
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 135, line 207-3,  t1419(I1),  t592,  3(SI32)
;;								## 34
	c0    mpyl $r0.13 = $r0.11, -155   ## [spec] bblock 132, line 211-3,  t612,  t465,  -155(SI32)
;;								## 35
	c0    mpyl $r0.15 = $r0.10, -47   ## [spec] bblock 132, line 208-3,  t492,  t471,  -47(SI32)
;;								## 36
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 132, line 211-3,  t483(SI24),  t612,  8(SI32)
;;								## 37
	c0    add $r0.15 = $r0.15, $r0.13   ## [spec] bblock 132, line 212-3,  t1415,  t492,  t483(SI24)
;;								## 38
	c0    mpyl $r0.13 = $r0.14, 215   ## [spec] bblock 132, line 210-3,  t75,  t473,  215(SI32)
;;								## 39
	c0    mpyl $r0.12 = $r0.12, -48   ## [spec] bblock 132, line 209-3,  t491,  t349,  -48(SI32)
;;								## 40
	c0    shr $r0.13 = $r0.13, 8   ## [spec] bblock 132, line 210-3,  t613(SI24),  t75,  8(SI32)
;;								## 41
	c0    add $r0.12 = $r0.12, $r0.13   ## [spec] bblock 132, line 212-3,  t1416,  t491,  t613(SI24)
;;								## 42
	c0    add $r0.4 = $r0.15, $r0.12   ## [spec] bblock 132, line 212-3,  t345,  t1415,  t1416
;;								## 43
	c0    ldbu.d $r0.3 = 0[$r0.8]   ## [spec] bblock 132, line 214-3, t463, t679
;;								## 44
	c0    mov $r0.2 = $r0.14   ## [spec] bblock 132, line 212-2,  t344,  t473
;;								## 45
	c0    mov $r0.5 = $r0.10   ## [spec] bblock 132, line 214-2,  t348,  t471
;;								## 46
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 132, line 207-3,  t592,  t592,  -4(SI32)
;;								## 47
	c0    add $r0.8 = $r0.8, (~0x3)   ## [spec] bblock 132, line 0,  t679,  t679,  (~0x3)(I32)
;;								## 48
	c0    stw 12[$r0.7] = $r0.9   ## bblock 69, line 212, t678, t487
;;								## 49
	c0    brf $b0.0, L47?3   ## bblock 69, line 207-1,  t1387(I1)
;;								## 50
	c0    stw 8[$r0.7] = $r0.11   ## bblock 138, line 212-1, t678, t465
;;								## 51
	c0    brf $b0.1, L48?3   ## bblock 138, line 207-2,  t1422(I1)
;;								## 52
	c0    stw 4[$r0.7] = $r0.14   ## bblock 135, line 212-2, t678, t473
;;								## 53
	c0    brf $b0.2, L49?3   ## bblock 135, line 207-3,  t1419(I1)
;;								## 54
	c0    stw 0[$r0.7] = $r0.4   ## bblock 132, line 212-3, t678, t345
;;								## 55
	c0    add $r0.7 = $r0.7, (~0xf)   ## bblock 132, line 0,  t678,  t678,  (~0xf)(I32)
	      ## goto
;;
	c0    goto L45?3 ## goto
;;								## 56
.trace 54
L49?3:
	c0    add $r0.12 = $r0.19, 4200   ## bblock 68, line 0,  t1254,  t1254,  4200(I32)
	      ## goto
;;
	c0    goto L50?3 ## goto
;;								## 0
.trace 48
L48?3:
	c0    add $r0.12 = $r0.19, 4200   ## bblock 68, line 0,  t1254,  t1254,  4200(I32)
	      ## goto
;;
	c0    goto L50?3 ## goto
;;								## 0
.trace 41
L47?3:
	c0    add $r0.12 = $r0.19, 4200   ## bblock 68, line 0,  t1254,  t1254,  4200(I32)
	      ## goto
;;
	c0    goto L50?3 ## goto
;;								## 0
.trace 35
L46?3:
	c0    add $r0.12 = $r0.19, 4200   ## bblock 68, line 0,  t1254,  t1254,  4200(I32)
;;								## 0
L50?3:
	c0    add $r0.10 = $r0.17, 1050   ## bblock 68, line 0,  t1255,  t1255,  1050(I32)
;;								## 1
	c0    add $r0.9 = $r0.16, 1   ## bblock 68, line 0,  t1256,  t1256,  1(I32)
;;								## 2
	c0    mov $r0.11 = $r0.18   ## t434
	      ## goto
;;
	c0    goto L43?3 ## goto
;;								## 3
.trace 62
L44?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.23 + 0)   ## addr(_?1STRINGVAR.23)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 8, line 220,  raddr(printf)(P32),  addr(_?1STRINGVAR.23)(P32)
;;								## 1
	c0    mov $r0.57 = ((fy2 + 0) + 58820)   ## bblock 9, line 0,  t1236,  (addr(fy2?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 2
	c0    mov $r0.58 = (~0xa)   ## bblock 9, line 0,  t1237,  (~0xa)(I32)
;;								## 3
.trace 20
L51?3:
	c0    ldw.d $r0.2 = 0[$r0.57]   ## [spec] bblock 64, line 222, t110, t1236
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 10, line 221,  t1362(I1),  t1237,  0(SI32)
;;								## 1
	c0    mov $r0.3 = (_?1STRINGPACKET.24 + 0)   ## addr(_?1STRINGVAR.24)(P32)
;;								## 2
	c0    shr $r0.4 = $r0.2, 8   ## [spec] bblock 64, line 222,  t111(SI24),  t110,  8(SI32)
;;								## 3
	c0    brf $b0.0, L52?3   ## bblock 10, line 221,  t1362(I1)
;;								## 4
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 64, line 222,  raddr(printf)(P32),  addr(_?1STRINGVAR.24)(P32),  t111(SI24)
;;								## 5
	c0    add $r0.57 = $r0.57, 4200   ## bblock 65, line 0,  t1236,  t1236,  4200(I32)
;;								## 6
	c0    add $r0.58 = $r0.58, 1   ## bblock 65, line 0,  t1237,  t1237,  1(I32)
	      ## goto
;;
	c0    goto L51?3 ## goto
;;								## 7
.trace 63
L52?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.25 + 0)   ## addr(_?1STRINGVAR.25)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 11, line 223,  raddr(printf)(P32),  addr(_?1STRINGVAR.25)(P32)
;;								## 1
	c0    ldw $r0.2 = 0x1c[$r0.1]  ## restore ## t321
;;								## 2
	c0    mov $r0.10 = (fy2 + 0)   ## bblock 12, line 0,  t1191,  addr(fy2?1.0)(P32)
;;								## 3
	c0    mov $r0.8 = (fy1 + 0)   ## bblock 12, line 0,  t1192,  addr(fy1?1.0)(P32)
;;								## 4
	c0    sub $r0.2 = $r0.0, $r0.2   ## bblock 12, line 0,  t1195,  0(I32),  t321
;;								## 5
	c0    mov $r0.3 = $r0.2   ## bblock 12, line 0,  t1194,  t1195
;;								## 6
	c0    mov $r0.7 = (ft + 0)   ## bblock 12, line 0,  t1193,  addr(ft?1.0)(P32)
;;								## 7
	c0    ldw $r0.9 = 0x20[$r0.1]  ## restore ## t322
	      xnop 1
;;								## 9
;;								## 10
.trace 21
L53?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 13, line 226,  t1363(I1),  t1194,  0(SI32)
;;								## 0
	c0    sub $r0.11 = 3, $r0.9   ## [spec] bblock 60, line 0,  t726,  3(I32),  t322
;;								## 1
	c0    brf $b0.0, L54?3   ## bblock 13, line 226,  t1363(I1)
;;								## 2
	c0    mov $r0.5 = $r0.11   ## bblock 60, line 0,  t725,  t726
;;								## 3
	c0    mov $r0.6 = $r0.7   ## bblock 60, line 0,  t724,  t1193
;;								## 4
	c0    mov $r0.4 = $r0.8   ## bblock 60, line 0,  t723,  t1192
;;								## 5
	c0    mov $r0.2 = $r0.10   ## bblock 60, line 0,  t722,  t1191
;;								## 6
	c0    mov $r0.11 = $r0.3   ## t1194
;;								## 7
	c0    mov $r0.12 = $r0.9   ## t322
;;								## 8
	c0    mov $r0.13 = $r0.7   ## t1193
;;								## 9
	c0    mov $r0.14 = $r0.8   ## t1192
;;								## 10
	c0    mov $r0.15 = $r0.10   ## t1191
;;								## 11
.trace 3
L55?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 63, line 228, t496, t722
;;								## 0
	c0    ldw.d $r0.7 = 0[$r0.4]   ## [spec] bblock 63, line 228, t508, t723
;;								## 1
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 61, line 227,  t1382(I1),  t725,  3(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 63, line 227-1,  t1383(I1),  t725,  2(SI32)
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.7   ## [spec] bblock 63, line 228,  t610,  t496,  t508
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## [spec] bblock 63, line 228,  t609,  t610,  8(I32)
;;								## 5
	c0    shr $r0.3 = $r0.3, 8   ## [spec] bblock 63, line 228,  t507(SI24),  t609,  8(SI32)
;;								## 6
	c0    brf $b0.0, L56?3   ## bblock 61, line 227,  t1382(I1)
;;								## 7
	c0    ldw.d $r0.7 = 4[$r0.2]   ## [spec] bblock 128, line 228-1, t126, t722
;;								## 8
	c0    ldw.d $r0.8 = 4[$r0.4]   ## [spec] bblock 128, line 228-1, t130, t723
;;								## 9
	c0    cmplt $b0.0 = $r0.5, 1   ## [spec] bblock 128, line 227-2,  t1414(I1),  t725,  1(SI32)
;;								## 10
	c0    ldw.d $r0.9 = 8[$r0.2]   ## [spec] bblock 125, line 228-2, t500, t722
;;								## 11
	c0    add $r0.7 = $r0.7, $r0.8   ## [spec] bblock 128, line 228-1,  t131,  t126,  t130
;;								## 12
	c0    shl $r0.7 = $r0.7, 8   ## [spec] bblock 128, line 228-1,  t133,  t131,  8(I32)
;;								## 13
	c0    shr $r0.7 = $r0.7, 8   ## [spec] bblock 128, line 228-1,  t611(SI24),  t133,  8(SI32)
;;								## 14
	c0    ldw.d $r0.8 = 8[$r0.4]   ## [spec] bblock 125, line 228-2, t499, t723
;;								## 15
	c0    cmplt $b0.2 = $r0.5, $r0.0   ## [spec] bblock 125, line 227-3,  t1413(I1),  t725,  0(SI32)
;;								## 16
	c0    ldw.d $r0.10 = 12[$r0.2]   ## [spec] bblock 122, line 228-3, t495, t722
;;								## 17
	c0    add $r0.9 = $r0.9, $r0.8   ## [spec] bblock 125, line 228-2,  t608,  t500,  t499
;;								## 18
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 125, line 228-2,  t607,  t608,  8(I32)
;;								## 19
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 125, line 228-2,  t134(SI24),  t607,  8(SI32)
;;								## 20
	c0    ldw.d $r0.8 = 12[$r0.4]   ## [spec] bblock 122, line 228-3, t494, t723
;;								## 21
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 122, line 0,  t722,  t722,  16(I32)
;;								## 22
	c0    add $r0.4 = $r0.4, 16   ## [spec] bblock 122, line 0,  t723,  t723,  16(I32)
;;								## 23
	c0    add $r0.10 = $r0.10, $r0.8   ## [spec] bblock 122, line 228-3,  t505,  t495,  t494
;;								## 24
	c0    shl $r0.10 = $r0.10, 8   ## [spec] bblock 122, line 228-3,  t504,  t505,  8(I32)
;;								## 25
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 122, line 228-3,  t503(SI24),  t504,  8(SI32)
;;								## 26
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 122, line 0,  t725,  t725,  4(I32)
;;								## 27
	c0    stw 0[$r0.6] = $r0.3   ## bblock 63, line 228, t724, t507(SI24)
;;								## 28
	c0    brf $b0.1, L56?3   ## bblock 63, line 227-1,  t1383(I1)
;;								## 29
	c0    stw 4[$r0.6] = $r0.7   ## bblock 128, line 228-1, t724, t611(SI24)
;;								## 30
	c0    brf $b0.0, L56?3   ## bblock 128, line 227-2,  t1414(I1)
;;								## 31
	c0    stw 8[$r0.6] = $r0.9   ## bblock 125, line 228-2, t724, t134(SI24)
;;								## 32
	c0    brf $b0.2, L56?3   ## bblock 125, line 227-3,  t1413(I1)
;;								## 33
	c0    stw 12[$r0.6] = $r0.10   ## bblock 122, line 228-3, t724, t503(SI24)
;;								## 34
	c0    add $r0.6 = $r0.6, 16   ## bblock 122, line 0,  t724,  t724,  16(I32)
	      ## goto
;;
	c0    goto L55?3 ## goto
;;								## 35
.trace 38
L56?3:
	c0    mov $r0.2 = 4200   ## 4200(I32)
;;								## 0
	c0    add $r0.10 = $r0.15, $r0.2   ## bblock 62, line 0,  t1191,  t1191,  4200(I32)
;;								## 1
	c0    add $r0.8 = $r0.14, $r0.2   ## bblock 62, line 0,  t1192,  t1192,  4200(I32)
;;								## 2
	c0    add $r0.7 = $r0.13, $r0.2   ## bblock 62, line 0,  t1193,  t1193,  4200(I32)
;;								## 3
	c0    add $r0.3 = $r0.11, 1   ## bblock 62, line 0,  t1194,  t1194,  1(I32)
;;								## 4
	c0    mov $r0.9 = $r0.12   ## t322
	      ## goto
;;
	c0    goto L53?3 ## goto
;;								## 5
.trace 64
L54?3:
	c0    stw 0x20[$r0.1] = $r0.9  ## spill ## t322
;;								## 0
	c0    mov $r0.3 = (_?1STRINGPACKET.26 + 0)   ## addr(_?1STRINGVAR.26)(P32)
;;								## 1
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 14, line 230,  raddr(printf)(P32),  addr(_?1STRINGVAR.26)(P32)
;;								## 2
	c0    mov $r0.57 = ((ft + 0) + 58820)   ## bblock 15, line 0,  t1173,  (addr(ft?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 3
	c0    mov $r0.58 = (~0xa)   ## bblock 15, line 0,  t1174,  (~0xa)(I32)
;;								## 4
.trace 22
L57?3:
	c0    ldw.d $r0.2 = 0[$r0.57]   ## [spec] bblock 58, line 232, t149, t1173
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 16, line 231,  t1364(I1),  t1174,  0(SI32)
;;								## 1
	c0    mov $r0.3 = (_?1STRINGPACKET.27 + 0)   ## addr(_?1STRINGVAR.27)(P32)
;;								## 2
	c0    shr $r0.4 = $r0.2, 8   ## [spec] bblock 58, line 232,  t150(SI24),  t149,  8(SI32)
;;								## 3
	c0    brf $b0.0, L58?3   ## bblock 16, line 231,  t1364(I1)
;;								## 4
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 58, line 232,  raddr(printf)(P32),  addr(_?1STRINGVAR.27)(P32),  t150(SI24)
;;								## 5
	c0    add $r0.57 = $r0.57, 4200   ## bblock 59, line 0,  t1173,  t1173,  4200(I32)
;;								## 6
	c0    add $r0.58 = $r0.58, 1   ## bblock 59, line 0,  t1174,  t1174,  1(I32)
	      ## goto
;;
	c0    goto L57?3 ## goto
;;								## 7
.trace 67
L58?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.28 + 0)   ## addr(_?1STRINGVAR.28)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 17, line 233,  raddr(printf)(P32),  addr(_?1STRINGVAR.28)(P32)
;;								## 1
	c0    ldw $r0.9 = 0x20[$r0.1]  ## restore ## t322
;;								## 2
	c0    mov $r0.12 = (ft + 0)   ## bblock 18, line 0,  t1143,  addr(ft?1.0)(P32)
;;								## 3
	c0    mov $r0.11 = (fy1 + 0)   ## bblock 18, line 0,  t1144,  addr(fy1?1.0)(P32)
;;								## 4
	c0    sub $r0.9 = $r0.0, $r0.9   ## bblock 18, line 0,  t1146,  0(I32),  t322
;;								## 5
	c0    mov $r0.3 = $r0.9   ## bblock 18, line 0,  t1145,  t1146
;;								## 6
	c0    ldw $r0.10 = 0x1c[$r0.1]  ## restore ## t321
	      xnop 1
;;								## 8
;;								## 9
.trace 24
L59?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 19, line 236,  t1365(I1),  t1145,  0(SI32)
;;								## 0
	c0    sub $r0.13 = 3, $r0.10   ## [spec] bblock 54, line 0,  t789,  3(I32),  t321
;;								## 1
	c0    brf $b0.0, L60?3   ## bblock 19, line 236,  t1365(I1)
;;								## 2
	c0    mov $r0.7 = $r0.13   ## bblock 54, line 0,  t788,  t789
;;								## 3
	c0    mov $r0.8 = $r0.11   ## bblock 54, line 0,  t787,  t1144
;;								## 4
	c0    mov $r0.2 = $r0.12   ## bblock 54, line 0,  t786,  t1143
;;								## 5
	c0    mov $r0.6 = $r0.0   ## bblock 54, line 237,  t510,  0(SI32)
;;								## 6
	c0    mov $r0.5 = $r0.0   ## bblock 54, line 237,  t424(SI24),  0(SI32)
;;								## 7
	c0    mov $r0.4 = $r0.0   ## bblock 54, line 237,  t423,  0(SI32)
;;								## 8
	c0    mov $r0.13 = $r0.3   ## t1145
;;								## 9
	c0    mov $r0.14 = $r0.10   ## t321
;;								## 10
	c0    mov $r0.15 = $r0.11   ## t1144
;;								## 11
	c0    mov $r0.16 = $r0.12   ## t1143
;;								## 12
.trace 4
L61?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 57, line 239, t604, t786
;;								## 0
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 57, line 239,  t534,  t423,  -155(SI32)
;;								## 1
	c0    mpyl $r0.9 = $r0.5, 215   ## [spec] bblock 57, line 239,  t512,  t424(SI24),  215(SI32)
;;								## 2
	c0    mpyl $r0.10 = $r0.3, -48   ## [spec] bblock 57, line 239,  t532,  t604,  -48(SI32)
;;								## 3
	c0    mpyl $r0.6 = $r0.6, 28   ## [spec] bblock 57, line 239,  t529,  t510,  28(SI32)
;;								## 4
	c0    add $r0.4 = $r0.4, $r0.10   ## [spec] bblock 57, line 239,  t1379,  t534,  t532
;;								## 5
	c0    add $r0.9 = $r0.9, $r0.6   ## [spec] bblock 57, line 239,  t1380,  t512,  t529
;;								## 6
	c0    add $r0.4 = $r0.4, $r0.9   ## [spec] bblock 57, line 239,  t531,  t1379,  t1380
;;								## 7
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 57, line 239,  t1352,  t531,  8(SI32)
;;								## 8
	c0    cmplt $b0.0 = $r0.7, 3   ## bblock 55, line 238,  t1378(I1),  t788,  3(SI32)
;;								## 9
	c0    cmplt $b0.1 = $r0.7, 2   ## [spec] bblock 57, line 238-1,  t1381(I1),  t788,  2(SI32)
;;								## 10
	c0    brf $b0.0, L62?3   ## bblock 55, line 238,  t1378(I1)
;;								## 11
	c0    ldw.d $r0.9 = 4200[$r0.2]   ## [spec] bblock 118, line 239-1, t352, t786
;;								## 12
	c0    mpyl $r0.5 = $r0.5, -155   ## [spec] bblock 118, line 239-1,  t164,  t424(SI24),  -155(SI32)
;;								## 13
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 118, line 239-1,  t167,  t1352,  215(SI32)
;;								## 14
	c0    mpyl $r0.11 = $r0.9, -48   ## [spec] bblock 118, line 239-1,  t176,  t352,  -48(SI32)
;;								## 15
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 118, line 239-1,  t170,  t604,  28(SI32)
;;								## 16
	c0    add $r0.5 = $r0.5, $r0.11   ## [spec] bblock 118, line 239-1,  t1410,  t164,  t176
;;								## 17
	c0    add $r0.10 = $r0.10, $r0.3   ## [spec] bblock 118, line 239-1,  t1411,  t167,  t170
;;								## 18
	c0    add $r0.5 = $r0.5, $r0.10   ## [spec] bblock 118, line 239-1,  t177,  t1410,  t1411
;;								## 19
	c0    shr $r0.5 = $r0.5, 8   ## [spec] bblock 118, line 239-1,  t1353,  t177,  8(SI32)
;;								## 20
	c0    cmplt $b0.0 = $r0.7, 1   ## [spec] bblock 118, line 238-2,  t1412(I1),  t788,  1(SI32)
;;								## 21
	c0    ldw.d $r0.3 = 8400[$r0.2]   ## [spec] bblock 115, line 239-2, t518, t786
;;								## 22
	c0    mpyl $r0.10 = $r0.4, -155   ## [spec] bblock 115, line 239-2,  t522,  t1352,  -155(SI32)
;;								## 23
	c0    mpyl $r0.11 = $r0.5, 215   ## [spec] bblock 115, line 239-2,  t600,  t1353,  215(SI32)
;;								## 24
	c0    mpyl $r0.12 = $r0.3, -48   ## [spec] bblock 115, line 239-2,  t517,  t518,  -48(SI32)
;;								## 25
	c0    mpyl $r0.9 = $r0.9, 28   ## [spec] bblock 115, line 239-2,  t599,  t352,  28(SI32)
;;								## 26
	c0    add $r0.10 = $r0.10, $r0.12   ## [spec] bblock 115, line 239-2,  t1407,  t522,  t517
;;								## 27
	c0    add $r0.11 = $r0.11, $r0.9   ## [spec] bblock 115, line 239-2,  t1408,  t600,  t599
;;								## 28
	c0    add $r0.10 = $r0.10, $r0.11   ## [spec] bblock 115, line 239-2,  t516,  t1407,  t1408
;;								## 29
	c0    shr $r0.10 = $r0.10, 8   ## [spec] bblock 115, line 239-2,  t1354,  t516,  8(SI32)
;;								## 30
	c0    cmplt $b0.2 = $r0.7, $r0.0   ## [spec] bblock 115, line 238-3,  t1409(I1),  t788,  0(SI32)
;;								## 31
	c0    ldw.d $r0.6 = 12600[$r0.2]   ## [spec] bblock 112, line 239-3, t510, t786
;;								## 32
	c0    mpyl $r0.9 = $r0.5, -155   ## [spec] bblock 112, line 239-3,  t527,  t1353,  -155(SI32)
;;								## 33
	c0    mpyl $r0.11 = $r0.10, 215   ## [spec] bblock 112, line 239-3,  t603,  t1354,  215(SI32)
;;								## 34
	c0    mpyl $r0.12 = $r0.6, -48   ## [spec] bblock 112, line 239-3,  t602,  t510,  -48(SI32)
;;								## 35
	c0    mpyl $r0.3 = $r0.3, 28   ## [spec] bblock 112, line 239-3,  t526,  t518,  28(SI32)
;;								## 36
	c0    add $r0.9 = $r0.9, $r0.12   ## [spec] bblock 112, line 239-3,  t1405,  t527,  t602
;;								## 37
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 112, line 239-3,  t1406,  t603,  t526
;;								## 38
	c0    add $r0.9 = $r0.9, $r0.11   ## [spec] bblock 112, line 239-3,  t601,  t1405,  t1406
;;								## 39
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 112, line 239-3,  t424(SI24),  t601,  8(SI32)
;;								## 40
	c0    stw 0[$r0.8] = $r0.4   ## bblock 57, line 239, t787, t1352
;;								## 41
	c0    brf $b0.1, L62?3   ## bblock 57, line 238-1,  t1381(I1)
;;								## 42
	c0    mov $r0.4 = $r0.10   ## [spec] bblock 112, line 239-2,  t423,  t1354
;;								## 43
	c0    add $r0.2 = $r0.2, 16800   ## [spec] bblock 112, line 0,  t786,  t786,  16800(I32)
;;								## 44
	c0    add $r0.7 = $r0.7, 4   ## [spec] bblock 112, line 0,  t788,  t788,  4(I32)
;;								## 45
	c0    stw 4200[$r0.8] = $r0.5   ## bblock 118, line 239-1, t787, t1353
;;								## 46
	c0    brf $b0.0, L62?3   ## bblock 118, line 238-2,  t1412(I1)
;;								## 47
	c0    mov $r0.5 = $r0.9   ## [spec] t424(SI24)
;;								## 48
	c0    stw 8400[$r0.8] = $r0.10   ## bblock 115, line 239-2, t787, t1354
;;								## 49
	c0    brf $b0.2, L62?3   ## bblock 115, line 238-3,  t1409(I1)
;;								## 50
	c0    stw 12600[$r0.8] = $r0.9   ## bblock 112, line 239-3, t787, t424(SI24)
;;								## 51
	c0    add $r0.8 = $r0.8, 16800   ## bblock 112, line 0,  t787,  t787,  16800(I32)
	      ## goto
;;
	c0    goto L61?3 ## goto
;;								## 52
.trace 37
L62?3:
	c0    add $r0.12 = $r0.16, 4   ## bblock 56, line 0,  t1143,  t1143,  4(I32)
;;								## 0
	c0    add $r0.11 = $r0.15, 4   ## bblock 56, line 0,  t1144,  t1144,  4(I32)
;;								## 1
	c0    add $r0.3 = $r0.13, 1   ## bblock 56, line 0,  t1145,  t1145,  1(I32)
;;								## 2
	c0    mov $r0.10 = $r0.14   ## t321
	      ## goto
;;
	c0    goto L59?3 ## goto
;;								## 3
.trace 68
L60?3:
	c0    stw 0x24[$r0.1] = $r0.59  ## spill ## t314
;;								## 0
	c0    stw 0x28[$r0.1] = $r0.60  ## spill ## t315
;;								## 1
	c0    stw 0x1c[$r0.1] = $r0.10  ## spill ## t321
;;								## 2
	c0    mov $r0.3 = (_?1STRINGPACKET.29 + 0)   ## addr(_?1STRINGVAR.29)(P32)
;;								## 3
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 20, line 246,  raddr(printf)(P32),  addr(_?1STRINGVAR.29)(P32)
;;								## 4
	c0    mov $r0.57 = ((fy1 + 0) + 58820)   ## bblock 21, line 0,  t1126,  (addr(fy1?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 5
	c0    mov $r0.58 = (~0xa)   ## bblock 21, line 0,  t1127,  (~0xa)(I32)
;;								## 6
	c0    ldw $r0.60 = 0x1c[$r0.1]  ## restore ## t321
;;								## 7
	c0    ldw $r0.59 = 0x20[$r0.1]  ## restore ## t322
	      xnop 1
;;								## 9
;;								## 10
.trace 23
L63?3:
	c0    ldw.d $r0.2 = 0[$r0.57]   ## [spec] bblock 52, line 248, t202, t1126
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 22, line 247,  t1366(I1),  t1127,  0(SI32)
;;								## 1
	c0    mov $r0.3 = (_?1STRINGPACKET.30 + 0)   ## addr(_?1STRINGVAR.30)(P32)
;;								## 2
	c0    shr $r0.4 = $r0.2, 8   ## [spec] bblock 52, line 248,  t203(SI24),  t202,  8(SI32)
;;								## 3
	c0    brf $b0.0, L64?3   ## bblock 22, line 247,  t1366(I1)
;;								## 4
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 52, line 248,  raddr(printf)(P32),  addr(_?1STRINGVAR.30)(P32),  t203(SI24)
;;								## 5
	c0    add $r0.57 = $r0.57, 4200   ## bblock 53, line 0,  t1126,  t1126,  4200(I32)
;;								## 6
	c0    add $r0.58 = $r0.58, 1   ## bblock 53, line 0,  t1127,  t1127,  1(I32)
	      ## goto
;;
	c0    goto L63?3 ## goto
;;								## 7
.trace 66
L64?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.31 + 0)   ## addr(_?1STRINGVAR.31)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 23, line 249,  raddr(printf)(P32),  addr(_?1STRINGVAR.31)(P32)
;;								## 1
	c0    sub $r0.2 = $r0.0, $r0.59   ## bblock 24, line 0,  t1099,  0(I32),  t322
;;								## 2
	c0    mov $r0.11 = $r0.2   ## bblock 24, line 0,  t1098,  t1099
;;								## 3
	c0    mov $r0.14 = ((fy2 + 0) + (~0x3137))   ## bblock 24, line 0,  t1096,  (addr(fy2?1.0)(P32) + 0xffffcec8(I32))(P32)
;;								## 4
	c0    mov $r0.13 = ((ft + 0) + (~0x3137))   ## bblock 24, line 0,  t1097,  (addr(ft?1.0)(P32) + 0xffffcec8(I32))(P32)
;;								## 5
	c0    add $r0.12 = $r0.60, -1   ## bblock 24, line 254,  t435,  t321,  -1(SI32)
;;								## 6
.trace 25
L65?3:
	c0    cmplt $b0.0 = $r0.11, $r0.0   ## bblock 25, line 252,  t1367(I1),  t1098,  0(SI32)
;;								## 0
	c0    mpylu $r0.15 = $r0.12, 4200   ## [spec] bblock 48, line 0,  t879,  t435,  4200(I32)
;;								## 1
	c0    brf $b0.0, L66?3   ## bblock 25, line 252,  t1367(I1)
;;								## 2
	c0    add $r0.8 = $r0.13, $r0.15   ## bblock 48, line 0,  t869,  t1097,  t879
;;								## 3
	c0    add $r0.7 = $r0.14, $r0.15   ## bblock 48, line 0,  t868,  t1096,  t879
;;								## 4
	c0    mov $r0.3 = $r0.0   ## bblock 48, line 253,  t539,  0(SI32)
;;								## 5
	c0    mov $r0.5 = $r0.0   ## bblock 48, line 253,  t535,  0(SI32)
;;								## 6
	c0    mov $r0.4 = $r0.0   ## bblock 48, line 253,  t538(SI24),  0(SI32)
;;								## 7
	c0    mov $r0.2 = $r0.0   ## bblock 48, line 253,  t537,  0(SI32)
;;								## 8
	c0    mov $r0.6 = $r0.12   ## bblock 48, line 254,  t552,  t435
;;								## 9
	c0    mov $r0.15 = $r0.11   ## t1098
;;								## 10
	c0    mov $r0.16 = $r0.12   ## t435
;;								## 11
	c0    mov $r0.17 = $r0.13   ## t1097
;;								## 12
	c0    mov $r0.18 = $r0.14   ## t1096
;;								## 13
.trace 6
L67?3:
	c0    mpyl $r0.2 = $r0.2, -155   ## [spec] bblock 51, line 255,  t565,  t537,  -155(SI32)
;;								## 0
	c0    mpyl $r0.9 = $r0.3, -47   ## [spec] bblock 51, line 255,  t597,  t539,  -47(SI32)
;;								## 1
	c0    mpyl $r0.10 = $r0.4, 215   ## [spec] bblock 51, line 255,  t541,  t538(SI24),  215(SI32)
;;								## 2
	c0    add $r0.2 = $r0.2, $r0.9   ## [spec] bblock 51, line 255,  t1375,  t565,  t597
;;								## 3
	c0    mpyl $r0.5 = $r0.5, 29   ## [spec] bblock 51, line 255,  t560,  t535,  29(SI32)
;;								## 4
	c0    cmpge $b0.0 = $r0.6, $r0.0   ## bblock 49, line 254,  t1374(I1),  t552,  0(SI32)
;;								## 5
	c0    add $r0.10 = $r0.10, $r0.5   ## [spec] bblock 51, line 255,  t1376,  t541,  t560
;;								## 6
	c0    add $r0.2 = $r0.2, $r0.10   ## [spec] bblock 51, line 255,  t596,  t1375,  t1376
;;								## 7
	c0    shr $r0.2 = $r0.2, 8   ## [spec] bblock 51, line 255,  t1355,  t596,  8(SI32)
;;								## 8
	c0    brf $b0.0, L68?3   ## bblock 49, line 254,  t1374(I1)
;;								## 9
	c0    ldw $r0.9 = 12600[$r0.8]   ## bblock 51, line 257, t559, t869
;;								## 10
	c0    cmpge $b0.0 = $r0.6, 1   ## bblock 51, line 254-1,  t1377(I1),  t552,  1(SI32)
;;								## 11
	c0    mpyl $r0.4 = $r0.4, -155   ## [spec] bblock 108, line 255-1,  t218,  t538(SI24),  -155(SI32)
;;								## 12
	c0    mpyl $r0.10 = $r0.9, -47   ## [spec] bblock 108, line 255-1,  t598,  t559,  -47(SI32)
;;								## 13
	c0    mpyl $r0.11 = $r0.2, 215   ## [spec] bblock 108, line 255-1,  t221,  t1355,  215(SI32)
;;								## 14
	c0    add $r0.4 = $r0.4, $r0.10   ## [spec] bblock 108, line 255-1,  t1402,  t218,  t598
;;								## 15
	c0    mpyl $r0.3 = $r0.3, 29   ## [spec] bblock 108, line 255-1,  t224,  t539,  29(SI32)
;;								## 16
	c0    ldw.d $r0.10 = 8400[$r0.8]   ## [spec] bblock 108, line 257-1, t347, t869
;;								## 17
	c0    add $r0.11 = $r0.11, $r0.3   ## [spec] bblock 108, line 255-1,  t1403,  t221,  t224
;;								## 18
	c0    add $r0.4 = $r0.4, $r0.11   ## [spec] bblock 108, line 255-1,  t228,  t1402,  t1403
;;								## 19
	c0    shr $r0.4 = $r0.4, 8   ## [spec] bblock 108, line 255-1,  t1356,  t228,  8(SI32)
;;								## 20
	c0    cmpge $b0.1 = $r0.6, 2   ## [spec] bblock 108, line 254-2,  t1404(I1),  t552,  2(SI32)
;;								## 21
	c0    mpyl $r0.11 = $r0.2, -155   ## [spec] bblock 105, line 255-2,  t551,  t1355,  -155(SI32)
;;								## 22
	c0    mpyl $r0.12 = $r0.10, -47   ## [spec] bblock 105, line 255-2,  t227,  t347,  -47(SI32)
;;								## 23
	c0    mpyl $r0.13 = $r0.4, 215   ## [spec] bblock 105, line 255-2,  t549,  t1356,  215(SI32)
;;								## 24
	c0    add $r0.11 = $r0.11, $r0.12   ## [spec] bblock 105, line 255-2,  t1399,  t551,  t227
;;								## 25
	c0    mpyl $r0.9 = $r0.9, 29   ## [spec] bblock 105, line 255-2,  t548,  t559,  29(SI32)
;;								## 26
	c0    ldw.d $r0.12 = 4200[$r0.8]   ## [spec] bblock 105, line 257-2, t540, t869
;;								## 27
	c0    add $r0.13 = $r0.13, $r0.9   ## [spec] bblock 105, line 255-2,  t1400,  t549,  t548
;;								## 28
	c0    add $r0.11 = $r0.11, $r0.13   ## [spec] bblock 105, line 255-2,  t546,  t1399,  t1400
;;								## 29
	c0    shr $r0.11 = $r0.11, 8   ## [spec] bblock 105, line 255-2,  t1357,  t546,  8(SI32)
;;								## 30
	c0    cmpge $b0.2 = $r0.6, 3   ## [spec] bblock 105, line 254-3,  t1401(I1),  t552,  3(SI32)
;;								## 31
	c0    mpyl $r0.9 = $r0.4, -155   ## [spec] bblock 102, line 255-3,  t595,  t1356,  -155(SI32)
;;								## 32
	c0    mpyl $r0.13 = $r0.12, -47   ## [spec] bblock 102, line 255-3,  t555,  t540,  -47(SI32)
;;								## 33
	c0    mpyl $r0.14 = $r0.11, 215   ## [spec] bblock 102, line 255-3,  t558,  t1357,  215(SI32)
;;								## 34
	c0    add $r0.9 = $r0.9, $r0.13   ## [spec] bblock 102, line 255-3,  t1397,  t595,  t555
;;								## 35
	c0    mpyl $r0.10 = $r0.10, 29   ## [spec] bblock 102, line 255-3,  t557,  t347,  29(SI32)
;;								## 36
	c0    ldw.d $r0.3 = 0[$r0.8]   ## [spec] bblock 102, line 257-3, t539, t869
;;								## 37
	c0    add $r0.14 = $r0.14, $r0.10   ## [spec] bblock 102, line 255-3,  t1398,  t558,  t557
;;								## 38
	c0    add $r0.9 = $r0.9, $r0.14   ## [spec] bblock 102, line 255-3,  t554,  t1397,  t1398
;;								## 39
	c0    shr $r0.9 = $r0.9, 8   ## [spec] bblock 102, line 255-3,  t538(SI24),  t554,  8(SI32)
;;								## 40
	c0    mov $r0.5 = $r0.12   ## [spec] bblock 102, line 257-2,  t535,  t540
;;								## 41
	c0    stw 12600[$r0.7] = $r0.2   ## bblock 51, line 255, t868, t1355
;;								## 42
	c0    brf $b0.0, L68?3   ## bblock 51, line 254-1,  t1377(I1)
;;								## 43
	c0    mov $r0.2 = $r0.11   ## [spec] bblock 102, line 255-2,  t537,  t1357
;;								## 44
	c0    add $r0.6 = $r0.6, -4   ## [spec] bblock 102, line 254-3,  t552,  t552,  -4(SI32)
;;								## 45
	c0    add $r0.8 = $r0.8, (~0x419f)   ## [spec] bblock 102, line 0,  t869,  t869,  (~0x419f)(I32)
;;								## 46
	c0    stw 8400[$r0.7] = $r0.4   ## bblock 108, line 255-1, t868, t1356
;;								## 47
	c0    brf $b0.1, L68?3   ## bblock 108, line 254-2,  t1404(I1)
;;								## 48
	c0    mov $r0.4 = $r0.9   ## [spec] t538(SI24)
;;								## 49
	c0    stw 4200[$r0.7] = $r0.11   ## bblock 105, line 255-2, t868, t1357
;;								## 50
	c0    brf $b0.2, L68?3   ## bblock 105, line 254-3,  t1401(I1)
;;								## 51
	c0    stw 0[$r0.7] = $r0.9   ## bblock 102, line 255-3, t868, t538(SI24)
;;								## 52
	c0    add $r0.7 = $r0.7, (~0x419f)   ## bblock 102, line 0,  t868,  t868,  (~0x419f)(I32)
	      ## goto
;;
	c0    goto L67?3 ## goto
;;								## 53
.trace 39
L68?3:
	c0    add $r0.14 = $r0.18, 4   ## bblock 50, line 0,  t1096,  t1096,  4(I32)
;;								## 0
	c0    add $r0.13 = $r0.17, 4   ## bblock 50, line 0,  t1097,  t1097,  4(I32)
;;								## 1
	c0    add $r0.11 = $r0.15, 1   ## bblock 50, line 0,  t1098,  t1098,  1(I32)
;;								## 2
	c0    mov $r0.12 = $r0.16   ## t435
	      ## goto
;;
	c0    goto L65?3 ## goto
;;								## 3
.trace 65
L66?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.32 + 0)   ## addr(_?1STRINGVAR.32)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 26, line 263,  raddr(printf)(P32),  addr(_?1STRINGVAR.32)(P32)
;;								## 1
	c0    mov $r0.57 = ((fy2 + 0) + 58820)   ## bblock 27, line 0,  t1079,  (addr(fy2?1.0)(P32) + 0xe5c4(I32))(P32)
;;								## 2
	c0    mov $r0.58 = (~0xa)   ## bblock 27, line 0,  t1080,  (~0xa)(I32)
;;								## 3
.trace 26
L69?3:
	c0    ldw.d $r0.2 = 0[$r0.57]   ## [spec] bblock 46, line 265, t254, t1079
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 28, line 264,  t1368(I1),  t1080,  0(SI32)
;;								## 1
	c0    mov $r0.3 = (_?1STRINGPACKET.33 + 0)   ## addr(_?1STRINGVAR.33)(P32)
;;								## 2
	c0    shr $r0.4 = $r0.2, 8   ## [spec] bblock 46, line 265,  t255(SI24),  t254,  8(SI32)
;;								## 3
	c0    brf $b0.0, L70?3   ## bblock 28, line 264,  t1368(I1)
;;								## 4
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 46, line 265,  raddr(printf)(P32),  addr(_?1STRINGVAR.33)(P32),  t255(SI24)
;;								## 5
	c0    add $r0.57 = $r0.57, 4200   ## bblock 47, line 0,  t1079,  t1079,  4200(I32)
;;								## 6
	c0    add $r0.58 = $r0.58, 1   ## bblock 47, line 0,  t1080,  t1080,  1(I32)
	      ## goto
;;
	c0    goto L69?3 ## goto
;;								## 7
.trace 69
L70?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.34 + 0)   ## addr(_?1STRINGVAR.34)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 29, line 266,  raddr(printf)(P32),  addr(_?1STRINGVAR.34)(P32)
;;								## 1
	c0    sub $r0.60 = $r0.0, $r0.60   ## bblock 30, line 0,  t1038,  0(I32),  t321
;;								## 2
	c0    mov $r0.3 = $r0.60   ## bblock 30, line 0,  t1037,  t1038
;;								## 3
	c0    mov $r0.11 = (fy2 + 0)   ## bblock 30, line 0,  t1035,  addr(fy2?1.0)(P32)
;;								## 4
	c0    mov $r0.10 = (fy1 + 0)   ## bblock 30, line 0,  t1036,  addr(fy1?1.0)(P32)
;;								## 5
	c0    mov $r0.8 = (out + 0)   ## bblock 30, line 0,  t1033,  addr(out?1.0)(P32)
;;								## 6
	c0    mov $r0.9 = $r0.59   ## t322
;;								## 7
.trace 27
L71?3:
	c0    cmplt $b0.0 = $r0.3, $r0.0   ## bblock 31, line 270,  t1369(I1),  t1037,  0(SI32)
;;								## 0
	c0    sub $r0.12 = 3, $r0.9   ## [spec] bblock 39, line 0,  t950,  3(I32),  t322
;;								## 1
	c0    brf $b0.0, L72?3   ## bblock 31, line 270,  t1369(I1)
;;								## 2
	c0    mov $r0.5 = $r0.12   ## bblock 39, line 0,  t949,  t950
;;								## 3
	c0    mov $r0.7 = $r0.8   ## bblock 39, line 0,  t948,  t1033
;;								## 4
	c0    mov $r0.6 = $r0.8   ## bblock 39, line 0,  t947,  t1033
;;								## 5
	c0    mov $r0.4 = $r0.10   ## bblock 39, line 0,  t946,  t1036
;;								## 6
	c0    mov $r0.2 = $r0.11   ## bblock 39, line 0,  t945,  t1035
;;								## 7
	c0    mov $r0.13 = $r0.3   ## t1037
;;								## 8
	c0    mov $r0.14 = $r0.9   ## t322
;;								## 9
	c0    mov $r0.15 = $r0.8   ## t1033
;;								## 10
	c0    mov $r0.16 = $r0.10   ## t1036
;;								## 11
	c0    mov $r0.17 = $r0.11   ## t1035
;;								## 12
.trace 5
L73?3:
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 42, line 272, t590, t945
;;								## 0
	c0    ldw.d $r0.8 = 0[$r0.4]   ## [spec] bblock 42, line 272, t589, t946
;;								## 1
	c0    cmplt $b0.0 = $r0.5, 3   ## bblock 40, line 271,  t1371(I1),  t949,  3(SI32)
;;								## 2
	c0    cmplt $b0.1 = $r0.5, 2   ## [spec] bblock 44, line 271-1,  t1373(I1),  t949,  2(SI32)
;;								## 3
	c0    add $r0.3 = $r0.3, $r0.8   ## [spec] bblock 42, line 272,  t580,  t590,  t589
;;								## 4
	c0    shl $r0.3 = $r0.3, 8   ## [spec] bblock 42, line 272,  t579,  t580,  8(I32)
;;								## 5
	c0    shr $r0.3 = $r0.3, 16   ## [spec] bblock 42, line 272,  t578(SI16),  t579,  16(SI32)
;;								## 6
	c0    brf $b0.0, L74?3   ## bblock 40, line 271,  t1371(I1)
;;								## 7
	c0    zxtb $r0.8 = $r0.3   ## bblock 42, line 272,  t577(I8),  t578(SI16)
;;								## 8
	c0    cmpgt $b0.0 = $r0.8, 125   ## bblock 42, line 273,  t1372(I1),  t577(I8),  125(SI32)
;;								## 9
	c0    ldw.d $r0.9 = 4[$r0.2]   ## [spec] bblock 95, line 272-1, t270, t945
;;								## 10
	c0    ldw.d $r0.8 = 4[$r0.4]   ## [spec] bblock 95, line 272-1, t274, t946
;;								## 11
	c0    cmplt $b0.2 = $r0.5, 1   ## [spec] bblock 97, line 271-2,  t1396(I1),  t949,  1(SI32)
;;								## 12
	c0    ldw.d $r0.10 = 8[$r0.2]   ## [spec] bblock 89, line 272-2, t573, t945
;;								## 13
	c0    add $r0.9 = $r0.9, $r0.8   ## [spec] bblock 95, line 272-1,  t275,  t270,  t274
;;								## 14
	c0    shl $r0.9 = $r0.9, 8   ## [spec] bblock 95, line 272-1,  t593,  t275,  8(I32)
;;								## 15
	c0    shr $r0.9 = $r0.9, 16   ## [spec] bblock 95, line 272-1,  t278(SI16),  t593,  16(SI32)
;;								## 16
	c0    zxtb $r0.8 = $r0.9   ## [spec] bblock 95, line 272-1,  t286(I8),  t278(SI16)
;;								## 17
	c0    cmpgt $b0.3 = $r0.8, 125   ## [spec] bblock 95, line 273-1,  t1395(I1),  t286(I8),  125(SI32)
;;								## 18
	c0    ldw.d $r0.11 = 8[$r0.4]   ## [spec] bblock 89, line 272-2, t572, t946
;;								## 19
	c0    cmplt $b0.4 = $r0.5, $r0.0   ## [spec] bblock 91, line 271-3,  t1394(I1),  t949,  0(SI32)
;;								## 20
	c0    ldw.d $r0.8 = 12[$r0.2]   ## [spec] bblock 83, line 272-3, t587, t945
;;								## 21
	c0    add $r0.10 = $r0.10, $r0.11   ## [spec] bblock 89, line 272-2,  t571,  t573,  t572
;;								## 22
	c0    shl $r0.10 = $r0.10, 8   ## [spec] bblock 89, line 272-2,  t277,  t571,  8(I32)
;;								## 23
	c0    shr $r0.10 = $r0.10, 16   ## [spec] bblock 89, line 272-2,  t570(SI16),  t277,  16(SI32)
;;								## 24
	c0    zxtb $r0.11 = $r0.10   ## [spec] bblock 89, line 272-2,  t569(I8),  t570(SI16)
;;								## 25
	c0    cmpgt $b0.5 = $r0.11, 125   ## [spec] bblock 89, line 273-2,  t1393(I1),  t569(I8),  125(SI32)
;;								## 26
	c0    ldw.d $r0.12 = 12[$r0.4]   ## [spec] bblock 83, line 272-3, t586, t946
;;								## 27
	c0    stb 0[$r0.6] = $r0.3   ## bblock 42, line 272, t947, t578(SI16)
;;								## 28
	c0    brf $b0.0, L75?3   ## bblock 42, line 273,  t1372(I1)
;;								## 29
	c0    add $r0.8 = $r0.8, $r0.12   ## [spec] bblock 83, line 272-3,  t585,  t587,  t586
;;								## 30
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 83, line 272-3,  t584,  t585,  8(I32)
;;								## 31
	c0    shr $r0.8 = $r0.8, 16   ## [spec] bblock 83, line 272-3,  t583(SI16),  t584,  16(SI32)
;;								## 32
	c0    zxtb $r0.3 = $r0.8   ## [spec] bblock 83, line 272-3,  t582(I8),  t583(SI16)
;;								## 33
	c0    cmpgt $b0.0 = $r0.3, 125   ## [spec] bblock 83, line 273-3,  t1392(I1),  t582(I8),  125(SI32)
;;								## 34
	c0    stb 0[$r0.6] = $r0.0   ## bblock 45, line 274, t947, 0(I32)
;;								## 35
L76?3:
	c0    brf $b0.1, L74?3   ## bblock 44, line 271-1,  t1373(I1)
;;								## 36
	c0    stb 1[$r0.6] = $r0.9   ## bblock 95, line 272-1, t947, t278(SI16)
;;								## 37
	c0    brf $b0.3, L77?3   ## bblock 95, line 273-1,  t1395(I1)
;;								## 38
	c0    stb 1[$r0.6] = $r0.0   ## bblock 98, line 274-1, t947, 0(I32)
;;								## 39
L78?3:
	c0    brf $b0.2, L74?3   ## bblock 97, line 271-2,  t1396(I1)
;;								## 40
	c0    stb 2[$r0.6] = $r0.10   ## bblock 89, line 272-2, t947, t570(SI16)
;;								## 41
	c0    brf $b0.5, L79?3   ## bblock 89, line 273-2,  t1393(I1)
;;								## 42
	c0    stb 2[$r0.6] = $r0.0   ## bblock 92, line 274-2, t947, 0(I32)
;;								## 43
L80?3:
	c0    brf $b0.4, L74?3   ## bblock 91, line 271-3,  t1394(I1)
;;								## 44
	c0    stb 3[$r0.6] = $r0.8   ## bblock 83, line 272-3, t947, t583(SI16)
;;								## 45
	c0    brf $b0.0, L81?3   ## bblock 83, line 273-3,  t1392(I1)
;;								## 46
	c0    add $r0.2 = $r0.2, 16   ## bblock 85, line 0,  t945,  t945,  16(I32)
;;								## 47
	c0    add $r0.4 = $r0.4, 16   ## bblock 85, line 0,  t946,  t946,  16(I32)
;;								## 48
	c0    add $r0.7 = $r0.7, 4   ## bblock 85, line 0,  t948,  t948,  4(I32)
;;								## 49
	c0    add $r0.5 = $r0.5, 4   ## bblock 85, line 0,  t949,  t949,  4(I32)
;;								## 50
	c0    stb 3[$r0.6] = $r0.0   ## bblock 86, line 274-3, t947, 0(I32)
;;								## 51
L82?3:
	c0    add $r0.6 = $r0.6, 4   ## bblock 85, line 0,  t947,  t947,  4(I32)
	      ## goto
;;
	c0    goto L73?3 ## goto
;;								## 52
.trace 16
L81?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.5 = $r0.5, 4   ## bblock 85, line 0,  t949,  t949,  4(I32)
;;								## 1
	c0    add $r0.4 = $r0.4, 16   ## bblock 85, line 0,  t946,  t946,  16(I32)
;;								## 2
	c0    add $r0.2 = $r0.2, 16   ## bblock 85, line 0,  t945,  t945,  16(I32)
;;								## 3
	c0    stb 3[$r0.7] = $r0.3   ## bblock 84, line 276-3, t948, 255(I32)
;;								## 4
	c0    add $r0.7 = $r0.7, 4   ## bblock 85, line 0,  t948,  t948,  4(I32)
	      ## goto
;;
	c0    goto L82?3 ## goto
;;								## 5
.trace 40
L74?3:
	c0    add $r0.11 = $r0.17, 4200   ## bblock 41, line 0,  t1035,  t1035,  4200(I32)
;;								## 0
	c0    add $r0.10 = $r0.16, 4200   ## bblock 41, line 0,  t1036,  t1036,  4200(I32)
;;								## 1
	c0    add $r0.8 = $r0.15, 1050   ## bblock 41, line 0,  t1033,  t1033,  1050(I32)
;;								## 2
	c0    add $r0.3 = $r0.13, 1   ## bblock 41, line 0,  t1037,  t1037,  1(I32)
;;								## 3
	c0    mov $r0.9 = $r0.14   ## t322
	      ## goto
;;
	c0    goto L71?3 ## goto
;;								## 4
.trace 15
L79?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 2[$r0.7] = $r0.3   ## bblock 90, line 276-2, t948, 255(I32)
	      ## goto
;;
	c0    goto L80?3 ## goto
;;								## 1
.trace 14
L77?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    stb 1[$r0.7] = $r0.3   ## bblock 96, line 276-1, t948, 255(I32)
	      ## goto
;;
	c0    goto L78?3 ## goto
;;								## 1
.trace 13
L75?3:
	c0    mov $r0.3 = 255   ## 255(I32)
;;								## 0
	c0    add $r0.8 = $r0.8, $r0.12   ## [spec] bblock 83, line 272-3,  t585,  t587,  t586
;;								## 1
	c0    shl $r0.8 = $r0.8, 8   ## [spec] bblock 83, line 272-3,  t584,  t585,  8(I32)
;;								## 2
	c0    shr $r0.8 = $r0.8, 16   ## [spec] bblock 83, line 272-3,  t583(SI16),  t584,  16(SI32)
;;								## 3
	c0    zxtb $r0.11 = $r0.8   ## [spec] bblock 83, line 272-3,  t582(I8),  t583(SI16)
;;								## 4
	c0    cmpgt $b0.0 = $r0.11, 125   ## [spec] bblock 83, line 273-3,  t1392(I1),  t582(I8),  125(SI32)
;;								## 5
	c0    stb 0[$r0.7] = $r0.3   ## bblock 43, line 276, t948, 255(I32)
	      ## goto
;;
	c0    goto L76?3 ## goto
;;								## 6
.trace 71
L72?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.35 + 0)   ## addr(_?1STRINGVAR.35)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 32, line 281,  raddr(printf)(P32),  addr(_?1STRINGVAR.35)(P32)
;;								## 1
	c0    mov $r0.57 = ((out + 0) + 14705)   ## bblock 33, line 0,  t1016,  (addr(out?1.0)(P32) + 0x3971(I32))(P32)
;;								## 2
	c0    mov $r0.58 = (~0xa)   ## bblock 33, line 0,  t1017,  (~0xa)(I32)
;;								## 3
	c0    ldw $r0.59 = 0x24[$r0.1]  ## restore ## t314
;;								## 4
	c0    ldw $r0.60 = 0x28[$r0.1]  ## restore ## t315
	      xnop 1
;;								## 6
;;								## 7
.trace 28
L83?3:
	c0    ldbu.d $r0.4 = 0[$r0.57]   ## [spec] bblock 37, line 283, t304(I8), t1016
;;								## 0
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 34, line 282,  t1370(I1),  t1017,  0(SI32)
;;								## 1
	c0    mov $r0.3 = (_?1STRINGPACKET.36 + 0)   ## addr(_?1STRINGVAR.36)(P32)
;;								## 2
	c0    brf $b0.0, L84?3   ## bblock 34, line 282,  t1370(I1)
;;								## 3
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 37, line 283,  raddr(printf)(P32),  addr(_?1STRINGVAR.36)(P32),  t304(I8)
;;								## 4
	c0    add $r0.57 = $r0.57, 1050   ## bblock 38, line 0,  t1016,  t1016,  1050(I32)
;;								## 5
	c0    add $r0.58 = $r0.58, 1   ## bblock 38, line 0,  t1017,  t1017,  1(I32)
	      ## goto
;;
	c0    goto L83?3 ## goto
;;								## 6
.trace 70
L84?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.37 + 0)   ## addr(_?1STRINGVAR.37)(P32)
;;								## 0
.call printf, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 35, line 284,  raddr(printf)(P32),  addr(_?1STRINGVAR.37)(P32)
;;								## 1
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t308
	      xnop 3
;;								## 5
	c0    ldw $r0.57 = 0x14[$r0.1]  ## restore ## t312
;;								## 6
	c0    ldw $r0.58 = 0x18[$r0.1]  ## restore ## t313
	      xnop 1
;;								## 8
.return ret()
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 36, line 285,  t309,  ?2.3?2auto_size(I32),  t308
;;								## 9
.endp
.section .bss
.section .data
.skip 3
_?1STRINGPACKET.20:
    .data1 10
    .data1 10
    .data1 70
    .data1 76
    .data1 49
    .data1 32
    .data1 102
    .data1 121
    .data1 49
    .data1 58
    .data1 10
    .data1 0
_?1STRINGPACKET.21:
    .data1 37
    .data1 100
    .data1 32
    .data1 0
_?1STRINGPACKET.22:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.23:
    .data1 70
    .data1 76
    .data1 50
    .data1 32
    .data1 102
    .data1 121
    .data1 50
    .data1 58
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.24:
    .data1 37
    .data1 100
    .data1 32
    .data1 0
_?1STRINGPACKET.25:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.26:
    .data1 70
    .data1 76
    .data1 51
    .data1 32
    .data1 102
    .data1 116
    .data1 58
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.27:
    .data1 37
    .data1 100
    .data1 32
    .data1 0
_?1STRINGPACKET.28:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.29:
    .data1 70
    .data1 76
    .data1 52
    .data1 32
    .data1 102
    .data1 121
    .data1 49
    .data1 58
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.30:
    .data1 37
    .data1 100
    .data1 32
    .data1 0
_?1STRINGPACKET.31:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.32:
    .data1 70
    .data1 76
    .data1 53
    .data1 32
    .data1 102
    .data1 121
    .data1 50
    .data1 58
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.33:
    .data1 37
    .data1 100
    .data1 32
    .data1 0
_?1STRINGPACKET.34:
    .data1 10
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.35:
    .data1 70
    .data1 76
    .data1 54
    .data1 32
    .data1 111
    .data1 117
    .data1 116
    .data1 58
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.36:
    .data1 37
    .data1 100
    .data1 32
    .data1 0
_?1STRINGPACKET.37:
    .data1 10
    .data1 10
    .data1 0
.equ ?2.3?2scratch.0, 0x0
.equ ?2.3?2ras_p, 0x10
.equ ?2.3?2spill_p, 0x14
.section .data
.section .text
.equ ?2.3?2auto_size, 0x40
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
.comm ft, 0x602160, 4
.comm fy2, 0x602160, 4
.comm fy1, 0x602160, 4
.comm t, 0x602160, 4
.comm y2, 0x602160, 4
.comm y1, 0x602160, 4
.section .text
.import _r_ilfloat
.type _r_ilfloat,@function
.import _r_ufloat
.type _r_ufloat,@function
.import _d_r
.type _d_r,@function
.import _r_ufix
.type _r_ufix,@function
.import _r_mul
.type _r_mul,@function
.import _r_add
.type _r_add,@function
.import printf
.type printf,@function
