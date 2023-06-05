/*
 *	kdsh
 *	/src/arch-x86_64.S
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifdef TARGET_x86_64

	.global		_start
	.global		syscall1, syscall2, syscall3, syscall4
	.global		syscall5, syscall6

syscall1:
	movq		%rsi,		%rax
	syscall
	ret

syscall2:
	movq		%rdx,		%rax
	syscall
	ret

syscall3:
	movq		%rcx,		%rax
	syscall
	ret

syscall4:
	movq		%rcx,		%r10
	movq		%r8,		%rax
	syscall
	ret

syscall5:
	movq		%rcx,		%r10
	movq		%r9,		%rax
	syscall
	ret

syscall6:
	movq		%rcx,		%r10
	movq		8(%rsp),	%rax
	syscall
	ret

_start:
	xorq		%rbp,		%rbp
	movq		%rsp,		%rdi
	andq		$-16,		%rsp
	call		start_c

#endif	// TARGET_x86_64
