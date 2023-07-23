#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

extern char **environ;

char *check_command(char *command);
char **splitstring(char *str, char *delim, int *numW);
void freeMemory(char **, char *, int);
void handle_builtin(char **buffer, char *line, int no_of_buffer);
void check_exit(char **buf, int no_of_buf);
bool check_builtin(const char *cmd);
void list_env(void);
void _setenv(const char *var_name, const char *value);
void _unsetenv(const char *variable);
int change_dir(char **cmd);
int check_separator(char *line);
void handle_separator(char *line, int count);
void execute_handler(char *buff);

#endif
