#include "main.h"
#include <stdarg.h>
#include <string.h>
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
				case 's':
					total_chars += printf_string(args);
					break;
				case 'c':
					total_chars += _printf_char(args);
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
  * printf_string - prints a string
  * @args: list of arguments
  * Return: total number of characters
  */
int printf_string(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	while (*s != '\0')
	{
		if (write(STDOUT_FILENO, s, 1) == -1)
			return (-1);
		s++;
		len++;
	}
	return (len);
}
/**
  * _printf_char - prints a character
  * @args: list of arguments
  * Return: total number of characters
  */
int _printf_char(va_list args)
{

	int c = va_arg(args, int);

	return (write(STDOUT_FILENO, &c, 1));
}
