/*
** EPITECH PROJECT, 2020
** game_init.c
** File description:
** function to initialize the game
*/

#include "my.h"

int game_init(game_s **game)
{
    (*game) = malloc(sizeof(*(*game)));
    if ((*game) == NULL)
        return (84);
    (*game)->mode = (sfVideoMode){1920, 1080, 32};
    (*game)->window = sfRenderWindow_create((*game)->mode, "My Hunter", \
    sfClose, NULL);
    if (!(*game)->window)
        return (84);
    sfRenderWindow_setFramerateLimit((*game)->window, 144);
    sfRenderWindow_setMouseCursorVisible((*game)->window, sfFalse);
    (*game)->click_clock = sfClock_create();
    (*game)->game_state = 0;
    return (0);
}