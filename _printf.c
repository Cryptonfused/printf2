#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Custom printf function
 * @format: The format string containing format specifiers
 * @...: Variable number of arguments to be printed
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
        	return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				count += _putchar(va_arg(args, int));
			else if (*format == 's')
				count += _print_str(va_arg(args, char *));
			else if (*format == '%')
				count += _putchar('%');
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				count += _print_num(num);
			}
			else
			{
				count += _putchar(*(format - 1));
				count += _putchar(*format);
			}
			format++;
		}
		else
		{
			count += _putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
