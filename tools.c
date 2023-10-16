#include "shell.h"
/**
 * free_array - free the command array
 * @array: the array of stings
 */
void free_array(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i]; i++)
		free(array[i]), array[i] = NULL;
	free(array), array = NULL;
}
/**
 * printerror - print the error if the command dont exist
 * @name: the name of command
 * @cmd: the command
 * @idx: the number of command
 */
void printerror(char *name, char *cmd, int idx)
{
	char mssg[] = ": not found\n";
	int i = 0, j;
	char buffer[20];
	/*index = _itoa(idx);*/

	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	 if (idx == 0)
		write(STDERR_FILENO, "0", 1);
	 else
	 {
		 while (idx > 0)
		 {
			 buffer[i++] = (idx % 10) + '0';
			 idx /= 10;
		 }
		 for (j = i - 1; j >= 0; j--)
		 {
			 char ch = buffer[j];

			 write(STDERR_FILENO, &ch, 1);
		 }
	 }
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, mssg, strlen(mssg));
}
