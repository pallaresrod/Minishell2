/*
** EPITECH PROJECT, 2025
** minishell1 [WSL: Ubuntu-24.04]
** File description:
** init_malloc
*/

#include "my.h"

char *init_malloc(int nb)
{
    char *str;

    str = malloc(sizeof(char) * nb + 1);
    for (int i = 0; i < nb + 1; i++){
        str[i] = '\0';
    }
    return str;
}
