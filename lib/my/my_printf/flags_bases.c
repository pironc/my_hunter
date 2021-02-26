/*
** EPITECH PROJECT, 2020
** flags_bases.c
** File description:
** functions to print numbers into bases
*/

#include "my.h"

int f_b(const char *format, int i, va_list ap)
{
    int x = 0;
    unsigned int uint_arg = va_arg(ap, unsigned int);
    char *binary = malloc(sizeof(char) * \
    (my_strlen(my_int_to_str(uint_arg)) * 3) + 2);

    if (format[i] == '%' && format[i + 1] == 'b') {
        for (x = 0; uint_arg >= 2; x++) {
            binary[x] = uint_arg % 2 + '0';
            uint_arg /= 2;
        }
        binary[x] = uint_arg % 2 + '0';
        my_revstr(binary);
        binary[x + 1] = '\0';
        i++;
    }
    my_putstr(binary);
    return (i);
}

int f_o(const char *format, int i, va_list ap)
{
    int x = 0;
    unsigned int uint_arg = va_arg(ap, unsigned int);
    char *octal = malloc(sizeof(char) * \
    (my_strlen(my_int_to_str(uint_arg)) * 3) + 2);

    if (format[i] == '%' && format[i + 1] == 'o') {
        for (x = 0; uint_arg >= 8; x++) {
            octal[x] = uint_arg % 8 + '0';
            uint_arg /= 8;
        }
        octal[x] = uint_arg % 8 + '0';
        my_revstr(octal);
        octal[x + 1] = '\0';
        i++;
    }
    my_putstr(octal);
    return (i);
}