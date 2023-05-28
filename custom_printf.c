#include <stddef.h>
#include "main.h"

#define BUF_FLUSH '\0'

/**
 * _printf - custom printf function implementation
 * @format: the format string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list argList;
    char *strPtr, *start;

    params_t params = PARAMS_INIT;

    va_start(argList, format);

    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);
    for (strPtr = (char *)format; *strPtr; strPtr++)
    {
        init_params(&params, argList);
        if (*strPtr != '%')
        {
            count += _putchar(*strPtr);
            continue;
        }
        start = strPtr;
        strPtr++;
        while (get_flag(strPtr, &params))
        {
            strPtr++;
        }
        strPtr = get_width(strPtr, &params, argList);
        strPtr = get_precision(strPtr, &params, argList);
        if (get_modifier(strPtr, &params))
            strPtr++;
        if (!get_specifier(strPtr))
             print_from_to(start, strPtr - 1, NULL);
        else
            count += get_print_func(strPtr, argList, &params);
    }
    _putchar(BUF_FLUSH);
    va_end(argList);
    return (count);
}
