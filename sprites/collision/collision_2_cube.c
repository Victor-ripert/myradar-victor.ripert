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

void display_cube(hitbox_cube_t first)
{
    printf("Cube 1 : \n");
    printf("\tAB {(%f, %f),(%f, %f)}\n", first.AB.A.x, first.AB.A.y, first.AB.B.x, first.AB.B.y);
    printf("\tBD {(%f, %f),(%f, %f)}\n", first.BD.A.x, first.BD.A.y, first.BD.B.x, first.BD.B.y);
    printf("\tDC {(%f, %f),(%f, %f)}\n", first.DC.A.x, first.DC.A.y, first.DC.B.x, first.DC.B.y);
    printf("\tCA {(%f, %f),(%f, %f)}\n", first.CA.A.x, first.CA.A.y, first.CA.B.x, first.CA.B.y);
}

int collision_face_cube(hitbox_face_t face, hitbox_cube_t cube)
{
    if (collision_2_faces(face, cube.AB) == 1) {
        printf("Cube 2 : Face AB\n");
        printf("Face (%f, %f), (%f, %f) == Face (%f, %f), (%f, %f)\n", face.A.x, face.A.y, face.B.x, face.B.y, cube.AB.A.x, cube.AB.A.y, cube.AB.B.x, cube.AB.B.y);
        printf("    -> Face (%f, %f), (%f, %f) == Face (%f, %f), (%f, %f)\n", face.A.x, face.A.y, face.B.x, face.B.y, cube.BD.A.x, cube.BD.A.y, cube.BD.B.x, cube.BD.B.y);
        return 1;
    }
    if (collision_2_faces(face, cube.BD) == 1) {
        printf("Cube 2 : Face BD\n");
        printf("Face (%f, %f), (%f, %f) == Face (%f, %f), (%f, %f)\n", face.A.x, face.A.y, face.B.x, face.B.y, cube.BD.A.x, cube.BD.A.y, cube.BD.B.x, cube.BD.B.y);
        printf("    -> Face (%f, %f), (%f, %f) == Face (%f, %f), (%f, %f)\n", face.A.x, face.A.y, face.B.x, face.B.y, cube.AB.A.x, cube.AB.A.y, cube.AB.B.x, cube.AB.B.y);
        return 1;
    }
    if (collision_2_faces(face, cube.DC) == 1) {
        printf("Cube 2 : Face DC\n");
        printf("Face (%f, %f), (%f, %f) == Face (%f, %f), (%f, %f)\n", face.A.x, face.A.y, face.B.x, face.B.y, cube.DC.A.x, cube.DC.A.y, cube.DC.B.x, cube.DC.B.y);
        printf("    -> Face (%f, %f), (%f, %f) == Face (%f, %f), (%f, %f)\n", face.A.x, face.A.y, face.B.x, face.B.y, cube.BD.A.x, cube.BD.A.y, cube.BD.B.x, cube.BD.B.y);
        return 1;
    }
    if (collision_2_faces(face, cube.CA) == 1) {
        printf("Cube 2 : Face CA\n");
        printf("Face (%f, %f), (%f, %f) == Face (%f, %f), (%f, %f)\n", face.A.x, face.A.y, face.B.x, face.B.y, cube.CA.A.x, cube.CA.A.y, cube.CA.B.x, cube.CA.B.y);
        printf("    -> Face (%f, %f), (%f, %f) == Face (%f, %f), (%f, %f)\n", face.A.x, face.A.y, face.B.x, face.B.y, cube.BD.A.x, cube.BD.A.y, cube.BD.B.x, cube.BD.B.y);
        return 1;
    }
    return 0;
}

sfVector2f *stack_perp(cube_t cube1, cube_t cube2, sfVector2f *stack)
{

    stack[0] = cube1.perp1;
    stack[1] = cube1.perp2;
    stack[2] = cube1.perp3;
    stack[3] = cube1.perp4;
    stack[4] = cube2.perp1;
    stack[5] = cube2.perp2;
    stack[6] = cube2.perp3;
    stack[7] = cube2.perp4;
    return stack;
}

int collision_2_cube(hitbox_cube_t first, hitbox_cube_t second)
{
    // // display_cube(first);
    // // display_cube(second);
    // if (collision_face_cube(first.AB, second) == 1) {
    //     printf("Cube 1 : Face AB\n");
    //     display_cube(first);
    //     display_cube(second);
    //     return 1;
    // }
    // if (collision_face_cube(first.BD, second) == 1) {
    //     printf("Cube 1 : Face BD\n");
    //     display_cube(first);
    //     display_cube(second);
    //     return 1;
    // }
    // if (collision_face_cube(first.DC, second) == 1) {
    //     printf("Cube 1 : Face DC\n");
    //     display_cube(first);
    //     display_cube(second);
    //     return 1;
    // }
    // if (collision_face_cube(first.CA, second) == 1) {
    //     printf("Cube 1 : Face CA\n");
    //     display_cube(first);
    //     display_cube(second);
    //     return 1;
    // }

    // printf("Collision Cube \n");
    cube_t cube1 = cube_to_cube(first);
    // printf("Cube to Cube 1\n");
    cube_t cube2 = cube_to_cube(second);
    // printf("Cube to Cube 2\n");
    sfVector2f *stack = malloc(sizeof(sfVector2f) * 8);
    stack_perp(cube1, cube1, stack);
    // printf("Stack perpendicular vector\n");
    if (projection_vertece(cube1, cube2, stack) == 1) {
        printf("Se touche\n");
        free(stack);
        return 1;
    }
    // printf("Se touche pas\n");
    free(stack);
    return 0;
}