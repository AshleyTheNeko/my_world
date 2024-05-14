/*
** EPITECH PROJECT, 2020
** len
** File description:
** size matters
*/

int my_baselen(int nbr, int base_to)
{
    int size = 1;

    if (nbr < 0)
        nbr *= -1;
    while (nbr /= base_to)
        size++;
    return (size);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
