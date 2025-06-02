/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** builtins
*/

#ifndef BUILTINS_H
    #define BUILTINS_H
    #include "my.h"

int is_builtin(char *cmd);
void execute_builtin(char **cmd, env_t *env_l);
void builtin_cd(char **cmd, env_t *env_l);
void builtin_env(env_t *env_l);
void builtin_setenv(char **cmd, env_t *env_l);
void builtin_unsetenv(char **cmd, env_t *env_l);
void builtin_exit(char **cmd, env_t *env_l);

#endif
