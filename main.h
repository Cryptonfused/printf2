#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _putchar(int c);
int _puts(char *str);
int _putnbr(int n);
int _printf(const char *format, ...);
int print_character(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
#endif
