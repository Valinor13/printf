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
* printd - Print to standard output
* @d: pointer to argument of type integer
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printd(va_list d, int count)
{
	int x;

	x = va_arg(d, int);
	count = print_number(x, count);
	return (count);
}

/**
* printi - Print integer to standard output
* @i: pointer to argument of type integer
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printi(va_list i, int count)
{
	int x;

	x = va_arg(i, int);
	count = print_number(x, count);
	return (count);
}
