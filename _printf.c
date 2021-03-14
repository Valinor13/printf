#include "holberton.h"

/**
* _printf - Write output to standard output based on input format
* @format: String to be printed, may include alternative format specifiers
*
* Return: Total number of characters printed
*/

int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

	/**
	* Array of structures, format specifiers and corresponding pointer functions
	*	that call relevant conversions and print desired string to standard input
	*/
	spec_t specSelect[] = {
		{"%", printPerc},
		{"c", printc},
		{"s", prints},
		{"d", printd},
		{"i", printi},
		{"b", printb},
		{"u", printu},
		{"o", printo},
		{"x", printx},
		{"X", printX},
		{"S", printS},
		{"p", printp},
		{"r", printr},
		{NULL, NULL}
	};

	va_start(args, format);

	/** NULL check for format pointer and contents of string literal */
	while (format && *format)
	{
		/** Check for format specifier */
		if (*format == '%')
		{
			/** Advance pointer through input string *************************/
			format++;
			i = 0;
			/** Scan array for function pointer which corresponds to format specifier */
			while (specSelect[i].spec != NULL)
			{
				if (*format == specSelect[i].spec[0])
				{
					/** count increased by the number of new characters printed */
					count = specSelect[i].specFunc(args, count);
					format++;
					break;
				}

				i++;
			}

			if (specSelect[i].spec == NULL)
				count = _puts("Invalid specifier", count);
		}
		/** Print the string if no format specifier */
		_putchar(*format);
		count++;
		format++;
	}
	va_end(args);

return (count);
}
