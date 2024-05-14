/*
** EPITECH PROJECT, 2020
** puts
** File description:
** they put
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy_functions.h"

void my_putchar(char character)
{
    write(1, &character, 1);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_dputstr(char const *str, int file_desc)
{
    write(file_desc, str, my_strlen(str));
}

void my_putnbr(long long nbr)
{
    int size = my_baselen(nbr, 10);
    char neg = nbr < 0;
    char *str = malloc(size + 1 + neg);

    if (neg) {
        str[0] = '-';
        nbr *= -1;
    }
    str[size] = '\0';
    size--;
    while (size >= 0) {
        str[size + neg] = (nbr % 10) + 48;
        nbr /= 10;
        size--;
    }
    my_putstr(str);
    free(str);
}