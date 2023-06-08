/*
 *	kdsh
 *	/src/kdsh.c
 *	By Mozilla Public License Version 2.0
 *	Copyright (C) 2023 Yao Zi. All rights reserved.
 */

#include"arch.h"
#include"syscall.h"
#include"interaction.h"
#include"malloc.h"
#include"tools.h"

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
	while (1) {
		char *line = read_a_line();
		assert(line);
		puts(line);
		free(line);
	}

	return 0;
}
