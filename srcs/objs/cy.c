
#include "minirt.h"


/*
** t²*x_d² + t²*y_d² + t²*z_d² - x_d*y_d*t² - z_d*y_d*t² - x_d*z_d*t²
** - x_0*y_d*t - x_d*y*y_0 - z_0*y_d*t - z_d*t*y_0 - x_0*z_d*t - x_d*t*z_0
** + x_0² + y_0² + z_0² + 2*x_0*x_d + 2*y_0*y_d + 2*z_0*z_d - x_0*y_0 - z_0*y_0 - x_0*z_0 - 3*a_r² == 0 ?
**/

t_list	*cruzamento_cy_reta(t_vec A, t_vec B, t_cylinder cy)
{
	t_vec	*vec_saida;
	t_list	*saida;
	double	a;
	double	b;
	double	c;


	saida = NULL;
	if (0)
	{
		// t = p / q;
		// if (!isnan(t) && t < INFINITY && t > -INFINITY)
		if (0)
		{
			vec_saida = (t_vec *)malloc(sizeof(t_vec));
			vec_saida->x = A.x + ((B.x - A.x) * 1);
			vec_saida->y = A.y + ((B.y - A.y) * 1);
			vec_saida->z = A.z + ((B.z - A.z) * 1);
			saida = list_init(vec_saida);
		}
	}
	return (saida);
}
