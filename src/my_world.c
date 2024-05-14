/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** first file
*/

#include "libmy_functions.h"
#include "my_world.h"
#include "my_world_macros.h"

static int check_display_env(const char **env)
{
    for (int i = 0; env[i]; i++)
        if (start_with(DISPLAY_PREFIX, env[i]))
            return SUCCESS_EXIT;
    return ERROR_EXIT;
}

static void display_state(data_t *g_d)
{
    if (g_d->state == STATE_MENU)
        display_menu(g_d);
    if (g_d->state == STATE_TUTO)
        display_tuto(g_d);
    if (g_d->state == STATE_EDIT) {
        if (g_d->mouse->locked != 0 && g_d->mouse->block_found)
            execute_hovered_action(g_d);
        refresh_map(g_d->map, 1);
        sfRenderWindow_clear(g_d->win, (sfColor){35, 35, 35, 1});
        sfRenderWindow_setView(g_d->win, g_d->win_view);
        draw_vertexes(g_d);
        display_bar(g_d);
    }
}

int my_world(char const **env)
{
    data_t game_data = {0};

    if (check_display_env(env) != SUCCESS_EXIT) {
        my_dputstr(NO_ENV, 2);
        return (84);
    }
    initialize_global_structure(&game_data);
    while (sfRenderWindow_isOpen(game_data.win)) {
        window_event_loop(&game_data);
        display_state(&game_data);
        sfRenderWindow_display(game_data.win);
    }
    save_map(&game_data, 0);
    sfRenderWindow_destroy(game_data.win);
    return (0);
}