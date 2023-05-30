#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * _printf - custom implementation of printf function
 * @format: the format string
 * ...: variable arguments
 * Return: the number of bytes printed
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
				case '%':
					total_chars += _printf_char(args);
					break;
				case 'd':
				case 'i':
					total_chars += printf_integer(args);
					break;
				default:
					if (write(STDOUT_FILENO, &format[i - 1], 2) == -1)
						return (-1);
					total_chars += 2;
					break;
			}
		}
		else
		{
			if (write(STDOUT_FILENO, &format[i], 1) == -1)
				return (-1);
			total_chars++;
		}
		i++;
	}
	va_end(args);
	return (total_chars);
}
/**
  *printf_integer - handles 'd' and 'i' conversion specifiers
  *@args: list of arguments
  *Return: no. of characters printed
  */
int printf_integer(va_list args)
{
	int num = va_arg(args, int);
	int len = 0;
	int written;

	len = printf("%d", num);
	written = write(STDOUT_FILENO, "", 0);
	if (written != 0)
		return (-1);
	return (len);
}
