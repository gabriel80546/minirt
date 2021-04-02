
#include "minirt.h"

void	draw(t_vars vars)
{
	int			x;
	int			y;
	t_vec		tela;
	// t_list		*result;
	t_list		*hits;
	double		ttan;
	double		tcam;
	t_hit		hit;
	int			flag;

	ttan = (tan((((vars.cam.fov)/2.0)*PI)/180.0));
	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			tcam = (((vars.largura - vars.altura) / 2));
			tela.x = vars.cam.pos.x + ((((2*ttan)/vars.largura) * x) - ttan);
			tela.y = vars.cam.pos.y - ((((2*ttan)/vars.largura) * (y + tcam)) - ttan);
			tela.z = vars.cam.pos.z + 1.0;
			hits = get_all_hits(vars, tela);
			if (hits != NULL)
			{
				hit = closest_hit(hits, vars.cam.pos);
				flag = can_light_see_this_hit(hit, vars);
				// result = cruzamento_sp_reta(hit.ponto, vars.light.pos, hit.obj.sp);
				// flag = can_light_see_this_hit_one_obj(hit, vars, result);
				// if (result != NULL)
				// 	clear_list_all(result);
				if (flag == 0)
					mlx_pixel_put(vars.mlx, vars.win, x, y, hit.obj.sp.cor);
				else
					mlx_pixel_put(vars.mlx, vars.win, x, y, (vars.light.cor | hit.obj.sp.cor));
				clear_list_all(hits);
				hits = NULL;
			}
			x++;
		}
		y++;
	}
}

/*
void	draw_yellow_sp(t_vars vars)
{
	int x;
	int y;
	t_vec tela;
	t_reta_or_n result;
	double d;
	int di;
	int cor;

	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			tela.x = (double)(x - (vars.largura / 2));
			tela.y = (double)((vars.altura / 2) - y);
			tela.z = (double)0.0;
			result = cruzamento_sp_reta(vars.cam, tela, vars.sp);
			if (result.n >= 1 && result.n <= 2)
			{
				d = distance(vars.cam, result.r.dest);
				if (d > distance(vars.cam, result.r.orig))
					d = distance(vars.cam, result.r.orig);

				d -= (distance(vars.cam, vars.sp.pos) - vars.sp.raio);
				if (d < 0)
					d = 0;
				d = d / vars.sp.raio;
				while (d > 1)
					d = d - 0.125;
				if (d < 0)
					d = 1 - d;
				di = (int)(d * 255);
				di = di % 255;
				cor = 0xFF0000;
				cor = cor | (di * 256);
				mlx_pixel_put(vars.mlx, vars.win, x, y, cor);
			}
			x++;
		}
		y++;
	}
}
*/

/*
void	draw_indiano(// t_vars vars 
)
{
	t_vec A;
	t_vec B;
	t_esfera sp;
	t_reta_or_n result;

	A.x = 10.0;
	A.y =  5.0;
	A.z =  2.0;

	B.x = 12.0;
	B.y =  6.0;
	B.z =  2.0;

	sp.pos.x = 0.0;
	sp.pos.y = 0.0;
	sp.pos.z = 0.0;
	sp.raio  = 3.0;

	printf("delta = %lf\n", cruzamento_sp_delta(A, B, sp));
	// result = cruzamento_sp_reta(A, B, sp);

	// printf("cruzou em %d pontos\n", result.n);
	if (result.n == 2)
	{
		printf("teste.orig.x = %lf\n", result.r.orig.x);
		printf("teste.orig.y = %lf\n", result.r.orig.y);
		printf("teste.orig.z = %lf\n", result.r.orig.z);

		printf("teste.dest.x = %lf\n", result.r.dest.x);
		printf("teste.dest.y = %lf\n", result.r.dest.y);
		printf("teste.dest.z = %lf\n", result.r.dest.z);

		printf("a distancia entre esses pontos eh %lf\n", distance(result.r.orig, result.r.dest));
	}
	else if (result.n == 1)
	{
		printf("teste.orig.x = %lf\n", result.r.orig.x);
		printf("teste.orig.y = %lf\n", result.r.orig.y);
		printf("teste.orig.z = %lf\n", result.r.orig.z);
	}
	else
		printf("nao cruzou em nenhum ponto\n");
}
*/
