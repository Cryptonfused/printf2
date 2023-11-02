#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
  int count = 0;
  va_list args;

  va_start(args, format);

  while (*format != '\0') {
    if (*format == '%') {
      format++;
      switch (*format) {
        case 'c':
          count += _putchar(va_arg(args, int));
          break;
        case 's':
          count += _puts(va_arg(args, char *));
          break;
        case 'd':
          count += _putnbr(va_arg(args, int));
          break;
        case 'i':
          count += _putnbr(va_arg(args, int));
          break;
        case '%':
          count += _putchar('%');
          break;
        default:
          break;
      }
      format++;
    } else {
      count += _putchar(*format);
      format++;
    }
  }

  va_end(args);

  return count;
}
