/*
** EPITECH PROJECT, 2020
** play_game_over.c
** File description:
** functions for game over screen
*/

#include "my.h"

void game_over_dog_laugh(play_s **play)
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

void game_over(game_s **game, play_s **play)
{
    sfVector2f dog_pos = sfSprite_getPosition((*play)->dog_laugh_sprite);

    if ((*play)->dog_laugh_status == 0) {
        sfSprite_move((*play)->dog_laugh_sprite, (sfVector2f){0, -1});
        if (dog_pos.y == 640)
            sfSound_play((*play)->game_over_sound);
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
            (*game)->game_state = 1;
            (*game)->highest_score = (*play)->score_counter_int;
        }
    }
    game_over_dog_laugh(play);
}