#include "holberton.h"

/**
* printb - Convert unsigned int to binary, store in an array in memory
* @b: pointer to argument of type unsigned integer
*
* Return: pointer to an array in memory
*/
char *printb(va_list b)
{
	unsigned int n, cvt;
	int i, rem, j, y;
	char *bi_tmp, *outbuff;

	n = va_arg(b, unsigned int);
	i = y =  0;

	bi_tmp = malloc(33);
	outbuff = malloc(33);
	if (bi_tmp == NULL || outbuff == NULL)
	{
		return (NULL);
	}

	while (n != 0)
	{
		rem = n % 2;
		bi_tmp[i] = rem;
		n /= 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--, y++)
	{
		outbuff[y] = bi_tmp[j];
	}
	outbuff[i] = '\0';
	free(bi_tmp);
	/** Storing in an array because all 1s exceeds unsigned int max */
	return (outbuff);
}

/**
* printu - Store an unsigned integer as an array in memory
* @u: pointer to argument of type unsigned integer
*
* Return: pointer to an array in memory
*/
char *printu(va_list u)
{
	return (printu_alt(va_arg(u, unsigned int)));
}

/**
* printo - Convert unsigned integer argument to octal, store in array in memory
* @o: pointer to argument of type unsigned integer
*
* Return: pointer to an array in memory
*/
char *printo(va_list o)
{
	unsigned int un, oct;
	int i;

	oct = 0;
	i = 1;
	un = va_arg(o, unsigned int);
	/** Convert unsigned integer argument into octal number */
	while (un != 0)
	{
		oct += (un % 8) * i;
		un /= 8;
		i *= 10;
	}
	/** Pass unsigned octal into printualt and return the char * into primary */
	return (printu_alt(oct));
}

/**
* printx - Convert an unsigned integer to hexadecimal (lower),
*	store in an array in memory
* @x: pointer to argument of type unsigned integer
*
* Return: pointer to an array in memory
*/
char *printx(va_list x)
{
	char *hexa_tmp, outbuff;
	int i, rem, j, y;
	unsigned int u;

	u = va_arg(x, unsigned int);
	i = y = 0;
	hexa_tmp = malloc(9);
	outbuff = malloc(9);

	if (hexa_tmp == NULL || outbuff == NULL)
	{
		return (NULL);
	}
	while (u != 0)
	{
		rem = u % 16;
		if (rem < 10)
		{
			hexa_tmp[i] = rem + 48;
			i++;
		}
		else
		{
			hexa_tmp[i] = temp + 87;
			i++;
		}
		n /= 16;
	}
	for (j = i - 1; j >= 0; j--, y++)
	{
		outbuff[y] = hexa_tmp[j];
	}
	outbuff[i] = '\0';
	free(hexa_tmp);
	return (outbuff);
}

/**
* printX - Convert an unsigned integer to hexadecimal (upper), store in
*	an array in memory
* @X: pointer to argument of type unsigned integer
*
* Return: pointer to an array in memory
*/
char *printX(va_list X)
{
	char *hexa_tmp, outbuff;
	int i, rem, j, y;
	unsigned int u;

	u = va_arg(X, unsigned int);
	i = y = 0;
	hexa_tmp = malloc(9);
	outbuff = malloc(9);
	if (hexa_tmp == NULL || outbuff == NULL)
	{
		return (NULL);
	}
	while (u != 0)
	{
		rem = u % 16;
		if (rem < 10)
		{
			hexa_tmp[i] = rem + 48;
			i++;
		}
		else
		{
			hexa_tmp[i] = temp + 55;
			i++;
		}
		n /= 16;
	}
	for (j = i - 1; j >= 0; j--, y++)
	{
	outbuff[y] = hexa_tmp[j];
	}
	outbuff[i] = '\0';
	free(hexa_tmp);
	return (outbuff);
}

