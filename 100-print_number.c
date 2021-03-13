#include "holberton.h"

/**
 * print_number - prints an int
 * @n: input integer
 *
 * Return: returns void
 */
void print_number(int n)
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
		print_number(n / 10);

	_putchar(n % 10 + c);
return;
}
