/*
** EPITECH PROJECT, 2020
** play_init_duck.c
** File description:
** functions to initialize duck
*/

#include "my.h"

void play_init_blue_duck(game_s *game, play_s **play)
{
    (*play)->blue_duck_sprite = sfSprite_create();
    (*play)->blue_duck_right_texture = \
    sfTexture_createFromFile("assets/blue_duck_right.png", NULL);
    sfSprite_setTexture((*play)->blue_duck_sprite, \
    (*play)->blue_duck_right_texture, sfFalse);

    (*play)->blue_duck_left_texture = \
    sfTexture_createFromFile("assets/blue_duck_left.png", NULL);
    (*play)->blue_duck_up_texture = \
    sfTexture_createFromFile("assets/blue_duck_up.png", NULL);

    sfSprite_setScale((*play)->blue_duck_sprite, (sfVector2f){0.6, 0.6});

    srand(time(NULL));
    (*play)->blue_duck_pos.x = 100 + (rand() % 900);
    (*play)->blue_duck_pos.y = 700;

    (*play)->shots_counter = 3;
    (*play)->blue_duck_clock = sfClock_create();
    (*play)->shoot_clock = sfClock_create();
    (*play)->death_clock = sfClock_create();

    sfSprite_setPosition((*play)->blue_duck_sprite, (*play)->blue_duck_pos);
}

void play_init_duck_rects(game_s *game, play_s **play)
{
    (*play)->blue_duck_up_rect = (sfIntRect){0, 0, 170, 165};

    (*play)->blue_duck_left_rect = (sfIntRect){0, 0, 170, 165};
    (*play)->blue_duck_top_left_rect = (sfIntRect){510, 0, 170, 165};
    (*play)->blue_duck_btm_left_rect = (sfIntRect){510, 0, 170, 165};

    (*play)->blue_duck_right_rect = (sfIntRect){0, 0, 170, 165};
    (*play)->blue_duck_top_right_rect = (sfIntRect){510, 0, 170, 165};
    (*play)->blue_duck_btm_right_rect = (sfIntRect){510, 0, 170, 165};

    sfSprite_setTextureRect((*play)->blue_duck_sprite, \
    (*play)->blue_duck_top_right_rect);
}