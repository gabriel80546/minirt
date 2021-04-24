#include "minirt.h"

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
