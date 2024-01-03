#include "shell.h"



/**
* main: A shell program that is simple
* Description: A simplified implementation of a Command-Line Interface (CLI) shell.
* Return: Indicates success with a return value of 0.
*/



int main(void)
{
	if (isatty(STDIN_FILENO))
		interactive_sh();
	else
		non_interactive_sh();
	return (0);
}
