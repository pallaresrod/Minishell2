/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** env
*/

#ifndef ENV_H
    #define ENV_H
    #include "my.h"

env_t *create_env(char **env);
void free_list(env_t *env_l);
char *get_env_value(env_t *env_l, const char *name);
void set_env_value(env_t *env_l, const char *name, const char *value);
void unset_env_value(env_t *env_l, const char *name);
char **env_to_array(env_t *env_l);

#endif
