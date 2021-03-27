
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

typedef struct camera {
	posicao pos;
} camera;

typedef struct esfera{
	posicao pos;
	double raio;
} esfera;

typedef struct tela{
	posicao tleft;
	posicao dright;
} tela;


double *expand(double a, double b)
{
	double *saida;

	saida = (double *)malloc(sizeof(double) * 3);
	saida[0] = (a * a);
	saida[1] = (2 * a * b);
	saida[2] = (b * b);
	return (saida);
}

int	cruza(posicao A, posicao B, esfera C)
{
	double *exptemp1;
	double *exptemp2;
	double *exptemp3;
	exptemp1 = expand(A.x - C.pos.x, B.x - A.x - C.pos.x);
	exptemp2 = expand(A.y - C.pos.y, B.y - A.y - C.pos.y);
	exptemp3 = expand(A.z - C.pos.z, B.z - A.z - C.pos.z);
	double a = exptemp1[2] + exptemp2[2] + exptemp3[2];
	double b = exptemp1[1] + exptemp2[1] + exptemp3[1];
	double c = exptemp1[0] + exptemp2[0] + exptemp3[0] - (C.raio * C.raio);
	double d = (b*b) + (-4*a*c);
	free(exptemp1);
	free(exptemp2);
	free(exptemp3);
	if (d >= 0)
		return (1);
	else
		return (0);
}

void	raytrace(t_vars vars)
{
	int i;
	int j;
	int x;
	int y;
	camera cam;
	posicao A;
	posicao B;
	esfera sp;
	tela screen;
	double d_raio;

	d_raio = 10.0;

	cam.pos.x =  0.0;
	cam.pos.y =  0.0;
	cam.pos.z = -2.0;

	sp.pos.x = 0.0;
	sp.pos.y = 0.0;
	sp.pos.z = 2.0;
	sp.raio  = 2.0;

	screen.tleft.x = -2.0;
	screen.tleft.y =  2.0;
	screen.tleft.z =  0.0;

	screen.dright.x =  2.0;
	screen.dright.y = -2.0;
	screen.dright.z =  0.0;

	// A.x = 10.0;
	// A.y =  5.0;
	// A.z =  2.0;

	// B.x = 12.0;
	// B.y =  6.0;
	// B.z =  2.0;

	A.x =    0.0;
	A.y =    0.0;
	A.z = (double)(-(LARGURA / 2));

	sp.pos.x = 0.0;
	sp.pos.y = 50.0;
	sp.pos.z = 0.0;
	sp.raio  = 90.0;

	y = 0;
	while (y < ALTURA)
	{
		x = 0;
		while (x < LARGURA)
		{
			B.x = (double)(x - (LARGURA / 2));
			B.y = (double)(y - (ALTURA / 2));
			B.z = (double)0.0;
			if (cruza(A, B, sp))
				mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}


void draw_squares_test(void *mlx_ptr, void *win_ptr)
{
	int i;
	int j;
	int x;
	int y;
	int size;
	int c_i;
	int	colors[] = {
					0x0FCBD6, 0x0F5CC4, 0x4DD410, 0x7C1B67, 0xEC4F46,
					0x0B401E, 0xF12421, 0x32009D, 0x28C41B, 0x5FF42B,
					0x6DB19B, 0xC1906A, 0x491405, 0x1211B6, 0x8B7884,
					0xC95ECF, 0x39B283, 0x2DED00, 0x6C81E1, 0xD00583,
					0xA29089, 0x1131ED, 0x6C6167, 0xF33EC8, 0xD4BE23,
					0xBCEE46, 0x38A454, 0x412695, 0x1BC633, 0xE406DE,
					0xAAC3F7, 0xA9B3A3, 0x754601, 0x4311E0, 0xCB0322,
					0xAC683C, 0x7CEF63, 0x7FD6AD, 0x09B6A7, 0x7E20C7,
					0xD0E2E7, 0xB2CE15, 0x2572F1, 0xFC1B3F, 0x9E0BFF,
					0xCA33EE, 0x8A71E8, 0xE4F8E1, 0xD1C2DA, 0xF4AE6A,
					0xE0CCC6, 0x08FCC9, 0xA2B328, 0x1A849F, 0x16DEF2,
					0x460A3F, 0x8F6BFC, 0x82A954, 0x7E457B, 0x3205FB,
					0xE1B0B2, 0x9A98F6, 0xFC23F4, 0x965BF8, 0x6282E8,
					0xD0A85D, 0x48095C, 0xF92C1D, 0x98B2EC, 0x7C8B4F,
					0x26749B, 0xDB1BB3, 0x951EF8, 0x6E23DA, 0xF8891D,
					0xB75940, 0x27C54C, 0xACD9FF, 0xEF779E, 0x9B9554,
					0xA8A400, 0xC0C112, 0x40AB12, 0xF73F16, 0x03302C,
					0xCC12A5, 0xD6C787, 0xE234B6, 0x598291, 0x2E489B,
					0xCF82D9, 0x33B8C8, 0x074496, 0x73D3B2, 0x072846,
					0x351DEA, 0x92D33A, 0x57A8FB, 0x6A9C74, 0x841AB1,
					0xFF0000, 0x00FF00, 0x0000FF,
					42 };

	c_i = 0;
	x = 10;
	y = 10;
	size = 40;
	while (colors[c_i] != 42)
	{
		i = 0;
		while(i < size)
		{
			j = 0;
			while(j < size)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, colors[c_i]);
				j++;
			}
			i++;
		}
		x += size;
		if (x > 580)
		{
			x = 10;
			y += size;
		}
		c_i++;
	}
}

void	*param;

int key_hook(int keycode, t_vars *vars)
{
	int *array;
	int teste;
	array = (int *)calloc(sizeof(int), 1);
	if (keycode == 65307)
	{
		printf("fechando... :)\n");
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);

		teste = array[0];
		free(vars->mlx);
		free(array);
		exit(1);
	}
	// printf("vars.mlx = %p, vars.win = %p\n", vars->mlx, vars->win);
	// printf("no events; keycode = %12d; param = %p\n", keycode, vars);
	free(array);
	return (0);
}


int	main(void)
{
	int (*teste)(int, t_vars*);
	t_vars      vars;
	// int fd;
	// char *linha;
	// int i;
	// int retorno;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 420, "minirt");
	// if (ray == 0)
	// 	draw_squares_test(vars.mlx, vars.win);
	// else if (ray == 1)
	raytrace(vars);

/*
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
