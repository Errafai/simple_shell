#include "main.h"

char *_command(const char *cmd)
{
	char *all_paths  = getenv("PATH");
	char *token;
	char *path;
	struct stat st;

	token = strtok(all_paths, ":");
	while (token != NULL)
	{
		path = malloc(sizeof(token) + sizeof(cmd) + 2);
		strcpy(path, token);
		strcat(path, "/");
		strcat(path, cmd);
		if (stat(path, &st) == 0)
			return(path);
		token = strtok(NULL, ":");
		free(path);
	}
	return (NULL);
}
