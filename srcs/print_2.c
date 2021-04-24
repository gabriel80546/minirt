#include "minirt.h"

void	print_mat4_cel(t_mat44 mat, int row, int col)
{
	say("% 6.6lf", DEB, mat.m[mat44_coor(row, col)]);
}

void	print_mat3_cel(t_mat33 mat, int row, int col)
{
	say("% 6.6lf", DEB, mat.m[(3 * row) + col]);
}

void	print_mat2_cel(t_mat22 mat, int row, int col)
{
	say("% 6.6lf", DEB, mat.m[(2 * row) + col]);
}
