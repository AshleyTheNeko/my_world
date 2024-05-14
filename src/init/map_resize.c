/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** map_resize
*/

#include "my_world.h"
#include <stdlib.h>
#include "libmy_functions.h"

static void copy_map(map_t *map, int mode)
{
    int **old_map = map->height_array;
    map->height_array = gen_int_array(&map->size, 0);
    for (unsigned int y = 0; y < map->size.y - 1 + (mode < 0); y++)
        for (unsigned int x = 0; x < map->size.x - 1 + (mode < 0); x++)
            map->height_array[y][x] = old_map[y][x];
    for (unsigned int y = 0; y < map->size.y - 1 + (mode < 0); y++)
        free(old_map[y]);
    free(old_map);
}

static void copy_blocks(map_t *map, int mode)
{
    block_t **old_blocks = map->blocks;

    map->blocks = malloc(sizeof(void *) * map->size.y);
    my_memset(map->blocks, sizeof(void *) * map->size.y);
    for (unsigned int y = 0; y < map->size.y; y++) {
        map->blocks[y] = malloc(sizeof(block_t) * (map->size.x));
        my_memset(map->blocks[y], sizeof(block_t) * (map->size.x));
    }
    for (unsigned int y = 0; y < map->size.y - (2 - (mode < 0)); y++)
        for (unsigned int x = 0; x < map->size.x - (2 - (mode < 0)); x++)
            map->blocks[y][x].texture = old_blocks[y][x].texture;
    for (unsigned int y = 0; y < map->size.y - 1 + (mode < 0); y++) {
        for (unsigned int x = 0; x < map->size.x - 1 + (mode < 0); x++) {
            sfVertexArray_destroy(old_blocks[y][x].lines);
            sfVertexArray_destroy(old_blocks[y][x].square);
        }
        free(old_blocks[y]);
    }
    free(old_blocks);
}

static void alloc_points(map_t *map, int mode)
{
    for (unsigned int y = 0; y < map->size.y - 1 + (mode < 0); y++)
        free(map->points[y]);
    free(map->points);
    map->points = malloc(sizeof(void *) * map->size.y);
    my_memset(map->points, sizeof(void *) * map->size.y);
    for (unsigned int y = 0; y < map->size.y; y++) {
        map->points[y] = malloc(sizeof(sfVector2f) * map->size.x);
        my_memset(map->points[y], sizeof(sfVector2f) * (map->size.x));
        for (unsigned int x = 0; x < map->size.x; x++)
            map->points[y][x] = make_iso_point(x, y,
            (float)map->height_array[y][x]);
    }
}

void resize_map(map_t *map, int mode)
{
    map->size.x += mode;
    map->size.y += mode;
    copy_map(map, mode);
    copy_blocks(map, mode);
    alloc_points(map, mode);
    refresh_map(map, 0);
}