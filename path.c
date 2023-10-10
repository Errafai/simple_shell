#include "main.h"

char *_command(const char *cmd)
{
	int n;
	char *all_paths  = getenv("PATH");
	char *token;
	char *path;
	struct stat st;

	token = strtok(all_paths, ":");
	n = sizeof(token) + sizeof(cmd) + 2;
	while (token != NULL)
	{
		path = malloc(n);
		strcpy(path, token);
		strcat(path, "/");
		strcat(path, cmd);
		if (stat(path, &st) == 0)
			return(path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
