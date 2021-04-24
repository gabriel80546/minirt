
#include "algebra.h"
#include <stdio.h>

void	test_baskara(void)
{
	t_solution	s;
	double		a;
	double		b;
	double		c;

	a =  1.0;
	b =  5.0;
	c = 36.0;
	printf("hello world!\n");
	s = solve_equation(a, b, c);
	printf("%4.1lfx² + %4.1lfx + %4.1lf = 0; tem %d solucoes\n", a, b, c, s.n);
	if (s.n == 2)
	{
		printf("%4.1lfx² + %4.1lfx + %4.1lf = 0; s1 = %4.1lf, s2 = %4.1lf\n", a, b, c, s.s1, s.s2);
		printf("%4.1lfx² + %4.1lfx + %4.1lf = 0; menor solucao = %4.1lf\n", a, b, c, min(s.s1, s.s2));
		printf("%4.1lfx² + %4.1lfx + %4.1lf = 0; maior solucao = %4.1lf\n", a, b, c, max(s.s1, s.s2));
	}
	else if (s.n == 1)
		printf("%4.1lfx² + %4.1lfx + %4.1lf = 0; unica solucao s1 = %4.1lf\n", a, b, c, s.s1);
	else
		printf("%4.1lfx² + %4.1lfx + %4.1lf = 0; nao tem solucao\n", a, b, c);
}

double	cosine_law(t_tuple A, t_tuple B, t_tuple C)
{
	double	BA;
	double	BC;
	double	AC;
	double	theta_cos;

	BA = distance(B, A);
	BC = distance(B, C);
	AC = distance(A, C);
	theta_cos = ((AC * AC) - (BA * BA) - (BC * BC)) / (-2 * BA * BC);
	return (theta_cos);
}

void main(void)
{
	t_tuple	A;
	t_tuple	B;
	t_tuple	C;

	A.x = 0.0;
	A.y = 1.0;
	A.z = 5.0;
	B.x = 0.0;
	B.y = 0.0;
	B.z = 0.0;
	C.x = 1.0;
	C.y = 3.0;
	C.z =-7.0;
	printf("theta_cos = %lf\n", cosine_law(A, B, C));
	printf("theta_degree = %lf\n", acos(cosine_law(A, B, C)) * (180 / 3.14159265358979));
}