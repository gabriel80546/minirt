
#include "../minirt.h"


t_tuple	spherical_to_tup(double radius, double inclination, double azimuth)
{
	t_tuple saida;

	saida.x = radius * cos(azimuth) * sin(inclination);
	saida.y = radius * cos(inclination);
	saida.z = radius * sin(azimuth) * sin(inclination);
	return (saida);
}

t_tuple	spherical_to_tup_rt(double radius, double inclination, double azimuth)
{
	return spherical_to_tup(radius, inclination - (PI / 2), -azimuth - (PI / 2));
}

double	tup_to_spherical_inc(t_tuple direc)
{
	double a;
	double b;
	double c;
	// double d;
	double e;
	// double f;

	a = direc.z;
	b = direc.x;
	c = sqrt((a * a) + (b * b));
	// d = atan2(c, direc.y);
	e = atan2(direc.y, c);
	// printf("a = % lf; b = % lf; c = % lf; d = % lf; e = % lf; f = % lf; (2 * PI) - e = % lf\n", a, b, c, d, e, f, (2 * PI) + e);
	// return (acos(direc.y / distance(empty_vec(), direc)));
	return (e);
}

double	tup_to_spherical_azi(t_tuple direc)
{
	return (atan2(direc.x, direc.z));
}


void draw_squares_test(void *mlx_ptr, void *win_ptr)
{
	int i;
	int j;
	int x;
	int y;
	int size;
	int c_i;
	int	colors[] = {
					0x0FCBD6, 0x0F5CC4, 0x4DD410, 0x7C1B67, 0xEC4F46,
					0x0B401E, 0xF12421, 0x32009D, 0x28C41B, 0x5FF42B,
					0x6DB19B, 0xC1906A, 0x491405, 0x1211B6, 0x8B7884,
					0xC95ECF, 0x39B283, 0x2DED00, 0x6C81E1, 0xD00583,
					0xA29089, 0x1131ED, 0x6C6167, 0xF33EC8, 0xD4BE23,
					0xBCEE46, 0x38A454, 0x412695, 0x1BC633, 0xE406DE,
					0xAAC3F7, 0xA9B3A3, 0x754601, 0x4311E0, 0xCB0322,
					0xAC683C, 0x7CEF63, 0x7FD6AD, 0x09B6A7, 0x7E20C7,
					0xD0E2E7, 0xB2CE15, 0x2572F1, 0xFC1B3F, 0x9E0BFF,
					0xCA33EE, 0x8A71E8, 0xE4F8E1, 0xD1C2DA, 0xF4AE6A,
					0xE0CCC6, 0x08FCC9, 0xA2B328, 0x1A849F, 0x16DEF2,
					0x460A3F, 0x8F6BFC, 0x82A954, 0x7E457B, 0x3205FB,
					0xE1B0B2, 0x9A98F6, 0xFC23F4, 0x965BF8, 0x6282E8,
					0xD0A85D, 0x48095C, 0xF92C1D, 0x98B2EC, 0x7C8B4F,
					0x26749B, 0xDB1BB3, 0x951EF8, 0x6E23DA, 0xF8891D,
					0xB75940, 0x27C54C, 0xACD9FF, 0xEF779E, 0x9B9554,
					0xA8A400, 0xC0C112, 0x40AB12, 0xF73F16, 0x03302C,
					0xCC12A5, 0xD6C787, 0xE234B6, 0x598291, 0x2E489B,
					0xCF82D9, 0x33B8C8, 0x074496, 0x73D3B2, 0x072846,
					0x351DEA, 0x92D33A, 0x57A8FB, 0x6A9C74, 0x841AB1,
					0xFF0000, 0x00FF00, 0x0000FF,
					42 };

	c_i = 0;
	x = 10;
	y = 10;
	size = 40;
	while (colors[c_i] != 42)
	{
		i = 0;
		while(i < size)
		{
			j = 0;
			while(j < size)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, colors[c_i]);
				j++;
			}
			i++;
		}
		x += size;
		if (x > 580)
		{
			x = 10;
			y += size;
		}
		c_i++;
	}
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
			if (sqrt(((centro_x - x) * (centro_x - x)) + ((centro_y - y) * (centro_y - y))) > raio)
				mlx_pixel_put(vars.mlx, vars.win, x, y, 0x000000);
			else
				mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFF0000);
			x += 1.0;
		}
		y += 1.0;
	}
}


t_vars	config_scene_cube_sphere(t_vars input)
{
	t_vars		vars;
	t_objeto	*obj;
	t_light		*light;
	t_tuple		direc;
	double		inc;
	double		azi;
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
	// obj->sp.raio = 0.25;
	// obj->sp.cor = 0x606060;
	vars.objs = list_init(obj);

	direc.x =  1.0;
	direc.y =  1.0;
	direc.z =  1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0x80FFFF;
	list_add(vars.objs, obj);

	direc.x =  1.0;
	direc.y =  1.0;
	direc.z = -1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFF80FF;
	list_add(vars.objs, obj);

	direc.x = -1.0;
	direc.y =  1.0;
	direc.z =  1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFFFF80;
	list_add(vars.objs, obj);

	direc.x = -1.0;
	direc.y =  1.0;
	direc.z = -1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFF8080;
	list_add(vars.objs, obj);



	direc.x =  1.0;
	direc.y = -1.0;
	direc.z =  1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc /* (7 * PI / 4) */, azi);
	// // obj->sp.pos = direc;
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0x80FF80;
	list_add(vars.objs, obj);

	direc.x =  1.0;
	direc.y = -1.0;
	direc.z = -1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0x8080FF;
	list_add(vars.objs, obj);

	direc.x = -1.0;
	direc.y = -1.0;
	direc.z =  1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0x808080;
	list_add(vars.objs, obj);

	direc.x = -1.0;
	direc.y = -1.0;
	direc.z = -1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0x808000;
	list_add(vars.objs, obj);










	direc.x =  1.0;
	direc.y =  0.0;
	direc.z =  1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFF0000;
	list_add(vars.objs, obj);

	direc.x =  1.0;
	direc.y =  0.0;
	direc.z = -1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0x00FF00;
	list_add(vars.objs, obj);

	direc.x = -1.0;
	direc.y =  0.0;
	direc.z = -1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0x0000FF;
	list_add(vars.objs, obj);

	direc.x = -1.0;
	direc.y =  0.0;
	direc.z =  1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFF00FF;
	list_add(vars.objs, obj);





	direc.x =  1.0;
	direc.y =  1.0;
	direc.z =  0.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFFFF00;
	list_add(vars.objs, obj);

	direc.x =  1.0;
	direc.y = -1.0;
	direc.z =  0.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0x00FFFF;
	list_add(vars.objs, obj);

	direc.x = -1.0;
	direc.y =  1.0;
	direc.z =  0.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// // obj->sp.cor = 0x800000;
	list_add(vars.objs, obj);

	direc.x = -1.0;
	direc.y = -1.0;
	direc.z =  0.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// // obj->sp.cor = 0x008000;
	list_add(vars.objs, obj);




	direc.x =  0.0;
	direc.y =  1.0;
	direc.z =  1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// // obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// // obj->sp.raio = 0.375;
	// obj->sp.cor = 0x000080;
	list_add(vars.objs, obj);

	direc.x =  0.0;
	direc.y = -1.0;
	direc.z =  1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0x800000;
	list_add(vars.objs, obj);

	direc.x =  0.0;
	direc.y =  1.0;
	direc.z = -1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0x008000;
	list_add(vars.objs, obj);

	direc.x =  0.0;
	direc.y = -1.0;
	direc.z = -1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0x008080;
	list_add(vars.objs, obj);







	direc.x =  1.0;
	direc.y =  0.0;
	direc.z =  0.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFF0000;
	list_add(vars.objs, obj);

	direc.x = -1.0;
	direc.y =  0.0;
	direc.z =  0.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0xFF0000;
	list_add(vars.objs, obj);


	direc.x =  0.0;
	direc.y =  1.0;
	direc.z =  0.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0x00FF00;
	list_add(vars.objs, obj);

	direc.x =  0.0;
	direc.y = -1.0;
	direc.z =  0.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0x00FF00;
	list_add(vars.objs, obj);




	direc.x =  0.0;
	direc.y =  0.0;
	direc.z =  1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);
	// printf("inc = % lf\n", inc);
	// printf("azi = % lf\n", azi);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0x0000FF;
	list_add(vars.objs, obj);

	direc.x =  0.0;
	direc.y =  0.0;
	direc.z = -1.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	// obj->sp.pos = spherical_to_tup_rt(distance(empty_vec(), direc), inc, azi);
	// obj->sp.raio = 0.375;
	// obj->sp.cor = 0x0000FF;
	list_add(vars.objs, obj);

	direc.x =  1.0;
	direc.y =  0.0;
	direc.z =  0.0;
	inc = tup_to_spherical_inc(direc);
	azi = tup_to_spherical_azi(direc);

	// i = 0;
	// while (i < 8)
	// {
	// 	obj = (t_objeto *)malloc(sizeof(t_objeto));
	// 	obj->tipo = SPHERE;
	// 	obj->sp.pos = spherical_to_tup_rt(1.0, 0.0, i * (PI / 8));
	// // 	obj->sp.raio = 0.375;
	// 	obj->sp.cor = 0xFF80FF;
	// 	list_add(vars.objs, obj);
	// 	i++;
	// }

	// LUZES

	vars.lights = NULL;
	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 0.3;
	// light->pos.x = 1.0;
	// light->pos.y = 2.0;
	// light->pos.z = -2.0;
	// light->cor = 0xFFFFFF;
	vars.lights = list_init(light);

	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 0.3;
	// light->pos.x = -1.0;
	// light->pos.y = 2.0;
	// light->pos.z = -2.0;
	// light->cor = 0xFFFFFF;
	// vars.lights = list_init(light);
	list_add(vars.lights, light);

	light = (t_light *)malloc(sizeof(t_light));
	light->bright = 0.3;
	// light->pos.x = -3.0;
	// light->pos.y = 5.0;
	// light->pos.z = -2.0;
	// light->cor = 0xFFFFFF;
	// vars.lights = list_init(light);
	list_add(vars.lights, light);

	// vars.cam.pos.x = 0.0;
	// vars.cam.pos.y = 0.0;
	// vars.cam.pos.z = 0.0;
	// vars.cam.fov = 90.0;

	return (vars);
}
