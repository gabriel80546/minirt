#include "algebra.h"

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

t_mat44	mat44_shearing(double xy, double xz, double yx, double yz,
			double zx, double zy)
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
