#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
        return (0);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '%')
            {
                write(1, format - 1, 1);
                charCount++;
            }
            else
            {
                format--;
                write(1, format, 2);
                charCount += 2;
                format++;
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
