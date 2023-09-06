#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void prompt(void);
void _print(const char *str);
int _strlen(const char *s);
void run(char *command);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
