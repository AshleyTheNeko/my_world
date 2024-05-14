/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** read_save
*/

#include <unistd.h>
#include "libmy_macros.h"
#include "my_world_structs.h"

void get_int(int *storage, int fd)
{
    char ch = 0;
    int number = 0;
    char sign = 1;

    while (read(fd, &ch, 1) > 0 && (NBR(ch) || ch == '-')) {
        if (ch == '-')
            sign = -1;
        else {
            number *= 10;
            number += ch - '0';
        }
    }
    *storage = number * sign;
}

void get_save_data(map_t *map, int fd)
{
    for (unsigned int y = 0; y < map->size.y; y++)
        for (unsigned int x = 0; x < map->size.x; x++)
            get_int(&map->height_array[y][x], fd);
    for (unsigned int y = 0; y < (map->size.y - 1); y++)
        for (unsigned int x = 0; x < (map->size.x - 1); x++) {
            get_int(&map->blocks[y][x].texture, fd);
            map->blocks[y][x].texture =
            map->blocks[y][x].texture > 2 || map->blocks[y][x].texture < 0 ? 0
            : map->blocks[y][x].texture;
        }
}