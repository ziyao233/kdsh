/*
 *	kdsh
 *	/src/arch_x86_64.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_ARCH_X86_64_H_INC__
#define __KDSH_ARCH_X86_64_H_INC__

#define ARCH_PAGE_SIZE 4096

#define SYS_read	0
#define SYS_write	1
#define SYS_open	2
#define SYS_close	3
#define	SYS_mmap	9
#define SYS_munmap	11
#define SYS_exit	60

#endif	// __KDSH_ARCH_X86_64_H_INC__
