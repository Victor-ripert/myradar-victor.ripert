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

hitbox_face_t find_next_face(hitbox_face_t previous_face)
{
    sfVector2f new_vector = {previous_face.B.y - previous_face.A.y, (previous_face.B.x - previous_face.A.x) * -1};
    hitbox_face_t new_face;

    new_face.A = previous_face.B;
    new_face.B.x = new_face.A.x + new_vector.x;
    new_face.B.y = new_face.A.y + new_vector.y;
    return new_face;
}

hitbox_cube_t find_4_faces(sfVector2f top_left_pos, sfVector2f normalized_vector)
{
    hitbox_cube_t cube;
    hitbox_face_t AB;
    hitbox_face_t BD;
    hitbox_face_t DC;
    hitbox_face_t CA;

    AB.A = top_left_pos;
    AB.B.x = top_left_pos.x + (normalized_vector.x * 20);
    AB.B.y = top_left_pos.y + (normalized_vector.y * 20);
    BD = find_next_face(AB);
    DC = find_next_face(BD);
    CA = find_next_face(DC);
    cube.AB = AB;
    cube.BD = BD;
    cube.DC = DC;
    cube.CA = CA;
    return cube;
}
