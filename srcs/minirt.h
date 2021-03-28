
#ifndef MINIRT_H
# define MINIRT_H

#include <stdlib.h>

#include <stdio.h>
#include "mlx.h"
#include "algebra.h"
#include "list.h"
#include <math.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
	int			largura;
	int			altura;
}               t_vars;

typedef struct	t_posicao {
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


typedef struct	t_esfera{
	t_vec		pos;
	double		raio;
}				t_esfera;

t_reta		empty_reta(void);
t_coeff		get_sp_coeff(t_vec A, t_vec B, t_esfera sp);
t_reta_or_n	cruzamento_sp_reta(t_vec A, t_vec B, t_esfera sp);
double		cruzamento_sp_delta(t_vec A, t_vec B, t_esfera sp);
int			cruza_sp(t_vec A, t_vec B, t_esfera sp);
void		draw(t_vars vars);
void		draw_yellow_sp(t_vars vars);
void		draw_indiano(/* t_vars vars */);

#endif