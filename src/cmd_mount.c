#include"syscall.h"
#include"tools.h"

define_usage(mount,
\n\t	mount <Source> <Target> <Type>
\n\t	Mount filesystem Source with type Type at Target
\n)

int
cmd_mount(int argc, const char *argv[])
{
	if (argc != 3)
		return mount_usage();

	scheck(!mount(argv[1], argv[2], argv[3], 0, NULL),
	       "Mount failed\n");
	return 0;
}
