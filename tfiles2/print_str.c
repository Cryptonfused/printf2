#include <stdarg.h>
#include <unistd.h>
/**
 * print_str - Print a string.
 */
int print_str(va_list args)
{
	char *string = va_arg(args, char *);
	int char_count = 0;
	while (*string)
	{
		write(1, string, 1);
		string++;
		char_count++;
	}
	return (char_count);
}
