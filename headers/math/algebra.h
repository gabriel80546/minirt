

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <math.h>

# define PI 3.1415926535897932384626433832795028841971

typedef struct	s_solution
{
	double		s1;
	double		s2;
	int			n;
}				t_solution;

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec;

typedef struct	s_mat3by3
{
	double		a[3];
	double		b[3];
	double		c[3];
}				t_mat3by3;


t_solution		solve_equation(double a, double b, double c);
double			min(double a, double b);
double			max(double a, double b);
double			distance(t_vec A, t_vec B);
double			cosine_law(t_vec A, t_vec B, t_vec C);

void			matrix_print(t_mat3by3 mat);
t_mat3by3		matrix_mult(t_mat3by3 a, t_mat3by3 b);
t_vec			matrix_mult_vec(t_mat3by3 mat, t_vec vec);
t_vec			rotacao_x(t_vec ponto, double angulo);
t_vec			rotacao_y(t_vec ponto, double angulo);
t_vec			rotacao_z(t_vec ponto, double angulo);


t_vec			spherical_to_vec(double radius, double inclination, double azimuth);
t_vec			spherical_to_vec_rt(double radius, double inclination, double azimuth);
double			vec_to_spherical_inc(t_vec direc);
double			vec_to_spherical_azi(t_vec direc);


#endif