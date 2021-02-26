/*
** EPITECH PROJECT, 2020
** create_sound.c
** File description:
** function to initialize sound
*/

#include "my.h"

void init_sound(sfSound **sound, sfSoundBuffer **soundbuffer, char *filepath)
{
    (*sound) = sfSound_create();
    (*soundbuffer) = sfSoundBuffer_createFromFile(filepath);
    sfSound_setBuffer((*sound), (*soundbuffer));
}