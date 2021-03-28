

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <math.h>

typedef struct	s_solution
{
	double		s1;
	double		s2;
	int			n;
}				t_solution;

t_solution		solve_equation(double a, double b, double c);
double			min(double a, double b);
double			max(double a, double b);

#endif