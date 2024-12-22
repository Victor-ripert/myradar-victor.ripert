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

void display_node_tower(tower_list_t *node, sfRenderWindow *window)
{
    //printf("Tower Sprite :\n");
    //printf("test\n");
    if (node != NULL) {
        sfRenderWindow_drawSprite(window, node->sprite, NULL);
        //printf("Tower Circle :\n");
        sfRenderWindow_drawCircleShape(window, node->hitbox, NULL);
    }
    //printf("After Tower circle !!\n");
}
