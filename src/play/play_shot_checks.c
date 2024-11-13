/*
** EPITECH PROJECT, 2020
** play_shot_checks.c
** File description:
** functions to check for shots
*/

#include "my.h"

void move_shots_rect(play_s **play)
{
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

void no_more_shots(game_s **game, play_s **play)
{
    (void)(game);

    sfVector2f speed = {0, -5};
    speed.y -= (*play)->rounds_counter / 2;
    sfSprite_move((*play)->blue_duck_sprite, speed);
    sfSprite_setTexture((*play)->blue_duck_sprite, \
    (*play)->blue_duck_up_texture, sfFalse);

    move_shots_rect(play);
    (*play)->blue_duck_pos = sfSprite_getPosition((*play)->blue_duck_sprite);
    if ((*play)->blue_duck_pos.y < -250) {
        (*play)->duck_status = 4;
        sfClock_restart((*play)->dog_laugh_hide_clock);
        sfClock_restart((*play)->dog_laugh_clock);
    }
    if ((*play)->shots_pink_time_ms > 150) {
        sfClock_restart((*play)->shots_pink_clock);
        (*play)->is_shots_pink_visible *= -1;
    }
}