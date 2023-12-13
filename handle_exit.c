#include "shell.h"

/**
 * my_exit_built - custom exit function
 * @args: argument
 */
void my_exit_built(char **args)
{
	int x;

	if (args[1])
	{
		x = atoi(args[1]);
	}
	exit(x);
}
