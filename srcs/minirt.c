
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
	t_light		*light;

	vars.largura = 400;
	vars.altura = 300;
	vars.ambient = 0x333333;
	vars.objs = NULL;
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
	obj->sp.raio = 0.75;
	obj->sp.cor = 0xe0d61d;
	list_add(vars.objs, obj);

	vars.lights = NULL;
	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 0.3;
	light->pos.x = 1.0;
	light->pos.y = 2.0;
	light->pos.z = -2.0;
	light->cor = 0xFFFFFF;
	vars.lights = list_init(light);

	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 0.3;
	light->pos.x = -1.0;
	light->pos.y = 2.0;
	light->pos.z = -2.0;
	light->cor = 0xFFFFFF;
	// vars.lights = list_init(light);
	list_add(vars.lights, light);

	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 0.3;
	light->pos.x = -3.0;
	light->pos.y = 5.0;
	light->pos.z = -2.0;
	light->cor = 0xFFFFFF;
	// vars.lights = list_init(light);
	list_add(vars.lights, light);

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
	t_light		*light;

	vars.largura = 320;
	vars.altura = 180;
	vars.objs = NULL;
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

	vars.lights = NULL;
	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 1.0;
	light->pos.x = 0.0;
	light->pos.y = 2.0;
	light->pos.z = 4.0;
	light->cor = 0xFFFFFF;
	vars.lights = list_init(light);

	return (vars);
}

void	clean_all(t_vars vars)
{
	if (vars.objs != NULL)
		clear_list_all(vars.objs);
	if (vars.lights != NULL)
		clear_list_all(vars.lights);
}

void	draw_circulo(t_vars vars)
{
	double	centro_x = 50;
	double	centro_y = 50;
	double	raio = 30;
	double	x;
	double	y;

	y = 0.0;
	while (y < vars.altura)
	{
		x = 0.0;
		while (x < vars.largura)
		{
			// draw_main(vars, x, y);
			if (sqrt(((centro_x - x) * (centro_x - x)) + ((centro_y - y) * (centro_y - y))) > raio)
				mlx_pixel_put(vars.mlx, vars.win, x, y, 0x000000);
			else
				mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFF0000);
			// if (x > 10 && y > 10)
			x += 1.0;
		}
		y += 1.0;
	}
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
		draw_circulo(vars);
	else if (0)
		draw_yellow_sp(vars);
	else
		draw(vars);
	clean_all(vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
