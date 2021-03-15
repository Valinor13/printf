#include "holberton.h"

/**
* printPerc - Print the % character to standard output
* @perc: **************************************
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printPerc(va_list perc, int count)
{
	va_arg(perc, int);
	_putchar('%');
	count++;
	return (count);
}

/**
* printc - Print ASCII character to standard output
* @c: pointer to argument of type integer, (ASCII val)
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printc(va_list c, int count)
{
	char cc;

	cc = va_arg(c, int);
	_putchar(cc);
	count++;
	return (count);
}

/**
* prints - Print string literal to standard output
* @s: pointer to argument of type string literal
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int prints(va_list s, int count)
{
	char *ss;

	ss = va_arg(s, char *);
	count = _puts(ss, count);
	return (count);
}

/**
* printint - Conveting integer data to a string
* @d: pointer to argument of type integer
*
* Return: pointer to string
*/
char *printint(va_list d)
{
	char *tmp;
	int i, rem, n, num, len;
	
	n = va_arg(d, int);
	num = n;
	len = 0;
        
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	tmp = malloc(len + 1);
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num /= 10;
		tmp[len - (i + 1)] = (rem + '0');
	}
	tmp[len] = '/0';
	return (tmp);
}




