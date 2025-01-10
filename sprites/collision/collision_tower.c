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

void collision_tower(tower_list_t **tower, plane_list_t **plane)
{
    tower_list_t *tmp_tower;
    plane_list_t *tmp_plane;
    int x_tower = 0;
    int y_tower = 0;
    int x_plane = 0;
    int y_plane = 0;
    int result_x = 0;
    int result_y = 0;

    tmp_tower = (*tower);
    tmp_plane = (*plane);
    while (tmp_tower != NULL) {
        x_tower = tmp_tower->position.x;
        y_tower = tmp_tower->position.y;
        while (tmp_plane != NULL) {
            x_plane = tmp_plane->pos.x;
            y_plane = tmp_plane->pos.y;
        result_x = (x_tower - x_plane);
        result_y = (y_tower - y_plane);
        if (result_x < 0) {
            result_x * -1;
        }
        if (result_y < 0) {
            result_y * -1;
        }
        if (result_x <= tmp_tower->radius && result_y <= tmp_tower->radius) {
            tmp_plane->in_tower_radius = 1;
        } else {
            tmp_plane->in_tower_radius = 0;
        }
        tmp_plane = tmp_plane->next;
        }
        tmp_tower = tmp_tower->next;
    }
}
