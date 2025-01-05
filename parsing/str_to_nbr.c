/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** desc
*/
#include "radar.h"

int special_strlen(char *str)
{
    int i = 0;
    int retoure = 0;

    while (str[i] != '\0' && str[i] != '.' && str[i] != '\n'){
        i++;
        retoure++;
    }
    return (retoure);
}

int str_to_nbr(char *nb)
{
    int result = 0;
    int nb_len = special_strlen(nb);
    int i = 0;

    if (nb[0] == '-') {
        i = 1;
    }
    for (; i != nb_len; i++) {
        result = result * 10;
        result += (nb[i] - '0');
    }
    if (nb[0] == '-') {
        result *= -1;

    }
    return result;
}
