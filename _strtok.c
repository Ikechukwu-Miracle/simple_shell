#include "shell.h"

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
