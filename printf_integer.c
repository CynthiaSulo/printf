#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf_int - Handles the printing of integers for the %d and %i specifiers.
 * @args: The va_list containing the integer argument.
 *
 * Return: The number of characters printed.
 */
int _printf_int(va_list args)
{
	int num = va_arg(args, int);

	return (printf("%d", num));
}

/**
 * _printf - Custom printf implementation.
 * @args: The va_list of arguments.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(va_list args, const char *format)
{
	int total_chars = 0;
	int i = 0;

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'd':
				case 'i':
					total_chars += _printf_int(args);
					break;
				default:
					putchar(format[i - 1]);
					total_chars++;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			total_chars++;
		}
		i++;
	}
	return (total_chars);
}
