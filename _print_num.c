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
	int mark = 0, count = 0;
	int num, digit, divisor = 1;


	if (n == INT_MIN)
	{
		mark = 1;
		count += _putchar('-');
		n = -(n + 1); /* Handle INT_MIN as a special case */
	}
	else if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	num = n;
	while (num / divisor >= 10)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		digit = num / divisor;
		if (divisor < 10 && mark == 1)
			_putchar((digit + 1) + '0');
		else
			_putchar(digit + '0');
		count++;
		num %= divisor;
		divisor /= 10;
	}

	return (count);
}
