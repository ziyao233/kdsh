/*
 *	kdsh
 *	/src/string.c
 *	By Mozilla Public License Version 2.0
 *	Copyright (C) 2023 Yao Zi. All rights reserved.
 */

#include"types.h"
#include"string.h"

size_t
strlen(const char *s)
{
	size_t size = 0;
	while (*s++)
		size++;
	return size;
}

char *
strcpy(char *dst, const char *src)
{
	char *ret = dst;
	while (*src)
		*dst++ = *src++;
	return ret;
}

int
strcmp(const char *a, const char *b)
{
	while (*a == *b && *a) {
		a++;
		b++;
	}
	return *a - *b;
}

void *
memcpy(void *dst, const void *src, size_t size)
{
	char *d = dst, *s = (char *)src;
	while (size--)
		*d++ = *s++;
	return dst;
}

void *
memset(void *s, int c, size_t n)
{
	char *p = s;
	while (n--)
		*p++ = (char)c;
	return s;
}
