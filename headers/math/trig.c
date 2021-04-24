#include "algebra.h"

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

t_tuple	spherical_to_tup(double radius, double inclination, double azimuth)
{
	t_tuple	saida;

	saida.x = radius * cos(azimuth) * sin(inclination);
	saida.y = radius * cos(inclination);
	saida.z = radius * sin(azimuth) * sin(inclination);
	return (saida);
}

t_tuple	spherical_to_tup_rt(double radius, double inclination, double azimuth)
{
	return (spherical_to_tup(radius, inclination - (PI / 2), -azimuth - (PI / 2)));
}

double	tup_to_spherical_inc(t_tuple direc)
{
	double	a;
	double	b;
	double	c;
	double	e;

	a = direc.z;
	b = direc.x;
	c = sqrt((a * a) + (b * b));
	e = atan2(direc.y, c);
	return (-e);
}

double	tup_to_spherical_azi(t_tuple direc)
{
	return (atan2(direc.x, direc.z));
}
