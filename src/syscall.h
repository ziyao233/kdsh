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

void exit(int code);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, void *buf, size_t count);

#endif	// __KDSH_SYSCALL_H_INC__
