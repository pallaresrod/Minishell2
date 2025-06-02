/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** my_strchr
*/

#include "my.h"

char *my_strchr(const char *s, int c)
{
    if (s == NULL)
        return NULL;
    while (*s != '\0') {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if ((char)c == '\0')
        return (char *)s;
    return NULL;
}
