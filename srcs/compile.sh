compile="gcc -g3 -fsanitize=address minirt.c -I ../assets/minilibx-linux/ -L ../assets/minilibx-linux/ -lmlx -lXext -lX11 -o minirt"
#compile="gcc -g minirt.c -I ../assets/minilibx-linux/ -L ../assets/minilibx-linux/ -lmlx -lXext -lX11 -o minirt"
echo $compile
$compile
