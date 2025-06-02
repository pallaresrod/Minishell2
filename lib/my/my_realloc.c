/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** my_realloc
*/

#include "my.h"

void *my_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    char *d = dest;
    const char *s = src;

    if (dest == NULL || src == NULL) {
        return dest;
    }
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}

void *my_realloc(void *ptr, size_t new_size)
{
    void *new_ptr;

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL) {
        return malloc(new_size);
    }
    new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }
    my_memcpy(new_ptr, ptr, new_size);
    free(ptr);
    return new_ptr;
}
