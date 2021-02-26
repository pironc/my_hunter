/*
** EPITECH PROJECT, 2020
** play_draw.c
** File description:
** function to draw play
*/

#include "my.h"

void draw_extra(game_s *game, play_s *play)
{
    sfVector2f win_related_scale = {(float)game->mode.width / 1920, \
        (float)game->mode.height / 1080};

    play->mouse_pos_float.x = play->mouse_pos_int.x - 19;
    play->mouse_pos_float.y = play->mouse_pos_int.y - 19;

    sfSprite_setPosition(play->cursor_sprite, play->mouse_pos_float);
    sfSprite_setScale(play->cursor_sprite, win_related_scale);
    sfRenderWindow_drawSprite(game->window, play->cursor_sprite, NULL);

    if ((play->duck_status == 0 || play->duck_status == 1) && \
    play->duck_blink_time_ms < 300 && play->current_duck < 10) {
        sfVector2f cur_duck_blink_pos = sfSprite_getPosition(\
        play->duck_icon[play->current_duck]->duck_icon_sprite);
        sfSprite_setPosition(play->duck_blink_sprite, cur_duck_blink_pos);
        sfRenderWindow_drawSprite(game->window, play->duck_blink_sprite, NULL);
    } else if (play->duck_blink_time_ms > 600)
        sfClock_restart(play->duck_blink_clock);
}

void draw_other_sprites(game_s *game, play_s *play)
{
    if (play->duck_status == 3)
        sfRenderWindow_drawSprite(game->window, play->sky_pink_sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window, play->sky_blue_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->dog_laugh_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->blue_duck_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->tree_small_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->dog_with_duck_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->ground_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->grass_left_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->grass_right_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->rounds_bg_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->rounds_equal_sprite, NULL);
    sfRenderWindow_drawText(game->window, play->rounds_text, NULL);
    sfRenderWindow_drawSprite(game->window, play->shots_bar_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->bullets_sprite, NULL);
}

void play_draw_sprites(game_s *game, play_s *play)
{
    draw_other_sprites(game, play);
    if (play->is_shots_pink_visible == 1)
        sfRenderWindow_drawSprite(game->window, play->shots_pink_sprite, NULL);
    if (play->duck_status != 3)
        sfRenderWindow_drawSprite(game->window, play->shots_blue_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->hits_bar_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->hits_text_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->score_bar_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->score_box_sprite, NULL);
    sfRenderWindow_drawText(game->window, play->score_text, NULL);
    if (play->duck_status == 3)
        sfRenderWindow_drawSprite(game->window, play->fly_away_sprite, NULL);
    if (play->duck_status == 6)
        sfRenderWindow_drawSprite(game->window, play->game_over_sprite, NULL);

    for (int i = 0; i <= 9; i++)
        sfRenderWindow_drawSprite(game->window, \
        play->duck_icon[i]->duck_icon_sprite, NULL);

    draw_extra(game, play);
}

void get_elapsed_times(play_s **play)
{
    (*play)->blue_duck_time_ms = sfTime_asMilliseconds\
    (sfClock_getElapsedTime((*play)->blue_duck_clock));
    (*play)->shoot_time_ms = sfTime_asMilliseconds\
    (sfClock_getElapsedTime((*play)->shoot_clock));
    (*play)->death_time_ms = sfTime_asMilliseconds\
    (sfClock_getElapsedTime((*play)->death_clock));
    (*play)->dog_laugh_time_ms = sfTime_asMilliseconds\
    (sfClock_getElapsedTime((*play)->dog_laugh_clock));
    (*play)->dog_laugh_hide_time_ms = sfTime_asMilliseconds\
    (sfClock_getElapsedTime((*play)->dog_laugh_hide_clock));
    (*play)->dog_with_duck_hide_time_ms = sfTime_asMilliseconds\
    (sfClock_getElapsedTime((*play)->dog_with_duck_hide_clock));
    (*play)->shots_pink_time_ms = sfTime_asMilliseconds\
    (sfClock_getElapsedTime((*play)->shots_pink_clock));
    (*play)->game_over_time_ms = sfTime_asMilliseconds\
    (sfClock_getElapsedTime((*play)->game_over_clock));
    (*play)->duck_blink_time_ms = sfTime_asMilliseconds\
    (sfClock_getElapsedTime((*play)->duck_blink_clock));
}

void play_draw(game_s *game, play_s *play)
{
    void (*duck_actions[])(game_s **game, play_s **play) = {duck_takeoff, \
        duck_is_alive, duck_is_dead, no_more_shots, play_dog_laughing, \
        play_dog_with_duck, game_over};

    for (int i = 0; i <= 6; i++)
        if (i == play->duck_status)
            duck_actions[i](&game, &play);

    get_elapsed_times(&play);
    play->mouse_pos_int = sfMouse_getPositionRenderWindow(game->window);

    play_draw_sprites(game, play);
}