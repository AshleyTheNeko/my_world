/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** write_save
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libmy_functions.h"
#include "my_world.h"

void save_map(data_t *data, int force_fd)
{
    int fd = force_fd;

    if (force_fd == -1)
        fd = open(get_lang(data->lang, "alias_map"), O_WRONLY | O_CREAT, 0644);
    if (fd < 0)
        return;
    my_dprintf(fd, "%d %d", data->map->size.x, data->map->size.y);
    for (unsigned int y = 0; y < data->map->size.y; y++)
        for (unsigned int x = 0; x < data->map->size.x; x++)
            my_dprintf(fd, "\n%d", data->map->height_array[y][x]);
    for (unsigned int y = 0; y < data->map->size.y - 1; y++)
        for (unsigned int x = 0; x < data->map->size.x - 1; x++)
            my_dprintf(fd, "\n%d", data->map->blocks[y][x].texture);
    close(fd);
}