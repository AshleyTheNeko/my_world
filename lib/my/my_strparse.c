/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_strparse
*/

#include <stdlib.h>
#include "libmy_functions.h"

static int delimiter_matchs(char const *string, char const *delimiter)
{
    int i = 0;
    int j = 0;
    int delim_matchs = 0;

    while (string[i]) {
        while (!my_strncmp(&string[j], delimiter, my_strlen(delimiter)))
            j += my_strlen(delimiter);
        if (i < j)
            i = j;
        if (!my_strncmp(&string[i], delimiter, my_strlen(delimiter))) {
            delim_matchs++;
            j = i;
        } else
            i++;
    }
    if (string[j])
        delim_matchs++;
    return (delim_matchs);
}

static void append_chunks_to_array(char **parsed_array, char const *string,
char const *delimiter)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (string[i]) {
        while (!my_strncmp(&string[j], delimiter, my_strlen(delimiter)))
            j += my_strlen(delimiter);
        if (i < j)
            i = j;
        if (!my_strncmp(&string[i], delimiter, my_strlen(delimiter))) {
            parsed_array[k] = my_strndup(&string[j], i - j);
            j = i;
            k++;
        } else
            i++;
    }
    if (string[j])
        parsed_array[k] = my_strndup(&string[j], i - j);
    parsed_array[k + (string[j] != 0)] = NULL;
}

char **parse_string(char const *string, char const *delimiter)
{
    int delim_matchs = 0;
    char **parsed_array = NULL;

    if (!string)
        return (NULL);
    if (!delimiter)
        return (NULL);
    delim_matchs = delimiter_matchs(string, delimiter);
    if (!delim_matchs)
        return (NULL);
    parsed_array = malloc((delim_matchs + 1) * sizeof(char *));
    append_chunks_to_array(parsed_array, string, delimiter);
    return (parsed_array);
}

void free_parse_str(char **parsed_str)
{
    int i = 0;

    if (!parsed_str)
        return;
    while (parsed_str[i])
        free(parsed_str[i++]);
    free(parsed_str);
}