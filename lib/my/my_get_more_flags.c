/*
** EPITECH PROJECT, 2020
** Conversions
** File description:
** converts
*/

#include "libmy_structs.h"
#include "libmy_other_prototypes.h"

static void get_converter_next(char format, form_t *form_arg)
{
    switch (format) {
        case 'X':
            form_arg->converter = 163;
            break;
        case 'c':
            form_arg->converter = 3;
            break;
        case 's':
            form_arg->converter = 4;
            break;
        case 'S':
            form_arg->converter = 5;
            break;
        case 'p':
            form_arg->converter = 6;
            break;
        default:
            form_arg->converter = 0;
            break;
    }
}

void get_converter(char format, form_t *form_arg)
{
    switch (format) {
        case 'd':
        case 'i':
        case 'u':
            form_arg->converter = 102;
            break;
        case 'b':
            form_arg->converter = 22;
            break;
        case 'o':
            form_arg->converter = 82;
            break;
        case 'x':
            form_arg->converter = 162;
            break;
        default:
            get_converter_next(format, form_arg);
    }
}