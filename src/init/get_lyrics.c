/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myworld-owen.welte
** File description:
** get_lyrics.c
*/

#include "my_world.h"
#include "my_world_macros.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

char *get_full_path(char const *filepath, char const *ext)
{
    char *fp_total = malloc(sizeof(char) * (LEN(filepath) + LEN(ext) + 1));

    if (!fp_total)
        return NULL;
    for (int i = 0; filepath[i]; i++)
        fp_total[i] = filepath[i];
    fp_total[my_strlen(filepath)] = '\0';
    fp_total = my_strcat(fp_total, ext);
    return fp_total;
}

char *get_lang(text_t *ifo, char *elem)
{
    char *filepath = get_full_path(ifo->elem_path, ifo->langs[ifo->curr_lang]);
    FILE *stream = fopen(filepath, "r");
    char *line = NULL;
    size_t line_buf_size = 0;

    if (!stream) {
        my_dputstr(FILE_NOT_FOUND, 2);
        return ("N/A");
    }
    while (getline(&line, &line_buf_size, stream) != -1) {
        if (!line || line[0] == '#')
            line = line;
        if (start_with(elem, line)) {
            free(filepath);
            fclose(stream);
            return (&line[my_strlen(elem) + 1]);
        }
    }
    fclose(stream);
    free(filepath);
    return ("N/A");
}

static int get_ok_phrase(char *line, tuto_t *tuto, int val, FILE *stream)
{
    if (line && line[0] != '#' && line[0] != '\n') {
        if (val == tuto->curr_text && start_with("end", line)) {
            tuto->end = true;
            fclose(stream);
            return (SUCCESS_EXIT);
        }
        if (val == tuto->curr_text) {
            fclose(stream);
            init_tuto_txt(tuto, line);
            return (SUCCESS_EXIT);
        }
    }
    return (ERROR_EXIT);
}

void get_tuto_text(text_t *inf, tuto_t *tuto)
{
    char *filepath = get_full_path(inf->tuto_path, inf->langs[inf->curr_lang]);
    FILE *stream = fopen(filepath, "r");
    char *line = NULL;
    size_t line_buf_size = 0;
    ssize_t read;
    int val = 0;

    if (stream == NULL) {
        my_dputstr(FILE_NOT_FOUND, 2);
        free(filepath);
        init_tuto_txt(tuto, "N/A");
        return;
    }
    while ((read = getline(&line, &line_buf_size, stream)) != -1) {
        if (get_ok_phrase(line, tuto, val, stream) == SUCCESS_EXIT) {
            free(filepath);
            return;
        }
        if (line && line[0] != '#' && line[0] != '\n')
            val++;
    }
}