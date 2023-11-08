#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"
int _print_arg(char *buf, const char *format, va_list args, char flag, int field_width, int precision, char length_modifier)
{
  int nchars = 0;

  switch (*format) {
    case 'c':
      nchars = sprintf(buf, "%-*c", field_width, va_arg(args, int));
      break;

    case 's':
      nchars = sprintf(buf, "%-*s", field_width, va_arg(args, char *));
      break;

    case 'd':
    case 'i':
      if (flag == 0){
      nchars = sprintf(buf, "%0-*d", field_width, _modify_int(va_arg(args, int), length_modifier));
      }else{
	nchars = sprintf(buf, "%-*d", field_width, _modify_int(va_arg(args, int), length_modifier));
      }
    break;

    case 'u':
      nchars = sprintf(buf, "%-*u", field_width, _modify_uint(va_arg(args, unsigned int), length_modifier));
      break;

    case 'o':
      nchars = sprintf(buf, "%-*o", field_width, _modify_uint(va_arg(args, unsigned int), length_modifier));
      break;

    case 'x':
    case 'X':
      nchars = sprintf(buf, "%-*x", field_width, _modify_uint(va_arg(args, unsigned int), length_modifier));
      break;

    case 'p':
      nchars = sprintf(buf, "%-*p", field_width, precision, va_arg(args, void *));
      break;

    default:
      break;
  }

  return nchars;
}
