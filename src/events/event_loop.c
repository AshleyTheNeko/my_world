/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** event_loop
*/

#include "my_world.h"
#include "my_world_macros.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int change_lang(data_t *g_d, sfEvent *e)
{
    sfVector2f m_pos = sfRenderWindow_mapPixelToCoords(
    g_d->win, (sfVector2i){e->mouseButton.x, e->mouseButton.y}, g_d->win_view);
    sfFloatRect mouse = {.height = 1, .width = 1,
    .top = m_pos.y, .left = m_pos.x};
    sfFloatRect flag = {0};
    sfSprite *flags[3] =
    {g_d->flags->en_flag_s, g_d->flags->fr_flag_s, g_d->flags->zu_flag_s};

    for (long unsigned int i = 0; i < sizeof(flags) / sizeof(*flags); i++) {
        flag = sfSprite_getGlobalBounds(flags[i]);
        if (sfFloatRect_intersects(&mouse, &flag, NULL)) {
            g_d->lang->curr_lang = i;
            init_play(g_d->lang, g_d->flags, g_d->win);
            return (i);
        }
    }
    return (g_d->lang->curr_lang);
}

static int update_state(data_t *g_d, sfEvent *e)
{
    sfVector2f m_pos = sfRenderWindow_mapPixelToCoords(
    g_d->win, (sfVector2i){e->mouseButton.x, e->mouseButton.y}, g_d->win_view);
    sfFloatRect mouse = {.height = 1, .width = 1,
    .top = m_pos.y, .left = m_pos.x};
    sfFloatRect text = sfText_getGlobalBounds(g_d->flags->play_btn);
    int fd = 0;

    if (sfFloatRect_intersects(&mouse, &text, NULL)) {
        fd = open(get_lang(g_d->lang, "alias_map"), O_RDONLY);
        if (fd != -1) {
            close(fd);
            g_d->win_view = sfView_createFromRect((sfFloatRect){.left =
            -600, .top = 0,
            .width = 1200, .height = 1200.0F * (1080.0F / 1980.0F)});
            sfRenderWindow_setView(g_d->win, g_d->win_view);
            return (STATE_EDIT);
        }
        return (STATE_TUTO);
    }
    return (g_d->state);
}

static int update_text_tuto(data_t *g_d, sfEvent *e)
{
    sfVector2f m_pos = sfRenderWindow_mapPixelToCoords(
    g_d->win, (sfVector2i){e->mouseButton.x, e->mouseButton.y}, g_d->win_view);
    sfFloatRect mouse = {.height = 1, .width = 1,
    .top = m_pos.y, .left = m_pos.x};
    sfFloatRect bubble = sfSprite_getGlobalBounds(g_d->tuto->bubble);

    if (sfFloatRect_intersects(&mouse, &bubble, NULL))
        return (g_d->tuto->curr_text + 1);
    return (g_d->tuto->curr_text);
}

static void click_check(data_t *g_d, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed && g_d->state == STATE_EDIT) {
        if (bar_clicked(g_d, event))
            return;
        sfClock_restart(g_d->clock);
        g_d->mouse->locked = event->mouseButton.button == sfMouseLeft ? 1 : -1;
    }
    if (event->type == sfEvtMouseButtonReleased) {
        g_d->mouse->locked = 0;
    }
    if (event->type == sfEvtMouseButtonPressed && g_d->state == STATE_TUTO)
        g_d->tuto->curr_text = update_text_tuto(g_d, event);
    if (event->type == sfEvtMouseButtonPressed && g_d->state == STATE_MENU)
        g_d->lang->curr_lang = change_lang(g_d, event);
    if (event->type == sfEvtMouseButtonPressed && g_d->state == STATE_MENU)
        g_d->state = update_state(g_d, event);
}

void window_event_loop(data_t *g_d)
{
    sfEvent event;
    int bar = 0;

    while (sfRenderWindow_pollEvent(g_d->win, &event) == sfTrue) {
        g_d->mouse->coord = sfRenderWindow_mapPixelToCoords(g_d->win,
        sfMouse_getPositionRenderWindow(g_d->win), g_d->win_view);
        if (g_d->state == STATE_EDIT)
            manage_move_zoom(g_d->win_view, &event, g_d->turbo_mode);
        if (event.type == sfEvtMouseMoved && g_d->state == STATE_EDIT) {
            bar = bar_hover(g_d);
            find_hover_block(g_d, bar);
        }
        key_actions(&event, g_d);
        if (event.type == sfEvtMouseButtonPressed ||
        event.type == sfEvtMouseButtonReleased)
            click_check(g_d, &event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g_d->win);
        g_d->mouse->coord = sfRenderWindow_mapPixelToCoords(g_d->win,
        sfMouse_getPositionRenderWindow(g_d->win), g_d->win_view);
    }
}