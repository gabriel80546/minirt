
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
	double d;

	coeff = get_sp_coeff(A, B, sp);

	d = (coeff.b*coeff.b) + (-4*coeff.a*coeff.c);

	if (d >= 0)
		return (1);
	else
		return (0);
}

t_reta_or_n	cruzamento_sp_reta(t_vec A, t_vec B, t_esfera sp)
{
	t_coeff coeff;
	t_reta_or_n saida;
	double	d;
	double	x1;
	double	x2;

	saida.r = empty_reta();

	coeff = get_sp_coeff(A, B, sp);

	d = (coeff.b*coeff.b) + (-4*coeff.a*coeff.c);

	if (d < 0)
		saida.n = 0;
	else if (d == 0)
	{
		x1 = (-coeff.b) / (2*coeff.a);

		saida.r.orig.x = A.x + ((B.x - A.x) * x1);
		saida.r.orig.y = A.y + ((B.y - A.y) * x1);
		saida.r.orig.z = A.z + ((B.z - A.z) * x1);

		saida.n = 1;
	}
	else
	{
		x1 = (-coeff.b + sqrt(d)) / (2*coeff.a);
		x2 = (-coeff.b - sqrt(d)) / (2*coeff.a);

		saida.r.orig.x = A.x + ((B.x - A.x) * x1);
		saida.r.orig.y = A.y + ((B.y - A.y) * x1);
		saida.r.orig.z = A.z + ((B.z - A.z) * x1);

		saida.r.dest.x = A.x + ((B.x - A.x) * x2);
		saida.r.dest.y = A.y + ((B.y - A.y) * x2);
		saida.r.dest.z = A.z + ((B.z - A.z) * x2);
		saida.n = 2;
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
