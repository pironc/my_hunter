/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** function to display menu window
*/

#include "my.h"

void update_menu_score(game_s *game, menu_s *menu)
{
    int cur_top_score = my_atoi(sfText_getString(menu->top_score_txt));
    char *new_top_score = my_int_to_str(game->highest_score);

    if (cur_top_score < game->highest_score)
        sfText_setString(menu->top_score_txt, new_top_score);
}

int menu(game_s *game)
{
    static menu_s *menu = 0;

    if (menu == 0)
        menu_init(game, &menu);
    else
        update_menu_score(game, menu);

    while (game->game_state == 1 && sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        menu_draw(game, menu);
        menu_keypresses(game, menu);
        sfRenderWindow_display(game->window);
    }
    if (!sfRenderWindow_isOpen(game->window))
        menu_dispose(menu);
    return (0);
}