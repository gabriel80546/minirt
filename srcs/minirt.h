
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

# define EPSILON 0.0000305176

# define PI 3.1415926535897932384626433832795028841971

typedef struct	s_posicao {
	double		x;
	double		y;
	double		z;
}				t_posicao;

typedef struct	s_coeff
{
	double		a;
	double		b;
	double		c;
}				t_coeff;

typedef struct	s_reta
{
	t_vec		orig;
	t_vec		dest;
}				t_reta;

typedef struct	s_reta_or_n
{
	t_reta		r;
	int			n;
}				t_reta_or_n;


typedef struct	s_esfera{
	t_vec		pos;
	double		raio;
	int			cor;
}				t_esfera;

typedef struct	s_objeto
{
	t_esfera	sp;
	int			tipo;
}				t_objeto;

typedef struct	s_hit
{
	t_objeto	obj;
	t_vec		ponto;
}				t_hit;

typedef struct	s_cam
{
	t_vec		pos;
	t_vec		normal;
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
	t_light		light;
}               t_vars;

t_reta		empty_reta(void);
t_vec		empty_vec(void);
t_coeff		get_sp_coeff(t_vec A, t_vec B, t_esfera sp/* , int print_flag */);
t_list		*cruzamento_sp_reta(t_vec A, t_vec B, t_esfera sp);
// t_list		*sanitize_cruz(t_vec cam, t_vec tela, t_list *result);
t_list		*sanitize_cruz(t_vec cam, t_vec tela, t_list *result);
double		cruzamento_sp_delta(t_vec A, t_vec B, t_esfera sp);
int			cruza_sp(t_vec A, t_vec B, t_esfera sp);

t_hit		closest_hit(t_list *hits, t_vec pos);
t_list		*get_all_hits(t_vars vars, t_vec tela);

int			can_light_see_this_hit_one_obj(t_hit temp_temp_hit, t_vars vars, t_list *result);
int			can_light_see_this_hit(t_hit temp_temp_hit, t_vars vars, t_list *result);

void		draw(t_vars vars);
void		draw_yellow_sp(t_vars vars);
void		draw_indiano(/* t_vars vars */);

#endif