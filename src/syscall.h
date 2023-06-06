/*
 *	kdsh
 *	/src/syscall.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_SYSCALL_H_INC__
#define __KDSH_SYSCALL_H_INC__

#include"types.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define MAP_ANONYMOUS	0x20
#define MAP_PRIVATE	0x02
#define PROT_READ	1
#define PROT_WRITE	2
#define MMAP_FAILED	((void *)(-1))

void exit(int code);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, void *buf, size_t count);
void *mmap(void *addr, size_t length, int prot, int flags,
	   int fd, size_t offset);
int munmap(void *addr, size_t length);

#endif	// __KDSH_SYSCALL_H_INC__
