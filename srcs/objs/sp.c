
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
	// y = B.x - A.x - sp.pos.x;
	y = B.x - A.x;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	x = A.y - sp.pos.y;
	// y = B.y - A.y - sp.pos.y;
	y = B.y - A.y;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	x = A.z - sp.pos.z;
	// y = B.z - A.z - sp.pos.z;
	y = B.z - A.z;
	saida.a += (y * y);
	saida.b += (2 * x * y);
	saida.c += (x * x);

	saida.c -= (sp.raio * sp.raio);
	return (saida);
}


t_reta_or_n	sanitize_cruz(t_vec cam, t_vec tela, t_reta_or_n result)
{
	t_reta_or_n saida;
	// static int	primeiro = 0;

	saida = result;
	if (result.n == 1)
	{
		if (distance(result.r.orig, tela) > distance(result.r.orig, cam))
		{
			saida.n -= 1;
			saida.r.orig.x = 0;
			saida.r.orig.y = 0;
			saida.r.orig.z = 0;
			saida.r.orig.w = 0;
		}
		else if (distance(result.r.orig, cam) < distance(cam, tela))
		{
			saida.n -= 1;
			saida.r.orig.x = 0;
			saida.r.orig.y = 0;
			saida.r.orig.z = 0;
			saida.r.orig.w = 0;
		}
	}
	else if (result.n == 2)
	{
		if (distance(result.r.dest, tela) > distance(result.r.dest, cam))
		{
			saida.n -= 1;
			saida.r.dest.x = 0;
			saida.r.dest.y = 0;
			saida.r.dest.z = 0;
			saida.r.dest.w = 0;
		}
		else if (distance(result.r.dest, cam) < distance(cam, tela))
		{
			saida.n -= 1;
			saida.r.dest.x = 0;
			saida.r.dest.y = 0;
			saida.r.dest.z = 0;
			saida.r.dest.w = 0;
		}
		if (distance(result.r.orig, tela) > distance(result.r.orig, cam))
		{
			saida.n -= 1;
			saida.r.orig.x = 0;
			saida.r.orig.y = 0;
			saida.r.orig.z = 0;
			saida.r.orig.w = 0;
		}
		else if (distance(result.r.orig, cam) < distance(cam, tela))
		{
			saida.n -= 1;
			saida.r.orig.x = 0;
			saida.r.orig.y = 0;
			saida.r.orig.z = 0;
			saida.r.orig.w = 0;
		}
	}
	if (saida.n >= 1 && saida.n <= 2)
	{
		// if (primeiro == 0)
		// {
		// 	primeiro = 1;
		if (((saida.r.orig.z < tela.z) && (saida.r.orig.z != 0.0)) || ((saida.r.dest.z < tela.z) && saida.r.dest.z != 0.0))
		{
			printf("saida.n = %d\n", saida.n);
			printf("distance(saida.r.orig, cam)  = %lf\n",  distance(saida.r.orig, cam));
			printf("distance(saida.r.orig, tela) = %lf\n",  distance(saida.r.orig, tela));
			printf("distance(saida.r.dest, cam)  = %lf\n",  distance(saida.r.dest, cam));
			printf("distance(saida.r.dest, tela) = %lf\n",  distance(saida.r.dest, tela));
			printf("distance(cam, tela) = %lf\n",           distance(cam, tela));

			printf("saida.r.orig.x = %02lf\n", saida.r.orig.x);
			printf("saida.r.orig.y = %02lf\n", saida.r.orig.y);
			printf("saida.r.orig.z = %02lf\n", saida.r.orig.z);
			printf("saida.r.dest.x = %02lf\n", saida.r.dest.x);
			printf("saida.r.dest.y = %02lf\n", saida.r.dest.y);
			printf("saida.r.dest.z = %02lf\n", saida.r.dest.z);
			printf("\n");
		}
		// }
	}
	return (saida);
}