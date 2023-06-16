/*
 *	kdsh
 *	/src/cmd.h
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved.
 */

#ifndef __KDSH_CMD_H_INC__
#define __KDSH_CMD_H_INC__

int cmd_write(int argc, const char *argv[]);
int cmd_sysrq(int argc, const char *argv[]);
int cmd_mount(int argc, const char *argv[]);
int cmd_mkdir(int argc, const char *argv[]);

#endif	// __KDSH_CMD_H_INC__
