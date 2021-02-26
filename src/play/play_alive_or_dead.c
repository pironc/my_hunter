/*
** EPITECH PROJECT, 2020
** play_alive_or_dead.c
** File description:
** functions to check if the duck is alive or not
*/

#include "my.h"

void duck_check_when_alive(game_s **game, play_s **play)
{
    void (*directions[])(play_s **play) = {mv_duck_left, mv_duck_right, \
        mv_duck_up, mv_duck_topl, mv_duck_topr, mv_duck_bl, mv_duck_br};

    void (*redirect[])(play_s **play) = {mv_redirect_top, \
        mv_redirect_bottom, mv_redirect_left, mv_redirect_right};

    for (int i = 0; i <= 3; i++)
        if (!sfIntRect_contains((const sfIntRect[]){{0, 0, 1750, 550}}, \
            (*play)->blue_duck_pos.x, (*play)->blue_duck_pos.y))
            redirect[i](play);

    for (int i = 0; i <= 6; i++)
        if (i == (*play)->direction)
            directions[i](play);
}

void duck_is_alive(game_s **game, play_s **play)
{
    (*play)->blue_duck_pos = sfSprite_getPosition((*play)->blue_duck_sprite);
    (*play)->direction_time = sfClock_getElapsedTime((*play)->direction_clock);
    (*play)->direction_time_ms = sfTime_asMilliseconds((*play)->direction_time);

    if ((*play)->direction_time_ms > 600) {
        sfClock_restart((*play)->direction_clock);
        (*play)->direction = rand() % 7;
    }

    duck_check_when_alive(game, play);

    if ((*play)->shots_counter == 0) {
        (*play)->duck_status = 3;
        (*play)->current_duck += 1;
    }
}

void duck_is_dead(game_s **game, play_s **play)
{
    if ((*play)->direction == 0 || (*play)->direction == 3 || \
        (*play)->direction == 5)
        play_duck_death_left(play);
    else if ((*play)->direction == 1 || (*play)->direction == 4 || \
        (*play)->direction == 6 || (*play)->direction == 2)
        play_duck_death_right(play);

    (*play)->blue_duck_pos = sfSprite_getPosition((*play)->blue_duck_sprite);
    if ((*play)->blue_duck_pos.y >= 730 && (*play)->blue_duck_pos.y <= 740) {
        sfSound_stop((*play)->falling_sound);
        sfSound_play((*play)->drop_sound);
    }

    if ((*play)->blue_duck_pos.y >= 900) {
        (*play)->duck_status = 5;
        sfClock_restart((*play)->dog_with_duck_hide_clock);
        sfVector2f dog_pos = (*play)->blue_duck_pos;
        dog_pos.y = 660;
        sfSprite_setPosition((*play)->dog_with_duck_sprite, dog_pos);
    }
}