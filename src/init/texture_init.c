/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myworld-owen.welte
** File description:
** texture_init.c
*/

#include "my_world.h"
#include "my_world_macros.h"
#include <stdlib.h>

text_t *init_text_t(void)
{
    text_t *text_info = malloc(sizeof(text_t));
    char **lang_array = malloc(sizeof(char *) * 4);
    char *my_array[4] = {"en", "fr", "zu", NULL};
    int i;
    int x;

    for (i = 0; my_array[i]; i++) {
        lang_array[i] = malloc(sizeof(char) * 3);
        for (x = 0; x < 3; x++)
            lang_array[i][x] = my_array[i][x];
    }
    lang_array[i] = NULL;
    text_info->curr_lang = EN_LANG;
    text_info->langs = lang_array;
    text_info->tuto_path = "./assets/lyrics/tuto_marvin.legend.";
    text_info->elem_path = "./assets/text_elem/voc.legend.";
    return text_info;
}

void init_play(text_t *lang, flags_st *flag, sfRenderWindow *win)
{
    sfFloatRect tsize;
    sfVector2u wsize = sfRenderWindow_getSize(win);

    sfText_setFont(flag->play_btn, flag->font);
    sfText_setString(flag->play_btn, get_lang(lang, "play_btn"));
    sfText_setColor(flag->play_btn, sfBlack);
    sfText_setStyle(flag->play_btn, sfTextBold);
    sfText_setCharacterSize(flag->play_btn, 40);
    tsize = sfText_getGlobalBounds(flag->play_btn);
    sfText_setPosition(flag->play_btn, (sfVector2f)
    {.x = (wsize.x / 2) - (tsize.width / 2.F), .y = 850});
}

flags_st *init_flags_struct(void)
{
    flags_st *flg = malloc(sizeof(flags_st));
    sfTexture *en_flag = sfTexture_createFromFile("./assets/png/en.png", NULL);
    sfTexture *fr_flag = sfTexture_createFromFile("./assets/png/fr.png", NULL);
    sfTexture *zu_flag = sfTexture_createFromFile("./assets/png/zu.png", NULL);

    flg->menu_t = sfTexture_createFromFile("./assets/png/menu.png", NULL);
    flg->en_flag_s = sfSprite_create();
    flg->fr_flag_s = sfSprite_create();
    flg->zu_flag_s = sfSprite_create();
    flg->menu_s = sfSprite_create();
    sfSprite_setTexture(flg->en_flag_s, en_flag, sfFalse);
    sfSprite_setTexture(flg->fr_flag_s, fr_flag, sfFalse);
    sfSprite_setTexture(flg->zu_flag_s, zu_flag, sfFalse);
    sfSprite_setTexture(flg->menu_s, flg->menu_t, sfFalse);
    flg->font = sfFont_createFromFile("./assets/font.ttf");
    flg->play_btn = sfText_create();
    return flg;
}

tuto_t *init_tuto(void)
{
    tuto_t *tuto = malloc(sizeof(tuto_t));
    sfTexture *bub = sfTexture_createFromFile("./assets/png/bubble.png", NULL);
    sfTexture *n_f = sfTexture_createFromFile("./assets/png/n_face.png", NULL);
    sfTexture *n_s = sfTexture_createFromFile("./assets/png/n_side.png", NULL);
    sfTexture *bg = sfTexture_createFromFile("./assets/png/menu.png", NULL);

    tuto->bubble = sfSprite_create();
    tuto->nao_face = sfSprite_create();
    tuto->nao_side = sfSprite_create();
    tuto->tuto_bg = sfSprite_create();
    sfSprite_setTexture(tuto->bubble, bub, sfFalse);
    sfSprite_setTexture(tuto->nao_face, n_f, sfFalse);
    sfSprite_setTexture(tuto->nao_side, n_s, sfFalse);
    sfSprite_setTexture(tuto->tuto_bg, bg, sfFalse);
    sfSprite_setScale(tuto->nao_face, (sfVector2f){0.4, 0.4});
    sfSprite_setScale(tuto->bubble, (sfVector2f){0.6, 0.3});
    tuto->font = sfFont_createFromFile("./assets/font.ttf");
    tuto->text = sfText_create();
    tuto->curr_text = 0;
    tuto->end = false;
    return tuto;
}

void init_tuto_txt(tuto_t *tut, char *src)
{
    sfText_setFont(tut->text, tut->font);
    sfText_setString(tut->text, NULL);
    sfText_setString(tut->text, src);
    sfText_setColor(tut->text, sfBlack);
    sfText_setStyle(tut->text, sfTextBold);
    sfText_setPosition(tut->text, (sfVector2f){1410, 390});
    sfText_setCharacterSize(tut->text, 22);
}