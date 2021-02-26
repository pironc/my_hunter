/*
** EPITECH PROJECT, 2020
** play_dispose.c
** File description:
** function to delete objet
*/

#include "my.h"

void play_dispose(play_s *play)
{
    free(play);
}