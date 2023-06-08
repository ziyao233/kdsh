/*
 *	kdsh
 *	/src/arch-aarch64.S
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifdef TARGET_aarch64

	.global		syscall1, syscall2, syscall3, syscall4
	.global		syscall5, syscall6
	.global		_start

syscall1:
	mov		x8,		x1
	svc		#0
	ret

syscall2:
	mov		x8,		x2
	svc		#0
	ret

syscall3:
	mov		x8,		x3
	svc		#0
	ret

syscall4:
	mov		x8,		x4
	svc		#0
	ret

syscall5:
	mov		x8,		x5
	svc		#0
	ret

syscall6:
	mov		x8,		x6
	svc		#0
	ret

_start:
	mov		x29,		#0
	mov		x30,		#0
	mov		x0,		sp
	and		sp,		x0,		#-16
	b		start_c

#endif	// TARGET_aarch64
