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
    sfVector2f scale = {0.3,0.3}; //Peut poser problème avec calculer de collision (changer les autres valeurs ??)
    sfVector2f pos = {100, 100};
    sfVector2f hitbox_size = {285, 268};

    //Set Plane Sprite :
    sfSprite_setTexture(plane, texture, sfTrue);
    sfSprite_setScale(plane, scale);

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
    temp->pos = temp->departure;
    temp->sprite = plane;
    temp->hitbox = hitbox;

    //calcule normalized vector :
    temp->normalized_vector = norm_vector(temp->departure, temp->arrival);
    temp->angle = plane_angle(norm_vector(temp->departure, temp->arrival));

    //hitbox & sprite pos :
    sfVector2f top_left_pos = {(temp->pos.x - ((hitbox_size.x / 2) * scale.x)), (temp->pos.y - ((hitbox_size.y / 2) * scale.y))};
    sfRectangleShape_setPosition(hitbox, top_left_pos);
    sfSprite_setPosition(plane, top_left_pos);
    if (temp->angle > 0) {
        sfRectangleShape_setRotation(hitbox, (temp->angle - 180));
        sfSprite_setRotation(plane, (temp->angle - 180));
    } else {
        sfRectangleShape_setRotation(hitbox, (temp->angle + 180));
        sfSprite_setRotation(plane, (temp->angle + 180));
    }
    if (temp->normalized_vector.x > 0) {
        sfRectangleShape_setRotation(hitbox, (temp->angle));
        sfSprite_setRotation(plane, (temp->angle));
    }
    // sfSprite_setRotation(plane, 0);
    printf("Plane Rottaion = %f\n", temp->angle);

    //push
    push_to_list_plane(begin, temp);
}
