/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** make_isometric_map
*/

#include "my_world.h"
#include "my_world_macros.h"
#include <stdlib.h>
#include "libmy_functions.h"

sfVector2f make_iso_point(float x, float y, float z)
{
    sfVector2f new_vector = {0};
    const float rad_x = TO_RAD(25);
    const float rad_y = TO_RAD(30);

    new_vector.x = cosf(rad_x) * x - cosf(rad_x) * y;
    new_vector.y = sinf(rad_y) * y + sinf(rad_y) * x - z;
    return (new_vector);
}

static void append_lines(sfVertexArray **ptr, sfVector2i *coords, map_t *map,
int mode)
{
    int x = coords->x;
    int y = coords->y;

    if (mode)
        sfVertexArray_clear(*ptr);
    else
        *ptr = sfVertexArray_create();
    sfVertexArray_append(*ptr, (sfVertex){
        .position = map->points[y + 1][x], .color = sfWhite,
        .texCoords = (sfVector2f){0}});
    sfVertexArray_append(*ptr, (sfVertex){
        .position = map->points[y + 1][x + 1], .color = sfWhite,
        .texCoords = (sfVector2f){0}});
    sfVertexArray_append(*ptr, (sfVertex){
        .position = map->points[y][x + 1], .color = sfWhite,
        .texCoords = (sfVector2f){0}});
    sfVertexArray_setPrimitiveType(*ptr, sfLinesStrip);
}

static void append_vertex_square(sfVertexArray **ptr, sfVector2i *coords,
map_t *map, int mode)
{
    int x = coords->x;
    int y = coords->y;
    int y_pos[] = {0, 0, 1, 1};
    int x_pos[] = {0, 1, 1, 0};

    if (mode)
        sfVertexArray_clear(*ptr);
    else
        *ptr = sfVertexArray_create();
    for (int i = 0; i < 4; i++) {
        sfVertexArray_append(
            *ptr, (sfVertex){
            .position = map->points[y + y_pos[i]][x + x_pos[i]],
            .color = sfWhite,
            .texCoords = (sfVector2f){.x = 100 * x_pos[i],
            .y = 100 * y_pos[i]}});
    }
    sfVertexArray_setPrimitiveType(*ptr, sfQuads);
}

void refresh_map(map_t *map, int call_state)
{
    for (unsigned int y = 0; y < map->size.y; y++)
        for (unsigned int x = 0; x < map->size.x; x++)
            map->points[y][x] = make_iso_point(x * 50, y * 50,
            (float)map->height_array[y][x]);
    sfVertexArray_clear(map->far_lines);
    for (unsigned int y = map->size.y - 1; y + 1; y--)
        sfVertexArray_append(map->far_lines, (sfVertex){.color = sfWhite,
        .texCoords = {0}, .position = map->points[y][0]});
    for (unsigned int x = 0; x < map->size.x; x++)
        sfVertexArray_append(map->far_lines, (sfVertex){.color = sfWhite,
        .texCoords = {0}, .position = map->points[0][x]});
    for (unsigned int y = 0; y < map->size.y - 1; y++)
        for (unsigned int x = 0; x < map->size.x - 1; x++) {
            append_vertex_square(&map->blocks[y][x].square,
            (sfVector2i [1]){{x, y}}, map, call_state);
            append_lines(&map->blocks[y][x].lines,
            (sfVector2i [1]){{x, y}}, map, call_state);
        }
}

void make_map(map_t *map, int fd)
{
    map->height_array = gen_int_array(&map->size, 0);
    map->far_lines = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(map->far_lines, sfLineStrip);
    map->blocks = malloc(sizeof(void *) * (map->size.y));
    my_memset(map->blocks, sizeof(void *) * (map->size.y));
    map->points = malloc(sizeof(void *) * map->size.y);
    my_memset(map->points, sizeof(void *) * map->size.y);
    for (unsigned int y = 0; y < map->size.y; y++) {
        map->blocks[y] = malloc(sizeof(block_t) * (map->size.x));
        my_memset(map->blocks[y], sizeof(block_t) * (map->size.x));
        map->points[y] = malloc(sizeof(sfVector2f) * map->size.x);
        my_memset(map->points[y], sizeof(sfVector2f) * (map->size.x));
        for (unsigned int x = 0; x < map->size.x; x++)
            map->points[y][x] = make_iso_point(x, y,
            (float)map->height_array[y][x]);
    }
    if (fd > -1)
        get_save_data(map, fd);
    refresh_map(map, 0);
}