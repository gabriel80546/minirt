
#include "minirt.h"

/*
** a_xyz = pl.direc
** c_xyz = pl.pos
** xyz_0 = A
** xyz_1 = B
** p = (a_x * c_x) - (a_x * x_0) + (a_y * c_y) - (a_y * y_0) + (a_z * c_z) - (a_z * z_0)
** q = (a_x * x_d) + (a_y * y_d) + (a_y * y_d)
** q = (a_x * (x_1 - x_0)) + (a_y * (y_1 - y_0)) + (a_y * (y_1 - y_0))
** t = p / q;
**/

t_list	*cruzamento_pl_reta(t_vec A, t_vec B, t_plano pl)
{
	t_vec	*vec_saida;
	t_list	*saida;
	double	t;
	double	p;
	double	q;

	saida = NULL;
	p = (pl.direc.x * pl.pos.x) - (pl.direc.x * A.x) +
		(pl.direc.y * pl.pos.y) - (pl.direc.y * A.y) +
		(pl.direc.z * pl.pos.z) - (pl.direc.z * A.z);
	q = (pl.direc.x * (B.x - A.x)) +
		(pl.direc.y * (B.y - A.y)) +
		(pl.direc.z * (B.z - A.z));
	t = p / q;
	if (!isnan(t))
	{
		vec_saida = (t_vec *)malloc(sizeof(t_vec));
		vec_saida->x = A.x + ((B.x - A.x) * t);
		vec_saida->y = A.y + ((B.y - A.y) * t);
		vec_saida->z = A.z + ((B.z - A.z) * t);
		saida = list_init(vec_saida);
	}
	return (saida);
}
