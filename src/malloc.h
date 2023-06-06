/*
 *	kdsh
 *	/src/malloc.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_MALLOC_H_INC__
#define __KDSH_MALLOC_H_INC__

#include"types.h"

void *malloc(size_t size);
void free(void *p);

#endif	// __KDSH_MALLOC_H_INC__
