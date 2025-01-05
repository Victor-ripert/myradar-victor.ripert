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

int collision_face_cube(hitbox_face_t face, hitbox_cube_t cube)
{
    if (collision_2_faces(face, cube.AB) == 1) {
        return 1;
    }
    if (collision_2_faces(face, cube.BD) == 1) {
        return 1;
    }
    if (collision_2_faces(face, cube.DC) == 1) {
        return 1;
    }
    if (collision_2_faces(face, cube.CA) == 1) {
        return 1;
    }
    return 0;
}

int collision_2_cube(hitbox_cube_t first, hitbox_cube_t second)
{
    if (collision_face_cube(first.AB, second) == 1) {
        return 1;
    }
    if (collision_face_cube(first.BD, second) == 1) {
        return 1;
    }
    if (collision_face_cube(first.DC, second) == 1) {
        return 1;
    }
    if (collision_face_cube(first.CA, second) == 1) {
        return 1;
    }
    return 0;
}