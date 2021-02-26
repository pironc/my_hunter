/*
** EPITECH PROJECT, 2020
** menu_init_top_score.c
** File description:
** function to initialize top score in menu
*/

#include "my.h"

void init_top_score(game_s *game, menu_s **menu)
{
    (*menu)->top_score_sprite = create_object((*menu)->top_score_sprite, \
    (*menu)->top_score_texture, "assets/top_score.png");
    sfSprite_setPosition((*menu)->top_score_sprite, (sfVector2f){700, 650});

    text_init(&(*menu)->top_score_txt, "0", 30, (sfColor){76, 220, 72, 255});
    text_set_font(&(*menu)->top_score_txt, &(*menu)->top_score_font, \
    "assets/duck_hunt_font.ttf");

    sfText_setPosition((*menu)->top_score_txt, (sfVector2f){1080, 650});
}