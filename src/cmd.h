/*
 *	kdsh
 *	/src/cmd.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_CMD_H_INC__
#define __KDSH_CMD_H_INC__

#define defcmd(name)					\
int cmd_##name(int argc, const char *argv[]);		\
int name##_usage(void);

defcmd(write)
defcmd(sysrq)
defcmd(mount)
defcmd(mkdir)

#undef defcmd

#endif	// __KDSH_CMD_H_INC__
