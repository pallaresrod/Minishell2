/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** my_strtok
*/

#include "my.h"

static bool is_rejected(char c, const char *reject)
{
    for (; *reject != '\0'; reject++) {
        if (c == *reject)
            return true;
    }
    return false;
}

size_t my_strcspn(const char *str, const char *reject)
{
    size_t count = 0;

    if (str == NULL || reject == NULL)
        return 0;
    for (; *str != '\0'; str++) {
        if (is_rejected(*str, reject))
            return count;
        count++;
    }
    return count;
}

char *my_strtok(char *str, const char *delim)
{
    static char *save_ptr = NULL;
    char *end;
    char *ret;

    if (str)
        save_ptr = str;
    if (!save_ptr || !*save_ptr)
        return NULL;
    ret = save_ptr;
    end = ret + my_strcspn(ret, delim);
    if (*end) {
        *end = '\0';
        save_ptr = end + 1;
    } else {
        save_ptr = end;
    }
    return ret;
}
