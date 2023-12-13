#include "shell.h"

/**
 * env_builtin - handles env builtin
 */

void env_builtin(void)
{
	int i;
	char **env;

	env = environ;

	i = 0;
	while (env[i] != NULL)
	{
		_print(env[i]);
		_print("\n");
		i++;
	}
}
