/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myworld-owen.welte
** File description:
** menu.c
*/

#include "my_world.h"
#include "my_world_macros.h"
#include "libmy_macros.h"

void display_menu(data_t *g_d)
{
    sfRenderWindow_clear(g_d->win, sfBlack);
    sfRenderWindow_drawSprite(g_d->win, g_d->flags->menu_s, NULL);
    sfSprite_setPosition(g_d->flags->en_flag_s, (sfVector2f) {1640, 1030});
    sfRenderWindow_drawSprite(g_d->win, g_d->flags->en_flag_s, NULL);
    sfSprite_setPosition(g_d->flags->fr_flag_s, (sfVector2f) {1740, 1030});
    sfRenderWindow_drawSprite(g_d->win, g_d->flags->fr_flag_s, NULL);
    sfSprite_setPosition(g_d->flags->zu_flag_s, (sfVector2f) {1840, 1030});
    sfRenderWindow_drawSprite(g_d->win, g_d->flags->zu_flag_s, NULL);
    sfRenderWindow_drawText(g_d->win, g_d->flags->play_btn, NULL);
}

void display_tuto(data_t *gm_d)
{
    gm_d->state = STATE_EDIT;
    gm_d->win_view = sfView_createFromRect((sfFloatRect){.left =
    -600, .top = 0,
    .width = 1200, .height = 1200.0F * (1080.0F / 1980.0F)});
    sfRenderWindow_setView(gm_d->win, gm_d->win_view);
    sfRenderWindow_clear(gm_d->win, sfBlack);
    sfRenderWindow_drawSprite(gm_d->win, gm_d->tuto->tuto_bg, NULL);
    sfSprite_setPosition(gm_d->tuto->nao_face, (sfVector2f) {1650, 560});
    sfRenderWindow_drawSprite(gm_d->win, gm_d->tuto->nao_face, NULL);
    sfSprite_setPosition(gm_d->tuto->bubble, (sfVector2f) {1380, 330});
    sfRenderWindow_drawSprite(gm_d->win, gm_d->tuto->bubble, NULL);
    get_tuto_text(gm_d->lang, gm_d->tuto);
    sfRenderWindow_drawText(gm_d->win, gm_d->tuto->text, NULL);
}

static void display_help_text(data_t *g_d)
{
    sfFloatRect ts = {0};
    sfVector2f vsize = sfView_getSize(g_d->win_view);

    sfText_setScale(g_d->bar->hover, (sfVector2f)
    {vsize.x / 1920, vsize.y / 1080});
    ts = sfText_getGlobalBounds(g_d->bar->hover);
    sfText_setPosition(g_d->bar->hover, (sfVector2f){
    .x = g_d->mouse->coord.x - (ts.width / 2.F),
    .y = g_d->mouse->coord.y - (ts.height * 2.F)});
    sfRectangleShape_setPosition(g_d->bar->text_bg, (sfVector2f){
    .x = g_d->mouse->coord.x - (ts.width / 2.F) + (ts.width - ts.width * 1.02),
    .y = g_d->mouse->coord.y - (ts.height * 2.F) +
    (ts.height - ts.height * 1.02)});
    sfRectangleShape_setSize(g_d->bar->text_bg,
    (sfVector2f){ts.width * 1.04, ts.height * 1.02});
    sfRenderWindow_drawRectangleShape(g_d->win, g_d->bar->text_bg, NULL);
    sfRenderWindow_drawText(g_d->win, g_d->bar->hover, NULL);
}

void display_bar(data_t *g_d)
{
    sfVector2u wsize = sfRenderWindow_getSize(g_d->win);
    sfFloatRect ssize = {0};
    sfVector2f vsize = sfView_getSize(g_d->win_view);
    sfVector2f bar_pos = {0};

    sfSprite_setScale(g_d->bar->bar[g_d->bar->curr], (sfVector2f)
    {vsize.x / 1920, vsize.y / 1080});
    ssize = sfSprite_getLocalBounds(g_d->bar->bar[g_d->bar->curr]);
    bar_pos = sfRenderWindow_mapPixelToCoords(g_d->win,
    (sfVector2i){(wsize.x / 2) - (ssize.width / 2), wsize.y - ssize.height},
    g_d->win_view);
    sfSprite_setPosition(g_d->bar->bar[g_d->bar->curr], bar_pos);
    sfRenderWindow_drawSprite(g_d->win, g_d->bar->bar[g_d->bar->curr], NULL);
    if (g_d->bar->display_text)
        display_help_text(g_d);
}