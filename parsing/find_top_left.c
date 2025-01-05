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

sfVector2f find_top_left(sfVector2f pos, sfVector2f normalized_vector)
{
    sfVector2f A = pos;
    sfVector2f AB = {normalized_vector.x * 10, normalized_vector.y * 10};
    sfVector2f B = {A.x + AB.x, A.y + AB.y};
    sfVector2f BC = {B.y - A.y, (B.x - A.x) * -1};
    sfVector2f C = {B.x + BC.x, B.y + BC.y};
    sfVector2f top_left = {A.x + (BC.x), A.y + (BC.y)};

    top_left.x += AB.x;
    top_left.y += AB.y;
    return top_left;
}
