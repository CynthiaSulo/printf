#include <stdarg.h>
#include <unistd.h>

int print_integer(va_list args)
{
    int input, temp;
    int count = 0, length = 0, is_negative = 0;
    char integer_str[12];
    char *ptr = 0;

    input = va_arg(args, int);

    if (input == 0)
    {
        if (write(1, "0", 1) == -1)
            return (-1);
        ptr++;
        return (1);
    }

    if (input < 0)
    {
        is_negative = 1;
        input = -input;
        count++;
    }

    while (input != 0)
    {
        integer_str[length] = (input % 10) + '0';
        input /= 10;
        length++;
    }

    if (is_negative)
    {
        integer_str[length] = '-';
        length++;
    }

    temp = length - 1;
    while (temp >= 0)
    {
        if (write(1, &integer_str[temp], 1) == -1)
            return (-1);
        ptr++;
        count++;
        temp--;
    }

    return (count);
}

int print_decimal(va_list args)
{
    return print_integer(args);
}

int print_integer_i(va_list args)
{
    return print_integer(args);
}

int my_printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'd')
        {
            count += print_decimal(args);
            format += 2;
        }
        else if (*format == '%' && *(format + 1) == 'i')
        {
            count += print_integer_i(args);
            format += 2;
        }
        else
        {
            if (write(1, format, 1) == -1)
                return -1;
            format++;
            count++;
        }
    }

    va_end(args);
    return count;
}
