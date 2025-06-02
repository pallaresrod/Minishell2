/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** semicolon
*/

#include "../include/my.h"
#include "../include/env.h"
#include "../include/cmd.h"

char *trim_whitespace(char *str)
{
    char *end;

    while (my_isspace((unsigned char)*str))
        str++;
    if (*str == 0)
        return str;
    end = str + strlen(str) - 1;
    while (end > str && my_isspace((unsigned char)*end))
        end--;
    *(end + 1) = '\0';
    return str;
}

char **split_by_semicolon(const char *line)
{
    char **commands = NULL;
    int count = 0;
    char *temp = my_strdup(line);
    char *token = my_strtok(temp, ";");

    while (token != NULL) {
        commands = my_realloc(commands, sizeof(char *) * (count + 2));
        commands[count] = my_strdup(token);
        count++;
        token = my_strtok(NULL, ";");
    }
    commands[count] = NULL;
    free(temp);
    return commands;
}

static void parse_and_execute_command(const char *raw_cmd, env_t *env)
{
    char *cmd_line = my_strdup(trim_whitespace((char *)raw_cmd));
    char *token;
    char *cmd_parts[512];
    int j = 0;

    if (!cmd_line)
        return;
    token = my_strtok(cmd_line, " \t\n");
    while (token != NULL) {
        cmd_parts[j] = token;
        j++;
        token = my_strtok(NULL, " \t\n");
    }
    cmd_parts[j] = NULL;
    if (cmd_parts[0] != NULL)
        process_cmd(cmd_parts, env);
    free(cmd_line);
}

void handle_semicolon_commands(const char *line, env_t *env)
{
    char **commands = split_by_semicolon(line);

    for (int i = 0; commands[i] != NULL; i++)
        parse_and_execute_command(commands[i], env);
    free_array(commands);
}
