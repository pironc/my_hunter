/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** function that reproduces the printf system function
*/

#include "my.h"

int flag_check(const char *format, int i, va_list ap)
{
    char *flags = "cCdisSbou";
    int (*flag[])(const char *, int, va_list) = {f_c2, f_c2, f_di, f_di, f_s2, \
        f_s2, f_b, f_o, f_u};

    for (int x = 0; flags[x] != '\0'; x++) {
        if (i != 0 && format[i - 1] == '%' && format[i] == '%') {
            my_putchar('%');
            return (i);
        } else if (format[i + 1] == flags[x]) {
            i = flag[x](format, i, ap);
            return (i);
        }
    }
    return (i);
}

int my_printf(const char *format, ...)
{
    int i = 0;

    va_list ap;
    va_start(ap, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            i = flag_check(format, i, ap);
        else
            my_putchar(format[i]);
    }
    va_end(ap);
    return (0);
}