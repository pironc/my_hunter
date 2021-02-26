/*
** EPITECH PROJECT, 2020
** play_init_dog.c
** File description:
** functions to initialize dog
*/

#include "my.h"

void play_init_dog_laugh(game_s *game, play_s **play)
{
    (*play)->dog_laugh_sprite = create_object((*play)->dog_laugh_sprite, \
    (*play)->dog_laugh_texture, "assets/dog_laughing.png");
    (*play)->dog_laugh_rect = (sfIntRect){0, 0, 150, 195};
    sfSprite_setTextureRect((*play)->dog_laugh_sprite, \
    (*play)->dog_laugh_rect);
    sfSprite_setScale((*play)->dog_laugh_sprite, (sfVector2f){0.7, 0.7});
    sfSprite_setPosition((*play)->dog_laugh_sprite, (sfVector2f){940, 660});
    (*play)->dog_laugh_hide_clock = sfClock_create();
    (*play)->dog_laugh_clock = sfClock_create();
    (*play)->dog_laugh_status = 0;
}

void play_init_dog_with_duck(game_s *game, play_s **play)
{
    (*play)->dog_with_duck_sprite = create_object((*play)->dog_with_duck_sprite\
    , (*play)->dog_with_duck_texture, "assets/dog_with_duck.png");
    sfSprite_setScale((*play)->dog_with_duck_sprite, (sfVector2f){0.7, 0.7});
    sfSprite_setPosition((*play)->dog_with_duck_sprite, (sfVector2f){940, 660});
    (*play)->dog_with_duck_hide_clock = sfClock_create();
    (*play)->dog_with_duck_status = 0;
}