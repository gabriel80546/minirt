#include "minirt.h"

void	print_tuple(t_tuple tupla, char *file, const char *func, int line)
{
	say("tupla.x = % 6.6lf\n", file, func, line, tupla.x);
	say("tupla.y = % 6.6lf\n", file, func, line, tupla.y);
	say("tupla.z = % 6.6lf\n", file, func, line, tupla.z);
	say("tupla.w = % 6.6lf\n", file, func, line, tupla.w);
}

void	print_mat44(t_mat44 mat, char *file, const char *func, int line)
{
	say("/***********************************************\\\n", file, func, line);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line,
		mat.m[0], mat.m[1], mat.m[2], mat.m[3]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line,
		mat.m[4], mat.m[5], mat.m[6], mat.m[7]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line,
		mat.m[8], mat.m[9], mat.m[10], mat.m[11]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line,
		mat.m[12], mat.m[13], mat.m[14], mat.m[15]);
	say("\\***********************************************/\n", file, func, line);
}

void	print_mat22(t_mat22 mat, char *file, const char *func, int line)
{
	say("/***********************\\\n", file, func, line);
	say("| % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[0], mat.m[1]);
	say("| % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[2], mat.m[3]);
	say("\\***********************/\n", file, func, line);
}

void	print_mat33(t_mat33 mat, char *file, const char *func, int line)
{
	say("/***********************************************\\\n", file, func, line);
	say("| % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line,
		mat.m[0], mat.m[1], mat.m[2]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line,
		mat.m[3], mat.m[4], mat.m[5]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line,
		mat.m[6], mat.m[7], mat.m[8]);
	say("\\***********************************************/\n", file, func, line);
}
