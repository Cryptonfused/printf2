#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_char - Print a character.
 */
int print_char(va_list args)
{
	char character = va_arg(args, int);
	return write(1, &character, 1);
}
