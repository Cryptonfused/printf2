#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _putchar(char c);
int _puts(char *str);
int _putnbr(int n);
int _printf(const char *format, ...);
int mini_printf(const char *format, ...);
int print_character(va_list args);
int print_string(va_list args);
int _print_str(char *str);
int print_integer(va_list args);
int _print_num(int n);
int _print_arg(char *buf, const char *format, va_list args, char flag, int field_width, int precision, char length_modifier);
unsigned int _modify_uint(unsigned int value, char length_modifier);
int _modify_int(int value, char length_modifier);
#endif
