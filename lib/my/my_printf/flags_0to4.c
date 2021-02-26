/*
** EPITECH PROJECT, 2020
** flags_0to4.c
** File description:
** four first flags for my_printf
*/

#include "my.h"

int f_c2(const char *format, int i, va_list ap)
{
    if (format[i] == '%' && format[i + 1] == 'c' || format[i + 1] == 'C') {
        my_putchar(va_arg(ap, int));
        i++;
    }
    return (i);
}

int f_di(const char *format, int i, va_list ap)
{
    if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i')) {
        my_put_nbr(va_arg(ap, int));
        i++;
    }
    return (i);
}

void f_s2_loop(char *str, int x)
{
    if (str[x] >= 32 && str[x] <= 126)
        my_putchar(str[x]);
    else {
        if (str[x] <= 9)
            my_printf("\\00%d", str[x]);
        else if (str[x] <= 31)
            my_printf("\\0%d", str[x]);
        if (str[x] == 127)
            my_printf("\\%d", str[x]);
    }
}

int f_s2(const char *format, int i, va_list ap)
{
    char *str = va_arg(ap, char *);

    if (format[i] == '%' && format[i + 1] == 's') {
        my_putstr(str);
        i++;
    } else if (format[i] == '%' && format[i + 1] == 'S') {
        for (int x = 0; str[x] != '\0'; x++) {
            f_s2_loop(str, x);
        }
        i++;
    }
    return (i);
}

int f_u(const char *format, int i, va_list ap)
{
    if (format[i] == '%' && format[i + 1] == 'u') {
        my_put_unsigned_nbr(va_arg(ap, unsigned int));
        i++;
    }
    return (i);
}