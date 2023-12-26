#include "shell.h"




/**
 * _getenv - Retrieves the value of an environment variable
 * @name: Name of the environment variable
 * Return: Pointer to the value in the environment, or NULL if there is no match
 */




char *_getenv(const char *name)
{
	/* Declare 'env' as an array of environment variables (char *). */
	char **env = environ, *env_var, *value;

	/* Error handling: 'name' must be a valid string. */
	if (name == NULL || name[0] == '\0')
		return (NULL);

	/* Iterate through all the enviroment variables */
	while (*env)
	{
		/* Tokenize each one with the delimiter "=". */
		env_var = _strtok(_strdup(*env), "=");
		if (env_var == NULL)
			return (NULL);

		/* Verify if the provided name matches the first token (variable name). */
		if (_strcmp(env_var, name) == 0)
		{
			value = _strtok(NULL, "=");
			free(env_var);
			return (value);
		}
		free(env_var);
		env++;
	}

	return (NULL);
}
