/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** my_hunter main function
*/

#include "my.h"

int my_hunter(void)
{
    int (*game_window[])(game_s *) = {spl_scr, menu, play};

    game_s *game = 0;
    if (game_init(&game) == 84)
        return (84);

    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        game_window[game->game_state](game);
        sfRenderWindow_display(game->window);
    }
    free(game);
    return (0);
}