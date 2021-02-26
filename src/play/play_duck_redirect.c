/*
** EPITECH PROJECT, 2020
** play_duck_force_redirect.c
** File description:
** functions for forcing redirect of duck movements
*/

#include "my.h"

void mv_redirect_top(play_s **play)
{
    if ((*play)->blue_duck_pos.y < 0) {
        (*play)->direction = 5 + (rand() % 2);
        sfClock_restart((*play)->direction_clock);
    }
}

void mv_redirect_bottom(play_s **play)
{
    if ((*play)->blue_duck_pos.x >= 1750) {
        (*play)->direction = 0;
        sfClock_restart((*play)->direction_clock);
    }
}

void mv_redirect_left(play_s **play)
{
    if ((*play)->blue_duck_pos.x < 0) {
        (*play)->direction = 1;
        sfClock_restart((*play)->direction_clock);
    }
}

void mv_redirect_right(play_s **play)
{
    if ((*play)->blue_duck_pos.y >= 550) {
        (*play)->direction = 3 + (rand() % 2);
        sfClock_restart((*play)->direction_clock);
    }
}