#include "holberton.h"

/**
 * _printf - Write output to standard output based on input format
 * @format: String to be printed, may include alternative format specifiers
 *
 * Return: Total number of characters printed
 */
int _printf(const char *format, ...)
{
	int x, flowchk, count;
	int *f;
	va_list data_list;
	char *tmp_buf, *BUFF;

	count = 0; /** Total number of characters writter */
	flowchk = 0; /** Buffer overflow prevention measure */
	f = &flowchk;

	if (format == NULL || *format == 00) /* NULL check, pointer and string */
		return (-1);

	va_start(data_list, format);
	BUFF = malloc(1024);
	if (BUFF == NULL)
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%') /** Check for format specifier */
		{
			format++;
			if (*format == '\0')
				return (-1);
			tmp_buf = (*scan_array(format))(data_list); /*Fill tmp*/
			format++; /* FLAG CODE */
			for (x = 0; x < _strlen(tmp_buf); x++, count++, flowchk++)
			{
				if (flowchk == 1024) /** Buffer empty */
					BUFF = flowchecky(f, BUFF);
				BUFF[flowchk] = tmp_buf[x]; /** Strcpy */
			}
			free(tmp_buf);
		}
		if (flowchk == 1024) /** Buffer empty */
			BUFF = flowchecky(f, BUFF);
		BUFF[flowchk] = *format; /** Pass input string to primary buffer */
		count++, flowchk++, format++;
	}
	write(1, BUFF, flowchk);
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
		write(1, BUFF, *f);
		*f = 0;
		free(BUFF);
		BUFF = malloc(1024);
		return (BUFF);
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


	while (*format != '\0')
	{
		while (*format == 32)
		{
			format++;
		}
	/* Scan array for function pointer which corresponds to format specifier */
		for (i = 0; specSelect[i].spec != NULL; i++)
		{
			if (*format == specSelect[i].spec[0])
			{
				return (specSelect[i].specFunc);
			}
		}
		format++;
	}
	return (errorFunc);
}
