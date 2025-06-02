/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** path
*/

#include "../include/my.h"
#include "../include/path.h"
#include "../include/env.h"

int is_absolute_path(char *cmd)
{
    return (cmd != NULL && cmd[0] == '/');
}

int is_valid_executable(char *path)
{
    if (access(path, F_OK | X_OK) == 0) {
        return 1;
    }
    return 0;
}

static char *build_full_path(char *dir, char *cmd)
{
    char *full_path = malloc(my_strlen(dir) + my_strlen(cmd) + 2);

    if (!full_path)
        return NULL;
    my_strcpy(full_path, dir);
    my_strcat(full_path, "/");
    my_strcat(full_path, cmd);
    return full_path;
}

static char *search_path_dirs(char *cmd, char *path_copy)
{
    char *dir = my_strtok(path_copy, ":");
    char *full_path = NULL;

    while (dir) {
        full_path = build_full_path(dir, cmd);
        if (!full_path)
            break;
        if (access(full_path, X_OK) == 0)
            return full_path;
        free(full_path);
        dir = my_strtok(NULL, ":");
    }
    return NULL;
}

char *find_in_path(char *cmd, env_t *env_l)
{
    char *path;
    char *path_copy;
    char *result;

    if (!cmd || !*cmd)
        return NULL;
    if (my_strchr(cmd, '/'))
        return (access(cmd, X_OK) == 0) ? my_strdup(cmd) : NULL;
    path = get_env_value(env_l, "PATH");
    if (!path) {
        write(2, "minishell: PATH not set\n", 24);
        return NULL;
    }
    path_copy = my_strdup(path);
    if (!path_copy)
        return NULL;
    result = search_path_dirs(cmd, path_copy);
    free(path_copy);
    return result;
}
