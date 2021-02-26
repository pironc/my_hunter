/*
** EPITECH PROJECT, 2020
** spl_scr_dispose.c
** File description:
** function to delete objet
*/

#include "my.h"

void spl_scr_dispose(spl_scr_s *spl_scr)
{
    sfImage_destroy(spl_scr->fade_image);
    sfSprite_destroy(spl_scr->fade_sprite);
    sfTexture_destroy(spl_scr->fade_texture);

    sfClock_destroy(spl_scr->anim_clock);
    sfClock_destroy(spl_scr->fade_clock);

    sfSound_destroy(spl_scr->anim_sound);
    sfSoundBuffer_destroy(spl_scr->anim_soundbuffer);

    sfSprite_destroy(spl_scr->sdh_sprite);
    sfTexture_destroy(spl_scr->sdh_texture);
    free(spl_scr);
}