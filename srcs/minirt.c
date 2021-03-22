
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

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



typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int key_hook(int keycode, t_vars *vars)
{
	int *array;
	int teste;
	array = (int *)calloc(sizeof(int), 1);
	if (keycode == 65507)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);

		teste = array[0];
		free(vars->mlx);
		//vars->mlx = NULL;
		free(array);
		exit(1);
	}
	printf("vars.mlx = %p, vars.win = %p\n", vars->mlx, vars->win);
	printf("no events; keycode = %12d; param = %p\n", keycode, vars);
	free(array);
	return (0);
}


int	main(void)
{
	int (*teste)(int, t_vars*);
	t_vars      vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 420, "minirt");
	draw_squares_test(vars.mlx, vars.win);

	printf("vars.mlx = %p, vars.win = %p\n", vars.mlx, vars.win);

	teste = key_hook;
	mlx_key_hook(vars.win, teste, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
