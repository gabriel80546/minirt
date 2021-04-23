
#ifndef MINIRT_H
# define MINIRT_H

#include <stdlib.h>

#include <stdio.h>
#include "mlx.h"
#include "algebra.h"
#include "list.h"
#include <math.h>

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

# define EPSILON 0.00001

# define PI 3.1415926535897932384626433832795028841971

# define DEB __FILE__, __func__, __LINE__


typedef struct	s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_tuple;

typedef struct	s_cor
{
	double	r;
	double	g;
	double	b;
}				t_cor;

typedef struct	s_mat44
{
	double	m[16];
}				t_mat44;

typedef struct	s_mat33
{
	double	m[9];
}				t_mat33;

typedef struct	s_mat22
{
	double	m[4];
}				t_mat22;


typedef struct	s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}				t_ray;

typedef	struct	s_material
{
	t_cor		color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;


typedef struct	s_esfera
{
	t_tuple		pos;
	double		diametro;
	t_mat44		transform;
	t_material	material;
	// int			cor;
	// double		ambient;
	// double		diffuse;
	// double		specular;
	// double		shininess;
}				t_esfera;


typedef struct	s_plano
{
	t_tuple		pos;
	// t_vec		direc;
	// int			cor;
	t_material	material;
	t_mat44		transform;
}				t_plano;

typedef struct	s_cylinder
{
	t_tuple		pos;
	// t_vec		direc;
	// int			cor;
	double		diameter;
	double		height;
	t_material	material;
	t_mat44		transform;
}				t_cylinder;

typedef struct	s_objeto
{
	int			tipo;
	t_esfera	sp;
	t_plano		pl;
	t_cylinder	cy;
}				t_objeto;

typedef struct	s_hit_old
{
	t_objeto	obj;
	t_vec		ponto;
}				t_hit_old;


typedef struct	s_hit
{
	t_objeto	obj;
	double		t;
}				t_hit;

typedef struct	s_cam
{
	t_vec		pos;
	t_vec		direc;
	t_vec		rot;
	double		fov;
	t_mat44		transform;
}				t_cam;

typedef struct	s_camera
{
	double	hsize;
	double	vsize;
	double	field_of_view;
	double	pixel_size;
	double	half_width;
	double	half_height;
	t_mat44	transform;
}				t_camera;

typedef struct	s_light
{
	t_tuple		position;
	double		bright;
	t_cor		cor;
}				t_light;

typedef struct	s_comps
{
	double		t;
	t_objeto	object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	int			inside;
	t_tuple		over_point;
}				t_comps;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
	int			largura;
	int			altura;
	t_cam		cam;
	t_list		*objs;
	t_list		*lights;
	t_list		*cams;
	int			ambient;
	int			gray;
}               t_vars;

typedef struct s_img
{
	void		*ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			bits_per_byte;
	char		*data;
}				t_img;

typedef struct	s_debug
{
	int			x;
	int			y;
	int			x_bugado;
	int			y_bugado;
	int			x_iluminado;
	int			y_iluminado;
	int			x_sombreado;
	int			y_sombreado;
	int			plane_pixels;
	int			plane_iluminated;
}				t_debug;




void		draw(t_vars vars);

t_mat44		mat44_identity(void);
t_tuple		vector(double x, double y, double z);
t_tuple		point(double x, double y, double z);
t_cor		color(double r, double g, double b);

t_mat44		mat44_shearing(double xy, double xz, double yx, double yz, double zx, double zy);
t_mat44		mat44_rotate_z(double r);
t_mat44		mat44_rotate_y(double r);
t_mat44		mat44_rotate_x(double r);
t_mat44		mat44_scaling(double x, double y, double z);
t_mat44		mat44_translate(double x, double y, double z);

t_mat44		mat44_mul(t_mat44 a, t_mat44 b);
t_tuple		mat44_tuple_mul(t_mat44 mat, t_tuple tupla);
int			say(const char *format, char *file, const char *func, int line, ...);
t_mat44		view_transform(t_tuple from, t_tuple to, t_tuple up);
int			is_shadowed(t_vars world, t_tuple point);

t_list		*ray_pl_intercection(t_ray ray, t_plano plane);
t_tuple		pl_normal(t_plano plane);

t_list		*ray_cy_intercection(t_ray ray, t_cylinder cylinder);
t_tuple		cy_normal(t_cylinder cylinder, t_tuple ponto);

#endif
