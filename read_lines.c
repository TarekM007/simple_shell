#include "shell.h"

/**
 * read_lines - reads lines in a non interactive mode.
 *
 * Return: pointer that points the the read line
 */
char *read_lines(void)
{
int bufsize = 1024;
int i = 0;
char *line = malloc(sizeof(char) * bufsize);
int ch;

if (line == NULL)
{
perror("allocation error");
exit(EXIT_FAILURE);
}
while (1)
{
ch = getchar();
if (ch == EOF)
{
free(line);
exit(EXIT_SUCCESS);
}
else if (ch == '\n')
{
line[i] = '\0';
return (line);
}
else
{
line[i] = ch;
}
i++;
if (i >= bufsize)
{
bufsize += bufsize;
line = realloc(line, bufsize);
if (line == NULL)
{
perror("reallocation error");
exit(EXIT_FAILURE);
}
}
}
}
