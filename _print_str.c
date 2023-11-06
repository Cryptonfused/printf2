#include "main.h"
#include <stddef.h>
/**
 * _print_str - Print a string to stdout
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _print_str(char *str)
{
	int count = 0;

	if (str == NULL)
	str = "(null)";
	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}

