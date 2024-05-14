/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** hovering_display
*/

#include "my_world.h"
#include "my_world_macros.h"
#include <SFML/Graphics.h>
#include <math.h>

static void make_dot_hover(data_t *g_d)
{
    sfVector2f center = g_d->map->points
    [g_d->mouse->near_block.y][g_d->mouse->near_block.x];

    sfVertexArray_clear(g_d->mouse->hover_display);
    sfVertexArray_append(g_d->mouse->hover_display, (sfVertex){
        .color = sfRed, .texCoords = (sfVector2f){0}, .position = center});
    for (int i = 0; i <= 360; i += 10)
        sfVertexArray_append(g_d->mouse->hover_display, (sfVertex){
            .color = sfRed, .texCoords = (sfVector2f){0},
            .position = (sfVector2f){
                .x = 3 * cosf(TO_RAD(i)) - 3 * sinf(TO_RAD(i)) + center.x,
                .y = 3 * sinf(TO_RAD(i)) + 3 * cosf(TO_RAD(i)) + center.y,
            }});
    sfVertexArray_setPrimitiveType(g_d->mouse->hover_display,
    sfTriangleFan);
}

static void make_hover_tile(data_t *g_d)
{
    sfVector2i ppos = g_d->mouse->near_block;
    sfVector2f points[4] = {g_d->map->points[ppos.y][ppos.x],
    g_d->map->points[ppos.y][ppos.x + 1],
    g_d->map->points[ppos.y + 1][ppos.x + 1],
    g_d->map->points[ppos.y + 1][ppos.x]};

    sfVertexArray_clear(g_d->mouse->hover_display);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(g_d->mouse->hover_display, (sfVertex){
            .color = {.a = 85, .r = 255}, .texCoords = {0},
            .position = points[i]});
    sfVertexArray_setPrimitiveType(g_d->mouse->hover_display, sfQuads);
}

void make_hover_texture(data_t *g_d)
{
    if (g_d->mouse->hover_type)
        make_hover_tile(g_d);
    else
        make_dot_hover(g_d);
}