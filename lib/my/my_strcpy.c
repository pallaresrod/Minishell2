/*
** EPITECH PROJECT, 2025
** minishell1 [WSL: Ubuntu-24.04]
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
