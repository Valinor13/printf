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
	(void)u;
	printf("printb");
	print_number(count, count);
	printf("%d\n", count);
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

/**
* printS - output a string with non-printable characters to standard output
* @S: pointer to argument of type string literal
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printS(va_list S, int count)
{
	(void)S;
	(void)count;
	printf("printS");
	return (count);
}

/**
* printp - output a pointer data type to the standard output
* @p: pointer to argument of type pointer
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printp(va_list p, int count)
{
	(void)p;
	(void)count;
	printf("printp");
	return (count);
}

/**
* printr - output a string to the standard output
* @r: pointer to argument of type string literal
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/
int printr(va_list r, int count)
{
	(void)r;
	(void)count;
	printf("printr");
	return (count);
}

