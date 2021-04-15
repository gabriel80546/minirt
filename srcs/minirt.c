
#include "minirt.h"

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
	cam->pos.z = -3.0;
	cam->direc.x = 0.0;
	cam->direc.y = 0.0;
	cam->direc.z = 3.0;
	cam->fov = 90.0;
	saida.cams = list_init(cam);
	// list_add(saida.cams, cam);
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
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
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
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
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
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->fov = 90.0;
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

	// PLANOS

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = PLANE;
	obj->pl.pos.x =  0.0;
	obj->pl.pos.y = -1.0;
	obj->pl.pos.z =  0.0;
	obj->pl.direc.x = 0.0;
	obj->pl.direc.y = 1.0;
	obj->pl.direc.z = 0.0;
	obj->pl.cor = 0x40D0D0;
	vars.objs = list_init(obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = PLANE;
	obj->pl.pos.x =  5.0;
	obj->pl.pos.y =  0.0;
	obj->pl.pos.z =  0.0;
	obj->pl.direc.x = 1.0;
	obj->pl.direc.y = 0.0;
	obj->pl.direc.z = 0.0;
	obj->pl.cor = 0xD0D040;
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);

	// list_add(vars.objs, obj);
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = PLANE;
	obj->pl.pos.x =  0.0;
	obj->pl.pos.y =  0.0;
	obj->pl.pos.z =  5.0;
	obj->pl.direc.x = 0.0;
	obj->pl.direc.y = 0.0;
	obj->pl.direc.z = -1.0;
	obj->pl.cor = 0xD040D0;
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = PLANE;
	obj->pl.pos.x =  -5.0;
	obj->pl.pos.y =   0.0;
	obj->pl.pos.z =   0.0;
	obj->pl.direc.x = 1.0;
	obj->pl.direc.y = 0.0;
	obj->pl.direc.z = 0.0;
	obj->pl.cor = 0x20FF40;
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = PLANE;
	obj->pl.pos.x =   0.0;
	obj->pl.pos.y =   0.0;
	obj->pl.pos.z =  -5.0;
	obj->pl.direc.x = 0.0;
	obj->pl.direc.y = 0.0;
	obj->pl.direc.z = 1.0;
	obj->pl.cor = 0x8040FF;
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);

	// ESFERAS

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = 0.0;
	obj->sp.pos.y = 0.0;
	obj->sp.pos.z = 0.0;
	obj->sp.diametro = 0.5;
	obj->sp.cor = 0x606060;
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =  1.0;
	obj->sp.pos.y = -0.25;
	obj->sp.pos.z =  1.0;
	obj->sp.diametro = 1.0;
	obj->sp.cor = 0xFF8080;
	list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = -1.0;
	obj->sp.pos.y = -0.25;
	obj->sp.pos.z =  1.0;
	obj->sp.diametro = 1.0;
	obj->sp.cor = 0x80FF80;
	list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =  1.0;
	obj->sp.pos.y = -0.25;
	obj->sp.pos.z = -1.0;
	obj->sp.diametro = 1.0;
	obj->sp.cor = 0x8080FF;
	list_add(vars.objs, obj);

	temp_direc.x = -1.0;
	temp_direc.y =  1.25;
	temp_direc.z = -3.0;
	// obj = (t_objeto *)malloc(sizeof(t_objeto));
	// obj->tipo = SPHERE;
	// obj->sp.pos.x = temp_direc.x - 1.2;
	// obj->sp.pos.y = temp_direc.y;
	// obj->sp.pos.z = temp_direc.z;
	// obj->sp.diametro = 1.0;
	// obj->sp.cor = 0x8080FF;
	// list_add(vars.objs, obj);

	// LUZES

	vars.lights = NULL;
	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 0.8;
	light->pos.x = temp_direc.x;
	light->pos.y = temp_direc.y;
	light->pos.z = temp_direc.z;
	light->cor = 0xFFFFFF;
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
		printf("%s(%s:%d): fechando... :)\n", __FILE__, __func__, __LINE__);
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
		// clear_screen(*vars);
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
