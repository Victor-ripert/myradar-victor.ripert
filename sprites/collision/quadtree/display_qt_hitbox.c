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

void display_qt_hitbox(sfRenderWindow *window, quadtree_hitbox_t *qt_hitbox, disp_t displayed)
{
    if (displayed.hitbox == 1) {
        sfRenderWindow_drawRectangleShape(window, qt_hitbox->A_ht, NULL);
        sfRenderWindow_drawRectangleShape(window, qt_hitbox->B_ht, NULL);
        sfRenderWindow_drawRectangleShape(window, qt_hitbox->C_ht, NULL);
        sfRenderWindow_drawRectangleShape(window, qt_hitbox->D_ht, NULL);
    }
}