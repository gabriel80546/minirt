
#include "minirt.h"

t_vars	config_cams(t_vars input)
{
	t_vars	saida;
	t_cam	*cam;
	int		i;
	int		k;
	double	speed;

	i = -5;
	k = i;
	speed = 1.0;
	saida = input;
	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->pos.x = 0.0;
	cam->pos.y = 0.0;
	cam->pos.z = 0.0;
	cam->fov = 90.0;
	saida.cams = list_init(cam);
	while (i < -k)
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0;
		cam->pos.y = 0.0 + (i * speed);
		cam->pos.z = -3.0;
		cam->fov = 90.0;
		list_add(saida.cams, cam);
		i++;
	}
	i = k;
	while (i < -k)
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0 + (i * speed);
		cam->pos.y = 0.0;
		cam->pos.z = -3.0;
		cam->fov = 90.0;
		list_add(saida.cams, cam);
		i++;
	}
	i = k;
	while (i < -k)
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0;
		cam->pos.y = 0.0;
		cam->pos.z = -3.0 + (i * speed);
		cam->fov = 90.0;
		list_add(saida.cams, cam);
		i++;
	}
	return (saida);
}

void	matrix_print(t_mat3by3 mat)
{
	printf("|%lf, %lf, %lf|\n", mat.a[0], mat.a[1], mat.a[2]);
	printf("|%lf, %lf, %lf|\n", mat.b[0], mat.b[1], mat.b[2]);
	printf("|%lf, %lf, %lf|\n", mat.c[0], mat.c[1], mat.c[2]);
}

t_mat3by3	matrix_mult(t_mat3by3 a, t_mat3by3 b)
{
	t_mat3by3 saida;

	saida.a[0] = (a.a[0] * b.a[0]) + (a.a[1] * b.b[0]) + (a.a[2] * b.c[0]);
	saida.a[1] = (a.a[0] * b.a[1]) + (a.a[1] * b.b[1]) + (a.a[2] * b.c[1]);
	saida.a[2] = (a.a[0] * b.a[2]) + (a.a[1] * b.b[2]) + (a.a[2] * b.c[2]);
	saida.b[0] = (a.b[0] * b.a[0]) + (a.b[1] * b.b[0]) + (a.b[2] * b.c[0]);
	saida.b[1] = (a.b[0] * b.a[1]) + (a.b[1] * b.b[1]) + (a.b[2] * b.c[1]);
	saida.b[2] = (a.b[0] * b.a[2]) + (a.b[1] * b.b[2]) + (a.b[2] * b.c[2]);
	saida.c[0] = (a.c[0] * b.a[0]) + (a.c[1] * b.b[0]) + (a.c[2] * b.c[0]);
	saida.c[1] = (a.c[0] * b.a[1]) + (a.c[1] * b.b[1]) + (a.c[2] * b.c[1]);
	saida.c[2] = (a.c[0] * b.a[2]) + (a.c[1] * b.b[2]) + (a.c[2] * b.c[2]);
	return (saida);
}

t_vec		matrix_mult_vec(t_mat3by3 mat, t_vec vec)
{
	t_vec saida;

	saida.x = (mat.a[0] * vec.x) + (mat.a[1] * vec.y) + (mat.a[2] * vec.z);
	saida.y = (mat.b[0] * vec.x) + (mat.b[1] * vec.y) + (mat.b[2] * vec.z);
	saida.z = (mat.c[0] * vec.x) + (mat.c[1] * vec.y) + (mat.c[2] * vec.z);
	return (saida);
}

t_vec	rotacao_y(t_vec ponto, double angulo)
{
	t_vec		saida;
	t_mat3by3	rot;

	rot.a[0] =  cos(angulo); rot.a[1] = 0.0; rot.a[2] = sin(angulo);
	rot.b[0] =         0.0;  rot.b[1] = 1.0; rot.b[2] =         0.0;
	rot.c[0] = -sin(angulo); rot.c[1] = 0.0; rot.c[2] = cos(angulo);
	saida = matrix_mult_vec(rot, ponto);
	return (saida);
}


t_vars	config_scene_easy(t_vars input)
{
	t_vars		vars;
	t_objeto	*obj;
	t_light		*light;
	t_vec		normal;

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
	obj->sp.cor = 0x00FF00;
	vars.objs = list_init(obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = 0.0;
	obj->sp.pos.y = 0.0;
	obj->sp.pos.z = 1.0;
	obj->sp.raio = 0.375;
	obj->sp.cor = 0xFFFFFF;
	list_add(vars.objs, obj);

	normal.x = 1.0;
	normal.y = 1.0;
	normal.z = 0.0;
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = 0.0;
	obj->sp.pos.y = 0.0;
	obj->sp.pos.z = 1.0;
	obj->sp.pos = rotacao_y(obj->sp.pos, (PI / 4));
	obj->sp.raio = 0.375;
	obj->sp.cor = 0xFF8080;
	list_add(vars.objs, obj);

	normal.x = 1.0;
	normal.y = 1.0;
	normal.z = 0.0;
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = 0.0;
	obj->sp.pos.y = 0.0;
	obj->sp.pos.z = 1.0;
	obj->sp.pos = rotacao_y(obj->sp.pos, (PI / 2));
	obj->sp.raio = 0.375;
	obj->sp.cor = 0x80FF80;
	list_add(vars.objs, obj);

	normal.x = 1.0;
	normal.y = 1.0;
	normal.z = 0.0;
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x = 0.0;
	obj->sp.pos.y = 0.0;
	obj->sp.pos.z = 1.0;
	obj->sp.pos = rotacao_y(obj->sp.pos, ((3 * PI) / 4));
	obj->sp.raio = 0.375;
	obj->sp.cor = 0x8080FF;
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
