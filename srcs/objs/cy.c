
#include "minirt.h"

/*
** t²*x_d² + t²*y_d² + t²*z_d² - x_d*y_d*t² - z_d*y_d*t² - x_d*z_d*t²
** - x_0*y_d*t - x_d*t*y_0 - z_0*y_d*t - z_d*t*y_0 - x_0*z_d*t - x_d*t*z_0
** + x_0² + y_0² + z_0² + 2*x_0*x_d + 2*y_0*y_d + 2*z_0*z_d - x_0*y_0 - z_0*y_0 - x_0*z_0 - 3*a_r² == 0 ?
**/

t_list	*cruzamento_cy_reta(t_vec A, t_vec B, t_cylinder cy)
{
	t_vec	*vec_saida;
	t_list	*saida;
	double	a;
	double	b;
	double	c;
	double	x_0 = A.x;
	double	y_0 = A.y;
	double	z_0 = A.z;
	double	x_d = B.x - x_0;
	double	y_d = B.y - y_0;
	double	z_d = B.z - z_0;
	t_solution solution;

	a = (x_d*x_d) + (y_d*y_d) + (z_d*z_d) - x_d*y_d - z_d*y_d - x_d*z_d;
	b = -x_0*y_d -x_d*y_0 -z_0*y_d -z_d*y_0 -x_0*z_d -x_d*z_0;
	c = (x_0*x_0) + (y_0*y_0) + (z_0*z_0) + 2*x_0*x_d + 2*y_0*y_d + 2*z_0*z_d - x_0*y_0 - z_0*y_0 - x_0*z_0;
	c -= 3*((cy.diameter / 2) * (cy.diameter / 2));
	solution = solve_equation(a, b, c);
	saida = NULL;
	if (solution.n >= 1)
	{
		if (!isnan(solution.s1) && solution.s1 < INFINITY && solution.s1 > -INFINITY)
		{
			vec_saida = (t_vec *)malloc(sizeof(t_vec));
			vec_saida->x = A.x + ((B.x - A.x) * solution.s1);
			vec_saida->y = A.y + ((B.y - A.y) * solution.s1);
			vec_saida->z = A.z + ((B.z - A.z) * solution.s1);
			saida = list_init(vec_saida);
		}
	}
	if (solution.n >= 1 && solution.n <= 2)
	{
		if (!isnan(solution.s1) && solution.s1 < INFINITY && solution.s1 > -INFINITY)
		{
			vec_saida = (t_vec *)malloc(sizeof(t_vec));
			vec_saida->x = A.x + ((B.x - A.x) * solution.s2);
			vec_saida->y = A.y + ((B.y - A.y) * solution.s2);
			vec_saida->z = A.z + ((B.z - A.z) * solution.s2);
			list_add(saida, vec_saida);
			// saida = list_init(vec_saida);
		}
	}
	return (saida);
}
