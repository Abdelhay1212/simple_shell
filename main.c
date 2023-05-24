#include "shell.h"

/**
 * main - takes a command and execute it
 * Return: integer
 **/
int main(void)
{
	int i;
	pid_t pid;
	char *command;
	char **tokens;
	size_t bufferSize = 1024;

	while (1)
	{

		write(1, "$ ", 2);
		command = malloc(1024 * sizeof(char));
		_getline(command, bufferSize);

		if (command != NULL)
		{
			tokens = tokenizeTheCommand(command);

			if (strcmp(tokens[0], "exit") == 0)
			{
				free(command);
				exit(0);
			}
			
			pid = fork();
			if (pid == -1)
			{
			write(1, "hsh: Failed to fork the process\n", 31);
			}
			else if (pid == 0)
			{
				if (strcmp(tokens[0], "env") == 0)
					printEnv();
				else
					executeCommand(tokens);
				exit(0);
			}
			else
				wait(NULL);

			for (i = 0; tokens[i] != NULL; i++)
				free(tokens[i]);
			free(tokens);
		}
		
		free(command);
	}

	return (0);
}
