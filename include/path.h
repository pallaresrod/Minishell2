/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** path
*/

#ifndef PATH_H
    #define PATH_H
    #include "my.h"

char *find_in_path(char *cmd, env_t *env_l);
int is_absolute_path(char *cmd);
int is_valid_executable(char *path);

#endif
