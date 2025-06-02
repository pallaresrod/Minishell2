/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** cmd
*/

#ifndef CMD_H
    #define CMD_H
    #include "my.h"

void process_cmd(char **cmd, env_t *env_l);
char **get_cmd(env_t *env_l);

#endif
