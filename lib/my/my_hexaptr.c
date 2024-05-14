/*
** EPITECH PROJECT, 2020
** My hexaptr
** File description:
** Pointers, everywhere
*/

#include <stdlib.h>
#include "libmy_functions.h"
#include "libmy_macros.h"
#include "libmy_structs.h"
#include "libmy_other_prototypes.h"

static char *get_sign_space(form_t *args)
{
    if (args->sign)
        return ("+0x");
    if (args->space)
        return (" 0x");
    return ("0x");
}

char *my_hexa_ptr(void *ptr, form_t *args)
{
    long pointer = (long)ptr;
    int size = DIFF(my_baselen(pointer, 16), ZPAD(args));
    char *base = "0123456789abcdef";
    char *output = malloc(size + 3 * sizeof(char));
    char *nulloutput = my_strdup("(nil)");
    int i = size + 1;

    if (ptr == NULL) {
        free(output);
        args->zero_paded = 0;
        return (append_padding(args, &nulloutput));
    }
    free(nulloutput);
    my_strcpy(output, get_sign_space(args));
    output[size + 2] = '\0';
    while (i >= (2 + SLOT((long)ptr))) {
        output[i] = base[(pointer % 16)];
        pointer = pointer / 16;
        --i;
    }
    return (output);
}