/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** aux_command
*/

#include "../include/my.h"
#include "../include/env.h"

void manage_status(int status)
{
    int id = WTERMSIG(status);

    if (id == 11)
        write(2, "Segmentation fault\n", 19);
    if (id == 8)
        write(2, "Floating exception\n", 19);
    if (WCOREDUMP(status))
        write(2, " (core dumped)\n", 15);
}

void process_exit(char **cmd, env_t *env_l)
{
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
    free_list(env_l);
    exit(EXIT_SUCCESS);
}

int check_cmd(char **cmd, env_t *env_l)
{
    if (my_strcmp(cmd[0], "cd") == 0) {
        my_putstr("cd\n");
        return 1;
    }
    if (my_strcmp(cmd[0], "env") == 0) {
        return 2;
    }
    if (my_strcmp(cmd[0], "setenv") == 0 ||
    my_strcmp(cmd[0], "unsetenv") == 0) {
        return 3;
    }
    if (my_strcmp(cmd[0], "exit") == 0) {
        process_exit(cmd, env_l);
        return 4;
    }
    return 0;
}
