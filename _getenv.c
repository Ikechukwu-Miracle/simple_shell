#include "shell.h"

/**
 * _getenv - returns the value of an environment variable
 * @name: pointer to the name of the environment variable
 *
 * Return: value of environment variable or NULL if not successful
 */
char *_getenv(const char *name)
{
	size_t nameLen;
	char **env;

	if (name == NULL || name[0] == '\0')
		return (NULL);

	nameLen = _strlen(name);
	env = environ;

	for (; *env != NULL; ++env)
	{
		if ((_strncmp(*env, name, nameLen)) == 0
				&& ((*env)[nameLen] == '='))
			return (*env + nameLen + 1);
	}
	return (NULL);
}
