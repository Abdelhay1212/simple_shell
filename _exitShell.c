#include "shell.h"

/**
 * _exitShell - exit with error number
 * @command: command to free
 * Return: void
 **/
void _exitShell(char *command)
{
	free(command);
	exit(0);
}

