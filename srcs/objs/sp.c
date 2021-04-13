
#include "minirt.h"

double	cruzamento_sp_delta(t_vec A, t_vec B, t_esfera sp)
{
	t_coeff coeff;
	double d;

	coeff = get_sp_coeff(A, B, sp);
	d = (coeff.b*coeff.b) + (-4*coeff.a*coeff.c);
	return (d);
}

int		cruza_sp(t_vec A, t_vec B, t_esfera sp)
{
	t_coeff coeff;
	t_solution solution;

	coeff = get_sp_coeff(A, B, sp);
	solution = solve_equation(coeff.a, coeff.b, coeff.c);
	if (solution.n >= 1 && solution.n <= 2)
		return (1);
	else
		return (0);
}

/*
	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =  -1.0;
	obj->sp.pos.y =   0.5;
	obj->sp.pos.z =   5.5;
	obj->sp.raio  =   1.75;
	obj->sp.cor   = 0x800000;
	vars.objs = list_init(obj);

	obj = (t_objeto *)malloc(sizeof(t_objeto));
	obj->tipo = SPHERE;
	obj->sp.pos.x =   1.0;
	obj->sp.pos.y =   0.0;
	obj->sp.pos.z =   5.0;
	obj->sp.raio  =   2.0;
	obj->sp.cor   = 0x000080;
	list_add(vars.objs, obj);
*/


t_list	*cruzamento_sp_reta(t_vec A, t_vec B, t_esfera sp)
{
	t_coeff coeff;
	t_solution solution;
	t_reta_or_n saida;
	t_list		*ssaida;
	t_vec		*vec_ssaida;

	saida.r = empty_reta();
	coeff = get_sp_coeff(A, B, sp);
	solution = solve_equation(coeff.a, coeff.b, coeff.c);
	saida.n = solution.n;
	ssaida = NULL;
	if (solution.n >= 1 && solution.n <= 2)
	{
		saida.r.orig.x = A.x + ((B.x - A.x) * solution.s1);
		saida.r.orig.y = A.y + ((B.y - A.y) * solution.s1);
		saida.r.orig.z = A.z + ((B.z - A.z) * solution.s1);
		vec_ssaida = (t_vec *)malloc(sizeof(t_vec));
		vec_ssaida->x = saida.r.orig.x;
		vec_ssaida->y = saida.r.orig.y;
		vec_ssaida->z = saida.r.orig.z;
		ssaida = list_init(vec_ssaida);
	}
	if (solution.n == 2)
	{
		saida.r.dest.x = A.x + ((B.x - A.x) * solution.s2);
		saida.r.dest.y = A.y + ((B.y - A.y) * solution.s2);
		saida.r.dest.z = A.z + ((B.z - A.z) * solution.s2);
		vec_ssaida = (t_vec *)malloc(sizeof(t_vec));
		vec_ssaida->x = saida.r.dest.x;
		vec_ssaida->y = saida.r.dest.y;
		vec_ssaida->z = saida.r.dest.z;
		// ssaida = list_init(vec_ssaida);
		list_add(ssaida, vec_ssaida);
	}
	return (ssaida);
}

t_coeff	get_sp_coeff(t_vec A, t_vec B, t_esfera sp)
{
	t_coeff	saida;
	double	x;
	double	y;

	saida.a = 0.0;
	saida.b = 0.0;
	saida.c = 0.0;

	x = A.x - sp.pos.x;
	y = B.x - A.x;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	x = A.y - sp.pos.y;
	y = B.y - A.y;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	x = A.z - sp.pos.z;
	y = B.z - A.z;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	saida.c -= (sp.raio * sp.raio);
	return (saida);
}

t_list		*sanitize_cruz_two(t_vec cam, t_vec tela, t_list *result)
{
	t_list	*saida;
	t_list	*save_to_delete;
	t_list	*temp_list;

	saida = result;
	while (1)
	{
		save_to_delete = NULL;
		temp_list = NULL;
		while (saida != NULL)
		{
			if (save_to_delete == NULL &&
				(distance(*(t_vec *)saida->data, tela) > distance(*(t_vec *)saida->data, cam) &&
				distance(*(t_vec *)saida->data, cam) > distance(cam, tela)))
				save_to_delete = saida;
			temp_list = saida;
			saida = saida->next;
		}
		if (save_to_delete != NULL)
			temp_list = list_delone_free(save_to_delete);
		saida = first_item(temp_list);
		if (save_to_delete == NULL)
			break;
	}
	return (saida);
}
