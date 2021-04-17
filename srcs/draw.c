
#include "minirt.h"

double	absolute(double n)
{
	if (n < 0.0)
		return -n;
	else
		return n;
}

int	equal(double a, double b)
{
	if (absolute(a - b) < EPSILON)
		return (1);
	else
		return (0);
}

t_tuple	mul_scalar(t_tuple input, double scalar)
{
	t_tuple	saida;

	saida = input;
	saida.x *= scalar;
	saida.y *= scalar;
	saida.z *= scalar;
	saida.w *= scalar;
	return (saida);
}

double	magnitude(t_tuple A)
{
	double a;
	double b;
	double c;
	double d;

	a = (A.x * A.x);
	b = (A.y * A.y);
	c = (A.z * A.z);
	d = (A.w * A.w);
	d = sqrt((a * a) + (b * b) + (c * c) + (d * d));
	return (d);
}


void	print_tuple(t_tuple tupla)
{
	printf("tupla.x = % 6.6lf\n", tupla.x);
	printf("tupla.y = % 6.6lf\n", tupla.y);
	printf("tupla.z = % 6.6lf\n", tupla.z);
	printf("tupla.w = % 6.6lf\n", tupla.w);
}

void	draw_main(t_vars vars, int x, int y, t_img img)
{
	t_tuple	teste;

	teste.x =  1;
	teste.y = -2;
	teste.z =  3;
	teste.w = -4;
	if (x == 3 && y == 5)
	{
		print_tuple(teste);
		printf("\n");
		print_tuple(mul_scalar(teste, 3.5));
		printf("\n");
		print_tuple(mul_scalar(teste, 0.5));
	}
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
