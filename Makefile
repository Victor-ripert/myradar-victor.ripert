##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make units tests
##

SRC =	main.c	\
	my_radar.c	\
	display.c	\
	sprites/tower/create_circle.c	\
	is_intersecting_circle.c	\
	parsing/config_parsing.c	\
	parsing/add_plane.c	\
	parsing/str_to_nbr.c	\
	parsing/add_tower.c	\
	parsing/norm_vector.c	\
	parsing/plane_angle.c	\
	parsing/find_top_left.c	\
	word_array/my_str_to_word_array.c	\
	word_array/my_strlen.c	\
	word_array/my_word_len.c	\
	linked_list/plane/delete_in_list_plane.c	\
	linked_list/plane/display_list_plane.c	\
	linked_list/plane/display_node_plane.c	\
	linked_list/plane/push_to_list_plane.c	\
	linked_list/plane/replace_ptr_plane.c	\
	linked_list/tower/delete_in_list_tower.c	\
	linked_list/tower/display_list_tower.c	\
	linked_list/tower/display_node_tower.c	\
	linked_list/tower/push_to_list_tower.c	\
	linked_list/tower/replace_ptr_tower.c	\
	sprites/movement/movement.c	\
	sprites/movement/pause.c	\
	sprites/movement/enable_plane.c	\
	sprites/plane_disp_param.c	\
	sprites/collision/collision_plane_list.c	\
	sprites/collision/find_4_faces.c	\
	sprites/collision/collision_2_cube.c	\
	sprites/collision/collision_2_faces.c

NAME	=	my_radar

OBJ	=	$(SRC:.c=.o)

CFLAGS += -g3 -iquote ./include

SFML = -l csfml-window -l csfml-graphics -l csfml-system

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFML) -I./include -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)


re:	fclean  all

radar :
	python3 generator.py -p 10 -t 4 -d 20 -f -r 30 -S -o map/10_planes_3_towers.rdr