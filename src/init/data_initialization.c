/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** data_initialization
*/

#include "libmy_macros.h"
#include "libmy_functions.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_world.h"
#include <malloc.h>
#include "my_world_macros.h"
#include <unistd.h>

int **gen_int_array(sfVector2u *size, int fill)
{
    int **new = malloc(sizeof(int *) * (size->y));

    for (unsigned int y = 0; y < size->y; y++) {
        new[y] = malloc(sizeof(int) * (size->x));
        for (unsigned int x = 0; x < size->x; x++)
            new[y][x] = fill;
    }
    return (new);
}

static void create_textures(data_t *g_d)
{
    sfTexture *grass =
    sfTexture_createFromFile("assets/textures/grass.jpg", NULL);
    sfTexture *sand =
    sfTexture_createFromFile("assets/textures/sand.jpg", NULL);
    sfTexture *cobble =
    sfTexture_createFromFile("assets/textures/cobble.jpg", NULL);

    g_d->textures = malloc(sizeof(sfTexture *) * 3);
    my_memcpy(g_d->textures, (sfTexture *[3]){grass, cobble, sand},
    sizeof(sfTexture *) * 3);
}

static void init_game(data_t *g_d, int save)
{
    g_d->mouse = malloc(sizeof(mouse_t));
    my_memset(g_d->mouse, sizeof(mouse_t));
    g_d->mouse->hover_display = sfVertexArray_create();
    g_d->map = malloc(sizeof(map_t));
    g_d->map->size = (sfVector2u){.x = 15, .y = 15};
    if (save != -1) {
        get_int((int *)&g_d->map->size.x, save);
        get_int((int *)&g_d->map->size.y, save);
    }
    create_textures(g_d);
    g_d->map->render_textures = 1;
    make_map(g_d->map, save);
}

void initialize_global_structure(data_t *g_d)
{
    int fd;

    g_d->win = create_render_win("My World", 144);
    g_d->lang = init_text_t();
    g_d->flags = init_flags_struct();
    init_play(g_d->lang, g_d->flags, g_d->win);
    fd = open(get_lang(g_d->lang, "alias_map"), O_RDONLY);
    init_game(g_d, fd);
    if (fd != -1)
        close(fd);
    g_d->state = STATE_MENU;
    g_d->tuto = init_tuto();
    g_d->bar = init_bar();
    g_d->turbo_mode = 1;
    g_d->clock = sfClock_create();
    g_d->bar->hover = sfText_create();
    sfText_setFont(g_d->bar->hover, g_d->tuto->font);
    g_d->bar->text_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(g_d->bar->text_bg, sfBlack);
    g_d->bar->display_text = 0;
}