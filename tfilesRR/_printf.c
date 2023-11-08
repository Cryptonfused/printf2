#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
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
					{
					const char *str = va_arg(args, const char *);
                        		if (str == NULL)
					{
						charCount += write(1, "(null)", 6);
					}else
					{
						charCount += write(1, str, strlen(str));
					}
					}
					break;
				case '%':
					write(1, format, 1);
					charCount++;
					break;
				default:
					write(1, format - 1, 1);
					write(1, format, 1);
					charCount += 2;
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
