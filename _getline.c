#include "shell.h"

static ssize_t read_buffer(char *buffer, ssize_t size, FILE *stream);
static ssize_t append_character(char **lineptr,
		                ssize_t *length, size_t *capacity, char character);
/**
 * _getline - reads a line from a file stream
 * @lineptr: stores the line read
 * @n: size of buffer
 * @stream: where the line is read from
 * Return: number of characters read on success,
 * (-1) on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char curr_char;
	ssize_t result;
	static char buffer[B_SIZE];
	static ssize_t buffer_size, buffer_index;
	ssize_t line_length = 0;

	if (*lineptr == NULL || *n == 0)
	{
		*n = B_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			buffer_size = read_buffer(buffer, B_SIZE, stream);
			buffer_index = 0;
			if (buffer_size <= 0)
			{
				if (line_length == 0)
					return (-1);
				(*lineptr)[line_length] = '\0';
				return (line_length);
			}
		}
		curr_char = buffer[buffer_index++];
		result = append_character(lineptr, &line_length, n, curr_char);
		if (result == -1)
			return (-1);

		if (curr_char == '\n')
		{
			(*lineptr)[line_length] = '\0';
			return (line_length);
		}
	}

	free(*lineptr);
	return (-1);
}

/**
 * read_buffer - reads data from the specified stream
 * into the provided buffer
 * @buffer: pointer to buffer to store the read data
 * @size: the maximum number of bytes to read
 * @stream: pointer to sream to read from
 * Return: number of bytes read or -1 on failure
 */
static ssize_t read_buffer(char *buffer, ssize_t size, FILE *stream)
{
	return (read(fileno(stream), buffer, size));
}

/**
 * append_character - appends a character to string
 * @lineptr: pointer to the line buffer
 * @length: pointer to the current length of the line buffer
 * @capacity: pointer to current capacity
 * @character: the character to append
 * Return: 0 on success, -1 on memory allocation
 */
static ssize_t append_character(char **lineptr,
		ssize_t *length, size_t *capacity, char character)
{
	char *new_line;

	(*lineptr)[*length] = character;
	(*length)++;

	if ((size_t)(*length) >= *capacity)
	{
		*capacity *= 2;
		new_line = realloc(*lineptr, *capacity);
		if (new_line == NULL)
			return (-1);
		*lineptr = new_line;
	}

	return (0);
}
