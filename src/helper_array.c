/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** helper_array
*/

#include "../include/my.h"

int is_separator(char c, char sep1, char sep2)
{
    return (c == sep1 || c == sep2 || c == '\0');
}

void skip_separators(char *map_one_dim, int *pos, char sep1, char sep2)
{
    while (is_separator(map_one_dim[*pos], sep1, sep2) &&
    map_one_dim[*pos] != '\0') {
        (*pos)++;
    }
}

int is_end_of_column(char c, char sep1, char sep2)
{
    return (c == sep1 || c == sep2 || c == '\0');
}

int is_end_of_row(char current, char next, char sep1, char sep2)
{
    return (!is_separator(current, sep1, sep2) &&
            is_separator(next, sep1, sep2));
}
