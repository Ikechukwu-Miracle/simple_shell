#include "shell.h"

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
