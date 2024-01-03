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
 * read_input - A function for reading user input.
 * @eof_stats: The memory address of a var that stores the end-of-file (EOF) stats
 * Return: (input) - a string that contains the input
 */



char *read_input(int *eof_stats)
{
    char *input = NULL;
    size_t input_len;
    int bytes_read;

    input_len = 0;
    *eof_stats = 0;
    bytes_read = getline(&input, &input_len, stdin);
    if (bytes_read == -1)
    {
        if (feof(stdin))
        {
            write(1, "\n", 1);
            *eof_stats = 1;
        }
        else
        {
            perror("_getline");
            free(input);
            exit(EXIT_FAILURE);
        }
    }

    if (input[bytes_read - 1] == '\n')
        input[bytes_read - 1] = '\0';

    return (input);
}
