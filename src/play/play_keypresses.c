/*
** EPITECH PROJECT, 2020
** play_keypresses.c
** File description:
** function to check for keypresses in play
*/

#include "my.h"

void update_score(play_s **play)
{
    int score_len = 0;
    (*play)->current_duck += 1;
    (*play)->current_duck_died = 1;
    (*play)->dead_ducks++;

    (*play)->score_counter_int += 500;
    (*play)->score_counter_char = my_int_to_str((*play)->score_counter_int);
    (*play)->score_counter_char = my_revstr((*play)->score_counter_char);

    score_len = my_strlen((*play)->score_counter_char);
    for (; score_len < 6; score_len++)
        (*play)->score_counter_char[score_len] = '0';

    (*play)->score_counter_char[score_len] = '\0';
    (*play)->score_counter_char = my_revstr((*play)->score_counter_char);
    sfText_setString((*play)->score_text, (*play)->score_counter_char);
}

void play_shot_check(play_s **play)
{
    sfFloatRect duck_rect = sfSprite_getGlobalBounds((*play)->blue_duck_sprite);

    if (sfFloatRect_contains(&duck_rect, (*play)->mouse_pos_float.x, \
    (*play)->mouse_pos_float.y) && (*play)->current_duck_died == 0) {
        sfSprite_setTexture((*play)->duck_icon[(*play)->current_duck]->\
        duck_icon_sprite, (*play)->duck_icon[(*play)->current_duck]\
        ->duck_icon_red_texture, sfTrue);
        sfSound_stop((*play)->flying_sound);
        sfClock_restart((*play)->death_clock);
        (*play)->duck_status = 2;
        update_score(play);
    }
}

void pollevent_check(game_s *game, play_s **play)
{
    if (game->event.type == sfEvtMouseButtonPressed && \
    sfMouse_isButtonPressed(sfMouseLeft) && (*play)->shoot_time_ms > 0.3 && \
    (*play)->shots_counter > 0) {
        sfClock_restart((*play)->shoot_clock);
        sfSound_play((*play)->shoot_sound);
        (*play)->shots_counter -= 1;
        (*play)->bullets_rect.width -= 40;
        sfSprite_setTextureRect((*play)->bullets_sprite, (*play)->bullets_rect);

        play_shot_check(play);
    }
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
}

void play_keypresses(game_s *game, play_s *play)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(game->window);
    while (sfRenderWindow_pollEvent(game->window, &(game->event)))
        pollevent_check(game, &play);
}