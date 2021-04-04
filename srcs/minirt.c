
#include "minirt.h"

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		printf("minirt.c(key_hook): 8: fechando... :)\n");
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
	return (0);
}

t_vars	config_scene_easy(void)
{
	t_vars		vars;
	t_objeto	*obj;

	vars.largura = 800;
	vars.altura = 600;
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = -2.0;
	obj->sp.pos.y = 0.0;
	obj->sp.pos.z = 5.0;
	obj->sp.raio = 2.0;
	obj->sp.cor = 0x1de0d6;
	vars.objs = list_init(obj);
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = 2.0;
	obj->sp.pos.y = 0.0;
	obj->sp.pos.z = 5.0;
	obj->sp.raio = 2.0;
	obj->sp.cor = 0x711de0;
	list_add(vars.objs, obj);
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = 0.0;
	obj->sp.pos.y = 1.0;
	obj->sp.pos.z = 2.0;
	obj->sp.raio = 0.5;
	obj->sp.cor = 0xe0d61d;
	list_add(vars.objs, obj);
	vars.light.bright = 1.0;
	vars.light.pos.x = 1.0;
	vars.light.pos.y = 2.0;
	vars.light.pos.z = -2.0;
	vars.light.cor = 0xFFFFFF;
	vars.cam.pos.x = 0.0;
	vars.cam.pos.y = 0.0;
	vars.cam.pos.z = 0.0;
	vars.cam.fov = 90.0;
	return (vars);
}

t_vars	config_scene(void)
{
	t_vars		vars;
	t_objeto	*obj;

	vars.largura = 320;
	vars.altura = 180;
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = -2.0;
	obj->sp.pos.y = -2.0;
	obj->sp.pos.z = 11.5;
	obj->sp.raio = 3.0;
	obj->sp.cor = 0xFF0000;
	vars.objs = list_init(obj);
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = -4.0;
	obj->sp.pos.y = -2.0;
	obj->sp.pos.z = 12.0;
	obj->sp.raio = 3.0;
	obj->sp.cor = 0x0000FF;
	list_add(vars.objs, obj);
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = -5.0;
	obj->sp.pos.y = -2.0;
	obj->sp.pos.z = 11.5;
	obj->sp.raio = 2.5;
	obj->sp.cor = 0x00FF00;
	list_add(vars.objs, obj);
	vars.cam.pos.x = -3.0;
	vars.cam.pos.y = -2.0;
	vars.cam.pos.z = 4.0;
	vars.cam.fov = 90.0;
	vars.light.bright = 1.0;
	vars.light.pos.x = 0.0;
	vars.light.pos.y = 2.0;
	vars.light.pos.z = 4.0;
	vars.light.cor = 0xFFFFFF;
	return (vars);
}

int		main(void)
{
	t_vars	vars;

	vars = config_scene_easy();
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
