#include "shell.h"



/**
*cmd- command prompt
*strtok- string token
*perror- path error
*lineptr- line pointer
*alloc- allocation
*args- argument
*int- integer
*src- source
*str- string
*chr- character
*len- length
*const- constant
*des- destination
*strlen-string length
*strcpy- string copy
*strdup- string duplicate
*strncmp- string compare 
*/



/**
 * _getenv - Retrieves the value of an environment variable
 * @name: Name of the environment variable
 * Return: Pointer to the value in the environment, or NULL if there is no match
 */




char *_getenv(const char *name)
{

	char **env = environ, *env_var, *value;


	if (name == NULL || name[0] == '\0')
		return (NULL);


	while (*env)
	{

		env_var = _strtok(_strdup(*env), "=");
		if (env_var == NULL)
			return (NULL);


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
