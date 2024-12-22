/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include "radar.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>


void display_node(linked_list_t *node, sfRenderWindow *window)
{
    sfRenderWindow_drawCircleShape(window, node->circle, NULL);
}
