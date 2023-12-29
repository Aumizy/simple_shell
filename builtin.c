#include "shell.h"



/**
 * is_builtin - Checks if the entered command is a built-in command.
 * @args: Array of command arguments.
 * Return: 99 if a built-in command is encountered, otherwise 0.
 */



int is_builtin(char **args)
{
	if (__exit(args) != 0)
		return (99);

	if (__env(args) == 0)
		return (99);

	if (is_setenv(args) != 0)
		return (99);

	return (0);
}



/**
 * _unsetenv - Deletes the variable name from the environment.
 * @name: Name of the variable to be deleted.
 * Return: 0 on success.
 */



int _unsetenv(char *name)
{
	int environ_len = 0, i, j;
	char **new_environ;

	while (environ[environ_len])
		environ_len++;

	new_environ = malloc(environ_len * sizeof(char *));
	if (new_environ == NULL)
	{
		perror("malloc");
		return (-1);
	}

	for (i = 0, j = 0; i < environ_len; i++)
	{
		if (_strncmp(environ[i], name, _strlen(name)) != 0)
		{
			new_environ[j] = _strdup(environ[i]);
			if (new_environ[j] == NULL)
			{
				perror("malloc");
				return (-1);
			}
			j++;
		}
	}
	new_environ[j] = NULL;
	environ = new_environ;

	return (0);
}
