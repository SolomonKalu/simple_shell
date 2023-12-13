#include "shell.h"

/**
 * my_strlen - custom function to read a string
 * @s: string
 *
 * Return: the lenght of str
 */

size_t my_strlen(const char *s)
{
	size_t x = 0;

	while (*s != '\0')
	{
		write(STDOUT_FILENO, s, 1);
		s++;
		x++;
	}
	return (x);
}
