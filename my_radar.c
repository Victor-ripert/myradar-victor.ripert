/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "radar.h"

int my_radar(char **argv)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfVector2f pos = {50, 50};
    sfVector2f pos_2 = {100, 300};
    sfCircleShape *circle = create_circle(pos, 150);
    sfCircleShape *circle_2 = create_circle(pos_2, 100);
    sfSprite* sprite;
    sfEvent event;
    linked_list_t *list = malloc(sizeof(linked_list_t));
    sfClock *mov_clock = sfClock_create();
    sfClock *delay_clock = sfClock_create();
    int clock_pause = 0;
    disp_t disp_param;
    quadtree_hitbox_t *qt_hitbox = init_qt_hitbox();

    plane_list_t *avion = malloc(sizeof(plane_list_t));
    tower_list_t *tower = malloc(sizeof(tower_list_t));

    disp_param.sprite = 1;
    disp_param.hitbox = 1;
    if (config_parsing(argv[1], &avion, &tower) == 84) {
        return 84;
    }

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    texture = sfTexture_create(800, 600);
    if (!texture)
        return EXIT_FAILURE;

    sprite = sfSprite_create();
    sfRenderWindow_setFramerateLimit(window, 30);
    /* Start the game loop */
    while (sfRenderWindow_isOpen(window))
    {
        /* Process events */
        while (sfRenderWindow_pollEvent(window, &event))
        {
            /* Close window : exit */
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyReleased) {
                clock_pause = pause(event, clock_pause);
                plane_disp_param(event, &disp_param);
            }
        }
        //Collision entre avions
        // collision_plane_list(&avion);
        collision_tower(&tower, &avion);
        quadtree(&avion);
        /* Clear the screen */
        enable_plane(&avion, delay_clock);
        if (clock_pause == 0) {
            movement(&avion, mov_clock);
        }
        sfRenderWindow_clear(window, sfBlack);
        //Draw all plane & tower
        display_list_plane(avion, window, disp_param);
        display_list_tower(tower, window, disp_param);
        display_qt_hitbox(window, qt_hitbox, disp_param);
        /* Draw the sprite */
        display(window, sprite);
        /* Update the window */
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    destroy_qt_hitbox(qt_hitbox);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
