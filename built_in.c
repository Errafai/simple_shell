#include "shell.h"
/**
 * built_in - check if the built in exit
 * @command: the command
 * Return: 1 or 0
 */
int built_in(char *command)
{
	char *builtin[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtin[i]; i++)
	{
		if (strcmp(command, builtin[i]) == 0)
			return (1);
	}

	return (0);
}

/**
  * handle_builtin - handle the built-in to be exute
  * @command: the command
  * @argv: the argment of the main
  * @status: the status of the exit
  * @idx: the number of command executed
  */

void handle_builtin(char **command, char **argv, int *status, int idx)
{
	(void) argv;
	(void) idx;

	if (strcmp(command[0], "exit") == 0)
		exit_shell(command, status);
	else if (strcmp(command[0], "env") == 0)
		print_env(command, status);
}
/**
 * exit_shell - exit from shell
 * @command: the command
 * @status: the status of the exit
 */
void exit_shell(char **command, int *status)
{
	free_array(command);
	exit(*status);
}
/**
 * print_env - print the envirment variable component
 * @command: the command
 * @status: the exit status
 */
void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_array(command), command = NULL;
	*status = 0;
}
