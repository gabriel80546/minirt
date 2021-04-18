
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


typedef struct	s_esfera
{
	t_vec		pos;
	double		diametro;
	int			cor;
}				t_esfera;

typedef struct	s_plano
{
	t_vec		pos;
	t_vec		direc;
	int			cor;
}				t_plano;

typedef struct	s_cylinder
{
	t_vec		pos;
	t_vec		direc;
	double		diameter;
	double		height;
	int			cor;
}				t_cylinder;

typedef struct	s_objeto
{
	int			tipo;
	t_esfera	sp;
	t_plano		pl;
	t_cylinder	cy;
}				t_objeto;

typedef struct	s_hit
{
	t_objeto	obj;
	t_vec		ponto;
}				t_hit;

typedef struct	s_cam
{
	t_vec		pos;
	t_vec		direc;
	t_vec		rot;
	double		fov;
}				t_cam;

typedef struct	s_light
{
	t_vec		pos;
	double		bright;
	int			cor;
}				t_light;

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

#endif
