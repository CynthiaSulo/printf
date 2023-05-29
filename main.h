#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>


int _printf(const char *format, ...);
int _printf_char(va_list args);
int printf_string(va_list args);

#endif
