/*
 *	kdsh
 *	/src/interaction.c
 *	By Mozilla Public License Version 2,0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#include"types.h"
#include"string.h"
#include"syscall.h"
#include"interaction.h"

void
puts(const char *msg)
{
	write(STDOUT_FILENO, (void*)msg, strlen(msg));
	return;
}
