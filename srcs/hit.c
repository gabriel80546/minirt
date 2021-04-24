#include "minirt.h"

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
		if (((t_hit *)hits->data)->t > 0.0
			&& (((t_hit *)hits->data)->t < hit.t || hit_isfirst))
		{
			hit_isfirst = 0;
			hit = *((t_hit *)hits->data);
		}
		hits = hits->next;
	}
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
			hits_inter = ray_sp_intercection(
					ray, ((t_objeto *)vars.objs->data)->sp);
		else if (((t_objeto *)vars.objs->data)->tipo == PLANE)
			hits_inter = ray_pl_intercection(
					ray, ((t_objeto *)vars.objs->data)->pl);
		else if (((t_objeto *)vars.objs->data)->tipo == CYLINDER)
			hits_inter = ray_cy_intercection(
					ray, ((t_objeto *)vars.objs->data)->cy);
		else if (((t_objeto *)vars.objs->data)->tipo == TRIANGLE)
			hits_inter = ray_tr_intercection(
					ray, ((t_objeto *)vars.objs->data)->tr);
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
