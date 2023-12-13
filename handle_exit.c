#include "shell.h"

/**
 * my_exit_built - custom exit function
 * @args: argument
 */
void my_exit_built(char **args)
{
	int status;

	if (args[1])
	{
		status = atoi(args[1]);
	}
	exit(status);
}
