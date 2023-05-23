#include "shell.h"

/**
 * _getline - takes input from STDIN
 * Return: void
 **/
void _getline(char *buffer, size_t bufferSize)
{
	int bytes;

	bytes = read(STDIN_FILENO, buffer, bufferSize);
	if (bytes == -1)
		perror("hsh");
	else
		buffer[strcspn(buffer, "\n")] = '\0';
}
