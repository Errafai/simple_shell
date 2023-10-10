#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void* _realloc(char *oldptr, int old_size, int new_size)
{
	char *newptr;
	unsigned int i;

	if (new_size == 0 && oldptr != NULL)
	{
		free(oldptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (oldptr);

	if (oldptr == NULL)
	{
		newptr = malloc(new_size);
		if (newptr == NULL)
			return (NULL);
		return (newptr);
	}


	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);
	for (i = 0; i < new_size && i < old_size; i++)
		newptr[i] = oldptr[i];

	free(oldptr);
	return (newptr);
}


ssize_t _getline(char **line, size_t *n, int fd)
{
	size_t r_bytes = 0;
	int i = 0;
	char buffer[1];

	if (fd == -1)
		return (-1);

	if (*line == NULL || *n == 0)
	{
		*n = 128;

		*line = (char*)malloc(*n);

		if (*line == NULL)
			return (-1);
	}

	while(r_bytes = read(fd, buffer, 1) > 0)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			*line = _realloc(*line, i, *n);
				if (*line == NULL)
					return (-1);
		}
		(*line)[i++] = buffer[0];
		if (buffer[0] == '\n')
			break;
	}

	(*line)[i] = '\0';
	if (r_bytes <= 0)
	{
		free(*line);
		*line == NULL;
		return (-1);
	}

	return (i);
}
