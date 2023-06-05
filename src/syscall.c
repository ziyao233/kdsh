/*
 *	kdsh
 *	/src/syscall.c
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#include"arch.h"

#define SYS_exit	60

void
exit(int code)
{
	syscall1(code, SYS_exit);
	return;
}
