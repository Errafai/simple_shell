#include "shell.h"
/**
 * read_line - read the command of the user
 * Return: the command line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);

}
