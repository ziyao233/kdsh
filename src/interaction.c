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

char *
read_a_line(void)
{
	char *s = malloc(16);
	if (!s)
		return NULL;

	size_t len = 0;
	for (len += read(STDIN_FILENO, s + len, 16);
	     !(len % 16) && s[len - 1] != '\n';
	     len += read(STDIN_FILENO, s + len, 16)) {
		s = mem_resize(s, len, len + 16);
		if (!s)
			return NULL;
	}

	s[len - 1] = '\0';
	return s;
}
