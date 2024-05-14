/*
** EPITECH PROJECT, 2020
** my_world.h
** File description:
** heads
*/

#ifndef MY_WORLD
#define MY_WORLD

#include "my_world_structs.h"

int my_world(char const **env);

void window_event_loop(data_t *game_data);
void initialize_global_structure(data_t *game_data);
void draw_vertexes(data_t *game_data);
void refresh_map(map_t *map, int call_state);
int **gen_int_array(sfVector2u *size, int fill);
sfRenderWindow *create_render_win(char *title, int framerate);
void make_map(map_t *map, int fd);
void make_hover_texture(data_t *g_d);
void find_hover_block(data_t *game_data, int bar);
char start_with(char const *start, char const *str);
void manage_move_zoom(sfView *view, sfEvent *events, int turbo);
int bar_clicked(data_t *g_d, sfEvent *event);
void free_map(data_t *g_d);
void execute_hovered_action(data_t *g_d);
void save_map(data_t *data, int force_fd);
void get_int(int *storage, int fd);
void get_save_data(map_t *map, int fd);
int is_in_view(data_t *g_d, int x, int y);
void key_actions(sfEvent *evt, data_t *g_d);
sfVector2f make_iso_point(float x, float y, float z);
void resize_map(map_t *map, int mode);
int bar_hover(data_t *g_d);

char *get_full_path(char const *filepath, char const *extension);
char *get_lang(text_t *ifo, char *element);
void get_tuto_text(text_t *info, tuto_t *tuto);
void init_play(text_t *lang, flags_st *flag, sfRenderWindow *win);

void display_menu(data_t *g_d);
void display_tuto(data_t *g_d);
void display_bar(data_t *g_d);
void init_tuto_txt(tuto_t *tut, char *src);

flags_st *init_flags_struct(void);
text_t *init_text_t(void);
tuto_t *init_tuto(void);
bar_edit_t *init_bar(void);

#endif /* !MY_WORLD */
