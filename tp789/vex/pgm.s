 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /home/matthias/vex-3.43 -I../include/ -ms -mas_g -mas_t -O2 -fmm=./vliw2.mm -DVEX -o edge_detect"
.sversion 3.43
.rta 2
.section .bss
.align 32
.section .data
.align 32
.equ _?1TEMPLATEPACKET.9, 0x0
.equ _?1TEMPLATEPACKET.7, 0x0
.equ _?1TEMPLATEPACKET.17, 0x0
 ## Begin load_pgm
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-192, arg($r0.3:u32,$r0.4:u32,$r0.5:u32,$r0.6:u32)
load_pgm::
.trace 23
	c0    add $r0.1 = $r0.1, (-0xc0)
;;								## 0
	c0    stw 0x94[$r0.1] = $l0.0  ## spill ## t133
;;								## 1
	c0    stw 0xb4[$r0.1] = $r0.4  ## spill ## t149
;;								## 2
	c0    stw 0xb8[$r0.1] = $r0.5  ## spill ## t150
	c0    mov $r0.4 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 3
	c0    stw 0xbc[$r0.1] = $r0.6  ## spill ## t151
;;								## 4
	c0    stw 0x98[$r0.1] = $r0.63  ## spill ## t143
;;								## 5
	c0    stw 0x9c[$r0.1] = $r0.62  ## spill ## t142
;;								## 6
	c0    stw 0xa0[$r0.1] = $r0.61  ## spill ## t141
;;								## 7
	c0    stw 0xa4[$r0.1] = $r0.60  ## spill ## t140
;;								## 8
	c0    stw 0xa8[$r0.1] = $r0.59  ## spill ## t139
;;								## 9
	c0    stw 0xac[$r0.1] = $r0.58  ## spill ## t138
;;								## 10
	c0    add $r0.58 = $r0.1, 0x10   ## bblock 0, line 32,  t0,  t134,  offset(comment?1.2)=0x10(P32)
	c0    stw 0xb0[$r0.1] = $r0.57  ## spill ## t137
;;								## 11
.call fopen, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = fopen   ## bblock 0, line 29,  raddr(fopen)(P32),  t2,  addr(_?1STRINGVAR.1)(P32)
;;								## 12
	c0    cmpne $b0.0 = $r0.3, $r0.0   ## bblock 1, line 33,  t177(I1),  t1,  0x0(P32)
	c0    add $r0.62 = $r0.1, 0x90   ## [spec] bblock 3, line 72,  t74,  t134,  offset(depth?1.2)=0x90(P32)
;;								## 13
	c0    mov $r0.57 = $r0.0   ## [spec] bblock 3, line 34,  t152,  0(SI32)
	c0    mov $r0.59 = $r0.3   ## t1
;;								## 14
	c0    ldw $r0.60 = 0xb4[$r0.1]  ## restore ## t149
;;								## 15
	c0    ldw $r0.61 = 0xb8[$r0.1]  ## restore ## t150
;;								## 16
	c0    ldw $r0.63 = 0xbc[$r0.1]  ## restore ## t151
;;								## 17
	c0    stw 0x90[$r0.1] = $r0.0   ## bblock 1, line 30, t134, 0(SI32)
	c0    brf $b0.0, L0?3   ## bblock 1, line 33,  t177(I1)
;;								## 18
;;								## 19
.trace 7
L1?3:
	c0    cmplt $b0.0 = $r0.57, 5   ## bblock 4, line 35,  t178(I1),  t152,  5(SI32)
	c0    cmpeq $b0.1 = $r0.57, $r0.0   ## [spec] bblock 25, line 77,  t186(I1),  t152,  0(SI32)
;;								## 0
	c0    mov $r0.4 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
	c0    mov $r0.3 = $r0.59   ## t1
;;								## 1
	c0    mov $r0.5 = $r0.58   ## t0
	c0    brf $b0.0, L2?3   ## bblock 4, line 35,  t178(I1)
;;								## 2
	c0    brf $b0.1, L3?3   ## bblock 25, line 77,  t186(I1)
;;								## 3
.call fscanf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fscanf   ## bblock 52, line 38,  raddr(fscanf)(P32),  t1,  addr(_?1STRINGVAR.2)(P32),  t0
;;								## 4
	c0    ldw $r0.2 = ((verbose + 0) + 0)[$r0.0]   ## bblock 53, line 39, t13, 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.3 + 0)   ## addr(_?1STRINGVAR.3)(P32)
;;								## 5
	c0    mov $r0.4 = $r0.58   ## t0
	      xnop 1
;;								## 7
	c0    cmpne $b0.0 = $r0.2, $r0.0   ## bblock 53, line 39,  t198(I1),  t13,  0(SI32)
	      xnop 1
;;								## 9
	c0    brf $b0.0, L4?3   ## bblock 53, line 39,  t198(I1)
;;								## 10
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 58, line 40,  raddr(printf)(P32),  addr(_?1STRINGVAR.3)(P32),  t0
;;								## 11
L4?3:
	c0    mov $r0.3 = (_?1STRINGPACKET.4 + 0)   ## addr(_?1STRINGVAR.4)(P32)
	c0    mov $r0.4 = $r0.58   ## t0
;;								## 12
.call strcmp, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = strcmp   ## bblock 54, line 41,  raddr(strcmp)(P32),  addr(_?1STRINGVAR.4)(P32),  t0
;;								## 13
	c0    cmpeq $b0.0 = $r0.3, $r0.0   ## bblock 55, line 41,  t199(I1),  t18,  0(SI32)
	c0    mov $r0.4 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
;;								## 14
	c0    mov $r0.5 = $r0.58   ## t0
;;								## 15
	c0    mov $r0.3 = $r0.59   ## t1
	c0    brf $b0.0, L5?3   ## bblock 55, line 41,  t199(I1)
;;								## 16
.call fscanf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    mov $r0.57 = 1   ## bblock 57, line 42,  t152,  1(SI32)
	c0    call $l0.0 = fscanf   ## bblock 57, line 43,  raddr(fscanf)(P32),  t1,  addr(_?1STRINGVAR.5)(P32),  t0
;;								## 17
	c0    goto L1?3 ## goto
;;								## 18
.trace 12
L5?3:
.call exit, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = exit   ## bblock 56, line 46,  raddr(exit)(P32),  -1(SI32)
	c0    mov $r0.3 = -1   ## -1(SI32)
	      ## goto
;;
	c0    goto L1?3 ## goto
;;								## 0
.trace 10
L3?3:
	c0    cmpeq $b0.0 = $r0.57, 1   ## bblock 26, line 77,  t187(I1),  t152,  1(SI32)
	c0    ldb.d $r0.6 = 0[$r0.58]   ## [spec] bblock 42, line 49, t27(SI8), t0
;;								## 0
	c0    mov $r0.4 = (_?1STRINGPACKET.6 + 0)   ## addr(_?1STRINGVAR.6)(P32)
	c0    mov $r0.3 = $r0.59   ## t1
;;								## 1
	c0    mov $r0.5 = $r0.58   ## t0
	c0    brf $b0.0, L6?3   ## bblock 26, line 77,  t187(I1)
;;								## 2
	c0    cmpeq $b0.0 = $r0.6, 35   ## bblock 42, line 49,  t194(I1),  t27(SI8),  35(SI32)
	      xnop 1
;;								## 4
	c0    brf $b0.0, L7?3   ## bblock 42, line 49,  t194(I1)
;;								## 5
.call fscanf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fscanf   ## bblock 44, line 50,  raddr(fscanf)(P32),  t1,  addr(_?1STRINGVAR.6)(P32),  t0
;;								## 6
	c0    ldw $r0.5 = ((verbose + 0) + 0)[$r0.0]   ## bblock 45, line 51, t33, 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.7 + 0)   ## addr(_?1STRINGVAR.7)(P32)
;;								## 7
	c0    mov $r0.4 = $r0.58   ## t0
	      xnop 1
;;								## 9
	c0    cmpne $b0.0 = $r0.5, $r0.0   ## bblock 45, line 51,  t195(I1),  t33,  0(SI32)
	      xnop 1
;;								## 11
	c0    brf $b0.0, L8?3   ## bblock 45, line 51,  t195(I1)
;;								## 12
.call printf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 51, line 52,  raddr(printf)(P32),  addr(_?1STRINGVAR.7)(P32),  t0
;;								## 13
L8?3:
;;								## 14
.trace 4
L9?3:
	c0    ldw $r0.2 = 4[$r0.59]   ## bblock 46, line 53, t40, t1
	c0    mov $r0.3 = $r0.59   ## t1
	      xnop 2
;;								## 2
	c0    add $r0.2 = $r0.2, -1   ## bblock 46, line 53,  t41,  t40,  -1(SI32)
;;								## 3
	c0    stw 4[$r0.59] = $r0.2   ## bblock 46, line 53, t1, t41
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 46, line 53,  t196(I1),  t41,  0(SI32)
	      xnop 1
;;								## 5
	c0    brf $b0.0, L10?3   ## bblock 46, line 53,  t196(I1)
;;								## 6
.call __srget, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = __srget   ## bblock 49, line 53,  raddr(__srget)(P32),  t1
;;								## 7
	   ## bblock 50, line 53,  t38,  t42## $r0.3(skipped)
;;								## 8
L11?3:
	c0    cmpne $b0.0 = $r0.3, 10   ## bblock 48, line 53,  t197(I1),  t38,  10(SI32)
	      xnop 1
;;								## 10
	c0    brf $b0.0, L7?3   ## bblock 48, line 53,  t197(I1)
	      ## goto
;;
	c0    goto L9?3 ## goto
;;								## 11
.trace 11
L7?3:
	c0    mov $r0.57 = 2   ## bblock 43, line 56,  t152,  2(SI32)
	c0    goto L1?3 ## goto
;;								## 0
.trace 6
L10?3:
	c0    ldw $r0.2 = 0[$r0.59]   ## bblock 47, line 53, t45, t1
	      xnop 2
;;								## 2
	c0    add $r0.4 = $r0.2, 1   ## bblock 47, line 53,  t46,  t45,  1(SI32)
;;								## 3
	c0    stw 0[$r0.59] = $r0.4   ## bblock 47, line 53, t1, t46
;;								## 4
	c0    ldbu $r0.3 = 0[$r0.2]   ## bblock 47, line 53, t38, t45
	      xnop 1
;;								## 6
	c0    goto L11?3 ## goto
;;								## 7
.trace 14
L6?3:
	c0    cmpeq $b0.0 = $r0.57, 2   ## bblock 27, line 77,  t188(I1),  t152,  2(SI32)
	c0    mov $r0.4 = (_?1STRINGPACKET.8 + 0)   ## addr(_?1STRINGVAR.8)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.58   ## t0
	c0    mov $r0.5 = $r0.60   ## t149
;;								## 1
	c0    brf $b0.0, L12?3   ## bblock 27, line 77,  t188(I1)
;;								## 2
.call sscanf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = sscanf   ## bblock 38, line 59,  raddr(sscanf)(P32),  t0,  addr(_?1STRINGVAR.8)(P32),  t149
;;								## 3
	c0    ldw $r0.5 = ((verbose + 0) + 0)[$r0.0]   ## bblock 39, line 60, t53, 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.9 + 0)   ## addr(_?1STRINGVAR.9)(P32)
;;								## 4
	c0    ldw.d $r0.4 = 0[$r0.60]   ## [spec] bblock 41, line 61, t58, t149
	      xnop 1
;;								## 6
	c0    cmpne $b0.0 = $r0.5, $r0.0   ## bblock 39, line 60,  t193(I1),  t53,  0(SI32)
	      xnop 1
;;								## 8
	c0    brf $b0.0, L13?3   ## bblock 39, line 60,  t193(I1)
;;								## 9
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 41, line 61,  raddr(printf)(P32),  addr(_?1STRINGVAR.9)(P32),  t58
;;								## 10
L13?3:
	c0    mov $r0.57 = 3   ## bblock 40, line 62,  t152,  3(SI32)
	c0    goto L1?3 ## goto
;;								## 11
.trace 16
L12?3:
	c0    cmpeq $b0.0 = $r0.57, 3   ## bblock 28, line 77,  t189(I1),  t152,  3(SI32)
	c0    mov $r0.4 = (_?1STRINGPACKET.10 + 0)   ## addr(_?1STRINGVAR.10)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.59   ## t1
	c0    mov $r0.5 = $r0.61   ## t150
;;								## 1
	c0    brf $b0.0, L14?3   ## bblock 28, line 77,  t189(I1)
;;								## 2
.call fscanf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fscanf   ## bblock 34, line 65,  raddr(fscanf)(P32),  t1,  addr(_?1STRINGVAR.10)(P32),  t150
;;								## 3
	c0    ldw $r0.5 = ((verbose + 0) + 0)[$r0.0]   ## bblock 35, line 66, t64, 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.11 + 0)   ## addr(_?1STRINGVAR.11)(P32)
;;								## 4
	c0    ldw.d $r0.4 = 0[$r0.61]   ## [spec] bblock 37, line 67, t69, t150
	      xnop 1
;;								## 6
	c0    cmpne $b0.0 = $r0.5, $r0.0   ## bblock 35, line 66,  t192(I1),  t64,  0(SI32)
	      xnop 1
;;								## 8
	c0    brf $b0.0, L15?3   ## bblock 35, line 66,  t192(I1)
;;								## 9
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 37, line 67,  raddr(printf)(P32),  addr(_?1STRINGVAR.11)(P32),  t69
;;								## 10
L15?3:
	c0    mov $r0.57 = 4   ## bblock 36, line 68,  t152,  4(SI32)
	c0    goto L1?3 ## goto
;;								## 11
.trace 20
L14?3:
	c0    cmpeq $b0.0 = $r0.57, 4   ## bblock 29, line 77,  t190(I1),  t152,  4(SI32)
	c0    mov $r0.4 = (_?1STRINGPACKET.12 + 0)   ## addr(_?1STRINGVAR.12)(P32)
;;								## 0
	c0    mov $r0.3 = $r0.59   ## t1
	c0    mov $r0.5 = $r0.62   ## t74
;;								## 1
	c0    brf $b0.0, L1?3   ## bblock 29, line 77,  t190(I1)
;;								## 2
.call fscanf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fscanf   ## bblock 30, line 72,  raddr(fscanf)(P32),  t1,  addr(_?1STRINGVAR.12)(P32),  t74
;;								## 3
	c0    ldw $r0.5 = ((verbose + 0) + 0)[$r0.0]   ## bblock 31, line 73, t75, 0(I32)
	c0    mov $r0.3 = (_?1STRINGPACKET.13 + 0)   ## addr(_?1STRINGVAR.13)(P32)
;;								## 4
	c0    ldw.d $r0.4 = 0x90[$r0.1]   ## [spec] bblock 33, line 74, t79, t134
	      xnop 1
;;								## 6
	c0    cmpne $b0.0 = $r0.5, $r0.0   ## bblock 31, line 73,  t191(I1),  t75,  0(SI32)
	      xnop 1
;;								## 8
	c0    brf $b0.0, L16?3   ## bblock 31, line 73,  t191(I1)
;;								## 9
.call printf, caller, arg($r0.3:u32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 33, line 74,  raddr(printf)(P32),  addr(_?1STRINGVAR.13)(P32),  t79
;;								## 10
L16?3:
	c0    mov $r0.57 = 5   ## bblock 32, line 75,  t152,  5(SI32)
	c0    goto L1?3 ## goto
;;								## 11
.trace 25
L2?3:
	c0    ldw $r0.3 = 0[$r0.61]   ## bblock 5, line 79, t81, t150
	c0    mov $r0.5 = $r0.63   ## [spec] bblock 13, line 0,  t173,  t151
;;								## 0
	c0    ldw.d $r0.7 = 0[$r0.61]   ## [spec] bblock 7, line 80, t87, t150
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 13, line 84,  t154,  0(SI32)
;;								## 1
	c0    ldw.d $r0.8 = 0[$r0.60]   ## [spec] bblock 9, line 81, t93, t149
	c0    mov $r0.2 = $r0.61   ## t150
;;								## 2
	c0    cmpgt $b0.0 = $r0.3, $r0.0   ## bblock 5, line 79,  t179(I1),  t81,  0(SI32)
	c0    ldw.d $r0.9 = 0[$r0.60]   ## [spec] bblock 11, line 82, t99, t149
;;								## 3
	c0    cmple $b0.1 = $r0.7, 1050   ## [spec] bblock 7, line 80,  t180(I1),  t87,  1050(SI32)
	c0    mov $r0.57 = $r0.60   ## t149
;;								## 4
	c0    cmpgt $b0.0 = $r0.8, $r0.0   ## [spec] bblock 9, line 81,  t181(I1),  t93,  0(SI32)
	c0    brf $b0.0, L17?3   ## bblock 5, line 79,  t179(I1)
;;								## 5
L18?3:
	c0    cmple $b0.1 = $r0.9, 1500   ## [spec] bblock 11, line 82,  t182(I1),  t99,  1500(SI32)
	c0    brf $b0.1, L19?3   ## bblock 7, line 80,  t180(I1)
;;								## 6
L20?3:
	c0    brf $b0.0, L21?3   ## bblock 9, line 81,  t181(I1)
;;								## 7
L22?3:
	c0    brf $b0.1, L23?3   ## bblock 11, line 82,  t182(I1)
;;								## 8
.trace 8
L24?3:
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 14, line 84, t106, t150
	c0    mov $r0.60 = $r0.5   ## [spec] bblock 17, line 0,  t158,  t173
;;								## 0
	c0    mov $r0.58 = $r0.0   ## [spec] bblock 17, line 85,  t153,  0(SI32)
	c0    mov $r0.61 = $r0.2   ## t150
;;								## 1
	c0    mov $r0.62 = $r0.4   ## t154
	c0    mov $r0.63 = $r0.5   ## t173
;;								## 2
	c0    cmplt $b0.0 = $r0.4, $r0.3   ## bblock 14, line 84,  t183(I1),  t154,  t106
	      xnop 1
;;								## 4
	c0    brf $b0.0, L25?3   ## bblock 14, line 84,  t183(I1)
;;								## 5
.trace 1
L26?3:
	c0    ldw $r0.2 = 0[$r0.57]   ## bblock 18, line 85, t111, t149
	c0    mov $r0.3 = $r0.59   ## t1
;;								## 0
	c0    ldw.d $r0.4 = 4[$r0.59]   ## [spec] bblock 20, line 86, t116, t1
	      xnop 1
;;								## 2
	c0    cmplt $b0.0 = $r0.58, $r0.2   ## bblock 18, line 85,  t184(I1),  t153,  t111
;;								## 3
	c0    add $r0.4 = $r0.4, -1   ## [spec] bblock 20, line 86,  t117,  t116,  -1(SI32)
;;								## 4
	c0    cmplt $b0.0 = $r0.4, $r0.0   ## [spec] bblock 20, line 86,  t185(I1),  t117,  0(SI32)
	c0    brf $b0.0, L27?3   ## bblock 18, line 85,  t184(I1)
;;								## 5
	c0    stw 4[$r0.59] = $r0.4   ## bblock 20, line 86, t1, t117
;;								## 6
	c0    brf $b0.0, L28?3   ## bblock 20, line 86,  t185(I1)
;;								## 7
.call __srget, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = __srget   ## bblock 23, line 86,  raddr(__srget)(P32),  t1
;;								## 8
	   ## bblock 24, line 86,  t114,  t118## $r0.3(skipped)
	c0    add $r0.58 = $r0.58, 1   ## bblock 22, line 85,  t153,  t153,  1(SI32)
;;								## 9
L29?3:
	c0    stb 0[$r0.60] = $r0.3   ## bblock 22, line 86, t158, t114
;;								## 10
	c0    add $r0.60 = $r0.60, 1050   ## bblock 22, line 0,  t158,  t158,  1050(I32)
	c0    goto L26?3 ## goto
;;								## 11
.trace 3
L28?3:
	c0    ldw $r0.2 = 0[$r0.59]   ## bblock 21, line 86, t121, t1
	c0    add $r0.58 = $r0.58, 1   ## bblock 22, line 85,  t153,  t153,  1(SI32)
	      xnop 2
;;								## 2
	c0    add $r0.4 = $r0.2, 1   ## bblock 21, line 86,  t122,  t121,  1(SI32)
;;								## 3
	c0    stw 0[$r0.59] = $r0.4   ## bblock 21, line 86, t1, t122
;;								## 4
	c0    ldbu $r0.3 = 0[$r0.2]   ## bblock 21, line 86, t114, t121
	      xnop 1
;;								## 6
	c0    goto L29?3 ## goto
;;								## 7
.trace 9
L27?3:
	c0    add $r0.5 = $r0.63, 1   ## bblock 19, line 0,  t173,  t173,  1(I32)
	c0    add $r0.4 = $r0.62, 1   ## bblock 19, line 84,  t154,  t154,  1(SI32)
;;								## 0
	c0    mov $r0.2 = $r0.61   ## t150
	c0    goto L24?3 ## goto
;;								## 1
.trace 27
L25?3:
.call fclose, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = fclose   ## bblock 15, line 89,  raddr(fclose)(P32),  t1
	c0    mov $r0.3 = $r0.59   ## t1
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x94[$r0.1]  ## restore ## t133
;;								## 1
	c0    ldw $r0.63 = 0x98[$r0.1]  ## restore ## t143
;;								## 2
	c0    ldw $r0.62 = 0x9c[$r0.1]  ## restore ## t142
;;								## 3
	c0    ldw $r0.61 = 0xa0[$r0.1]  ## restore ## t141
;;								## 4
	c0    ldw $r0.60 = 0xa4[$r0.1]  ## restore ## t140
;;								## 5
	c0    ldw $r0.59 = 0xa8[$r0.1]  ## restore ## t139
;;								## 6
	c0    ldw $r0.58 = 0xac[$r0.1]  ## restore ## t138
;;								## 7
	c0    ldw $r0.57 = 0xb0[$r0.1]  ## restore ## t137
	      xnop 1
;;								## 9
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0xc0), $l0.0   ## bblock 16, line 93,  t134,  ?2.1?2auto_size(I32),  t133
;;								## 10
.trace 31
L23?3:
	c0    stw 0xb8[$r0.1] = $r0.2  ## spill ## t150
	c0    mov $r0.5 = (_?1STRINGPACKET.21 + 0)   ## addr(_?1STRINGVAR.21)(P32)
;;								## 0
	c0    mov $r0.4 = 82   ## 82(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.20 + 0)   ## addr(_?1STRINGVAR.20)(P32)
;;								## 1
.call __assert, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32), ret()
	c0    call $l0.0 = __assert   ## bblock 12, line 82,  raddr(__assert)(P32),  addr(_?1STRINGVAR.20)(P32),  82(SI32),  addr(_?1STRINGVAR.21)(P32)
;;								## 2
	c0    mov $r0.5 = $r0.63   ## bblock 13, line 0,  t173,  t151
	c0    mov $r0.4 = $r0.0   ## bblock 13, line 84,  t154,  0(SI32)
;;								## 3
	c0    ldw $r0.2 = 0xb8[$r0.1]  ## restore ## t150
	      xnop 1
;;								## 5
	c0    goto L24?3 ## goto
;;								## 6
.trace 29
L21?3:
	c0    stw 0xb8[$r0.1] = $r0.2  ## spill ## t150
	c0    mov $r0.5 = (_?1STRINGPACKET.19 + 0)   ## addr(_?1STRINGVAR.19)(P32)
;;								## 0
	c0    mov $r0.4 = 81   ## 81(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.18 + 0)   ## addr(_?1STRINGVAR.18)(P32)
;;								## 1
.call __assert, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32), ret()
	c0    call $l0.0 = __assert   ## bblock 10, line 81,  raddr(__assert)(P32),  addr(_?1STRINGVAR.18)(P32),  81(SI32),  addr(_?1STRINGVAR.19)(P32)
;;								## 2
	c0    ldw $r0.9 = 0[$r0.57]   ## bblock 11, line 82, t99, t149
	c0    mov $r0.5 = $r0.63   ## [spec] bblock 13, line 0,  t173,  t151
;;								## 3
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 13, line 84,  t154,  0(SI32)
	c0    ldw $r0.2 = 0xb8[$r0.1]  ## restore ## t150
	      xnop 1
;;								## 5
	c0    cmple $b0.1 = $r0.9, 1500   ## bblock 11, line 82,  t182(I1),  t99,  1500(SI32)
;;								## 6
	c0    goto L22?3 ## goto
;;								## 7
.trace 28
L19?3:
	c0    stw 0xb8[$r0.1] = $r0.2  ## spill ## t150
	c0    mov $r0.5 = (_?1STRINGPACKET.17 + 0)   ## addr(_?1STRINGVAR.17)(P32)
;;								## 0
	c0    mov $r0.4 = 80   ## 80(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.16 + 0)   ## addr(_?1STRINGVAR.16)(P32)
;;								## 1
.call __assert, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32), ret()
	c0    call $l0.0 = __assert   ## bblock 8, line 80,  raddr(__assert)(P32),  addr(_?1STRINGVAR.16)(P32),  80(SI32),  addr(_?1STRINGVAR.17)(P32)
;;								## 2
	c0    ldw $r0.8 = 0[$r0.57]   ## bblock 9, line 81, t93, t149
	c0    mov $r0.5 = $r0.63   ## [spec] bblock 13, line 0,  t173,  t151
;;								## 3
	c0    ldw.d $r0.9 = 0[$r0.57]   ## [spec] bblock 11, line 82, t99, t149
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 13, line 84,  t154,  0(SI32)
;;								## 4
	c0    ldw $r0.2 = 0xb8[$r0.1]  ## restore ## t150
;;								## 5
	c0    cmpgt $b0.0 = $r0.8, $r0.0   ## bblock 9, line 81,  t181(I1),  t93,  0(SI32)
;;								## 6
	c0    cmple $b0.1 = $r0.9, 1500   ## [spec] bblock 11, line 82,  t182(I1),  t99,  1500(SI32)
	c0    goto L20?3 ## goto
;;								## 7
.trace 30
L17?3:
	c0    stw 0xb8[$r0.1] = $r0.2  ## spill ## t150
	c0    mov $r0.5 = (_?1STRINGPACKET.15 + 0)   ## addr(_?1STRINGVAR.15)(P32)
;;								## 0
	c0    mov $r0.4 = 79   ## 79(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.14 + 0)   ## addr(_?1STRINGVAR.14)(P32)
;;								## 1
.call __assert, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32), ret()
	c0    call $l0.0 = __assert   ## bblock 6, line 79,  raddr(__assert)(P32),  addr(_?1STRINGVAR.14)(P32),  79(SI32),  addr(_?1STRINGVAR.15)(P32)
;;								## 2
	c0    mov $r0.5 = $r0.63   ## [spec] bblock 13, line 0,  t173,  t151
	c0    ldw $r0.2 = 0xb8[$r0.1]  ## restore ## t150
;;								## 3
	c0    ldw.d $r0.8 = 0[$r0.57]   ## [spec] bblock 9, line 81, t93, t149
	c0    mov $r0.4 = $r0.0   ## [spec] bblock 13, line 84,  t154,  0(SI32)
;;								## 4
	c0    ldw.d $r0.9 = 0[$r0.57]   ## [spec] bblock 11, line 82, t99, t149
;;								## 5
	c0    ldw $r0.7 = 0[$r0.2]   ## bblock 7, line 80, t87, t150
	      xnop 2
;;								## 8
	c0    cmple $b0.1 = $r0.7, 1050   ## bblock 7, line 80,  t180(I1),  t87,  1050(SI32)
;;								## 9
	c0    cmpgt $b0.0 = $r0.8, $r0.0   ## [spec] bblock 9, line 81,  t181(I1),  t93,  0(SI32)
	c0    goto L18?3 ## goto
;;								## 10
.trace 26
L0?3:
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    ldw $l0.0 = 0x94[$r0.1]  ## restore ## t133
;;								## 0
	c0    ldw $r0.63 = 0x98[$r0.1]  ## restore ## t143
;;								## 1
	c0    ldw $r0.62 = 0x9c[$r0.1]  ## restore ## t142
;;								## 2
	c0    ldw $r0.61 = 0xa0[$r0.1]  ## restore ## t141
;;								## 3
	c0    ldw $r0.60 = 0xa4[$r0.1]  ## restore ## t140
;;								## 4
	c0    ldw $r0.59 = 0xa8[$r0.1]  ## restore ## t139
;;								## 5
	c0    ldw $r0.58 = 0xac[$r0.1]  ## restore ## t138
;;								## 6
	c0    ldw $r0.57 = 0xb0[$r0.1]  ## restore ## t137
	      xnop 1
;;								## 8
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0xc0), $l0.0   ## bblock 2, line 91,  t134,  ?2.1?2auto_size(I32),  t133
;;								## 9
.endp
.section .bss
.section .data
_?1STRINGPACKET.7:
    .data1 99
    .data1 111
    .data1 109
    .data1 109
    .data1 101
    .data1 110
    .data1 116
    .data1 32
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 10
    .data1 0
.skip 2
_?1STRINGPACKET.14:
    .data1 46
    .data1 46
    .data1 47
    .data1 115
    .data1 114
    .data1 99
    .data1 47
    .data1 47
    .data1 112
    .data1 103
    .data1 109
    .data1 46
    .data1 99
    .data1 0
.skip 2
_?1STRINGPACKET.16:
    .data1 46
    .data1 46
    .data1 47
    .data1 115
    .data1 114
    .data1 99
    .data1 47
    .data1 47
    .data1 112
    .data1 103
    .data1 109
    .data1 46
    .data1 99
    .data1 0
.skip 2
_?1STRINGPACKET.17:
    .data1 42
    .data1 104
    .data1 101
    .data1 105
    .data1 103
    .data1 104
    .data1 116
    .data1 32
    .data1 60
    .data1 61
    .data1 32
    .data1 77
    .data1 65
    .data1 88
    .data1 95
    .data1 72
    .data1 69
    .data1 73
    .data1 71
    .data1 72
    .data1 84
    .data1 0
.skip 2
_?1STRINGPACKET.18:
    .data1 46
    .data1 46
    .data1 47
    .data1 115
    .data1 114
    .data1 99
    .data1 47
    .data1 47
    .data1 112
    .data1 103
    .data1 109
    .data1 46
    .data1 99
    .data1 0
.skip 2
_?1STRINGPACKET.20:
    .data1 46
    .data1 46
    .data1 47
    .data1 115
    .data1 114
    .data1 99
    .data1 47
    .data1 47
    .data1 112
    .data1 103
    .data1 109
    .data1 46
    .data1 99
    .data1 0
.skip 2
_?1STRINGPACKET.1:
    .data1 114
    .data1 0
.skip 2
_?1STRINGPACKET.2:
    .data1 37
    .data1 115
    .data1 0
.skip 1
_?1STRINGPACKET.3:
    .data1 104
    .data1 101
    .data1 97
    .data1 100
    .data1 101
    .data1 114
    .data1 32
    .data1 37
    .data1 115
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.4:
    .data1 80
    .data1 53
    .data1 0
.skip 1
_?1STRINGPACKET.5:
    .data1 37
    .data1 115
    .data1 0
.skip 1
_?1STRINGPACKET.6:
    .data1 37
    .data1 115
    .data1 0
.skip 1
_?1STRINGPACKET.8:
    .data1 37
    .data1 117
    .data1 0
.skip 1
_?1STRINGPACKET.9:
    .data1 119
    .data1 105
    .data1 100
    .data1 116
    .data1 104
    .data1 61
    .data1 32
    .data1 37
    .data1 117
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.10:
    .data1 37
    .data1 117
    .data1 0
.skip 1
_?1STRINGPACKET.11:
    .data1 104
    .data1 101
    .data1 105
    .data1 103
    .data1 104
    .data1 116
    .data1 61
    .data1 32
    .data1 37
    .data1 117
    .data1 10
    .data1 0
_?1STRINGPACKET.12:
    .data1 37
    .data1 117
    .data1 0
.skip 1
_?1STRINGPACKET.13:
    .data1 100
    .data1 101
    .data1 112
    .data1 116
    .data1 104
    .data1 61
    .data1 32
    .data1 37
    .data1 117
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.15:
    .data1 42
    .data1 104
    .data1 101
    .data1 105
    .data1 103
    .data1 104
    .data1 116
    .data1 32
    .data1 62
    .data1 32
    .data1 48
    .data1 0
_?1STRINGPACKET.19:
    .data1 42
    .data1 119
    .data1 105
    .data1 100
    .data1 116
    .data1 104
    .data1 32
    .data1 62
    .data1 32
    .data1 48
    .data1 0
.skip 1
_?1STRINGPACKET.21:
    .data1 42
    .data1 119
    .data1 105
    .data1 100
    .data1 116
    .data1 104
    .data1 32
    .data1 60
    .data1 61
    .data1 32
    .data1 77
    .data1 65
    .data1 88
    .data1 95
    .data1 87
    .data1 73
    .data1 68
    .data1 84
    .data1 72
    .data1 0
.equ ?2.1?2scratch.0, 0x0
.equ _?1PACKET.5, 0x10
.equ _?1PACKET.2, 0x90
.equ ?2.1?2ras_p, 0x94
.equ ?2.1?2spill_p, 0x98
.equ _?1TEMPLATEPACKET.21, 0x0
.section .data
.section .text
.equ ?2.1?2auto_size, 0xc0
 ## End load_pgm
.equ _?1TEMPLATEPACKET.18, 0x0
 ## Begin save_pgm
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-96, arg($r0.3:u32,$r0.4:s32,$r0.5:s32,$r0.6:u32)
save_pgm::
.trace 9
	c0    add $r0.1 = $r0.1, (-0x60)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t116
;;								## 1
	c0    stw 0x34[$r0.1] = $r0.6  ## spill ## t134
;;								## 2
	c0    stw 0x18[$r0.1] = $r0.63  ## spill ## t126
;;								## 3
	c0    stw 0x1c[$r0.1] = $r0.62  ## spill ## t125
;;								## 4
	c0    stw 0x20[$r0.1] = $r0.61  ## spill ## t124
;;								## 5
	c0    stw 0x24[$r0.1] = $r0.60  ## spill ## t123
;;								## 6
	c0    stw 0x28[$r0.1] = $r0.59  ## spill ## t122
;;								## 7
	c0    stw 0x2c[$r0.1] = $r0.58  ## spill ## t121
;;								## 8
	c0    stw 0x30[$r0.1] = $r0.57  ## spill ## t120
;;								## 9
	c0    stw 0x38[$r0.1] = $r0.5  ## spill ## t133
;;								## 10
	c0    stw 0x3c[$r0.1] = $r0.4  ## spill ## t132
;;								## 11
	c0    mov $r0.4 = (_?1STRINGPACKET.22 + 0)   ## addr(_?1STRINGVAR.22)(P32)
	c0    stw 0x40[$r0.1] = $r0.3  ## spill ## t131
;;								## 12
.call fopen, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = fopen   ## bblock 0, line 98,  raddr(fopen)(P32),  t131,  addr(_?1STRINGVAR.22)(P32)
;;								## 13
	c0    stw 0x44[$r0.1] = $r0.3  ## spill ## t0
;;								## 14
	c0    mov $r0.3 = (_?1STRINGPACKET.23 + 0)   ## addr(_?1STRINGVAR.23)(P32)
	c0    ldw $r0.6 = 0x38[$r0.1]  ## restore ## t133
;;								## 15
	c0    ldw $r0.5 = 0x3c[$r0.1]  ## restore ## t132
;;								## 16
	c0    ldw $r0.4 = 0x40[$r0.1]  ## restore ## t131
	      xnop 1
;;								## 18
.call printf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:s32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = printf   ## bblock 1, line 99,  raddr(printf)(P32),  addr(_?1STRINGVAR.23)(P32),  t131,  t132,  t133
;;								## 19
	c0    ldw $r0.4 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 2, line 100, t11, 0(I32)
	      xnop 2
;;								## 22
	c0    ldw $r0.3 = 8[$r0.4]   ## bblock 2, line 100, t12, t11
	      xnop 1
;;								## 24
.call fflush, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = fflush   ## bblock 2, line 100,  raddr(fflush)(P32),  t12
;;								## 25
	c0    mov $r0.4 = (_?1STRINGPACKET.24 + 0)   ## addr(_?1STRINGVAR.24)(P32)
	c0    ldw $r0.3 = 0x44[$r0.1]  ## restore ## t0
;;								## 26
	c0    ldw $r0.6 = 0x38[$r0.1]  ## restore ## t133
;;								## 27
	c0    ldw $r0.5 = 0x3c[$r0.1]  ## restore ## t132
;;								## 28
	c0    cmpne $b0.0 = $r0.3, $r0.0   ## bblock 3, line 101,  t170(I1),  t0,  0x0(P32)
	      xnop 1
;;								## 30
	c0    brf $b0.0, L30?3   ## bblock 3, line 101,  t170(I1)
;;								## 31
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:s32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 6, line 102,  raddr(fprintf)(P32),  t0,  addr(_?1STRINGVAR.24)(P32),  t132,  t133
;;								## 32
	c0    mov $r0.60 = $r0.0   ## [spec] bblock 15, line 107,  t137,  0(SI32)
	c0    ldw $r0.4 = 0x38[$r0.1]  ## restore ## t133
;;								## 33
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t132
;;								## 34
	c0    ldw $r0.6 = 0x34[$r0.1]  ## restore ## t134
;;								## 35
	c0    cmpgt $b0.0 = $r0.4, $r0.0   ## bblock 7, line 103,  t171(I1),  t133,  0(SI32)
	c0    cmple $b0.1 = $r0.4, 1050   ## [spec] bblock 9, line 104,  t172(I1),  t133,  1050(SI32)
;;								## 36
	c0    cmpgt $b0.2 = $r0.3, $r0.0   ## [spec] bblock 11, line 105,  t173(I1),  t132,  0(SI32)
	c0    cmple $b0.3 = $r0.3, 1500   ## [spec] bblock 13, line 106,  t174(I1),  t132,  1500(SI32)
;;								## 37
	c0    sub $r0.4 = $r0.0, $r0.4   ## [spec] bblock 15, line 0,  t163,  0(I32),  t133
	c0    brf $b0.0, L31?3   ## bblock 7, line 103,  t171(I1)
;;								## 38
L32?3:
	c0    mov $r0.2 = $r0.4   ## [spec] bblock 15, line 0,  t162,  t163
	c0    brf $b0.1, L33?3   ## bblock 9, line 104,  t172(I1)
;;								## 39
L34?3:
	c0    mov $r0.5 = $r0.6   ## [spec] bblock 15, line 0,  t161,  t134
	c0    brf $b0.2, L35?3   ## bblock 11, line 105,  t173(I1)
;;								## 40
L36?3:
	c0    ldw $r0.57 = 0x44[$r0.1]  ## restore ## t0
	c0    brf $b0.3, L37?3   ## bblock 13, line 106,  t174(I1)
;;								## 41
L38?3:
;;								## 42
;;								## 43
.trace 7
L39?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 16, line 107,  t175(I1),  t162,  0(SI32)
	c0    sub $r0.4 = $r0.0, $r0.3   ## [spec] bblock 19, line 0,  t143,  0(I32),  t132
;;								## 0
	c0    mov $r0.58 = $r0.4   ## [spec] bblock 19, line 0,  t142,  t143
	c0    stw 0x14[$r0.1] = $r0.5  ## spill ## t161
;;								## 1
	c0    mov $r0.59 = $r0.5   ## [spec] bblock 19, line 0,  t141,  t161
	c0    brf $b0.0, L40?3   ## bblock 16, line 107,  t175(I1)
;;								## 2
	c0    mov $r0.61 = $r0.0   ## bblock 19, line 108,  t138,  0(SI32)
	c0    mov $r0.62 = $r0.2   ## t162
;;								## 3
	c0    mov $r0.63 = $r0.3   ## t132
;;								## 4
.trace 1
L41?3:
	c0    cmplt $b0.0 = $r0.58, $r0.0   ## bblock 20, line 108,  t176(I1),  t142,  0(SI32)
	c0    ldw.d $r0.2 = 8[$r0.57]   ## [spec] bblock 22, line 109, t50, t0
;;								## 0
	c0    ldw.d $r0.7 = 24[$r0.57]   ## [spec] bblock 29, line 109, t56, t0
	c0    mov $r0.4 = (_?1STRINGPACKET.33 + 0)   ## addr(_?1STRINGVAR.33)(P32)
;;								## 1
	c0    ldw.d $r0.8 = 0[$r0.57]   ## [spec] bblock 33, line 109, t65, t0
	c0    brf $b0.0, L42?3   ## bblock 20, line 108,  t176(I1)
;;								## 2
	c0    add $r0.2 = $r0.2, -1   ## bblock 22, line 110,  t51,  t50,  -1(SI32)
	c0    mov $r0.5 = $r0.60   ## t137
;;								## 3
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 22, line 109,  t177(I1),  t51,  0(SI32)
	c0    cmpge $b0.1 = $r0.2, $r0.7   ## [spec] bblock 29, line 109,  t179(I1),  t51,  t56
;;								## 4
	c0    stw 8[$r0.57] = $r0.2   ## bblock 22, line 109, t0, t51
	c0    mov $r0.6 = $r0.61   ## t138
;;								## 5
	c0    ldbu.d $r0.2 = 0[$r0.59]   ## [spec] bblock 33, line 109, t63(I8), t141
	c0    brf $b0.0, L43?3   ## bblock 22, line 109,  t177(I1)
;;								## 6
	c0    brf $b0.1, L44?3   ## bblock 29, line 109,  t179(I1)
;;								## 7
;;								## 8
	c0    stb 0[$r0.8] = $r0.2   ## bblock 33, line 109, t65, t63(I8)
;;								## 9
	c0    ldw $r0.2 = 0[$r0.57]   ## bblock 33, line 109, t68, t0
	      xnop 2
;;								## 12
	c0    ldbu $r0.7 = 0[$r0.2]   ## bblock 33, line 109, t69(I8), t68
	c0    add $r0.8 = $r0.2, 1   ## [spec] bblock 37, line 109,  t72,  t68,  1(SI32)
	      xnop 2
;;								## 15
	c0    cmpne $b0.0 = $r0.7, 10   ## bblock 33, line 109,  t180(I1),  t69(I8),  10(SI32)
	      xnop 1
;;								## 17
	c0    brf $b0.0, L45?3   ## bblock 33, line 109,  t180(I1)
;;								## 18
	c0    stw 0[$r0.57] = $r0.8   ## bblock 37, line 109, t0, t72
;;								## 19
	c0    ldbu $r0.2 = 0[$r0.2]   ## bblock 37, line 109, t66, t68
;;								## 20
	c0    ldw.d $r0.7 = ((_impure_ptr + 0) + 0)[$r0.0]   ## [spec] bblock 26, line 111, t100, 0(I32)
	      xnop 1
;;								## 22
L46?3:
	   ## bblock 36, line 109,  t52,  t66## $r0.2(skipped)
;;								## 23
L47?3:
	   ## bblock 32, line 109,  t48,  t52## $r0.2(skipped)
	c0    ldw.d $r0.3 = 12[$r0.7]   ## [spec] bblock 26, line 111, t101, t100
;;								## 24
L48?3:
	c0    cmplt $b0.0 = $r0.2, $r0.0   ## bblock 24, line 110,  t178(I1),  t48,  0(SI32)
	      xnop 1
;;								## 26
	c0    brf $b0.0, L49?3   ## bblock 24, line 110,  t178(I1)
;;								## 27
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:s32,$r0.6:s32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 26, line 111,  raddr(fprintf)(P32),  t101,  addr(_?1STRINGVAR.33)(P32),  t137,  t138
;;								## 28
.call fclose, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = fclose   ## bblock 27, line 112,  raddr(fclose)(P32),  t0
	c0    mov $r0.3 = $r0.57   ## t0
;;								## 29
.call exit, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = exit   ## bblock 28, line 113,  raddr(exit)(P32),  -1(SI32)
	c0    mov $r0.3 = -1   ## -1(SI32)
;;								## 30
L49?3:
	c0    add $r0.59 = $r0.59, 1050   ## bblock 25, line 0,  t141,  t141,  1050(I32)
	c0    add $r0.61 = $r0.61, 1   ## bblock 25, line 108,  t138,  t138,  1(SI32)
;;								## 31
	c0    add $r0.58 = $r0.58, 1   ## bblock 25, line 0,  t142,  t142,  1(I32)
	c0    goto L41?3 ## goto
;;								## 32
.trace 6
L45?3:
	c0    mov $r0.4 = $r0.57   ## t0
	c0    mov $r0.3 = 10   ## 10(SI32)
;;								## 0
.call __swbuf, caller, arg($r0.3:s32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = __swbuf   ## bblock 34, line 109,  raddr(__swbuf)(P32),  10(SI32),  t0
;;								## 1
	c0    mov $r0.2 = $r0.3   ## bblock 35, line 109,  t66,  t74
	c0    mov $r0.4 = (_?1STRINGPACKET.33 + 0)   ## addr(_?1STRINGVAR.33)(P32)
;;								## 2
	c0    mov $r0.5 = $r0.60   ## t137
	c0    mov $r0.6 = $r0.61   ## t138
;;								## 3
	c0    ldw.d $r0.7 = ((_impure_ptr + 0) + 0)[$r0.0]   ## [spec] bblock 26, line 111, t100, 0(I32)
;;								## 4
	c0    goto L46?3 ## goto
;;								## 5
.trace 5
L44?3:
	c0    ldbu $r0.3 = 0[$r0.59]   ## bblock 30, line 109, t83(I8), t141
	c0    mov $r0.4 = $r0.57   ## t0
	      xnop 1
;;								## 1
.call __swbuf, caller, arg($r0.3:s32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = __swbuf   ## bblock 30, line 109,  raddr(__swbuf)(P32),  t83(I8),  t0
;;								## 2
	c0    mov $r0.2 = $r0.3   ## bblock 31, line 109,  t52,  t76
	c0    ldw.d $r0.7 = ((_impure_ptr + 0) + 0)[$r0.0]   ## [spec] bblock 26, line 111, t100, 0(I32)
;;								## 3
	c0    mov $r0.4 = (_?1STRINGPACKET.33 + 0)   ## addr(_?1STRINGVAR.33)(P32)
	c0    mov $r0.5 = $r0.60   ## t137
;;								## 4
	c0    mov $r0.6 = $r0.61   ## t138
	c0    goto L47?3 ## goto
;;								## 5
.trace 3
L43?3:
	c0    ldbu $r0.3 = 0[$r0.59]   ## bblock 23, line 109, t91(I8), t141
	c0    mov $r0.4 = (_?1STRINGPACKET.33 + 0)   ## addr(_?1STRINGVAR.33)(P32)
;;								## 0
	c0    ldw $r0.8 = 0[$r0.57]   ## bblock 23, line 109, t93, t0
	c0    mov $r0.5 = $r0.60   ## t137
;;								## 1
	c0    mov $r0.6 = $r0.61   ## t138
	      xnop 1
;;								## 3
	c0    stb 0[$r0.8] = $r0.3   ## bblock 23, line 109, t93, t91(I8)
;;								## 4
	c0    ldw $r0.3 = 0[$r0.57]   ## bblock 23, line 109, t95, t0
	      xnop 2
;;								## 7
	c0    add $r0.8 = $r0.3, 1   ## bblock 23, line 109,  t96,  t95,  1(SI32)
;;								## 8
	c0    stw 0[$r0.57] = $r0.8   ## bblock 23, line 109, t0, t96
;;								## 9
	c0    ldbu $r0.2 = 0[$r0.3]   ## bblock 23, line 109, t48, t95
;;								## 10
	c0    ldw.d $r0.7 = ((_impure_ptr + 0) + 0)[$r0.0]   ## [spec] bblock 26, line 111, t100, 0(I32)
	      xnop 2
;;								## 13
	c0    ldw.d $r0.3 = 12[$r0.7]   ## [spec] bblock 26, line 111, t101, t100
	c0    goto L48?3 ## goto
;;								## 14
.trace 8
L42?3:
	c0    add $r0.60 = $r0.60, 1   ## bblock 21, line 107,  t137,  t137,  1(SI32)
	c0    ldw $r0.5 = 0x14[$r0.1]  ## restore ## t161
;;								## 0
	c0    add $r0.2 = $r0.62, 1   ## bblock 21, line 0,  t162,  t162,  1(I32)
	c0    mov $r0.3 = $r0.63   ## t132
	      xnop 1
;;								## 2
	c0    add $r0.5 = $r0.5, 1   ## bblock 21, line 0,  t161,  t161,  1(I32)
	c0    goto L39?3 ## goto
;;								## 3
.trace 11
L40?3:
.call fclose, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = fclose   ## bblock 17, line 117,  raddr(fclose)(P32),  t0
	c0    mov $r0.3 = $r0.57   ## t0
;;								## 0
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t116
;;								## 1
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t126
;;								## 2
	c0    ldw $r0.62 = 0x1c[$r0.1]  ## restore ## t125
;;								## 3
	c0    ldw $r0.61 = 0x20[$r0.1]  ## restore ## t124
;;								## 4
	c0    ldw $r0.60 = 0x24[$r0.1]  ## restore ## t123
;;								## 5
	c0    ldw $r0.59 = 0x28[$r0.1]  ## restore ## t122
;;								## 6
	c0    ldw $r0.58 = 0x2c[$r0.1]  ## restore ## t121
;;								## 7
	c0    ldw $r0.57 = 0x30[$r0.1]  ## restore ## t120
	      xnop 1
;;								## 9
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x60), $l0.0   ## bblock 18, line 118,  t117,  ?2.2?2auto_size(I32),  t116
;;								## 10
.trace 12
L37?3:
	c0    stw 0x3c[$r0.1] = $r0.3  ## spill ## t132
	c0    mov $r0.5 = (_?1STRINGPACKET.32 + 0)   ## addr(_?1STRINGVAR.32)(P32)
;;								## 0
	c0    mov $r0.4 = 106   ## 106(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.31 + 0)   ## addr(_?1STRINGVAR.31)(P32)
;;								## 1
.call __assert, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32), ret()
	c0    call $l0.0 = __assert   ## bblock 14, line 106,  raddr(__assert)(P32),  addr(_?1STRINGVAR.31)(P32),  106(SI32),  addr(_?1STRINGVAR.32)(P32)
	c0    stw 0x44[$r0.1] = $r0.57  ## spill ## t0
;;								## 2
	c0    mov $r0.60 = $r0.0   ## bblock 15, line 107,  t137,  0(SI32)
	c0    ldw $r0.4 = 0x38[$r0.1]  ## restore ## t133
;;								## 3
	c0    ldw $r0.6 = 0x34[$r0.1]  ## restore ## t134
;;								## 4
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t132
;;								## 5
	c0    sub $r0.4 = $r0.0, $r0.4   ## bblock 15, line 0,  t163,  0(I32),  t133
;;								## 6
	c0    mov $r0.2 = $r0.4   ## bblock 15, line 0,  t162,  t163
	c0    mov $r0.5 = $r0.6   ## bblock 15, line 0,  t161,  t134
;;								## 7
	c0    ldw $r0.57 = 0x44[$r0.1]  ## restore ## t0
	c0    goto L38?3 ## goto
;;								## 8
.trace 15
L35?3:
	c0    stw 0x3c[$r0.1] = $r0.3  ## spill ## t132
	c0    mov $r0.5 = (_?1STRINGPACKET.30 + 0)   ## addr(_?1STRINGVAR.30)(P32)
;;								## 0
	c0    mov $r0.4 = 105   ## 105(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.29 + 0)   ## addr(_?1STRINGVAR.29)(P32)
;;								## 1
.call __assert, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32), ret()
	c0    call $l0.0 = __assert   ## bblock 12, line 105,  raddr(__assert)(P32),  addr(_?1STRINGVAR.29)(P32),  105(SI32),  addr(_?1STRINGVAR.30)(P32)
;;								## 2
	c0    mov $r0.60 = $r0.0   ## [spec] bblock 15, line 107,  t137,  0(SI32)
	c0    ldw $r0.4 = 0x38[$r0.1]  ## restore ## t133
;;								## 3
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t132
;;								## 4
	c0    ldw $r0.6 = 0x34[$r0.1]  ## restore ## t134
;;								## 5
	c0    sub $r0.4 = $r0.0, $r0.4   ## [spec] bblock 15, line 0,  t163,  0(I32),  t133
;;								## 6
	c0    cmple $b0.3 = $r0.3, 1500   ## bblock 13, line 106,  t174(I1),  t132,  1500(SI32)
	c0    mov $r0.2 = $r0.4   ## [spec] bblock 15, line 0,  t162,  t163
;;								## 7
	c0    mov $r0.5 = $r0.6   ## [spec] bblock 15, line 0,  t161,  t134
	c0    goto L36?3 ## goto
;;								## 8
.trace 14
L33?3:
	c0    stw 0x3c[$r0.1] = $r0.3  ## spill ## t132
	c0    mov $r0.5 = (_?1STRINGPACKET.28 + 0)   ## addr(_?1STRINGVAR.28)(P32)
;;								## 0
	c0    mov $r0.4 = 104   ## 104(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.27 + 0)   ## addr(_?1STRINGVAR.27)(P32)
;;								## 1
.call __assert, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32), ret()
	c0    call $l0.0 = __assert   ## bblock 10, line 104,  raddr(__assert)(P32),  addr(_?1STRINGVAR.27)(P32),  104(SI32),  addr(_?1STRINGVAR.28)(P32)
;;								## 2
	c0    mov $r0.60 = $r0.0   ## [spec] bblock 15, line 107,  t137,  0(SI32)
	c0    ldw $r0.5 = 0x38[$r0.1]  ## restore ## t133
;;								## 3
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t132
;;								## 4
	c0    ldw $r0.6 = 0x34[$r0.1]  ## restore ## t134
;;								## 5
	c0    sub $r0.4 = $r0.0, $r0.5   ## [spec] bblock 15, line 0,  t163,  0(I32),  t133
;;								## 6
	c0    cmpgt $b0.2 = $r0.3, $r0.0   ## bblock 11, line 105,  t173(I1),  t132,  0(SI32)
	c0    mov $r0.2 = $r0.4   ## [spec] bblock 15, line 0,  t162,  t163
;;								## 7
	c0    cmple $b0.3 = $r0.3, 1500   ## [spec] bblock 13, line 106,  t174(I1),  t132,  1500(SI32)
;;								## 8
	c0    goto L34?3 ## goto
;;								## 9
.trace 13
L31?3:
	c0    stw 0x3c[$r0.1] = $r0.3  ## spill ## t132
	c0    mov $r0.5 = (_?1STRINGPACKET.26 + 0)   ## addr(_?1STRINGVAR.26)(P32)
;;								## 0
	c0    mov $r0.4 = 103   ## 103(SI32)
	c0    mov $r0.3 = (_?1STRINGPACKET.25 + 0)   ## addr(_?1STRINGVAR.25)(P32)
;;								## 1
.call __assert, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32), ret()
	c0    call $l0.0 = __assert   ## bblock 8, line 103,  raddr(__assert)(P32),  addr(_?1STRINGVAR.25)(P32),  103(SI32),  addr(_?1STRINGVAR.26)(P32)
;;								## 2
	c0    mov $r0.60 = $r0.0   ## [spec] bblock 15, line 107,  t137,  0(SI32)
	c0    ldw $r0.5 = 0x38[$r0.1]  ## restore ## t133
;;								## 3
	c0    ldw $r0.3 = 0x3c[$r0.1]  ## restore ## t132
;;								## 4
	c0    ldw $r0.6 = 0x34[$r0.1]  ## restore ## t134
;;								## 5
	c0    cmple $b0.1 = $r0.5, 1050   ## bblock 9, line 104,  t172(I1),  t133,  1050(SI32)
	c0    sub $r0.4 = $r0.0, $r0.5   ## [spec] bblock 15, line 0,  t163,  0(I32),  t133
;;								## 6
	c0    cmpgt $b0.2 = $r0.3, $r0.0   ## [spec] bblock 11, line 105,  t173(I1),  t132,  0(SI32)
	c0    cmple $b0.3 = $r0.3, 1500   ## [spec] bblock 13, line 106,  t174(I1),  t132,  1500(SI32)
;;								## 7
	c0    goto L32?3 ## goto
;;								## 8
.trace 10
L30?3:
	c0    ldw $r0.2 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 4, line 120, t111, 0(I32)
	c0    mov $r0.4 = (_?1STRINGPACKET.34 + 0)   ## addr(_?1STRINGVAR.34)(P32)
;;								## 0
	c0    ldw $r0.5 = 0x40[$r0.1]  ## restore ## t131
	      xnop 1
;;								## 2
	c0    ldw $r0.3 = 12[$r0.2]   ## bblock 4, line 120, t112, t111
	      xnop 1
;;								## 4
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 4, line 120,  raddr(fprintf)(P32),  t112,  addr(_?1STRINGVAR.34)(P32),  t131
;;								## 5
	c0    mov $r0.3 = -1   ## -1(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t116
;;								## 6
	c0    ldw $r0.63 = 0x18[$r0.1]  ## restore ## t126
;;								## 7
	c0    ldw $r0.62 = 0x1c[$r0.1]  ## restore ## t125
;;								## 8
	c0    ldw $r0.61 = 0x20[$r0.1]  ## restore ## t124
;;								## 9
	c0    ldw $r0.60 = 0x24[$r0.1]  ## restore ## t123
;;								## 10
	c0    ldw $r0.59 = 0x28[$r0.1]  ## restore ## t122
;;								## 11
	c0    ldw $r0.58 = 0x2c[$r0.1]  ## restore ## t121
;;								## 12
	c0    ldw $r0.57 = 0x30[$r0.1]  ## restore ## t120
	      xnop 1
;;								## 14
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x60), $l0.0   ## bblock 5, line 121,  t117,  ?2.2?2auto_size(I32),  t116
;;								## 15
.endp
.section .bss
.section .data
_?1STRINGPACKET.23:
    .data1 83
    .data1 97
    .data1 118
    .data1 105
    .data1 110
    .data1 103
    .data1 32
    .data1 105
    .data1 109
    .data1 97
    .data1 103
    .data1 101
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 40
    .data1 119
    .data1 61
    .data1 37
    .data1 117
    .data1 32
    .data1 120
    .data1 32
    .data1 104
    .data1 61
    .data1 37
    .data1 117
    .data1 41
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.24:
    .data1 80
    .data1 53
    .data1 10
    .data1 37
    .data1 117
    .data1 32
    .data1 37
    .data1 117
    .data1 10
    .data1 32
    .data1 50
    .data1 53
    .data1 53
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.25:
    .data1 46
    .data1 46
    .data1 47
    .data1 115
    .data1 114
    .data1 99
    .data1 47
    .data1 47
    .data1 112
    .data1 103
    .data1 109
    .data1 46
    .data1 99
    .data1 0
.skip 2
_?1STRINGPACKET.27:
    .data1 46
    .data1 46
    .data1 47
    .data1 115
    .data1 114
    .data1 99
    .data1 47
    .data1 47
    .data1 112
    .data1 103
    .data1 109
    .data1 46
    .data1 99
    .data1 0
.skip 2
_?1STRINGPACKET.28:
    .data1 104
    .data1 101
    .data1 105
    .data1 103
    .data1 104
    .data1 116
    .data1 32
    .data1 60
    .data1 61
    .data1 32
    .data1 77
    .data1 65
    .data1 88
    .data1 95
    .data1 72
    .data1 69
    .data1 73
    .data1 71
    .data1 72
    .data1 84
    .data1 0
.skip 3
_?1STRINGPACKET.29:
    .data1 46
    .data1 46
    .data1 47
    .data1 115
    .data1 114
    .data1 99
    .data1 47
    .data1 47
    .data1 112
    .data1 103
    .data1 109
    .data1 46
    .data1 99
    .data1 0
.skip 2
_?1STRINGPACKET.31:
    .data1 46
    .data1 46
    .data1 47
    .data1 115
    .data1 114
    .data1 99
    .data1 47
    .data1 47
    .data1 112
    .data1 103
    .data1 109
    .data1 46
    .data1 99
    .data1 0
.skip 2
_?1STRINGPACKET.34:
    .data1 67
    .data1 111
    .data1 117
    .data1 108
    .data1 100
    .data1 32
    .data1 110
    .data1 111
    .data1 116
    .data1 32
    .data1 111
    .data1 112
    .data1 101
    .data1 110
    .data1 32
    .data1 102
    .data1 105
    .data1 108
    .data1 101
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 105
    .data1 110
    .data1 32
    .data1 114
    .data1 101
    .data1 97
    .data1 100
    .data1 32
    .data1 109
    .data1 111
    .data1 100
    .data1 101
    .data1 10
    .data1 0
.skip 3
_?1STRINGPACKET.22:
    .data1 119
    .data1 0
.skip 2
_?1STRINGPACKET.26:
    .data1 104
    .data1 101
    .data1 105
    .data1 103
    .data1 104
    .data1 116
    .data1 32
    .data1 62
    .data1 32
    .data1 48
    .data1 0
.skip 1
_?1STRINGPACKET.30:
    .data1 119
    .data1 105
    .data1 100
    .data1 116
    .data1 104
    .data1 32
    .data1 62
    .data1 32
    .data1 48
    .data1 0
.skip 2
_?1STRINGPACKET.32:
    .data1 119
    .data1 105
    .data1 100
    .data1 116
    .data1 104
    .data1 32
    .data1 60
    .data1 61
    .data1 32
    .data1 77
    .data1 65
    .data1 88
    .data1 95
    .data1 87
    .data1 73
    .data1 68
    .data1 84
    .data1 72
    .data1 0
.skip 1
_?1STRINGPACKET.33:
    .data1 69
    .data1 114
    .data1 114
    .data1 111
    .data1 114
    .data1 32
    .data1 100
    .data1 117
    .data1 114
    .data1 105
    .data1 110
    .data1 103
    .data1 32
    .data1 105
    .data1 109
    .data1 97
    .data1 103
    .data1 101
    .data1 32
    .data1 119
    .data1 114
    .data1 105
    .data1 116
    .data1 101
    .data1 32
    .data1 40
    .data1 97
    .data1 116
    .data1 32
    .data1 104
    .data1 61
    .data1 37
    .data1 100
    .data1 44
    .data1 119
    .data1 61
    .data1 37
    .data1 100
    .data1 41
    .data1 10
    .data1 0
.equ ?2.2?2scratch.0, 0x0
.equ ?2.2?2ras_p, 0x10
.equ ?2.2?2spill_p, 0x14
.equ _?1TEMPLATEPACKET.22, 0x0
.section .data
.section .text
.equ ?2.2?2auto_size, 0x60
 ## End save_pgm
.section .bss
.section .data
.skip 3
verbose::
    .data4 1
.section .data
.import _impure_ptr
.type _impure_ptr,@object
.section .text
.import __assert
.type __assert,@function
.import exit
.type exit,@function
.import strcmp
.type strcmp,@function
.import __swbuf
.type __swbuf,@function
.import __srget
.type __srget,@function
.import fopen
.type fopen,@function
.import sscanf
.type sscanf,@function
.import printf
.type printf,@function
.import fscanf
.type fscanf,@function
.import fprintf
.type fprintf,@function
.import fflush
.type fflush,@function
.import fclose
.type fclose,@function
