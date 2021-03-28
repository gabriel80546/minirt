
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

	vars.largura = 640;
	vars.altura = 400;
	vars.sp.pos.x = -30.0;
	vars.sp.pos.y = +30.0;
	vars.sp.pos.z =  80.0;
	vars.sp.raio  = 150.0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.largura, vars.altura, "minirt");
	if (0)
		draw_indiano();
	else if(0)
		draw_yellow_sp(vars);
	else
		draw(vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
