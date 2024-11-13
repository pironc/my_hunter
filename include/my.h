/*
** EPITECH PROJECT, 2020
** _MY_H_
** File description:
** _MY_H_
*/

#ifndef _MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>

#define uint unsigned int

/* GRAPHICAL STRUCTURES */

typedef struct game_t {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;

    sfClock *click_clock;
    sfTime click_timer;
    float time_ms;

    int game_state;
    int highest_score;
}game_s;

typedef struct spl_scr_t {
    /* Fade in */
    sfClock *fade_clock;
    sfClock *anim_clock;

    /* Fade out */
    sfTime fade_timer;
    sfTime anim_timer;

    /* Fade black image */
    sfImage *fade_image;
    sfSprite *fade_sprite;
    sfTexture *fade_texture;
    sfColor fade_black;

    /* Anim sound */
    sfSound *anim_sound;
    sfSoundBuffer *anim_soundbuffer;

    /* Intro animated sprite */
    sfSprite *sdh_sprite;
    sfTexture *sdh_texture;

    sfIntRect rect;
    int fade_status;
}spl_scr_s;

typedef struct menu_t {
    /* Selection condition */
    int cur_sel;

    /* Select & texture */
    sfSprite *select_sprite;
    sfTexture *select_texture;

    /* Logo sprite & texture */
    sfSprite *logo_sprite;
    sfTexture *logo_texture;

    /* Play text */
    sfText *play_text;
    sfFont *play_font;

    /* Quit text */
    sfText *quit_text;
    sfFont *quit_font;

    /* top score */
    sfSprite *top_score_sprite;
    sfTexture *top_score_texture;

    /* top score text */
    sfText *top_score_txt;
    sfFont *top_score_font;

    /* Anim sound */
    sfSound *anim_sound;
    sfSoundBuffer *anim_soundbuffer;

    /* Menu move sound */
    sfSound *move_sound;
    sfSoundBuffer *move_soundbuffer;
}menu_s;

typedef struct duck_icon_t {
    sfSprite *duck_icon_sprite;
    sfTexture *duck_icon_white_texture;
    sfTexture *duck_icon_red_texture;

    sfVector2f duck_icon_pos;
}duck_icon_s;

typedef struct play_t {
    duck_icon_s **duck_icon;

    int current_duck_died;
    int highest_score;
    float speed;

    int current_duck;
    int dead_ducks;

    sfSprite *duck_blink_sprite;
    sfTexture *duck_blink_texture;
    sfClock *duck_blink_clock;
    float duck_blink_time_ms;

    /* Play background */
    sfSprite *sky_blue_sprite;
    sfSprite *sky_pink_sprite;
    sfTexture *sky_blue_texture;
    sfTexture *sky_pink_texture;

    sfSound *flying_sound;
    sfSoundBuffer *flying_soundbuffer;
    sfSound *falling_sound;
    sfSoundBuffer *falling_soundbuffer;
    sfSound *drop_sound;
    sfSoundBuffer *drop_soundbuffer;
    int play_fall_sound;

    sfSprite *ground_sprite;
    sfTexture *ground_texture;

    /* Grass texture */
    sfSprite *grass_left_sprite;
    sfSprite *grass_right_sprite;
    sfTexture *grass_texture;

    /* Tree small */
    sfSprite *tree_small_sprite;
    sfTexture *tree_small_texture;

    /* Rounds */
    sfSprite *rounds_bg_sprite;
    sfTexture *rounds_bg_texture;
    sfText *rounds_text;
    sfFont *rounds_font;
    int rounds_counter;

    sfSprite *rounds_equal_sprite;
    sfTexture *rounds_equal_texture;

    /* Shots bar */
    sfSprite *shots_bar_sprite;
    sfTexture *shots_bar_texture;

    sfSprite *shots_blue_sprite;
    sfTexture *shots_blue_texture;
    int is_shots_pink_visible;

    sfSprite *shots_pink_sprite;
    sfTexture *shots_pink_texture;

    sfClock *shots_blue_clock;
    sfClock *shots_pink_clock;
    float shots_pink_time_ms;
    float shots_blue_time_ms;

    sfSprite *bullets_sprite;
    sfTexture *bullets_texture;
    sfIntRect bullets_rect;

    /* Hits bar */
    sfSprite *hits_bar_sprite;
    sfTexture *hits_bar_texture;
    sfSprite *hits_text_sprite;
    sfTexture *hits_text_texture;

    /* Score bar */
    sfSprite *score_bar_sprite;
    sfTexture *score_bar_texture;
    sfSprite *score_box_sprite;
    sfTexture *score_box_texture;
    sfText *score_text;
    sfFont *score_font;
    int score_counter_int;
    char *score_counter_char;

    /* Fly away */
    sfSprite *fly_away_sprite;
    sfTexture *fly_away_texture;

    /* Game over */
    sfSprite *game_over_sprite;
    sfTexture *game_over_texture;
    sfClock *game_over_clock;
    float game_over_time_ms;

    sfSound *game_over_sound;
    sfSoundBuffer *game_over_soundbuffer;

    /* Blue duck */
    sfSprite *blue_duck_sprite;
    sfTexture *blue_duck_right_texture;
    sfTexture *blue_duck_left_texture;
    sfTexture *blue_duck_up_texture;

    sfIntRect blue_duck_up_rect;

    sfIntRect blue_duck_left_rect;
    sfIntRect blue_duck_top_left_rect;
    sfIntRect blue_duck_btm_left_rect;

    sfIntRect blue_duck_right_rect;
    sfIntRect blue_duck_top_right_rect;
    sfIntRect blue_duck_btm_right_rect;

    sfClock *blue_duck_clock;
    float blue_duck_time_ms;

    sfVector2f blue_duck_pos;
    int duck_status;

    /* Dog laugh */
    sfSprite *dog_laugh_sprite;
    sfTexture *dog_laugh_texture;
    sfIntRect dog_laugh_rect;

    sfClock *dog_laugh_hide_clock;
    sfClock *dog_laugh_clock;
    float dog_laugh_hide_time_ms;
    float dog_laugh_time_ms;
    int dog_laugh_status;

    sfSound *duck_laugh_sound;
    sfSoundBuffer *duck_laugh_soundbuffer;

    /* Dog hold duck */
    sfSprite *dog_with_duck_sprite;
    sfTexture *dog_with_duck_texture;
    sfIntRect dog_with_duck_rect;

    sfClock *dog_with_duck_hide_clock;
    float dog_with_duck_hide_time_ms;
    int dog_with_duck_status;

    sfSound *dog_with_duck_sound;
    sfSoundBuffer *dog_with_duck_soundbuffer;

    sfClock *shoot_clock;
    float shoot_time_ms;
    int shots_counter;

    sfSound *shoot_sound;
    sfSoundBuffer *shoot_soundbuffer;

    sfClock *death_clock;
    float death_time_ms;

    sfVector2i mouse_pos_int;
    sfVector2f mouse_pos_float;

    sfClock *direction_clock;
    sfTime direction_time;
    float direction_time_ms;
    int direction;

    /* Target cursor */
    sfSprite *cursor_sprite;
    sfTexture *cursor_texture;
    sfVector2f cursor_pos;
}play_s;

/* CSFML Functions */

sfSprite *create_object(sfSprite *spr, sfTexture *texture, char *texture_path);

void text_init(sfText **text, char *string, uint size, sfColor color);
void text_set_font(sfText **text, sfFont **font, char *font_path);
void text_set_outlinecolor(sfText **text, float thickness, sfColor color);

void init_sound(sfSound **sound, sfSoundBuffer **soundbuffer, char *filepath);

/* DELCARATIONS IN LIB FUNCTIONS */

int prime(int nb);
int num_check(char *str, int i);
int str_to_int(char *str, int i, int num_len);
void print_maxint(void);
char *lower(char *str);
int word_check(char *str, char const *to_find, int i, char **sub_ptr);

/* LIB FUNCTIONS */

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int word_check(char *str, char const *to_find, int i, char **sub_ptr);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strcapitalize(char *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *array, int size);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_int_to_str(int nb);
void print_error(char *str);
int my_show_word_array(char * const *tab);
int my_atoi(const char *nptr);

// my_printf

int my_printf(const char *format, ...);
int flag_check(const char *format, int i, va_list ap);

int f_c2(const char *format, int i, va_list ap);
int f_di(const char *format, int i, va_list ap);
void f_s2_loop(char *str, int x);
int f_s2(const char *format, int i, va_list ap);
int f_u(const char *format, int i, va_list ap);
int f_b(const char *format, int i, va_list ap);
int f_o(const char *format, int i, va_list ap);
void my_put_unsigned_nbr(unsigned int nb);

/* PROJECT FUNCTIONS */

/* main functions */
int my_hunter(void);
int error_handling(int ac);
int help_display(int ac, char **av);
int game_init(game_s **game);

/* spl_scr - 0 */
int spl_scr(game_s *game);
spl_scr_s *spl_scr_init(game_s *game, spl_scr_s *spl_scr);
void spl_scr_draw(game_s *game, spl_scr_s *spl_scr);
void spl_scr_keypresses(game_s *game);
void spl_scr_dispose(spl_scr_s *spl_scr);

/* menu - 1 */
int menu(game_s *game);
int menu_init(game_s *game, menu_s **menu);
void menu_draw(game_s *game, menu_s *menu);
void menu_keypresses(game_s *game, menu_s *menu);
void menu_dispose(menu_s *menu);

void init_top_score(game_s *game, menu_s **menu);

/* play - 2 */
int play(game_s *game);
int play_init(game_s *game, play_s **play);
void play_draw(game_s *game, play_s *play);
void play_keypresses(game_s *game, play_s *play);
void play_dispose(play_s *play);

void play_draw_sprites(game_s *game, play_s *play);
void play_init_dog_laugh(play_s **play);
void play_init_dog_with_duck(play_s **play);
void play_bg_init(play_s **play);
void play_init_grass(play_s **play);
void play_init_tree(play_s **play);
void play_init_rounds(play_s **play);
void play_init_shots_bar(play_s **play);
void play_init_hits_bar(play_s **play);
void play_init_score_bar(play_s **play);
void play_init_duck_hits(play_s **play);
void play_init_blue_duck(play_s **play);
void play_init_duck_rects(play_s **play);
void play_init_fly_away(play_s **play);
void play_init_cursor(play_s **play);
void play_shot_check(play_s **play);
void update_round(game_s **game, play_s **play);
void play_takeoff_end_check(play_s **play);
void duck_check_when_alive(play_s **play);
void play_dog_laughing(game_s **game, play_s **play);
void play_dog_with_duck(game_s **game, play_s **play);
void reset_duck_positions_clocks(play_s **play);
void reset_duck(play_s **play);
void move_shots_rect(play_s **play);
void no_more_shots(game_s **game, play_s **play);
void play_dog_laugh_loop(play_s **play);

//duck status check
void duck_takeoff(game_s **game, play_s **play);
void duck_is_alive(game_s **game, play_s **play);
void duck_is_dead(game_s **game, play_s **play);
void no_more_shots(game_s **game, play_s **play);

//duck movements
void mv_duck_up(play_s **play);
void mv_duck_left(play_s **play);
void mv_duck_topl(play_s **play);
void mv_duck_bl(play_s **play);
void mv_duck_right(play_s **play);
void mv_duck_topr(play_s **play);
void mv_duck_br(play_s **play);

//duck redirect
void mv_redirect_top(play_s **play);
void mv_redirect_bottom(play_s **play);
void mv_redirect_left(play_s **play);
void mv_redirect_right(play_s **play);

//duck death
void play_duck_death_left(play_s **play);
void play_duck_death_right(play_s **play);

//dog
void play_dog_laughing(game_s **game, play_s **play);
void play_dog_with_duck(game_s **game, play_s **play);
void game_over(game_s **game, play_s **play);
void game_over_dog_laugh(play_s **play);

#endif /* !_MY_H_ */