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



cube_t find_4_vertece(sfRectangleShape *hitbox)
{
    sfTransform transformations = sfRectangleShape_getTransform(hitbox);
    cube_t cube_hitbox; //malloc(sizeof(cube_t));

    cube_hitbox.vertece = malloc(sizeof(sfVector2f) * 4);
    for (int i = 0; i < 4; i++) {
        cube_hitbox.vertece[i] = sfRectangleShape_getPoint(hitbox, i);
        cube_hitbox.vertece[i] = sfTransform_transformPoint(&transformations, cube_hitbox.vertece[i]);
    }
    return cube_hitbox;
}
