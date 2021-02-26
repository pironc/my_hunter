/*
** EPITECH PROJECT, 2020
** menu_dispose.c
** File description:
** function to delete all sprites, textures and freeing
*/

#include "my.h"

void menu_dispose(menu_s *menu)
{
    sfText_destroy(menu->play_text);
    sfText_destroy(menu->quit_text);
    sfSprite_destroy(menu->select_sprite);
    sfSprite_destroy(menu->logo_sprite);
    sfTexture_destroy(menu->logo_texture);
    free(menu);
}