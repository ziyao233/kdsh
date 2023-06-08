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
#include"string.h"
#include"cmd.h"

static inline void
print_license(void)
{
	puts(
"\tkdsh built on " __DATE__ "\n"
"By Mozilla Public License Version 2.0\n"
"Copyright (c) 2023 Yao Zi. All rights reserved\n"
"Refer to https://github.com/ziyao233/kdsh for more information\n");
	return;
}

int
cmd_license(int argc, const char *argv[])
{
	(void)argc;
	(void)argv;
	print_license();
	return 0;
}

typedef int (*Cmd_Fn)(int, const char **);

struct {
	const char *name;
	Cmd_Fn fn;
} cmds[] = {
	{"license", cmd_license},
	{NULL, NULL}
};

static inline Cmd_Fn
search_cmd(const char *name)
{
	for (int i = 0; cmds[i].name; i++) {
		if (!strcmp(cmds[i].name, name))
			return cmds[i].fn;
	}
	return NULL;
}

char **
read_cmd(int *output_argc)
{
	puts("% ");

	char *line = read_a_line();
	check(line, "OOM: Cannot read from input");

	*output_argc = 0;
	char **argv = NULL;
	for (const char *p = line; *p; (*output_argc)++) {
		argv = mem_resize(argv, *output_argc * sizeof(char *),
				  (*output_argc + 1) * sizeof(char *));
		check(argv, "OOM: Cannot split command");

		const char *end = p;
		while (*end != ' ' && *end)
			end++;

		char *arg = malloc(end - p + 1);
		check(arg, "OOM: Cannot split command");
		argv[*output_argc] = arg;

		while (p < end) {
			*arg = *p;
			p++;
			arg++;
		}

		while (*p == ' ')
			p++;
	}
	free(line);
	return argv;
}

static inline void
enter_shell(void)
{
	while (1) {
		int argc = 0;
		char **argv = read_cmd(&argc);

		Cmd_Fn fn = search_cmd(argv[0]);

		if (!fn) {
			puts(argv[0]);
			puts(": command not found\n");
		} else {
			fn(argc, (const char **)argv);
		}

		for (int i = 0; i < argc; i++)
			free(argv[i]);
		free(argv);
	}
	return;
}

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
	(void)argc;
	(void)argv;
	print_license();
	enter_shell();
	return 0;
}
