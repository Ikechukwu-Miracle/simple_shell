#include "shell.h"

/**
 * check_separator - checks the standard input for a command separator
 * @line: parameter to check
 *
 * Return: returns an integer
 */
int check_separator(char *line)
{
	int i, count = 0;

	for (i = 0 ; line[i] != '\0' ; i++)
	{
		if (line[i] == ';')
			count++;
	}
	if (count == 0)
		return (0);
	else
		return (count);
}


/**
 * handle_separator -process a line of input containing
 * multiple commands separated by semicolons (';').
 * @line:  A pointer to a character array (string) that
 * contains the input line with multiple commands
 *
 * Return: void
 */
void handle_separator(char *line)
{
	char **commandlist;
	int i, j, numcmd = 0;

	commandlist = splitstring(line, ";", &numcmd);

	i = 0;
	while (commandlist[i] != NULL)
	{
		execute_handler(commandlist[i]);
		i++;
	}
	for (j = 0; j < numcmd; j++)
		free(commandlist[j]);
	free(commandlist);

	/*return;*/
}
