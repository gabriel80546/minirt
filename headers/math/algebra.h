#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <math.h>

# define EPSILON 0.00001
# define PI 3.1415926535897932384626433832795028841971

typedef struct s_solution
{
	double		s1;
	double		s2;
	long		n;
}				t_solution;

typedef struct s_tuple
{
	double		x;
	double		y;
	double		z;
	double		w;
}	t_tuple;

typedef struct s_mat44
{
	double	m[16];
}				t_mat44;

typedef struct s_mat33
{
	double	m[9];
}				t_mat33;

typedef struct s_mat22
{
	double	m[4];
}				t_mat22;

t_solution		solve_equation(double a, double b, double c);
double			min(double a, double b);
double			max(double a, double b);
double			distance(t_tuple A, t_tuple B);
double			cosine_law(t_tuple A, t_tuple B, t_tuple C);

t_tuple			spherical_to_tup(double radius,
					double inclination, double azimuth);
t_tuple			spherical_to_tup_rt(double radius,
					double inclination, double azimuth);
double			tup_to_spherical_inc(t_tuple direc);
double			tup_to_spherical_azi(t_tuple direc);

int				mat44_coor(int row, int col);
int				mat33_coor(int row, int col);
int				mat22_coor(int row, int col);
int				mat44_equal(t_mat44 mat_a, t_mat44 mat_b);
t_mat44			mat44_mul(t_mat44 a, t_mat44 b);
t_tuple			mat44_tuple_mul(t_mat44 mat, t_tuple tupla);
t_mat44			mat44_identity(void);
t_mat44			mat44_transpose(t_mat44 mat);
double			mat22_det(t_mat22 mat);
t_mat22			mat33_sub_matrix(t_mat33 mat, int row, int col);
t_mat33			mat44_sub_matrix(t_mat44 mat, int row, int col);
double			mat33_minor(t_mat33 mat, int row, int col);
double			mat33_cofactor(t_mat33 mat, int row, int col);
double			mat33_det(t_mat33 mat);
double			mat44_minor(t_mat44 mat, int row, int col);
double			mat44_cofactor(t_mat44 mat, int row, int col);
double			mat44_det(t_mat44 mat);
t_mat44			mat44_inverse(t_mat44 mat);
t_mat44			mat44_translate(double x, double y, double z);
t_mat44			mat44_scaling(double x, double y, double z);
t_mat44			mat44_rotate_x(double r);
t_mat44			mat44_rotate_y(double r);
t_mat44			mat44_rotate_z(double r);
t_mat44			mat44_shearing(double xy, double xz, double yx, double yz,
					double zx, double zy);

double			absolute(double n);
int				equal(double a, double b);
t_tuple			vector(double x, double y, double z);
t_tuple			point(double x, double y, double z);
t_tuple			tupla(double x, double y, double z, double w);
t_tuple			mul_scalar(t_tuple input, double scalar);
double			magnitude(t_tuple tupla);
t_tuple			normalize(t_tuple tupla);
double			dot(t_tuple	a, t_tuple b);
t_tuple			cross(t_tuple a, t_tuple b);
t_tuple			tup_add(t_tuple a, t_tuple b);
t_tuple			tup_sub(t_tuple a, t_tuple b);

t_mat44			set_row_ooone(t_mat44 input, double c1, double c2,
					double c3, double c4);
t_mat44			set_row_tttwo(t_mat44 input, double c1, double c2,
					double c3, double c4);
t_mat44			set_row_three(t_mat44 input, double c1, double c2,
					double c3, double c4);
t_mat44			set_row_ffour(t_mat44 input, double c1, double c2,
					double c3, double c4);
#endif
