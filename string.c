#include "shell.h"

/**
 * _strcspn - counts the number of characters not similar
 * @str: first string
 * @reject: second string to be rejected
 *
 * Return: number of non-similar characters
 */

size_t _strcspn(const char *str, const char *reject)
{
	const char *ptr;
	size_t count = 0;

	for (; *str != '\0'; str++)
	{
		for (ptr = reject; *ptr != '\0'; ptr++)
		{
			if (*str == *ptr)
				return (count);
		}
		count++;
	}
	return (count);
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: different number
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * remove_whitespace - function that removes trailing whitespaces
 * @str: string from which whitespaces are removed
 *
 */

void remove_whitespace(char *str)
{
	int len = _strlen(str);
	int i = len - 1;

	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
	{
		str[i] = '\0';
		i--;
	}
}

/**
 * remove_leading - function that removes leading whitespaces
 * @str: string that might have leading whitespaces
 *
 */

void remove_leading(char *str)
{
	int i = 0;
	int j = 0;
	int len = _strlen(str);

	while (str[i] == ' ' || str[i] == '\t')
		i++;

	while (i < len)
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
}
