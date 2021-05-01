#include <stdio.h>
#include "minirt.h"
#include "check.h"

int main(void)
{
	t_tuple	ponto;
	t_tuple saida;

	printf("mat44_rotate_z: ");
	ponto = point(0, 1, 0);
	saida = mat44_tuple_mul(mat44_rotate_z(PI / 2), ponto);
	check(equal(saida.x, -1.0)
		&& equal(saida.y,  0.0)
		&& equal(saida.z,  0.0)
		&& equal(saida.w,  1.0));
	printf("\n");
	return (0);
}
