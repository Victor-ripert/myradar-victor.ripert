/*
** EPITECH PROJECT, 2024
** my
** File description:
** my
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>

#ifndef FILE_H
    #define FILE_H

//Linked List :
typedef struct linked_list_s {
    sfCircleShape *circle;
    int id;
    struct linked_list_s *previous;
    struct linked_list_s *next;
} linked_list_t;
void delete_in_list(linked_list_t **begin, int id);
void replace_ptr(linked_list_t **temp, linked_list_t **begin);
void display_list(linked_list_t *begin, sfRenderWindow *window);
void display_node(linked_list_t *node, sfRenderWindow *window);
void push_to_list(linked_list_t **begin, int id, sfCircleShape *circle);

//Plane :
typedef struct plane_list_s {
    int id;
    struct plane_list_s *previous;
    struct plane_list_s *next;
    sfRectangleShape *hitbox;
    sfSprite *sprite;
    sfVector2f departure;
    sfVector2f arrival;
    int speed;
    int delay;
    sfVector2f pos;
    sfVector2f normalized_vector;
    float angle;
} plane_list_t;
void push_to_list_plane(plane_list_t **begin, plane_list_t *temp);
void display_list_plane(plane_list_t *begin, sfRenderWindow *window);
void display_node_plane(plane_list_t *node, sfRenderWindow *window);
void delete_in_list_plane(plane_list_t **begin, int id);
void replace_ptr_plane(plane_list_t **temp, plane_list_t **begin);

//Tower :
typedef struct tower_list_s {
    int id;
    struct tower_list_s *previous;
    struct tower_list_s *next;
    sfCircleShape *hitbox;
    sfSprite *sprite;
    sfVector2f position;
    float radius;
} tower_list_t;
void push_to_list_tower(tower_list_t **begin, tower_list_t *temp);
void display_list_tower(tower_list_t *begin, sfRenderWindow *window);
void display_node_tower(tower_list_t *node, sfRenderWindow *window);
void delete_in_list_tower(tower_list_t **begin, int id);
void replace_ptr_tower(tower_list_t **temp, tower_list_t **begin);

//Parsing :
int config_parsing(char *pathname, plane_list_t **begin_plane, tower_list_t **begin_tower);
int add_plane(char *config, plane_list_t **begin, sfTexture *texture);
int add_tower(char *config, tower_list_t **begin, sfTexture *texture);
sfVector2f norm_vector(sfVector2f pos1, sfVector2f pos2);

//Movement :
void movement(plane_list_t **begin, sfClock *clock);
float plane_angle(sfVector2f norm);
int pause(sfEvent event, int clock_pause);

//Word array :
char **my_str_to_word_array(char *str, char separator);
int my_strlen(char const *str);
int my_word_len(char *str, char separator, int i);
int str_to_nbr(char *nb);

int my_radar(char **argv);
void display(sfRenderWindow *window, sfSprite *sprite);
sfCircleShape *create_circle(sfVector2f position, float radius);
int is_intersecting_circle(sfCircleShape *c1, sfCircleShape *c2);
#endif /* FILE_H */
