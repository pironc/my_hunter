/*
** EPITECH PROJECT, 2020
** my_show_word_array.c
** File description:
** function to print a word array with \n's in between
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}