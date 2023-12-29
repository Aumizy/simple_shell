#include "shell.h"



/**
* __exit - Exits the current process.
* @args: Array containing the arguments of the command.
* Return: (1) in case the command "exit" is provided
*/



int __exit(char **args)
{
	int status;
	char *error;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
		{
			free(args[0]);
			free(args);
			exit(EXIT_SUCCESS);
		}

		if (args[2] != NULL)
		{
			error = "usage: exit status\n";
			write(2, error, _strlen(error));
			return (1);
		}
		status = atoi(args[1]);
		if (status == 0 && _strcmp(args[1], "0") != 0)
		{
			error = "invalid exit status\n";
			write(2, error, _strlen(error));
			return (1);
		}
		free(args[0]);
		free(args);
		exit(status);
	}
	return (0);
}



/**
* __env - A function responsible for printing.
* @args: Array containing the arguments of the command.
* Return: 0 on success.
*/



int __env(char **args)
{
	char **env = environ;


	if ((_strcmp(args[0], "env") == 0) && (args[1] == NULL))
	{
		while (*env)
		{
			write(1, *env, _strlen(*env));
			write(1, "\n", 1);
			env++;
		}
		free(args[0]);
		free(args);
		return (0);
	}
	return (1);
}



/**
* _setenv - change or add an environment variable
* @name: Name of the environment variable.
* @value: Value of the environment variable.
* @overwrite: Overwrite option.
*
* Description: The _setenv() function adds the variable name to the environment with the specified value,
* only if name does not already exist.
* If the variable name already exists in the environment, the _setenv() function changes its value to the specified value.
* if overwrite is nonzero;
* if overwrite is zero, then the value of name is  not
* changed  (and  setenv()  returns a success status).
* Return: 0 on success.
*/



int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_name_value;
	int putenv_status;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);
	if (_getenv(name) != NULL && overwrite != 0)
		return (0);

	env_name_value = malloc(_strlen(name) + _strlen(value) + 2);
	if (env_name_value == NULL)
	{
		perror("malloc");
		return (-1);
	}
	sprintf(env_name_value, "%s=%s", name, value);

	putenv_status = _putenv(env_name_value);

	if (putenv_status != 0)
	{
		free(env_name_value);
		return  (-1);
	}
	free(env_name_value);
	return (0);
}



/**
* is_setenv - Check if cmd is setenv and invoke setenv.
* @args: An array containing the command arguments.
*
* Return: 0 if successful otherwise -1.
*/



int is_setenv(char **args)
{
	char *error = "usage: setenv VARIABLE VALUE\n";

	if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
		{
			write(2, error, _strlen(error));
			return (98);
		}

		if (_setenv(args[1], args[2], 1) == -1)
		{
			error = "setenv failed\n";
			write(2, error, _strlen(error));
			return (98);
		}
		free(args[0]);
		free(args);
		return (99);
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL || args[3] != NULL)
		{
			error = "usage: unsetenv VARIABLE\n";
			write(2, error, _strlen(error));
			return (98);
		}
		if (_unsetenv(args[1]) == -1)
		{
			error = "unsetenv failed\n";
			write(2, error, _strlen(error));
			return (98);
		}
		free(args[0]);
		free(args);
		return (99);
	}
	return (0);
}



/**
* _putenv - Add or update an environment variable.
* @name_value: A string in the format "NAME=VALUE" to be added to the environment.
* Description: a function that prints the alphabet
* Return: 0 on success, -1 on failure.
*/



int _putenv(char *name_value)
{
	int env_len = 0, i;
	char **new_environ;

	while (environ[env_len])
		env_len++;



	/**
	 * allocate memory for new environ (+2 because of null pointer
	 * and new environ var
	 */



	new_environ = malloc((env_len + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		perror("malloc");
		return (-1);
	}

	for (i = 0; i < env_len; i++)
		new_environ[i] = _strdup(environ[i]);

	new_environ[env_len] = _strdup(name_value);
	new_environ[env_len + 1] = NULL;

	environ = new_environ;

	return (0);
}
