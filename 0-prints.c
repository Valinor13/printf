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
 * _puts - prints all chars in a string
 * @str: input string
 *
 * Return: returns void
 */
int _puts(char *str, int count)
{
        int i;

        if (str == NULL)
                return (count);

        for (i = 0; str[i] != '\0'; i++)
        {
                _putchar(str[i]);
                count++;
        }
return (count);
}

/**
 * print_number - prints an int
 * @n: input integer
 *
 * Return: returns void
 */
int print_number(int n, int count)
{
	char c = '0';

	if (n < 0)
	{
		if (n % 10 == 0)
		{
			_putchar('-');
			n = (n * -1);
		}

		else
		{
			_putchar('-');
			n++;
			c = '1';
			n = (n * -1);
		}
	}

	if (n / 10 != 0)
	{
		print_number(n / 10, count);
	}

	_putchar(n % 10 + c);
	count++;
return (count);
}
