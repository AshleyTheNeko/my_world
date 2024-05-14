/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myworld-owen.welte
** File description:
** init_taskbar.c
*/

#include "my_world.h"
#include <malloc.h>

bar_edit_t *init_bar(void)
{
    bar_edit_t *bar = malloc(sizeof(bar_edit_t));

    sfTexture *br = sfTexture_createFromFile("./assets/png/taskbar.png", NULL);
    sfTexture *br_shape = sfTexture_createFromFile("./assets/png/taskbar_"
    "shape.png", NULL);
    sfTexture *br_textu = sfTexture_createFromFile("./assets/png/taskbar_"
    "textu.png", NULL);
    sfTexture *br_opt = sfTexture_createFromFile("assets/png/takbar_"
    "options.png", NULL);

    bar->bar = malloc(sizeof(sfSprite *) * 5);
    for (int i = 0; i < 4; ++i)
        bar->bar[i] = sfSprite_create();
    bar->bar[4] = NULL;
    sfSprite_setTexture(bar->bar[0], br, sfFalse);
    sfSprite_setTexture(bar->bar[1], br_shape, sfFalse);
    sfSprite_setTexture(bar->bar[2], br_textu, sfFalse);
    sfSprite_setTexture(bar->bar[3], br_opt, sfFalse);
    bar->curr = 0;
    return (bar);
}