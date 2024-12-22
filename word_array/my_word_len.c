/*
** EPITECH PROJECT, 2024
** my_getloadavg
** File description:
** get the load average
*/
#include <stdlib.h>
#include <stdio.h>

int my_word_len(char *str, char separator, int i)
{
    int count = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            return count;
        }
        count++;
    }
    return count;
}
