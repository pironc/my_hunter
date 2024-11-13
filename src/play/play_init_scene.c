/*
** EPITECH PROJECT, 2020
** play_init_scene.c
** File description:
** functions to initialize basic graphical scene elements
*/

#include "my.h"

void play_bg_init(play_s **play)
{
    (*play)->sky_blue_sprite = create_object((*play)->sky_blue_sprite, \
    (*play)->sky_blue_texture, "assets/sky_blue.jpg");
    (*play)->sky_pink_sprite = create_object((*play)->sky_pink_sprite, \
    (*play)->sky_blue_texture, "assets/sky_pink.jpg");

    (*play)->ground_sprite = create_object((*play)->ground_sprite, \
    (*play)->ground_texture, "assets/ground.jpg");
    sfSprite_setPosition((*play)->ground_sprite, (sfVector2f){0, 740});
}

void play_init_grass(play_s **play)
{
    (*play)->grass_left_sprite = create_object((*play)->grass_left_sprite, \
    (*play)->grass_texture, "assets/grass.png");
    sfSprite_setPosition((*play)->grass_left_sprite, (sfVector2f){0, 625});

    (*play)->grass_right_sprite = create_object((*play)->grass_right_sprite, \
    (*play)->grass_texture, "assets/grass.png");
    sfSprite_setPosition((*play)->grass_right_sprite, (sfVector2f){964, 625});
}

void play_init_tree(play_s **play)
{
    (*play)->tree_small_sprite = create_object((*play)->tree_small_sprite, \
    (*play)->tree_small_texture, "assets/tree_small.png");
    sfSprite_setPosition((*play)->tree_small_sprite, (sfVector2f){150, 140});
}

void play_init_fly_away(play_s **play)
{
    (*play)->fly_away_sprite = create_object((*play)->fly_away_sprite, \
    (*play)->fly_away_texture, "assets/fly_away.png");
    sfSprite_setPosition((*play)->fly_away_sprite, (sfVector2f){777, 220});
}

void play_init_cursor(play_s **play)
{
    (*play)->cursor_sprite = create_object((*play)->cursor_sprite, \
    (*play)->cursor_texture, "assets/target.png");
}