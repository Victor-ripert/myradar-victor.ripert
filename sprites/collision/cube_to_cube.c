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

sfVector2f find_edge(sfVector2f vertece1, sfVector2f vertece2)
{
    sfVector2f edge = {vertece2.x - vertece1.x, vertece2.y - vertece1.y};

    return edge;
}

sfVector2f find_perp_vector(sfVector2f edge)
{
    sfVector2f perp = {(edge.y * -1), edge.x};
    if (edge.y == 0) {
        perp.x = 0;
    }

    return perp;
}

cube_t cube_to_cube(cube_t cube)
{

    // cube.vertece[0] = hitbox.AB.A;
    // cube.vertece[1] = hitbox.BD.A;
    // cube.vertece[2] = hitbox.DC.A;
    // cube.vertece[3] = hitbox.CA.A;
    cube.edge[0] = find_edge(cube.vertece[0], cube.vertece[1]);
    cube.edge[1] = find_edge(cube.vertece[1], cube.vertece[2]);
    cube.edge[2] = find_edge(cube.vertece[2], cube.vertece[3]);
    cube.edge[3] = find_edge(cube.vertece[3], cube.vertece[0]);
    cube.perp1 = find_perp_vector(cube.edge[0]);
    cube.perp2 = find_perp_vector(cube.edge[1]);
    cube.perp3 = find_perp_vector(cube.edge[2]);
    cube.perp4 = find_perp_vector(cube.edge[3]);
    return cube;
}