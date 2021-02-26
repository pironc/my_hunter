/*
** EPITECH PROJECT, 2020
** play_takeoff.c
** File description:
** functions to check for duck takeoff
*/

#include "my.h"

void play_takeoff_animation(game_s **game, play_s **play)
{
    if ((*play)->blue_duck_time_ms > 50) {
        if ((*play)->blue_duck_right_rect.left < 850)
            (*play)->blue_duck_right_rect.left += 170;
        else
            (*play)->blue_duck_right_rect.left = 510;
        sfSprite_setTextureRect((*play)->blue_duck_sprite, \
        (*play)->blue_duck_right_rect);
        sfClock_restart((*play)->blue_duck_clock);
    }
}

void play_takeoff_end_check(game_s **game, play_s **play)
{
    (*play)->blue_duck_pos = sfSprite_getPosition(\
    (*play)->blue_duck_sprite);
    if ((*play)->blue_duck_pos.y < 480)
        (*play)->duck_status = 1;
}

void duck_takeoff(game_s **game, play_s **play)
{
    if ((*play)->current_duck == 10 && (*play)->dead_ducks < 6) {
        (*play)->duck_status = 6;
        (*play)->dead_ducks = 0;
        sfSound_stop((*play)->flying_sound);
    } else if ((*play)->current_duck == 10)
        update_round(game, play);

    sfSound_setLoop((*play)->flying_sound, sfTrue);

    play_takeoff_animation(game, play);
    play_takeoff_end_check(game, play);

    sfVector2f speed = {1.5, -3};
    speed.x += (*play)->rounds_counter / 2;
    speed.y -= (*play)->rounds_counter / 2;
    sfSprite_move((*play)->blue_duck_sprite, speed);
    sfClock_restart((*play)->direction_clock);
}