/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include "radar.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

void destroy_qt_hitbox(quadtree_hitbox_t *qt_hitbox)
{
    sfRectangleShape_destroy(qt_hitbox->A_ht);
    sfRectangleShape_destroy(qt_hitbox->B_ht);
    sfRectangleShape_destroy(qt_hitbox->C_ht);
    sfRectangleShape_destroy(qt_hitbox->D_ht);
}