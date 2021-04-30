#include "minirt.h"

t_cor	color_at(t_vars vars, t_ray ray, t_debug deb)
{
	t_list	*hits;
	t_cor	hit_cor;
	t_hit	hit;
	t_comps	comps;

	hit_cor = color(0.0, 0.0, 0.0);
	hits = intersect_world(vars, ray);
	hit = closest_hit(hits);
	if (hits != NULL)
		clear_list_all(hits);
	if (!equal(hit.t, -42.0))
	{
		comps = prepare_computations(hit, ray);
		hit_cor = shade_hit(vars, comps, deb);
	}
	return (hit_cor);
}

void	put_pixel(t_img *img, int x, int y, t_cor cor)
{
	int				ratio;
	int				offset;
	unsigned int	*ptr;

	ptr = (unsigned int *)img->data;
	ratio = (img->bits_per_pixel / img->bits_per_byte);
	offset = (x + (y * img->size_line / ratio));
	*(ptr + offset) = (unsigned int)cor_to_rgb(cor);
}

void	draw_main(t_vars vars, int x, int y, t_img img, t_debug deb)
{
	t_ray		ray;
	t_cor		hit_cor;
	t_camera	camera;

	camera = setup_camera(vars);
	ray = ray_for_pixel(camera, x, y);
	hit_cor = color_at(vars, ray, deb);
	if ((deb.x == deb.x_bugado && deb.y == deb.y_bugado)
		|| (deb.x == deb.x_iluminado && deb.y == deb.y_iluminado))
	{
		hit_cor.r = 1.0;
		hit_cor.g = 0.0;
		hit_cor.b = 0.0;
	}
	put_pixel(&img, x, y, hit_cor);
}

void	draw(t_vars vars)
{
	int			x;
	int			y;
	t_img		img;
	t_debug		deb;
	static int	i = 0;

	deb.x_bugado = 220;
	deb.y_bugado = 340;
	deb.x_iluminado = 120;
	deb.y_iluminado = 280;
	img.ptr = mlx_new_image(vars.mlx, vars.largura, vars.altura);
	img.data = mlx_get_data_addr(img.ptr,
			&img.bits_per_pixel, &img.size_line, &img.endian);
	img.bits_per_byte = 8;
	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			deb.x = x;
			deb.y = y;
			draw_main(vars, x, y, img, deb);
			x++;
		}
		y++;
	}
	say("camera[%i]\n", DEB, i);
	i++;
	mlx_put_image_to_window(vars.mlx, vars.win, img.ptr, 0, 0);
	mlx_destroy_image(vars.mlx, img.ptr);
}
