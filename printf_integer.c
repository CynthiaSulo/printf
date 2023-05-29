#include <stdio.h>
#include <stdarg.h>
/**
  *my_printf - handle conversion specifiers
  *@format: pointer to constant string
  *Return: number of characters printed
  */
int my_printf(char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					{
						int value = va_arg(args, int);

						printf("%d", value);
						count++;
						break;
					}
				default:
					{
						printf("Unknown format specifier: %c\n", *format);
						break;
					}
			}
		}
		else
		{
			printf("%c", *format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
