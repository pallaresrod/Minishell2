/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** redirections
*/

#include "../include/my.h"
#include "../include/env.h"
#include "../include/cmd.h"

int redirect_output(const char *file)
{
    int fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
        return -1;
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return 0;
}

static int redirect_output_append(const char *file)
{
    int fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);

    if (fd == -1)
        return -1;
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return 0;
}

int redirect_input(const char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return -1;
    dup2(fd, STDIN_FILENO);
    close(fd);
    return 0;
}

static void heredoc_loop(const char *delimiter, int write_fd)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1) {
        write(1, "> ", 2);
        nread = getline(&line, &len, stdin);
        if (nread == -1)
            break;
        line[nread - 1] = '\0';
        if (my_strcmp(line, delimiter) == 0)
            break;
        write(write_fd, line, my_strlen(line));
        write(write_fd, "\n", 1);
    }
    free(line);
}

static int redirect_heredoc(const char *delimiter)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
        return -1;
    heredoc_loop(delimiter, pipefd[1]);
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    return 0;
}

static bool match_redirection(redir_ctx_t *ctx, int i,
    const char *symbol, int redir_type)
{
    if (my_strcmp(ctx->cmd[i], symbol) == 0 && ctx->cmd[i + 1]) {
        *(ctx->filename) = ctx->cmd[i + 1];
        ctx->cmd[i] = NULL;
        *(ctx->type) = redir_type;
        return true;
    }
    return false;
}

static int get_redirection_info(char **cmd, char **filename)
{
    int type = 0;
    redir_ctx_t ctx = {cmd, filename, &type};

    for (int i = 0; cmd[i]; i++) {
        if (match_redirection(&ctx, i, ">>", 3))
            return type;
        if (match_redirection(&ctx, i, "<<", 4))
            return type;
        if (match_redirection(&ctx, i, ">", 1))
            return type;
        if (match_redirection(&ctx, i, "<", 2))
            return type;
    }
    return 0;
}

void run_with_redirection(char **cmd, env_t *env_l, int type,
    const char *filename)
{
    if (type == 1 && redirect_output(filename) == -1)
        exit(84);
    if (type == 2 && redirect_input(filename) == -1)
        exit(84);
    if (type == 3 && redirect_output_append(filename) == -1)
        exit(84);
    if (type == 4 && redirect_heredoc(filename) == -1)
        exit(84);
    process_cmd(cmd, env_l);
    exit(0);
}

bool handle_redirections(char **cmd, env_t *env_l)
{
    int saved_stdin = dup(STDIN_FILENO);
    int saved_stdout = dup(STDOUT_FILENO);
    int type;
    char *filename = NULL;
    pid_t pid;
    int status;

    type = get_redirection_info(cmd, &filename);
    if (type == 0)
        return false;
    pid = fork();
    if (pid == 0)
        run_with_redirection(cmd, env_l, type, filename);
    waitpid(pid, &status, 0);
    dup2(saved_stdin, STDIN_FILENO);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdin);
    close(saved_stdout);
    return true;
}
