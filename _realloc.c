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
 * _realloc - Adjusts the allocation of a memory block..
 * @ptr: Pointer to the previous memory block.
 * @new_size: Updated size of the memory block..
 * Return: Pointer to the newly allocated memory block, or NULL in case of failure.
 */



void *_realloc(void *ptr, size_t new_size)
{
size_t prev_size, element_size, total_elements, i;
void *new_ptr;
char *prev_content, *new_content;
if (new_size == 0)
{
	free(ptr);
	return (NULL);
}
if (ptr == NULL)
	return (malloc(new_size));
new_ptr = malloc(new_size);

if (new_ptr)
{
	element_size = sizeof(((char *)ptr)[0]);
	total_elements = new_size / element_size;
	prev_size = total_elements * element_size;
	if (new_size < prev_size)
	{
		prev_size = new_size;
	}
	prev_content = (char *)ptr;
	new_content = (char *)new_ptr;

	for (i = 0; i < prev_size; i++)
	{
		new_content[i] = prev_content[i];
	}
	free(ptr);
	return (new_ptr);
}
else
{
	return (NULL); 
}
}
