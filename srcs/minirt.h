#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>

# include <stdio.h>
# include "mlx.h"
# include "algebra.h"
# include "list.h"
# include <math.h>

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define TRIANGLE 4

# define DEB __FILE__, __func__, __LINE__

typedef struct s_cor
{
	double	r;
	double	g;
	double	b;
}				t_cor;

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}				t_ray;

typedef struct s_material
{
	t_cor		color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;

typedef struct s_esfera
{
	t_tuple		pos;
	double		diametro;
	t_mat44		transform;
	t_material	material;
}				t_esfera;

typedef struct s_plano
{
	t_tuple		pos;
	t_material	material;
	t_mat44		transform;
	t_tuple		direc;
}				t_plano;

typedef struct s_cylinder
{
	t_tuple		pos;
	t_tuple		direc;
	double		diameter;
	double		height;
	t_material	material;
	t_mat44		transform;
}				t_cylinder;

typedef struct s_triangle
{
	t_tuple		pos_a;
	t_tuple		pos_b;
	t_tuple		pos_c;
	t_material	material;
}				t_triangle;

typedef struct s_objeto
{
	long		tipo;
	t_esfera	sp;
	t_plano		pl;
	t_cylinder	cy;
	t_triangle	tr;
}				t_objeto;

typedef struct s_hit_old
{
	t_objeto	obj;
	t_tuple		ponto;
}				t_hit_old;

typedef struct s_hit
{
	t_objeto	obj;
	double		t;
}				t_hit;

typedef struct s_cam
{
	t_tuple		pos;
	t_tuple		direc;
	t_tuple		rot;
	double		fov;
	t_mat44		transform;
}				t_cam;

typedef struct s_camera
{
	double	hsize;
	double	vsize;
	double	field_of_view;
	double	pixel_size;
	double	half_width;
	double	half_height;
	t_mat44	transform;
}				t_camera;

typedef struct s_light
{
	t_tuple		position;
	double		bright;
	t_cor		cor;
}				t_light;

typedef struct s_comps
{
	double		t;
	t_objeto	object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	long		inside;
	t_tuple		over_point;
}				t_comps;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		largura;
	int		altura;
	t_cam	cam;
	t_list	*objs;
	t_list	*lights;
	t_list	*cams;
	int		ambient;
	int		gray;
}				t_vars;

typedef struct s_img
{
	void		*ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			bits_per_byte;
	void		*data;
}				t_img;

typedef struct s_debug
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
void		put_pixel(t_img *img, int x, int y, t_cor cor);

t_mat44		mat44_identity(void);
t_tuple		vector(double x, double y, double z);
t_tuple		point(double x, double y, double z);
t_cor		color(double r, double g, double b);

t_mat44		mat44_shearing(double xy, double xz, double yx, double yz,
				double zx, double zy);
t_mat44		mat44_rotate_z(double r);
t_mat44		mat44_rotate_y(double r);
t_mat44		mat44_rotate_x(double r);
t_mat44		mat44_scaling(double x, double y, double z);
t_mat44		mat44_translate(double x, double y, double z);

t_mat44		mat44_mul(t_mat44 a, t_mat44 b);
t_tuple		mat44_tuple_mul(t_mat44 mat, t_tuple tupla);
int			say(const char *format, char *file, const char *func,
				int line, ...);
t_mat44		view_transform(t_tuple from, t_tuple to, t_tuple up);

t_list		*ray_pl_intercection(t_ray ray, t_plano plane);
t_tuple		pl_normal(t_plano plane);

t_list		*ray_cy_intercection(t_ray ray, t_cylinder cylinder);
t_tuple		cy_normal(t_cylinder cylinder, t_tuple ponto);

t_list		*ray_tr_intercection(t_ray ray, t_triangle triangle);
t_tuple		tr_normal(t_triangle triangle);

t_cor		color(double r, double g, double b);
t_cor		color_add(t_cor a, t_cor b);
t_cor		color_sub(t_cor a, t_cor b);
t_cor		color_mul_scalar(t_cor cor, double scalar);
t_cor		color_mul(t_cor a, t_cor b);
unsigned cor_to_rgb(t_cor cor);

t_ray		ray_create(t_tuple origin, t_tuple direction);
t_tuple		ray_position(t_ray ray, double dist);
t_ray		ray_transform(t_ray ray, t_mat44 matrix);

t_list		*ray_sp_intercection(t_ray ray, t_esfera sp);
t_tuple		sp_normal(t_esfera sphere, t_tuple world_point);

t_tuple		reflect(t_tuple in, t_tuple normal);
t_cor		lighting(t_material material, t_light light, t_tuple point,
				t_tuple eyev, t_tuple normalv, int in_shadow);
t_cor		shade_hit(t_vars world, t_comps comps);
int			is_shadowed(t_vars world, t_tuple point);

t_mat44		view_transform(t_tuple from, t_tuple to, t_tuple up);
t_camera	setup_camera(t_vars vars);
t_ray		ray_for_pixel(t_camera camera, int px, int py);
t_cam		empty_cam(void);

t_hit		closest_hit(t_list *hits);
t_list		*intersect_world(t_vars vars, t_ray ray);

t_comps		prepare_computations(t_hit	intersection, t_ray ray);
t_material	choose_material(t_comps comps);

void		print_mat4_cel(t_mat44 mat, int row, int col);
void		print_mat3_cel(t_mat33 mat, int row, int col);
void		print_mat2_cel(t_mat22 mat, int row, int col);

void		print_tuple(t_tuple tupla, char *file, const char *func, int line);
void		print_mat44(t_mat44 mat, char *file, const char *func, int line);
void		print_mat22(t_mat22 mat, char *file, const char *func, int line);
void		print_mat33(t_mat33 mat, char *file, const char *func, int line);

int			key_hook(int keycode, void *param);
t_cor		color_at(t_vars vars, t_ray ray);
t_vars		config_cams(t_vars input);
void		clean_all(t_vars vars);
t_vars		config_scene_easy(t_vars input);
void		draw_main(t_vars vars, int x, int y, t_img img);

t_vars		cylinder_rotation(t_vars input);

#endif
