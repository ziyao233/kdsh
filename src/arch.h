/*
 *	kdsh
 *	/src/arch.h
 *	By Mozilla Public License Version 2.0
 &	Copyright (c) 2023 Yao Zi, All rights reserved.
 */

#ifndef __KDSH_ARCH_H_INC__
#define __KDSH_ARCH_H_INC__

#if defined(TARGET_x86_64)

#include"arch-x86_64.h"

#elif defined(TARGET_riscv64)

#include"arch-riscv64.h"

#elif defined(TARGET_aarch64)

#include"arch-aarch64.h"

#else

#error "Unsupported architecture"

#endif

unsigned long int syscall1(unsigned long int a, unsigned long int nr);
unsigned long int syscall2(unsigned long int a, unsigned long int b,
			   unsigned long int nr);
unsigned long int syscall3(unsigned long int a, unsigned long int b,
			   unsigned long int c, unsigned long int nr);
unsigned long int syscall4(unsigned long int a, unsigned long int b,
			   unsigned long int c, unsigned long int d,
			   unsigned long int nr);
unsigned long int syscall5(unsigned long int a, unsigned long int b,
			   unsigned long int c, unsigned long int d,
			   unsigned long int e, unsigned long int nr);
unsigned long int syscall6(unsigned long int a, unsigned long int b,
			   unsigned long int c, unsigned long int d,
			   unsigned long int e, unsigned long int f,
			   unsigned long int nr);

#endif	// __KDSH_ARCH_H_INC__
