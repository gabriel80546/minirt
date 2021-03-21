compile="gcc main.c -I ../assets/minilibx-linux/ -L ../assets/minilibx-linux/ -lmlx -lXext -lX11 -o main"
echo $compile
$compile
