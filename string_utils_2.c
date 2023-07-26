#include "shell.h"

/**
 * _strdup - duplicates a string
 * @source: string to duplicate
 *
 * Return: returns a pointer to the duplicate string
 */
char *_strdup(char *source)
{
	size_t len;
	char *destination;

	if (source == NULL)
		return (NULL);

	len = _strlen(source) + 1;
	destination = (char *)malloc(len);

	if (destination != NULL)
		_strcpy(destination, source);

	return (destination);
}

/**
 * _strcat - appends a string to another
 * @dest: the string to be appended to
 * @src: the string that is appended
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strpbrk - finds the first occurrence of any character
 * from a given string.
 * @input_str: pointer to string
 * @charset: pointer to characters to match
 *
 * Return: pointer to character in string
 */
char *_strpbrk(const char *input_str, const char *charset)
{
	const char *c;

	while (*input_str)
	{
		c = charset;
		while (*c)
		{
			if (*input_str == *c)
				return ((char *)input_str);
			c++;
		}
		input_str++;
	}

	return (NULL);
}

/**
 * _strtok - splits strings into tokens
 * @str: pointer to string to tokenize
 * @delims: delimeters
 *
 * Return: pointer to token
 */
char *_strtok(char *str, const char *delims)
{
	static char *nxtToken;
	char *start_token, *delims_position;

	if (str != NULL)
		nxtToken = str;
	if (nxtToken == NULL)
		return (NULL);

	start_token = nxtToken;
	delims_position = _strpbrk(nxtToken, delims);

	if (delims_position != NULL)
	{
		*delims_position = '\0';
		nxtToken = delims_position + 1;
	}
	else
		nxtToken = NULL;

	if (start_token[0] == '\0')
		return (_strtok(NULL, delims));

	return (start_token);
}
