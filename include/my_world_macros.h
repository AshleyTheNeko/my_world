/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** my_world_macros
*/

#ifndef MY_WORLD_MACROS_H_
#define MY_WORLD_MACROS_H_

#include <math.h>
#include "libmy_functions.h"
#include <SFML/Graphics.h>

#define UNUSED __attribute__((unused))

#define TO_RAD(deg) ((deg) * (M_PI / 180.0f))

#define TIME_MS(clock) sfTime_asMilliseconds(sfClock_getElapsedTime(clock))

enum states {
    STATE_MENU,
    STATE_TUTO,
    STATE_EDIT,
    STATE_QUIT
};

enum langs {
    EN_LANG,
    FR_LANG,
    ZU_LANG
};

#define SUCCESS_EXIT 0
#define ERROR_EXIT 84

#define DISPLAY_PREFIX "DISPLAY="
#define NO_ENV "The program had been launch without environnement.\n"

#define LEN(str) (my_strlen(str))
#define FILE_NOT_FOUND "Error while opening file: file not found.\n"

#endif /* !MY_WORLD_MACROS_H_ */