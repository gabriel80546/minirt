

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <math.h>

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

t_solution		solve_equation(double a, double b, double c);
double			min(double a, double b);
double			max(double a, double b);
double			distance(t_vec A, t_vec B);
double			cosine_law(t_vec A, t_vec B, t_vec C);

#endif