compile="gcc minirt.c -I ../assets/minilibx-linux/ -L ../assets/minilibx-linux/ -lmlx -lXext -lX11 -o minirt"
echo $compile
$compile
