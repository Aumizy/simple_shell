#include "shell.h"




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

	/*  Pass the content of PATH to the variable 'path'. */
	path = getenv("PATH");
	if (path == NULL)
	{
		perror("getenv");
		exit(EXIT_FAILURE);
	}
	cmd_len = _strlen(cmd);
	/* 'path' is a colon-separated string. Tokenize each string. */
	token = _strtok(path, ":");

	while (token != NULL)
	{
		/* Try executing 'cmd' without the specified path. */
		execve(cmd, argv, envp);

		token_len = _strlen(token);
		/* Merge 'path' with 'cmd'. */
		e_len = (token_len + cmd_len + 2) * sizeof(char);
		executable = malloc((e_len) * sizeof(char));
		if (executable == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		snprintf(executable, e_len, "%s/%s", token, cmd);

		/* Attempt to execute 'cmd' with the modified 'path' */
		execve(executable, argv, envp);

		/* If the code reaches here, it means execve failed. Try the next path */
		token = _strtok(NULL, ":");
	}
	/* If the code reaches here, it means we have exhausted all paths in the 'path' variable. */
	perror("execve");
	exit(EXIT_FAILURE);
}
