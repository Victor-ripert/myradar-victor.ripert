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

int is_super_posed(sfVector2f first, sfVector2f second, sfVector2f third)
{
    if (third.x >= first.x && third.x <= second.x || third.x >= second.x && third.x <= first.x) {
        if (third.y >= first.y && third.y <= second.y || third.y >= second.y && third.y <= first.y) {
            return 1;
        }
    }
    return 0;
}

int find_orientation(sfVector2f first, sfVector2f second, sfVector2f third)
{
    int result = ((second.y - first.y) * (third.x - second.x)) - ((second.x -first.x) * (third.y - second.y));
    return result;
}

int collision_2_faces(hitbox_face_t first, hitbox_face_t second)
{
    int orientation_1 = find_orientation(first.A, first.B, second.A);
    int orientation_2 = find_orientation(first.A, first.B, second.B);
    int orientation_3 = find_orientation(second.A, second.B, first.A);
    int orientation_4 = find_orientation(second.A, second.B, first.B);

    if (orientation_1 * orientation_2 < 0 && orientation_3 * orientation_4 < 0) {
           printf("===========> Les deux faces se touches\n");
        return 1;
    }
    //Cas geenral si les deux faces se touches
    // if (orientation_1 != orientation_2 && orientation_3 != orientation_4) {
    //     printf("===========> Les deux faces se touches\n");
    //     return 1;
    // }

    //Cas special si les deux faces soint colinéire et supeposer (si colinéaire = 0, donc check si superposer)
    if (orientation_1 == 0 && is_super_posed(first.A, first.B, second.A) == 1) {
        printf("===========> Colinear faces\n");
        return 1;
    }
    if (orientation_2 == 0 && is_super_posed(first.A, first.B, second.B) == 1) {
        printf("===========> Colinear faces\n");
        return 1;
    }
    if (orientation_3 == 0 && is_super_posed(second.A, second.B, first.A) == 1) {
        printf("===========> Colinear faces\n");
        return 1;
    }
    if (orientation_4 == 0 && is_super_posed(second.A, second.B, first.B) == 1) {
        printf("===========> Colinear faces\n");
        return 1;
    }
    return 0;
}