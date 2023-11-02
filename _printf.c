#include "main.h"
#include <unistd.h>
#include <stdarg.h>

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
	{
		return (-1);
	}
	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char_count += print_character(args);
			}
			else if (*format == 's')
			{
				char_count += print_string(args);
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				char_count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				char_count += print_integer(args);
			}
			else
			{
				if (*format)
				{
					format--;
					write(1, format, 1);
					format++;
				}
				char_count++;
			}
		}
		format++;
	}

	va_end(args);
	return (char_count);
}
