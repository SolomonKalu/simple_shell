#ifndef SHELL_H
#define SHELL_H

/*header files*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/*wait*/

#include <sys/types.h>
#include <sys/wait.h>

/*external*/

extern char **environ;

#define BUFFER_SIZE 1024

/*prototypes*/

void _print(char *string);
int _strlen(char *s);
size_t _strcspn(const char *str, const char *reject);
int _strcmp(const char *str1, const char *str2);
void remove_whitespace(char *str);

/*exit*/

void my_exit_built(char **args);

#endif
