#include "holberton.h"

/**
 * _puts - prints all chars in a string
 * @str: input string
 *
 * Return: returns void
 */
void _puts(char *str)
{
	int i;

	if (str == NULL)
		return;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
return;
}
