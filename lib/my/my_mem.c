/*
** EPITECH PROJECT, 2021
** memset
** File description:
** my_memset
*/

#include <stddef.h>

void my_memset(void *pointer, size_t length)
{
    unsigned char *ptr = pointer;

    while (length-- > 0)
        *(ptr++) = 0;
}

void my_memcpy(void *dest, void const *src, size_t length)
{
    unsigned char *dest_c = dest;
    unsigned char const *src_c = src;

    while (length-- > 0)
        *(dest_c++) = *(src_c++);
}