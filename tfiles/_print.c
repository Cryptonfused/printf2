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
    int printed_chars = 0;
    va_list args;
    char c, *s;

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    printed_chars++;
                    break;

                case 's':
                    s = va_arg(args, char *);
                    while (*s)
                    {
                        write(1, s, 1);
                        s++;
                        printed_chars++;
                    }
                    break;

                case '%':
                    write(1, "%", 1);
                    printed_chars++;
                    break;

                default:
                    write(1, "%", 1);
                    write(1, format, 1);
                    printed_chars += 2;
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return (printed_chars);
}
