/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** env_manager
*/

#include "../include/my.h"
#include "../include/env.h"

static node_t *new_node(char *env)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;
    node->data = my_strdup(env);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

static void append_node(env_t *env_l, char *env_data)
{
    node_t *node = new_node(env_data);

    if (!node)
        return;
    node->prev = env_l->tail;
    if (env_l->tail)
        env_l->tail->next = node;
    env_l->tail = node;
    if (!env_l->head)
        env_l->head = node;
}

env_t *create_env(char **env)
{
    env_t *env_l = malloc(sizeof(env_t));

    if (!env_l)
        return NULL;
    env_l->head = NULL;
    env_l->tail = NULL;
    if (!env || !*env)
        return env_l;
    append_node(env_l, env[0]);
    for (int i = 1; env[i]; i++) {
        append_node(env_l, env[i]);
    }
    return env_l;
}

void free_list(env_t *env_l)
{
    node_t *current;
    node_t *next;

    if (!env_l)
        return;
    current = env_l->head;
    while (current) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(env_l);
}
