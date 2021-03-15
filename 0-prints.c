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

	while (*s != '\0')
	{
		s++;
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
	char *error;

	(void) double_space;

	error = malloc(3);

	error[0] = '0';
	error[1] = '0';
	error[2] = '\0';

	return (error);
}
