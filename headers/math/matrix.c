
#include "algebra.h"
#include <stdio.h>

void	matrix_print(t_mat3by3 mat)
{
	printf("|%lf, %lf, %lf|\n", mat.a[0], mat.a[1], mat.a[2]);
	printf("|%lf, %lf, %lf|\n", mat.b[0], mat.b[1], mat.b[2]);
	printf("|%lf, %lf, %lf|\n", mat.c[0], mat.c[1], mat.c[2]);
}

t_mat3by3	matrix_mult(t_mat3by3 a, t_mat3by3 b)
{
	t_mat3by3 saida;

	saida.a[0] = (a.a[0] * b.a[0]) + (a.a[1] * b.b[0]) + (a.a[2] * b.c[0]);
	saida.a[1] = (a.a[0] * b.a[1]) + (a.a[1] * b.b[1]) + (a.a[2] * b.c[1]);
	saida.a[2] = (a.a[0] * b.a[2]) + (a.a[1] * b.b[2]) + (a.a[2] * b.c[2]);
	saida.b[0] = (a.b[0] * b.a[0]) + (a.b[1] * b.b[0]) + (a.b[2] * b.c[0]);
	saida.b[1] = (a.b[0] * b.a[1]) + (a.b[1] * b.b[1]) + (a.b[2] * b.c[1]);
	saida.b[2] = (a.b[0] * b.a[2]) + (a.b[1] * b.b[2]) + (a.b[2] * b.c[2]);
	saida.c[0] = (a.c[0] * b.a[0]) + (a.c[1] * b.b[0]) + (a.c[2] * b.c[0]);
	saida.c[1] = (a.c[0] * b.a[1]) + (a.c[1] * b.b[1]) + (a.c[2] * b.c[1]);
	saida.c[2] = (a.c[0] * b.a[2]) + (a.c[1] * b.b[2]) + (a.c[2] * b.c[2]);
	return (saida);
}

t_vec		matrix_mult_vec(t_mat3by3 mat, t_vec vec)
{
	t_vec saida;

	saida.x = (mat.a[0] * vec.x) + (mat.a[1] * vec.y) + (mat.a[2] * vec.z);
	saida.y = (mat.b[0] * vec.x) + (mat.b[1] * vec.y) + (mat.b[2] * vec.z);
	saida.z = (mat.c[0] * vec.x) + (mat.c[1] * vec.y) + (mat.c[2] * vec.z);
	return (saida);
}

t_vec	rotacao_x(t_vec ponto, double angulo)
{
	t_vec		saida;
	t_mat3by3	rot;

	rot.a[0] = 1.0; rot.a[1] = 0.0;         rot.a[2] = 0.0;
	rot.b[0] = 0.0; rot.b[1] = cos(angulo); rot.b[2] = -sin(angulo);
	rot.c[0] = 0.0; rot.c[1] = sin(angulo); rot.c[2] = cos(angulo);
	// printf("rotacao_x(ponto, %lf) =>\n", angulo);
	// matrix_print(rot);
	saida = matrix_mult_vec(rot, ponto);
	return (saida);
}

t_vec	rotacao_y(t_vec ponto, double angulo)
{
	t_vec		saida;
	t_mat3by3	rot;

	rot.a[0] =  cos(angulo); rot.a[1] = 0.0; rot.a[2] = sin(angulo);
	rot.b[0] =         0.0;  rot.b[1] = 1.0; rot.b[2] =         0.0;
	rot.c[0] = -sin(angulo); rot.c[1] = 0.0; rot.c[2] = cos(angulo);
	// printf("rotacao_y(ponto, %lf) =>\n", angulo);
	// matrix_print(rot);
	saida = matrix_mult_vec(rot, ponto);
	return (saida);
}

t_vec	rotacao_z(t_vec ponto, double angulo)
{
	t_vec		saida;
	t_mat3by3	rot;

	rot.a[0] =  cos(angulo); rot.a[1] = -sin(angulo); rot.a[2] = 0.0;
	rot.b[0] =  sin(angulo); rot.b[1] =  cos(angulo); rot.b[2] = 0.0;
	rot.c[0] =          0.0; rot.c[1] =          0.0; rot.c[2] = 1.0;
	saida = matrix_mult_vec(rot, ponto);
	return (saida);
}
