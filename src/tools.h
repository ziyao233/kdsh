/*
 *	kdsh
 *	/src/tools.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_TOOLS_H_INC__
#define __KDSH_TOOLS_H_INC__

#include"interaction.h"

#define assert(expr) do {					\
	if (!(expr)) {						\
		puts(__FILE__					\
		     ": Assertion failed: "#expr "\n");		\
		abort();					\
	}							\
} while (0)

#define check(expr, msg) do {					\
	if (!(expr))						\
		fatal(msg);					\
} while (0)
		  

void abort(void);
void fatal(const char *msg);

#endif	// __KDSH_TOOLS_H_INC__
