
#include "minirt.h"

t_list	*get_all_hits(t_vars vars, t_vec tela)
{
	t_list	*result;
	t_list	*temp_result;
	t_list	*temp_list;
	t_hit	*n;
	t_list	*hits;

	hits = NULL;
	while (vars.objs != NULL)
	{
		if (((t_objeto *)vars.objs->data)->tipo == SPHERE)
			result = cruzamento_sp_reta(vars.cam.pos, tela, ((t_objeto *)vars.objs->data)->sp);
		else if (((t_objeto *)vars.objs->data)->tipo == PLANE)
			result = cruzamento_pl_reta(vars.cam.pos, tela, ((t_objeto *)vars.objs->data)->pl);
		else if (((t_objeto *)vars.objs->data)->tipo == CYLINDER)
			result = cruzamento_cy_reta(vars.cam.pos, tela, ((t_objeto *)vars.objs->data)->cy);
		result = sanitize_cruz_two(vars.cam.pos, tela, result);
		if (result != NULL)
			result = first_item(result);
		temp_result = NULL;
		while (result != NULL)
		{
			n = (t_hit *)malloc(sizeof(t_hit));
			n->ponto = *((t_vec *)result->data);
			n->obj = *((t_objeto *)vars.objs->data);
			if (hits == NULL)
				hits = list_init(n);
			else
				list_add(hits, n);
			temp_result = result;
			result = result->next;
		}
		result = temp_result;
		if (result != NULL)
			clear_list_all(result);
		temp_list = vars.objs;
		vars.objs = vars.objs->next;
	}
	vars.objs = first_item(temp_list);
	return (hits);
}

t_hit	closest_hit(t_list *hits, t_vec pos)
{
	t_hit	saida;
	double	dist;
	double	smaller;
	int		first;
	t_list	*temp_hit;

	first = 0;
	smaller = 0.0;
	saida = (t_hit){0};
	if (hits != NULL)
		hits = first_item(hits);
	while (hits != NULL)
	{
		dist = distance(((t_hit *)hits->data)->ponto, pos);
		if (dist < smaller || first == 0)
		{
			first = 1;
			smaller = dist;
			saida = *((t_hit *)hits->data);
		}
		temp_hit = hits;
		hits = hits->next;
	}
	hits = first_item(temp_hit);
	return (saida);
}
