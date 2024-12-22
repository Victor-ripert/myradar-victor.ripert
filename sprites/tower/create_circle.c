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

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle;
    sfVector2f scale_factor = {1, 1};

    circle = sfCircleShape_create();
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_scale(circle, scale_factor);
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);

    return circle;
}
