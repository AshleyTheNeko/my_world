/*
** EPITECH PROJECT, 2020
** strmodify
** File description:
** modifies and create
*/

#include <stdlib.h>
#include "libmy_functions.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *newString = NULL;
    int length = 0;

    if (src == NULL)
        return (NULL);
    length = my_strlen(src);
    newString = malloc(length + 1);
    my_memset(newString, length);
    my_strcpy(newString, src);
    return (newString);
}

char *my_strcat(char *dest, char const *src)
{
    int index_dest = 0;
    int index_swap = 0;

    while (dest[index_dest] != '\0')
        index_dest++;
    while (src[index_swap] != '\0') {
        dest[index_swap + index_dest] = src[index_swap];
        index_swap++;
    }
    dest[index_swap + index_dest] = '\0';
    return (dest);
}

char *my_strdupcat(char const *s1, char const *s2)
{
    char *output = malloc((my_strlen(s1) + my_strlen(s2) + 2) * sizeof(char));
    int i = 0;
    int j = 0;
    int io = 0;

    while (s1[i] != '\0') {
        output[io] = s1[i];
        i++;
        io++;
    }
    while (s2[j] != '\0') {
        output[io] = s2[j];
        j++;
        io++;
    }
    output[io] = '\0';
    return (output);
}