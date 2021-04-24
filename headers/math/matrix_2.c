#include "algebra.h"

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

	saida.m[mat22_coor(0, 0)] = 0.0;
	saida.m[mat22_coor(0, 1)] = 0.0;
	saida.m[mat22_coor(1, 0)] = 0.0;
	saida.m[mat22_coor(1, 1)] = 0.0;
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
