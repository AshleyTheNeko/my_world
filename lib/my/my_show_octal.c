/*
** EPITECH PROJECT, 2020
** My show octal
** File description:
** it's mine !
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy_functions.h"
#include "libmy_macros.h"
#include "libmy_structs.h"
#include "libmy_other_prototypes.h"

void replace_by_oct(char **str, int i)
{
    char *copy = my_strdup(*str);
    char *converted = NULL;
    form_t args = {.padding = 3, .zero_paded = 1, .converter = 80};

    free(*str);
    *str = malloc(my_strlen(copy) + 5);
    my_strncpy(*str, copy, i);
    my_strcat(*str, "\\\0");
    converted = base_convert(&args, copy[i], 0);
    my_strcat(*str, converted);
    free(converted);
    my_strcat(*str, &copy[i + 1]);
    free(copy);
}

char *my_octal_str(char *str)
{
    int i = 0;
    char *copy = NULL;

    if (str == NULL)
        return (my_strdup("(null)"));
    copy = my_strdup(str);
    while (copy[i] != '\0') {
        if (!(copy[i] >= 20 && copy[i] <= 126)) {
            replace_by_oct(&copy, i);
            i = 0;
        } else
            i++;
    }
    return (copy);
}