
#include "mlx.h"

void draw_squares_test(void *mlx_ptr, void *win_ptr)
{
	int i;
	int j;
	int x;
	int y;
	int size;
	int c_i;
	int	colors[] = { 0x0000FF, 0x00FF00, 0x00FFFF, 0xFF00FF,
					0xFFFF00, 0xFFFFFF, 0x00007F, 0x007F00,
					0x007F7F, 0x7F007F, 0x7F7F00, 0x7F7F7F, 42 };

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
		if (x > 400)
		{
			x = 10;
			y += size;
		}
		c_i++;
	}
}

int	main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 420, "minirt");
	draw_squares_test(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
