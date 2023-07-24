#include "shell.h"

/**
 * main - entry point for interactive
 * and non-interactive mode of the shell programme
 *
 * Return: 0 on success
 */
int main(void)
{
	char *buff = NULL;
	size_t n = 0;
	ssize_t numChar;
	int s_rval;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(STDOUT_FILENO, "Ahmed_Iyke_Shell $ ", 20);
			numChar = _getline(&buff, &n, stdin);
			if (numChar == -1)
			{
				free(buff);
				return (-1);
			}
			if (numChar == 1)
				continue;
			if (buff != NULL && buff[numChar - 1] == '\n')
				buff[numChar - 1] = '\0';
			s_rval = check_separator(buff);
			(s_rval != 0) ? handle_separator(buff) : execute_handler(buff);
		}
	}
	else
	{
		while ((numChar = _getline(&buff, &n, stdin)) != -1)
		{
			if (buff != NULL && buff[numChar - 1] == '\n')
				buff[numChar - 1] = '\0';
			s_rval = check_separator(buff);
			if (s_rval != 0)
				handle_separator(buff);
			else
				execute_handler(buff);
		}
	}
	free(buff);
	return (0);
}


/**
 * execute_handler - handles the calling of the execute command
 * @buff: pointer to comand passed on standard input
 *
 * Return: void
 */
void execute_handler(char *buff)
{
	char **command, *actual_cmd;
	int j, no_of_cmd;

	command = splitstring(buff, " ", &no_of_cmd);

	if (check_builtin(command[0]) == true)
	{
		handle_builtin(command, buff, no_of_cmd);
		for (j = 0; j < no_of_cmd; j++)
			free(command[j]);
		free(command);
	}
	else
	{
		actual_cmd = check_command(command[0]);
		if (actual_cmd == NULL)
		{
			perror("Shell");
			for (j = 0; j < no_of_cmd; j++)
				free(command[j]);
			free(command);
			return;
		}
		executecommand(command, actual_cmd);
		freeMemory(command, actual_cmd, no_of_cmd);
	}
}


/**
 * executecommand - executes command passed into the shell programme
 * @cmd: double pointer parameter
 * @actualcmd: pointer parameter
 *
 * Return: 0 on success
 */
int executecommand(char **cmd, char *actualcmd)
{
	pid_t child;
	int status;

	child = fork();

	if (child < 0)
	{
		perror("Shell");
		return (-1);
	}
	else if (child == 0)
	{
		if (execve(actualcmd, cmd, environ) == -1)
		{
			perror("Shell");
			return (-1);
		}
	}
	else
		wait(&status);
	return (0);
}
