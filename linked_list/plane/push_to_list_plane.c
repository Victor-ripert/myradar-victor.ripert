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

void push_to_list_plane(plane_list_t **begin, plane_list_t *temp)
{
    temp->id = 0;
    temp->previous = NULL;
    temp->next = *begin;
    if ((*begin)->sprite == NULL) {
        (*begin) = temp;
    } else {
        (*begin)->previous = temp;
        (*begin) = temp;
    }
}
