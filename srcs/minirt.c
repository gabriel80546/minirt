#include "minirt.h"

t_vars	config_cams(t_vars input)
{
	t_vars	saida;
	t_cam	*cam;
	int		i;

	i = -5;
	saida.cams = NULL;
	saida = input;
	i = 0;
	while (i < 16)
	{
		cam = (t_cam *)malloc(sizeof(t_cam));
		cam->pos.x = 0.0;
		cam->pos.y = 0.0;
		cam->pos.z = -3.0;
		cam->pos = mat44_tuple_mul(mat44_rotate_y(i * (PI / 8)), cam->pos);
		cam->direc.x = -cam->pos.x;
		cam->direc.y = -cam->pos.y;
		cam->direc.z = -cam->pos.z;
		cam->fov = 60.0;
		cam->transform = view_transform(mat44_tuple_mul(mat44_rotate_y(
						i * (PI / 8)), point(0, 1.5, -5)),
				point(0, 1, 0), vector(0, 1, 0));
		if (saida.cams == NULL)
			saida.cams = list_init(cam);
		else
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
	t_tuple		temp_direc;

	vars = input;
	vars.objs = NULL;
	obj = NULL;
	vars.largura = 200;
	vars.altura = 140;
	vars.gray = 0;
	vars.ambient = 0x404040;
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = PLANE;
	obj->pl.pos = point(0.0, 0.0, 0.0);
	obj->pl.material.color = color(1.0, 0.4, 0.8);
	obj->pl.material.ambient = 0.1;
	obj->pl.material.diffuse = 0.7;
	obj->pl.material.specular = 0.2;
	obj->pl.material.shininess = 200.0;
	obj->pl.transform = mat44_identity();
	vars.objs = list_init(obj);
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = PLANE;
	obj->pl.pos = point(0.0, 0.0, 0.0);
	obj->pl.material.color = color(0.4, 1.0, 0.8);
	obj->pl.material.ambient = 0.1;
	obj->pl.material.diffuse = 0.7;
	obj->pl.material.specular = 0.2;
	obj->pl.material.shininess = 200.0;
	obj->pl.transform = mat44_mul(mat44_rotate_x(PI / 2),
			mat44_translate(0, 10, 0));
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
	list_add(vars.objs, obj);
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = CYLINDER;
	obj->cy.pos = point(0.0, 0.0, 0.0);
	obj->cy.diameter = 157.0;
	obj->cy.material.color = color(1.0, 0.0, 0.0);
	obj->cy.material.ambient = 0.1;
	obj->cy.material.diffuse = 0.7;
	obj->cy.material.specular = 0.3;
	obj->cy.material.shininess = 200.0;
	obj->cy.transform = mat44_mul(mat44_scaling(0.5, 0.5, 0.5),
			mat44_mul(mat44_rotate_x(PI / 4), mat44_translate(2.0, 10.0, 0.0)));
	obj->cy.height = 10.0;
	list_add(vars.objs, obj);
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = TRIANGLE;
	obj->tr.pos_a = point(2.0, 1.0, 1.0);
	obj->tr.pos_b = point(2.0, 2.0, 3.0);
	obj->tr.pos_c = point(3.0, 2.0, 3.0);
	obj->tr.material.color = color(0.0, 1.0, 0.0);
	obj->tr.material.ambient = 0.1;
	obj->tr.material.diffuse = 0.7;
	obj->tr.material.specular = 0.3;
	obj->tr.material.shininess = 200.0;
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
	list_add(vars.objs, obj);
	temp_direc.x = -10.0;
	temp_direc.y = 10.0;
	temp_direc.z = -10.0;
	vars.lights = NULL;
	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 0.8;
	light->position = point(temp_direc.x, temp_direc.y, temp_direc.z);
	light->cor = color(1.0, 1.0, 1.0);
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

int	key_hook(int keycode, t_vars *vars)
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

int	main(void)
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
