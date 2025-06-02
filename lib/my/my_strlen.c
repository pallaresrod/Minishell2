/*
** EPITECH PROJECT, 2025
** minishell1 [WSL: Ubuntu-24.04]
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
