#include "shell.h"
/**
 * check_command - searches for the absolute path of a given command
 * within the directories listed in the PATH environment variable.
 * @command:  pointer to a null-terminated string representing the
 * command whose existence is to be checked in the directories
 * listed in the PATH and the current directory.
 *
 * Return: returns pointer to the path
 */
char *check_command(char *command)
{
	char *cmdpath, *cmdpath_cpy, *token, *filepath;
	struct stat buff;

	cmdpath = _getenv("PATH");

	if (cmdpath)
	{
		cmdpath_cpy = _strdup(cmdpath);
		token = _strtok(cmdpath_cpy, ":");

		while (token != NULL)
		{
			filepath = malloc(_strlen(cmdpath_cpy) + _strlen(token) + 2);

			_strcpy(filepath, token);
			_strcat(filepath, "/");
			_strcat(filepath, command);

			if (stat(filepath, &buff) == 0)
			{
				free(cmdpath_cpy);
				return(filepath);
			}
			else
			{
				free(filepath);
				token = _strtok(NULL, ":");
			}
		}
		free(cmdpath_cpy);
		if (stat(command, &buff) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}

/**
 * handle_builtin - handles the builtin commands passed to the shell
 * @buffer: vecter array of commands
 * @line: pointer to string 
 * @no_of_buffer: number of commands
 *
 * Return: void
 */
void handle_builtin(char **buffer, char *line, int no_of_buffer)
{
	if (_strcmp(buffer[0], "exit") == 0)
	{
		free(line);
		check_exit(buffer, no_of_buffer);
	}
	else if (_strcmp(buffer[0], "env") == 0)
		list_env();
	else if (_strcmp(buffer[0], "setenv") == 0)
		_setenv(buffer[1], buffer[2]);
	else if (_strcmp(buffer[0], "unsetenv") == 0)
		_unsetenv(buffer[1]);
	else if (_strcmp(buffer[0], "cd") == 0)
		change_dir(buffer);
}

/**
 * check_builtin - checks if command is builtin
 * @cmd: command to check
 *
 * Return: true if builtin, false otherwise
 */
bool check_builtin(const char *cmd)
{
	const char *keywords[] = {"exit", "env", "cd", "setenv", "unsetenv"};
	int i, no_of_keyword = sizeof(keywords)/sizeof(keywords[0]);

	for (i = 0; i < no_of_keyword; i++)
	{
		if (_strcmp(cmd, keywords[i]) == 0)
			return (true);
	}
	return (false);
}
