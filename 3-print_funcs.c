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
	char *input, *tmp;
	int i;

	input = malloc(17);
	if (input  == NULL)
		return (NULL);
	tmp = va_arg(p, void *);

	for (i = 0; i < 17; i++)
	{
		input[i] = tmp[i];
	}
	input[i] = '\0';
	return (input);
}

/**
* printr - output a string to the standard output
* @r: pointer to argument of type string literal
* @count: existing total number of characters printed
*
* Return: cumulative total number of characters printed
*/

