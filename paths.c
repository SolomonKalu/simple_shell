#include "shell.h"

/**
 * reveal_path - searches for cmd in path
 * @cmd: command
 *
 * Return: cmd location
 */

char *reveal_path(char *cmd)
{
	char *path_tk, *mypath;
	char *dir;
	int cmd_len;
	struct stat mem;

	mypath = getenv("PATH");
	if (!mypath)
	{
		return (NULL);
	}
	cmd_len = strlen(cmd);
	path_tk = strtok(mypath, ":");
	while (path_tk)
	{
		dir = malloc(strlen(path_tk) + cmd_len + 2);
		if (!dir)
		{
			return (NULL);
		}
		strcpy(dir, path_tk);
		strcat(dir, "/");
		strcat(dir, cmd);
		if (stat(dir, &mem) == 0)
		{
			free(mypath);
			return (dir);
		}
		free(dir);
		path_tk = strtok(NULL, ":");
	}
	free(mypath);
	return (NULL);
}
