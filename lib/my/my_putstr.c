/*
** EPITECH PROJECT, 2024
** Task02, my_putstr
** File description:
** This program will display,
** one by one, the character of string
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
