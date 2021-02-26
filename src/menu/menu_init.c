/*
** EPITECH PROJECT, 2020
** menu_init.c
** File description:
** function to initialize the main menu if not already
*/

#include "my.h"

void init_select(game_s *game, menu_s **menu, sfVector2f win_related_scale)
{
    (void)(game);

    sfFloatRect text_rect = sfText_getGlobalBounds((*menu)->play_text);
    sfVector2f text_pos = sfText_getPosition((*menu)->play_text);
    text_pos.x -= text_rect.width / 1.4;
    text_pos.y -= text_rect.height / 20;

    (*menu)->select_sprite = create_object((*menu)->select_sprite, \
    (*menu)->select_texture, "assets/menu_select.png");
    sfSprite_setScale((*menu)->select_sprite, win_related_scale);

    sfSprite_setPosition((*menu)->select_sprite, text_pos);
}

void init_logo(game_s *game, menu_s **menu, sfVector2f win_related_scale)
{
    sfVector2f logo_pos = {0, (float)game->mode.height / 10};
    sfFloatRect logo_bounds;

    (*menu)->logo_sprite = create_object((*menu)->logo_sprite, \
    (*menu)->logo_texture, "assets/menu_logo.jpg");
    sfSprite_setScale((*menu)->logo_sprite, win_related_scale);

    logo_bounds = sfSprite_getGlobalBounds((*menu)->logo_sprite);
    logo_pos.x = (game->mode.width / 2) - logo_bounds.width / 2;
    sfSprite_setPosition((*menu)->logo_sprite, logo_pos);
}

void init_play_text(game_s *game, menu_s **menu, sfVector2f win_related_scale)
{
    sfVector2f text_pos = {0, (float)game->mode.height / 2.5};
    sfFloatRect text_bounds;
    sfColor Orange = {255, 140, 0, 255};

    text_init(&(*menu)->play_text, "PLAY", 30, Orange);
    text_set_font(&(*menu)->play_text, &(*menu)->play_font, \
    "assets/duck_hunt_font.ttf");

    sfText_setScale((*menu)->play_text, win_related_scale);

    text_bounds = sfText_getGlobalBounds((*menu)->play_text);
    text_pos.x = (game->mode.width / 2) - text_bounds.width / 2;
    sfText_setPosition((*menu)->play_text, text_pos);
}

void init_quit_text(game_s *game, menu_s **menu, sfVector2f win_related_scale)
{
    sfVector2f text_pos = {0, (float)game->mode.height / 2};
    sfFloatRect text_bounds;
    sfColor Orange = (sfColor){255, 140, 0, 255};

    text_init(&(*menu)->quit_text, "QUIT", 30, Orange);
    text_set_font(&(*menu)->quit_text, &(*menu)->quit_font, \
    "assets/duck_hunt_font.ttf");

    sfText_setScale((*menu)->quit_text, win_related_scale);

    text_bounds = sfText_getGlobalBounds((*menu)->quit_text);
    text_pos.x = (game->mode.width / 2) - text_bounds.width / 2;
    sfText_setPosition((*menu)->quit_text, text_pos);
}

int menu_init(game_s *game, menu_s **menu)
{
    sfVector2f win_related_scale = {(float)game->mode.width / 1920, \
        (float)game->mode.height / 1080};

    (*menu) = malloc(sizeof(*(*menu)));
    if ((*menu) == NULL)
        return (84);

    (*menu)->cur_sel = 0;

    init_logo(game, menu, win_related_scale);
    init_play_text(game, menu, win_related_scale);
    init_quit_text(game, menu, win_related_scale);
    init_top_score(game, menu);
    init_select(game, menu, win_related_scale);
    init_sound(&(*menu)->move_sound, &(*menu)->move_soundbuffer, \
    "assets/sound/menu_move.ogg");

    return (0);
}