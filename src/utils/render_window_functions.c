/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** render_window_functions
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_render_win(char *title, int framerate)
{
    sfRenderWindow *win = sfRenderWindow_create((sfVideoMode){
        .bitsPerPixel = 32, .height = 1080, .width = 1920},
        title,
        sfFullscreen,
        NULL
    );

    sfRenderWindow_setFramerateLimit(win, framerate);
    return (win);
}