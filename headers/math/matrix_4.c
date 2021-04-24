#include "algebra.h"

double	mat44_cofactor(t_mat44 mat, int row, int col)
{
	if ((row + col) % 2 == 0)
		return (mat44_minor(mat, row, col));
	else
		return (-mat44_minor(mat, row, col));
}

double	mat44_det(t_mat44 mat)
{
	double	saida;

	saida = 0;
	saida += (mat.m[mat44_coor(0, 0)] * mat44_cofactor(mat, 0, 0));
	saida += (mat.m[mat44_coor(0, 1)] * mat44_cofactor(mat, 0, 1));
	saida += (mat.m[mat44_coor(0, 2)] * mat44_cofactor(mat, 0, 2));
	saida += (mat.m[mat44_coor(0, 3)] * mat44_cofactor(mat, 0, 3));
	return (saida);
}

t_mat44	mat44_inverse(t_mat44 mat)
{
	t_mat44	saida;
	int		row;
	int		col;
	double	c;
	double	d_orig;

	if (!equal(mat44_det(mat), 0))
	{
		saida = mat;
		d_orig = mat44_det(saida);
		row = 0;
		while (row < 4)
		{
			col = 0;
			while (col < 4)
			{
				c = mat44_cofactor(mat, row, col);
				saida.m[mat44_coor(col, row)] = c / d_orig;
				col++;
			}
			row++;
		}
	}
	else
		saida = mat44_identity();
	return (saida);
}

t_mat44	mat44_translate(double x, double y, double z)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[3] = x;
	saida.m[7] = y;
	saida.m[11] = z;
	return (saida);
}

t_mat44	mat44_scaling(double x, double y, double z)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[0] = x;
	saida.m[5] = y;
	saida.m[10] = z;
	return (saida);
}
