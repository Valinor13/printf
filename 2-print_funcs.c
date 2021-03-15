#include "holberton.h"

/**
* printb - Convert unsigned int to binary, output result to standard output
* @b: pointer to argument of type unsigned integer
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printb(va_list b, int count)
{
	(void)b;
	/** Convert va_args(b, int) into binary */
	printf("printb");
	print_number(count, count);
	return (count);
}

/**
* printu - output an unsigned integer to standard output
* @u: pointer to argument of type unsigned integer
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printu(va_list u, int count)
{
	count = print_un_number(va_arg(u, unsigned int), count);
	return (count);
}

/**
* printo - output an unsigned integer to standard output
* @o: pointer to argument of type unsigned integer
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printo(va_list o, int count)
{
	(void)o;
	(void)count;
	printf("printo");
	return (count);
}

/**
* printx - output an unsigned integer to standard output
* @x: pointer to argument of type unsigned integer
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printx(va_list x, int count)
{
	(void)x;
	(void)count;
	printf("printx");
	return (count);
}

/**
* printX - output an unsigned integer to standard output
* @X: pointer to argument of type unsigned integer
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printX(va_list X, int count)
{
	(void)X;
	(void)count;
	printf("printX");
	return (count);
}

