#include "main.h"

int _printf(const char *format, ...)
{
    int co = 0;

    va_list args;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c') /*print character*/
            {
                char cha = va_arg(args, int);
                _putchar(cha);
                co++;
                format++;
            }
            else if (*format == 's') /*print argument string*/
            {
                char *str =  va_arg(args, char*);
                co += _print_str(str);
                format++;
            }
            else if (*format == '%') /*for %% print %*/
            {
                _putchar('%');
                co++;
                format++;
            }
            else /*%string or other character*/
            {
                if (*format)
                {
                    format--;
                    _putchar(*format);
                    format++;
                }
                co++;
            }
        }
        else
        {
            _putchar(*format);
            co++;
            format++;
        }
    }
    return (co);
}
