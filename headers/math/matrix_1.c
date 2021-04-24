#include "algebra.h"
#include <stdio.h>

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

	saida = set_row_ooone(saida, 1.0, 0.0, 0.0, 0.0);
	saida = set_row_tttwo(saida, 0.0, 1.0, 0.0, 0.0);
	saida = set_row_three(saida, 0.0, 0.0, 1.0, 0.0);
	saida = set_row_ffour(saida, 0.0, 0.0, 0.0, 1.0);
	return (saida);
}

t_mat44	mat44_transpose(t_mat44 mat)
{
	t_mat44	saida;

	saida = set_row_ooone(saida, mat.m[0], mat.m[4], mat.m[8], mat.m[12]);
	saida = set_row_tttwo(saida, mat.m[1], mat.m[5], mat.m[9], mat.m[13]);
	saida = set_row_three(saida, mat.m[2], mat.m[6], mat.m[10], mat.m[14]);
	saida = set_row_ffour(saida, mat.m[3], mat.m[7], mat.m[11], mat.m[15]);
	return (saida);
}
