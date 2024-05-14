/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** hovering
*/

#include "my_world.h"
#include <SFML/Graphics.h>
#include "libmy_functions.h"

static int find_dot(data_t *game_data, unsigned int x, unsigned int y)
{
    float d_x = game_data->map->points[y][x].x - game_data->mouse->coord.x;
    float d_y = game_data->map->points[y][x].y - game_data->mouse->coord.y;

    if (d_x < 5.0F && d_x > -5.0F && d_y < 5.0F && d_y > -5.0F) {
        game_data->mouse->near_block = (sfVector2i){x, y};
        game_data->mouse->block_found = 1;
        return (0);
    }
    return (1);
}

static float get_sign(sfVector2f *p1, sfVector2f *p2, sfVector2f *p3)
{
    return ((p1->x - p3->x) * (p2->y - p3->y) -
    (p2->x - p3->x) * (p1->y - p3->y));
}

static int is_in_triangle(sfVector2f *pt, sfVector2f triangle[3])
{
    float d1 = 0;
    float d2 = 0;
    float d3 = 0;
    int has_neg = 0;
    int has_pos = 0;

    d1 = get_sign(pt, &triangle[0], &triangle[1]);
    d2 = get_sign(pt, &triangle[1], &triangle[2]);
    d3 = get_sign(pt, &triangle[2], &triangle[0]);
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return (!(has_neg && has_pos));
}

static int find_block(data_t *game_data, unsigned int x, unsigned int y)
{
    sfVector2f triangle1[3] = {0};
    sfVector2f triangle2[3] = {0};

    if (x >= game_data->map->size.x - 1 || y >= game_data->map->size.y - 1)
        return (1);
    if (!is_in_view(game_data, x, y))
        return (1);
    my_memcpy(triangle1, (sfVector2f [3]){game_data->map->points[y + 1][x],
    game_data->map->points[y][x], game_data->map->points[y][x + 1]},
    sizeof(sfVector2f) * 3);
    my_memcpy(triangle2, (sfVector2f [3]){game_data->map->points[y + 1][x],
    game_data->map->points[y + 1][x + 1], game_data->map->points[y][x + 1]},
    sizeof(sfVector2f) * 3);
    if (is_in_triangle(&game_data->mouse->coord, triangle1) ||
    is_in_triangle(&game_data->mouse->coord, triangle2)) {
        game_data->mouse->near_block = (sfVector2i){.x = x, .y = y};
        game_data->mouse->block_found = 1;
        return (0);
    }
    return (1);
}

void find_hover_block(data_t *game_data, int bar)
{
    int (*fptr[])(data_t *, unsigned int, unsigned int) =
    {find_dot, find_block};
    int s = 1;

    if (bar)
        return;
    for (unsigned int y = game_data->map->size.y - 1; y + 1 && s; y--)
        for (unsigned int x = game_data->map->size.x - 1; x + 1 && s; x--)
            s = fptr[game_data->mouse->hover_type](game_data, x, y);
    if (s) {
        game_data->mouse->block_found = 0;
        sfClock_restart(game_data->clock);
    }
}