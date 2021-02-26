/*
** EPITECH PROJECT, 2020
** menu_keypresses.c
** File description:
** function to check for keypresses in menu
*/

#include "my.h"

void menu_keypress_check(game_s *game, menu_s **menu)
{
    sfVector2f select_pos = sfSprite_getPosition((*menu)->select_sprite);

    if (game->event.key.code == sfKeyDown && (*menu)->cur_sel < 1) {
        sfSound_play((*menu)->move_sound);
        (*menu)->cur_sel += 1;
        select_pos.y += (game->mode.height * 108) / 1080;
        sfSprite_setPosition((*menu)->select_sprite, select_pos);
    }
    if (game->event.key.code == sfKeyUp && (*menu)->cur_sel > 0) {
        sfSound_play((*menu)->move_sound);
        (*menu)->cur_sel -= 1;
        select_pos.y -= (game->mode.height * 108) / 1080;
        sfSprite_setPosition((*menu)->select_sprite, select_pos);
    }
}

void menu_selection_check(game_s **game, menu_s *menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) || \
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfClock_restart((*game)->click_clock);
        if (menu->cur_sel == 0 && (*game)->time_ms > 0.2) {
            (*game)->game_state = 2;
            sfClock_restart((*game)->click_clock);
        }
        if (menu->cur_sel == 1 && (*game)->time_ms > 0.2)
            sfRenderWindow_close((*game)->window);
    }
}

void menu_keypresses(game_s *game, menu_s *menu)
{
    game->click_timer = sfClock_getElapsedTime(game->click_clock);
    game->time_ms = sfTime_asSeconds(game->click_timer);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed)
            menu_keypress_check(game, &menu);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window);
    }
    menu_selection_check(&game, menu);
}