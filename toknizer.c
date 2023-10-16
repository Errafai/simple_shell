#include "shell.h"
/**
 * tokniser - split the command to array of strings
 * @line: the line of command
 * Return: array of strings
 */
char **tokniser(char *line)
{
	char *token;
	char **command;
	int i = 0, j = 0;
	char *temp;

	if (!line)
		return (NULL);

	temp = strdup(line);

	token = strtok(temp, DELIME);
	if (!token)
	{
		free(line), line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, DELIME);
	}
	free(temp), temp = NULL;

	command = malloc(sizeof(char*) * (i + 1));
	if (command == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIME);
	while (token)
	{
		command[j] = strdup(token);
		token = strtok(NULL, DELIME);
		j++;
	}
	free(line), line = NULL;
	command[j] = NULL;
	return (command);
}
