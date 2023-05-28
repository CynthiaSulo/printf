#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

/* Define any required structures or macros */

typedef struct params
{
    /* Define your structure members */
    int l_modifier;
    int h_modifier;
    /* ... */
} params_t;

#define PARAMS_INIT { 0, 0 /* Initialize structure members */ }

/* Function prototypes */

void init_params(params_t *params, va_list argList);
int _putchar(char c);
int get_flag(const char *strPtr, params_t *params);
char *get_width(const char *strPtr, params_t *params, va_list argList);
char *get_precision(const char *strPtr, params_t *params, va_list argList);
int get_modifier(const char *strPtr, params_t *params);
int get_specifier(const char *strPtr);
void print_from_to(const char *start, const char *end, const char *modifier);
int get_print_func(const char *strPtr, va_list argList, params_t *params);
int _printf(const char *format, ...);

#endif
