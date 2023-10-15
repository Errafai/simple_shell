#include "shell.h"

int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, idx = 0;
	(void) ac;


	while (1)
	{
		line = read_line();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;
		command = tokniser(line);
		if (!command)
			continue;
		if (built_in(command[0]))
			handle_builtin(command, argv, &status, idx);
		status = _execute(command, argv, idx);

	}
}
