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
#include <math.h>

typedef struct equation_s {
    float a;
    float b;
} equation_t;

equation_t find_equation(hitbox_face_t line)
{
    equation_t line_equation;

    line_equation.a = (line.B.y - line.A.y) / (line.B.x - line.A.x);
    line_equation.b = line.A.y - (line_equation.a * line.A.x);
}

sfVector2f find_intersecting_point(equation_t first, equation_t second)
{
    float x = (second.b - first.b) / (second.a - first.a);
    float y = (first.a * x) + first.b;
    sfVector2f result = {x, y};

    return result;
}

// float find_distance_2_point(sfVector2f A, sfVector2f B)
// {
//     int distance = sqrt()
// }

int find_point_on_line(sfVector2f point, hitbox_face_t face, equation_t face_equation)
{
    // printf("Find Point on Line \n");
    // int n = 0;
    // // ((face_equation.a * i) + face_equation.b) == face.B.y
    // for (int i = face.A.x; n < 20; i++) {
    //     if (n > 20) {
    //         return 0;
    //     }
    //     printf("Equations are =\n");
    //     printf("y = ax+b = %f\n", ((face_equation.a * n) + face_equation.b));
    //     printf("x = %d\n", i);
    //     if (((face_equation.a * i) + face_equation.b) == point.y && i == point.x) {
    //         return 1;
    //     }
    //     n++;
    // }
    // return 0;

    sfVector2f AP;
}

int is_parralle_near(hitbox_face_t first, hitbox_face_t second, equation_t first_equation, equation_t second_equation)
{
    if (first.A.x == second.A.x && first.B.x == second.B.x && first.A.x == second.A.x && first.B.x == second.B.x) {
        return 1;
    }
    if (find_point_on_line(second.A, first, first_equation)) {
        return 1;
    }
    if (find_point_on_line(second.B, first, first_equation)) {
        return 1;
    }
    if (find_point_on_line(first.A, second, second_equation)) {
        return 1;
    }
    if (find_point_on_line(first.B, second, second_equation)) {
        return 1;
    }
    return 0;
}

// int intersecting_droite(hitbox_face_t first, hitbox_face_t second)
// {
//     printf("Check collision !!!!\n");
//     equation_t first_equation = find_equation(first);
//     equation_t second_equation = find_equation(second);
//     sfVector2f point;

//     if (first_equation.a == second_equation.a) {
//         if (first_equation.b == second_equation.b) {
//             // if (first.A.x == second.A.x && first.B.x == second.B.x && first.A.y == second.A.y && first.B.y == second.B.y) {
//             //     return 1;
//             // }
//             if (is_parralle_near(first, second, first_equation, second_equation) == 1) {
//                 printf("==========> Same coefficient directeur : %f == %f\n", first_equation.b, second_equation.b);
//                 printf("First = {(%f, %f), (%f, %f)}\nSecond = {(%f, %f), (%f, %f)}\n", first.A.x, first.A.y, first.B.x, first.B.y, second.A.x, second.A.y, second.B.x, second.B.y);
//                 return 1;
//             }
//             return 1;
//         }
//         return 0;
//     }
//     point = find_intersecting_point(first_equation, second_equation);
//     if (find_point_on_line(point, second, second_equation) == 1 && find_point_on_line(point, first, first_equation) == 1) {
//         printf("==========> On line\n");
//         return 1;
//     }
//     return 0;
// }
