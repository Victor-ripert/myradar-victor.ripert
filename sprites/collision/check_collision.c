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

void check_collision(plane_list_t **begin, plane_list_t *plane)
{
    plane_list_t *temp = malloc(sizeof(plane_list_t));

    temp = (*begin);
    while (temp != NULL) {
        if (temp->pos.x == temp->)
        temp = temp->next;
    }
}
