#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024
/**
  *_printf - print characters
  *@format: pointer to a constant string
  *Return: total number of characters printed
  */
int _printf(const char *format, ...)
{
	int total_chars = 0;
	va_list args;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0, i = 0;
	if (!format)
		return (-1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER_SIZE)
			{
				total_chars += write(STDOUT_FILENO, buffer, BUFFER_SIZE);
				buffer_index = 0;
			}
			total_chars++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'd':
				case 'i':
					{
						int value = va_arg(args, int);
						int len = snprintf(buffer + buffer_index,
								BUFFER_SIZE - buffer_index,
								"%d", value);
						int remaining_space = BUFFER_SIZE - buffer_index;
						if (len >= remaining_space)
						{
							total_chars += write(STDOUT_FILENO, buffer, BUFFER_SIZE);
							buffer_index = 0;
							len = snprintf(buffer, BUFFER_SIZE, "%d", value);
						}
						buffer_index += len;
						total_chars += len;
						break;
					}
				default:
					{
						buffer[buffer_index++] = '%';
						buffer[buffer_index++] = format[i];
						total_chars += 2;
						break;
					}
			}
		}
	}
	if (buffer_index > 0)
		total_chars += write(STDOUT_FILENO, buffer, buffer_index);
	va_end(args);
	return (total_chars);
}
