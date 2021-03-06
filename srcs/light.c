#include "minirt.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return (tup_sub(in, mul_scalar(normal, 2 * dot(in, normal))));
}

t_cor	lighting(t_material material, t_light light,
		t_tuple point, t_tuple eyev,
		t_tuple normalv, int in_shadow, t_debug deb)
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
		diffuse = color_mul_scalar(
				effective_color, material.diffuse * light_dot_normal);
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
	if ((deb.x == deb.x_bugado && deb.y == deb.y_bugado)
		|| (deb.x == deb.x_iluminado && deb.y == deb.y_iluminado))
	{
		if (deb.x == deb.x_bugado && deb.y == deb.y_bugado)
			say("ponto bugado =>\n", DEB);
		else
			say("ponto normal =>\n", DEB);
		say("in_shadow = %i\n", DEB, in_shadow);
		say("ambient.r = % 6.6lf; ambient.g = % 6.6lf; ambient.b = % 6.6lf\n",
			DEB, ambient.r, ambient.g, ambient.b);
		say("diffuse.r = % 6.6lf; diffuse.g = % 6.6lf; diffuse.b = % 6.6lf\n",
			DEB, diffuse.r, diffuse.g, diffuse.b);
		say("ambient.r = % 6.6lf; ambient.g = % 6.6lf; ambient.b = % 6.6lf\n",
			DEB, specular.r, specular.g, specular.b);
		say("deb.x = %i deb.y = %i\n", DEB, deb.x, deb.y);
	}
	if (in_shadow == 1)
		return (ambient);
	else
		return (color_add(color_add(ambient, diffuse), specular));
}

t_cor	shade_hit(t_vars world, t_comps comps, t_debug deb)
{
	t_cor		saida;
	int			shadowed;
	t_material	material;

	shadowed = is_shadowed(world, comps.over_point);
	material = choose_material(comps);
	saida = lighting(material,
			*((t_light *)world.lights->data),
			comps.over_point, comps.eyev,
			comps.normalv, shadowed, deb);
	return (saida);
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
	if (!equal(hit.t, -42.0) && hit.t < dist)
		return (1);
	else
		return (0);
}
