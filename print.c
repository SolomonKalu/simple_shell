#include "shell.h"

/**
 * _print - simple print function
 * @string: string parameter
 *
*/

void _print(char *string)
{
	write(STDOUT_FILENO, string, _strlen(string));
}

/**
 * _strlen - function that finds length of string
 * @s: the string
 *
 * Return: length of the string
*/

int _strlen(char *s)
{
	int l = 0;

	while (*s)
	{
		l++;
		s++;
	}

	return (l);
}
