
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include "mlx.h"
//#include "get_next_line.h"
//#include <sys/stat.h>
//#include <fcntl.h>

# define LARGURA 640
# define ALTURA 420


typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct posicao {
	double x;
	double y;
	double z;
} posicao;

// typedef struct camera {
// 	posicao pos;
// } camera;

typedef struct esfera{
	posicao pos;
	double raio;
} esfera;

// typedef struct tela{
// 	posicao tleft;
// 	posicao dright;
// } tela;

int	cruza(posicao A, posicao B, esfera C)
{
	double x;
	double y;
	double a;
	double b;
	double c;

	a = 0.0;
	b = 0.0;
	c = 0.0;
	x = A.x - C.pos.x;
	y = B.x - A.x - C.pos.x;
	a += (y * y);
	b += (2 * x * y);
	c += (x * x);

	x = A.y - C.pos.y;
	y = B.y - A.y - C.pos.y;
	a += (y * y);
	b += (2 * x * y);
	c += (x * x);

	x = A.z - C.pos.z;
	y = B.z - A.z - C.pos.z;
	a += (y * y);
	b += (2 * x * y);
	c += (x * x);

	c -= (C.raio * C.raio);

	double d = (b*b) + (-4*a*c);

	if (d >= 0)
		return (1);
	else
		return (0);
}

void	raytrace(t_vars vars)
{
	int x;
	int y;
	posicao A;
	posicao B;
	esfera sp;

	if (0)
	{
		// A.x = 10.0;
		// A.y =  5.0;
		// A.z =  2.0;

		// B.x = 12.0;
		// B.y =  6.0;
		// B.z =  2.0;

		// if (cruza(A, B, sp))
		// 	printf("cruza\n");
		// else
		// 	printf("nao cruza");
	}
	else
	{
		A.x =    0.0;
		A.y =    0.0;
		A.z = (double)(-(LARGURA / 2));

		sp.pos.x =   0.0;
		sp.pos.y = -50.0;
		sp.pos.z =   0.0;
		sp.raio  =  90.0;

		y = 0;
		while (y < ALTURA)
		{
			x = 0;
			while (x < LARGURA)
			{
				B.x = (double)(x - (LARGURA / 2));
				B.y = (double)((ALTURA / 2) - y);
				B.z = (double)0.0;
				if (cruza(A, B, sp))
					mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFF0000);
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
	vars.win = mlx_new_window(vars.mlx, 640, 420, "minirt");
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
