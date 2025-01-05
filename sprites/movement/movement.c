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

void movement(plane_list_t **begin, sfClock *clock)
{
    plane_list_t *temp = malloc(sizeof(plane_list_t));
    sfTime elapsed_time = sfClock_getElapsedTime(clock);
    //printf("Clock = %d\n", (int)elapsed_time.microseconds);

    temp = (*begin);
    while (temp != NULL) {
        if (elapsed_time.microseconds > 10000 && temp->enable == 1) {
            temp->pos.x += ((temp->normalized_vector.x * temp->speed) / 100);
            temp->pos.y += (temp->normalized_vector.y * temp->speed) / 100;
            temp->top_left_pos.x += ((temp->normalized_vector.x * temp->speed) / 100);
            temp->top_left_pos.y += (temp->normalized_vector.y * temp->speed) / 100;
            sfSprite_setPosition(temp->sprite, temp->top_left_pos);
            sfRectangleShape_setPosition(temp->hitbox, temp->top_left_pos);
            sfClock_restart(clock);
        }
        if (temp->pos.x < temp->arrival.x + 2 && temp->pos.y < temp->arrival.y + 2 && temp->pos.x > temp->arrival.x - 2 && temp->pos.y > temp->arrival.y - 2) {
            temp->enable = 2;
        }
        //printf("node !\n");
        temp = temp->next;
    }
    //free(temp);
}
