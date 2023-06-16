/*
 *	kdsh
 *	/src/syscall.c
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#include"arch.h"
#include"types.h"
#include"syscall.h"

void
exit(int code)
{
	syscall1(code, SYS_exit);
	return;
}

ssize_t
read(int fd, void *buf, size_t count)
{
	return syscall3(fd, (unsigned long int)buf, count, SYS_read);
}

ssize_t
write(int fd, void *buf, size_t count)
{
	return syscall3(fd, (unsigned long int)buf, count, SYS_write);
}

#ifdef SYS_open

int
open(const char *p, int flags, int mode)
{
	return syscall3((unsigned long int)p, flags, mode, SYS_open);
}

#else

int
open(const char *p, int flags, int mode)
{
	return syscall4(AT_FDCWD, (unsigned long int)p, flags, mode,
			SYS_openat);
}

#endif

int
close(int fd)
{
	return syscall1(fd, SYS_close);
}

void *
mmap(void *addr, size_t length, int prot, int flags, int fd, size_t offset)
{
	return (void*)syscall6((unsigned long int)addr, length, prot, flags,
			       fd, offset, SYS_mmap);
}

int
munmap(void *addr, size_t length)
{
	return syscall2((unsigned long int)addr, length, SYS_munmap);
}

int
mount(const char *source, const char *target, const char *type,
      unsigned long int flags, const void *data)
{
	return syscall5((unsigned long int)source, (unsigned long int)target,
			(unsigned long int)type, flags,
			(unsigned long int)data, SYS_mount);
}

int
mkdirat(int dir, const char *path, int mode)
{
	return syscall3(dir, (unsigned long int)path, mode, SYS_mkdirat);
}
