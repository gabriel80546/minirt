
#include "minirt.h"

// typedef struct	s_count
// {
// 	int			plane_pixels;
// 	int			plane_iluminated;
// }				t_count;

t_vec	setup_tela(t_vars vars, int x, int y)
{
	t_vec	saida;
	double	ttan;
	double	tcam;

	ttan = (tan((((vars.cam.fov) / 2.0) * PI) / 180.0));
	tcam = (((vars.largura - vars.altura) / 2));
	saida.x =  ((((2 * ttan) / vars.largura) * x) - ttan);
	saida.y = -((((2 * ttan) / vars.largura) * (y + tcam)) - ttan);
	saida.z =  1.0;

	saida = rotacao_x(saida, vec_to_spherical_inc(vars.cam.direc));
	saida = rotacao_y(saida, vec_to_spherical_azi(vars.cam.direc));

	saida.x += vars.cam.pos.x;
	saida.y += vars.cam.pos.y;
	saida.z += vars.cam.pos.z;
	return (saida);
}

void	draw_main(t_vars vars, int x, int y, t_img img, t_debug *deb)
{
	t_vec		tela;
	t_list		*hits;
	t_hit		hit;
	int			flag;
	double		intensity;
	t_list		*iluminados;
	t_light		*iluminado;
	t_list		*temp_luz;
	int			counter;
	int			cor;
	t_cor_had	had;
	t_cor_had	result;

	tela = setup_tela(vars, x, y);
	hits = get_all_hits(vars, tela);
	if ((x == deb->x_bugado && y == deb->y_bugado) ||
		(x == deb->x_iluminado && y == deb->y_iluminado) ||
		(x == deb->x_sombreado && y == deb->x_sombreado))
	{
		printf("%s(%s:%d): x = %d\n", __FILE__, __func__, __LINE__, x);
		printf("%s(%s:%d): y = %d\n", __FILE__, __func__, __LINE__, y);
		printf("%s(%s:%d): hits = %p\n", __FILE__, __func__, __LINE__, hits);
	}
	if (hits != NULL)
	{
		hit = closest_hit(hits, vars.cam.pos);
		iluminados = NULL;
		while (vars.lights != NULL)
		{
			flag = can_light_see_this_hit(hit, vars, *((t_light *)vars.lights->data), *deb);
			if ((x == deb->x_bugado && y == deb->y_bugado) ||
				(x == deb->x_iluminado && y == deb->y_iluminado) ||
				(x == deb->x_sombreado && y == deb->x_sombreado))
			{
				printf("%s(%s:%d): x = %d\n", __FILE__, __func__, __LINE__, x);
				printf("%s(%s:%d): y = %d\n", __FILE__, __func__, __LINE__, y);
				printf("%s(%s:%d): flag = %d\n", __FILE__, __func__, __LINE__, flag);
			}
			if (flag != 0)
			{
				iluminado = ((t_light *)vars.lights->data);
				if (iluminados == NULL)
					iluminados = list_init(iluminado);
				else
					list_add(iluminados, iluminado);
			}
			vars.lights = vars.lights->next;
		}
		counter = 0;
		if (hit.obj.tipo == SPHERE)
			cor = hit.obj.sp.cor;
		else if (hit.obj.tipo == PLANE)
		{
			cor = hit.obj.pl.cor;
			deb->plane_pixels++;
			if (iluminados != NULL)
				deb->plane_iluminated++;
		}
		had = to_had(vars.ambient);
		temp_luz = NULL;
		if (x == 260 && y == 40)
			printf("%s(%s:%d): iluminados = %p\n", __FILE__, __func__, __LINE__, iluminados);
		while (iluminados != NULL)
		{
			if (hit.obj.tipo == SPHERE)
				intensity = ((acos(cosine_law(((t_light *)iluminados->data)->pos, hit.ponto, hit.obj.sp.pos)) * (180.0 / PI) - 90.0) / 90.0);
			else if (hit.obj.tipo == PLANE)
				intensity = 1.0;
			had.r += (intensity * ((t_light *)iluminados->data)->bright);
			had.g += (intensity * ((t_light *)iluminados->data)->bright);
			had.b += (intensity * ((t_light *)iluminados->data)->bright);
			counter++;
			temp_luz = iluminados;
			iluminados = iluminados->next;
		}
		result = norm_had(mult_had(to_had(cor), had));
		if (vars.gray == 1)
		{
			result.r = (result.r * 0.299) + (result.g * 0.587) + (result.b * 0.114);
			result.g = result.r;
			result.b = result.r;
		}
		cor = to_rgb(result);
		if ((x == deb->x_bugado && y == deb->y_bugado) ||
			(x == deb->x_iluminado && y == deb->y_iluminado) ||
			(x == deb->x_sombreado && y == deb->y_sombreado))
			cor = 0xFF0000;
		iluminados = first_item(temp_luz);
		if (counter >= 0)
			*((unsigned int *)img.data + (x + (y * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = cor;
		clear_list(iluminados);
		clear_list_all(hits);
		hits = NULL;
	}
}

void	draw(t_vars vars)
{
	int		x;
	int		y;
	t_img	img;
	// t_count	count;
	t_debug	deb;

	deb = (t_debug) {0};
	deb.x_bugado = 190;
	deb.y_bugado = 160;
	deb.x_iluminado = 230;
	deb.y_iluminado = 160;
	deb.x_sombreado = 380;
	deb.y_sombreado = 280;
	deb.plane_pixels = 0;
	deb.plane_iluminated = 0;

	img.ptr = mlx_new_image(vars.mlx, vars.largura, vars.altura);
	img.data = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	img.bits_per_byte = 8;

	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			deb.x = x;
			deb.y = y;
			draw_main(vars, x, y, img, &deb);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.ptr, 0, 0);
	mlx_destroy_image(vars.mlx, img.ptr);
	printf("%s(%s:%d): deb.plane_pixels = %d\n", __FILE__, __func__, __LINE__, deb.plane_pixels);
	printf("%s(%s:%d): deb.plane_iluminated = %d\n", __FILE__, __func__, __LINE__, deb.plane_iluminated);
	// printf("%s(%s:%d): vars.cam.pos.x = % 6.6lf\n", __FILE__, __func__, __LINE__, vars.cam.pos.x);
	// printf("%s(%s:%d): vars.cam.pos.y = % 6.6lf\n", __FILE__, __func__, __LINE__, vars.cam.pos.y);
	// printf("%s(%s:%d): vars.cam.pos.z = % 6.6lf\n", __FILE__, __func__, __LINE__, vars.cam.pos.z);
	// printf("%s(%s:%d): vars.cam.direc.x = % 6.6lf\n", __FILE__, __func__, __LINE__, vars.cam.direc.x);
	// printf("%s(%s:%d): vars.cam.direc.y = % 6.6lf\n", __FILE__, __func__, __LINE__, vars.cam.direc.y);
	// printf("%s(%s:%d): vars.cam.direc.z = % 6.6lf\n", __FILE__, __func__, __LINE__, vars.cam.direc.z);
}

void	clear_screen(t_vars vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			mlx_pixel_put(vars.mlx, vars.win, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
