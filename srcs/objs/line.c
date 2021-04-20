
#include "minirt.h"

t_reta		empty_reta(void)
{
	t_reta saida;

	saida.orig.x = 0.0;
	saida.orig.y = 0.0;
	saida.orig.z = 0.0;
	saida.orig.w = 0.0;
	saida.dest.x = 0.0;
	saida.dest.y = 0.0;
	saida.dest.z = 0.0;
	saida.dest.w = 0.0;
	return (saida);
}

t_vec		empty_vec(void)
{
	t_vec saida;

	saida.x = 0.0;
	saida.y = 0.0;
	saida.z = 0.0;
	saida.w = 0.0;
	return (saida);
}

