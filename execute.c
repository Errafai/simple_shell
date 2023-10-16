#include "shell.h"
/**
 * _execute - execute the command of the user
 * @command: the command
 * @argv: the argument of the main
 * @idx: the number of command executed
 * Return: the execute status
 */

int _execute(char **command, char **argv, int idx)
{
	pid_t child;
	int status;
	char *full_path;

	full_path = _getpath(command[0]);
	if (!full_path)
	{
		printerror(argv[0], command[0], idx);
		free_array(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_path, command, environ) == -1)
		{
			free(full_path), full_path = NULL;
			free_array(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(command);
		free(full_path), full_path = NULL;
	}
	return (WEXITSTATUS(status));
}
