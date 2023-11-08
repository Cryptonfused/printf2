/**
 * _printf - Custom printf function.
 * @format: Format string.
 * @...: Variable number of arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int char_count = 0;

	if (!format || !format[0])
	{
		return (-1);
	}
	va_list args;
	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				char_count += print_character(args);
				break;
			case 's':
				char_count += print_string(args);
				break;
			case '%':
				write(1, "%", 1);
				char_count++;
				break;
			case 'd':
			case 'i':
				char_count += print_integer(args);
				break;
			default:
				if (*format)
				{
					format--;
					write(1, format, 1);
					format++;
				}
				char_count++;
			}
		}
		else
		{
			write(1, format, 1);
			char_count++;
		}
		format++;
	}
	va_end(args);
	return (char_count);
}
