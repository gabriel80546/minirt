#compile="gcc -g3 -fsanitize=address minirt.c ../libs/gnl/get_next_line.c ../libs/gnl/get_next_line_utils.c ../libs/gnl/get_next_line.h -I ../assets/minilibx-linux/ -L ../assets/minilibx-linux/ -lmlx -lXext -lX11 -o minirt"
compile="gcc -g minirt.c \
../libs/gnl/get_next_line.c ../libs/gnl/get_next_line_utils.c ../libs/gnl/get_next_line.h \
 -I ../assets/minilibx-linux/ -L ../assets/minilibx-linux/ -lmlx -lXext -lX11 -o minirt"
echo $compile
$compile
