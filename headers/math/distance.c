#include "algebra.h"

double	distance(t_tuple A, t_tuple B)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = (A.x - B.x);
	b = (A.y - B.y);
	c = (A.z - B.z);
	d = sqrt((a * a) + (b * b) + (c * c));
	return (d);
}
