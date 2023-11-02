#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int charCount = 0;
	va_list args;

	if (!format || !format[0])
		return (-1);

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					charCount += print_character(args);
					break;
				case 's':
					charCount += print_string(args);
					break;
				case 'r':
					write(1, "%", 1);
					write(1, "r", 1);
					charCount += 2;
					break;
				case '%':
					write(1, "%", 1);
					charCount++;
					break;
				case 'd':
				case 'i':
					/* Handle integers here */
					break;
				default:
					if (*format)
					{
						format--;
						write(1, format, 1);
						format++;
					}
					charCount++;
			}
		}
		else
		{
			write(1, format, 1);
			charCount++;
		}
		format++;
	}

	va_end(args);
	return (charCount);
}
