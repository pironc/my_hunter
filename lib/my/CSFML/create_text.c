/*
** EPITECH PROJECT, 2020
** create_text.c
** File description:
** function to create text
*/

#include "my.h"

void text_init(sfText **text, char *string, uint size, sfColor color)
{
    (*text) = sfText_create();
    sfText_setString((*text), string);
    sfText_setCharacterSize((*text), size);
    sfText_setFillColor((*text), color);
}

void text_set_font(sfText **text, sfFont **font, char *font_path)
{
    (*font) = sfFont_createFromFile(font_path);
    sfText_setFont((*text), (*font));
}

void text_set_outlinecolor(sfText **text, float thickness, sfColor color)
{
    sfText_setOutlineThickness((*text), thickness);
    sfText_setOutlineColor((*text), color);
}