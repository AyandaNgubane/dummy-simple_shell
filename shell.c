#include "shell.h"

/**
 * main - main function
 * @ac: argument count
 * @av: argument vector
 * Return: 0 if successful
 */
int main(int ac, char *av[])
{
	char *command = NULL;
	size_t size = 0;
	ssize_t bytes_read, i;

	while (1)
	{
		prompt();
		bytes_read = getline(&command, &size, stdin); 
		if (bytes_read == -1)
		{
			free(command);
			return (1);
		}
		for (i = 0; i < bytes_read - 1; i++)
			continue;
		command[i] = '\0';
		run(command);
	}
	return (0);
}
/**
 * prompt - displays the in input prompt
 * Return: void
 */
void prompt(void)
{
	_print("$ ");
}
/**
 * _print - printing function
 * Return: void
 */
void _print(const char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
/**
 * _strlen - counts length of string
 *
 * @s: string to be checked
 * Return: length
 */
int _strlen(const char *s)
{
	int i;
	int length;

	length = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return (length);
}
