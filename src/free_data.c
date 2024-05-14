/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** free_data
*/

#include "my_world.h"

void free_map(data_t *g_d)
{
    if (!g_d)
        return;
    if (!g_d->map)
        return;
    if (!g_d->map->height_array)
        return;
}