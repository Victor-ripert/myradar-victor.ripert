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


void display_node_plane(plane_list_t *node, sfRenderWindow *window)
{
    //printf("Plane :\n\tid->%d\n\tdeparture->%f\n\tspeed->%d,\n\tdelay->%d\n", node->id, node->departure.x, node->speed, node->delay);
    // sfRenderWindow_drawCircleShape(window, node->circle, NULL);
    //printf("Plane SPrite :\n");
    //printf("test plane\n");
    if (node != NULL) {
        sfRenderWindow_drawSprite(window, node->sprite, NULL);
        //printf("Plane Rect :\n");
        sfRenderWindow_drawRectangleShape(window, node->hitbox, NULL);
    };
    //printf("After Plane rect !!\n");
}
