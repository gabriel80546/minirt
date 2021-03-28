
#include "minirt.h"

void	draw(t_vars vars)
{
	int x;
	int y;
	t_vec A;
	t_vec B;
	t_esfera sp;
	t_reta_or_n result;
	double d;
	int di;
	int cor;

	if (0)
	{
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
		// t_reta teste;

		// teste = cruzamento_sp_reta(A, B, sp);
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
		// if (cruza_sp(A, B, sp))
		// 	printf("cruza_sp\n");
		// else
		// 	printf("nao cruza_sp\n");
	}
	else
	{
		A.x =    0.0;
		A.y =    0.0;
		A.z = (double)(-(LARGURA / 2));

		sp.pos.x = -30.0;
		sp.pos.y = +30.0;
		sp.pos.z =  80.0;
		sp.raio  = 150.0;

		y = 0;
		while (y < ALTURA)
		{
			x = 0;
			while (x < LARGURA)
			{
				B.x = (double)(x - (LARGURA / 2));
				B.y = (double)((ALTURA / 2) - y);
				B.z = (double)0.0;
				if (0)
				{
					if (cruza_sp(A, B, sp))
						mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFF0000);
				}
				else
				{
					result = cruzamento_sp_reta(A, B, sp);
					if (result.n == 2)
					{
						d = distance(A, result.r.dest);
						if (d > distance(A, result.r.orig))
							d = distance(A, result.r.orig);

						d -= (distance(A, sp.pos) - sp.raio);
						if (d < 0)
							d = 0;
						d = d / sp.raio;
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
					// else
					// 	mlx_pixel_put(vars.mlx, vars.win, x, y, 0xE0E0E0);
				}
				x++;
			}
			y++;
		}
	}
}
