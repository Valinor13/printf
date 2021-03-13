#include "holberton.h"

int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;
	char *ptr;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				_putchar(*format);

			if (*format == 's')
			{
				ptr = va_arg(args, char *);
				_puts(ptr);
			}

			if (*format == 'd' || *format == 'i')
			{
				i = va_arg(args, int);
				print_number(i);
			}

			else
				_puts("Invalid specifier");
		}

		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);

return (count);
}
