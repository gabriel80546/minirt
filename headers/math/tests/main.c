
#include "algebra.h"
#include <stdio.h>

void main(void)
{
	t_solution	s;
	double		a;
	double		b;
	double		c;

	a =  1.0;
	b = -6.0;
	c =  9.0;
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