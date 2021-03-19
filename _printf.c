#include "holberton.h"
#include <stdio.h>
/**
 * _printf - Write output to standard output based on input format
 * @format: String to be printed, may include alternative format specifiers
 *
 * Return: Total number of characters printed
 */
int _printf(const char *format, ...)
{
	int x, bc = 0, count = 0, *f = &bc;
	va_list data_list;
	char *tmp_buf, *BUFF;

	if (format == NULL) /** Is there a string? */
		return (-1);
	va_start(data_list, format);
	if (data_list == NULL) /* Are there arguments */
		return (0);
	BUFF = malloc(1024);
	if (BUFF == NULL)
		return (-1);/* Did we successfully create our buffer? */
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0') /* Check for format specifier */
		{
			format++;
			while (*format == 32)
				format++; /* Move through any spaces after % */
			if (*format == '\0')
			{
				BUFF[bc] = '%';
				break;
			}
			tmp_buf = (*scan_array(format))(data_list); /*Fill tmp*/
			if (tmp_buf == NULL)
			{
				format--;
				flowchecky(f, BUFF);
				BUFF[bc] = *(format);
				bc++, format++, count++;
				flowchecky(f, BUFF);
				BUFF[bc] = *(format);
				bc++, count++;
			}
			else
			{
				for (x = 0; tmp_buf[x] != '\0'; x++, count++, bc++)
				{
					flowchecky(f, BUFF);
					BUFF[bc] = tmp_buf[x]; /** Strcpy */
				}
				free(tmp_buf);
			}
			if (*(format + 1) == '%')
			{
				format++;
				continue;
			}
			else if (*(format + 1) == 00)
				break;
			format++;
		}
		flowchecky(f, BUFF);
		BUFF[bc] = *format;
		count++, bc++, format++;
	}
	write(1, BUFF, bc);
	free(BUFF);
	va_end(data_list);
	return (count);
}

/**
 * flowchecky - function that writes and resets buff when full
 * @f: pointer to flowcheck variable address
 * @BUFF: input buff at max size
 * Return: returns buff reset
 */
char *flowchecky(int *f, char *BUFF)
{
	if (*f >= 1024)
	{
		write(1, BUFF, *f);
		*f = 0;
		free(BUFF);
		BUFF = malloc(1024);
		return (BUFF);
	}
	else
	{
		return (BUFF);
	}
}

/**
 * scan_array - function that selects the corresponding function pointer
 * @format: input string looking for specifier
 * Return: returns function pointer
 */
char *(*scan_array(const char *format))(va_list)
{
	unsigned int i;

	/*
	* Array of structures, format specifiers and corresponding pointer functions
	* that call relevant conversions and print desired string to standard input
	*/
	spec_t specSelect[] = {
	{"%", printPerc}, {"c", printc}, {"s", prints}, {"d", printint},
	{"i", printint}, {"b", printb}, {"u", printu}, {"o", printo}, {"x", printx},
	{"X", printX}, {"S", printS}, {"p", printp}, {NULL, NULL}};


	/* Scan array for function pointer which corresponds to format specifier */
	for (i = 0; specSelect[i].spec != NULL; i++)
	{
		if (*format == specSelect[i].spec[0])
		{
			return (specSelect[i].specFunc);
		}
	}
	return (errorFunc);
}
