#include "holberton.h"

/**
* printPerc - Store the % sign character in an array in memory
* @perc:unused, argument list
*
* Return: pointer to two bits in memory, holds '%' and null byte
*/
char *printPerc(va_list perc)
{
	char *str;
	(void) perc;

	str = malloc(2);
	if (str == NULL)
	{
		return (NULL);
	}
	str[0] = '%';
	str[1] = '\0';
	return (str);
}

/**
* printc - Convert ASCII value to character, store in an array in memory
* @c: pointer to argument of type integer, (ASCII val)
*
* Return: pointer to two bits in memory, holds char and null byte
*/
char *printc(va_list c)
{
	char *str;
	char chr;

	chr = va_arg(c, int);
	str = malloc(2);
	if (str == NULL)
	{
		return (NULL);
	}
	str[0] = chr;
	str[1] = '\0';
	return (str);
}

/**
* prints - Copy string literal argument to allocated memory
* @s: pointer to argument of type string literal
*
* Return: pointer to string in memory
*/
char *prints(va_list s)
{
	char *str, *tmpstr;
	int n;

	tmpstr = va_arg(s, char *);
	str = malloc(_strlen(tmpstr) + 1);
	if  (str == NULL)
	{
		return (NULL);
	}

	for (n = 0; n <= _strlen(tmpstr); n++)
	{
		str[n] = tmpstr[n];
	}

	return (str);
}

/**
* printint - Conveting integer data to a string
* @d: pointer to argument of type integer
*
* Return: pointer to string of numeric characters
*/
char *printint(va_list d)
{
	char *tmp;
	int i, rem, n, num, len, x;
/*
 * iterator, last digit, initial integer, copy of initial integer,
 * length of input, length for negatives
 */

	n = va_arg(d, int);
	num = n;
	len = i = 0;

	while (n != 0)	/** Integer length */
	{
		len++;
		n /= 10;
	}
	x = len;
	if (num == 0) /** Zero case */
	{
		tmp = malloc(2);
		tmp[0] = '0';
	}
	else if (num < 0) /** Negative case */
	{
		x++; /** Account for dash indicator */
		tmp = malloc(len + 2); /** Dash indicator and null byte */
		tmp[0] = '-';
		num *= -1;
	}
	else /** Positive case */
		tmp = malloc(len + 1);

	for (; i < len; i++)
	{
		rem = num % 10; /** Isolate last digt */
		num /= 10; /** Shorten integer */
		tmp[x - (i + 1)] = (rem + '0'); /** Fill, right to left */
	}
	tmp[x] = '\0';
	return (tmp);
}

/**
 * printu_alt - store an unsigned integer as an array in memory
 * @u: pointer to argument of type unsigned integer
 *
 * Return: pointer to an array in memory
 */
char *printu_alt(unsigned int u)
{
	char *tmp;
	unsigned int n, num;
	int i, rem, len;
/** iterator, last digit, initial int, initial integer copy, input length */

	n = u;
	num = n;
	len = 0;

	while (n != 0)  /** Integer length */
	{
		len++;
		n /= 10;
	}
	if (num == 0) /** Zero case */
	{
		tmp = malloc(2);
		tmp[0] = '0';
	}
	else /** Positive case */
	{
		tmp = malloc(len + 1);
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10; /** Isolate last digt */
		num /= 10; /** Shorten integer */
		tmp[len - (i + 1)] = (rem + '0'); /** Fill, right to left */
	}
	tmp[len] = '\0';
return (tmp);
}
