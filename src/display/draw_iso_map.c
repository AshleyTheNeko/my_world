/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** draw_iso_map
*/

#include "my_world.h"
#include "my_world_macros.h"
#include <stdlib.h>
#include "libmy_functions.h"

static void draw_single_vertex(int render, sfTexture *texture,
sfVertexArray *v_array, sfRenderWindow *win)
{
    sfTransform transformation = sfTransform_Identity;
    sfRenderStates renderstats = {0};
    sfBlendMode b_mode = {0};

    if (render == 2)
        b_mode = sfBlendAlpha;
    else
        b_mode = sfBlendNone;
    renderstats = (sfRenderStates){
        .shader = NULL,
        .texture = texture,
        .blendMode = b_mode,
        .transform = transformation
    };
    if (render)
        sfRenderWindow_drawVertexArray(win, v_array, &renderstats);
}

static int handle_hover_rendering(data_t *game_data, int x, int y,
int rendered)
{
    if (rendered + game_data->mouse->hover_type > 2)
        return (rendered > 10 ? rendered : 0);
    if (game_data->mouse->block_found)
        if ((x == game_data->mouse->near_block.x
        && game_data->mouse->near_block.y == y) || rendered == -1) {
            make_hover_texture(game_data);
            draw_single_vertex(1 + game_data->mouse->hover_type, NULL,
            game_data->mouse->hover_display, game_data->win);
            return (99);
        }
    return (0);
}

int is_in_view(data_t *g_d, int x, int y)
{
    sfVector2f vcenter = sfView_getCenter(g_d->win_view);
    sfVector2f vsize = sfView_getSize(g_d->win_view);
    sfVector2f pts[4] = {g_d->map->points[y][x], g_d->map->points[y][x + 1],
    g_d->map->points[y + 1][x + 1], g_d->map->points[y + 1][x]};
    int ret_value = 0;

    for (int i = 0; i < 4; i++) {
        ret_value = ret_value || (pts[i].y > vcenter.y -(vsize.y / 2.0F) &&
        pts[i].y < vcenter.y + (vsize.y / 2.0F));
        ret_value = ret_value || (pts[i].x > vcenter.x - (vsize.x / 2.0F) &&
        pts[i].x < vcenter.x + (vsize.x / 2.0F));
    }
    return (ret_value);
}

void draw_vertexes(data_t *g_d)
{
    int rendered = 0;

    is_in_view(g_d, 0, 0);
    draw_single_vertex(1, NULL, g_d->map->far_lines, g_d->win);
    for (unsigned int y = 0; y < (g_d->map->size.y - 1); y++)
        for (unsigned int x = 0; x < (g_d->map->size.x - 1); x++) {
            rendered = handle_hover_rendering(g_d, x, y, rendered + 2);
            draw_single_vertex(
            g_d->map->render_textures * is_in_view(g_d, x, y),
            g_d->textures[g_d->map->blocks[y][x].texture],
            g_d->map->blocks[y][x].square, g_d->win);
            draw_single_vertex(1, NULL,
            g_d->map->blocks[y][x].lines, g_d->win);
            rendered = handle_hover_rendering(g_d, x, y, rendered);
        }
    if (!rendered)
        handle_hover_rendering(g_d, 0, 0, -1);
}