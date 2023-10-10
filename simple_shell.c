#include "main.h"

char **spliter(char *command)
{
	char **array;
	int i = 1;

	array = malloc(sizeof(char*) * 1024);
	if (array == NULL)
	{
		perror("malloc faild");
		exit(1);
	}
	array[0] = strtok(command, " \n\t");
	while (command)
	{
		array[i] = strtok(NULL, " \n\t");
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
	char *token;
	char **full_command;
	pid_t pid;

	while (1)
	{
		write(1, "$ ", 2);
		n_char = _getline(&buffer, &buffer_size, 0);
		token = _command(buffer);
		full_command = spliter(token);
		pid = fork();
		if (pid == 0)
		{
			if (execve(full_command[0], full_command, env) == -1)
				perror("execve");
		}
		else
			wait(&status);
		i = 0;
		free(full_command);
	}
}
