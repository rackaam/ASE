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
 ## Begin isqrt
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:u32)
isqrt::
.trace 4
	      ## auto_size == 0
;;								## 0
	c0    mov $r0.6 = (~0x5)   ## bblock 0, line 0,  t86,  (~0x5)(I32)
;;								## 1
	c0    mov $r0.5 = $r0.0   ## bblock 0, line 35,  t42(I16),  0(I32)
;;								## 2
	c0    mov $r0.4 = $r0.0   ## bblock 0, line 36,  t41,  0(SI32)
;;								## 3
	c0    mov $r0.2 = $r0.3   ## t38
;;								## 4
.trace 1
L0?3:
	c0    and $r0.3 = $r0.2, 192   ## bblock 1, line 43,  t59,  t38,  192(I32)
;;								## 0
	c0    shru $r0.3 = $r0.3, 6   ## bblock 1, line 43,  t5(I26),  t59,  6(SI32)
;;								## 1
	c0    sh2add $r0.4 = $r0.4, $r0.3   ## bblock 1, line 43,  t64,  t41,  t5(I26)
;;								## 2
	c0    shl $r0.5 = $r0.5, 1   ## bblock 1, line 45,  t63,  t42(I16),  1(SI32)
;;								## 3
	c0    zxth $r0.3 = $r0.5   ## bblock 1, line 45,  t53(I16),  t63
;;								## 4
	c0    sh1add $r0.7 = $r0.3, 1   ## bblock 1, line 46,  t51,  t53(I16),  1(SI32)
;;								## 5
	c0    cmpgeu $b0.0 = $r0.4, $r0.7   ## bblock 1, line 47,  t56(I1),  t64,  t51
;;								## 6
	c0    add $r0.5 = $r0.5, 1   ## bblock 1, line 49,  t58,  t63,  1(SI32)
;;								## 7
	c0    zxth $r0.5 = $r0.5   ## bblock 1, line 49,  t55(I16),  t58
;;								## 8
	c0    slct $r0.5 = $b0.0, $r0.5, $r0.3   ## bblock 1, line 49,  t61(I16),  t56(I1),  t55(I16),  t53(I16)
;;								## 9
	c0    shl $r0.5 = $r0.5, 1   ## bblock 1, line 45-1,  t73,  t61(I16),  1(SI32)
;;								## 10
	c0    zxth $r0.3 = $r0.5   ## bblock 1, line 45-1,  t74(I16),  t73
;;								## 11
	c0    sh1add $r0.8 = $r0.3, 1   ## bblock 1, line 46-1,  t76,  t74(I16),  1(SI32)
;;								## 12
	c0    sub $r0.7 = $r0.4, $r0.7   ## bblock 1, line 48,  t57,  t64,  t51
;;								## 13
	c0    slct $r0.7 = $b0.0, $r0.7, $r0.4   ## bblock 1, line 48,  t60,  t56(I1),  t57,  t64
;;								## 14
	c0    shl $r0.2 = $r0.2, 2   ## bblock 1, line 44,  t65,  t38,  2(SI32)
;;								## 15
	c0    and $r0.9 = $r0.2, 192   ## bblock 1, line 43-1,  t68,  t65,  192(I32)
;;								## 16
	c0    shru $r0.9 = $r0.9, 6   ## bblock 1, line 43-1,  t69(I26),  t68,  6(SI32)
;;								## 17
	c0    sh2add $r0.7 = $r0.7, $r0.9   ## bblock 1, line 43-1,  t71,  t60,  t69(I26)
;;								## 18
	c0    cmpgeu $b0.0 = $r0.7, $r0.8   ## bblock 1, line 47-1,  t77(I1),  t71,  t76
;;								## 19
	c0    sub $r0.8 = $r0.7, $r0.8   ## bblock 1, line 48-1,  t78,  t71,  t76
;;								## 20
	c0    slct $r0.8 = $b0.0, $r0.8, $r0.7   ## bblock 1, line 48-1,  t81,  t77(I1),  t78,  t71
;;								## 21
	c0    add $r0.5 = $r0.5, 1   ## bblock 1, line 49-1,  t79,  t73,  1(SI32)
;;								## 22
	c0    zxth $r0.5 = $r0.5   ## bblock 1, line 49-1,  t80(I16),  t79
;;								## 23
	c0    slct $r0.5 = $b0.0, $r0.5, $r0.3   ## bblock 1, line 49-1,  t82(I16),  t77(I1),  t80(I16),  t74(I16)
;;								## 24
	c0    shl $r0.2 = $r0.2, 2   ## bblock 1, line 44-1,  t72,  t65,  2(SI32)
;;								## 25
	c0    cmplt $b0.0 = $r0.6, $r0.0   ## bblock 1, line 41-2,  t99(I1),  t86,  0(SI32)
;;								## 26
	c0    and $r0.3 = $r0.2, 192   ## [spec] bblock 5, line 43-2,  t4,  t72,  192(I32)
;;								## 27
	c0    brf $b0.0, L1?3   ## bblock 1, line 41-2,  t99(I1)
;;								## 28
	c0    shru $r0.3 = $r0.3, 6   ## bblock 5, line 43-2,  t52(I26),  t4,  6(SI32)
;;								## 29
	c0    sh2add $r0.8 = $r0.8, $r0.3   ## bblock 5, line 43-2,  t49,  t81,  t52(I26)
;;								## 30
	c0    shl $r0.5 = $r0.5, 1   ## bblock 5, line 45-2,  t12,  t82(I16),  1(SI32)
;;								## 31
	c0    zxth $r0.3 = $r0.5   ## bblock 5, line 45-2,  t50(I16),  t12
;;								## 32
	c0    sh1add $r0.7 = $r0.3, 1   ## bblock 5, line 46-2,  t40,  t50(I16),  1(SI32)
;;								## 33
	c0    cmpgeu $b0.0 = $r0.8, $r0.7   ## bblock 5, line 47-2,  t44(I1),  t49,  t40
;;								## 34
	c0    sub $r0.7 = $r0.8, $r0.7   ## bblock 5, line 48-2,  t45,  t49,  t40
;;								## 35
	c0    slct $r0.4 = $b0.0, $r0.7, $r0.8   ## bblock 5, line 48-2,  t41,  t44(I1),  t45,  t49
;;								## 36
	c0    add $r0.5 = $r0.5, 1   ## bblock 5, line 49-2,  t46,  t12,  1(SI32)
;;								## 37
	c0    zxth $r0.5 = $r0.5   ## bblock 5, line 49-2,  t47(I16),  t46
;;								## 38
	c0    slct $r0.5 = $b0.0, $r0.5, $r0.3   ## bblock 5, line 49-2,  t42(I16),  t44(I1),  t47(I16),  t50(I16)
;;								## 39
	c0    shl $r0.2 = $r0.2, 2   ## bblock 5, line 44-2,  t38,  t72,  2(SI32)
;;								## 40
	c0    add $r0.6 = $r0.6, 3   ## bblock 5, line 0,  t86,  t86,  3(I32)
	      ## goto
;;
	c0    goto L0?3 ## goto
;;								## 41
.trace 3
L1?3:
	c0    mov $r0.3 = $r0.5   ## t82(I16)
;;								## 0
.return ret($r0.3:u32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 6, line 52,  t27,  ?2.1?2auto_size(I32),  t26
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.1?2auto_size, 0x0
 ## End isqrt
.equ _?1TEMPLATEPACKET.18, 0x0
.equ _?1TEMPLATEPACKET.1, 0x0
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:s32,$r0.4:u32)
main::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x40)
;;								## 0
	c0    stw 0x18[$r0.1] = $l0.0  ## spill ## t103
;;								## 1
	c0    stw 0x1c[$r0.1] = $r0.3  ## spill ## t116
;;								## 2
	c0    stw 0x20[$r0.1] = $r0.4  ## spill ## t117
;;								## 3
	c0    mov $r0.2 = $r0.0   ## bblock 0, line 70,  t118,  0(SI32)
;;								## 4
	c0    stw 0x24[$r0.1] = $r0.2  ## spill ## t118
;;								## 5
.call sim_ta_disable, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = sim_ta_disable   ## bblock 0, line 74,  raddr(sim_ta_disable)(P32)
;;								## 6
	c0    ldw $r0.2 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 1, line 76, t2, 0(I32)
;;								## 7
	c0    ldw $r0.6 = 0x20[$r0.1]  ## restore ## t117
;;								## 8
	c0    mov $r0.4 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 9
	c0    ldw $r0.3 = 12[$r0.2]   ## bblock 1, line 76, t3, t2
;;								## 10
	c0    ldw $r0.5 = 0[$r0.6]   ## bblock 1, line 76, t8, t117
	      xnop 1
;;								## 12
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 1, line 76,  raddr(fprintf)(P32),  t3,  addr(_?1STRINGVAR.1)(P32),  t8
;;								## 13
	c0    ldw $r0.2 = 0x1c[$r0.1]  ## restore ## t116
;;								## 14
	c0    ldw.d $r0.6 = ((_impure_ptr + 0) + 0)[$r0.0]   ## [spec] bblock 43, line 79, t11, 0(I32)
;;								## 15
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 16
	c0    cmplt $b0.0 = $r0.2, 3   ## bblock 2, line 78,  t122(I1),  t116,  3(SI32)
;;								## 17
	c0    ldw.d $r0.3 = 12[$r0.6]   ## [spec] bblock 43, line 79, t12, t11
;;								## 18
	c0    brf $b0.0, L2?3   ## bblock 2, line 78,  t122(I1)
;;								## 19
	c0    ldw $r0.5 = 0[$r0.7]   ## bblock 43, line 79, t17, t117
;;								## 20
	c0    mov $r0.4 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
;;								## 21
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 43, line 79,  raddr(fprintf)(P32),  t12,  addr(_?1STRINGVAR.2)(P32),  t17
;;								## 22
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 23
.call exit, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = exit   ## bblock 44, line 80,  raddr(exit)(P32),  1(SI32)
;;								## 24
L3?3:
	c0    ldw $r0.2 = 0x1c[$r0.1]  ## restore ## t116
;;								## 25
	c0    ldw $r0.5 = 0x20[$r0.1]  ## restore ## t117
;;								## 26
	c0    mov $r0.4 = (_?1STRINGPACKET.3 + 0)   ## addr(_?1STRINGVAR.3)(P32)
;;								## 27
	c0    cmpeq $b0.0 = $r0.2, 4   ## bblock 3, line 84,  t123(I1),  t116,  4(SI32)
;;								## 28
	c0    ldw.d $r0.3 = 12[$r0.5]   ## [spec] bblock 25, line 85, t22, t117
;;								## 29
	c0    brf $b0.0, L4?3   ## bblock 3, line 84,  t123(I1)
;;								## 30
.call strcmp, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = strcmp   ## bblock 25, line 85,  raddr(strcmp)(P32),  t22,  addr(_?1STRINGVAR.3)(P32)
;;								## 31
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## bblock 26, line 85,  t131(I1),  t19,  0(SI32)
;;								## 32
	c0    mov $r0.2 = 1   ## [spec] bblock 42, line 86,  t118,  1(SI32)
;;								## 33
	c0    brf $b0.0, L5?3   ## bblock 26, line 85,  t131(I1)
;;								## 34
.trace 8
	c0    stw 0x24[$r0.1] = $r0.2  ## spill ## t118
;;								## 0
	c0    add $r0.4 = $r0.1, 0x14   ## [spec] bblock 5, line 109,  t68,  t104,  offset(width?1.6)=0x14(P32)
;;								## 1
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 2
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
;;								## 3
	c0    goto L6?3 ## goto
;;								## 4
.trace 3
L8?3:
	c0    ldw.d $r0.3 = 0x14[$r0.1]   ## [spec] bblock 21, line 121, t82, t104
;;								## 0
	c0    ldw.d $r0.4 = 0x10[$r0.1]   ## [spec] bblock 21, line 121, t83, t104
;;								## 1
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
	      xnop 2
;;								## 4
	c0    cmpeq $b0.0 = $r0.2, 2   ## bblock 9, line 135,  t126(I1),  t118,  2(SI32)
	      xnop 1
;;								## 6
	c0    brf $b0.0, L9?3   ## bblock 9, line 135,  t126(I1)
;;								## 7
.call deriche_slow, caller, arg($r0.3:s32,$r0.4:s32), ret()
	c0    call $l0.0 = deriche_slow   ## bblock 21, line 121,  raddr(deriche_slow)(P32),  t82,  t83
	      ## goto
;;
	c0    goto L7?3 ## goto
;;								## 8
.trace 7
L9?3:
	c0    ldw.d $r0.3 = 0x14[$r0.1]   ## [spec] bblock 20, line 124, t84, t104
;;								## 0
	c0    ldw.d $r0.4 = 0x10[$r0.1]   ## [spec] bblock 20, line 124, t85, t104
;;								## 1
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
	      xnop 2
;;								## 4
	c0    cmpeq $b0.0 = $r0.2, 3   ## bblock 10, line 135,  t127(I1),  t118,  3(SI32)
	      xnop 1
;;								## 6
	c0    brf $b0.0, L10?3   ## bblock 10, line 135,  t127(I1)
;;								## 7
.call deriche_fused, caller, arg($r0.3:s32,$r0.4:s32), ret()
	c0    call $l0.0 = deriche_fused   ## bblock 20, line 124,  raddr(deriche_fused)(P32),  t84,  t85
	      ## goto
;;
	c0    goto L7?3 ## goto
;;								## 8
.trace 9
L10?3:
	c0    ldw.d $r0.3 = 0x14[$r0.1]   ## [spec] bblock 19, line 127, t86, t104
;;								## 0
	c0    ldw.d $r0.4 = 0x10[$r0.1]   ## [spec] bblock 19, line 127, t87, t104
;;								## 1
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
	      xnop 2
;;								## 4
	c0    cmpeq $b0.0 = $r0.2, 4   ## bblock 11, line 135,  t128(I1),  t118,  4(SI32)
	      xnop 1
;;								## 6
	c0    brf $b0.0, L11?3   ## bblock 11, line 135,  t128(I1)
;;								## 7
.call deriche_array, caller, arg($r0.3:s32,$r0.4:s32), ret()
	c0    call $l0.0 = deriche_array   ## bblock 19, line 127,  raddr(deriche_array)(P32),  t86,  t87
	      ## goto
;;
	c0    goto L7?3 ## goto
;;								## 8
.trace 11
L11?3:
	c0    ldw.d $r0.3 = 0x14[$r0.1]   ## [spec] bblock 18, line 130, t89, t104
;;								## 0
	c0    ldw.d $r0.4 = 0x10[$r0.1]   ## [spec] bblock 18, line 130, t90, t104
;;								## 1
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
	      xnop 2
;;								## 4
	c0    cmpeq $b0.0 = $r0.2, 5   ## bblock 12, line 135,  t129(I1),  t118,  5(SI32)
	      xnop 1
;;								## 6
	c0    brf $b0.0, L12?3   ## bblock 12, line 135,  t129(I1)
;;								## 7
.call deriche_short, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = deriche_short   ## bblock 18, line 130,  raddr(deriche_short)(P32),  t89,  t90
;;								## 8
	c0    goto L7?3 ## goto
;;								## 9
.trace 14
L12?3:
	c0    ldw.d $r0.3 = 0x14[$r0.1]   ## [spec] bblock 17, line 133, t92, t104
;;								## 0
	c0    ldw.d $r0.4 = 0x10[$r0.1]   ## [spec] bblock 17, line 133, t93, t104
;;								## 1
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
	      xnop 2
;;								## 4
	c0    cmpeq $b0.0 = $r0.2, 6   ## bblock 13, line 135,  t130(I1),  t118,  6(SI32)
	      xnop 1
;;								## 6
	c0    brf $b0.0, L7?3   ## bblock 13, line 135,  t130(I1)
;;								## 7
.call deriche_simd, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = deriche_simd   ## bblock 17, line 133,  raddr(deriche_simd)(P32),  t92,  t93
;;								## 8
	c0    goto L7?3 ## goto
;;								## 9
.trace 5
L14?3:
	c0    ldw $r0.2 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 23, line 101, t57, 0(I32)
;;								## 0
	c0    ldw $r0.6 = 0x20[$r0.1]  ## restore ## t117
;;								## 1
	c0    mov $r0.4 = (_?1STRINGPACKET.9 + 0)   ## addr(_?1STRINGVAR.9)(P32)
;;								## 2
	c0    ldw $r0.3 = 12[$r0.2]   ## bblock 23, line 101, t58, t57
;;								## 3
	c0    ldw $r0.5 = 12[$r0.6]   ## bblock 23, line 101, t63, t117
	      xnop 1
;;								## 5
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 23, line 101,  raddr(fprintf)(P32),  t58,  addr(_?1STRINGVAR.9)(P32),  t63
;;								## 6
	c0    mov $r0.3 = 1   ## 1(SI32)
;;								## 7
.call exit, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = exit   ## bblock 24, line 102,  raddr(exit)(P32),  1(SI32)
;;								## 8
	c0    ldw $r0.2 = 0x20[$r0.1]  ## restore ## t117
;;								## 9
	c0    add $r0.4 = $r0.1, 0x14   ## bblock 5, line 109,  t68,  t104,  offset(width?1.6)=0x14(P32)
;;								## 10
	c0    add $r0.5 = $r0.1, 0x10   ## bblock 5, line 109,  t69,  t104,  offset(height?1.6)=0x10(P32)
;;								## 11
	c0    ldw $r0.3 = 4[$r0.2]   ## bblock 5, line 109, t67, t117
	      xnop 1
;;								## 13
	c0    goto L13?3 ## goto
;;								## 14
.trace 6
L5?3:
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 0
	c0    mov $r0.4 = (_?1STRINGPACKET.4 + 0)   ## addr(_?1STRINGVAR.4)(P32)
	      xnop 1
;;								## 2
	c0    ldw $r0.3 = 12[$r0.7]   ## bblock 27, line 87, t28, t117
	      xnop 1
;;								## 4
.call strcmp, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = strcmp   ## bblock 27, line 87,  raddr(strcmp)(P32),  t28,  addr(_?1STRINGVAR.4)(P32)
;;								## 5
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## bblock 28, line 87,  t132(I1),  t25,  0(SI32)
;;								## 6
	c0    add $r0.4 = $r0.1, 0x14   ## [spec] bblock 5, line 109,  t68,  t104,  offset(width?1.6)=0x14(P32)
;;								## 7
	c0    brf $b0.0, L15?3   ## bblock 28, line 87,  t132(I1)
;;								## 8
	c0    mov $r0.2 = 2   ## bblock 41, line 88,  t118,  2(SI32)
;;								## 9
	c0    stw 0x24[$r0.1] = $r0.2  ## spill ## t118
;;								## 10
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 11
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
;;								## 12
	c0    goto L6?3 ## goto
;;								## 13
.trace 10
L15?3:
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 0
	c0    mov $r0.4 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
	      xnop 1
;;								## 2
	c0    ldw $r0.3 = 12[$r0.7]   ## bblock 29, line 89, t34, t117
	      xnop 1
;;								## 4
.call strcmp, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = strcmp   ## bblock 29, line 89,  raddr(strcmp)(P32),  t34,  addr(_?1STRINGVAR.5)(P32)
;;								## 5
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## bblock 30, line 89,  t133(I1),  t31,  0(SI32)
;;								## 6
	c0    add $r0.4 = $r0.1, 0x14   ## [spec] bblock 5, line 109,  t68,  t104,  offset(width?1.6)=0x14(P32)
;;								## 7
	c0    brf $b0.0, L16?3   ## bblock 30, line 89,  t133(I1)
;;								## 8
	c0    mov $r0.2 = 3   ## bblock 40, line 90,  t118,  3(SI32)
;;								## 9
	c0    stw 0x24[$r0.1] = $r0.2  ## spill ## t118
;;								## 10
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 11
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
;;								## 12
	c0    goto L6?3 ## goto
;;								## 13
.trace 12
L16?3:
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 0
	c0    mov $r0.4 = (_?1STRINGPACKET.6 + 0)   ## addr(_?1STRINGVAR.6)(P32)
	      xnop 1
;;								## 2
	c0    ldw $r0.3 = 12[$r0.7]   ## bblock 31, line 91, t40, t117
	      xnop 1
;;								## 4
.call strcmp, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = strcmp   ## bblock 31, line 91,  raddr(strcmp)(P32),  t40,  addr(_?1STRINGVAR.6)(P32)
;;								## 5
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## bblock 32, line 91,  t134(I1),  t37,  0(SI32)
;;								## 6
	c0    add $r0.4 = $r0.1, 0x14   ## [spec] bblock 5, line 109,  t68,  t104,  offset(width?1.6)=0x14(P32)
;;								## 7
	c0    brf $b0.0, L17?3   ## bblock 32, line 91,  t134(I1)
;;								## 8
	c0    mov $r0.2 = 4   ## bblock 39, line 92,  t118,  4(SI32)
;;								## 9
	c0    stw 0x24[$r0.1] = $r0.2  ## spill ## t118
;;								## 10
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 11
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
;;								## 12
	c0    goto L6?3 ## goto
;;								## 13
.trace 13
L17?3:
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 0
	c0    mov $r0.4 = (_?1STRINGPACKET.7 + 0)   ## addr(_?1STRINGVAR.7)(P32)
	      xnop 1
;;								## 2
	c0    ldw $r0.3 = 12[$r0.7]   ## bblock 33, line 93, t46, t117
	      xnop 1
;;								## 4
.call strcmp, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = strcmp   ## bblock 33, line 93,  raddr(strcmp)(P32),  t46,  addr(_?1STRINGVAR.7)(P32)
;;								## 5
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## bblock 34, line 93,  t135(I1),  t43,  0(SI32)
;;								## 6
	c0    add $r0.4 = $r0.1, 0x14   ## [spec] bblock 5, line 109,  t68,  t104,  offset(width?1.6)=0x14(P32)
;;								## 7
	c0    brf $b0.0, L18?3   ## bblock 34, line 93,  t135(I1)
;;								## 8
	c0    mov $r0.2 = 5   ## bblock 38, line 94,  t118,  5(SI32)
;;								## 9
	c0    stw 0x24[$r0.1] = $r0.2  ## spill ## t118
;;								## 10
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 11
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
;;								## 12
	c0    goto L6?3 ## goto
;;								## 13
.trace 15
L18?3:
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 0
	c0    mov $r0.4 = (_?1STRINGPACKET.8 + 0)   ## addr(_?1STRINGVAR.8)(P32)
	      xnop 1
;;								## 2
	c0    ldw $r0.3 = 12[$r0.7]   ## bblock 35, line 95, t52, t117
	      xnop 1
;;								## 4
.call strcmp, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = strcmp   ## bblock 35, line 95,  raddr(strcmp)(P32),  t52,  addr(_?1STRINGVAR.8)(P32)
;;								## 5
	c0    cmpne $b0.0 = $r0.3, $r0.0   ## bblock 36, line 96,  t136(I1),  t49,  0(I32)
;;								## 6
	c0    slct $r0.2 = $b0.0, $r0.0, 6   ## bblock 36, line 96,  t118,  t136(I1),  0(SI32),  6(SI32)
;;								## 7
	c0    stw 0x24[$r0.1] = $r0.2  ## spill ## t118
;;								## 8
	c0    add $r0.4 = $r0.1, 0x14   ## [spec] bblock 5, line 109,  t68,  t104,  offset(width?1.6)=0x14(P32)
;;								## 9
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 10
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
;;								## 11
	c0    goto L6?3 ## goto
;;								## 12
.trace 2
L4?3:
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 0
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
;;								## 1
	c0    add $r0.4 = $r0.1, 0x14   ## [spec] bblock 5, line 109,  t68,  t104,  offset(width?1.6)=0x14(P32)
;;								## 2
L6?3:
	c0    ldw.d $r0.3 = 4[$r0.7]   ## [spec] bblock 5, line 109, t67, t117
;;								## 3
	c0    cmpeq $b0.0 = $r0.2, $r0.0   ## bblock 4, line 100,  t124(I1),  t118,  0(SI32)
;;								## 4
	c0    add $r0.5 = $r0.1, 0x10   ## [spec] bblock 5, line 109,  t69,  t104,  offset(height?1.6)=0x10(P32)
;;								## 5
	c0    br $b0.0, L14?3   ## bblock 4, line 100,  t124(I1)
;;								## 6
L13?3:
	c0    mov $r0.6 = (in + 0)   ## addr(in?1.0)(P32)
;;								## 7
.call load_pgm, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32), ret($r0.3:s32)
	c0    call $l0.0 = load_pgm   ## bblock 5, line 109,  raddr(load_pgm)(P32),  t67,  t68,  t69,  addr(in?1.0)(P32)
;;								## 8
	c0    ldw $r0.5 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 6, line 110, t73, 0(I32)
;;								## 9
	c0    mov $r0.4 = (_?1STRINGPACKET.10 + 0)   ## addr(_?1STRINGVAR.10)(P32)
	      xnop 1
;;								## 11
	c0    ldw $r0.3 = 8[$r0.5]   ## bblock 6, line 110, t74, t73
	      xnop 1
;;								## 13
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 6, line 110,  raddr(fprintf)(P32),  t74,  addr(_?1STRINGVAR.10)(P32)
;;								## 14
.call sim_ta_enable, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = sim_ta_enable   ## bblock 7, line 113,  raddr(sim_ta_enable)(P32)
;;								## 15
	c0    ldw $r0.2 = 0x24[$r0.1]  ## restore ## t118
;;								## 16
	c0    ldw.d $r0.3 = 0x14[$r0.1]   ## [spec] bblock 22, line 118, t80, t104
;;								## 17
	c0    ldw.d $r0.4 = 0x10[$r0.1]   ## [spec] bblock 22, line 118, t81, t104
;;								## 18
	c0    cmpeq $b0.0 = $r0.2, 1   ## bblock 8, line 135,  t125(I1),  t118,  1(SI32)
	      xnop 1
;;								## 20
	c0    brf $b0.0, L8?3   ## bblock 8, line 135,  t125(I1)
;;								## 21
.call deriche_float, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = deriche_float   ## bblock 22, line 118,  raddr(deriche_float)(P32),  t80,  t81
;;								## 22
L7?3:
.call sim_ta_finish, caller, arg(), ret($r0.3:s32)
	c0    call $l0.0 = sim_ta_finish   ## bblock 14, line 138,  raddr(sim_ta_finish)(P32)
;;								## 23
	c0    ldw $r0.7 = 0x20[$r0.1]  ## restore ## t117
;;								## 24
	c0    ldw $r0.4 = 0x14[$r0.1]   ## bblock 15, line 141, t99, t104
;;								## 25
	c0    ldw $r0.5 = 0x10[$r0.1]   ## bblock 15, line 141, t100, t104
;;								## 26
	c0    ldw $r0.3 = 8[$r0.7]   ## bblock 15, line 141, t98, t117
;;								## 27
	c0    mov $r0.6 = (out + 0)   ## addr(out?1.0)(P32)
;;								## 28
.call save_pgm, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:s32,$r0.6:u32), ret($r0.3:s32)
	c0    call $l0.0 = save_pgm   ## bblock 15, line 141,  raddr(save_pgm)(P32),  t98,  t99,  t100,  addr(out?1.0)(P32)
;;								## 29
	c0    ldw $l0.0 = 0x18[$r0.1]  ## restore ## t103
;;								## 30
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	      xnop 2
;;								## 33
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 16, line 142,  t104,  ?2.2?2auto_size(I32),  t103
;;								## 34
.trace 4
L2?3:
	c0    goto L3?3 ## goto
;;								## 0
.endp
.section .bss
.section .data
_?1STRINGPACKET.2:
    .data1 117
    .data1 115
    .data1 97
    .data1 103
    .data1 101
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 105
    .data1 110
    .data1 46
    .data1 112
    .data1 103
    .data1 109
    .data1 32
    .data1 111
    .data1 117
    .data1 116
    .data1 46
    .data1 112
    .data1 103
    .data1 109
    .data1 32
    .data1 109
    .data1 111
    .data1 100
    .data1 101
    .data1 0
.skip 2
_?1STRINGPACKET.1:
    .data1 117
    .data1 115
    .data1 97
    .data1 103
    .data1 101
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 105
    .data1 110
    .data1 46
    .data1 112
    .data1 103
    .data1 109
    .data1 32
    .data1 111
    .data1 117
    .data1 116
    .data1 46
    .data1 112
    .data1 103
    .data1 109
    .data1 32
    .data1 109
    .data1 111
    .data1 100
    .data1 101
    .data1 61
    .data1 123
    .data1 102
    .data1 108
    .data1 111
    .data1 97
    .data1 116
    .data1 95
    .data1 115
    .data1 108
    .data1 111
    .data1 119
    .data1 44
    .data1 102
    .data1 105
    .data1 120
    .data1 101
    .data1 100
    .data1 95
    .data1 115
    .data1 108
    .data1 111
    .data1 119
    .data1 44
    .data1 102
    .data1 105
    .data1 120
    .data1 101
    .data1 100
    .data1 95
    .data1 102
    .data1 97
    .data1 115
    .data1 116
    .data1 125
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.3:
    .data1 102
    .data1 108
    .data1 111
    .data1 97
    .data1 116
    .data1 95
    .data1 115
    .data1 108
    .data1 111
    .data1 119
    .data1 0
.skip 1
_?1STRINGPACKET.4:
    .data1 102
    .data1 105
    .data1 120
    .data1 101
    .data1 100
    .data1 95
    .data1 115
    .data1 108
    .data1 111
    .data1 119
    .data1 0
.skip 1
_?1STRINGPACKET.5:
    .data1 102
    .data1 105
    .data1 120
    .data1 101
    .data1 100
    .data1 95
    .data1 102
    .data1 97
    .data1 115
    .data1 116
    .data1 0
.skip 1
_?1STRINGPACKET.6:
    .data1 102
    .data1 105
    .data1 120
    .data1 101
    .data1 100
    .data1 95
    .data1 97
    .data1 114
    .data1 114
    .data1 97
    .data1 121
    .data1 0
_?1STRINGPACKET.7:
    .data1 102
    .data1 105
    .data1 120
    .data1 101
    .data1 100
    .data1 95
    .data1 115
    .data1 104
    .data1 111
    .data1 114
    .data1 116
    .data1 0
_?1STRINGPACKET.8:
    .data1 102
    .data1 105
    .data1 120
    .data1 101
    .data1 100
    .data1 95
    .data1 115
    .data1 105
    .data1 109
    .data1 100
    .data1 0
.skip 1
_?1STRINGPACKET.9:
    .data1 117
    .data1 110
    .data1 107
    .data1 110
    .data1 111
    .data1 119
    .data1 110
    .data1 32
    .data1 111
    .data1 112
    .data1 101
    .data1 114
    .data1 97
    .data1 116
    .data1 105
    .data1 110
    .data1 103
    .data1 32
    .data1 109
    .data1 111
    .data1 100
    .data1 101
    .data1 32
    .data1 37
    .data1 115
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.10:
    .data1 108
    .data1 111
    .data1 97
    .data1 100
    .data1 101
    .data1 100
    .data1 32
    .data1 46
    .data1 46
    .data1 46
    .data1 0
.equ ?2.2?2scratch.0, 0x0
.equ _?1PACKET.6, 0x10
.equ _?1PACKET.5, 0x14
.equ ?2.2?2ras_p, 0x18
.equ ?2.2?2spill_p, 0x1c
.section .data
.section .text
.equ ?2.2?2auto_size, 0x40
 ## End main
.section .bss
.section .data
.section .data
.import _impure_ptr
.type _impure_ptr,@object
.comm out, 0x180858, 4
.comm in, 0x180858, 4
.comm Gy, 0x602160, 4
.comm Gx, 0x602160, 4
.section .text
.import sim_ta_finish
.type sim_ta_finish,@function
.import deriche_simd
.type deriche_simd,@function
.import deriche_short
.type deriche_short,@function
.import deriche_float
.type deriche_float,@function
.import sim_ta_enable
.type sim_ta_enable,@function
.import sim_ta_disable
.type sim_ta_disable,@function
.import deriche_array
.type deriche_array,@function
.import deriche_slow
.type deriche_slow,@function
.import deriche_fused
.type deriche_fused,@function
.import save_pgm
.type save_pgm,@function
.import load_pgm
.type load_pgm,@function
.import exit
.type exit,@function
.import strcmp
.type strcmp,@function
.import fprintf
.type fprintf,@function
