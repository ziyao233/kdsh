/*
 *	kdsh
 *	/src/syscall.c
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#include"arch.h"
#include"types.h"

#define SYS_read	0
#define SYS_write	1
#define SYS_mmap	9
#define SYS_munmap	11
#define SYS_exit	60

void
exit(int code)
{
	syscall1(code, SYS_exit);
	return;
}

ssize_t 
read(int fd, void *buf, size_t count)
{
	return syscall3(fd, buf, count, SYS_read);
}

ssize_t
write(int fd, void *buf, size_t count)
{
	return syscall3(fd, buf, count, SYS_write);
}

void *
mmap(void *addr, size_t length, int prot, int flags, int fd, size_t offset)
{
	return syscall6(addr, length, prot, flags, fd, offset, SYS_mmap);
}