
#include "minirt.h"

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		printf("key_hook: 8: fechando... :)\n");
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
	return (0);
}

t_vars config_scene(void)
{
	t_vars vars;
	t_objeto *obj;

	vars.largura = 640;
	vars.altura = 400;


	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = -30.0;
	obj->sp.pos.y =  30.0;
	obj->sp.pos.z =  80.0;
	obj->sp.raio  = 150.0;
	obj->sp.cor   = 0xFF0000;
	vars.objs = list_init(obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =  30.0;
	obj->sp.pos.y = -30.0;
	obj->sp.pos.z =  80.0;
	obj->sp.raio  = 150.0;
	obj->sp.cor   = 0x0000FF;
	list_add(vars.objs, obj);

	vars.cam.x = 0.0;
	vars.cam.y = 0.0;
	vars.cam.z = (double)(-(vars.largura / 2));
	return (vars);
}

int	main(/* int argc, char **argv */)
{
	t_vars      vars;

	vars = config_scene();

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.largura, vars.altura, "minirt");
	if (0)
		draw_indiano();
	else if (0)
		draw_yellow_sp(vars);
	else
		draw(vars);
	clear_list_all(vars.objs);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
