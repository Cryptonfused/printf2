#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: Format string.
 * @...: Variable number of arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;

	if (!format || !format[0])
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				char_count += print_char(args);
			else if (*format == 's')
				char_count += print_str(args);
			else if (*format == '%')
				char_count += write(1, format, 1);
			else
			{
				if (*format)
					char_count += write(1, format - 1, 1);
			}
		}
		else
			char_count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (char_count);
}
