#include <limits.h>

int _modify_int(int value, char length_modifier)
{
  switch (length_modifier) {
    case 'h':
      return (short)value;
    case 'l':
      return (long)value;
    default:
      return value;
  }
}
