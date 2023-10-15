#include "shell.h"

char *_getenv(char *name)
{
	int i;
	char *temp, *env, *value, *key;


	for (i = 0; environ[i]; i++)
	{
		temp = strdup(environ[i]);
		key = strtok(temp, "=");
		if (strcmp(key, name) == 0)
		{
			value = strtok(NULL, "\n");
			env = strdup(value);
			free(temp), temp = NULL;
			return (env);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}
