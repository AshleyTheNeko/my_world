/*
** EPITECH PROJECT, 2020
** power
** File description:
** does power
*/

int my_power(int nb, int p)
{
    long result = 0;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    result = nb * my_power(nb, p - 1);
    if (result > 2147483647)
        return (0);
    if (result < -2147483647)
        return (0);
    if (!(nb < 0) && result < 0)
        return (0);
    return (result);
}
