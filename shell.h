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

#define B_SIZE 1024

extern char **environ;
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
int executecommand(char **cmd, char *actualcmd);
char *check_command(char *command);
char **splitstring(char *str, char *delim, int *numW);
void freeMemory(char **, char *, int);
void handle_builtin(char **buffer, char *line, int no_of_buffer);
void check_exit(char **buf, int no_of_buf);
bool check_builtin(const char *cmd);
int _strcmp(char *s1, char *s2);
void list_env(void);
void _setenv(const char *var_name, const char *value);
void _unsetenv(const char *variable);
int change_dir(char **cmd);
int check_separator(char *line);
void handle_separator(char *line);
void execute_handler(char *buff);
char *_strtok(char *str, const char *delims);
char *_strpbrk(const char *input_str, const char *charset);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(const char *name);
void _puts(char *s);

#endif
