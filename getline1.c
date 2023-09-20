#include "shell.h"



/**
 * create_buffer - function to create buffer
 * @lineptr: double pointer to line
 * @n: number of character
 *
 * Return: result
 */
char *create_buffer(char **lineptr, size_t *n)
{
	*lineptr = malloc(BUFFER_SIZE);
	if (!*lineptr)
		return (NULL);
	*n = BUFFER_SIZE;
	return (*lineptr);
}

/**
 * my_getline - simple implemetation of a getline function
 * @lineptr: double pointer to the line
 * @n: the number of character
 * @fd: the file descriptor
 *
 * Return: the number of character read or -1 on failure
 */

ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
	static char buffer[BUFFER_SIZE];
	static char *p;
	static ssize_t len;
	size_t i = 0;

	if (!lineptr || !n || !create_buffer(lineptr, n))
		return (-1);

	**lineptr = '\0';

	for (;;)
	{
		if (len <= 0)
		{
			len = read(fd, buffer, BUFFER_SIZE);
			if (len < 0)
				return (-1);
			if (len == 0)
				return (**lineptr ? (ssize_t)strlen(*lineptr) : -1);

			p = buffer;
		}

		process_buffer(lineptr, &i, n, &p, &len);
	}
}

/**
 * process_buffer - process buffer
 * @lineptr: allocated memory
 * @n: number of memory
 * @i: append character
 * @p: value character
 * @len: character size
 * Return: 0
 */
void process_buffer(char **lineptr, size_t *i, size_t *n,
char **p, ssize_t *len)
{
	while (*len > 0)
	{
		if (*n <= strlen(*lineptr) + 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (!*lineptr)
				return;
		}
		append_char_to_line(char **i,ssize_t **p, len);
	}
}

/**
 * append_char_to_line - the function appends a character from the buffer
 * @lineptr: allocated memory
 * @i: append character
 * @p: value character
 * @len: character size
 * Return: 0
 */

void append_char_to_line(char **lineptr, char **p, ssize_t *len)
{
	(*lineptr)[strlen(*lineptr) + 1] = '\0';
	(*lineptr)[strlen(*lineptr)] = *(*p)++;
	(*len)--;
}
