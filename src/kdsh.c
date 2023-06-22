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
license_usage(void)
{
	puts("\n\tlicense\n\tPrint the license of kdsh\n");
	return 0;
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
typedef int (*Cmd_Usage)(void);

static int cmd_help(int argc, const char *argv[]);
static int help_usage(void);

#define defcmd(name) {#name, (Cmd_Fn)cmd_##name, (Cmd_Usage)name##_usage}

struct {
	const char *name;
	Cmd_Fn fn;
	int (*usage)(void);
} cmds[] = {
	defcmd(license),
	defcmd(write),
	defcmd(sysrq),
	defcmd(mount),
	defcmd(mkdir),
	defcmd(help),
	{NULL, NULL, NULL}
};

#undef defcmd

static inline int
search_cmd_index(const char *name)
{
	for (int i = 0; cmds[i].name; i++) {
		if (!strcmp(cmds[i].name, name))
			return i;
	}
	return -1;
}

static inline Cmd_Fn
search_cmd(const char *name)
{
	int i = search_cmd_index(name);
	return i < 0 ? NULL : cmds[i].fn;
}

static inline Cmd_Usage
search_usage(const char *name)
{
	int i = search_cmd_index(name);
	return i < 0 ? NULL : cmds[i].usage;
}

static int
help_print_list()
{
	puts("\nAvailable commands:\n");
	for (int i = 0; cmds[i].name; i++) {
		puts("\t");
		puts(cmds[i].name);
		puts("\n");
	}
	return 0;
}

static int
help_print_usage(const char *name)
{
	Cmd_Usage usage = search_usage(name);
	if (usage) {
		return usage();
	} else {
		puts("No such command: ");
		puts(name);
		puts("\n");
		return -1;
	}
}

static int
cmd_help(int argc, const char *argv[])
{
	if (argc == 0) {
		return help_print_list();
	} else {
		return help_print_usage(argv[1]);
	}
}

static
define_usage(help,
\n\t	help [command]
\n\t	Get a list of available commands or description of the [command].
\n\t
\n\t	Get the description of [command]. If [command] is omitted, a list of
\n\t	available commands will be printed.
\n)

static inline int
is_space(const char *p)
{
	return *p == ' ';
}

static const char *
skip_space(const char *p)
{
	while (is_space(p))
		p++;
	return p;
}

static const char *
skip_word(const char *p)
{
	while(!is_space(p) && *p)
		p++;
	return p;
}

static const char *
copy_str_until(char *dst, const char *src, const char *srcEnd)
{
	char *p = dst;
	while (src < srcEnd) {
		*p = *src;
		src++;
		p++;
	}
	*p = '\0';
	return dst;
}

static char **
split_cmd_line(const char *line, int *output_argc)
{
	*output_argc = 0;
	char **argv = NULL;
	for (const char *p = line; *p; (*output_argc)++) {
		argv = mem_resize(argv, *output_argc * sizeof(char *),
				  (*output_argc + 1) * sizeof(char *));
		check(argv, "OOM: Cannot split command");

		const char *end = skip_word(p);

		char *arg = malloc(end - p + 1);
		check(arg, "OOM: Cannot split command");
		argv[*output_argc] = arg;

		copy_str_until(arg, p, end);

		p = skip_space(end);
	}
	(*output_argc)--;
	return argv;
}

char **
read_cmd(int *output_argc)
{
	puts("% ");

	char *line = read_a_line();
	check(line, "OOM: Cannot read from input");

	char **argv = split_cmd_line(line, output_argc);
	free(line);
	return argv;
}

static inline void
enter_shell(void)
{
	while (1) {
		int argc = 0;
		char **argv = read_cmd(&argc);
		if (!argv)
			continue;

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
