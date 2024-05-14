/*
** EPITECH PROJECT, 2021
** lm
** File description:
** libmy_structs
*/

#ifndef LIBMY_STRUCTS_H_
#define LIBMY_STRUCTS_H_

typedef struct formatting {
    char alt;
    char zero_paded;
    char left_adj;
    char space;
    char sign;
    char lm;
    int converter;
    int padding;
    int precision;
} form_t;

#endif /* !LIBMY_STRUCTS_H_ */