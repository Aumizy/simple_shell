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
*strcpy- string copy
*strdup- string duplicate
*strncmp- string compare 
*/



/**
 * _strtok - Splits a string into tokens using specified delimiters.
 *
 * @input: The string to be tokenized
 * @delim: The delimiter
 * Return: A reference to the next token or NULL if no tokens remain.
 */



char *_strtok(char *input, const char *delim)
{
    static char *tracker;
    char *token;
    if (input != NULL)
        tracker = input;
    while ((tracker != NULL) && (_strchr(delim, *tracker) != NULL) &&
           (*tracker != '\0'))
        tracker++;
    token = tracker;
    if (tracker == NULL || *tracker == '\0')
        return (NULL);
    while (*tracker != '\0')
    {
        if (_strchr(delim, *tracker) != NULL)
        {
            *tracker = '\0';
            tracker++;
            return (token);
        }
        tracker++;
    }

    if (*tracker == '\0')
    {
        tracker = NULL;
        return (token);
    }
    return (NULL);
}
