/*
** EPITECH PROJECT, 2020
** error_handling.c
** File description:
** function to handle errors for the my_hunter game
*/

#include "my.h"

int error_handling(int ac)
{
    if (ac != 1) {
        print_error("Error: Not enough arguments");
        return (84);
    }
    return (0);
}