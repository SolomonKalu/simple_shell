#include "shell.h"

/**
 * mod_getline - modified getline function
 *
 * Return: the string getline() read from stdin
*/

char *mod_getline(void)
{
	char *line = NULL;
	size_t buffer_size = 0;
	ssize_t read;

	read = getline(&line, &buffer_size, stdin);

	if (read == -1)
	{
		free(line);
		return (NULL);
	}
	else
		return (line);
}
