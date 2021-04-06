
#include "minirt.h"

t_vec	setup_tela(t_vars vars, int x, int y)
{
	t_vec	saida;
	double	ttan;
	double	tcam;

	ttan = (tan((((vars.cam.fov) / 2.0) * PI) / 180.0));
	tcam = (((vars.largura - vars.altura) / 2));
	saida.x = vars.cam.pos.x + ((((2 * ttan) / vars.largura) * x) - ttan);
	saida.y = vars.cam.pos.y - ((((2 * ttan) / vars.largura) * (y + tcam)) - ttan);
	saida.z = vars.cam.pos.z + 1.0;
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
	// t_cor_had	final;

	tela = setup_tela(vars, x, y);
	hits = get_all_hits(vars, tela);
	if (hits != NULL)
	{
		hit = closest_hit(hits, vars.cam.pos);
		iluminados = NULL;
		
		while (vars.lights != NULL)
		{
			flag = can_light_see_this_hit(hit, vars, *((t_light *)vars.lights->data));
			if (flag == 0)
				mlx_pixel_put(vars.mlx, vars.win, x, y, compute_color(0.8, hit.obj.sp.cor));
			else
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
			had.r += intensity;
			had.g += intensity;
			had.b += intensity;
			counter++;
			temp_luz = iluminados;
			iluminados = iluminados->next;
		}
		cor = to_rgb(norm_had(mult_had(to_had(cor), had)));
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
			x++;
		}
		y++;
	}
}
