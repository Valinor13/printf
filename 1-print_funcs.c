#include "holberton.h"

int printPerc(va_list perc, int count)
{
	va_arg(perc, int);
	_putchar('%');
	count++;
	return (count);
}

int printc(va_list c, int count)
{
	char cc;

	cc = va_arg(c, int);
	_putchar(cc);
	count++;
	return (count);
}

int prints(va_list s, int count)
{
	char *ss;

	ss = va_arg(s, char *);
	count = count + _puts(ss, count);
	return (count);
}

int printd(va_list d, int count)
{
	int x;

	x = va_arg(d, int);
	count = count + print_number(x, count);
	return (count);
}

int printi(va_list i, int count)
{
	int x;

	x = va_arg(i, int);
	count = count + print_number(x, count);
	return (count);
}
