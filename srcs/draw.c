#include "minirt.h"

t_cor	shade_hit(t_vars world, t_comps comps)
{
	t_cor		saida;
	int			shadowed;
	t_material	material;

	shadowed = is_shadowed(world, comps.over_point);
	material = choose_material(comps);
	saida = lighting(material,
			*((t_light *)world.lights->data),
			comps.over_point, comps.eyev,
			comps.normalv, shadowed);
	return (saida);
}

t_cor	color_at(t_vars vars, t_ray ray)
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
	if (hit.t != -42.0)
	{
		comps = prepare_computations(hit, ray);
		hit_cor = shade_hit(vars, comps);
		if (hit_cor.r > 1.0)
			hit_cor.r = 1.0;
		if (hit_cor.g > 1.0)
			hit_cor.g = 1.0;
		if (hit_cor.b > 1.0)
			hit_cor.b = 1.0;
	}
	return (hit_cor);
}

int	is_shadowed(t_vars world, t_tuple point)
{
	t_tuple	v;
	double	dist;
	t_tuple	direction;
	t_ray	r;
	t_list	*hits;
	t_hit	hit;

	v = tup_sub(((t_light *)world.lights->data)->position, point);
	dist = magnitude(v);
	direction = normalize(v);
	r = ray_create(point, direction);
	hits = intersect_world(world, r);
	hit = closest_hit(hits);
	if (hits != NULL)
		clear_list_all(hits);
	if (hit.t != -42.0 && hit.t < dist)
		return (1);
	else
		return (0);
}

t_tuple	pl_normal(t_plano plane)
{
	return (mat44_tuple_mul(mat44_inverse(plane.transform), vector(0, 1, 0)));
}

t_list	*ray_pl_intercection(t_ray ray, t_plano plane)
{
	t_list	*saida;
	t_hit	*hit;
	double	t;

	ray = ray_transform(ray, mat44_inverse(plane.transform));
	saida = NULL;
	if (absolute(ray.direction.y) < EPSILON)
		return (saida);
	t = -ray.origin.y / ray.direction.y;
	hit = (t_hit *)malloc(sizeof(t_hit));
	hit->obj.tipo = PLANE;
	hit->obj.pl = plane;
	hit->t = t;
	saida = list_init(hit);
	return (saida);
}

t_tuple	cy_normal(t_cylinder cylinder, t_tuple world_point)
{
	t_tuple	object_point;

	object_point = mat44_tuple_mul(mat44_inverse(cylinder.transform), world_point);
	return (vector(object_point.x, 0, object_point.z));
}

t_list	*ray_cy_intercection(t_ray ray, t_cylinder cylinder)
{
	t_list		*saida;
	t_hit		*hit;
	double		a;
	double		b;
	double		c;
	t_solution	solution;
	double		y0;

	ray = ray_transform(ray, mat44_inverse(cylinder.transform));
	saida = NULL;
	a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (equal(absolute(a), EPSILON))
		return (saida);
	b = (2 * ray.origin.x * ray.direction.x
		+ 2 * ray.origin.z * ray.direction.z);
	c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	solution = (solve_equation(a, b, c));
	if (solution.n >= 1 && solution.n <= 2)
	{
		y0 = ray.origin.y + solution.s1 * ray.direction.y;
		if (y0 < (cylinder.height / 2) && y0 > -(cylinder.height / 2))
		{
			hit = (t_hit *)malloc(sizeof(t_hit));
			hit->obj.tipo = CYLINDER;
			hit->obj.cy = cylinder;
			hit->t = solution.s1;
			saida = list_init(hit);
		}
	}
	if (solution.n == 2)
	{
		y0 = ray.origin.y + solution.s2 * ray.direction.y;
		if (y0 < (cylinder.height / 2) && y0 > -(cylinder.height / 2))
		{
			hit = (t_hit *)malloc(sizeof(t_hit));
			hit->obj.tipo = CYLINDER;
			hit->obj.cy = cylinder;
			hit->t = solution.s2;
			if (saida == NULL)
				saida = list_init(hit);
			else
				list_add(saida, hit);
		}
	}
	return (saida);
}

t_tuple	tr_normal(t_triangle triangle)
{
	t_tuple	e1;
	t_tuple	e2;
	t_tuple	normal;

	e1 = tup_sub(triangle.pos_b, triangle.pos_a);
	e2 = tup_sub(triangle.pos_c, triangle.pos_a);
	normal = normalize(cross(e1, e2));
	// normal = normalize(cross(e2, e1));
	return (normal);
}

t_list	*ray_tr_intercection(t_ray ray, t_triangle triangle)
{
	t_list	*saida;
	t_tuple	dir_cross_e2;
	t_tuple	p1_to_origin;
	double	det;
	double	f;
	double	u;
	t_tuple	e1;
	t_tuple	e2;
	t_tuple	origin_cross_e1;
	double	v;
	double	t;
	t_hit	*hit;

	saida = NULL;
	e1 = tup_sub(triangle.pos_b, triangle.pos_a);
	e2 = tup_sub(triangle.pos_c, triangle.pos_a);
	dir_cross_e2 = cross(ray.direction, e2);
	det = dot(e1, dir_cross_e2);
	if (absolute(det) < EPSILON)
		return (saida);
	f = 1.0 / det;
	p1_to_origin = tup_sub(ray.origin, triangle.pos_a);
	u = f * dot(p1_to_origin, dir_cross_e2);
	if (u < 0 || u > 1)
		return (saida);
	origin_cross_e1 = cross(p1_to_origin, e1);
	v = f * dot(ray.direction, origin_cross_e1);
	if (v < 0 || (u + v) > 1)
		return (saida);
	t = f * dot(e2, origin_cross_e1);
	hit = (t_hit *)malloc(sizeof(t_hit));
	hit->obj.tipo = TRIANGLE;
	hit->obj.tr = triangle;
	hit->t = t;
	saida = list_init(hit);
	return (saida);
}

void	put_pixel(t_img *img, int x, int y, t_cor cor)
{
	int	ratio;
	int	offset;

	ratio = (img->bits_per_pixel / img->bits_per_byte);
	offset = (x + (y * img->size_line / ratio));
	*((unsigned int *)img->data + offset) = cor_to_rgb(cor);
}

void	draw_main(t_vars vars, int x, int y, t_img img)
{
	t_ray		ray;
	t_cor		hit_cor;
	t_camera	camera;

	camera = setup_camera(vars);
	ray = ray_for_pixel(camera, x, y);
	hit_cor = color_at(vars, ray);
	put_pixel(&img, x, y, hit_cor);
	if (x == 3 && y == 5)
	{
		// say("rendering image...\n", DEB);
	}
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
