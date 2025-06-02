/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** command_manager
*/

#include "../include/my.h"
#include "../include/builtins.h"
#include "../include/path.h"
#include "../include/env.h"
#include "../include/addons.h"

char *read_cmd(env_t *env_l)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, stdin);

    if (read == -1) {
        if (line)
            free(line);
        if (isatty(0))
            my_putstr("exit\n");
        free_list(env_l);
        exit(0);
    }
    return line;
}

static bool is_empty_input(const char *str)
{
    return (!str || str[0] == '\0' || (str[0] == '\n' && str[1] == '\0'));
}

static void remove_trailing_newline(char *str)
{
    size_t len = my_strlen(str);

    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

char **get_cmd(env_t *env_l)
{
    char *cmd_str = read_cmd(env_l);
    char **cmd = NULL;

    if (is_empty_input(cmd_str)) {
        free(cmd_str);
        return NULL;
    }
    remove_trailing_newline(cmd_str);
    cmd = get_array(cmd_str, ' ', '\t');
    free(cmd_str);
    return cmd;
}

static void run_child_process(char **cmd, char **env, env_t *env_l)
{
    execve(cmd[0], cmd, env);
    perror(cmd[0]);
    free_array(env);
    free_array(cmd);
    free_list(env_l);
    exit(EXIT_FAILURE);
}

void execute_cmd(char **cmd, env_t *env_l)
{
    pid_t pid = fork();
    int status;
    char **env = env_to_array(env_l);

    if (pid == -1) {
        perror("fork");
        free_array(env);
        return;
    }
    if (pid == 0)
        run_child_process(cmd, env, env_l);
    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status))
        manage_status(status);
    free_array(env);
}

static bool try_execute_absolute(char **cmd, env_t *env_l)
{
    if (access(cmd[0], X_OK) == 0) {
        execute_cmd(cmd, env_l);
        return true;
    }
    return false;
}

static bool try_execute_from_path(char **cmd, env_t *env_l)
{
    char *full_path = find_in_path(cmd[0], env_l);

    if (!full_path)
        return false;
    cmd[0] = full_path;
    execute_cmd(cmd, env_l);
    free(full_path);
    return true;
}

void process_cmd(char **cmd, env_t *env_l)
{
    if (!cmd || !cmd[0])
        return;
    if (handle_redirections(cmd, env_l))
        return;
    if (is_builtin(cmd[0])) {
        execute_builtin(cmd, env_l);
        return;
    }
    if (my_strchr(cmd[0], '/')) {
        if (try_execute_absolute(cmd, env_l))
            return;
    } else {
        if (try_execute_from_path(cmd, env_l))
            return;
    }
    write(2, cmd[0], my_strlen(cmd[0]));
    write(2, ": command not found\n", 20);
}
