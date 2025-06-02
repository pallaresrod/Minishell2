/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int ret = 0;
    int count = 0;
    int sign = 1;

    while (str[count] == '+' || str[count] == '-') {
        if (str[count] == '-')
            sign = sign * (-1);
        count++;
    }
    while (str[count] != '\0') {
        if (str[count] > 47 && str[count] < 58) {
            ret = ret * 10;
            ret = ret + str[count] - 48;
            count++;
        } else {
            return (ret * sign);
        }
    }
    return (ret * sign);
}
