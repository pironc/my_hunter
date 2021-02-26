/*
** EPITECH PROJECT, 2020
** play_duck_death.c
** File description:
** functions to check if the duck died going left or right way
*/

#include "my.h"

void play_duck_death_left_loop(play_s **play)
{
    if ((*play)->blue_duck_time_ms > 50) {
        if ((*play)->blue_duck_left_rect.left < 1360)
            (*play)->blue_duck_left_rect.left += 170;
        else
            (*play)->blue_duck_left_rect.left = 1190;
        sfSprite_setTextureRect((*play)->blue_duck_sprite, \
        (*play)->blue_duck_left_rect);
        sfClock_restart((*play)->blue_duck_clock);
    }
    sfSprite_move((*play)->blue_duck_sprite, (sfVector2f){0, 3.5});
}

void play_duck_death_right_loop(play_s **play)
{
    if ((*play)->blue_duck_time_ms > 50) {
        if ((*play)->blue_duck_right_rect.left < 1360)
            (*play)->blue_duck_right_rect.left += 170;
        else
            (*play)->blue_duck_right_rect.left = 1190;
        sfSprite_setTextureRect((*play)->blue_duck_sprite, \
        (*play)->blue_duck_right_rect);
        sfClock_restart((*play)->blue_duck_clock);
    }
    sfSprite_move((*play)->blue_duck_sprite, (sfVector2f){0, 3.5});
}

void play_duck_death_left(play_s **play)
{
    if ((*play)->death_time_ms > 350) {
        play_duck_death_left_loop(play);
    } else {
        if ((*play)->play_fall_sound == 0) {
            sfSound_play((*play)->falling_sound);
            (*play)->play_fall_sound = 1;
        }
        (*play)->blue_duck_left_rect.left = 1020;
        sfSprite_setTextureRect((*play)->blue_duck_sprite, \
        (*play)->blue_duck_left_rect);
    }
}

void play_duck_death_right(play_s **play)
{
    if ((*play)->death_time_ms > 350) {
        play_duck_death_right_loop(play);
    } else {
        if ((*play)->play_fall_sound == 0) {
            sfSound_play((*play)->falling_sound);
            (*play)->play_fall_sound = 1;
        }
        sfSprite_setTexture((*play)->blue_duck_sprite, \
        (*play)->blue_duck_right_texture, sfTrue);
        (*play)->blue_duck_right_rect.left = 1020;
        sfSprite_setTextureRect((*play)->blue_duck_sprite, \
        (*play)->blue_duck_right_rect);
    }
}