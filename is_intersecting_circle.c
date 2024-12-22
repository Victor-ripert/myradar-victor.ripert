/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <stdlib.h>
#include "radar.h"

int is_intersecting_circle(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f c1_pos = sfCircleShape_getPosition(c1);
    float c1_radius = sfCircleShape_getRadius(c1);
    sfVector2f c1_center = {c1_pos.x + c1_radius, c1_pos.y + c1_radius};
    sfVector2f c2_pos = sfCircleShape_getPosition(c2);
    float c2_radius = sfCircleShape_getRadius(c2);
    sfVector2f c2_center = {c2_pos.x + c2_radius, c2_pos.y + c2_radius};
    float x_square = (c1_center.x - c2_center.x) * (c1_center.x - c2_center.x);
    float y_square = (c1_center.y - c2_center.y) * (c1_center.y - c2_center.y);
    float c_radius = (c1_radius + c2_radius) * (c1_radius + c2_radius);

    if ((x_square + y_square) <= c_radius) {
        return 1;
    }
    return 0;
}