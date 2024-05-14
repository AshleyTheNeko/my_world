/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** view_manager
*/

#include "my_world.h"
#include "my_world_macros.h"

void manage_move_zoom(sfView *view, sfEvent *events, int turbo)
{
    const int move_speed = 5 * turbo;
    const sfVector2f moves[4] = {
        {.x = -1 * move_speed, .y = 0}, {.x = move_speed, .y = 0},
        {.x = 0, .y = -1 * move_speed}, {.x = 0, .y = move_speed}};

    if (events->type == sfEvtKeyPressed)
        if (events->key.code >= sfKeyLeft && events->key.code <= sfKeyDown)
            sfView_move(view, moves[events->key.code - sfKeyLeft]);
    if (events->type == sfEvtMouseWheelScrolled) {
        if (events->mouseWheelScroll.delta < 0.0f)
            sfView_zoom(view, sfView_getSize(view).x < 3000 ? 1.09 : 1);
        else
            sfView_zoom(view, sfView_getSize(view).x > 100 ? 0.91 : 1);
    }
}