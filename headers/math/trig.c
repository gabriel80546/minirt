
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