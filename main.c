#include "shell.h"

/**
 * main - entry point function to the shell
 *
 * Return: 0 on success
 */
int main(void) {
char *line = NULL;
char **args;
size_t bufsize = 0;
int status = -1;
if (isatty(STDIN_FILENO) == 1) {
do {
printf("$ ");
if (getline(&line, &bufsize, stdin) == -1) {
if (feof(stdin)) {
free(line);
exit(EXIT_SUCCESS);
}
else {
free(line);
perror("error while reading the line from stdin");
exit(EXIT_FAILURE);
}
}
args = _tokenizer(line);
status = execute_args(args);
free(line);
free(args);
if (status >= 0)
exit(status);
} while (status == -1);
}
else {
do {
line = read_lines();
args = _tokenizer(line);
status = execute_args(args);
free(line);
free(args);
if (status >= 0)
exit(status);
}
while (status == -1);
}
return (0);
}
