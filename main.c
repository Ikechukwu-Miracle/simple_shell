#include "shell.h"

int main(void)
{
	char *buff = NULL;
	size_t n = 0;
	int s_rval;
	size_t numChar;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(STDOUT_FILENO, "Shell $ ", 9);
		}
	}
}
