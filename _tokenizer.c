#include "shell.h"

/**
 * _tokenizer - splits a string into multiple strings
 * @line: string to be tokenized
 *
 * Return: pointer that points to the new array
 */
char **_tokenizer(char *line)
{
int bufsize = 64;
int i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("allocation error in _tokenizer: tokens\n");
exit(EXIT_FAILURE);
}
token = strtok(line, DELIM);
while (token != NULL)
{
if (token[0] == '#')
{
break;
}
tokens[i] = token;
i++;
if (i >= bufsize)
{
bufsize += bufsize;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror("reallocation error in _tokenizer: tokens");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, DELIM);
}
tokens[i] = NULL;
return (tokens);
}
