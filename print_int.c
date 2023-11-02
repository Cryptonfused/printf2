#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * print_integer - Print an integer.
 * @args: The arguments list.
 *
 * Return: The number of characters printed.
 */
int print_integer(va_list args)
{
    int number = va_arg(args, int);
    char buffer[12]; /* This size is enough for INT_MIN (-2147483648) plus a null terminator */
    int char_count = 0, written;
    int length = snprintf(buffer, sizeof(buffer), "%d", number);

    if (length < 0) {
        return -1;
    }

    written = write(1, buffer, length);

    if (written < 0) {
        return -1;
    }

    char_count += written;

    return char_count;
}
