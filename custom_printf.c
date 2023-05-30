#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...)
{
    int total_chars = 0;
    va_list args;
    int format_length = 0;
    const char *p = format;
    char *buffer;
    int buffer_index = 0, i = 0;
    va_start(args, format);

    while (*p != '\0')
    {
        format_length++;
        p++;
    }

    
    buffer = (char *)malloc((format_length + 1) * sizeof(char));

    if (!buffer)
    {
        va_end(args);
        return -1;
    }
    while (format[i] != '\0')
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
                char ch = (char)va_arg(args, int);
                buffer[buffer_index++] = ch;
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
                while (str[len] != '\0')
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

    if (buffer_index > 0)
    {
        total_chars += write(STDOUT_FILENO, buffer, buffer_index);
    }

    free(buffer);
    va_end(args);

    return total_chars;
}
