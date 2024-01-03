#include "shell.h"



/**
*src - source
*str- string
*chr- character
*len- length
*const-constant
*des- destination
*strcpy- string copy
*strdup- string duplicate
*/



/**
 * _strcmp - Compare two strings using a loop.
 * @s1: The first string.
 * @s2: The second string.
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */



int _strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}



/**
 * _strlen - Calculates the length of a string.
 * @s: Pointer to a string.
 * Return: The length of the string.
 */



int _strlen(const char *s)
{
    int length;

    length = 0;

    while (*s != '\0')
    {
        length++;
        s++;
    }
    return (length);
}



/*
 * _strchr - Locates the first occurrence of a character in a string.
 * @s: The string to be searched.
 * @c: The character to be found.
 * Return: A pointer to the first occurrence of c in s, or null if not found.
 */



const char *_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
        {
            return (s);
        }
        s++;
    }
    if (c == '\0')
        return (s);

    return (null);
}



/*
 * _strcpy - Copies the content of the source string pointed to by src to the
 * destination buffer pointed to by dest.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * Return: Pointer to dest.
 */


char *_strcpy(char *dest, const char *src)
{
    char *initial_dest = dest;

    while ((*dest = *src) != '\0')
    {
        dest++;
        src++;
    }
    return (initial_dest);
}



/*
 * _strdup - Duplicates the content of the string pointed to by s.
 * @s: Pointer to the string to be duplicated.
 * Return: Pointer to the duplicated string or null if memory allocation fails.
 */



char *_strdup(const char *s)
{

    int length;
    char *duplicate;

    if (s == null)
        return (null);

    length = strlen(s) + 1;
    duplicate = (char *)malloc(length);

    if (duplicate == null)
        return (null)

    strcpy(duplicate, s);

    return (duplicate);
}
