/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include "radar.h"
#include <stdio.h>
#include <stdlib.h>

void display_list(linked_list_t *begin, sfRenderWindow *window)
{
    linked_list_t *temp;

    temp = begin;
    while (temp != NULL) {
        display_node(temp, window);
        temp = temp->next;
    }
}
