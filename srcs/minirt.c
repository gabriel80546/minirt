
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include "mlx.h"
#include <math.h>

//#include "get_next_line.h"
//#include <sys/stat.h>
//#include <fcntl.h>

# define LARGURA 640
# define ALTURA 420

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct	t_posicao {
	double		x;
	double		y;
	double		z;
}				t_posicao;

typedef struct	s_coeff
{
	double		a;
	double		b;
	double		c;
}				t_coeff;

typedef struct	s_reta
{
	t_posicao	orig;
	t_posicao	dest;
}				t_reta;

typedef struct	s_reta_or_n
{
	t_reta		r;
	int			n;
}				t_reta_or_n;


// typedef struct camera {
// 	posicao pos;
// } camera;

typedef struct	t_esfera{
	t_posicao	pos;
	double		raio;
}				t_esfera;

// typedef struct tela{
// 	posicao tleft;
// 	posicao dright;
// } tela;

t_reta		empty_reta(void)
{
	t_reta saida;

	saida.orig.x = 0.0;
	saida.orig.y = 0.0;
	saida.orig.z = 0.0;
	saida.dest.x = 0.0;
	saida.dest.y = 0.0;
	saida.dest.z = 0.0;
	return (saida);
}

t_coeff	get_sp_coeff(t_posicao A, t_posicao B, t_esfera sp)
{
	t_coeff	saida;
	double	x;
	double	y;

	saida.a = 0.0;
	saida.b = 0.0;
	saida.c = 0.0;
	x = A.x - sp.pos.x;
	y = B.x - A.x - sp.pos.x;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	x = A.y - sp.pos.y;
	y = B.y - A.y - sp.pos.y;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	x = A.z - sp.pos.z;
	y = B.z - A.z - sp.pos.z;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	saida.c -= (sp.raio * sp.raio);
	return (saida);
}

int		cruza_sp(t_posicao A, t_posicao B, t_esfera sp)
{
	t_coeff coeff;
	double d;

	coeff = get_sp_coeff(A, B, sp);

	d = (coeff.b*coeff.b) + (-4*coeff.a*coeff.c);

	if (d >= 0)
		return (1);
	else
		return (0);
}

double	cruzamento_sp_delta(t_posicao A, t_posicao B, t_esfera sp)
{
	t_coeff coeff;
	double d;

	coeff = get_sp_coeff(A, B, sp);

	d = (coeff.b*coeff.b) + (-4*coeff.a*coeff.c);

	return (d);
}

t_reta_or_n	cruzamento_sp_reta(t_posicao A, t_posicao B, t_esfera sp)
{
	t_coeff coeff;
	t_reta_or_n saida;
	double	d;
	double	x1;
	double	x2;

	saida.r = empty_reta();

	coeff = get_sp_coeff(A, B, sp);

	d = (coeff.b*coeff.b) + (-4*coeff.a*coeff.c);

	if (d < 0)
		saida.n = 0;
	else if (d == 0)
	{
		x1 = (-coeff.b) / (2*coeff.a);

		saida.r.orig.x = A.x + ((B.x - A.x) * x1);
		saida.r.orig.y = A.y + ((B.y - A.y) * x1);
		saida.r.orig.z = A.z + ((B.z - A.z) * x1);

		saida.n = 1;
	}
	else
	{
		x1 = (-coeff.b + sqrt(d)) / (2*coeff.a);
		x2 = (-coeff.b - sqrt(d)) / (2*coeff.a);

		saida.r.orig.x = A.x + ((B.x - A.x) * x1);
		saida.r.orig.y = A.y + ((B.y - A.y) * x1);
		saida.r.orig.z = A.z + ((B.z - A.z) * x1);

		saida.r.dest.x = A.x + ((B.x - A.x) * x2);
		saida.r.dest.y = A.y + ((B.y - A.y) * x2);
		saida.r.dest.z = A.z + ((B.z - A.z) * x2);
		saida.n = 2;
	}
	return (saida);
}

double	distance(t_posicao A, t_posicao B)
{
	double a;
	double b;
	double c;
	double d;

	a = (A.x - B.x);
	b = (A.y - B.y);
	c = (A.z - B.z);
	d = sqrt((a * a) + (b * b) + (c * c));
	return (d);
}

void	raytrace(t_vars vars)
{
	int x;
	int y;
	t_posicao A;
	t_posicao B;
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

						B = sp.pos;
						// B.z -= sp.raio;
						d -= (distance(A, B) - sp.raio);
						// printf("x = %d; y = %d; d = %lf; p/org = %lf\n", x, y, d, distance(A, B));
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
						// cor = cor | di;

						mlx_pixel_put(vars.mlx, vars.win, x, y, cor);
					}
					// else
					// 	printf("nao cruza\n");
				}
				x++;
			}
			y++;
		}
	}
}

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		printf("fechando... :)\n");
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
	return (0);
}

int	main(void)
{
	int (*teste)(int, t_vars*);
	t_vars      vars;

	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, LARGURA, ALTURA, "minirt");
	raytrace(vars);

/*
	// int fd;
	// char *linha;
	// int i;
	// int retorno;
	fd = open("../../files/example.rt", O_RDONLY);
	i = 0;
	retorno = 1;
	while (retorno == 1)
	{
		retorno = get_next_line(fd, &linha);
		if (retorno != 1)
			break;
		printf("1: linha[%d] = '%s'; retorno = %i\n", i, linha, strlen(linha), retorno);
		free(linha);
		i++;
	}
	if (retorno != -1)
	{
		printf("2: linha[%d] = '%s'(%ld); retorno = %i\n", i, linha, strlen(linha), retorno);
		free(linha);
	}
	else
		printf("get_next_line retornou -1\n");
*/
	teste = key_hook;
	mlx_key_hook(vars.win, teste, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
