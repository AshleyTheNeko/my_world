/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** bar_hovering
*/

#include "my_world.h"

static void opt_bar(data_t *g_d, sfVector2f *click, sfFloatRect *ssize)
{
    if (click->x < (ssize->left + (ssize->width / 4))) {
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "show_text"));
        return;
    }
    if (click->x < (ssize->left + (ssize->width / 2))) {
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "add_line"));
        return;
    }
    if (click->x < (ssize->left + (ssize->width / 4) * 3))
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "remove_line"));
}

static void texture_bar(data_t *g_d, sfVector2f *click, sfFloatRect *ssize)
{
    if (click->x < (ssize->left + (ssize->width / 4))) {
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "apply_grass"));
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 2))) {
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "apply_cobble"));
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 4) * 3))
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "apply_sand"));
}

static void select_bar(data_t *g_d, sfVector2f *click, sfFloatRect *ssize)
{
    if (click->x < (ssize->left + (ssize->width / 4))) {
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "select_corn"));
        return;
    }
    if (click->x < ssize->left + (ssize->width / 2)) {
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "select_tiles"));
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 4) * 3))
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "level_tiles"));
}

static void edit_bar(data_t *g_d, sfVector2f *click, sfFloatRect *ssize)
{
    if (click->x < (ssize->left + (ssize->width / 4))) {
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "map_opt"));
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 4) * 2)) {
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "select_opt"));
        return;
    }
    if (click->x < ssize->left + ((ssize->width / 4) * 3)) {
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "apply_textu"));
        return;
    }
    if (click->x < ssize->left + ssize->width)
        sfText_setString(g_d->bar->hover, get_lang(g_d->lang, "save_map"));
}

int bar_hover(data_t *g_d)
{
    sfFloatRect b_size =
    sfSprite_getGlobalBounds(g_d->bar->bar[g_d->bar->curr]);
    sfVector2f mouse_p = g_d->mouse->coord;
    void (*bars[4])(data_t *, sfVector2f *, sfFloatRect *) =
    {edit_bar, select_bar, texture_bar, opt_bar};

    if (mouse_p.y > b_size.top &&
    mouse_p.y < b_size.top + b_size.height)
        if (mouse_p.x > b_size.left && mouse_p.x <
        b_size.left + b_size.width) {
            bars[g_d->bar->curr](g_d, &mouse_p, &b_size);
            g_d->bar->display_text = 1;
            return (1);
        }
    g_d->bar->display_text = 0;
    return (0);
}