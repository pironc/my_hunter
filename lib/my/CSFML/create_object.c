/*
** EPITECH PROJECT, 2020
** create_object.c
** File description:
** function to create a new object, composed of a sprite and a texture
*/

#include "my.h"

sfSprite *create_object(sfSprite *spr, sfTexture *texture, char *texture_path)
{
    spr = sfSprite_create();
    texture = sfTexture_createFromFile(texture_path, NULL);
    sfSprite_setTexture(spr, texture, sfTrue);
    return (spr);
}