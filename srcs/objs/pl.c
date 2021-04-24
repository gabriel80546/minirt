#include "minirt.h"

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
