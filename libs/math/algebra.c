
#include "algebra.h"

double			min(double a, double b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

double			max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_solution		solve_equation(double a, double b, double c)
{
	t_solution saida;
	double delta;

	delta = (b * b) - (4 * a * c);

	saida.s1 = 0.0;
	saida.s2 = 0.0;

	if (delta < 0.0)
		saida.n = 0;
	else if (delta == 0.0)
	{
		saida.s1 = -b / (2 * a);
		saida.n = 1;
	}
	else if (delta > 0.0)
	{
		saida.s1 = (-b + sqrt(delta)) / (2 * a);
		saida.s2 = (-b - sqrt(delta)) / (2 * a);
		saida.n = 2;
	}
	else
		saida.n = -1;
	return (saida);
}