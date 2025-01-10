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

int quadtree(plane_list_t **list)
{
    plane_list_t *tmp;
    quadtree_t *A = malloc(sizeof(quadtree_t));
    quadtree_t *B = malloc(sizeof(quadtree_t));
    quadtree_t *C = malloc(sizeof(quadtree_t));
    quadtree_t *D = malloc(sizeof(quadtree_t));

    A->next = NULL;
    A->previous = NULL;
    A->plane = NULL;
    B->next = NULL;
    B->previous = NULL;
    B->plane = NULL;
    C->next = NULL;
    C->previous = NULL;
    C->plane = NULL;
    D->next = NULL;
    D->previous = NULL;
    D->plane = NULL;
    tmp = (*list);
    while (tmp != NULL)  {
        if (tmp->pos.x < 960 && tmp->pos.y < 540) {
            push_list_quadtree(&A, tmp);
            sfRectangleShape_setFillColor(tmp->hitbox, sfRed);
        }
        if (tmp->pos.x > 960 && tmp->pos.y < 540) {
            push_list_quadtree(&B, tmp);
            sfRectangleShape_setFillColor(tmp->hitbox, sfBlue);
        }
        if (tmp->pos.x < 960 && tmp->pos.y > 540) {
            push_list_quadtree(&C, tmp);
            sfRectangleShape_setFillColor(tmp->hitbox, sfYellow);
        }
        if (tmp->pos.x > 960 && tmp->pos.y > 540) {
            push_list_quadtree(&D, tmp);
            sfRectangleShape_setFillColor(tmp->hitbox, sfGreen);
        }
        tmp = tmp->next;
    }
    collision_plane_list(&A);
    collision_plane_list(&B);
    collision_plane_list(&C);
    collision_plane_list(&D);
    free_quadtree(&A);
    free_quadtree(&B);
    free_quadtree(&C);
    free_quadtree(&D);
    return 0;
}