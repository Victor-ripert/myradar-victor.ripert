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
#include "math.h"

sfVector2f norm_vector(sfVector2f pos1, sfVector2f pos2)
{
    sfVector2f result;
    float pythagore;

    result.x = pos2.x - pos1.x;
    result.y = pos2.y - pos1.y;
    pythagore = (result.x * result.x) + (result.y * result.y);
    pythagore = sqrt(pythagore);

    result.x = result.x / pythagore;
    result.y = result.y / pythagore;

    return result;
}