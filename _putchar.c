#include "main.h"
#include <unistd.h>
/**
 * _putchar - Print a single character to stdout
 * @c: The character to be printed
 *
 * Return: The number of characters printed (1 for success, -1 for failure)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
