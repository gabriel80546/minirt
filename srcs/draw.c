
#include "minirt.h"

void	draw(t_vars vars)
{
	int			x;
	int			y;
	t_vec		tela;
	t_reta_or_n	result;
	t_list		*temp_list;
	t_reta_or_n	resolvido;
	t_list		*hits;
	t_list		*temp_hit;
	t_hit		*n;
	double		dist;
	double		smaller;
	int			cor;
	double		ttan;
	double		tcam;
	// int			first;

	// first = 0;
	hits = NULL;
	temp_hit = NULL;
	temp_list = NULL;
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
			resolvido.n = -1;
			while (vars.objs != NULL)
			{
				result = cruzamento_sp_reta(vars.cam.pos, tela, *((t_esfera *)vars.objs->data));
				result = sanitize_cruz(vars.cam.pos, tela, result);
				if (result.n >= 1 && result.n <= 2)
					resolvido = result;
				if (result.n > 0)
				{
					n = (t_hit *)malloc(sizeof(t_hit));
					n->obj = *((t_objeto *)vars.objs->data);
					n->ponto = result.r.orig;
					if (hits == NULL)
						hits = list_init(n);
					else
						list_add(hits, n);
					if (result.n == 2)
					{
						n = (t_hit *)malloc(sizeof(t_hit));
						n->obj = *((t_objeto *)vars.objs->data);
						n->ponto = result.r.dest;
						list_add(hits, n);
					}
				}
				temp_list = vars.objs;
				vars.objs = vars.objs->next;
			}
			if (resolvido.n >= 1 && resolvido.n <= 2)
			{
				vars.objs = temp_list;
				smaller = 1000000.0;
				while (hits != NULL)
				{
					dist = distance(((t_hit *)hits->data)->ponto, vars.cam.pos);
					if (dist < smaller)
					{
						smaller = dist;
						cor = ((t_objeto)((t_hit *) hits->data)->obj).sp.cor;
					}
					temp_hit = hits;
					hits = hits->next;
				}
				hits = first_item(temp_hit);
				mlx_pixel_put(vars.mlx, vars.win, x, y, cor);
				clear_list_all(hits);
				hits = NULL;
			}
			vars.objs = first_item(temp_list);
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

void	draw_indiano(/* t_vars vars */)
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
	result = cruzamento_sp_reta(A, B, sp);

	printf("cruzou em %d pontos\n", result.n);
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
