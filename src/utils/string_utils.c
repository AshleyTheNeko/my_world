/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myworld-owen.welte
** File description:
** string_utils.c
*/

#include "my_world.h"
#include "libmy_functions.h"

char start_with(char const *start, char const *str)
{
    if (start == NULL || str == NULL)
        return 0;
    if (my_strlen(start) > my_strlen(str))
        return 0;
    for (int i = 0; i < my_strlen(start); i++) {
        if (start[i] != str[i])
            return 0;
    }
    return 1;
}