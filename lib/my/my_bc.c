/*
** EPITECH PROJECT, 2020
** Base convert
** File description:
** converts bases
*/

#include <stdlib.h>
#include "libmy_structs.h"
#include "libmy_macros.h"
#include "libmy_functions.h"

char *alt(form_t *args, long long nb)
{
    if (args->alt) {
        if (args->converter % 10 == 3 && nb != 0)
            return ("0X\0");
        if (args->converter % 10 == 2 && args->converter / 10 > 10 && nb != 0)
            return ("0x\0");
        if (args->converter / 10 == 8 && nb != 0)
            return ("0\0");
        return ("\0");
    }
    return ("\0");
}

char *base_convert(form_t *args, long long number, char mode)
{
    char *base = MODE(mode);
    char *prefix = alt(args, CAST(number));
    char base_nb = args->converter / 10;
    int size = DIFF(my_baselen(number, base_nb), PADD(number, prefix));
    char *result = malloc(size + 3 + SLOT(number) + my_strlen(prefix));
    int i = size - 1 + SLOT(number) + my_strlen(prefix);

    my_memset(result, size + 2 + SLOT(number) + my_strlen(prefix));
    if (number < 0) {
        number *= -1;
        result[0] = '-';
    } else if ((args->space || args->sign) && ISDEC)
        result[0] = (args->sign) ? '+' : ' ';
    my_strcat(result, prefix);
    while (i >= my_strlen(prefix) + SLOTP(number)) {
        result[i--] = base[(number % base_nb)];
        number = number / base_nb;
    }
    free(base);
    return (result);
}