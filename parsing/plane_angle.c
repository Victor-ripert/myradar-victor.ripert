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

float plane_angle(sfVector2f norm)
{
    float result;

    result = norm.y / norm.x;
    result = atan(result);
    result = (result * 180) / M_PI;
    return result;
}