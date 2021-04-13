
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
	t_vec		direc;

	vars = input;
	vars.largura = 400;
	vars.altura = 300;
	vars.gray = 0;
	vars.ambient = 0x333333;
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
	obj->pl.cor = 0xFF0000;
	vars.objs = list_init(obj);

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
	obj->sp.pos.y =  1.0;
	obj->sp.pos.z =  1.0;
	obj->sp.diametro = 1.0;
	obj->sp.cor = 0xFF8080;
	list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = -1.0;
	obj->sp.pos.y =  1.0;
	obj->sp.pos.z =  1.0;
	obj->sp.diametro = 1.0;
	obj->sp.cor = 0x80FF80;
	list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =  1.0;
	obj->sp.pos.y =  1.0;
	obj->sp.pos.z = -1.0;
	obj->sp.diametro = 1.0;
	obj->sp.cor = 0x8080FF;
	list_add(vars.objs, obj);

	direc.x =  1.0;
	direc.y =  1.2;
	direc.z =  1.0;

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos = direc;
	obj->sp.diametro = 1.0;
	obj->sp.cor = 0xFF80FF;
	list_add(vars.objs, obj);





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
