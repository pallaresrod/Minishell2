/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** addons
*/

#ifndef ADDONS_H
    #define ADDONS_H
    #include "my.h"

char **split_by_semicolon(const char *line);
void handle_semicolon_commands(const char *line, env_t *env);
bool handle_redirections(char **cmd, env_t *env_l);

#endif
