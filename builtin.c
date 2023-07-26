#include "shell.h"

/**
 * check_exit - handles exit
 * @buf: array of pointers to command passed to shell
 * @no_of_buf: holds number of commands
 *
 * Return: nothing
 */
void check_exit(char **buf, int no_of_buf)
{
	int status = 0;
	int i;

	if (buf[1] != NULL)
		status = atoi(buf[1]);

	for (i = 0; i < no_of_buf; i++)
		free(buf[i]);
	free(buf);

	exit(status);
}

/**
 * list_env - prints out the environment variable
 *
 * Return: nothing
 */
void list_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		i++;
	}
}

/**
 * _setenv - sets environment variable
 * @var_name: points to variable name
 * @value: points to value of variable
 *
 * Return: nothing
 */
void _setenv(const char *var_name, const char *value)
{
	int r_val;

	if (var_name == NULL || value == NULL)
		write(STDERR_FILENO, "Usage: setenv VARIABLE_NAME VALUE\n", 30);

	r_val = setenv(var_name, value, 1);

	if (r_val == -1)
		write(STDERR_FILENO, "Failed to set environment variable\n", 30);
}

/**
 * _unsetenv - removes an environment variable
 * @variable: pointer to name of variable
 *
 * Return: nothing
 */
void _unsetenv(const char *variable)
{
	char **currVar, **nextVar;
	int successful = 0;
	size_t varLen;

	varLen = _strlen(variable);
	currVar = environ;

	for (; currVar != NULL; ++currVar)
	{
		if ((_strncmp(variable, *currVar, varLen) == 0)
				&& ((*currVar)[varLen] == '='))
		{
			nextVar = currVar;

			while (*(nextVar + 1) != NULL)
			{
				*nextVar = *(nextVar + 1);
				++nextVar;
			}
			*nextVar = NULL;
			successful = 1;
			break;
		}
	}

	if (!successful)
		write(STDERR_FILENO, "Environment variable not found\n", 30);
}

/**
 * change_dir - changes the current directory of the shell
 * @cmd: array of pointers to command passed to the shell
 *
 * Return: 0 o success, -1 on failure
 */
int change_dir(char **cmd)
{
	char *s, *dir, buff[1024];
	int chdir_rval;

	s = getcwd(buff, 1024);
	if (s == NULL)
	{
		perror("Shell");
		return (-1);
	}
	if (cmd[1] == NULL)
	{
		dir = _getenv("HOME");
		if (!dir)
			chdir_rval = chdir((dir = _getenv("PWD")) ? dir : "/");
		else
			chdir_rval = chdir(dir);
	}
	else if (_strcmp(cmd[1], "-") == 0)
	{
		if (_getenv("OLDPWD") == NULL)
		{
			perror("Shell");
			return (-1);
		}
		chdir_rval = chdir((dir = _getenv("OLDPWD")) ? dir : "/");
	}
	else
		chdir_rval = chdir(cmd[1]);
	if (chdir_rval == -1)
	{
		perror("Shell");
		return (-1);
	}
	else
	{
		_setenv("OLDPWD", _getenv("PWD"));
		_setenv("PWD", getcwd(buff, 1024));
	}
	return (0);
}
