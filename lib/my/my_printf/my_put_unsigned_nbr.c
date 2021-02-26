/*
** EPITECH PROJECT, 2020
** my_put_unsigned_nbr
** File description:
** function to print unsigned int
*/

#include "my.h"

void my_put_unsigned_nbr(unsigned int nb)
{
    if (nb > 9)
        my_put_nbr(nb / 10);

    my_putchar(nb % 10 + '0');
}