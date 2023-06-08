/*
 *	kdsh
 *	/src/tools.c
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#include"arch.h"
#include"syscall.h"
#include"interaction.h"

void
abort(void)
{
	puts("Aborted\n");
	exit(-1);
	return;
}

void
fatal(const char *msg)
{
	puts("Fatal error: ");
	puts(msg);
	puts("\nkdsh now exi:s");
	abort();
	return;
}
