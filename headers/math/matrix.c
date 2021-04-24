#include "algebra.h"
#include <stdio.h>

int	mat44_coor(int row, int col)
{
	return ((4 * row) + col);
}

int	mat33_coor(int row, int col)
{
	return ((3 * row) + col);
}

int	mat22_coor(int row, int col)
{
	return ((2 * row) + col);
}

int	mat44_equal(t_mat44 mat_a, t_mat44 mat_b)
{
	int	saida;

	saida = 1;
	saida = equal(mat_a.m[0], mat_b.m[0]);
	saida = saida && equal(mat_a.m[1], mat_b.m[1]);
	saida = saida && equal(mat_a.m[2], mat_b.m[2]);
	saida = saida && equal(mat_a.m[3], mat_b.m[3]);
	saida = saida && equal(mat_a.m[4], mat_b.m[4]);
	saida = saida && equal(mat_a.m[5], mat_b.m[5]);
	saida = saida && equal(mat_a.m[6], mat_b.m[6]);
	saida = saida && equal(mat_a.m[7], mat_b.m[7]);
	saida = saida && equal(mat_a.m[8], mat_b.m[8]);
	saida = saida && equal(mat_a.m[9], mat_b.m[9]);
	saida = saida && equal(mat_a.m[10], mat_b.m[10]);
	saida = saida && equal(mat_a.m[11], mat_b.m[11]);
	saida = saida && equal(mat_a.m[12], mat_b.m[12]);
	saida = saida && equal(mat_a.m[13], mat_b.m[13]);
	saida = saida && equal(mat_a.m[14], mat_b.m[14]);
	saida = saida && equal(mat_a.m[15], mat_b.m[15]);
	return (saida);
}

t_mat44	mat44_mul(t_mat44 a, t_mat44 b)
{
	t_mat44	saida;
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			saida.m[mat44_coor(row, col)]
				= a.m[mat44_coor(row, 0)] * b.m[mat44_coor(0, col)]
				+ a.m[mat44_coor(row, 1)] * b.m[mat44_coor(1, col)]
				+ a.m[mat44_coor(row, 2)] * b.m[mat44_coor(2, col)]
				+ a.m[mat44_coor(row, 3)] * b.m[mat44_coor(3, col)];
			col++;
		}
		row++;
	}
	return (saida);
}

t_tuple	mat44_tuple_mul(t_mat44 mat, t_tuple tupla)
{
	t_tuple	saida;

	saida.x = (mat.m[0] * tupla.x) + (mat.m[1] * tupla.y)
		+ (mat.m[2] * tupla.z) + (mat.m[3] * tupla.w);
	saida.y = (mat.m[4] * tupla.x) + (mat.m[5] * tupla.y)
		+ (mat.m[6] * tupla.z) + (mat.m[7] * tupla.w);
	saida.z = (mat.m[8] * tupla.x) + (mat.m[9] * tupla.y)
		+ (mat.m[10] * tupla.z) + (mat.m[11] * tupla.w);
	saida.w = (mat.m[12] * tupla.x) + (mat.m[13] * tupla.y)
		+ (mat.m[14] * tupla.z) + (mat.m[15] * tupla.w);
	return (saida);
}

t_mat44	mat44_identity(void)
{
	t_mat44	saida;

	saida.m[0] = 1.0; saida.m[1] = 0.0; saida.m[2] = 0.0; saida.m[3] = 0.0;
	saida.m[4] = 0.0; saida.m[5] = 1.0; saida.m[6] = 0.0; saida.m[7] = 0.0;
	saida.m[8] = 0.0; saida.m[9] = 0.0; saida.m[10] = 1.0; saida.m[11] = 0.0;
	saida.m[12] = 0.0; saida.m[13] = 0.0; saida.m[14] = 0.0; saida.m[15] = 1.0;
	return (saida);
}

t_mat44	mat44_transpose(t_mat44 mat)
{
	t_mat44	saida;

	saida.m[0] = mat.m[0]; saida.m[1] = mat.m[4]; saida.m[2] = mat.m[8]; saida.m[3] = mat.m[12];
	saida.m[4] = mat.m[1]; saida.m[5] = mat.m[5]; saida.m[6] = mat.m[9]; saida.m[7] = mat.m[13];
	saida.m[8] = mat.m[2]; saida.m[9] = mat.m[6]; saida.m[10] = mat.m[10]; saida.m[11] = mat.m[14];
	saida.m[12] = mat.m[3]; saida.m[13] = mat.m[7]; saida.m[14] = mat.m[11]; saida.m[15] = mat.m[15];
	return (saida);
}

double	mat22_det(t_mat22 mat)
{
	double	saida;

	saida = (mat.m[0] * mat.m[3]) - (mat.m[1] * mat.m[2]);
	return (saida);
}

t_mat22	mat33_sub_matrix(t_mat33 mat, int row, int col)
{
	t_mat22	saida;
	int		i;
	int		j;
	int		m;

	saida.m[mat22_coor(0, 0)] = 0.0; saida.m[mat22_coor(0, 1)] = 0.0;
	saida.m[mat22_coor(1, 0)] = 0.0; saida.m[mat22_coor(1, 1)] = 0.0;
	i = 0;
	j = 0;
	m = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i != row && j != col)
			{
				saida.m[m] = mat.m[mat33_coor(i, j)];
				m++;
			}
			j++;
		}
		i++;
	}
	return (saida);
}

t_mat33	mat44_sub_matrix(t_mat44 mat, int row, int col)
{
	t_mat33	saida;
	int		i;
	int		j;
	int		m;

	saida.m[mat33_coor(0, 0)] = 0.0; saida.m[mat33_coor(0, 1)] = 0.0; saida.m[mat33_coor(0, 2)] = 0.0;
	saida.m[mat33_coor(1, 0)] = 0.0; saida.m[mat33_coor(1, 1)] = 0.0; saida.m[mat33_coor(1, 2)] = 0.0;
	saida.m[mat33_coor(2, 0)] = 0.0; saida.m[mat33_coor(2, 1)] = 0.0; saida.m[mat33_coor(2, 2)] = 0.0;
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

	if (mat44_det(mat) != 0)
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

t_mat44	mat44_rotate_x(double r)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[5] = cos(r);
	saida.m[6] = -sin(r);
	saida.m[9] = sin(r);
	saida.m[10] = cos(r);
	return (saida);
}

t_mat44	mat44_rotate_y(double r)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[0] = cos(r);
	saida.m[2] = sin(r);
	saida.m[8] = -sin(r);
	saida.m[10] = cos(r);
	return (saida);
}

t_mat44	mat44_rotate_z(double r)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[0] = cos(r);
	saida.m[1] = -sin(r);
	saida.m[4] = sin(r);
	saida.m[5] = cos(r);
	return (saida);
}

t_mat44	mat44_shearing(double xy, double xz, double yx, double yz, double zx, double zy)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[1] = xy;
	saida.m[2] = xz;
	saida.m[4] = yx;
	saida.m[6] = yz;
	saida.m[8] = zx;
	saida.m[9] = zy;
	return (saida);
}
