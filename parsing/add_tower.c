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

int add_tower(char *config, tower_list_t **begin, sfTexture *texture)
{
    char **config_array;
    tower_list_t *temp = malloc(sizeof(tower_list_t));
    sfSprite *tower = sfSprite_create();
    sfCircleShape *hitbox = sfCircleShape_create();
    sfVector2f scale = {1, 1}; //Peut poser problème avec calcules de collision (changer les autres valeurs ??)
    sfVector2f sprite_scale = {0.2, 0.2}; //0.2
    sfVector2f radius_center;

    //Set Tower Sprite :
    sfSprite_setTexture(tower, texture, sfTrue);
    sfSprite_setScale(tower, sprite_scale);

    printf("Add Plane !!\n");

    config_array = my_str_to_word_array(config, ' ');
    temp->position.x = str_to_nbr(config_array[1]);
    temp->position.y = str_to_nbr(config_array[2]);
    temp->radius = str_to_nbr(config_array[3]);
    temp->sprite = tower;
    temp->hitbox = hitbox;

    //Set plane Hitbox :
    sfCircleShape_setFillColor(hitbox, sfTransparent);
    sfCircleShape_setOutlineThickness(hitbox, 3);
    sfCircleShape_setOutlineColor(hitbox, sfRed);
    sfCircleShape_setScale(hitbox, scale);
    sfCircleShape_setRadius(hitbox, temp->radius);

    //hitbox & sprite pos :
    int tower_texture_size = 512;
    radius_center.x = (temp->position.x - temp->radius); //+ (tower_texture_size * scale.x);
    radius_center.y = (temp->position.y - temp->radius); //+ (tower_texture_size * scale.y);
    sfCircleShape_setPosition(hitbox, radius_center);
    int sprite_position = ((tower_texture_size / 2) * sprite_scale.x);
    sfVector2f sprite_pos = {temp->position.x - sprite_position, temp->position.y - sprite_position};
    sfSprite_setPosition(tower, sprite_pos);

    //push
    push_to_list_tower(begin, temp);
}
