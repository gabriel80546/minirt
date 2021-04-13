gcc -Wall -Wextra -g *.c 
 ../libs/gnl/get_next_line.c
 ../headers/math/*.c
 ../headers/list/*.c
 ../libs/gnl/get_next_line_utils.c
 ../libs/gnl/get_next_line.h
 objs/*.c
 -I .
 -I ../assets/minilibx-linux
 -I ../headers/list
 -I ../headers/math
 -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11 -o miniRT
