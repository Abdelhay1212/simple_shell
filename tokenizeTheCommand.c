#include "shell.h"

/**
 * tokenizeTheCommand - tokenization of the command
 * Return: pointer to pointer
 **/
char **tokenizeTheCommand(char *command)
{
	int i = 0;
	char *token;
	char **tokens;

	tokens = malloc(20 * sizeof(char *));

	token = strtok(command, " ");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
