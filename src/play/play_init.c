/*
** EPITECH PROJECT, 2020
** play_init.c
** File description:
** function to initialize the play if not already
*/

#include "my.h"

void play_init_game_over(game_s *game, play_s **play)
{
    (void)(game);

    (*play)->game_over_sprite = create_object((*play)->game_over_sprite, \
    (*play)->game_over_texture, "assets/game_over.png");
    sfSprite_setPosition((*play)->game_over_sprite, (sfVector2f){798, 220});

    (*play)->game_over_clock = sfClock_create();
}

void play_init_sound_effects(play_s **play)
{
    init_sound(&(*play)->duck_laugh_sound, &(*play)->duck_laugh_soundbuffer, \
    "assets/sound/dog_laughing.ogg");
    init_sound(&(*play)->shoot_sound, &(*play)->shoot_soundbuffer, \
    "assets/sound/gun_shot.ogg");
    init_sound(&(*play)->dog_with_duck_sound, \
    &(*play)->dog_with_duck_soundbuffer, "assets/sound/duck_caught.ogg");
    init_sound(&(*play)->game_over_sound, \
    &(*play)->game_over_soundbuffer, "assets/sound/game_over_1.ogg");
    init_sound(&(*play)->flying_sound, \
    &(*play)->flying_soundbuffer, "assets/sound/duck_flapping.ogg");
    init_sound(&(*play)->falling_sound, \
    &(*play)->falling_soundbuffer, "assets/sound/duck_falling.ogg");
    init_sound(&(*play)->drop_sound, \
    &(*play)->drop_soundbuffer, "assets/sound/duck_drop.ogg");
    sfSound_play((*play)->flying_sound);
    (*play)->play_fall_sound = 0;
}

void init_basic_infos(play_s **play)
{
    (*play)->duck_status = 0;

    (*play)->current_duck = 0;
    (*play)->dead_ducks = 0;
    (*play)->current_duck_died = 0;

    srand(time(NULL));
    (*play)->direction = rand() % 2;
    (*play)->direction_clock = sfClock_create();
    (*play)->duck_blink_clock = sfClock_create();
}

int play_init(game_s *game, play_s **play)
{
    (*play) = malloc(sizeof(*(*play)));

    init_basic_infos(play);
    play_bg_init(play);
    play_init_grass(play);
    play_init_tree(play);
    play_init_rounds(play);
    play_init_shots_bar(play);
    play_init_hits_bar(play);
    play_init_score_bar(play);
    play_init_blue_duck(play);
    play_init_duck_rects(play);
    play_init_dog_laugh(play);
    play_init_dog_with_duck(play);
    play_init_duck_hits(play);
    play_init_game_over(game, play);
    play_init_sound_effects(play);
    play_init_fly_away(play);
    play_init_cursor(play);

    return (0);
}