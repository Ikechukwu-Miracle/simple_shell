#include "shell.h"
/**
 * freeMemory - frees allocated memory
 * @vec: array of vectors
 * @cmd: command
 * @no_of_vec: no of commands
 *
 * Return: void
 */
void freeMemory(char **vec, char *cmd, int no_of_vec)
{
	int i;

	if (_strcmp(vec[0], cmd) == 0)
	{
		for (i = 0 ; i < no_of_vec ; i++)
			free(vec[i]);
		free(vec);
	}
	else
	{
		free(cmd);
		for (i = 0 ; i < no_of_vec ; i++)
			free(vec[i]);
		free(vec);
	}
}
