
#include "minirt.h"

/*
** t²*x_d² + t²*y_d² + t²*z_d² - x_d*y_d*t² - z_d*y_d*t² - x_d*z_d*t²
** - x_0*y_d*t - x_d*t*y_0 - z_0*y_d*t - z_d*t*y_0 - x_0*z_d*t - x_d*t*z_0
** + x_0² + y_0² + z_0² + 2*x_0*x_d + 2*y_0*y_d + 2*z_0*z_d - x_0*y_0 - z_0*y_0 - x_0*z_0 - 3*a_r² == 0 ?
**
**
** 2 c^2 t^2-2 c t^2 u+2 t^2 u^2-2 c t^2 v-2 t^2 u v+2 t^2 v^2+4 c t x-2 t u x-2 t v x+2 x^2-2 c t y+4 t u y-2 t v y-2 x y+2 y^2-2 c t z-2 t u z+4 t v z-2 x z-2 y z+2 z^2
** 2 c^2 t^2-2 c t^2 u+2 t^2 u^2-2 c t^2 v-2 t^2 u v+2 t^2 v^2+4 c t x-2 t u x-2 t v x+2 x^2-2 c t y+4 t u y-2 t v y-2 x y+2 y^2-2 c t z-2 t u z+4 t v z-2 x z-2 y z+2 z^2
**
**/

t_list	*cruzamento_cy_reta(t_vec A, t_vec B, t_cylinder cy)
{
	t_vec	*vec_saida;
	t_list	*saida;
	t_vec	temp_vec1;
	t_vec	temp_vec2;
	double	a_1;
	double	b_1;
	double	c_1;

	A = rotacao_x(A, PI / 4);
	B = rotacao_x(B, PI / 4);
	A = rotacao_z(A, (PI / 4));
	B = rotacao_z(B, (PI / 4));

	double	x_0 = A.x;
	double	y_0 = A.y;
	double	z_0 = A.z;
	double	x_d = B.x - x_0;
	double	y_d = B.y - y_0;
	double	z_d = B.z - z_0;
	// double	y = y_0;
	// double	u = y_d;
	double	x = x_0;
	double	c = x_d;
	double	z = z_0;
	double	v = z_d;
	t_solution solution;

	a_1 = c*c + v*v;
	b_1 = 2*c*x + 2*v*z;
	c_1 = x*x + z*z;
	c_1 -= (cy.diameter / 2) * (cy.diameter / 2);


	A = rotacao_z(A, -(PI / 4));
	B = rotacao_z(B, -(PI / 4));
	A = rotacao_x(A, -(PI / 4));
	B = rotacao_x(B, -(PI / 4));
	x_0 = A.x;
	y_0 = A.y;
	z_0 = A.z;
	x_d = B.x - x_0;
	y_d = B.y - y_0;
	z_d = B.z - z_0;

	solution = solve_equation(a_1, b_1, c_1);
	saida = NULL;
	temp_vec1.x = x_0 + (x_d * solution.s1);
	temp_vec1.y = y_0 + (y_d * solution.s1);
	temp_vec1.z = z_0 + (z_d * solution.s1);
	temp_vec2.x = x_0 + (x_d * solution.s2);
	temp_vec2.y = y_0 + (y_d * solution.s2);
	temp_vec2.z = z_0 + (z_d * solution.s2);
	if (solution.n >= 1)
	{
		if (!isnan(solution.s1) && solution.s1 < INFINITY && solution.s1 > -INFINITY)// &&
		// distance(temp_vec1, emp) < 1.0)
		{
			vec_saida = (t_vec *)malloc(sizeof(t_vec));
			*vec_saida = temp_vec1;
			saida = list_init(vec_saida);
		}
	}
	if (solution.n >= 1 && solution.n <= 2)
	{
		if (!isnan(solution.s1) && solution.s1 < INFINITY && solution.s1 > -INFINITY)// &&
		// distance(temp_vec1, emp) < 1.0 && distance(temp_vec2, emp) < 1.0)
		{
			vec_saida = (t_vec *)malloc(sizeof(t_vec));
			*vec_saida = temp_vec2;
			list_add(saida, vec_saida);
			// saida = list_init(vec_saida);
		}
	}
	return (saida);
}
