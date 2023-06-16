/*
 *	kdsh
 *	/src/cmd_sysrq.c
 *	By Mozilla Public License Version 2.0
 *	Copyright (c) 2023 Yao Zi. All rights reserved
 */

#include"syscall.h"
#include"tools.h"

define_usage(sysrq,
\n\t	sysrq <Event>
\n\t	Trigger a sysrq event
\n\t
\n\t	<Event>: Event to trigger, could be
\n\t\t		c:\t	kernel crash
\n\t\t		g:\t	kgdb event
\n)

int
cmd_sysrq(int argc, const char *argv[])
{
	if (argc != 1)
		return sysrq_usage();

	int fd = open("/proc/sysrq-trigger", O_WRONLY, 0655);
	scheck(fd >= 0, "Cannot open /proc/sysrq-trigger\n");

	write(fd, (void*)argv[1], 1);

	scheck(!close(fd), "Cannot close file\n");

	return 0;
}
