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

int start_to_end_list(plane_list_t **list, plane_list_t actual)
{
    plane_list_t *tmp;
    // hitbox_cube_t tmp_cube;
    // hitbox_cube_t actual_cube = find_4_faces(actual.top_left_pos, actual.normalized_vector);
    cube_t tmp_cube;
    cube_t actual_cube = find_4_vertece(actual.hitbox);
    printf("4 verteces found !!\n");

    tmp = (*list);
    while (tmp != NULL) {
        if (tmp->enable == 1) {
            // tmp_cube = find_4_faces(tmp->top_left_pos, tmp->normalized_vector);
            tmp_cube = find_4_vertece(tmp->hitbox);
            printf("Après find 4 verteces tmp_cube\n");
            if (SAT_2_cube(actual_cube, tmp_cube) == 1) {
                printf("===========> Collision beetween plane (%f, %f) and (%f, %f)\n\n", actual.pos.x, actual.pos.y, tmp->pos.x, tmp->pos.y);
                actual.enable = 2;
                tmp->enable = 2;
                sfRectangleShape_setFillColor(actual.hitbox, sfWhite);
                sfRectangleShape_setFillColor(tmp->hitbox, sfWhite);
                return 1;
            }
        }
        tmp = tmp->next;
    }
    return 0;
}

int collision_plane_list(plane_list_t **list)
{
    plane_list_t *tmp;

    tmp = (*list);
    while (tmp != NULL)  {
        if (tmp->enable == 1 && tmp->next != NULL) {
            start_to_end_list(&tmp->next, (*tmp));
        }
        tmp = tmp->next;
    }
    return 0;
}