gcc -O3 -Wall -Wextra -g *.c
 ../headers/math/*.c
 ../headers/list/*.c
 objs/*.c
 -I .
 -I ../assets/minilibx-linux
 -I ../headers/list
 -I ../headers/math
 -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11 -o miniRT
