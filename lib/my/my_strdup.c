/*
** EPITECH PROJECT, 2025
** minishell1 [WSL: Ubuntu-24.04]
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src) + 1;
    char *nsrc;
    int i;

    if (len > 0){
        nsrc = malloc(len);
    } else {
        return NULL;
    }
    for (i = 0; src[i] != '\0'; i++){
        nsrc[i] = src[i];
    }
    nsrc[i] = '\0';
    return nsrc;
}
