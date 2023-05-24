#include "shell.h"

/**
 * _getline - custom get_line function
 * @lineptr: pointer to line string
 * @n: size
 * @stream: steam file
 * Return: number of readed character
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer, *new_buffer;
	size_t buffer_size, new_size;
	ssize_t length;
	int c;
	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL || *n < INITIAL_BUFFER_SIZE)
	{
		*lineptr = (char *)malloc(INITIAL_BUFFER_SIZE * sizeof(char));
		*n = INITIAL_BUFFER_SIZE;
	}


	buffer = *lineptr;
	buffer_size = *n;
	length = 0;

	while ((c = fgetc(stream)) != EOF)
	{
		if (length >= (ssize_t) buffer_size - 1)
		{
			new_size = buffer_size * GROWTH_FACTOR;
			new_buffer = (char *)realloc(buffer, new_size * sizeof(char));

			if (new_buffer == NULL)
				return (-1);
			buffer = new_buffer;
			buffer_size = new_size;
			*lineptr = buffer;
			*n = buffer_size;
		}

		buffer[length++] = (char)c;
		if (c == '\n')
			break;
	}
	if (length == 0)
		return (-1);

	buffer[length] = '\0';
	return (length);
}