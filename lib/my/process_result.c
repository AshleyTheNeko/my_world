/*
** EPITECH PROJECT, 2020
** Process result
** File description:
** processes result
*/

#include <stdarg.h>
#include <stdlib.h>
#include "libmy_functions.h"
#include "libmy_macros.h"
#include "libmy_structs.h"
#include "libmy_other_prototypes.h"

static void str_pushfront(char **to_push)
{
    char *copy = my_strdup(*to_push);

    free(*to_push);
    *to_push = malloc(my_strlen(copy) + 2);
    (*to_push)[0] = ' ';
    (*to_push)[1] = '\0';
    my_strcat(*to_push, copy);
    free(copy);
}

char *append_padding(form_t *args, char **in)
{
    char *output = malloc(sizeof(char) * my_strlen(*in) + args->padding + 1);
    int i = 0;

    my_strcpy(output, *in);
    free(*in);
    if (args->left_adj) {
        while (output[i] != '\0')
            i++;
        while (my_strlen(output) < args->padding) {
            output[i] = ' ';
            output[i + 1] = '\0';
            i++;
        }
    }
    if (!args->left_adj && !(args->zero_paded &&
    (args->converter > 10 || args->converter == 6))) {
        while (my_strlen(output) < args->padding) {
            str_pushfront(&output);
        }
    }
    return (output);
}

static char *char_string(char to_put)
{
    char *output = malloc(sizeof(char) * 2);

    output[0] = to_put;
    output[1] = '\0';
    return (output);
}

static char *my_null_strdup(char const *str)
{
    if (!str)
        return (my_strdup("(null)"));
    return (my_strdup(str));
}

char *get_result(form_t *format_arg, va_list *arg_list)
{
    char *tmp = NULL;

    if (format_arg->converter == 3)
        tmp = char_string((char)va_arg(*arg_list, int));
    if (format_arg->converter > 10 && format_arg->converter % 10 == 2)
        tmp = base_convert(format_arg, va_arg(*arg_list, long long), 1);
    if (format_arg->converter > 10 && format_arg->converter % 10 == 3)
        tmp = base_convert(format_arg, va_arg(*arg_list, long long), 0);
    if (format_arg->converter == 4)
        tmp = my_null_strdup(va_arg(*arg_list, char *));
    if (format_arg->converter == 5)
        tmp = my_octal_str(va_arg(*arg_list, char *));
    if (format_arg->converter == 6)
        tmp = my_hexa_ptr(va_arg(*arg_list, void *), format_arg);
    return (append_padding(format_arg, &tmp));
}