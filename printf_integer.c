#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
  *print_integer - print no. of characerts
  *@num: no. to be printed
  *Return: 0
  */
void print_integer(int num)
{
	int count = 0, length = 0, is_negative = 0, temp = num, i = length - 1;
	char *num_str = NULL;

	if (num == 0)
	{
		putchar('0');
		return;
	}
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
		count++;
	}
	while (temp != 0)
	{
		temp /= 10;
		length++;
	}
	count += length;
	num_str = (char *)malloc((length + 1) * sizeof(char));
	if (num_str == NULL)
	{
		return;
	}
	temp = num;
	while (i >= 0)
	{
		num_str[i] = (temp % 10) + '0';
		temp /= 10;
		i--;
	}
	if (is_negative)
	{
		putchar('-');
	}
	i = 0;
	while (i < length)
	{
		putchar(num_str[i]);
		i++;
	}
	free(num_str);
}
/**
  *my_print - constant string to be printed
  *@format: constant string
  *@...: arguments passed
  */
int my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'd')
		{
			int num = va_arg(args, int);

			print_integer(num);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'i')
		{
			int num = va_arg(args, int);

			print_integer(num);
			format += 2;
		}
		else
		{
			putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (0);
}
