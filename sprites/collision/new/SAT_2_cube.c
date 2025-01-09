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

int SAT_2_cube(cube_t first, cube_t second)
{

    printf("SAT 2 CUBE\n");
    cube_t cube1 = cube_to_cube(first);
    printf("Après cube to cube1\n");
    cube_t cube2 = cube_to_cube(second);
    printf("Après cube to cube1\n");
    sfVector2f *stack = malloc(sizeof(sfVector2f) * 8);
    printf("Après stack\n");
    stack_perp(cube1, cube1, stack);
    if (projection_vertece(cube1, cube2, stack) == 1) {
        printf("Se touche\n");
        free(stack);
        return 1;
    }
    free(stack);
    return 0;
}