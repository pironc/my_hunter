/*
** EPITECH PROJECT, 2020
** play_duck_movements_up.c
** File description:
** functions to move duck in upper direction
*/

#include "my.h"

void mv_duck_up(play_s **play)
{
    sfSprite_setTexture((*play)->blue_duck_sprite, \
    (*play)->blue_duck_up_texture, sfFalse);
    sfVector2f speed = {0, -2.5};
    speed.y -= (*play)->rounds_counter / 2;
    sfSprite_move((*play)->blue_duck_sprite, speed);

    if ((*play)->blue_duck_time_ms > 50) {
        if ((*play)->blue_duck_right_rect.left < 340)
            (*play)->blue_duck_right_rect.left += 170;
        else
            (*play)->blue_duck_right_rect.left = 0;
        sfSprite_setTextureRect((*play)->blue_duck_sprite, \
        (*play)->blue_duck_right_rect);
        sfClock_restart((*play)->blue_duck_clock);
    }
}