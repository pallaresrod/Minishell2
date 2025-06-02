/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** aux_env
*/

#include "../include/my.h"
#include "../include/env.h"

char *get_env_value(env_t *env_l, const char *name)
{
    size_t name_len = my_strlen(name);

    for (node_t *node = env_l->head; node; node = node->next) {
        if (my_strncmp(node->data, name, name_len) == 0 &&
            node->data[name_len] == '=')
            return node->data + name_len + 1;
    }
    return NULL;
}

static bool replace_env_value(env_t *env_l,
    const char *name, const char *env_str)
{
    size_t name_len = my_strlen(name);

    for (node_t *node = env_l->head; node; node = node->next) {
        if (my_strncmp(node->data, name, name_len) == 0 &&
            node->data[name_len] == '=') {
            free(node->data);
            node->data = my_strdup(env_str);
            return true;
        }
    }
    return false;
}

static void append_env_value(env_t *env_l, const char *env_str)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node)
        return;
    new_node->data = my_strdup(env_str);
    new_node->next = NULL;
    new_node->prev = env_l->tail;
    if (env_l->tail) {
        env_l->tail->next = new_node;
    } else {
        env_l->head = new_node;
    }
    env_l->tail = new_node;
}

void set_env_value(env_t *env_l, const char *name, const char *value)
{
    char *env_str = malloc(my_strlen(name) + my_strlen(value) + 2);

    if (!env_str)
        return;
    my_strcpy(env_str, name);
    my_strcat(env_str, "=");
    my_strcat(env_str, value);
    if (!replace_env_value(env_l, name, env_str))
        append_env_value(env_l, env_str);
    free(env_str);
}

static node_t *find_env_node(env_t *env_l, const char *name)
{
    size_t name_len = my_strlen(name);

    for (node_t *node = env_l->head; node; node = node->next) {
        if (my_strncmp(node->data, name, name_len) == 0 &&
            node->data[name_len] == '=')
            return node;
    }
    return NULL;
}

static void remove_env_node(env_t *env_l, node_t *node)
{
    if (!node)
        return;
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        env_l->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        env_l->tail = node->prev;
    }
    free(node->data);
    free(node);
}

void unset_env_value(env_t *env_l, const char *name)
{
    node_t *node = find_env_node(env_l, name);

    remove_env_node(env_l, node);
}

char **env_to_array(env_t *env_l)
{
    int count = 0;
    int i = 0;
    char **env;

    for (node_t *node = env_l->head; node; node = node->next)
        count++;
    env = malloc(sizeof(char *) * (count + 1));
    if (!env)
        return NULL;
    for (node_t *node = env_l->head; node; node = node->next) {
        env[i] = my_strdup(node->data);
        i++;
    }
    env[count] = NULL;
    return env;
}
