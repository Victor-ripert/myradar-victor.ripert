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

int config_parsing(char *pathname, plane_list_t **begin_plane, tower_list_t **begin_tower)
{
    FILE *stream;
    char *line;
    size_t len = 0;
    sfTexture *plane_texture;
    sfTexture *tower_texture;

    printf("Config Parsing -->\n");
    printf("pathname = %s\n", pathname);

    stream = fopen(pathname, "r");
    if (stream == NULL) {
        perror("fopen");
        return 84;
    }

    //set texture for plane & tower :
    plane_texture = sfTexture_createFromFile("sprites/texture/plane.png", NULL);
    tower_texture = sfTexture_createFromFile("sprites/texture/tower.png", NULL);

    while (getline(&line, &len, stream) != -1) {
        if (line[0] == 'A') {
            add_plane(line, begin_plane, plane_texture);
        }
        if (line[0] == 'T') {
            add_tower(line, begin_tower, tower_texture);
        }
        printf("%s\n", line);
    }
    printf("fin des args !!\n");
    return 0;
}
