/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** minishell
*/

#include "../include/my.h"
#include "../include/cmd.h"
#include "../include/env.h"
#include "../include/addons.h"

void minishell(int argc, char **argv, char **env)
{
    env_t *env_l = create_env(env);
    char cwd[PATH_MAX];
    char **cmd;
    char *line = NULL;
    size_t len;

    while (1) {
        len = 0;
        if (isatty(0) && isatty(1))
            my_putstr("$> ");
        if (getline(&line, &len, stdin) == -1) {
            exit(84);
        }
        if (line[0] != '\n')
            handle_semicolon_commands(line, env_l);
        free(line);
    }
}

int main(int argc, char **argv, char **env)
{
    if (argc > 1 && my_strcmp(argv[1], "-h") == 0) {
        my_putstr("Minishell2 - UNIX command interpreter based on TCSH.\n");
        my_putstr("It includes semicolons and redirections\n\n");
        my_putstr("Options:\n");
        my_putstr("  -h     Displays this help message and exits\n");
        return 0;
    }
    minishell(argc, argv, env);
    return 0;
}
