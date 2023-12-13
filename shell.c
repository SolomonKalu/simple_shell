#include "shell.h"

/**
 * main - envoke shell
 *
 * Return: 0
*/

int main(void)
{
	char *readline, *token;
	char **args = { NULL };
	pid_t my_pid;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_print("($) ");
		readline = mod_getline();
		if (readline == NULL)
		{
			if (isatty(STDIN_FILENO))
				_print("\n");
			break;
		}

		readline[_strcspn(readline, "\n")] = '\0';
		remove_whitespace(readline);
		remove_leading(readline);
		if (*readline == '\0')
			continue;

		token = strtok(readline, " ");
		while (token != NULL)
		{
			my_pid = fork();
			if (my_pid == 0)
			{
				execve(readline, args, environ);
				perror("execve");
			}
			else if (my_pid > 0)
				wait(&status);
			else
				perror("fork");
			token = strtok(NULL, " ");
		}
		free(readline);
	}
	return (0);
}
