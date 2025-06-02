/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** my_isspace
*/

#include "my.h"

int my_isspace(int c)
{
    return (c == ' ' ||
            c == '\t' ||
            c == '\n' ||
            c == '\v' ||
            c == '\f' ||
            c == '\r');
}
