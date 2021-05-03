#include <stdio.h>
#include "minirt.h"
#include "check.h"

int main(void)
{
	t_tuple	v;
	t_tuple	n;
	t_tuple	r;

	printf("reflect: ");

	v = vector(0, -1, 0);
	n = vector(sqrt(2.0)/2.0, sqrt(2.0)/2.0, 0.0);

	r = reflect(v, n);
	check(equal(r.x, 1.0)
		&& equal(r.y, 0.0)
		&& equal(r.z, 0.0));
	printf("\n");
	return (0);
}
