/*
 *	kdsh
 *	/src/syscall.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_SYSCALL_H_INC__
#define __KDSH_SYSCALL_H_INC__

#include"types.h"

#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

#define O_CREAT		0100
#define O_TRUNC		01000
#define O_APPEND	02000
#define O_RDONLY	00
#define O_WRONLY	01
#define O_RDWR		02

#define AT_FDCWD	(-100)

#define MAP_ANONYMOUS	0x20
#define MAP_PRIVATE	0x02
#define PROT_READ	1
#define PROT_WRITE	2
#define MMAP_FAILED	((void *)(-1))

void exit(int code);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, void *buf, size_t count);
int open(const char *path, int flag, int mode);
int close(int fd);
void *mmap(void *addr, size_t length, int prot, int flags,
	   int fd, size_t offset);
int munmap(void *addr, size_t length);
int mount(const char *src, const char *target, const char *type,
	  unsigned long int flags, const void *data);
int mkdirat(int dir, const char *path, int mode);

#endif	// __KDSH_SYSCALL_H_INC__
