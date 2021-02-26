/*
** EPITECH PROJECT, 2020
** play_init_hud.c
** File description:
** functions to initialize the player's hud
*/

#include "my.h"

void play_init_rounds(game_s *game, play_s **play)
{
    (*play)->rounds_counter = 0;
    sfColor green = {131, 211, 19, 255};

    text_init(&(*play)->rounds_text, "0", 40, green);
    text_set_font(&(*play)->rounds_text, &(*play)->rounds_font, \
    "assets/duck_hunt_font.ttf");

    sfText_setPosition((*play)->rounds_text, (sfVector2f){400, 800});

    (*play)->rounds_bg_sprite = create_object((*play)->rounds_bg_sprite, \
    (*play)->rounds_bg_texture, "assets/rounds_bg_box.jpg");
    sfSprite_setPosition((*play)->rounds_bg_sprite, (sfVector2f){320, 800});

    (*play)->rounds_equal_sprite = create_object((*play)->rounds_equal_sprite, \
    (*play)->rounds_equal_texture, "assets/rounds_equal.jpg");
    sfSprite_setPosition((*play)->rounds_equal_sprite, (sfVector2f){320, 800});
}

void play_init_shots_bar(game_s *game, play_s **play)
{
    (*play)->shots_bar_sprite = create_object((*play)->shots_bar_sprite, \
    (*play)->shots_bar_texture, "assets/shots_bar.png");

    (*play)->bullets_sprite = create_object((*play)->bullets_sprite, \
    (*play)->bullets_texture, "assets/bullets.jpg");
    (*play)->bullets_rect = (sfIntRect){0, 0, 120, 45};
    sfSprite_setTextureRect((*play)->bullets_sprite, (*play)->bullets_rect);
    sfSprite_setPosition((*play)->bullets_sprite, (sfVector2f){313, 872});

    (*play)->shots_blue_sprite = create_object((*play)->shots_blue_sprite, \
    (*play)->shots_blue_texture, "assets/shots_blue.jpg");
    sfSprite_setPosition((*play)->shots_blue_sprite, (sfVector2f){310, 915});

    (*play)->shots_pink_sprite = create_object((*play)->shots_pink_sprite, \
    (*play)->shots_pink_texture, "assets/shots_pink.jpg");
    sfSprite_setPosition((*play)->shots_pink_sprite, (sfVector2f){310, 915});
    (*play)->shots_pink_clock = sfClock_create();
    (*play)->is_shots_pink_visible = -1;

    sfSprite_setPosition((*play)->shots_bar_sprite, (sfVector2f){300, 860});
}

void play_init_hits_bar(game_s *game, play_s **play)
{
    (*play)->hits_text_sprite = create_object((*play)->hits_text_sprite, \
    (*play)->hits_text_texture, "assets/hit_text.jpg");
    sfSprite_setPosition((*play)->hits_text_sprite, (sfVector2f){681, 877});

    (*play)->hits_bar_sprite = create_object((*play)->hits_bar_sprite, \
    (*play)->hits_bar_texture, "assets/hits_bar.png");
    sfSprite_setPosition((*play)->hits_bar_sprite, (sfVector2f){660, 860});

    (*play)->duck_blink_sprite = create_object((*play)->duck_blink_sprite, \
    (*play)->duck_blink_texture, "assets/duck_blink.jpg");
}

void play_init_score_bar(game_s *game, play_s **play)
{
    (*play)->score_bar_sprite = create_object((*play)->score_bar_sprite, \
    (*play)->score_bar_texture, "assets/score_bar.png");
    sfSprite_setPosition((*play)->score_bar_sprite, (sfVector2f){1450, 860});

    (*play)->score_box_sprite = create_object((*play)->score_box_sprite, \
    (*play)->score_box_texture, "assets/score_box.jpg");
    sfSprite_setPosition((*play)->score_box_sprite, (sfVector2f){1458, 912});

    (*play)->score_counter_int = 0;

    text_init(&(*play)->score_text, "000000", 40, sfWhite);
    text_set_font(&(*play)->score_text, &(*play)->score_font, \
    "assets/duck_hunt_font.ttf");

    sfText_setPosition((*play)->score_text, (sfVector2f){1465, 871});
}

void play_init_duck_hits(game_s *game, play_s **play)
{
    (*play)->duck_icon = malloc(sizeof(duck_icon_s) * 10);

    for (int i = 0; i <= 9; i++)
        (*play)->duck_icon[i] = malloc(sizeof(duck_icon_s));

    sfVector2f duck_pos = {832, 878};

    for (int i = 0; i <= 9; i++) {
        (*play)->duck_icon[i]->duck_icon_sprite = sfSprite_create();
        (*play)->duck_icon[i]->duck_icon_white_texture = \
        sfTexture_createFromFile("assets/white_duck.jpg", NULL);
        (*play)->duck_icon[i]->duck_icon_red_texture = \
        sfTexture_createFromFile("assets/red_duck.jpg", NULL);
        (*play)->duck_icon[i]->duck_icon_pos = duck_pos;
        sfSprite_setTexture((*play)->duck_icon[i]->duck_icon_sprite, \
        (*play)->duck_icon[i]->duck_icon_white_texture, sfTrue);
        sfSprite_setPosition((*play)->duck_icon[i]->duck_icon_sprite, \
        (*play)->duck_icon[i]->duck_icon_pos);
        duck_pos.x += 40;
    }
}