#include "main.h"

/**
 * print_character - Print a character.
 * @args: The arguments list.
 *
 * Return: The number of characters printed.
 */

int print_character(va_list args)
{
	char character = va_arg(args, int);

	return (write(1, &character, 1));
}
