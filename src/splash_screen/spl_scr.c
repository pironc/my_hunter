/*
** EPITECH PROJECT, 2020
** spl_scr.c
** File description:
** function to display splash screen
*/

#include "my.h"

int spl_scr(game_s *game)
{
    spl_scr_s *spl_scr = 0;
    spl_scr = spl_scr_init(game, spl_scr);

    while (game->game_state == 0 && sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, (sfColor){70, 70, 70, 255});
        spl_scr_draw(game, spl_scr);
        spl_scr_keypresses(game);
        sfRenderWindow_display(game->window);
    }
    spl_scr_dispose(spl_scr);
    return (0);
}