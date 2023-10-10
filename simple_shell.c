#include "main.h"

char **spliter(char *command)
{
	char *token;
	char **array;
	int i = 0;

	array = malloc(sizeof(char*) * 1024);
	if (array == NULL)
	{
		perror("malloc faild");
		return (NULL);
	}
	token = strtok(command, " \n\t");
	while (command)
	{
		array[i] = strtok(NULL, " \n\t");
		token = strtok(NULL, " \n\t");
		i++;
	}
	array[i] = NULL;
	return (array);
}

int main(int ac, char *av[], char **env)
{
	int status, i = 0, n_char;
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *cmd;
	char **full_command;
	pid_t pid;

	while (1)
	{
		write(1, "$ ", 2);
		n_char = _getline(&buffer, &buffer_size, 0);
		if (n_char == -1)
		{
			write(1, "\n", 1);
			exit(1);
		}
		full_command = spliter(buffer);
		if (strcmp(full_command[0], "exit") == 0)
			exit(0);

		pid = fork();
		if (pid == 0)
		{
			cmd = _command(full_command[0]);
			if (cmd)
				execve(cmd, full_command, env);
			else
				perror("command not found");
			exit(0);
		}
		else
			wait(&status);
	}
	return (0);
}
