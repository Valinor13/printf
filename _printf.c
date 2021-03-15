#include "holberton.h"

/**
* _printf - Write output to standard output based on input format
* @format: String to be printed, may include alternative format specifiers
*
* Return: Total number of characters printed
*/

int _printf(const char *format, ...)
{
	int x, flowchk; count;
	int *f;
	va_list data_list;
	char *tmp_buf, BUFF;

	va_start(data_list, format);
	count = 0; /** Total number of characters writter */
	flowchk = 0; /** Buffer overflow prevention measure */
	f = &flowchk;

	BUFF = malloc(1024);

	/** NULL check for format pointer and contents of string literal */
	while (format && *format)
	{
		if (*format == '%') /** Check for format specifier */
		{
			format++;
			tmp_buf = (scan_array(format))(data_list); /** Filling the temporary buffer */
/**
* FLAG CODE
*/
		/** Strcpy the returned char * into BUFF, write to stdout */
			for (x = 0, x < _strlen(tmp_buf); x++, count++, flowchk++)
			{
				if (flowchk == 1024) /** Buffer empty */
					BUFF = flowchecky(f, BUFF);
				BUFF[flowchk] = tmp_buf[x]; /** Strcpy */
			}
		}
		if (flowchk == 1024) /** Buffer empty */
			BUFF = flowchecky(f, BUFF);
		BUFF[flowchk] = *format; /** Pass input string to primary buffer */
		count++, flowchk++, format++;
	}
	write (1, BUFF, flowchk);
	free(BUFF);
	va_end(args);
	return (count);
}

char *flowchecky(int *f, char *BUFF)
{
		write (1, BUFF, *f);
		*f = 0;
		free(BUFF);
		BUFF = malloc(1024);
		return (BUFF);
}


char *(*scan_array(char *format))(va_list)
{
	unsigned int i;

	/**
	* Array of structures, format specifiers and corresponding pointer functions
	*       that call relevant conversions and print desired string to standard input
	*/
	spec_t specSelect[] = {
		{"%", printPerc}, {"c", printc}, {"s", prints}, {"d", printint}, {"i", printint},
		{"b", printb}, {"u", printu}, {"o", printo}, {"x", printx}, {"X", printX},
 		{"S", printS}, {"p", printp}, {"r", printr}, {NULL, NULL}};
		
		while (*format != 32 && *format + 1 != 32) /**ASCII 32 == " " */
		{
		/** Scan array for function pointer which corresponds to format specifier */
			for (i = 0; specSelect[i].spec != NULL; i++)
			{
				if (*format == specSelect[i].spec[0])
				{
					while (*format != '%')
					{
						format--;
					}
					return (specSelect[i].specFunc);
				}
			}
			format++
		}
		if (*format == 32 && *format + 1 == 32) /** Empty input, no specifier */
			return (errorFunc);
}
