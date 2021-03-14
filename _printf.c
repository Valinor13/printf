#include "holberton.h"

int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

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

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			i = 0;
			while (specSelect[i].spec != NULL)
			{
				if (*format == specSelect[i].spec[0])
				{
					count = specSelect[i].specFunc(args, count);
					format++;
					break;
				}

				i++;
			}

			if (specSelect[i].spec == NULL)
				count = count + _puts("Invalid specifier", count);
		}
		_putchar(*format);
		count++;
		format++;
	}
	va_end(args);

return (count);
}
