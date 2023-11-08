#include <limits.h>

unsigned int _modify_uint(unsigned int value, char length_modifier)
{
  switch (length_modifier) {
    case 'h':
      return (unsigned short)value;
    case 'l':
      return (unsigned long)value;
    default:
      return value;
  }
 }
