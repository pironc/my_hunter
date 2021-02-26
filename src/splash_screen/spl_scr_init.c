/*
** EPITECH PROJECT, 2020
** spl_scr_init.c
** File description:
** function to initialize the spl_scr
*/

#include "my.h"

spl_scr_s *init_fade(game_s *game, spl_scr_s *spl_scr)
{
    spl_scr->fade_image = sfImage_createFromColor(game->mode.width, \
    game->mode.height, sfBlack);
    spl_scr->fade_sprite = sfSprite_create();
    spl_scr->fade_texture = sfTexture_createFromImage\
    (spl_scr->fade_image, NULL);
    spl_scr->fade_black = (sfColor){255, 255, 255, 255};
    sfSprite_setColor(spl_scr->fade_sprite, spl_scr->fade_black);
    sfSprite_setTexture(spl_scr->fade_sprite, spl_scr->fade_texture, sfTrue);

    spl_scr->fade_status = 0;
    spl_scr->fade_clock = sfClock_create();

    return (spl_scr);
}

spl_scr_s *init_anim(spl_scr_s *spl_scr)
{
    init_sound(&spl_scr->anim_sound, &spl_scr->anim_soundbuffer, \
    "assets/sound/splash_screen_sound.ogg");

    spl_scr->anim_clock = sfClock_create();

    return (spl_scr);
}

spl_scr_s *init_bg(game_s *game, spl_scr_s *spl_scr)
{
    sfVector2f position = {(game->mode.width / 2) - 142, \
        (game->mode.height / 2) - 84};

    spl_scr->sdh_sprite = sfSprite_create();
    spl_scr->sdh_texture = sfTexture_createFromFile("assets/spl_scr.png", NULL);
    sfSprite_setTextureRect(spl_scr->sdh_sprite, spl_scr->rect);

    sfSprite_setTexture(spl_scr->sdh_sprite, spl_scr->sdh_texture, sfFalse);
    sfSprite_setPosition(spl_scr->sdh_sprite, position);

    return (spl_scr);
}

spl_scr_s *spl_scr_init(game_s *game, spl_scr_s *spl_scr)
{
    spl_scr = malloc(sizeof(*spl_scr));

    spl_scr->rect = (sfIntRect){0, 0, 284, 168};

    spl_scr = init_fade(game, spl_scr);
    spl_scr = init_anim(spl_scr);
    spl_scr = init_bg(game, spl_scr);

    return (spl_scr);
}