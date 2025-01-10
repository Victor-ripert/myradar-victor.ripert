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

quadtree_hitbox_t *init_qt_hitbox(void)
{
    quadtree_hitbox_t *qt_hitbox = malloc(sizeof(quadtree_hitbox_t));
    sfRectangleShape *hitbox_a = sfRectangleShape_create();
    sfRectangleShape *hitbox_b = sfRectangleShape_create();
    sfRectangleShape *hitbox_c = sfRectangleShape_create();
    sfRectangleShape *hitbox_d = sfRectangleShape_create();
    sfVector2f pos_a = {0, 0};
    sfVector2f pos_b = {960, 0};
    sfVector2f pos_c = {0, 540};
    sfVector2f pos_d = {960, 540};
    sfVector2f size = {960, 540};

    sfRectangleShape_setPosition(hitbox_a, pos_a);
    sfRectangleShape_setPosition(hitbox_b, pos_b);
    sfRectangleShape_setPosition(hitbox_c, pos_c);
    sfRectangleShape_setPosition(hitbox_d, pos_d);

    sfRectangleShape_setSize(hitbox_a, size);
    sfRectangleShape_setSize(hitbox_b, size);
    sfRectangleShape_setSize(hitbox_c, size);
    sfRectangleShape_setSize(hitbox_d, size);

    sfRectangleShape_setFillColor(hitbox_a, sfTransparent);
    sfRectangleShape_setFillColor(hitbox_b, sfTransparent);
    sfRectangleShape_setFillColor(hitbox_c, sfTransparent);
    sfRectangleShape_setFillColor(hitbox_d, sfTransparent);

    sfRectangleShape_setOutlineColor(hitbox_a, sfRed);
    sfRectangleShape_setOutlineColor(hitbox_b, sfRed);
    sfRectangleShape_setOutlineColor(hitbox_c, sfRed);
    sfRectangleShape_setOutlineColor(hitbox_d, sfRed);

    sfRectangleShape_setOutlineThickness(hitbox_a, 2);
    sfRectangleShape_setOutlineThickness(hitbox_b, 2);
    sfRectangleShape_setOutlineThickness(hitbox_c, 2);
    sfRectangleShape_setOutlineThickness(hitbox_d, 2);

    qt_hitbox->A_ht = hitbox_a;
    qt_hitbox->B_ht = hitbox_b;
    qt_hitbox->C_ht = hitbox_c;
    qt_hitbox->D_ht = hitbox_d;
    return qt_hitbox;
}