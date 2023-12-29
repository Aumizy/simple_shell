#include "shell.h"



/**
* interactive_sh - A function for executing the shell in interactive mode.
*/



void interactive_sh(void)
{
	char *input, **args;
	pid_t pid;
	int status, token_status, eof_status = 0;

	while (1)
	{
		write(1, "($) ", _strlen("($) "));
		input = read_input(&eof_status);
		if (eof_status == 1)
			break;
		args = parse_input(input, &token_status);

		if (token_status == 1 || is_builtin(args) == 99 || _f_ok(args[0]) != 0)
			continue;

		pid = fork();
		if (pid == 0)
		{
			_execvpe(args[0], args, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(args[0]);
	free(args);
	
}



/**
* non_interactive_sh - A function for executing the shell in non interactive mode.
*/



void non_interactive_sh(void)
{
	char *input, **args;
	pid_t pid;
	int status, token_status, eof_status = 0;

	input = read_input(&eof_status);

		if (eof_status != 1)
		{
			args = parse_input(input, &token_status);
			if (token_status == 1 || is_builtin(args) == 99 ||  _f_ok(args[0]) != 0)
				return;

			pid = fork();
			if (pid == 0)
			{
				_execvpe(args[0], args, environ);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
				waitpid(pid, &status, 0);

			free(args[0]);
			free(args);
		}
}
