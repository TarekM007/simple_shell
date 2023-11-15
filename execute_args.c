#include "shell.h"

/**
 * execute_args - a functions that executes non_built_in functions.
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int execute_args(char **args)
{
pid_t pid;
int status;

if (args[0] == NULL)
return (-1);

pid = fork();
if (pid ==  0)
{
if (execvp(args[0], args) == -1)
{
perror("error in new_process: child process");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("error in new_process: forking");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (-1);
}
