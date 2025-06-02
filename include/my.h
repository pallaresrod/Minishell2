/*
** EPITECH PROJECT, 2025
** bs_minishell2 [WSL: Ubuntu-24.04]
** File description:
** my
*/

#ifndef MY_H
    #define MY_H
    #include <unistd.h>
    #include <sys/wait.h>
    #include <linux/limits.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <fcntl.h>

typedef struct node_s {
    char *data;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct env_s {
    struct node_s *head;
    struct node_s *tail;
} env_t;

typedef struct redir_ctx_s {
    char **cmd;
    char **filename;
    int *type;
} redir_ctx_t;

//lib
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strncmp(const char *s1, const char *s2, size_t n);
char **free_array(char **array);
char *my_strtok(char *str, const char *delim);
char *init_malloc(int nb);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strchr(const char *s, int c);
int my_isspace(int c);
void *my_realloc(void *ptr, size_t new_size);

// helpers
char **get_array(char *map_one_dim, char sep1, char sep2);
void manage_status(int status);
#endif
