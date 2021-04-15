
#include "minirt.h"

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

void	draw_main(t_vars vars, int x, int y, t_img img)
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
	if (hits != NULL)
	{
		hit = closest_hit(hits, vars.cam.pos);
		iluminados = NULL;
		while (vars.lights != NULL)
		{
			flag = can_light_see_this_hit(hit, vars, *((t_light *)vars.lights->data));
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
			cor = hit.obj.pl.cor;
		had = to_had(vars.ambient);
		temp_luz = NULL;
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

	img.ptr = mlx_new_image(vars.mlx, vars.largura, vars.altura);
	img.data = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	img.bits_per_byte = 8;

	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			draw_main(vars, x, y, img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.ptr, 0, 0);
	mlx_destroy_image(vars.mlx, img.ptr);
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
