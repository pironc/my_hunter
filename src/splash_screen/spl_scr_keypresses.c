/*
** EPITECH PROJECT, 2020
** spl_scr_keypresses.c
** File description:
** function to check for keypresses in spl_scr
*/

#include "my.h"

void spl_scr_keypresses(game_s *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(game->window);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}