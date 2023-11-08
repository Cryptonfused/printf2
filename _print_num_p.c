#include "main.h"
#include <limits.h>
#include <stdio.h>
/**
 * _print_num - Print an integer to stdout
 * @n: The int to be printed the by functn
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
			_putchar('2');
			_putchar('1');
			count += 2;
			n = 47483648;
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
