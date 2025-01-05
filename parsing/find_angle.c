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

void find_angle(plane_list_t *temp)
{
    sfVector2f top_left_pos;
    //hitbox & sprite rotation :
    //si le vecteur depasse 360 --> -360
    if (temp->angle > 360) {
        temp->angle -= 360;
    }
    //si le vecteur depasse -360 --> +360
    if (temp->angle < -360) {
        temp->angle += 360;
    }
    // si deplacement negatif (vers la gauche) += 180;
    if (temp->normalized_vector.x < 0) {
        temp->angle += 180;
    }
    // if (temp->normalized_vector.y <= 0) {

    // }
    // printf("temp->angle = %f\n", temp->angle);
    sfRectangleShape_setRotation(hitbox, temp->angle);
    sfSprite_setRotation(plane, temp->angle);
    printf("--------------- Rotation = %f\n", temp->angle);
    // if (temp->normalized_vector.x >= 0) {
    //     sfRectangleShape_setRotation(hitbox, (temp->angle));
    //     sfSprite_setRotation(plane, (temp->angle));
    // } else {
        // if (temp->angle > 0) {
        //     temp->angle = temp->angle - 180;
        //     sfRectangleShape_setRotation(hitbox, temp->angle);
        //     sfSprite_setRotation(plane, temp->angle);
        // } else {
        //     temp->angle = temp->angle + 180;
        //     sfRectangleShape_setRotation(hitbox, temp->angle);
        //     sfSprite_setRotation(plane, temp->angle);
        // }
    //}

    //hitbox & sprite position
    // printf("temp->angle reordonner = %f\n", temp->angle);
    top_left_pos.x = (temp->pos.x - ((hitbox_size.x / 2) * scale.x));
    top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
    if (temp->angle > 0) {
        // angle 0
        if ((temp->angle > 270 && temp->angle <= 360) || (temp->angle <= 0 && temp->angle > -90)) {
            top_left_pos.x = (temp->p ((hitbox_size.x / 2) * scale.x));
            top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
        }
        // angle 90
        if (temp->angle > 0 && temp->angle <= 90) {
            printf("je suis 90\n");
            top_left_pos.x = (temp->pos.x - ((hitbox_size.x / 2) * scale.x));
            top_left_pos.y = (temp->pos.y + ((hitbox_size.y / 2) * scale.y));
        }
        // angle 180
        if (temp->angle > 90 && temp->angle <= 180) {
            printf("je suis pas 90\n");
            top_left_pos.x = (temp->pos.x + ((hitbox_size.x / 2) * scale.x));
            top_left_pos.y = (temp->pos.y + ((hitbox_size.y / 2) * scale.y));
        }
        // angle 270
        if (temp->angle > 180 && temp->angle <= 270) {
            printf("toujours pars\n");
            top_left_pos.x = (temp->pos.x + ((hitbox_size.x / 2) * scale.x));
            top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
        }
    } else {
        if (temp->angle <= -360 && temp->angle > -270) {
            top_left_pos.x = (temp->pos.x - ((hitbox_size.x / 2) * scale.x));
            top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
        }
        if (temp->angle <= -270 && temp->angle > -180) {
            top_left_pos.x = (temp->pos.x - ((hitbox_size.x / 2) * scale.x));
            top_left_pos.y = (temp->pos.y + ((hitbox_size.y / 2) * scale.y));
        }
        if (temp->angle <= -180 && temp->angle > -90) {
            top_left_pos.x = (temp->pos.x + ((hitbox_size.x / 2) * scale.x));
            top_left_pos.y = (temp->pos.y + ((hitbox_size.y / 2) * scale.y));
        }
        if (temp->angle <= -90 && temp->angle > -0) {
            top_left_pos.x = (temp->pos.x + ((hitbox_size.x / 2) * scale.x));
            top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
        }
    }
    temp->top_left_pos = top_left_pos;
    sfRectangleShape_setPosition(hitbox, temp->top_left_pos);
    sfSprite_setPosition(plane, temp->top_left_pos);
    printf("topleftpos = {%f, %f}\n", temp->top_left_pos.x, temp->top_left_pos.y);
}
