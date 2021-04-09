
#include "minirt.h"

t_vec	setup_tela(t_vars vars, int x, int y)
{
	t_vec	saida;
	double	ttan;
	double	tcam;

	// if (vars.cam.p == 0)
	// {
	// 	printf("10: cam.p = %d\n", vars.cam.p);
	// 	printf("vars.cam.pos.x = (%lf)\n", vars.cam.pos.x);
	// 	printf("vars.cam.pos.y = (%lf)\n", vars.cam.pos.y);
	// 	printf("vars.cam.pos.z = (%lf)\n", vars.cam.pos.z);


	// 	// printf("vars.cam.rot.x = (%lf)\n", vars.cam.rot.x);
	// 	printf("vars.cam.rot.y = (%lf)\n", vars.cam.rot.y);
	// 	// printf("vars.cam.rot.z = (%lf)\n", vars.cam.rot.z);
	// }

	ttan = (tan((((vars.cam.fov) / 2.0) * PI) / 180.0));
	tcam = (((vars.largura - vars.altura) / 2));
	saida.x =  ((((2 * ttan) / vars.largura) * x) - ttan);
	saida.y = -((((2 * ttan) / vars.largura) * (y + tcam)) - ttan);
	saida.z =  1.0;

	saida = rotacao_x(saida, vars.cam.rot.x);
	saida = rotacao_y(saida, vars.cam.rot.y);

	saida.x += vars.cam.pos.x;
	saida.y += vars.cam.pos.y;
	saida.z += vars.cam.pos.z;
	return (saida);
}

void	draw_main(t_vars vars, int x, int y)
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
	// t_cor_had	final;

	tela = setup_tela(vars, x, y);
	vars.cam.p = 1;
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
		cor = hit.obj.sp.cor;
		had = to_had(vars.ambient);
		temp_luz = NULL;
		while (iluminados != NULL)
		{
			intensity = ((acos(cosine_law(((t_light *)iluminados->data)->pos, hit.ponto, hit.obj.sp.pos)) * (180.0 / PI) - 90.0) / 90.0);
			had.r += (intensity * ((t_light *)iluminados->data)->bright);
			had.g += (intensity * ((t_light *)iluminados->data)->bright);
			had.b += (intensity * ((t_light *)iluminados->data)->bright);
			counter++;
			temp_luz = iluminados;
			iluminados = iluminados->next;
		}
		result = norm_had(mult_had(to_had(cor), had));
		// 0.299R + 0.587G + 0.114B;
		if (vars.gray == 1)
		{
			result.r = (result.r * 0.299) + (result.g * 0.587) + (result.b * 0.114);
			result.g = result.r;
			result.b = result.r;
		}
		cor = to_rgb(result);
		// printf("cor\n")
		iluminados = first_item(temp_luz);
		if (counter >= 0)
			mlx_pixel_put(vars.mlx, vars.win, x, y, cor);
		clear_list(iluminados);
		clear_list_all(hits);
		hits = NULL;
	}
}

void	draw(t_vars vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			draw_main(vars, x, y);
			vars.cam.p = 1;
			x++;
		}
		y++;
	}
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
