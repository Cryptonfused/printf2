#include "main.h"
#include <limits.h>
/**
 * _print_num - Prints an integer to stdout
 * @n: The integer to be printed
 *
 * Return: The number of characters printed
 */
int _print_num(int n)
{
	int count = 0;
	int divisor, digit;

	if (n < 0)
	{
		_putchar('-');
		count++;
		if (n == INT_MIN) /* Handle the case where n is most negative value) */
		{
			n++; /* Increment n to avoid overflow when negating */
			n = -n;
			_putchar('2'); /* Print the first digit */
			count++;
		}
		else
		{
			n = -n;
		}
	}
	divisor = 10; /* Initialize divisor with 10 */
	while (n / divisor >= 10)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		digit = n / divisor;
		_putchar(digit + '0');
		count++;
		n %= divisor;
		divisor /= 10;
	}
	return (count);
}
