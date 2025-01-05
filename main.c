/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "radar.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 2) {
        return 84;
    }
    return my_radar(argv); // 84 if error;
}
