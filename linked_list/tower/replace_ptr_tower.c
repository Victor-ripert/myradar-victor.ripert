/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include "radar.h"
#include <stdio.h>
#include <stdlib.h>

void replace_ptr_tower(tower_list_t **temp, tower_list_t **begin)
{
    if ((*temp)->previous != NULL) {
        (*temp)->previous->next = (*temp)->next;
    } else {
        *begin = (*temp)->next;
    }
    if ((*temp)->next != NULL) {
        (*temp)->next->previous = (*temp)->previous;
    }
}
