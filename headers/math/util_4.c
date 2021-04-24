#include "algebra.h"

t_mat44	set_row_ooone(t_mat44 input, double c1, double c2, double c3, double c4)
{
	t_mat44	saida;

	saida = input;
	saida.m[0] = c1;
	saida.m[1] = c2;
	saida.m[2] = c3;
	saida.m[3] = c4;
	return (saida);
}

t_mat44	set_row_tttwo(t_mat44 input, double c1, double c2, double c3, double c4)
{
	t_mat44	saida;

	saida = input;
	saida.m[4] = c1;
	saida.m[5] = c2;
	saida.m[6] = c3;
	saida.m[7] = c4;
	return (saida);
}

t_mat44	set_row_three(t_mat44 input, double c1, double c2, double c3, double c4)
{
	t_mat44	saida;

	saida = input;
	saida.m[8] = c1;
	saida.m[9] = c2;
	saida.m[10] = c3;
	saida.m[11] = c4;
	return (saida);
}

t_mat44	set_row_ffour(t_mat44 input, double c1, double c2, double c3, double c4)
{
	t_mat44	saida;

	saida = input;
	saida.m[12] = c1;
	saida.m[13] = c2;
	saida.m[14] = c3;
	saida.m[15] = c4;
	return (saida);
}
