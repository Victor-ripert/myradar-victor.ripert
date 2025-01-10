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

int start_to_end_list(quadtree_t **list, quadtree_t actual)
{
    quadtree_t *tmp;
    cube_t tmp_cube;
    cube_t actual_cube = find_4_vertece(actual.plane->hitbox);

    tmp = (*list);
    while (tmp != NULL) {
        if (tmp->plane->enable == 1 && tmp->plane->in_tower_radius == 0) {
            tmp_cube = find_4_vertece(tmp->plane->hitbox);
            if (SAT_2_cube(actual_cube, tmp_cube) == 1) {
                printf("===========> Collision beetween plane (%f, %f) and (%f, %f)\n\n", actual.plane->pos.x, actual.plane->pos.y, tmp->plane->pos.x, tmp->plane->pos.y);
                actual.plane->enable = 2;
                tmp->plane->enable = 2;
                // sfRectangleShape_setFillColor(actual.plane->hitbox, sfWhite);
                // sfRectangleShape_setFillColor(tmp->plane->hitbox, sfWhite);
                return 1;
            }
        }
        tmp = tmp->next;
    }
    return 0;
}

int collision_plane_list(quadtree_t **list)
{
    quadtree_t *tmp;

    tmp = (*list);
    while (tmp != NULL)  {
        if (tmp->plane->enable == 1 && tmp->plane->in_tower_radius == 0) {
            if (tmp->next != NULL) {
                start_to_end_list(&tmp->next, (*tmp));
            }
        }
        tmp = tmp->next;
    }
    return 0;
}
