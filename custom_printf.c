#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
	int total_chars = 0, format_length = 0, buffer_index = 0, i = 0;
	va_list args;
	const char *p = format;
	char *buffer;

	va_start(args, format);
	while (*p++)
		format_length++;
	buffer = (char *)malloc((format_length + 1) * sizeof(char));
	if (!buffer)
	{
		va_end(args);
		return (-1);
	}
	while (format[i])
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == format_length)
			{
				total_chars += write(STDOUT_FILENO, buffer, buffer_index);
				buffer_index = 0;
			}
			total_chars++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				buffer[buffer_index++] = '%';
				if (buffer_index == format_length)
				{
					total_chars += write(STDOUT_FILENO, buffer, buffer_index);
					buffer_index = 0;
				}
				total_chars++;
			}
			else if (format[i] == 'c')
			{
				buffer[buffer_index++] = (char)va_arg(args, int);
				if (buffer_index == format_length)
				{
					total_chars += write(STDOUT_FILENO, buffer, buffer_index);
					buffer_index = 0;
				}
				total_chars++;
			}
			else if (format[i] == 's')
			{
				const char *str = va_arg(args, const char *);
				int len = 0;

				while (str[len])
				{
					buffer[buffer_index++] = str[len++];
					if (buffer_index == format_length)
					{
						total_chars += write(STDOUT_FILENO, buffer, buffer_index);
						buffer_index = 0;
					}
					total_chars++;
				}
			}
		}
		i++;
	}
	if (buffer_index)
	{
		total_chars += write(STDOUT_FILENO, buffer, buffer_index);
	}
	free(buffer);
	va_end(args);
	return (total_chars);
}
