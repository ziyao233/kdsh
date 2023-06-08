/*
 *	kdsh
 *	/src/string.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_STRING_H_INC__
#define __KDSH_STRING_H_INC__

#include"types.h"

size_t strlen(const char *s);
char *strcpy(char *dst, const char *src);
void *memcpy(void *dst, const void *src, size_t size);
void *memset(void *s, int c, size_t n);

#endif	// __KDSH_STRING_H_INC__
