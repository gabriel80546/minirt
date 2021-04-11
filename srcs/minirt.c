
#include "minirt.h"

// double	direction_to_inc(t_vec direc)
// {
// }

// t_vec	spherical_to_vec(double radius, double inclination, double azimuth)
// {
// 	t_vec saida;

// 	saida.x = radius * cos(azimuth) * sin(inclination);
// 	saida.y = radius * cos(inclination);
// 	saida.z = radius * sin(azimuth) * sin(inclination);
// 	return (saida);
// }

// t_vec	spherical_to_vec_rt(double radius, double inclination, double azimuth)
// {
// 	return spherical_to_vec(radius, inclination - (PI / 2), -azimuth - (PI / 2));
// }


// double	vec_to_spherical_inc(t_vec direc)
// {
// 	double a;
// 	double b;
// 	double c;
// 	// double d;
// 	double e;
// 	// double f;

// 	a = direc.z;
// 	b = direc.x;
// 	c = sqrt((a * a) + (b * b));
// 	// d = atan2(c, direc.y);
// 	e = atan2(direc.y, c);
// 	// printf("a = % lf; b = % lf; c = % lf; d = % lf; e = % lf; f = % lf; (2 * PI) - e = % lf\n", a, b, c, d, e, f, (2 * PI) + e);
// 	// return (acos(direc.y / distance(empty_vec(), direc)));
// 	return (e);
// }

// double	vec_to_spherical_azi(t_vec direc)
// {
// 	return (atan2(direc.x, direc.z));
// }

t_vars	config_cams(t_vars input)
{
	t_vars	saida;
	t_cam	*cam;
	int		i;
	// int		k;
	// double	speed;

	i = -5;
	// k = i;
	// speed = 1.0;
	saida = input;
	// cam = (t_cam *)malloc(sizeof(t_cam));
	// cam->pos.x = 0.0;
	// cam->pos.y = 0.0;
	// cam->pos.z = 0.0;
	// cam->rot.x = 0.0;
	// cam->rot.y = 0.0;
	// cam->rot.z = 0.0;
	// cam->p = 0;
	// cam->fov = 90.0;
	// saida.cams = list_init(cam);
	// while (i < -k)
	// {
	// 	cam = (t_cam *)malloc(sizeof(t_cam));
	// 	cam->pos.x = 0.0;
	// 	cam->pos.y = 0.0 + (i * speed);
	// 	cam->pos.z = -3.0;
	// 	cam->rot.x = 0.0;
	// 	cam->rot.y = 0.0;
	// 	cam->rot.z = 0.0;
	// 	cam->fov = 90.0;
	// 	list_add(saida.cams, cam);
	// 	i++;
	// }
	// i = k;
	// while (i < -k)
	// {
	// 	cam = (t_cam *)malloc(sizeof(t_cam));
	// 	cam->pos.x = 0.0 + (i * speed);
	// 	cam->pos.y = 0.0;
	// 	cam->pos.z = -3.0;
	// 	cam->rot.x = 0.0;
	// 	cam->rot.y = 0.0;
	// 	cam->rot.z = 0.0;
	// 	cam->fov = 90.0;
	// 	list_add(saida.cams, cam);
	// 	i++;
	// }
	// i = k;
	// while (i < -k)
	// {
	// 	cam = (t_cam *)malloc(sizeof(t_cam));
	// 	cam->pos.x = 0.0;
	// 	cam->pos.y = 0.0;
	// 	cam->pos.z = -3.0 + (i * speed);
	// 	cam->rot.x = 0.0;
	// 	cam->rot.y = 0.0;
	// 	cam->rot.z = 0.0;
	// 	cam->fov = 90.0;
	// 	list_add(saida.cams, cam);
	// 	i++;
	// }

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->pos.x =  0.0;
	cam->pos.y =  0.0;
	cam->pos.z = -3.0;
	cam->rot.x = 0.0;
	cam->rot.y = 0.0;
	cam->rot.z = 0.0;
	cam->direc.x = 0.0;
	cam->direc.y = 0.0;
	cam->direc.z = 3.0;
	cam->p = 0;
	cam->fov = 90.0;
	// list_add(saida.cams, cam);
	saida.cams = list_init(cam);


	i = 0;
	while (i < 32)
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0;
		cam->pos.y = 0.0;
		cam->pos.z = -3.0;
		cam->pos = rotacao_y(cam->pos, i * (PI / 16));
		// cam->rot.x = 0.0;
		// cam->rot.y = i * (PI / 16);
		// cam->rot.z = 0.0;
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->p = 0;
		cam->fov = 90.0;
		list_add(saida.cams, cam);
		i++;
	}


	i = 0;
	while (i < 32)
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0;
		cam->pos.y = 0.0;
		cam->pos.z = -3.0;
		cam->pos = rotacao_x(cam->pos, i * (PI / 16));
		cam->rot.x = i * (PI / 16);
		cam->rot.y = 0.0;
		cam->rot.z = 0.0;
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->p = 0;
		cam->fov = 90.0;
		list_add(saida.cams, cam);
		i++;
	}


	i = 0;
	while (i < 6)
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0;
		cam->pos.y = 0.0;
		cam->pos.z = -3.0;
		cam->pos = rotacao_x(cam->pos, i * (PI / 16));
		cam->pos = rotacao_y(cam->pos, i * (PI / 16));
		// cam->rot.x = i * (PI / 16);
		// cam->rot.y = i * (PI / 16);
		// cam->rot.z = 0.0;
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->p = 0;
		cam->fov = 90.0;
		list_add(saida.cams, cam);
		i++;
	}

	i = 5;
	while (i < (32 - 5))
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0;
		cam->pos.y = 0.0;
		cam->pos.z = -3.0;
		cam->pos = rotacao_x(cam->pos, 5 * (PI / 16));
		cam->pos = rotacao_y(cam->pos, i * (PI / 16));
		// cam->rot.x = 5 * (PI / 16);
		// cam->rot.y = i * (PI / 16);
		// cam->rot.z = 0.0;
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->p = 0;
		cam->fov = 90.0;
		list_add(saida.cams, cam);
		i++;
	}

	i = 27;
	while (i < 32)
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0;
		cam->pos.y = 0.0;
		cam->pos.z = -3.0;
		cam->pos = rotacao_x(cam->pos, (32 - i) * (PI / 16));
		cam->pos = rotacao_y(cam->pos, i * (PI / 16));
		// cam->rot.x = (32 - i) * (PI / 16);
		// cam->rot.y = i * (PI / 16);
		// cam->rot.z = 0.0;
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->p = 0;
		cam->fov = 90.0;
		list_add(saida.cams, cam);
		i++;
	}


	return (saida);
}

t_vars	config_scene_easy(t_vars input)
{
	t_vars		vars;
	t_objeto	*obj;
	t_light		*light;
	// t_vec		direc;
	// double		inc;
	// double		azi;
	int			i;

	vars = input;
	vars.largura = 600;
	vars.altura = 400;
	vars.gray = 0;
	vars.ambient = 0x333333;
	vars.objs = NULL;

	// ESFERAS

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = 0.0;
	obj->sp.pos.y = 0.0;
	obj->sp.pos.z = 0.0;
	obj->sp.raio = 0.25;
	obj->sp.cor = 0x606060;
	vars.objs = list_init(obj);


	// obj = (t_objeto *)malloc(sizeof(t_objeto));
	// obj->tipo = SPHERE;
	// obj->sp.pos.x = 0.0;
	// obj->sp.pos.y = 0.0;
	// obj->sp.pos.z = 1.0;
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFFFFFF;
	// list_add(vars.objs, obj);

	// // normal.x = 1.0;
	// // normal.y = 1.0;
	// // normal.z = 0.0;
	// obj = (t_objeto *)malloc(sizeof(t_objeto));
	// obj->tipo = SPHERE;
	// obj->sp.pos.x = 0.0;
	// obj->sp.pos.y = 0.0;
	// obj->sp.pos.z = 1.0;
	// // obj->sp.pos = rotacao_x(obj->sp.pos, (2 * PI) - (PI / 4));
	// obj->sp.pos = rotacao_y(obj->sp.pos, (PI / 4));
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFF8080;
	// list_add(vars.objs, obj);

	// // normal.x = 1.0;
	// // normal.y = 1.0;
	// // normal.z = 0.0;
	// obj = (t_objeto *)malloc(sizeof(t_objeto));
	// obj->tipo = SPHERE;
	// obj->sp.pos.x = 0.0;
	// obj->sp.pos.y = 0.0;
	// obj->sp.pos.z = 1.0;
	// // obj->sp.pos = rotacao_x(obj->sp.pos, (2 * PI) - (PI / 2));
	// obj->sp.pos = rotacao_y(obj->sp.pos, (PI / 2));
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0x80FF80;
	// list_add(vars.objs, obj);

	// // normal.x = 1.0;
	// // normal.y = 1.0;
	// // normal.z = 0.0;
	// obj = (t_objeto *)malloc(sizeof(t_objeto));
	// obj->tipo = SPHERE;
	// obj->sp.pos.x = 0.0;
	// obj->sp.pos.y = 0.0;
	// obj->sp.pos.z = 1.0;
	// // obj->sp.pos = rotacao_x(obj->sp.pos, (2 * PI) - ((3 * PI) / 4));
	// obj->sp.pos = rotacao_y(obj->sp.pos, ((3 * PI) / 4));
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0x8080FF;
	// list_add(vars.objs, obj);

	// testing spherical_to_vec

	i = 0;
	while (i < 8)
	{
		obj = (t_objeto *)malloc(sizeof(t_objeto));
		obj->tipo = SPHERE;
		obj->sp.pos = spherical_to_vec_rt(1.0, i * (PI / 8), 0.0);
		obj->sp.raio = 0.375;
		obj->sp.cor = 0xFFFF80;
		list_add(vars.objs, obj);
		i++;
	}


	i = 0;
	while (i < 8)
	{
		obj = (t_objeto *)malloc(sizeof(t_objeto));
		obj->tipo = SPHERE;
		obj->sp.pos = spherical_to_vec_rt(1.0, 0.0, i * (PI / 8));
		obj->sp.raio = 0.375;
		obj->sp.cor = 0xFF80FF;
		list_add(vars.objs, obj);
		i++;
	}

	// LUZES

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

	// vars.cam.pos.x = 0.0;
	// vars.cam.pos.y = 0.0;
	// vars.cam.pos.z = 0.0;
	// vars.cam.fov = 90.0;

	return (vars);
}

void	clean_all(t_vars vars)
{
	if (vars.objs != NULL)
		clear_list_all(vars.objs);
	if (vars.lights != NULL)
		clear_list_all(vars.lights);
}

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		printf("minirt.c(key_hook): 8: fechando... :)\n");
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		clear_list_all(vars->cams);
		exit(1);
	}
	else if (keycode == 32)
	{
		if (vars->cams != NULL)
		{
			if (vars->cams->next != NULL)
				vars->cams = vars->cams->next;
			else
				vars->cams = first_item(vars->cams);
			vars->cam = *((t_cam *)vars->cams->data);
		}
		*vars = config_scene_easy(*vars);
		clear_screen(*vars);
		draw(*vars);
		clean_all(*vars);
	}
	return (0);
}

t_cam	empty_cam(void)
{
	t_cam	saida;

	saida.pos.x = 0.0;
	saida.pos.y = 0.0;
	saida.pos.z = 0.0;
	saida.fov = 90.0;
	return (saida);
}


int		main(void)
{
	t_vars	vars;

	vars.cams = NULL;
	vars = config_cams(vars);
	if (vars.cams != NULL)
		vars.cam = *((t_cam *)vars.cams->data);
	else
		vars.cam = empty_cam();
	vars = config_scene_easy(vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.largura, vars.altura, "minirt");
	draw(vars);
	clean_all(vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
