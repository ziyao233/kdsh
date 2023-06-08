/*
 *	kdsh
 *	/src/arch-aarch64.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_ARCH_AARCH64_H_INC__
#define __KDSH_ARCH_AARCH64_H_INC__

#define ARCH_PAGE_SIZE 4096

#define SYS_read	63
#define SYS_write	64
#define SYS_openat	56
#define SYS_close	57
#define SYS_mmap	222
#define SYS_munmap	215
#define SYS_exit	93

#endif	// __KDSH_ARCH_AARCH64_H_INC__
