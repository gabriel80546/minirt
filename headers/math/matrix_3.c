#include "algebra.h"

t_mat33	mat44_sub_matrix(t_mat44 mat, int row, int col)
{
	t_mat33	saida;
	int		i;
	int		j;
	int		m;

	saida.m[mat33_coor(0, 0)] = 0.0;
	saida.m[mat33_coor(0, 1)] = 0.0;
	saida.m[mat33_coor(0, 2)] = 0.0;
	saida.m[mat33_coor(1, 0)] = 0.0;
	saida.m[mat33_coor(1, 1)] = 0.0;
	saida.m[mat33_coor(1, 2)] = 0.0;
	saida.m[mat33_coor(2, 0)] = 0.0;
	saida.m[mat33_coor(2, 1)] = 0.0;
	saida.m[mat33_coor(2, 2)] = 0.0;
	i = 0;
	j = 0;
	m = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != row && j != col)
			{
				saida.m[m] = mat.m[mat44_coor(i, j)];
				m++;
			}
			j++;
		}
		i++;
	}
	return (saida);
}

double	mat33_minor(t_mat33 mat, int row, int col)
{
	double	saida;
	t_mat22	b;

	b = mat33_sub_matrix(mat, row, col);
	saida = mat22_det(b);
	return (saida);
}

double	mat33_cofactor(t_mat33 mat, int row, int col)
{
	if ((row + col) % 2 == 0)
		return (mat33_minor(mat, row, col));
	else
		return (-mat33_minor(mat, row, col));
}

double	mat33_det(t_mat33 mat)
{
	double	saida;

	saida = 0;
	saida += (mat.m[mat33_coor(0, 0)] * mat33_cofactor(mat, 0, 0));
	saida += (mat.m[mat33_coor(0, 1)] * mat33_cofactor(mat, 0, 1));
	saida += (mat.m[mat33_coor(0, 2)] * mat33_cofactor(mat, 0, 2));
	return (saida);
}

double	mat44_minor(t_mat44 mat, int row, int col)
{
	double	saida;
	t_mat33	b;

	b = mat44_sub_matrix(mat, row, col);
	saida = mat33_det(b);
	return (saida);
}
