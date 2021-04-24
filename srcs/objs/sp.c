#include "minirt.h"

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
