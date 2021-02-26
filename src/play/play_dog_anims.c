/*
** EPITECH PROJECT, 2020
** play_dog_anims.c
** File description:
** functions to play the dog animations
*/

#include "my.h"

void play_dog_laugh_loop(play_s **play)
{
    if ((*play)->dog_laugh_time_ms > 100) {
        if ((*play)->dog_laugh_rect.left < 150)
            (*play)->dog_laugh_rect.left += 150;
        else
            (*play)->dog_laugh_rect.left = 0;
        sfSprite_setTextureRect((*play)->dog_laugh_sprite, \
        (*play)->dog_laugh_rect);
        sfClock_restart((*play)->dog_laugh_clock);
    }
}

void play_dog_laughing(game_s **game, play_s **play)
{
    sfSound_stop((*play)->flying_sound);
    sfVector2f dog_pos = sfSprite_getPosition((*play)->dog_laugh_sprite);

    if ((*play)->dog_laugh_status == 0) {
        sfSprite_move((*play)->dog_laugh_sprite, (sfVector2f){0, -1});
        if (dog_pos.y == 640)
            sfSound_play((*play)->duck_laugh_sound);
        if (dog_pos.y <= 560) {
            sfClock_restart((*play)->dog_laugh_hide_clock);
            (*play)->dog_laugh_status = 1;
        }
    }

    if ((*play)->dog_laugh_status == 1 && \
    (*play)->dog_laugh_hide_time_ms > 1000) {
        sfSprite_move((*play)->dog_laugh_sprite, (sfVector2f){0, 2});
        if (dog_pos.y >= 780) {
            (*play)->duck_status = 0;
            reset_duck(play);
        }
    }
    play_dog_laugh_loop(play);
}

void play_dog_with_duck(game_s **game, play_s **play)
{
    sfVector2f dog_pos = sfSprite_getPosition((*play)->dog_with_duck_sprite);

    if ((*play)->dog_with_duck_status == 0) {
        sfSprite_move((*play)->dog_with_duck_sprite, (sfVector2f){0, -2.5});
        if (dog_pos.y == 640)
            sfSound_play((*play)->dog_with_duck_sound);
        if (dog_pos.y <= 556) {
            sfClock_restart((*play)->dog_with_duck_hide_clock);
            (*play)->dog_with_duck_status = 1;
        }
    }
    if ((*play)->dog_with_duck_status == 1 && \
    (*play)->dog_with_duck_hide_time_ms > 500) {
        sfSprite_move((*play)->dog_with_duck_sprite, (sfVector2f){0, 2.5});
        if (dog_pos.y >= 750) {
            (*play)->duck_status = 0;
            reset_duck(play);
        }
    }
}