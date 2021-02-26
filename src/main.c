/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function
*/

#include "my.h"

int main(int ac, char **av)
{
    if (help_display(ac, av) == 0)
        return (0);
    if (error_handling(ac) == 84)
        return (84);
    if (my_hunter() == 84) {
        print_error("Error: an unknown error occured during the game");
        return (84);
    }
    return (0);
}