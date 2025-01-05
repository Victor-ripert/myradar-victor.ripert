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

int add_plane(char *config, plane_list_t **begin, sfTexture *texture)
{
    sfVector2i start_pos;
    sfVector2i end_pos;
    int speed;
    int delay;
    char **config_array;
    plane_list_t *temp = malloc(sizeof(plane_list_t));
    sfSprite *plane = sfSprite_create();
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfVector2f scale = {1, 1}; //0.3Peut poser problème avec calculer de collision (changer les autres valeurs ??)
    sfVector2f scale_sprite = {0.08, 0.08};
    sfVector2f pos = {100, 100};
    sfVector2f hitbox_size = {20, 20};    //285, 268CHanger taille avion & hitbox : 20x20 px square

    //Set Plane Sprite :
    sfSprite_setTexture(plane, texture, sfTrue);
    sfSprite_setScale(plane, scale_sprite);

    //Set plane Hitbox :
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(hitbox, 3);
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setScale(hitbox, scale);
    sfRectangleShape_setSize(hitbox, hitbox_size);


    printf("Add Plane !!\n");

    config_array = my_str_to_word_array(config, ' ');
    temp->departure.x = str_to_nbr(config_array[1]);
    temp->departure.y = str_to_nbr(config_array[2]);
    temp->arrival.x = str_to_nbr(config_array[3]);
    temp->arrival.y = str_to_nbr(config_array[4]);
    temp->speed = str_to_nbr(config_array[5]);
    temp->delay = str_to_nbr(config_array[6]);
    temp->enable = 0;
    temp->pos = temp->departure;
    temp->sprite = plane;
    temp->hitbox = hitbox;
    sfVector2f top_left_pos;

    //calcule normalized vector :
    temp->normalized_vector = norm_vector(temp->departure, temp->arrival);
    temp->angle = plane_angle(norm_vector(temp->departure, temp->arrival));

    //hitbox & sprite rotation :
    //si le vecteur depasse 360 --> -360
    if (temp->angle > 360) {
        temp->angle -= 360;
    }
    //si le vecteur depasse -360 --> +360
    if (temp->angle < -360) {
        temp->angle += 360;
    }
    // //set all vectors at 0
    // if (temp->angle < 0) {
    //     temp->angle = temp->angle * -1;
    //     temp->angle = 360 - temp->angle;
    // }
    // if (temp->angle == -0) {
    //     temp->angle = 0;
    // }
    // si deplacement negatif (vers la gauche) += 180;
    if (temp->normalized_vector.x < 0) {
        temp->angle += 180;
    }
    // if (temp->normalized_vector.y <= 0) {

    // }
    // printf("temp->angle = %f\n", temp->angle);
    // sfRectangleShape_setRotation(hitbox, temp->angle);
    // sfSprite_setRotation(plane, temp->angle);
    // printf("--------------- Rotation = %f\n", temp->angle);
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

    //Top_left Pos position :
    top_left_pos = find_top_left(temp->pos, temp->normalized_vector);
    temp->top_left_pos = temp->pos;
    temp->top_left_pos = top_left_pos;

    //hitbox & sprite position
    // printf("temp->angle reordonner = %f\n", temp->angle);
    // top_left_pos.x = (temp->pos.x - ((hitbox_size.x / 2) * scale.x));
    // top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
    // if (temp->angle > 0) {
    //     // angle 0
    //     if ((temp->angle > 270 && temp->angle <= 360) || (temp->angle <= 0 && temp->angle > -90)) {
    //         top_left_pos.x = (temp->pos.x - ((hitbox_size.x / 2) * scale.x));
    //         top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
    //     }
    //     // angle 90
    //     if (temp->angle > 0 && temp->angle <= 90) {
    //         printf("je suis 90\n");
    //         top_left_pos.x = (temp->pos.x - ((hitbox_size.x / 2) * scale.x));
    //         top_left_pos.y = (temp->pos.y + ((hitbox_size.y / 2) * scale.y));
    //     }
    //     // angle 180
    //     if (temp->angle > 90 && temp->angle <= 180) {
    //         printf("je suis pas 90\n");
    //         top_left_pos.x = (temp->pos.x + ((hitbox_size.x / 2) * scale.x));
    //         top_left_pos.y = (temp->pos.y + ((hitbox_size.y / 2) * scale.y));
    //     }
    //     // angle 270
    //     if (temp->angle > 180 && temp->angle <= 270) {
    //         printf("toujours pars\n");
    //         top_left_pos.x = (temp->pos.x + ((hitbox_size.x / 2) * scale.x));
    //         top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
    //     }
    // } else {
    //     if (temp->angle <= -360 && temp->angle > -270) {
    //         top_left_pos.x = (temp->pos.x - ((hitbox_size.x / 2) * scale.x));
    //         top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
    //     }
    //     if (temp->angle <= -270 && temp->angle > -180) {
    //         top_left_pos.x = (temp->pos.x - ((hitbox_size.x / 2) * scale.x));
    //         top_left_pos.y = (temp->pos.y + ((hitbox_size.y / 2) * scale.y));
    //     }
    //     if (temp->angle <= -180 && temp->angle > -90) {
    //         top_left_pos.x = (temp->pos.x + ((hitbox_size.x / 2) * scale.x));
    //         top_left_pos.y = (temp->pos.y + ((hitbox_size.y / 2) * scale.y));
    //     }
    //     if (temp->angle <= -90 && temp->angle > -0) {
    //         top_left_pos.x = (temp->pos.x + ((hitbox_size.x / 2) * scale.x));
    //         top_left_pos.y = (temp->pos.y - ((hitbox_size.y / 2) * scale.y));
    //     }
    // }
    // temp->top_left_pos = top_left_pos;

    sfRectangleShape_setRotation(hitbox, temp->angle);
    sfSprite_setRotation(plane, temp->angle);
    // printf("--------------- Rotation = %f\n", temp->angle);

    sfRectangleShape_setPosition(hitbox, temp->top_left_pos);
    sfSprite_setPosition(plane, temp->top_left_pos);
    //printf("topleftpos = {%f, %f}\n", temp->top_left_pos.x, temp->top_left_pos.y);


    // sfSprite_setRotation(plane, 0);
    // printf("Plane Rottaion = %f\n", temp->angle);

    //push
    push_to_list_plane(begin, temp);
}
