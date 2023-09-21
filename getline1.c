#include "shell.h"


/**
 * my_getline - simple implemetation of a getline function
 *
 * Return: the number of character read or -1 on failure
 */

char *my_getline(void)
{
	char buffer[BUFFER_SIZE];
	char *line = NULL;
	size_t len = 0;

	while (fgets(buffer, BUFFER_SIZE, stdin))
	{
		size_t buflen = strlen(buffer);

		char *new_line = realloc(line, len + buflen + 1);

		if (!new_line)
		{
			free(line);
			return (NULL);
		}

		line = new_line;

		memcpy(line + len, buffer, buflen);
		len += buflen;

		if (buffer[buflen - 1] == '\n')
		{
			line[len] = '\0';
			return (line);
		}
	}
	if (!len)
	{
		free(line);
		return (NULL);
	}

	line[len] = '\0';
	return (line);
}
