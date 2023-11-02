#include "main.h"
#include <unistd.h>

int _puts(char *str)
{
  int count = 0;

  while (*str != '\0') {
    _putchar(*str);
    str++;
    count++;
  }

  _putchar('\n');
  count++;

  return (count);
}
