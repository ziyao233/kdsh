/*
 *	kdsh
 *	/src/arch-riscv64.S
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifdef TARGET_riscv64

	.global		_start
	.global		syscall1, syscall2, syscall3, syscall4
	.global		syscall5, syscall6
	.weak		__global_pointer$
	.hidden		__global_pointer$

syscall1:
	mv		a7,		a1
	ecall
	ret

syscall2:
	mv		a7,		a2
	ecall
	ret

syscall3:
	mv		a7,		a3
	ecall
	ret

syscall4:
	mv		a7,		a4
	ecall
	ret

syscall5:
	mv		a7,		a5
	ecall
	ret

syscall6:
	mv		a7,		a6
	ecall
	ret

_start:
	mv		a0,		sp
	andi		sp,		sp,		-16
	j		start_c

#endif	// TARGET_riscv64
