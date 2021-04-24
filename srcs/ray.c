#include "minirt.h"

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
