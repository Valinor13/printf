#include "holberton.h"

/**
* printS - Store string in memory, interpret nonprintable characters in Hex
* @S: pointer to argument of type string literal
*
* Return: pointer to an array in memory
*/
char *printS(va_list S)
{
	char *str, *tmpstr, *hex_str;
	int i, j, k, non;

	tmpstr = va_arg(S, char *);
	i = j = k = 0;
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
			hex_str = print_rev(non);
			for (k = 0; hex_str[k] != '\0'; k++)
			{
				str[i] = hex_str[k];
				i++;
			}
			j++;
			free(hex_str);
		}
	}
	str[i] = 00;
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

/**
 * printr - prints a string in reverse
 * @r: input argument string
 * Return: returns allocated string in reverse
 */
char *printr(va_list r)
{
	char *str, *tmpstr, *dup;
	int n, len, i;

	dup = "(null)";

	tmpstr = va_arg(r, char *);
	if (tmpstr == NULL)
	{
		return (_strdup(dup));
	}
	len = _strlen(tmpstr);
	str = malloc(len + 1);
	if  (str == NULL)
	{
		return (NULL);
	}

	for (n = 0, i = len - 1; n < len; n++, i--)
	{
		str[n] = tmpstr[i];
	}
	str[len] = 00;

	return (str);
}

/**
 * printR - prints a string in rot13
 * @R: input string
 * Return: returns allocated string in Rot13 encryption
 */
char *printR(va_list R)
{
	int i, x, len;
	char *j = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *z = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *rot, *dup, *nurot;

	dup = "(null)";
	rot = va_arg(R, char *);
	if (rot == NULL)
	{
		return (_strdup(dup));
	}
	len = _strlen(rot);
	nurot = malloc(len + 1);
	if (nurot == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		x = 0;

		if ((rot[i] >= 65 && rot[i] <= 90) || (rot[i] >= 97 && rot[i] <= 122))
		{
			while (rot[i] != j[x])
			{
				x++;
			}
			nurot[i] = z[x];
		}
		else
			nurot[i] = rot[i];
	}

return (nurot);
}
