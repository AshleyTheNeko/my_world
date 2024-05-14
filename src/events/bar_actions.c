/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** bar_actions
*/

#include "my_world.h"

static void opt_bar(data_t *g_d, sfVector2f *click, sfFloatRect *ssize)
{
    if (click->x < (ssize->left + (ssize->width / 4))) {
        g_d->map->render_textures = g_d->map->render_textures ? 0 : 1;
        return;
    }
    if (click->x < (ssize->left + (ssize->width / 2))) {
        if (g_d->map->size.x < 200)
            resize_map(g_d->map, 1);
        return;
    }
    if (click->x < (ssize->left + (ssize->width / 4) * 3)) {
        if (g_d->map->size.x > 2)
            resize_map(g_d->map, -1);
        return;
    }
}

static void texture_bar(data_t *g_d, sfVector2f *click, sfFloatRect *ssize)
{
    if (click->x < (ssize->left + (ssize->width / 4))) {
        g_d->mouse->hover_action = 1;
        g_d->mouse->hover_type = 1;
        g_d->mouse->apply_texture = 0;
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 2))) {
        g_d->mouse->hover_action = 1;
        g_d->mouse->hover_type = 1;
        g_d->mouse->apply_texture = 1;
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 4) * 3)) {
        g_d->mouse->hover_action = 1;
        g_d->mouse->hover_type = 1;
        g_d->mouse->apply_texture = 2;
        return;
    }
}

static void select_bar(data_t *g_d, sfVector2f *click, sfFloatRect *ssize)
{
    if (click->x < (ssize->left + (ssize->width / 4))) {
        g_d->mouse->hover_action = 0;
        g_d->mouse->hover_type = 0;
        return;
    }
    if (click->x < ssize->left + (ssize->width / 2)) {
        g_d->mouse->hover_action = 0;
        g_d->mouse->hover_type = 1;
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 4) * 3)) {
        g_d->mouse->hover_action = 2;
        g_d->mouse->hover_type = 1;
    }
}

static void edit_bar(data_t *g_d, sfVector2f *click, sfFloatRect *ssize)
{
    if (click->x < (ssize->left + (ssize->width / 4))) {
        g_d->bar->curr = 3;
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 4) * 2)) {
        g_d->bar->curr = 1;
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 4) * 3)) {
        g_d->bar->curr = 2;
        return;
    }
    if (click->x < ssize->left + ssize->width)
        save_map(g_d, -1);
}

int bar_clicked(data_t *g_d, sfEvent *event)
{
    sfFloatRect b_size =
    sfSprite_getGlobalBounds(g_d->bar->bar[g_d->bar->curr]);
    sfVector2f mouse_p = sfRenderWindow_mapPixelToCoords(g_d->win,
    (sfVector2i){event->mouseButton.x, event->mouseButton.y}, g_d->win_view);
    void (*bars[4])(data_t *, sfVector2f *, sfFloatRect *) =
    {edit_bar, select_bar, texture_bar, opt_bar};

    if (mouse_p.y > b_size.top &&
    mouse_p.y < b_size.top + b_size.height)
        if (mouse_p.x > b_size.left && mouse_p.x <
        b_size.left + b_size.width) {
            bars[g_d->bar->curr](g_d, &mouse_p, &b_size);
            return (1);
        }
    return (0);
}