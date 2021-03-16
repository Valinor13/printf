#include "holberton.h"

/**
* printS - Store string in memory, interpret nonprintable characters in Hex
* @S: pointer to argument of type string literal
*
* Return: pointer to an array in memory
*/
char *printS(va_list S)
{
	char *str, *tmpstr;
	int i, j, rem, non;

	tmpstr = va_arg(S, char *);
	i = j = 0;
	str = malloc((_strlen(tmpstr) * 4) + 1);
	if (str == NULL)
		return (NULL);
	while (tmpstr[j] != '\0')
	{
		if (tmpstr[j] >= 33) /** ASCII <32 are 'non-printable' characters */
		{
			str[i] = tmpstr[j];
			i++, j++;
		}
		else
		{
			str[i] = '\\', i++;
			str[i] = 'x', i++;
			non = tmpstr[j];
		if (non < 16)
		{
			str[i] = '0', i++;
		}
		while (non != 0)
		{
		rem = non % 16;
		if (rem < 10)
		{
			str[i] = rem + 48, i++;
		}
		else
			str[i] = rem + 55, i++;

		non /= 16;
		}
		j++;
		}
	}
	return (str);
}

/**
* printp - Cast input pointer to a string, copy into primary buffer
* @p: pointer to argument of type pointer
*
* Return: pointer to an array in memory
*/
char *printp(va_list p)
{
	char *hexa_tmp, *outbuff;
	int i, rem, j, y;
	unsigned long int u;

	u = va_arg(p, unsigned long int);
	i = 2;
	y = 2;
	hexa_tmp = malloc(sizeof(char) * 16);
	outbuff = malloc(sizeof(char) * 16);

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
			hexa_tmp[i] = rem + 87;
			i++;
		}
		u /= 16;
	}
	outbuff[0] = '0';
	outbuff[1] = 'x';
	for (j = i - 1; j >= 0; j--, y++)
	{
		outbuff[y] = hexa_tmp[j];
	}
	outbuff[i] = '\0';
	free(hexa_tmp);
	return (outbuff);
}

