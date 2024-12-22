/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include "radar.h"
#include <stdio.h>
#include <stdlib.h>

void display_list_tower(tower_list_t *begin, sfRenderWindow *window)
{
    tower_list_t *temp;

    temp = begin;
    while (temp != NULL) {
        display_node_tower(temp, window);
        temp = temp->next;
    }
    //printf("End of Plane's List.\n");
}
