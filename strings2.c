#include "shell.h"



/**
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
 * _strncmp - Compares the first (up to) n bytes of s1 and s2.
 * @s1: The initial string.
 * @s2: The second string
 * @n: The maximum number of bytes to compare.
 * Return: An integer less than, equal to, or greater than zero 
 * if `s1` (or the first `n` bytes thereof) is found, respectively, 
 * to be less than, to match, or be greater than `s2`.
 */



int _strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;

    while (i < n)
    {
        if (*s1 == '\0' || *s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
        i++;
    }
    return (0);
}
