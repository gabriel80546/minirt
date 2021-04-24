#include "minirt.h"

t_tuple	tr_normal(t_triangle triangle)
{
	t_tuple	e1;
	t_tuple	e2;
	t_tuple	normal;

	e1 = tup_sub(triangle.pos_b, triangle.pos_a);
	e2 = tup_sub(triangle.pos_c, triangle.pos_a);
	// normal = normalize(cross(e1, e2));
	normal = normalize(cross(e2, e1));
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
	if (hit != NULL)
	{
		hit->obj.tipo = TRIANGLE;
		hit->obj.tr = triangle;
		hit->t = t;
		saida = list_init(hit);
	}
	return (saida);
}
