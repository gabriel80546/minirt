
#include "minirt.h"

void	draw_main(t_vars vars, int x, int y, t_img img)
{
	if (x + y > (vars.largura / 2))
		*((unsigned int *)img.data + (x + (y * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = 0xFF0000;
	else
		*((unsigned int *)img.data + (x + (y * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = 0x00FF00;
}

void	draw(t_vars vars)
{
	int		x;
	int		y;
	t_img	img;

	img.ptr = mlx_new_image(vars.mlx, vars.largura, vars.altura);
	img.data = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	img.bits_per_byte = 8;

	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			draw_main(vars, x, y, img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.ptr, 0, 0);
	mlx_destroy_image(vars.mlx, img.ptr);
}
