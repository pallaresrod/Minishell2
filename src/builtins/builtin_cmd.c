/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** builtin_cmd
*/

#include "../../include/my.h"
#include "../../include/builtins.h"
#include "../../include/env.h"

static char *resolve_cd_target(char **cmd, env_t *env_l)
{
    char *home;
    char *oldpwd;

    if (!cmd[1]) {
        home = get_env_value(env_l, "HOME");
        if (!home)
            write(2, "minishell: cd: HOME not set\n", 28);
        return home;
    }
    if (my_strcmp(cmd[1], "-") == 0) {
        oldpwd = get_env_value(env_l, "OLDPWD");
        if (!oldpwd)
            write(2, "minishell: cd: OLDPWD not set\n", 30);
        else {
            my_putstr(oldpwd);
            my_putstr("\n");
        }
        return oldpwd;
    }
    return cmd[1];
}

static bool update_pwd(env_t *env_l, const char *oldpwd)
{
    char cwd[PATH_MAX];

    if (!getcwd(cwd, sizeof(cwd))) {
        perror("minishell: getcwd");
        return false;
    }
    if (oldpwd)
        set_env_value(env_l, "OLDPWD", oldpwd);
    set_env_value(env_l, "PWD", cwd);
    return true;
}

void builtin_cd(char **cmd, env_t *env_l)
{
    char *target = resolve_cd_target(cmd, env_l);
    char *oldpwd = get_env_value(env_l, "PWD");

    if (!target)
        return;
    if (chdir(target) != 0) {
        perror("minishell: cd");
        return;
    }
    update_pwd(env_l, oldpwd);
}

void builtin_exit(char **cmd, env_t *env_l)
{
    int status = cmd[1] ? my_getnbr(cmd[1]) : 0;

    free_list(env_l);
    exit(status);
}
