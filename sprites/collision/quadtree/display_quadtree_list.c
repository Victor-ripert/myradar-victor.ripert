/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "radar.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

void display_quadtree_list(quadtree_t **list)
{
    quadtree_t *tmp;

    tmp = (*list);
    while (tmp != NULL)  {
        // printf("Data address = %p -> (%f, %f)\n", &tmp->plane, tmp->plane->pos.x, tmp->plane->pos.y);
        tmp = tmp->next;
    }
}