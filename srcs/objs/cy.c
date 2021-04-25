#include "minirt.h"

t_tuple	cy_normal(t_cylinder cylinder, t_tuple world_point)
{
	t_tuple	object_point;

	object_point = mat44_tuple_mul(
			mat44_inverse(cylinder.transform), world_point);
	return (normalize(vector(object_point.x, 0, object_point.z)));
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
			if (hit != NULL)
			{
				hit->obj.tipo = CYLINDER;
				hit->obj.cy = cylinder;
				hit->t = solution.s1;
				saida = list_init(hit);
			}
		}
	}
	if (solution.n == 2)
	{
		y0 = ray.origin.y + solution.s2 * ray.direction.y;
		if (y0 < (cylinder.height / 2) && y0 > -(cylinder.height / 2))
		{
			hit = (t_hit *)malloc(sizeof(t_hit));
			if (hit != NULL)
			{
				hit->obj.tipo = CYLINDER;
				hit->obj.cy = cylinder;
				hit->t = solution.s2;
				if (saida == NULL)
					saida = list_init(hit);
				else
					list_add(saida, hit);
			}
		}
	}
	return (saida);
}
