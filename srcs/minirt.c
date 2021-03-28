
#include "minirt.h"

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		printf("fechando... :)\n");
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
	return (0);
}

int	main(/* int argc, char **argv */)
{
	t_vars      vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, LARGURA, ALTURA, "minirt");
	draw(vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
