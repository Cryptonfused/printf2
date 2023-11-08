#include <stdio.h>
#include <stdarg.h>

int mini_printf(const char *format, ...) {
   char charCount =0;

    va_list args;
    va_start(args, format);
    
    while (*format) {
        if (*format != '%') {
            putchar(*format);
            charCount++;
        } else {
            format++; /*Move past "%"*/
            if (*format == 's') {
                const char *str = va_arg(args, const char *);
                if (str) {
                    while (*str) {
                        putchar(*str);
                        str++;
                        charCount++;
                    }
                } else {
                    /*Handle NULL string*/
                    const char *nullStr = "(null)";
                    while (*nullStr) {
                        putchar(*nullStr);
                        nullStr++;
                        charCount++;
                    }
                }
            }
        }
        format++;
    }

    va_end(args);
    return charCount;
}
