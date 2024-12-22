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

void push_to_list(linked_list_t **begin, int id, sfCircleShape *circle)
{
    linked_list_t *temp = malloc(sizeof(linked_list_t));

    temp->circle = circle;
    temp->id = id;
    temp->previous = NULL;
    temp->next = *begin;
    if ((*begin)->circle == NULL) {
        (*begin) = temp;
    } else {
        (*begin)->previous = temp;
        (*begin) = temp;
    }
}
