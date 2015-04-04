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
.equ _?1TEMPLATEPACKET.1, 0x0
 ## Begin mat_malloc
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:s32,$r0.4:s32,$r0.5:s32)
mat_malloc::
.trace 3
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    shl $r0.2 = $r0.3, 2   ## bblock 0, line 45,  t2,  t30,  2(I32)
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t16
;;								## 1
	c0    stw 0x14[$r0.1] = $r0.57  ## spill ## t20
;;								## 2
	c0    stw 0x18[$r0.1] = $r0.58  ## spill ## t21
;;								## 3
	c0    stw 0x1c[$r0.1] = $r0.59  ## spill ## t22
;;								## 4
	c0    stw 0x20[$r0.1] = $r0.5  ## spill ## t32
;;								## 5
	c0    stw 0x24[$r0.1] = $r0.4  ## spill ## t31
;;								## 6
	c0    stw 0x28[$r0.1] = $r0.3  ## spill ## t30
;;								## 7
.call malloc, caller, arg($r0.3:u32), ret($r0.3:u32)
	c0    call $l0.0 = malloc   ## bblock 0, line 45,  raddr(malloc)(P32),  t2
	c0    mov $r0.3 = $r0.2   ## t2
;;								## 8
	c0    mov $r0.59 = $r0.3   ## bblock 1, line 45,  t36,  t0
	c0    stw 0x2c[$r0.1] = $r0.3  ## spill ## t0
;;								## 9
	c0    ldw $r0.5 = 0x20[$r0.1]  ## restore ## t32
;;								## 10
	c0    ldw $r0.4 = 0x24[$r0.1]  ## restore ## t31
;;								## 11
	c0    ldw $r0.3 = 0x28[$r0.1]  ## restore ## t30
	      xnop 1
;;								## 13
	c0    mpylu $r0.2 = $r0.4, $r0.5   ## bblock 1, line 52,  t50,  t31,  t32
	c0    mpyhs $r0.4 = $r0.4, $r0.5   ## bblock 1, line 52,  t51,  t31,  t32
;;								## 14
	c0    sub $r0.3 = $r0.0, $r0.3   ## bblock 1, line 0,  t38,  0(I32),  t30
;;								## 15
	c0    add $r0.58 = $r0.2, $r0.4   ## bblock 1, line 52,  t10,  t50,  t51
	c0    mov $r0.57 = $r0.3   ## bblock 1, line 0,  t37,  t38
;;								## 16
.trace 1
L0?3:
	c0    cmplt $b0.0 = $r0.57, $r0.0   ## bblock 2, line 50,  t52(I1),  t37,  0(SI32)
	c0    mov $r0.3 = $r0.58   ## t10
	      xnop 1
;;								## 1
	c0    brf $b0.0, L1?3   ## bblock 2, line 50,  t52(I1)
;;								## 2
.call malloc, caller, arg($r0.3:u32), ret($r0.3:u32)
	c0    call $l0.0 = malloc   ## bblock 4, line 52,  raddr(malloc)(P32),  t10
;;								## 3
	c0    stw 0[$r0.59] = $r0.3   ## bblock 5, line 52, t36, t7
	c0    add $r0.57 = $r0.57, 1   ## bblock 5, line 0,  t37,  t37,  1(I32)
;;								## 4
	c0    add $r0.59 = $r0.59, 4   ## bblock 5, line 0,  t36,  t36,  4(I32)
	c0    goto L0?3 ## goto
;;								## 5
.trace 4
L1?3:
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t16
;;								## 0
	c0    ldw $r0.3 = 0x2c[$r0.1]  ## restore ## t0
;;								## 1
	c0    ldw $r0.59 = 0x1c[$r0.1]  ## restore ## t22
;;								## 2
	c0    ldw $r0.58 = 0x18[$r0.1]  ## restore ## t21
;;								## 3
	c0    ldw $r0.57 = 0x14[$r0.1]  ## restore ## t20
	      xnop 1
;;								## 5
.return ret($r0.3:u32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 3, line 58,  t17,  ?2.1?2auto_size(I32),  t16
;;								## 6
.endp
.section .bss
.section .data
.equ ?2.1?2scratch.0, 0x0
.equ ?2.1?2ras_p, 0x10
.equ ?2.1?2spill_p, 0x14
.section .data
.section .text
.equ ?2.1?2auto_size, 0x40
 ## End mat_malloc
.section .bss
.section .data
.section .data
.section .text
.import malloc
.type malloc,@function
