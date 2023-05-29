#include <stdarg.h>
#include <stdio.h>
/**
  *my_printf - print characters
  *@format: pointer to constant string
  *Return: total characters printed
  */
void my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			switch (*(format + 1))
			{
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);

						printf("%d", num);
						break;
					}
				default:
					putchar(*format);
			}
			format += 2;
		}
		else
		{
			putchar(*format);
			format++;
		}
	}
	va_end(args);
}
