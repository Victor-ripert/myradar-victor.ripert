/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include "radar.h"
#include <stdio.h>
#include <stdlib.h>

void delete_in_list(linked_list_t **begin, int id)
{
    linked_list_t *temp;

    temp = *begin;
    while (temp != NULL) {
        if (temp->id == id) {
            replace_ptr(&temp, begin);
            free(temp);
            temp = *begin;
        } else {
            temp = temp->next;
        }
    }
}
