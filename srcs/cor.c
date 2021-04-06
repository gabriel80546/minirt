
#include "minirt.h"


int			to_rgb(t_cor_had cor)
{
	int	r;
	int	g;
	int	b;
	int saida;

	r = cor.r * 255;
	g = cor.g * 255;
	b = cor.b * 255;
	saida = ((int)b << 16 | (int)g << 8 | (int)r);
	return (saida);
}

t_cor_had	to_had(int rgb)
{
	double	r;
	double	g;
	double	b;
	t_cor_had	saida;

	r = (double)((rgb & 0x0000FF) >> 0);
	g = (double)((rgb & 0x00FF00) >> 8);
	b = (double)((rgb & 0xFF0000) >> 16);
	saida.r = (double)(r / 255);
	saida.g = (double)(g / 255);
	saida.b = (double)(b / 255);
	return (saida);
}

t_cor_had	norm_had(t_cor_had input)
{
	t_cor_had saida;

	saida.r = input.r;
	saida.g = input.g;
	saida.b = input.b;
	if (saida.r > 1.0)
		saida.r = 1.0;
	if (saida.g > 1.0)
		saida.g = 1.0;
	if (saida.b > 1.0)
		saida.b = 1.0;
	return (saida);
}

t_cor_had	mult_had(t_cor_had a, t_cor_had b)
{
	t_cor_had saida;

	saida.r = a.r * b.r;
	saida.g = a.g * b.g;
	saida.b = a.b * b.b;
	return (saida);
}

t_cor_had	sum_had(t_cor_had a, t_cor_had b)
{
	t_cor_had saida;

	saida.r = a.r + b.r;
	saida.g = a.g + b.g;
	saida.b = a.b + b.b;
	return (saida);
}