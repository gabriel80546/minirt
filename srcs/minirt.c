
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

t_vars config_scene_easy(void)
{
	t_vars vars;
	t_objeto *obj;

	// tela = quadrado
	// tela_top_left = -320 x, y =  200, z = 0
	// tela_top_right = 320 x, y = -200, z = 0
	// top_down_left = -320 x, y =  200, z = 0
	// top_down_right = 320 x, y = -200, z = 0

	vars.largura = 400;
	vars.altura = 400;

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =  -1.0;
	obj->sp.pos.y =   0.0;
	obj->sp.pos.z =   5.0;
	obj->sp.raio  =   2.0;
	obj->sp.cor   = 0xFF0000;
	vars.objs = list_init(obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =   1.0;
	obj->sp.pos.y =   0.0;
	obj->sp.pos.z =   5.0;
	obj->sp.raio  =   2.0;
	obj->sp.cor   = 0x0000FF;
	list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =   0.0;
	obj->sp.pos.y =   0.0;
	obj->sp.pos.z =   0.0;
	obj->sp.raio  =   1.0;
	obj->sp.cor   = 0x00FF00;
	// vars.objs = list_init(obj);
	list_add(vars.objs, obj);

	vars.cam.pos.x =  0.0;
	vars.cam.pos.y =  0.0;
	vars.cam.pos.z =  0.0;
	vars.cam.fov   = 90.0;
	// vars.cam.pos.z = (double)(-(vars.largura / 2));
	return (vars);
}

t_vars config_scene(void)
{
	t_vars vars;
	t_objeto *obj;

	vars.largura = 600;
	vars.altura  = 600;

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =  -2.0;
	obj->sp.pos.y =  -2.0;
	obj->sp.pos.z =   7.8;
	obj->sp.raio  =   3.0;
	obj->sp.cor   = 0xFF0000;
	vars.objs = list_init(obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =  -4.0;
	obj->sp.pos.y =  -2.0;
	obj->sp.pos.z =  12.0;
	obj->sp.raio  =   3.0;
	obj->sp.cor   = 0x0000FF;
	list_add(vars.objs, obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =  -4.0;
	obj->sp.pos.y =  -2.0;
	obj->sp.pos.z =  -6.0;
	obj->sp.raio  =   3.0;
	obj->sp.cor   = 0x00FF00;
	list_add(vars.objs, obj);

	vars.cam.pos.x =  -3.0;
	vars.cam.pos.y =  -2.0;
	vars.cam.pos.z =   4.0;
	vars.cam.fov   =  90.0;
	// vars.cam.pos.z = (double)(-(vars.largura / 2));
	return (vars);
}

int	main(/* int argc, char **argv */)
{
	t_vars      vars;

	vars = config_scene();
	// vars = config_scene_easy();

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
