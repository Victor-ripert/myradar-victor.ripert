/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "radar.h"
#include <stdio.h>

int pause(sfEvent event, int clock_pause)
{
    if (event.key.code == sfKeySpace) {
        if (clock_pause == 1) {
            return 0;
        }
        return 1;
    }
    return clock_pause;
}
