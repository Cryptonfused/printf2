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
            if (*format)
            {
                if (*format == 's')
                {
                    char *str = va_arg(args, char *);
                    if (str == NULL)
                    {
                        write(1, "(null)", 6);
                        char_count += 6;
                    }
                    else
                    {
                        while (*str)
                        {
                            write(1, str, 1);
                            char_count++;
                            str++;
                        }
                    }
                }
                else if (*format == '%')
                {
                    write(1, "%", 1);
                    char_count++;
                }
                else if (*format == '!')
                {
                    if (*(format - 1) == '%')
                    {
                        write(1, "%%!", 3);
                        char_count += 3;
                    }
                }
                else
                {
                    write(1, "%", 1);
                    char_count++;
                    while (*format && *format != 'c' && *format != 's' && *format != '%' && *format != 'd' && *format != 'i')
                    {
                        write(1, format, 1);
                        char_count++;
                        format++;
                    }
                }
            }
        }
        else
        {
            write(1, format, 1);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count;
}
