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
* _execvpe - Execute a new process image.
* @cmd: The command to be executed.
* @argv: An array of strings representing the argument list. The first element should point to cmd, and the last element should be NULL.
* @envp: The environment of the caller.
* Description: This function works similarly to execvpe. Refer to the man page of execvpe for more details.
* Return: The exec() functions return only if an error has occurred. The return value is -1, and errno is set to indicate the error.
*/




int _execvpe(const char *cmd, char *argv[], char *const envp[])
{
	char *path, *token, *executable;
	size_t cmd_len, token_len, e_len;

	path = getenv("PATH");
	if (path == NULL)
	{
		perror("getenv");
		exit(EXIT_FAILURE);
	}
	cmd_len = _strlen(cmd);
	
	token = _strtok(path, ":");

	while (token != NULL)
	{
	
		execve(cmd, argv, envp);

		token_len = _strlen(token);
	
		e_len = (token_len + cmd_len + 2) * sizeof(char);
		executable = malloc((e_len) * sizeof(char));
		if (executable == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		snprintf(executable, e_len, "%s/%s", token, cmd);

	
		execve(executable, argv, envp);

	
		token = _strtok(NULL, ":");
	}
	
	perror("execve");
	exit(EXIT_FAILURE);
}
