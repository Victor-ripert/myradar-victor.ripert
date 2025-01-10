/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include "radar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void push_list_quadtree(quadtree_t **begin, plane_list_t *plane)
{
    quadtree_t *tmp = malloc(sizeof(quadtree_t));

    tmp->previous = NULL;
    tmp->next = *begin;
    tmp->plane = plane;
    if ((*begin)->plane == NULL) {
        (*begin)->plane = plane;
        (*begin)->next = NULL;
    } else {
        (*begin)->previous = tmp;
        (*begin) = tmp;
    }
}
