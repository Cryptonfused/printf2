#include "main.h"
#include <limits.h>

/**
 * _print_num - Print an integer to stdout
 * @n: The integer to be printed
 *
 * Return: The number of characters printed
 */
int _print_num(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		if (n == INT_MIN)
		{
			n = -(n + 1);
		}
		else
		{
			n = -n;
		}
		count++;
	}

	while (n / 10 > 0)
	{
		count += _print_num(n / 10);
		n = n % 10;
	}

	_putchar(n + '0');
	count++;

	return (count);
}
