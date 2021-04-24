#include "minirt.h"

t_cor	color_mul_scalar(t_cor cor, double scalar)
{
	t_cor	saida;

	saida = cor;
	saida.r *= scalar;
	saida.g *= scalar;
	saida.b *= scalar;
	return (saida);
}

t_cor	color_mul(t_cor a, t_cor b)
{
	t_cor	saida;

	saida.r = a.r * b.r;
	saida.g = a.g * b.g;
	saida.b = a.b * b.b;
	return (saida);
}

unsigned int	cor_to_rgb(t_cor cor)
{
	unsigned int	saida;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (cor.r > 1.0)
		cor.r = 1.0;
	if (cor.g > 1.0)
		cor.g = 1.0;
	if (cor.b > 1.0)
		cor.b = 1.0;
	r = (unsigned int)(cor.r * 255);
	g = (unsigned int)(cor.g * 255);
	b = (unsigned int)(cor.b * 255);
	saida = (r << 16 | g << 8 | b);
	return (saida);
}
