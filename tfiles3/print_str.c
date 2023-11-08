#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 * print_string - Print a string.
 * @args: The arguments list.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	char *string = va_arg(args, char *);
	int char_count = 0;
	while (*string)
	{
		write(1, string, 1);
		string++;
		char_count++;
	}
	return (char_count);
}
