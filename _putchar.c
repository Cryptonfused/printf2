#include "main.h"
#include <unistd.h>

int _putchar(int c)
{
  write(STDOUT_FILENO, &c, 1);
  return (1);
}
