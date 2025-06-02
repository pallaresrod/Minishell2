/*
** EPITECH PROJECT, 2025
** minishell1 [WSL: Ubuntu-24.04]
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return dest;
}
