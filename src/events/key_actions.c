/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** key_actions
*/

#include "my_world.h"

static void other_actions(sfEvent *evt, data_t *g_d)
{
    if (evt->type == sfEvtKeyPressed) {
        if (evt->key.code == sfKeyEscape)
            g_d->bar->curr = 0;
        if (evt->key.code == sfKeyLControl)
            g_d->turbo_mode = 4;
        if (evt->key.code == sfKeyC) {
            g_d->mouse->hover_action = 0;
            g_d->mouse->hover_type = 0;
        }
        if (evt->key.code == sfKeyT) {
            g_d->mouse->hover_action = 0;
            g_d->mouse->hover_type = 1;
        }
        if (evt->key.code == sfKeyL) {
            g_d->mouse->hover_action = 2;
            g_d->mouse->hover_type = 1;
        }
        if (evt->key.code == sfKeyQ)
            sfRenderWindow_close(g_d->win);
    }
}

void key_actions(sfEvent *evt, data_t *g_d)
{
    other_actions(evt, g_d);
    if (evt->type == sfEvtKeyReleased)
        if (evt->key.code == sfKeyLControl)
            g_d->turbo_mode = 1;
}