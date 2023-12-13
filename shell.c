#include "shell.h"

void handle_sigint(int signal)
{
	(void)signal;
	_print("\n");
	exit(0);
}

/**
 * parser - parses the string
 *
 * @line: the string to be parsed
 */

void parser(char *line)
{
	char *args[BUFFER_SIZE];
	pid_t my_pid;
	int i = 0;

	char *token = strtok(line, " \t");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;

	if (_strcmp(args[0], "exit") == 0)
		exit(0);

	my_pid = fork();

	if (my_pid == 0)
	{
		execve(args[0], args, environ);
		perror("execve failed");
		exit(1);
	}
	else if (my_pid > 0)
		wait(NULL);
	else
	{
		perror("fork failed");
		exit(1);
	}
}

/**
 * main - main function
 *
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t buffer = 0;
	ssize_t read;

	signal(SIGINT, handle_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_print("($) ");
		read = getline(&line, &buffer, stdin);

		if (read == -1)
			exit(1);

		line[_strcspn(line, "\n")] = '\0';

		if (*line == '\0')
			continue;

		parser(line);
	}
	free(line);
	return (0);
}
