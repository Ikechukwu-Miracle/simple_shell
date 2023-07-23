#include "main.h"

#define MAX_WORD 100

/**
 * splitstring - split a given input string into multiple
 * substrings based on a specified delimiter.
 * @str: pointer to a character array (string)
 * that represents the input string to be split.
 * @delim: pointer to a character array (string) representing
 * the delimiter used for splitting the input string.
 * @numW: pointer to an integer that stores the number
 * of substrings found after splitting.
 *
 * Return: returns a dynamically allocated array of strings
 */
char **splitstring(char *str, char *delim, int *numW)
{
	char **words, *token;

	*numW = 0;

	words = malloc((MAX_WORD + 1) * sizeof(char *));
	if (words == NULL)
	{
		perror("Error");
		return (NULL);
	}

	token = _strtok(str, delim);

	while (token && *numW < MAX_WORD)
	{
		words[*numW] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (words[*numW] == NULL)
		{
			perror("Error");
			return (NULL);
		}

		_strcpy(words[*numW], token);
		(*numW)++;
		token = _strtok(NULL, delim);
	}

	words[*numW] = NULL;

	return (words);
}
