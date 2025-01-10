/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include "radar.h"
#include <stdio.h>
#include <stdlib.h>

void display_list_plane(plane_list_t *begin, sfRenderWindow *window, disp_t disp_param)
{
    plane_list_t *temp;

    temp = begin;
    while (temp != NULL) {
        if (temp->enable == 1) {
            display_node_plane(temp, window, disp_param);
        }
        temp = temp->next;
    }
}
