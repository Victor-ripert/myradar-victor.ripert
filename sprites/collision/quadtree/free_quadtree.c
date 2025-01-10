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

void free_quadtree(quadtree_t **list)
{
    quadtree_t *tmp;
    quadtree_t *next;

    tmp = (*list);
    while (tmp != NULL)  {
        if (tmp->next != NULL) {
            next = tmp->next;
        } else {
            next = NULL;
        }
        free(tmp);
        tmp = next;
    }
}