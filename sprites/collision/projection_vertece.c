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

void display_vertex(cube_t cube) {
    for (int i = 0; i < 4; i++) {
        printf("\t(%f, %f)\n", cube.vertece[i].x, cube.vertece[i].y);
    }
}

int projection_vertece(cube_t cube1, cube_t cube2, sfVector2f *stack)
{
    // printf("Projection Vertece\n");
    float amax;
    float amin;
    float bmax;
    float bmin;
    float dot;

    printf("cube1 :\n");
    printf("\t(%f, %f) == (%f, %f) ?\n", cube1.perp1.x, cube1.perp1.y, cube1.edge[0].x, cube1.edge[0].y);
    printf("\t(%f, %f) == (%f, %f) ?\n", cube1.perp2.x, cube1.perp2.y, cube1.edge[1].x, cube1.edge[1].y);
    printf("\t(%f, %f) == (%f, %f) ?\n", cube1.perp3.x, cube1.perp3.y, cube1.edge[2].x, cube1.edge[2].y);
    printf("\t(%f, %f) == (%f, %f) ?\n", cube1.perp4.x, cube1.perp4.y, cube1.edge[3].x, cube1.edge[3].y);
    printf("\t(%f, %f)\n", cube1.vertece[0].x, cube1.vertece[0].y);
    printf("\t(%f, %f)?\n", cube1.vertece[1].x, cube1.vertece[1].y);
    printf("\t(%f, %f)?\n", cube1.vertece[2].x, cube1.vertece[2].y);
    printf("\t(%f, %f)?\n", cube1.vertece[3].x, cube1.vertece[3].y);

    //Boucle Vertice
    for(int i = 0; i < 8; i++) {
        // printf("Face perp Vector %d\n", i);
        //printf("stack[i] == (%f, %f)   ==== (%f, %f)\n", stack[i].x, stack[i].y, cube1.perp1.x, cube1.perp1.y);
        //Amax, amin, bmax, bmin == projection vertice 1 de chaque cube sur perp[i]
        amax = (cube1.vertece[0].x * stack[i].x ) + (cube1.vertece[0].y + stack[i].y);
        amin = (cube1.vertece[0].x * stack[i].x ) + (cube1.vertece[0].y + stack[i].y);
        bmax = (cube2.vertece[0].x * stack[i].x ) + (cube2.vertece[0].y + stack[i].y);
        bmin = (cube2.vertece[0].x * stack[i].x ) + (cube2.vertece[0].y + stack[i].y);
        //Boucle projection vertece[j] de cube 1 par perp[i]
        for (int j = 0; j < 4; j++) {
            dot = (cube1.vertece[j].x * stack[i].x ) + (cube1.vertece[j].y + stack[i].y);
            if(dot > amax) {
                amax = dot;
            }
            if(dot < amin) {
                amin = dot;
            }
        }
        dot = 0;
        //Boucle projection vertece[j] de cube 2 par perp[i]
        for (int j = 0; j < 4; j++) {
            dot = (cube2.vertece[j].x * stack[i].x ) + (cube2.vertece[j].y + stack[i].y);
            if(dot > bmax) {
                bmax = dot;
            }
            if(dot < bmin) {
                bmin = dot;
            }
        }
        //printf("%d < %d && %d > %d || %d < %d && %d > %d\n", amin, bmax, amin, bmin, bmin, amax, bmin, amin);
        if ((amin < bmax && amin > bmin) || (bmin < amax && bmin > amin)) {
            printf("V : %f < %f && %f > %f || %f < %f && %f > %f\n", amin, bmax, amin, bmin, bmin, amax, bmin, amin);
            printf("Le carrer est superposer !!\n");
        } else {
            // printf("F : %d < %d && %d > %d || %d < %d && %d > %d\n", amin, bmax, amin, bmin, bmin, amax, bmin, amin);
            // printf("Carré pas superposé !!\n");
            // printf("Pas de Collision\n");
            return 0;
        }
    }
        display_vertex(cube1);
        display_vertex(cube2);
    printf("Collision !!\n");
    return 1;
}
