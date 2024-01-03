
#include "shell.h"



/**
 * parse_input - A function that processes the input string into a command and its arguments.
 * @input: The provided input string.
 * @token_status: A pointer indicating whether the token is NULL from the start.
 * Return: The array holding the command and its arguments.
 */



char **parse_input(char *input, int *token_status)
{
    char *token = NULL, **args;
    int t_count = 0;

    *token_status = 0;

    token = _strtok(input, TOKEN_DELIM);
    if (token == NULL)
    {
        *token_status = 1;
    }
    args = malloc(sizeof(char *) * 64);
    if (args == NULL)
    {

        perror("malloc");
        exit(EXIT_FAILURE);
    }
    args[t_count++] = token;

    while ((token = _strtok(NULL, TOKEN_DELIM)))
    {
        args[t_count++] = token;
        if (t_count >= 64)
        {
            args = _realloc(args, sizeof(char *) * t_count * 2);
            if (args == NULL)
            {

                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
    }
    args[t_count] = NULL;
    return (args);
}
