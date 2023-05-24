#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

char **tokenizeTheCommand(char *command);
void executeCommand(char **tokens);
void _getline(char *buffer, size_t bufferSize);
void printEnv(void);
void _exitShell(char *command);

#endif
