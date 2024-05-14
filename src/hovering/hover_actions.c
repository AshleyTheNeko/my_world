/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** hover_actions
*/

#include "my_world.h"
#include "my_world_macros.h"

static void lift_tile(data_t *g_d, int mode)
{
    int x_arr[4] = {g_d->mouse->near_block.x, g_d->mouse->near_block.x + 1,
    g_d->mouse->near_block.x + 1, g_d->mouse->near_block.x};
    int y_arr[4] = {g_d->mouse->near_block.y, g_d->mouse->near_block.y,
    g_d->mouse->near_block.y + 1, g_d->mouse->near_block.y + 1};

    for (int i = 0; i < 4; i++)
        if (mode == 0)
            g_d->map->height_array[y_arr[i]][x_arr[i]] +=
            g_d->mouse->locked * (TIME_MS(g_d->clock) / 10) * g_d->turbo_mode;
        else
            g_d->map->height_array[y_arr[i]][x_arr[i]] = 0;
}

void execute_hovered_action(data_t *g_d)
{
    if (!g_d->mouse->hover_action) {
        if (!g_d->mouse->hover_type)
            g_d->map->height_array
            [g_d->mouse->near_block.y][g_d->mouse->near_block.x] +=
            g_d->mouse->locked * (TIME_MS(g_d->clock) / 10) * g_d->turbo_mode;
        else
            lift_tile(g_d, 0);
    }
    if (g_d->mouse->hover_action == 1)
        g_d->map->blocks[g_d->mouse->near_block.y]
        [g_d->mouse->near_block.x].texture = g_d->mouse->apply_texture;
    if (g_d->mouse->hover_action == 2)
        lift_tile(g_d, 1);
    if (TIME_MS(g_d->clock) / 10 > 0)
        sfClock_restart(g_d->clock);
}