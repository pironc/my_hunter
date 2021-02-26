/*
** EPITECH PROJECT, 2020
** spl_scr_draw.c
** File description:
** function to draw splash screen
*/

#include "my.h"

void draw_fade_in(game_s *game, spl_scr_s *spl_scr)
{
    spl_scr->fade_timer = sfClock_getElapsedTime(spl_scr->fade_clock);
    int time_as_sec = (int)sfTime_asMicroseconds(spl_scr->fade_timer);

    if (time_as_sec >= 2500) {
        sfClock_restart(spl_scr->fade_clock);
        spl_scr->fade_black.a -= 1;
        sfSprite_setColor(spl_scr->fade_sprite, spl_scr->fade_black);
        if (spl_scr->fade_black.a == 0)
            spl_scr->fade_status = 1;
    }
    sfRenderWindow_drawSprite(game->window, spl_scr->fade_sprite, NULL);
}

void draw_anim(spl_scr_s *spl_scr)
{
    spl_scr->anim_timer = sfClock_getElapsedTime(spl_scr->anim_clock);
    if ((int)sfTime_asMilliseconds(spl_scr->anim_timer) > 100) {
        sfClock_restart(spl_scr->anim_clock);
        if (spl_scr->rect.left == 284)
            sfSound_play(spl_scr->anim_sound);
        if (spl_scr->rect.left < 1704 && spl_scr->fade_status == 1)
            spl_scr->rect.left += 284;
        else if (spl_scr->fade_status == 1) {
            spl_scr->fade_status = 2;
            spl_scr->rect.left = 0;
        }
        sfSprite_setTextureRect(spl_scr->sdh_sprite, spl_scr->rect);
    }
}

void draw_fade_out(game_s *game, spl_scr_s *spl_scr)
{
    spl_scr->fade_timer = sfClock_getElapsedTime(spl_scr->fade_clock);
    if ((int)sfTime_asMicroseconds(spl_scr->fade_timer) >= 2500) {
        sfClock_restart(spl_scr->fade_clock);
        spl_scr->fade_black.a += 1;
        sfSprite_setColor(spl_scr->fade_sprite, spl_scr->fade_black);
    }
    sfRenderWindow_drawSprite(game->window, spl_scr->fade_sprite, NULL);
}

void spl_scr_draw(game_s *game, spl_scr_s *spl_scr)
{
    sfRenderWindow_drawSprite(game->window, spl_scr->sdh_sprite, NULL);

    if (spl_scr->fade_status == 0)
        draw_fade_in(game, spl_scr);

    if (spl_scr->fade_status == 1)
        draw_anim(spl_scr);

    if (spl_scr->fade_status == 2)
        draw_fade_out(game, spl_scr);

    if (spl_scr->fade_status == 2 && spl_scr->fade_black.a >= 255) {
        game->game_state = 1;
        spl_scr->fade_status = 0;
    }
}