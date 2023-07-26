#include "shell.h"
#include <stddef.h>
/**
 * _strcpy - copies string
 * @dest: destination
 * @src: source
 * Return: copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[i] = src[i];
	*(dest + i) = '\0';

	return (dest);
}

/**
 * _strlen -  returns the length of a string.
 * @s: integer
 *
 * Return: returns the length
 */
int _strlen(const char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: returns 0 if both strings are equal
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] < s2[i])
			return (-s2[i]);
		else if (s1[i] > s2[i])
			return (s1[i]);
	}
	return (0);
}

/**
 * _puts - prints a given string with newline
 * @str: the string to be printed
 * Return: nothing
 */

void _puts(char *str)
{
	int x;

	for (x = 0 ; str[x] != '\0' ; x++)
	{
		_putchar(str[x]);
	}
	_putchar('\n');
}

/**
 * _strncmp - compares the first n characters of two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 * @n: number of characters to compare
 *
 * Return: 0 on success
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	if (s1[i] == '\0')
		return (0);

	return (0);
}
