/*
 *	kdsh
 *	/src/write.c
 *	By Mozillza Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */


#include"types.h"
#include"syscall.h"
#include"string.h"
#include"tools.h"
#include"interaction.h"

define_usage(write,
\n\t	write [-c] <path> <EOF>
\n\t	Read input from stdin and write to <path>, using <EOF> as end of file
\n
\n\t	-c:	(Re)create file\n
)

int
cmd_write(int argc, const char *argv[])
{
	int flag = O_WRONLY | O_APPEND;
	int argStart = 2;
	if (argc == 3 && !strcmp(argv[1], "-c"))
		flag = O_WRONLY | O_TRUNC | O_CREAT;
	else if (argc == 2)
		argStart = 1;
	else
		return usage();

	int fd = open(argv[argStart], flag, 0644);
	scheck(fd >= 0, "Cannot open file\n");

	char *line;
	for (line = read_a_line();
	     strcmp(line, argv[argStart + 1]);
	     line = read_a_line()) {
		size_t len = strlen(line);
		line[len] = '\n';
		write(fd, line, len + 1);
		free(line);
	}
	free(line);

	scheck(!close(fd), "Cannot close file\n");

	return 0;
}
