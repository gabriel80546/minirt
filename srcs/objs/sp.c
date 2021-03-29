
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

t_reta_or_n	cruzamento_sp_reta(t_vec A, t_vec B, t_esfera sp)
{
	t_coeff coeff;
	t_solution solution;
	t_reta_or_n saida;

	// printf("sp.raio = %lf\n", sp.raio);
	// printf("sp.pos.x = %lf\n", sp.pos.x);
	// printf("sp.pos.y = %lf\n", sp.pos.y);
	// printf("sp.pos.z = %lf\n", sp.pos.z);

	saida.r = empty_reta();
	coeff = get_sp_coeff(A, B, sp);
	solution = solve_equation(coeff.a, coeff.b, coeff.c);
	saida.n = solution.n;
	if (solution.n >= 1 && solution.n <= 2)
	{
		saida.r.orig.x = A.x + ((B.x - A.x) * solution.s1);
		saida.r.orig.y = A.y + ((B.y - A.y) * solution.s1);
		saida.r.orig.z = A.z + ((B.z - A.z) * solution.s1);
	}
	if (solution.n == 2)
	{
		saida.r.dest.x = A.x + ((B.x - A.x) * solution.s2);
		saida.r.dest.y = A.y + ((B.y - A.y) * solution.s2);
		saida.r.dest.z = A.z + ((B.z - A.z) * solution.s2);
	}
	return (saida);
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
	y = B.x - A.x - sp.pos.x;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	x = A.y - sp.pos.y;
	y = B.y - A.y - sp.pos.y;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	x = A.z - sp.pos.z;
	y = B.z - A.z - sp.pos.z;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	saida.c -= (sp.raio * sp.raio);
	return (saida);
}
