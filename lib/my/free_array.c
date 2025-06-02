/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** free_array
*/

#include "my.h"

char **free_array(char **array)
{
    if (array) {
        for (int i = 0; array[i]; i++) {
            free(array[i]);
        }
        free(array);
    }
    return NULL;
}
