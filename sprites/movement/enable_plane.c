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

void enable_plane(plane_list_t **begin, sfClock *clock)
{
    plane_list_t *temp = malloc(sizeof(plane_list_t));
    sfTime elapsed_time = sfClock_getElapsedTime(clock);

    temp = (*begin);
    while (temp != NULL) {
        elapsed_time = sfClock_getElapsedTime(clock);
        //printf("%d > %d ?\n\n", (int)(elapsed_time.microseconds/1000000), temp->delay);
        if ((int)(elapsed_time.microseconds / 1000000) > temp->delay && temp->enable == 0) {
            temp->enable = 1;
        }
        temp = temp->next;
    }
}
