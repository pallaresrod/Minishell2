/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** This file contains the declarations
** of all function in the library
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/sysmacros.h>
    #include <pwd.h>
    #include <grp.h>
    #include <dirent.h>
    #include <time.h>
    #include <errno.h>
    #include <curses.h>
    #include <math.h>
    #include <utmp.h>
    #include <ctype.h>

void my_putchar(char c);
int my_putstr(char const *str);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *init_malloc(int nb);
char *my_strtok(char *str, const char *delim);
char **free_array(char **array);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strchr(const char *s, int c);
int my_isspace(int c);
void *my_realloc(void *ptr, size_t new_size);

#endif
