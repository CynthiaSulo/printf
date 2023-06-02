#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * print_integer - Prints an integer (%d %i)
 * @args: va_list containing the integer argument
 * Return: Number of characters printed
 */
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

/**
 * print_decimal - Prints a decimal (%d)
 * @args: va_list containing the decimal argument
 * Return: Number of characters printed
 */
int print_decimal(va_list args)
{
    return print_integer(args);
}

/**
 * print_integer_i - Prints an integer (%i)
 * @args: va_list containing the integer argument
 * Return: Number of characters printed
 */
int print_integer_i(va_list args)
{
    return print_integer(args);
}
