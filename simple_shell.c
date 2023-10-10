#include "shell.h"


int main(int ac, char *av[], char **env)
{
	int status;
	int  n_char;
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *cmd;
	char **full_command;
	pid_t pid;

	INUSED(ac);
	INUSED(av);
	while (1)
	{
		write(1, "$ ", 2);
		n_char = getline(&buffer, &buffer_size, stdin);
		if (n_char == -1)
		{
			write(1, "\n", 1);
			free(buffer);
			exit(1);
		}
		full_command = spliter(buffer);
		if (strcmp(full_command[0], "exit") == 0)
		{
			free(buffer);
			exit(0);
		}

		pid = fork();
		if (pid == 0)
		{
			cmd = get_path(full_command[0]);
			if (cmd)
			{
				execve(cmd, full_command, env);
				perror("execve faild");
			}
			else
			{
				perror("command not found");
			}
			free(buffer);
			free(cmd);
			exit(1);
		}
		else if (pid == -1)
			perror("fork failed");
		else
			wait(&status);
		free(full_command);
	}
	return (0);
}

