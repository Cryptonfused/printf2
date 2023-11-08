#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#define PRINTF_BUF_SIZE 1024

int _printf(const char *format, ...)
{
  va_list args;
  char buf[PRINTF_BUF_SIZE];
  int count = 0;
  int nchars;
  char flag;
  int field_width;
  int precision;
  char length_modifier;

  /* Start a new line. */
  _putchar('\n');

  va_start(args, format);

  while (*format != '\0') {
    if (*format == '%') {
      format++;

      /* Parse the format specifier. */
      while (*format != '%' && *format != '\0') {
        switch (*format) {
          case '-':
            flag = '-';
            format++;
            break;
          case '+':
            flag = '+';
            format++;
            break;
          case '0':
            flag = '0';
            format++;
            break;
          case '#':
            flag = '#';
            format++;
            break;
          case ' ':
            flag = ' ';
            format++;
            break;
          case '*':
            field_width = va_arg(args, int);
            format++;
            break;
          case '.':
            precision = va_arg(args, int);
            format++;
            break;
          case 'h':
          case 'l':
            length_modifier = *format;
            format++;
            break;
          default:
            break;
        }
      }

      /* Print the argument according to the format specifier. */
      nchars = _print_arg(buf, format, args, flag, field_width, precision, length_modifier); 
      count += nchars;
      format++;
    } else {
      /* Print the character. */
      buf[count++] = *format++;
    }

    /* Flush the buffer if it is full. */
    if (count >= PRINTF_BUF_SIZE - 1) {
      write(STDOUT_FILENO, buf, count);
      count = 0;
    }
  }

  /* Flush the buffer at the end. */
  if (count > 0) {
    write(STDOUT_FILENO, buf, count);
  }

  va_end(args);

  return count;
}
