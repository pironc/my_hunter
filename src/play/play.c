/*
** EPITECH PROJECT, 2020
** play.c
** File description:
** function to display play window
*/

#include "my.h"

int play(game_s *game)
{
    play_s *play = 0;
    play_init(game, &play);

    while (game->game_state == 2 && sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        play_draw(game, play);
        play_keypresses(game, play);
        sfRenderWindow_display(game->window);
    }
    play_dispose(play);
    return (0);
}