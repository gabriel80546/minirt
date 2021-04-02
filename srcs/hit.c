
#include "minirt.h"

t_list	*get_all_hits(void)
{

	return (NULL);
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
