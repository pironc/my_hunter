/*
** EPITECH PROJECT, 2020
** menu_draw.c
** File description:
** function to draw elements for menu
*/

#include "my.h"

void menu_draw(game_s *game, menu_s *menu)
{
    sfRenderWindow_drawSprite(game->window, menu->logo_sprite, NULL);
    sfRenderWindow_drawSprite(game->window, menu->select_sprite, NULL);
    sfRenderWindow_drawText(game->window, menu->play_text, NULL);
    sfRenderWindow_drawText(game->window, menu->quit_text, NULL);
    sfRenderWindow_drawSprite(game->window, menu->top_score_sprite, NULL);
    sfRenderWindow_drawText(game->window, menu->top_score_txt, NULL);
}