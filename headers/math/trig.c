
#include "algebra.h"

double	cosine_law(t_vec A, t_vec B, t_vec C)
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


t_vec	spherical_to_vec(double radius, double inclination, double azimuth)
{
	t_vec saida;

	saida.x = radius * cos(azimuth) * sin(inclination);
	saida.y = radius * cos(inclination);
	saida.z = radius * sin(azimuth) * sin(inclination);
	return (saida);
}

t_vec	spherical_to_vec_rt(double radius, double inclination, double azimuth)
{
	return spherical_to_vec(radius, inclination - (PI / 2), -azimuth - (PI / 2));
}

double	vec_to_spherical_inc(t_vec direc)
{
	double a;
	double b;
	double c;
	// double d;
	double e;
	// double f;

	a = direc.z;
	b = direc.x;
	c = sqrt((a * a) + (b * b));
	// d = atan2(c, direc.y);
	e = atan2(direc.y, c);
	// printf("a = % lf; b = % lf; c = % lf; d = % lf; e = % lf; f = % lf; (2 * PI) - e = % lf\n", a, b, c, d, e, f, (2 * PI) + e);
	// return (acos(direc.y / distance(empty_vec(), direc)));
	return (-e);
}

double	vec_to_spherical_azi(t_vec direc)
{
	return (atan2(direc.x, direc.z));
}
