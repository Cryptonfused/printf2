#include <unistd.h>
#include "main.h"
int _putnbr(int n)
{
  int count = 0;

  if (n < 0) {
    _putchar('-');
    count++;
    n = -n;
  }

  if (n >= 10) {
    count += _putnbr(n / 10);
  }

  _putchar(n % 10 + '0');
  count++;

  return count;
}
