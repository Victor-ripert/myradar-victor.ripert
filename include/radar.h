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


//Structure params (here for enable dislay of sprite & hitboxes)
typedef struct disp_s {
    int sprite;
    int hitbox;
} disp_t;

//Structure hitbox_face
typedef struct hitbox_face_s {
    sfVector2f A;
    sfVector2f B;
} hitbox_face_t;

//Structure hitbox_cube (all four faces)
typedef struct hitbox_cube_s {
    hitbox_face_t AB;
    hitbox_face_t BD;
    hitbox_face_t DC;
    hitbox_face_t CA;
} hitbox_cube_t;

typedef struct cube_s {
    sfVector2f *vertece;
    sfVector2f edge[4];
    sfVector2f perp1;
    sfVector2f perp2;
    sfVector2f perp3;
    sfVector2f perp4;
} cube_t;

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
    sfVector2f top_left_pos;
    sfVector2f departure;
    sfVector2f arrival;
    int speed;
    int delay;
    int enable;
    sfVector2f pos;
    sfVector2f normalized_vector;
    float angle;
    int in_tower_radius;
} plane_list_t;
void push_to_list_plane(plane_list_t **begin, plane_list_t *temp);
void display_list_plane(plane_list_t *begin, sfRenderWindow *window, disp_t disp_param);
void display_node_plane(plane_list_t *node, sfRenderWindow *window, disp_t disp_param);
void delete_in_list_plane(plane_list_t **begin, int id);
void replace_ptr_plane(plane_list_t **temp, plane_list_t **begin);

//Structure Quadtree
typedef struct quadtree_s {
    plane_list_t *plane;
    struct quadtree_s *previous;
    struct quadtree_s *next;
} quadtree_t;

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
void display_list_tower(tower_list_t *begin, sfRenderWindow *window, disp_t disp_param);
void display_node_tower(tower_list_t *node, sfRenderWindow *window, disp_t disp_param);
void delete_in_list_tower(tower_list_t **begin, int id);
void replace_ptr_tower(tower_list_t **temp, tower_list_t **begin);

//Parsing :
int config_parsing(char *pathname, plane_list_t **begin_plane, tower_list_t **begin_tower);
int add_plane(char *config, plane_list_t **begin, sfTexture *texture);
int add_tower(char *config, tower_list_t **begin, sfTexture *texture);
sfVector2f norm_vector(sfVector2f pos1, sfVector2f pos2);
sfVector2f find_top_left(sfVector2f pos, sfVector2f normalized_vector);

//Movement :
void movement(plane_list_t **begin, sfClock *clock);
float plane_angle(sfVector2f norm);
int pause(sfEvent event, int clock_pause);
void enable_plane(plane_list_t **begin, sfClock *clock);
void plane_disp_param(sfEvent event, disp_t *param);

//Collision
int collision_2_faces(hitbox_face_t first, hitbox_face_t second);
hitbox_cube_t find_4_faces(sfVector2f top_left_pos, sfVector2f normalized_vector);
int collision_2_cube(hitbox_cube_t first, hitbox_cube_t second);
int collision_plane_list(quadtree_t **list);
int intersecting_droite(hitbox_face_t first, hitbox_face_t second);

//Word array :
char **my_str_to_word_array(char *str, char separator);
int my_strlen(char const *str);
int my_word_len(char *str, char separator, int i);
int str_to_nbr(char *nb);

int my_radar(char **argv);
void display(sfRenderWindow *window, sfSprite *sprite);
sfCircleShape *create_circle(sfVector2f position, float radius);
int is_intersecting_circle(sfCircleShape *c1, sfCircleShape *c2);

//Colision Vrai :
cube_t cube_to_cube(cube_t hitbox);
int projection_vertece(cube_t cube1, cube_t cube2, sfVector2f *stack);
int SAT_2_cube(cube_t first, cube_t second);
cube_t find_4_vertece(sfRectangleShape *hitbox);

//Quadtree
int quadtree(plane_list_t **list);
void push_list_quadtree(quadtree_t **begin, plane_list_t *plane);
void free_quadtree(quadtree_t **list);
void display_quadtree_list(quadtree_t **list);

typedef struct quadtree_hitbox_s {
    sfRectangleShape *A_ht;
    sfRectangleShape *B_ht;
    sfRectangleShape *C_ht;
    sfRectangleShape *D_ht;
} quadtree_hitbox_t;
quadtree_hitbox_t *init_qt_hitbox(void);
void display_qt_hitbox(sfRenderWindow *window, quadtree_hitbox_t *qt_hitbox);
void destroy_qt_hitbox(quadtree_hitbox_t *qt_hitbox);
void collision_tower(tower_list_t **tower, plane_list_t **plane);

#endif /* FILE_H */
