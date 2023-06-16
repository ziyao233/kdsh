#include"syscall.h"
#include"tools.h"

define_usage(mkdir,
\n\t	mkdir <path>
\n\t	Create directory <path>
\n)

int
cmd_mkdir(int argc, const char *argv[])
{
	if (argc != 1)
		return mkdir_usage();

	scheck(!mkdirat(AT_FDCWD, argv[1], 0755), "Cannot create directory");

	return 0;
}
