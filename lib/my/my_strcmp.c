/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL) {
        if (s1 == s2)
            return 0;
        return s1 ? 1 : -1;
    }
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
