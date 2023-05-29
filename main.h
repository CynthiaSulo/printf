#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int printf_char(va_list args);
int printf_string(va_list args);

#endif
