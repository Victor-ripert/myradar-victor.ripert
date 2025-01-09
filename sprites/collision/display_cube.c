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