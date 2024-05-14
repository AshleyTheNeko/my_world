/*
** EPITECH PROJECT, 2020
** My printf
** File description:
** it's mine
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmy_functions.h"
#include "libmy_macros.h"
#include "libmy_structs.h"
#include "libmy_other_prototypes.h"

static void replace_index(char **target, char *replacement, int beg, int end)
{
    char *copy = my_strdup(*target);

    free(*target);
    *target = malloc(my_strlen(copy) + my_strlen(replacement));
    my_strncpy(*target, copy, beg);
    my_strcat(*target, replacement);
    my_strcat(*target, &copy[end]);
    free(copy);
}

static int parse_percent(char **format, int i, va_list *arg_list)
{
    form_t format_arg = {0};
    char *res = NULL;
    int flag_len = 0;
    int size = 0;

    if ((*format)[i + 1] == '%') {
        replace_index(format, "%", i, i + 2);
        return (1);
    }
    if (!(flag_len = get_flags(&(*format)[i + 1], &format_arg)))
        return (1);
    res = get_result(&format_arg, arg_list);
    replace_index(format, res, i, i + flag_len);
    size = my_strlen(res);
    free(res);
    return (size);
}

int my_printf(const char *format, ...)
{
    int i = 0;
    char *copy = my_strdup(format);
    va_list arg_list = {0};
    int size = 0;

    va_start(arg_list, format);
    while (copy[i] != '\0') {
        if (copy[i] == '%')
            i += parse_percent(&copy, i, &arg_list);
        else
            i++;
    }
    va_end(arg_list);
    my_putstr(copy);
    size = my_strlen(copy);
    free(copy);
    return (size);
}

int my_sprintf(char **string, const char *format, ...)
{
    int i = 0;
    char *copy = my_strdup(format);
    va_list arg_list;
    int size;

    va_start(arg_list, format);
    while (copy[i] != '\0') {
        if (copy[i] == '%')
            i += parse_percent(&copy, i, &arg_list);
        else
            i++;
    }
    va_end(arg_list);
    size = my_strlen(copy);
    if (*string)
        free(*string);
    *string = my_strdup(copy);
    free(copy);
    return (size);
}

int my_dprintf(const int file_descriptor, const char *format, ...)
{
    int i = 0;
    char *copy = my_strdup(format);
    va_list arg_list;
    int size;

    va_start(arg_list, format);
    while (copy[i] != '\0') {
        if (copy[i] == '%')
            i += parse_percent(&copy, i, &arg_list);
        else
            i++;
    }
    va_end(arg_list);
    size = my_strlen(copy);
    my_dputstr(copy, file_descriptor);
    free(copy);
    return (size);
}