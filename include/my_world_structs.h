/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** my_world_structs
*/

#ifndef MY_WORLD_STRUCTS_H_
#define MY_WORLD_STRUCTS_H_

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct block {
    sfVertexArray *square;
    sfVertexArray *lines;
    int texture;
} block_t;

typedef struct map {
    block_t **blocks;
    int **height_array;
    sfVertexArray *far_lines;
    sfVector2f **points;
    sfVector2u size;
    int render_textures : 1;
} map_t;

typedef struct mouse_hovering {
    sfVertexArray *hover_display;
    sfVector2i near_line[2];
    sfVector2f coord;
    sfVector2i near_block;
    int hover_type;
    int hover_action;
    int apply_texture;
    int block_found;
    int locked;
} mouse_t;

typedef struct flags_t {
    sfSprite *en_flag_s;
    sfSprite *fr_flag_s;
    sfSprite *zu_flag_s;
    sfTexture *menu_t;
    sfSprite *menu_s;
    sfText *play_btn;
    sfFont *font;
} flags_st;

typedef struct map_edit_s {
    sfSprite **bar;
    int curr;
    sfRectangleShape *text_bg;
    int display_text;
    sfText *hover;
} bar_edit_t;

typedef struct text_s {
    char const *tuto_path;
    char const *elem_path;
    char **langs;
    int curr_lang;
} text_t;

typedef struct tuto_s {
    sfSprite *tuto_bg;
    sfSprite *nao_face;
    sfSprite *nao_side;
    sfSprite *bubble;
    sfText *text;
    sfFont *font;
    int curr_text;
    bool end;
} tuto_t;

typedef struct global_game {
    int turbo_mode;
    sfTexture **textures;
    sfRenderWindow *win;
    sfView *win_view;
    flags_st *flags;
    bar_edit_t *bar;
    mouse_t *mouse;
    sfClock *clock;
    text_t *lang;
    tuto_t *tuto;
    map_t *map;
    int state;
} data_t;

#endif /* !MY_WORLD_STRUCTS_H_ */