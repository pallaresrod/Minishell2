/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** builtins
*/

#include "../../include/my.h"
#include "../../include/builtins.h"
#include "../../include/env.h"

int is_builtin(char *cmd)
{
    return (my_strcmp(cmd, "cd") == 0 ||
            my_strcmp(cmd, "setenv") == 0 ||
            my_strcmp(cmd, "unsetenv") == 0 ||
            my_strcmp(cmd, "env") == 0 ||
            my_strcmp(cmd, "exit") == 0);
}

void execute_builtin(char **cmd, env_t *env_l)
{
    if (my_strcmp(cmd[0], "cd") == 0)
        builtin_cd(cmd, env_l);
    if (my_strcmp(cmd[0], "env") == 0)
        builtin_env(env_l);
    if (my_strcmp(cmd[0], "setenv") == 0)
        builtin_setenv(cmd, env_l);
    if (my_strcmp(cmd[0], "unsetenv") == 0)
        builtin_unsetenv(cmd, env_l);
    if (my_strcmp(cmd[0], "exit") == 0)
        builtin_exit(cmd, env_l);
}
