/*
** EPITECH PROJECT, 2020
** atoi
** File description:
** ints and strs
*/

#include "libmy_functions.h"
#include "libmy_macros.h"
#include <stdlib.h>

int my_atoi(char const *parse, char anywhere)
{
    int i = 0;
    char sign = 1;
    int res = 0;

    if (anywhere) {
        while ((!NBR(parse[i]) || parse[i] == '-') && parse[i] != '\0')
            i++;
    }
    if (parse[i] == '-') {
        sign = -1;
        i++;
    }
    while (NBR(parse[i]) && parse[i] != '\0') {
        res *= 10;
        res += parse[i] - 48;
        i++;
    }
    return (res * sign);
}

char *my_unatoi(int number)
{
    int length = my_baselen(number, 10);
    char neg = number < 0;
    char *res = malloc(length + 1 + neg);
    int i = length + neg - 1;

    res[i + 1] = '\0';
    if (neg) {
        number *= -1;
        res[0] = '-';
    }
    while (i >= neg) {
        res[i] = (number % 10) + 48;
        number /= 10;
        i--;
    }
    return (res);
}
