
#include "minirt.h"

int	can_light_see_this_hit(t_hit hit, t_vars vars, t_light light, t_debug deb)
{
	t_list		*result;
	t_list		*temp_result;
	t_list		*temp_list;
	t_vec		ponto_teste;
	double		smaller;
	double		dist;
	int			first;
	int			saida;

	if ((deb.x == deb.x_bugado && deb.y == deb.y_bugado) ||
		(deb.x == deb.x_iluminado && deb.y == deb.y_iluminado) ||
		(deb.x == deb.x_sombreado && deb.y == deb.x_sombreado))
		printf("%s(%s:%d): achei meu ponto\n", __FILE__, __func__, __LINE__);

	saida = 0;
	smaller = 0.0;
	ponto_teste = empty_vec();
	first = 0;
	while (vars.objs != NULL)
	{
		if (((t_objeto *)vars.objs->data)->tipo == SPHERE)
			result = cruzamento_sp_reta(hit.ponto, light.pos, ((t_objeto *)vars.objs->data)->sp);
		else if (((t_objeto *)vars.objs->data)->tipo == PLANE)
		{
			result = cruzamento_pl_reta(hit.ponto, light.pos, ((t_objeto *)vars.objs->data)->pl);
			// result = sanitize_cruz_two(vars.cam.pos, tela, result);
		}
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
	// if (meu_ponto == 1)
	// {
	// 	printf("%s(%s:%d): result = %p\n", __FILE__, __func__, __LINE__, result);
	// 	printf("%s(%s:%d): ponto_teste.x = % 6.6lf\n", __FILE__, __func__, __LINE__, ponto_teste.x);
	// 	printf("%s(%s:%d): ponto_teste.y = % 6.6lf\n", __FILE__, __func__, __LINE__, ponto_teste.y);
	// 	printf("%s(%s:%d): ponto_teste.z = % 6.6lf\n", __FILE__, __func__, __LINE__, ponto_teste.z);
	// 	printf("%s(%s:%d): hit.ponto.x = % 6.6lf\n", __FILE__, __func__, __LINE__, hit.ponto.x);
	// 	printf("%s(%s:%d): hit.ponto.y = % 6.6lf\n", __FILE__, __func__, __LINE__, hit.ponto.y);
	// 	printf("%s(%s:%d): hit.ponto.z = % 6.6lf\n", __FILE__, __func__, __LINE__, hit.ponto.z);
	// 	printf("%s(%s:%d): distance(light.pos, hit.ponto) = % 6.6lf\n", __FILE__, __func__, __LINE__, distance(light.pos, hit.ponto));
	// 	printf("%s(%s:%d): distance(light.pos, ponto_teste) + EPSILON = % 6.6lf\n", __FILE__, __func__, __LINE__, distance(light.pos, ponto_teste) + EPSILON);
	// }
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
