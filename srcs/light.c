
#include "minirt.h"

int	can_light_see_this_hit_one_obj(t_hit hit, /* t_vars vars, */ t_list *result, t_light light)
{
	t_list	*temp_result;

	while (result != NULL)
	{
		if (distance(light.pos, *(t_vec *)result->data) + EPSILON <
			distance(light.pos, hit.ponto))
			return (0);
		temp_result = result;
		result = result->next;
	}
	result = temp_result;
	return (1);
}

int	can_light_see_this_hit(t_hit hit, t_vars vars, t_light light)
{
	t_list		*result;
	t_list		*temp_result;
	t_list		*temp_list;
	t_vec		ponto_teste;
	double		smaller;
	double		dist;
	int			first;
	int			saida;

	saida = 0;
	smaller = 0.0;
	ponto_teste = empty_vec();
	first = 0;
	while (vars.objs != NULL)
	{
		result = cruzamento_sp_reta(hit.ponto, light.pos, *((t_esfera *)vars.objs->data));
		if (result != NULL)
			result = first_item(result);
		temp_result = NULL;
		while (result != NULL)
		{
			dist = distance(*((t_vec *)result->data), light.pos);
			if (dist < smaller || first == 0)
			{
				first = 1;
				smaller = dist;
				ponto_teste = *((t_vec *)result->data);
			}
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
	if (distance(light.pos, ponto_teste) + EPSILON <
		distance(light.pos, hit.ponto))
		saida = 0;
	else
		saida = 1;
	return (saida);
}

int	compute_color(double intensity, int input)
{
	int			temp;
	double		temp6;
	double		temp7;
	double		temp8;

	if (intensity < 0.1)
		intensity = 0.1;

	temp6 = (input & 0x0000FF) >> 0;
	temp7 = (input & 0x00FF00) >> 8;
	temp8 = (input & 0xFF0000) >> 16;
	temp6 = ((temp6 / 255) * intensity) * 255;
	temp7 = ((temp7 / 255) * intensity) * 255;
	temp8 = ((temp8 / 255) * intensity) * 255;
	temp = ((int)temp8 << 16 | (int)temp7 << 8 | (int)temp6);
	return (temp);
}
