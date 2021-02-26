/*
** EPITECH PROJECT, 2020
** help_display.c
** File description:
** function to print help message
*/

#include "my.h"

int help_display(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf("MY_HUNTER\n\n\t./my_hunter\t  : Starts the game\n");
        my_printf("\t./my_hunter -h    : Displays this help menu\n\n");
        my_printf("\tLEFT CLICK\t  : Shoot\n");
        my_printf("\tESCAPE KEY\t  : Close game\n\n");
        my_printf("\tUP ARROW KEY\t  : Move up in menu\n");
        my_printf("\tDOWN ARROW KEY\t  : Move down in menu\n");
        my_printf("\tENTER / SPACE KEY : Select menu\n");
        my_printf("\nRULES\n\n\tYou have to kill a total of 6 ducks to go to \
the next round.\n\tYou only have a maximum of 3 bullets per round.\n\n");
        my_printf("\tYour highest score is saved and visible in the main menu");
        my_printf(".\n\tIf you happen to score a better score, it will be \
displayed.\n\tOtherwise, nothing will happen.\n");
        my_printf("\n\tWatch out, the ducks' speed might increase \
depending on the rounds ;)\n");
        return (0);
    }
    return (84);
}