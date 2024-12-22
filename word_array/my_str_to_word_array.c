/*
** EPITECH PROJECT, 2024
** my_getloadavg
** File description:
** get the load average
*/
#include <stdlib.h>
#include <stdio.h>
#include "radar.h"

int line_nbr(char *str, char separator)
{
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            count++;
        }
    }
    return count;
}

int find_biggest_word(char *str, char separator)
{
    int biggest_word = my_word_len(str, separator, 0);
    int temp = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            temp = my_word_len(str, separator, i + 1);
        }
        if (temp > biggest_word) {
            biggest_word = temp;
        }
    }
    return biggest_word;
}

char **create_word_array(int nb_rows, int nb_cols)
{
    char **word_array = malloc(sizeof(char *) * (nb_rows +1));

    for (int i = 0; i < nb_rows; i++) {
        word_array[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    return word_array;
}

char **my_str_to_word_array(char *str, char separator)
{
    int nb_rows = line_nbr(str, separator);
    int nb_cols = find_biggest_word(str, separator);
    char **word_array = create_word_array(nb_rows, nb_cols);
    int n = 0;

    for (int i = 0; i != nb_rows; i++) {
        for (int j = 0; str[n] != separator && str[n] != '\0'; j++) {
            word_array[i][j] = str[n];
            word_array[i][j + 1] = '\0';
            n++;
        }
        n++;
    }
    word_array[nb_rows] = NULL;
    return word_array;
}
