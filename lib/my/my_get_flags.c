/*
** EPITECH PROJECT, 2020
** Flag processing
** File description:
** processes flags
*/

#include "libmy_functions.h"
#include "libmy_structs.h"
#include "libmy_other_prototypes.h"

char is_flag(char format, form_t *format_arg)
{
    switch (format) {
        case '#':
            format_arg->alt = 1;
            return (1);
        case '0':
            format_arg->zero_paded = 1;
            return (1);
        case ' ':
            format_arg->space = 1;
            return (1);
        case '+':
            format_arg->sign = 1;
            return (1);
        case '-':
            format_arg->left_adj = 1;
            return (1);
        case '\'':
            return (1);
    }
    return (0);
}

int get_precision(char *format, form_t *format_arg)
{
    int i = 0;
    int precision = 0;

    if (format[0] == '.') {
        format = &format[1];
        if (format[i] <= '9' || format[i] >= '0') {
            precision = my_atoi(format, 0);
            format_arg->precision = precision;
            return (my_baselen(precision, 10) + 1);
        }
        return (1);
    }
    return (0);
}

int get_width(char *format, form_t *format_arg)
{
    int i = 0;
    int padding = 0;

    if (format[i] <= '9' && format[i] > '0') {
        padding = my_atoi(format, 0);
        format_arg->padding = padding;
        return (my_baselen(padding, 10));
    }
    return (0);
}

int get_lm(char *format, form_t *form_arg)
{
    form_arg->lm = 0;
    if (my_strncmp(format, "hh", 2) == 0)
        form_arg->lm = 1;
    if (my_strncmp(format, "ll", 2) == 0)
        form_arg->lm = 2;
    if (form_arg->lm)
        return (2);
    switch (format[0]) {
        case 'h':
            form_arg->lm = 3;
            return (1);
        case 'l':
            form_arg->lm = 4;
            return (1);
        case 'j':
        case 'z':
        case 't':
            return (1);
        default:
            return (0);
    }
}

int get_flags(char *format, form_t *format_arg)
{
    int i = 0;

    while (is_flag(format[i], format_arg))
        i++;
    i += get_width(&format[i], format_arg);
    i += get_precision(&format[i], format_arg);
    i += get_lm(&format[i], format_arg);
    get_converter(format[i], format_arg);
    if (format_arg->converter == 0)
        return (0);
    return (i + 2);
}