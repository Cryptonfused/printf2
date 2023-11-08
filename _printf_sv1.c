#include "main.h"
#include <stdio.h>
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
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c' || *format == 's' || *format == '%' || *format == 'd' || *format == 'i')
            {
                if (*format == 'c')
                    count += _putchar(va_arg(args, int));
                else if (*format == 's')
                    count += _print_str(va_arg(args, char *));
                else if (*format == '%')
                    count += _putchar('%');
                else if (*format == 'd' || *format == 'i')
                {
                    int num = va_arg(args, int);
                    if (num < 0)
                        count++;
                    count += _print_num(num);
                }
                format++;
            }
            else
            {
                if (*format)
                {
			format--;
			count += _putchar(*format);
			format++;
                }
            }
        }
        else
        {
            count += _putchar(*format);
            format++;
        }
    }

    va_end(args);
    return count;
}
