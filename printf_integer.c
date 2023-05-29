#include <stdio.h>
#include <stdarg.h>
/**
  *_printf - handle conversion specifiers
  *@format: pointer to format string
  *Return: total no. of characters printed
  */
int _printf(const char *format, ...)
{
	int i = 0, total_chars = 0;
	va_list args;
	
	if (!format)
		return (-1);
	
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'd':
					{
						int num = va_arg(args, int);
						total_chars += printf("%d", num);
						break;
					}
				case 'i':
					{
						int num = va_arg(args, int);
						total_chars += printf("%i", num);
						break;
					}
				default:
					{
						if (putchar(format[i - 1]) == EOF || putchar(format[i]) == EOF)
							return (-1);
						total_chars += 2;
						break;
					}
			}
		}
		else
		{
			if (putchar(format[i]) == EOF)
				return (-1);
			total_chars++;
		}
		i++;
	}
	va_end(args);
	return (total_chars);
}
