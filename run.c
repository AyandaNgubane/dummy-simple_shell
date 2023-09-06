#include "shell.h"

/**
 * run - runs the command from input
 * @command: command
 * Return: void
 */
void run(char *command)
{
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *path = "/bin/";
		char *program = "ls";
		char *args[] = {program, NULL};

		char *path2 = (char *)malloc(strlen(path) + strlen(command) + 1);
		_strcpy(path2, path);
		_strcat(path2, command);
		printf("path2: %s\n", path2);
		int len = strlen(path2);
		for (int i = 0; i < len; i++)
			printf("path2[%d]: %c\n", i, path2[i]);
		printf("length: %d\n", len);

		int exc = execve(path2, args, NULL);

		if (exc == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int stat;

		wait(&stat);
	}

}
/**
 * _strcat - appends the src string to the dest string
 *
 * @dest: destination
 * @src: string to append
 * Return: the full string
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcpy - copies string
 *
 * @dest: where to store copied string
 * @src: string to copy
 * Return: return the copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);
}
