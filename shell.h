#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define DELIM " \t\n"

extern char **environ;

char **_tokenizer(char *line);
int execute_args(char **args);
char *read_lines(void);

#endif
