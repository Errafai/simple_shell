#include "shell.h"

char **tokniser(char *line)
{
	char *token;
	char **command;
	int i = 0, j = 0;
	char *temp;

	if (!line)
		return (NULL);

	temp = strdup(line);

	token = strtok(temp, " ");
	if (!token)
	{
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, " ");
	}
	free(temp), temp = NULL;

	command = malloc(sizeof(char*) * (i + 1));
	if (command == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, " ");
	while (token)
	{
		command[j] = token;
		token = strtok(NULL, " ");
		j++;
	}
	free(line), line = NULL;
	command[j] = NULL;
	return (command);
}

int main()
{
	char **line = tokniser("i am very good");
	int i;

	for (i = 0; line[i]; i++)
		printf("%s\n", line[i]);
}
