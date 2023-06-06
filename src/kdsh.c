/*
 *	kdsh
 *	/src/kdsh.c
 *	By Mozilla Public License Version 2.0
 *	Copyright (C) 2023 Yao Zi. All rights reserved.
 */

#include"arch.h"
#include"syscall.h"
#include"interaction.h"

int main(int argc, const char *argv[]);

void
start_c(unsigned long int *arg)
{
	int argc	= arg[0];
	char **argv	= (void*)(arg + 1);
	exit(main(argc, (const char **)argv));
	return;
}


int
main(int argc, const char *argv[])
{
	puts("Hello kdsh!\n");
	return 0;
}
