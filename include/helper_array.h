/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** helper_array
*/

#ifndef HELPER_ARRAY_H
    #define HELPER_ARRAY_H
    #include "my.h"

void skip_separators(char *map_one_dim, int *pos, char sep1, char sep2);
int is_end_of_column(char c, char sep1, char sep2);
int is_separator(char c, char sep1, char sep2);
int is_end_of_row(char current, char next, char sep1, char sep2);

#endif
