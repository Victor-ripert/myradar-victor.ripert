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

void display_node_tower(tower_list_t *node, sfRenderWindow *window, disp_t disp_param)
{
    if (node != NULL) {
        if (disp_param.sprite == 1) {
            sfRenderWindow_drawSprite(window, node->sprite, NULL);
        }
        if (disp_param.hitbox == 1) {
            sfRenderWindow_drawCircleShape(window, node->hitbox, NULL);
        }
    }
}
