#!/bin/bash
#compile="gcc -g3 -fsanitize=address minirt.c ../libs/gnl/get_next_line.c ../libs/gnl/get_next_line_utils.c ../libs/gnl/get_next_line.h -I ../assets/minilibx-linux/ -L ../assets/minilibx-linux/ -lmlx -lXext -lX11 -o minirt"
# compile="gcc -Wall -Wextra -g minirt.c \
# ../libs/gnl/get_next_line.c ../headers/math/*.c ../headers/list/*.c ../libs/gnl/get_next_line_utils.c ../libs/gnl/get_next_line.h \
#  -I ../assets/minilibx-linux/ -I ../headers/list -I ../headers/math/  -L ../assets/minilibx-linux/ -lm -lmlx -lXext -lX11 -o minirt"

compile=`cat warp_compile.sh | echo $(</dev/stdin)`
echo $compile
$compile