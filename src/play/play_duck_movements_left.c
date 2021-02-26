/*
** EPITECH PROJECT, 2020
** play_duck_movements_left.c
** File description:
** functions to move duck in left directions
*/

#include "my.h"

void mv_duck_left(play_s **play)
{
    sfSprite_setTexture((*play)->blue_duck_sprite, \
    (*play)->blue_duck_left_texture, sfFalse);
    sfVector2f speed = {-3, -1};
    speed.x -= (*play)->rounds_counter / 2;
    speed.y -= (*play)->rounds_counter / 2;
    sfSprite_move((*play)->blue_duck_sprite, speed);

    if ((*play)->blue_duck_time_ms > 50) {
        if ((*play)->blue_duck_left_rect.left < 340)
            (*play)->blue_duck_left_rect.left += 170;
        else
            (*play)->blue_duck_left_rect.left = 0;
        sfSprite_setTextureRect((*play)->blue_duck_sprite, \
        (*play)->blue_duck_left_rect);
        sfClock_restart((*play)->blue_duck_clock);
    }
}

void mv_duck_topl(play_s **play)
{
    sfSprite_setTexture((*play)->blue_duck_sprite, \
    (*play)->blue_duck_left_texture, sfFalse);
    sfVector2f speed = {-2.3, -3};
    speed.x -= (*play)->rounds_counter / 2;
    speed.y -= (*play)->rounds_counter / 2;
    sfSprite_move((*play)->blue_duck_sprite, speed);

    if ((*play)->blue_duck_time_ms > 50) {
        if ((*play)->blue_duck_left_rect.left < 850)
            (*play)->blue_duck_left_rect.left += 170;
        else
            (*play)->blue_duck_left_rect.left = 510;
        sfSprite_setTextureRect((*play)->blue_duck_sprite, \
        (*play)->blue_duck_left_rect);
        sfClock_restart((*play)->blue_duck_clock);
    }
}

void mv_duck_bl(play_s **play)
{
    sfSprite_setTexture((*play)->blue_duck_sprite, \
    (*play)->blue_duck_left_texture, sfFalse);
    sfVector2f speed = {-3.2, 2.8};
    speed.x -= (*play)->rounds_counter / 2;
    speed.y += (*play)->rounds_counter / 2;
    sfSprite_move((*play)->blue_duck_sprite, speed);

    if ((*play)->blue_duck_time_ms > 50) {
        if ((*play)->blue_duck_left_rect.left < 850)
            (*play)->blue_duck_left_rect.left += 170;
        else
            (*play)->blue_duck_left_rect.left = 510;
        sfSprite_setTextureRect((*play)->blue_duck_sprite, \
        (*play)->blue_duck_left_rect);
        sfClock_restart((*play)->blue_duck_clock);
    }
}