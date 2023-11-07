#include "main.h"
#include <unistd.h>

/**
 * _puts - Prints a string followed by a newline to stdout
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _puts(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		count++;
	}

	_putchar('\n');
	count++;

	return (count);
}
