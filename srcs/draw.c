
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

t_tuple	vector(double x, double y, double z)
{
	t_tuple	saida;

	saida.x = x;
	saida.y = y;
	saida.z = z;
	saida.w = 0.0;
	return (saida);
}

t_tuple	point(double x, double y, double z)
{
	t_tuple	saida;

	saida.x = x;
	saida.y = y;
	saida.z = z;
	saida.w = 1.0;
	return (saida);
}

t_tuple	tupla(double x, double y, double z, double w)
{
	t_tuple	saida;

	saida.x = x;
	saida.y = y;
	saida.z = z;
	saida.w = w;
	return (saida);
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

double	magnitude(t_tuple tupla)
{
	double a;
	double b;
	double c;
	double d;

	a = (tupla.x * tupla.x);
	b = (tupla.y * tupla.y);
	c = (tupla.z * tupla.z);
	d = (tupla.w * tupla.w);
	d = sqrt(a + b + c + d);
	return (d);
}

t_tuple	normalize(t_tuple tupla)
{
	t_tuple	saida;
	double	mag;

	saida = tupla;
	mag = magnitude(saida);
	saida.x /= mag;
	saida.y /= mag;
	saida.z /= mag;
	saida.w /= mag;
	return (saida);
}

double	dot(t_tuple	a, t_tuple b)
{
	double	saida;

	saida = 0.0;
	saida += a.x * b.x;
	saida += a.y * b.y;
	saida += a.z * b.z;
	saida += a.w * b.w;
	return (saida);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	t_tuple	saida;
	double	x;
	double	y;
	double	z;

	x = ((a.y * b.z) - (a.z * b.y));
	y = ((a.z * b.x) - (a.x * b.z));
	z = ((a.x * b.y) - (a.y * b.x));
	saida = vector(x, y, z);
	return (saida);
}

t_tuple		tup_add(t_tuple a, t_tuple b)
{
	t_tuple	saida;

	saida.x = a.x + b.x;
	saida.y = a.y + b.y;
	saida.z = a.z + b.z;
	saida.w = a.w + b.w;
	return (saida);
}

t_tuple		tup_sub(t_tuple a, t_tuple b)
{
	t_tuple	saida;

	saida.x = a.x - b.x;
	saida.y = a.y - b.y;
	saida.z = a.z - b.z;
	saida.w = a.w - b.w;
	return (saida);
}

typedef struct	s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}				t_projectile;


t_projectile	projectile(t_tuple position, t_tuple velocity)
{
	t_projectile	saida;

	saida.position = position;
	saida.velocity = velocity;
	return (saida);
}

t_projectile	tick(t_tuple gravity, t_tuple wind, t_projectile proj)
{
	t_tuple	position;
	t_tuple	velocity;

	position = tup_add(proj.position, proj.velocity);
	velocity = tup_add(proj.velocity, tup_add(gravity, wind));
	return projectile(position, velocity);
}

t_cor	color(double r, double g, double b)
{
	t_cor saida;

	saida.r = r;
	saida.g = g;
	saida.b = b;
	return (saida);
}

t_cor	color_add(t_cor a, t_cor b)
{
	t_cor	saida;

	saida.r = a.r + b.r;
	saida.g = a.g + b.g;
	saida.b = a.b + b.b;
	return (saida);
}

t_cor	color_sub(t_cor a, t_cor b)
{
	t_cor	saida;

	saida.r = a.r + b.r;
	saida.g = a.g + b.g;
	saida.b = a.b + b.b;
	return (saida);
}

t_cor	color_mul_scalar(t_cor cor, double scalar)
{
	t_cor	saida;

	saida = cor;
	saida.r *= scalar;
	saida.g *= scalar;
	saida.b *= scalar;
	return (saida);
}

t_cor color_mul(t_cor a, t_cor b)
{
	t_cor	saida;

	saida.r = a.r * b.r;
	saida.g = a.g * b.g;
	saida.b = a.b * b.b;
	return (saida);
}

int	cor_to_rgb(t_cor cor)
{
	int saida;
	int r;
	int g;
	int b;

	r = (int)(cor.r * 255);
	g = (int)(cor.g * 255);
	b = (int)(cor.b * 255);
	saida = (r << 16 | g << 8 | b);
	return (saida);
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
	t_projectile p;
	t_tuple	gravity;
	t_tuple	wind;
	int	xis;
	int yis;

	p = projectile(point(0, 1, 0), mul_scalar(normalize(vector(1, 1.8, 0)), 11.25));
	gravity = vector(0, -0.1, 0);
	wind = vector(-0.01, 0, 0);

	if (x == 3 && y == 5)
	{
		int count = 0;
		while (p.position.y > 0)
		{
			printf("count = %d\n", count);
			printf("p.position => \n");
			print_tuple(p.position);
			p = tick(gravity, wind, p);
			printf("p.position => \n");
			print_tuple(p.position);
			xis = ((int)p.position.x);
			yis = ((int)p.position.y);
			printf("x = %d\n", xis);
			printf("y = %d\n", yis);
			if (yis >= 0)
				*((unsigned int *)img.data + (xis + ((vars.altura - yis) * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = cor_to_rgb(color(1.0, 0.0, 0.0));
			count++;
		}
		printf("precisou de %i ticks para bater no chao\n", count);
	}
	// if (x + y > (vars.largura / 2))
	// 	*((unsigned int *)img.data + (x + (y * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = 0xFF0000;
	// else
	// 	*((unsigned int *)img.data + (x + (y * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = cor_to_rgb(color(0.0, 1.0, 0.0));
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
