/*
** EPITECH PROJECT, 2020
** strnmodify
** File description:
** nmodifies and ncreates
*/

#include <stdlib.h>
#include "libmy_functions.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int index_dest = 0;
    int index_swap = 0;

    while (dest[index_dest] != '\0')
        index_dest++;
    while (src[index_swap] != '\0' && index_swap < nb) {
        dest[index_swap + index_dest] = src[index_swap];
        index_swap++;
    }
    dest[index_dest + index_swap] = '\0';
    return (dest);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strndup(char const *src, int n)
{
    char *newString = NULL;

    if (src == NULL)
        return (NULL);
    newString = malloc((n + 1) * sizeof(char));
    my_memset(newString, n);
    my_strncpy(newString, src, n);
    return (newString);
}

char *my_strndupcat(char const *s1, char const *s2, int n)
{
    char *output = malloc(my_strlen(s1) + my_strlen(s2) + 1);
    int i = 0;
    int j = 0;
    int io = 0;

    while (s1[i] != '\0') {
        output[io] = s1[i];
        i++;
        io++;
    }
    while (s2[j - 1] != '\0' && j < n) {
        output[io] = s2[j];
        j++;
        io++;
    }
    output[io] = '\0';
    return (output);
}
