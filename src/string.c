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
