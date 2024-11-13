/*
** EPITECH PROJECT, 2020
** play_duck_status.c
** File description:
** functions to check for duck status
*/

#include "my.h"

void update_round(game_s **game, play_s **play)
{
    (void)(game);

    char *round = my_int_to_str((*play)->rounds_counter += 1);
    sfText_setString((*play)->rounds_text, round);
    (*play)->current_duck = 0;

    (*play)->dead_ducks = 0;
    for (int i = 0; i <= 9; i++) {
        sfSprite_setTexture((*play)->duck_icon[i]->\
        duck_icon_sprite, (*play)->duck_icon[i]\
        ->duck_icon_white_texture, sfTrue);
    }
    if ((*play)->rounds_counter >= 10)
        sfSprite_setScale((*play)->rounds_bg_sprite, (sfVector2f){1.35, 1});
}

void reset_duck_positions_clocks(play_s **play)
{
    sfClock_restart((*play)->blue_duck_clock);
    sfClock_restart((*play)->shoot_clock);
    sfClock_restart((*play)->death_clock);

    sfSprite_setPosition((*play)->blue_duck_sprite, (*play)->blue_duck_pos);
    sfSprite_setPosition((*play)->dog_with_duck_sprite, (sfVector2f){940, 660});
    sfSprite_setPosition((*play)->dog_laugh_sprite, (sfVector2f){940, 660});
}

void reset_duck(play_s **play)
{
    srand(time(NULL));
    (*play)->blue_duck_pos.x = 100 + (rand() % 900);
    (*play)->blue_duck_pos.y = 700;

    (*play)->shots_counter = 3;
    reset_duck_positions_clocks(play);

    sfSprite_setTexture((*play)->blue_duck_sprite, \
    (*play)->blue_duck_right_texture, sfFalse);
    sfSprite_setTextureRect((*play)->blue_duck_sprite, \
    (*play)->blue_duck_right_rect);
    (*play)->duck_status = 0;
    (*play)->dog_laugh_status = 0;

    (*play)->bullets_rect.width = 120;
    sfSprite_setTextureRect((*play)->bullets_sprite, (*play)->bullets_rect);
    (*play)->is_shots_pink_visible = -1;
    (*play)->dog_with_duck_status = 0;
    (*play)->current_duck_died = 0;
    sfSound_play((*play)->flying_sound);
    (*play)->play_fall_sound = 0;
}