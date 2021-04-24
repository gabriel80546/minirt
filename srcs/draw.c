#include "minirt.h"

void	print_tuple(t_tuple tupla, char *file, const char *func, int line)
{
	say("tupla.x = % 6.6lf\n", file, func, line, tupla.x);
	say("tupla.y = % 6.6lf\n", file, func, line, tupla.y);
	say("tupla.z = % 6.6lf\n", file, func, line, tupla.z);
	say("tupla.w = % 6.6lf\n", file, func, line, tupla.w);
}

void	print_mat44(t_mat44 mat, char *file, const char *func, int line)
{
	say("/***********************************************\\\n", file, func, line);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[0], mat.m[1], mat.m[2], mat.m[3]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[4], mat.m[5], mat.m[6], mat.m[7]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[8], mat.m[9], mat.m[10], mat.m[11]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[12], mat.m[13], mat.m[14], mat.m[15]);
	say("\\***********************************************/\n", file, func, line);
}

void	print_mat22(t_mat22 mat, char *file, const char *func, int line)
{
	say("/***********************\\\n", file, func, line);
	say("| % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[0], mat.m[1]);
	say("| % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[2], mat.m[3]);
	say("\\***********************/\n", file, func, line);
}

void	print_mat33(t_mat33 mat, char *file, const char *func, int line)
{
	say("/***********************************************\\\n", file, func, line);
	say("| % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[0], mat.m[1], mat.m[2]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[3], mat.m[4], mat.m[5]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[6], mat.m[7], mat.m[8]);
	say("\\***********************************************/\n", file, func, line);
}

void	print_mat4_cel(t_mat44 mat, int row, int col)
{
	say("% 6.6lf", DEB, mat.m[mat44_coor(row, col)]);
}

void	print_mat3_cel(t_mat33 mat, int row, int col)
{
	say("% 6.6lf", DEB, mat.m[(3 * row) + col]);
}

void	print_mat2_cel(t_mat22 mat, int row, int col)
{
	say("% 6.6lf", DEB, mat.m[(2 * row) + col]);
}

t_ray	ray_create(t_tuple origin, t_tuple direction)
{
	t_ray	saida;

	saida.origin = origin;
	saida.direction = direction;
	return (saida);
}

t_tuple	ray_position(t_ray ray, double dist)
{
	t_tuple	saida;

	saida = tup_add(ray.origin, mul_scalar(ray.direction, dist));
	return (saida);
}

t_ray	ray_transform(t_ray ray, t_mat44 matrix)
{
	t_ray	saida;

	saida = ray;
	saida.origin = mat44_tuple_mul(matrix, saida.origin);
	saida.direction = mat44_tuple_mul(matrix, saida.direction);
	return (saida);
}

t_list	*ray_sp_intercection(t_ray ray, t_esfera sp)
{
	t_tuple		sphere_to_ray;
	double		a;
	double		b;
	double		c;
	t_list		*saida;
	t_hit		*hit;
	t_solution	solution;

	saida = NULL;
	ray = ray_transform(ray, mat44_inverse(sp.transform));
	sphere_to_ray = tup_sub(ray.origin, point(0, 0, 0));
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	solution = (solve_equation(a, b, c));
	if (solution.n >= 1 && solution.n <= 2)
	{
		hit = (t_hit *)malloc(sizeof(t_hit));
		hit->obj.tipo = SPHERE;
		hit->obj.sp = sp;
		hit->t = solution.s1;
		saida = list_init(hit);
	}
	if (solution.n == 2)
	{
		hit = (t_hit *)malloc(sizeof(t_hit));
		hit->obj.tipo = SPHERE;
		hit->obj.sp = sp;
		hit->t = solution.s2;
		list_add(saida, hit);
	}
	return (saida);
}

t_tuple	sp_normal(t_esfera sphere, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mat44_tuple_mul(mat44_inverse(sphere.transform), world_point);
	object_normal = tup_sub(object_point, point(0.0, 0.0, 0.0));
	world_normal = mat44_tuple_mul(mat44_transpose(mat44_inverse(sphere.transform)), object_normal);
	world_normal.w = 0.0;
	return (normalize(world_normal));
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (tup_sub(in, mul_scalar(normal, 2 * dot(in, normal))));
}

t_cor	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_cor	effective_color;
	t_cor	ambient;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	light_dot_normal;
	t_cor	diffuse;
	t_cor	specular;
	double	factor;

	effective_color = color_mul(material.color, light.cor);
	lightv = normalize(tup_sub(light.position, point));
	ambient = color_mul_scalar(effective_color, material.ambient);
	light_dot_normal = dot(lightv, normalv);
	if (light_dot_normal < 0.0)
	{
		diffuse = color(0.0, 0.0, 0.0);
		specular = color(0.0, 0.0, 0.0);
	}
	else
	{
		diffuse = color_mul_scalar(effective_color, material.diffuse * light_dot_normal);
		reflectv = reflect(mul_scalar(lightv, -1.0), normalv);
		reflect_dot_eye = dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = color(0.0, 0.0, 0.0);
		else
		{
			factor = pow(reflect_dot_eye, material.shininess);
			specular = color_mul_scalar(light.cor, material.specular * factor);
		}
	}
	return (color_add(color_add(ambient, diffuse), specular));
}

t_cor	lighting_new(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv, int in_shadow)
{
	t_cor	effective_color;
	t_cor	ambient;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	light_dot_normal;
	t_cor	diffuse;
	t_cor	specular;
	double	factor;

	effective_color = color_mul(material.color, light.cor);
	lightv = normalize(tup_sub(light.position, point));
	ambient = color_mul_scalar(effective_color, material.ambient);
	light_dot_normal = dot(lightv, normalv);
	if (light_dot_normal < 0.0)
	{
		diffuse = color(0.0, 0.0, 0.0);
		specular = color(0.0, 0.0, 0.0);
	}
	else
	{
		diffuse = color_mul_scalar(effective_color, material.diffuse * light_dot_normal);
		reflectv = reflect(mul_scalar(lightv, -1.0), normalv);
		reflect_dot_eye = dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = color(0.0, 0.0, 0.0);
		else
		{
			factor = pow(reflect_dot_eye, material.shininess);
			specular = color_mul_scalar(light.cor, material.specular * factor);
		}
	}
	if (in_shadow == 1)
		return (ambient);
	else
		return (color_add(color_add(ambient, diffuse), specular));
}

t_hit	closest_hit(t_list *hits)
{
	t_hit	hit;
	t_list	*temp_list;
	int		hit_isfirst;

	hit_isfirst = 1;
	hit.t = -42.0;
	temp_list = NULL;
	if (hits != NULL)
		hits = first_item(hits);
	while (hits != NULL)
	{
		if (((t_hit *)hits->data)->t > 0.0 && (((t_hit *)hits->data)->t < hit.t || hit_isfirst))
		{
			hit_isfirst = 0;
			hit = *((t_hit *)hits->data);
		}
		temp_list = hits;
		hits = hits->next;
	}
	if (temp_list != NULL)
		hits = temp_list;
	return (hit);
}

t_list	*intersect_world(t_vars vars, t_ray ray)
{
	t_list	*hits_inter;
	t_list	*hits;
	t_list	*temp_list;
	t_list	*temp_temp_list;

	if (vars.objs != NULL)
		vars.objs = first_item(vars.objs);
	temp_list = NULL;
	hits = NULL;
	while (vars.objs != NULL)
	{
		hits_inter = NULL;
		ray.direction = normalize(ray.direction);
		if (((t_objeto *)vars.objs->data)->tipo == SPHERE)
			hits_inter = ray_sp_intercection(ray, ((t_objeto *)vars.objs->data)->sp);
		else if (((t_objeto *)vars.objs->data)->tipo == PLANE)
			hits_inter = ray_pl_intercection(ray, ((t_objeto *)vars.objs->data)->pl);
		else if (((t_objeto *)vars.objs->data)->tipo == CYLINDER)
			hits_inter = ray_cy_intercection(ray, ((t_objeto *)vars.objs->data)->cy);
		else if (((t_objeto *)vars.objs->data)->tipo == TRIANGLE)
			hits_inter = ray_tr_intercection(ray, ((t_objeto *)vars.objs->data)->tr);
		temp_temp_list = NULL;
		while (hits_inter != NULL)
		{
			if (hits == NULL)
				hits = list_init(hits_inter->data);
			else
				list_add(hits, hits_inter->data);
			temp_temp_list = hits_inter;
			hits_inter = hits_inter->next;
		}
		if (temp_temp_list != NULL)
			hits_inter = temp_temp_list;
		clear_list(hits_inter);
		temp_list = vars.objs;
		vars.objs = vars.objs->next;
	}
	if (temp_list != NULL)
		vars.objs = temp_list;
	return (hits);
}

t_comps	prepare_computations(t_hit	intersection, t_ray ray)
{
	t_comps	comps;

	comps = (t_comps){0};
	comps.t = intersection.t;
	comps.object = intersection.obj;
	comps.point = ray_position(ray, comps.t);
	comps.eyev = mul_scalar(ray.direction, -1.0);
	if (comps.object.tipo == SPHERE)
		comps.normalv = sp_normal(comps.object.sp, comps.point);
	else if (comps.object.tipo == PLANE)
		comps.normalv = pl_normal(comps.object.pl);
	else if (comps.object.tipo == CYLINDER)
		comps.normalv = cy_normal(comps.object.cy, comps.point);
	else if (comps.object.tipo == TRIANGLE)
		comps.normalv = tr_normal(comps.object.tr);
	else
		comps.normalv = vector(0, 1, 0);
	comps.over_point = tup_add(comps.point, mul_scalar(comps.normalv, EPSILON));
	if (dot(comps.normalv, comps.eyev) < 0.0)
	{
		comps.inside = 1;
		comps.normalv = mul_scalar(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	return (comps);
}

t_material	choose_material(t_comps comps)
{
	t_material	saida;

	saida = (t_material){0};
	if (comps.object.tipo == SPHERE)
		saida = comps.object.sp.material;
	else if (comps.object.tipo == PLANE)
		saida = comps.object.pl.material;
	else if (comps.object.tipo == CYLINDER)
		saida = comps.object.cy.material;
	else if (comps.object.tipo == TRIANGLE)
		saida = comps.object.tr.material;
	return (saida);
}

t_cor	shade_hit(t_vars world, t_comps comps)
{
	t_cor		saida;
	int			shadowed;
	t_material	material;

	shadowed = is_shadowed(world, comps.over_point);
	material = choose_material(comps);
	saida = lighting_new(material,
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

t_mat44	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_mat44	saida;
	t_tuple	forward;
	t_tuple	upn;
	t_tuple	left;
	t_tuple	true_up;
	t_mat44	orientation;

	forward = normalize(tup_sub(to, from));
	upn = normalize(up);
	left = cross(forward, upn);
	true_up = cross(left, forward);
	orientation.m[0] = left.x; orientation.m[1] = left.y; orientation.m[2] = left.z; orientation.m[3] = 0;
	orientation.m[4] = true_up.x; orientation.m[5] = true_up.y; orientation.m[6] = true_up.z; orientation.m[7] = 0;
	orientation.m[8] = -forward.x; orientation.m[9] = -forward.y; orientation.m[10] = -forward.z; orientation.m[11] = 0;
	orientation.m[12] = 0; orientation.m[13] = 0; orientation.m[14] = 0; orientation.m[15] = 1;
	saida = mat44_mul(orientation, mat44_translate(-from.x, -from.y, -from.z));
	return (saida);
}

t_camera	setup_camera(t_vars vars)
{
	t_camera	camera;
	double		half_view;
	double		aspect;

	camera.hsize = (double)vars.largura;
	camera.vsize = (double)vars.altura;
	camera.field_of_view = (vars.cam.fov / 180.0) * (PI);
	camera.transform = vars.cam.transform;
	half_view = tan(camera.field_of_view / 2);
	aspect = camera.hsize / camera.vsize;
	if (aspect >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / camera.hsize;
	return (camera);
}

t_ray	ray_for_pixel(t_camera camera, int px, int py)
{
	t_ray	ray;
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

	xoffset = (px + 0.5) * camera.pixel_size;
	yoffset = (py + 0.5) * camera.pixel_size;
	world_x = camera.half_width - xoffset;
	world_y = camera.half_height - yoffset;
	pixel = mat44_tuple_mul(mat44_inverse(camera.transform), point(world_x, world_y, -1));
	origin = mat44_tuple_mul(mat44_inverse(camera.transform), point(0, 0, 0));
	direction = normalize(tup_sub(pixel, origin));
	ray = ray_create(origin, direction);
	return (ray);
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

t_tuple	sp_normal_new(t_esfera sphere, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mat44_tuple_mul(mat44_inverse(sphere.transform), world_point);
	object_normal = tup_sub(object_point, point(0.0, 0.0, 0.0));
	world_normal = mat44_tuple_mul(mat44_transpose(mat44_inverse(sphere.transform)), object_normal);
	world_normal.w = 0.0;
	return (normalize(world_normal));
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
