clang -O3 -Wall -Wextra -Weverything -g -c *.c
 ../headers/math/*.c
 ../headers/list/*.c
 objs/*.c
 -I .
 -I ../assets/minilibx-linux
 -I ../headers/list
 -I ../headers/math
 -L ../assets/minilibx-linux -lm -lmlx -lXext -lX11
