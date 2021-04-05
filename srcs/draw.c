
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
			{
				// printf("x = %d, y = %d, nao esta iluminado por essa luz\n", x, y);
				flag = flag + 0;
			}
			else
			{
				if (iluminados == NULL)
				{
					iluminado = (t_light *)malloc(sizeof(t_light));
					iluminado = &(*((t_light *)vars.lights->data));
					iluminados = list_init(iluminado);
				}
				else
				{
					iluminado = (t_light *)malloc(sizeof(t_light));
					iluminado = &(*((t_light *)vars.lights->data));
					list_add(iluminados, iluminado);
				}
				// printf("x = %d, y = %d, esta iluminado por essa luz\n", x, y);
			}	
			// if (flag == 0)
			// 	mlx_pixel_put(vars.mlx, vars.win, x, y, compute_color(0.1, hit.obj.sp.cor));
			// else
			// {
			// 	intensity = ((acos(cosine_law(((t_light *)vars.lights->data)->pos /* vars.light.pos */, hit.ponto, hit.obj.sp.pos)) * (180.0 / PI) - 90.0) / 90.0);
			// 	if (intensity < 0.1)
			// 		intensity = 0.1;
			// 	mlx_pixel_put(vars.mlx, vars.win, x, y, compute_color(intensity, hit.obj.sp.cor));
			// }
			vars.lights = vars.lights->next;
		}
		while (iluminados != NULL)
		{
			// printf("x = %d, y = %d; light.x = %lf\n", x, y, ((t_light *)iluminados->data)->pos.x);
			intensity = ((acos(cosine_law(((t_light *)iluminados->data)->pos /* vars.light.pos */, hit.ponto, hit.obj.sp.pos)) * (180.0 / PI) - 90.0) / 90.0);
			if (intensity < 0.1)
				intensity = 0.1;
			mlx_pixel_put(vars.mlx, vars.win, x, y, compute_color(intensity, hit.obj.sp.cor));
			iluminados = iluminados->next;
		}
		// printf("x = %d, y = %d; tem %d luzes iluminando\n", x, y, counter);
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
