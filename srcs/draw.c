
#include "minirt.h"

void	draw(t_vars vars)
{
	int x;
	int y;
	t_vec A;
	t_vec B;
	t_reta_or_n result;

	A.x = 0.0;
	A.y = 0.0;
	A.z = (double)(-(vars.largura / 2));

	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			B.x = (double)(x - (vars.largura / 2));
			B.y = (double)((vars.altura / 2) - y);
			B.z = (double)0.0;
			result = cruzamento_sp_reta(A, B, vars.sp);
			if (result.n >= 1 && result.n <= 2)
				mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	draw_yellow_sp(t_vars vars)
{
	int x;
	int y;
	t_vec A;
	t_vec B;
	t_reta_or_n result;
	double d;
	int di;
	int cor;

	A.x = 0.0;
	A.y = 0.0;
	A.z = (double)(-(vars.largura / 2));
	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			B.x = (double)(x - (vars.largura / 2));
			B.y = (double)((vars.altura / 2) - y);
			B.z = (double)0.0;
			result = cruzamento_sp_reta(A, B, vars.sp);
			if (result.n >= 1 && result.n <= 2)
			{
				d = distance(A, result.r.dest);
				if (d > distance(A, result.r.orig))
					d = distance(A, result.r.orig);

				d -= (distance(A, vars.sp.pos) - vars.sp.raio);
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
