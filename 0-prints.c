#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _strlen - find the length of a string of characters
* @s: a string of characters in an array
*
* Return: the number of characters in input string (minus null val), as integer
*/

int _strlen(char *s)
{
	int x;

	x = 0;

	while (s[x] != '\0')
	{
		x++;
	}

return (x);
}

/**
* errorFunc - Error statement in case of invalid '%' use
* @double_space: no associated variadic argument, void in function
*
* Return: Error statement
*/

char *errorFunc(va_list double_space)
{
	(void) double_space;

	return (NULL);
}

/**
 * print_rev - prints a 2 digit string in reverse
 * @non: input integer
 * Return: returns reverse string pointer
 */
char *print_rev(int non)
{
	int i, j = 0, rem = 0, len;
	char *tmp, *nu_str;

	if (non < 16)
		len = 1;
	else
		len = 2;
	if (non < 16)
	{
		nu_str = malloc(sizeof(char) * 2);
		tmp = malloc(sizeof(char) * 2);
		while (non != 0)
		{
			rem = non % 16;
			if (rem < 10)
				tmp[j] = rem + 48, j++;
			else
				tmp[j] = rem + 55, j++;
			non /= 16;
		}
	}
	else
	{
		nu_str = malloc(sizeof(char) * 3);
		tmp = malloc(sizeof(char) * 3);
		while (non != 0)
		{
			rem = non % 16;
			if (rem < 10)
				tmp[j] = rem + 48, j++;
			else
				tmp[j] = rem + 55, j++;
			non /= 16;
		}
	}
	for (j = 0, i = len - 1; i >= 0; i--, j++)
		nu_str[j] = tmp[i];
	nu_str[len] = 00;
	free(tmp);
return (nu_str);
}

/**
 * _strdup - copies a string into the heap
 * @str: input string
 * Return: returns a pointer or NULL
 */
char *_strdup(char *str)
{
	char *s;
	int i, x;

	if (str == NULL)
	{
		return (NULL);
	}

	x = 1;

	for (i = 0; str[i] != 00; i++)
	{
		x++;
	}

	s = malloc(x * sizeof(char));

	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != 00; i++)
	{
		s[i] = str[i];
	}

return (s);
}
