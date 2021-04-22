
#include "minirt.h"
#include <stdarg.h>

int		say(const char *format, char *file, const char *func, int line, ...)
{
	va_list		args;
	int			saida;
	static int	counter = 0;

	printf("%05d:%s(%s:%d): ", counter, file, func, line);
	va_start(args, line);
	saida = vprintf(format, args);
	va_end(args);
	counter++;
	return (saida);
}


t_vars	config_cams(t_vars input)
{
	t_vars	saida;
	t_cam	*cam;
	int		i;

	i = -5;
	saida = input;

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->pos.x =  0.0;
	cam->pos.y =  0.0;
	cam->pos.z =  5.0;
	cam->direc.x = 0.0;
	cam->direc.y = 0.0;
	cam->direc.z = 3.0;
	cam->fov = 60.0;
	cam->transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));
	saida.cams = list_init(cam);
	// list_add(saida.cams, cam);

	// i = 0;
	// while (i < 60)
	// {
	// 	cam = (t_cam *)malloc(sizeof(t_cam));
	// 	cam->pos.x = 0.0;
	// 	cam->pos.y = 0.0;
	// 	cam->pos.z = 5.0 - (double)(i * 0.25);
	// 	cam->direc.x = -cam->pos.x;
	// 	cam->direc.y = -cam->pos.y;
	// 	cam->direc.z = -cam->pos.z;
	// 	cam->fov = 60.0;
	// 	// cam->transform = mat44_mul(mat44_scaling(-1, 1, 1), mat44_translate(cam->pos.x, cam->pos.y, cam->pos.z));
	// 	cam->transform = view_transform(point(0, 1.5, -5 + (double)(i * 0.25)), point(0, 1, 0), vector(0, 1, 0));
	// 	list_add(saida.cams, cam);
	// 	i++;
	// }
	i = 0;
	while (i < 32)
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0;
		cam->pos.y = 0.0;
		cam->pos.z = -3.0;
		cam->pos = rotacao_y(cam->pos, i * (PI / 16));
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->fov = 60.0;
		cam->transform = view_transform(mat44_tuple_mul(mat44_rotate_y(i * (PI / 16)), point(0, 1.5, -5)), point(0, 1, 0), vector(0, 1, 0));
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
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->fov = 60.0;
		cam->transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));
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
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->fov = 60.0;
		cam->transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));
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
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->fov = 60.0;
		cam->transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));
		list_add(saida.cams, cam);
		i++;
	}


	// i = 0;
	// while (i < 32)
	// {
	// 	cam = (t_cam *)malloc(sizeof(t_cam));
	// 	cam->pos.x = 0.0;
	// 	cam->pos.y = 0.0;
	// 	cam->pos.z = -3.0;
	// 	cam->pos = rotacao_x(cam->pos, i * (PI / 16));
	// 	cam->direc.x = -cam->pos.x;
	// 	cam->direc.y = -cam->pos.y;
	// 	cam->direc.z = -cam->pos.z;
	// 	cam->fov = 90.0;
	// 	list_add(saida.cams, cam);
	// 	i++;
	// }

	return (saida);
}

t_vars	config_scene_easy(t_vars input)
{
	t_vars		vars;
	t_objeto	*obj;
	t_light		*light;
	t_vec		temp_direc;
	// int			i;

	vars = input;
	vars.largura = 400;
	vars.altura = 300;
	vars.gray = 0;
	vars.ambient = 0x404040;
	vars.objs = NULL;
	obj = NULL;



/* 
	The default world
	Given light ← point_light(point(-10, 10, -10), color(1, 1, 1))
	And s1 ← sphere() with:
	| material.color     | (0.8, 1.0, 0.6)        |
	| material.diffuse   | 0.7                    |
	| material.specular  | 0.2                    |
	And s2 ← sphere() with:
	| transform | scaling(0.5, 0.5, 0.5) |
	When w ← default_world()
	Then w.light = light
	And w contains s1
	And w contains s2
 */

	// ESFERAS


	// UMA ESFERA VERMELHA NO (0, 0, 0)
	// obj = (t_objeto *)malloc(sizeof(t_objeto));
	// obj->tipo = SPHERE;
	// obj->sp.pos = point(0.0, 0.0, 0.0);
	// obj->sp.diametro = 157.0;
	// obj->sp.material.color = color(1.0, 0.0, 0.0);
	// obj->sp.material.ambient = 0.1;
	// obj->sp.material.diffuse = 0.7;
	// obj->sp.material.specular = 0.2;
	// obj->sp.material.shininess = 200.0;
	// obj->sp.transform = mat44_identity();
	// vars.objs = list_init(obj);
	// // list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos = point(0.0, 0.0, 0.0);
	obj->sp.diametro = 157.0;
	obj->sp.material.color = color(1.0, 0.9, 0.9);
	// obj->sp.material.color = color(1.0, 1.0, 1.0);
	// obj->sp.material.ambient = 0.1;
	// obj->sp.material.diffuse = 0.7;
	// obj->sp.material.specular = 0.2;
	// obj->sp.material.shininess = 200.0;
	obj->sp.material.ambient = 0.1;
	obj->sp.material.diffuse = 0.7;
	obj->sp.material.specular = 0.0;
	obj->sp.material.shininess = 200.0;
	obj->sp.transform = mat44_scaling(10, 0.01, 10);
	vars.objs = list_init(obj);
	// list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos = point(0.0, 0.0, 0.0);
	obj->sp.diametro = 157.0;
	obj->sp.material.color = color(1.0, 0.9, 0.9);
	obj->sp.material.ambient = 0.1;
	obj->sp.material.diffuse = 0.7;
	obj->sp.material.specular = 0.0;
	obj->sp.material.shininess = 200.0;
	obj->sp.transform = mat44_mul(
								mat44_translate(0, 0, 5),
									mat44_mul(
										mat44_rotate_y(-PI / 4),
										mat44_mul(
											mat44_rotate_x(PI / 2),
											mat44_scaling(10, 0.01, 10))));
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);


	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos = point(0.0, 0.0, 0.0);
	obj->sp.diametro = 157.0;
	obj->sp.material.color = color(1.0, 0.9, 0.9);
	obj->sp.material.ambient = 0.1;
	obj->sp.material.diffuse = 0.7;
	obj->sp.material.specular = 0.0;
	obj->sp.material.shininess = 200.0;
	obj->sp.transform = mat44_mul(
								mat44_translate(0, 0, 5),
									mat44_mul(
										mat44_rotate_y(PI / 4),
										mat44_mul(
											mat44_rotate_x(PI / 2),
											mat44_scaling(10, 0.01, 10))));
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);


	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos = point(0.0, 0.0, 0.0);
	obj->sp.diametro = 157.0;
	obj->sp.material.color = color(0.1, 1, 0.5);
	obj->sp.material.ambient = 0.1;
	obj->sp.material.diffuse = 0.7;
	obj->sp.material.specular = 0.3;
	obj->sp.material.shininess = 200.0;
	obj->sp.transform = mat44_translate(-0.5, 1, 0.5);
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);


	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos = point(0.0, 0.0, 0.0);
	obj->sp.diametro = 157.0;
	obj->sp.material.color = color(0.5, 1, 0.1);
	obj->sp.material.ambient = 0.1;
	obj->sp.material.diffuse = 0.7;
	obj->sp.material.specular = 0.3;
	obj->sp.material.shininess = 200.0;
	obj->sp.transform = mat44_mul(mat44_translate(1.5, 0.5, -0.5), 
							mat44_scaling(0.5, 0.5, 0.5));
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);



	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos = point(0.0, 0.0, 0.0);
	obj->sp.diametro = 157.0;
	obj->sp.material.color = color(1.0, 0.8, 0.1);
	obj->sp.material.ambient = 0.1;
	obj->sp.material.diffuse = 0.7;
	obj->sp.material.specular = 0.3;
	obj->sp.material.shininess = 200.0;
	obj->sp.transform = mat44_mul(mat44_translate(-1.5, 0.33, -0.75), 
							mat44_scaling(0.33, 0.33, 0.33));
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);



	// LUZES

	temp_direc.x = -10.0;
	temp_direc.y =  6.0;
	temp_direc.z = -10.0;
	// temp_direc.x =  0.0;
	// temp_direc.y =  0.25;
	// temp_direc.z =  0.0;

	vars.lights = NULL;
	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 0.8;
	light->position = point(temp_direc.x, temp_direc.y, temp_direc.z);
	light->cor =  color(1.0, 1.0, 1.0);
	vars.lights = list_init(light);

	// light = (t_light *)malloc(sizeof(t_light));
	// light->bright = 0.3;
	// light->pos.x = 0.0;
	// light->pos.y = 3.0;
	// light->pos.z = 3.0;
	// light->cor = 0xFFFFFF;
	// // vars.lights = list_init(light);
	// list_add(vars.lights, light);

	// light = (t_light *)malloc(sizeof(t_light));
	// light->bright = 0.5;
	// light->pos.x = 3.0;
	// light->pos.y = 4.0;
	// light->pos.z = 0.0;
	// light->cor = 0xFFFFFF;
	// // vars.lights = list_init(light);
	// list_add(vars.lights, light);
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
		say("fechando... :)\n", DEB);
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
	vars.win = mlx_new_window(vars.mlx, vars.largura, vars.altura, "miniRT");
	draw(vars);
	clean_all(vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
