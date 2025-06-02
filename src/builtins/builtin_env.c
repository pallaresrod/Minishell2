/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** builtin_env
*/

#include "../../include/my.h"
#include "../../include/builtins.h"
#include "../../include/env.h"

void builtin_env(env_t *env_l)
{
    for (node_t *node = env_l->head; node; node = node->next) {
        my_putstr(node->data);
        my_putstr("\n");
    }
}

void builtin_setenv(char **cmd, env_t *env_l)
{
    char *value;

    if (!cmd[1]) {
        builtin_env(env_l);
        return;
    }
    value = cmd[2] ? cmd[2] : "";
    set_env_value(env_l, cmd[1], value);
}

void builtin_unsetenv(char **cmd, env_t *env_l)
{
    if (!cmd[1]) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return;
    }
    unset_env_value(env_l, cmd[1]);
}
