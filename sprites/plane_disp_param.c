/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "radar.h"
#include <stdio.h>

void plane_disp_param(sfEvent event, disp_t *param)
{
    if (event.key.code == sfKeyL) {
        if (param->hitbox == 1) {
            param->hitbox = 0;
        } else {
            param->hitbox = 1;
        }
    }
    if (event.key.code == sfKeyS) {
        if (param->sprite == 1) {
            param->sprite = 0;
        } else {
            param->sprite = 1;
        }
    }
}
