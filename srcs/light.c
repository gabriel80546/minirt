
#include "minirt.h"

int	can_light_see_this_hit_one_obj(t_hit hit, t_vars vars, t_list *result)
{
	t_list	*temp_result;
	// int		flag;

	// flag = 1;
	while (result != NULL)
	{
		if (distance(vars.light.pos, *(t_vec *)result->data) + EPSILON <
			distance(vars.light.pos, hit.ponto))
			return (0);
		temp_result = result;
		result = result->next;
	}
	result = temp_result;
	// if (result != NULL)
	// 	clear_list_all(result);
	return (1);
}

int	can_light_see_this_hit(t_hit hit, t_vars vars)
{
	t_list	*result;
	t_list	*temp_result;
	t_list	*temp_list;
	t_vec	ponto_teste;
	double	smaller;
	double	dist;
	int		first;
	int		saida;
	static int	teste_one   = 0;
	static int	teste_two   = 0;
	static int	teste_three = 0;
	static int	teste_four  = 0;

	saida = 0;
	smaller = 0.0;
	ponto_teste = empty_vec();
	first = 0;
	while (vars.objs != NULL)
	{
		result = cruzamento_sp_reta(hit.ponto, vars.light.pos, *((t_esfera *)vars.objs->data));
		if (result != NULL)
			result = first_item(result);
		temp_result = NULL;
		while(result != NULL)
		{
			dist = distance(*((t_vec *)result->data), vars.light.pos);
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

	if (distance(vars.light.pos, ponto_teste) + EPSILON <
		distance(vars.light.pos, hit.ponto))
		saida = 0;
	else
		saida = 1;
	if (1)
		saida = saida + 0;
	else if (teste_one < 3 && saida == 1 && hit.obj.sp.cor == 0x000080)
	{
		teste_one++;
		printf("light.c(can_light_see_this_hit): 62: hit = %d\n", hit.obj.tipo);
		printf("light.c(can_light_see_this_hit): 63: ponto_teste.x = %lf\n", ponto_teste.x);
		printf("light.c(can_light_see_this_hit): 64: ponto_teste.y = %lf\n", ponto_teste.y);
		printf("light.c(can_light_see_this_hit): 65: ponto_teste.z = %lf\n", ponto_teste.z);
		printf("light.c(can_light_see_this_hit): 66: hit.ponto.x = %lf\n", hit.ponto.x);
		printf("light.c(can_light_see_this_hit): 67: hit.ponto.y = %lf\n", hit.ponto.y);
		printf("light.c(can_light_see_this_hit): 68: hit.ponto.z = %lf\n", hit.ponto.z);
		printf("light.c(can_light_see_this_hit): 68: hit.obj.sp.cor = 0x%X\n", hit.obj.sp.cor);
		printf("light.c(can_light_see_this_hit): 68: saida = %d\n", saida);
		printf("\n");
	}
	else if (teste_two < 3 && saida == 0 && hit.obj.sp.cor == 0x000080)
	{
		teste_two++;
		printf("light.c(can_light_see_this_hit): 62: hit = %d\n", hit.obj.tipo);
		printf("light.c(can_light_see_this_hit): 63: ponto_teste.x = %lf\n", ponto_teste.x);
		printf("light.c(can_light_see_this_hit): 64: ponto_teste.y = %lf\n", ponto_teste.y);
		printf("light.c(can_light_see_this_hit): 65: ponto_teste.z = %lf\n", ponto_teste.z);
		printf("light.c(can_light_see_this_hit): 66: hit.ponto.x = %lf\n", hit.ponto.x);
		printf("light.c(can_light_see_this_hit): 67: hit.ponto.y = %lf\n", hit.ponto.y);
		printf("light.c(can_light_see_this_hit): 68: hit.ponto.z = %lf\n", hit.ponto.z);
		printf("light.c(can_light_see_this_hit): 68: hit.obj.sp.cor = 0x%X\n", hit.obj.sp.cor);
		printf("light.c(can_light_see_this_hit): 68: saida = %d\n", saida);
		printf("\n");
	}
	else if (teste_three < 3 && saida == 1 && hit.obj.sp.cor == 0x800000)
	{
		teste_three++;
		printf("light.c(can_light_see_this_hit): 62: hit = %d\n", hit.obj.tipo);
		printf("light.c(can_light_see_this_hit): 63: ponto_teste.x = %lf\n", ponto_teste.x);
		printf("light.c(can_light_see_this_hit): 64: ponto_teste.y = %lf\n", ponto_teste.y);
		printf("light.c(can_light_see_this_hit): 65: ponto_teste.z = %lf\n", ponto_teste.z);
		printf("light.c(can_light_see_this_hit): 66: hit.ponto.x = %lf\n", hit.ponto.x);
		printf("light.c(can_light_see_this_hit): 67: hit.ponto.y = %lf\n", hit.ponto.y);
		printf("light.c(can_light_see_this_hit): 68: hit.ponto.z = %lf\n", hit.ponto.z);
		printf("light.c(can_light_see_this_hit): 68: hit.obj.sp.cor = 0x%X\n", hit.obj.sp.cor);
		printf("light.c(can_light_see_this_hit): 68: saida = %d\n", saida);
		printf("\n");
	}
	else if (teste_four < 3 && saida == 0 && hit.obj.sp.cor == 0x800000)
	{
		teste_four++;
		printf("light.c(can_light_see_this_hit): 62: hit = %d\n", hit.obj.tipo);
		printf("light.c(can_light_see_this_hit): 63: ponto_teste.x = %lf\n", ponto_teste.x);
		printf("light.c(can_light_see_this_hit): 64: ponto_teste.y = %lf\n", ponto_teste.y);
		printf("light.c(can_light_see_this_hit): 65: ponto_teste.z = %lf\n", ponto_teste.z);
		printf("light.c(can_light_see_this_hit): 66: hit.ponto.x = %lf\n", hit.ponto.x);
		printf("light.c(can_light_see_this_hit): 67: hit.ponto.y = %lf\n", hit.ponto.y);
		printf("light.c(can_light_see_this_hit): 68: hit.ponto.z = %lf\n", hit.ponto.z);
		printf("light.c(can_light_see_this_hit): 68: hit.obj.sp.cor = 0x%X\n", hit.obj.sp.cor);
		printf("light.c(can_light_see_this_hit): 68: saida = %d\n", saida);
		printf("\n");
	}
	return (saida);
}
