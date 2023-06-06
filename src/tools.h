/*
 *	kdsh
 *	/src/tools.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_TOOLS_H_INC__
#define __KDSH_TOOLS_H_INC__

#include"interaction.h"

#define __macro_to_str__(s) #s
#define assert(expr) do {					\
	if (!(expr)) {						\
		puts(__FILE__					\
		     ": Assertion failed: "#expr "\n");		\
		abort();					\
	}							\
} while (0)
#undef to_str

void abort(void);

#endif	// __KDSH_TOOLS_H_INC__
