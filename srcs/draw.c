
#include "minirt.h"

double	absolute(double n)
{
	if (n < 0.0)
		return -n;
	else
		return n;
}

int	equal(double a, double b)
{
	if (absolute(a - b) < EPSILON)
		return (1);
	else
		return (0);
}

t_tuple	vector(double x, double y, double z)
{
	t_tuple	saida;

	saida.x = x;
	saida.y = y;
	saida.z = z;
	saida.w = 0.0;
	return (saida);
}

t_tuple	point(double x, double y, double z)
{
	t_tuple	saida;

	saida.x = x;
	saida.y = y;
	saida.z = z;
	saida.w = 1.0;
	return (saida);
}

t_tuple	tupla(double x, double y, double z, double w)
{
	t_tuple	saida;

	saida.x = x;
	saida.y = y;
	saida.z = z;
	saida.w = w;
	return (saida);
}

t_tuple	mul_scalar(t_tuple input, double scalar)
{
	t_tuple	saida;

	saida = input;
	saida.x *= scalar;
	saida.y *= scalar;
	saida.z *= scalar;
	saida.w *= scalar;
	return (saida);
}

double	magnitude(t_tuple tupla)
{
	double a;
	double b;
	double c;
	double d;

	a = (tupla.x * tupla.x);
	b = (tupla.y * tupla.y);
	c = (tupla.z * tupla.z);
	d = (tupla.w * tupla.w);
	d = sqrt(a + b + c + d);
	return (d);
}

t_tuple	normalize(t_tuple tupla)
{
	t_tuple	saida;
	double	mag;

	saida = tupla;
	mag = magnitude(saida);
	saida.x /= mag;
	saida.y /= mag;
	saida.z /= mag;
	saida.w /= mag;
	return (saida);
}

double	dot(t_tuple	a, t_tuple b)
{
	double	saida;

	saida = 0.0;
	saida += a.x * b.x;
	saida += a.y * b.y;
	saida += a.z * b.z;
	saida += a.w * b.w;
	return (saida);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	t_tuple	saida;
	double	x;
	double	y;
	double	z;

	x = ((a.y * b.z) - (a.z * b.y));
	y = ((a.z * b.x) - (a.x * b.z));
	z = ((a.x * b.y) - (a.y * b.x));
	saida = vector(x, y, z);
	return (saida);
}

t_tuple		tup_add(t_tuple a, t_tuple b)
{
	t_tuple	saida;

	saida.x = a.x + b.x;
	saida.y = a.y + b.y;
	saida.z = a.z + b.z;
	saida.w = a.w + b.w;
	return (saida);
}

t_tuple		tup_sub(t_tuple a, t_tuple b)
{
	t_tuple	saida;

	saida.x = a.x - b.x;
	saida.y = a.y - b.y;
	saida.z = a.z - b.z;
	saida.w = a.w - b.w;
	return (saida);
}

t_cor	color(double r, double g, double b)
{
	t_cor saida;

	saida.r = r;
	saida.g = g;
	saida.b = b;
	return (saida);
}

t_cor	color_add(t_cor a, t_cor b)
{
	t_cor	saida;

	saida.r = a.r + b.r;
	saida.g = a.g + b.g;
	saida.b = a.b + b.b;
	return (saida);
}

t_cor	color_sub(t_cor a, t_cor b)
{
	t_cor	saida;

	saida.r = a.r + b.r;
	saida.g = a.g + b.g;
	saida.b = a.b + b.b;
	return (saida);
}

t_cor	color_mul_scalar(t_cor cor, double scalar)
{
	t_cor	saida;

	saida = cor;
	saida.r *= scalar;
	saida.g *= scalar;
	saida.b *= scalar;
	return (saida);
}

t_cor color_mul(t_cor a, t_cor b)
{
	t_cor	saida;

	saida.r = a.r * b.r;
	saida.g = a.g * b.g;
	saida.b = a.b * b.b;
	return (saida);
}

int	cor_to_rgb(t_cor cor)
{
	int saida;
	int r;
	int g;
	int b;

	r = (int)(cor.r * 255);
	g = (int)(cor.g * 255);
	b = (int)(cor.b * 255);
	saida = (r << 16 | g << 8 | b);
	return (saida);
}


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
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[0],  mat.m[1],  mat.m[2],  mat.m[3]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[4],  mat.m[5],  mat.m[6],  mat.m[7]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[8],  mat.m[9],  mat.m[10], mat.m[11]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[12], mat.m[13], mat.m[14], mat.m[15]);
	say("\\***********************************************/\n", file, func, line);
}

void	print_mat22(t_mat22 mat, char *file, const char *func, int line)
{
	say("/***********************\\\n", file, func, line);
	say("| % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[0],  mat.m[1]);
	say("| % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[2],  mat.m[3]);
	say("\\***********************/\n", file, func, line);
}

void	print_mat33(t_mat33 mat, char *file, const char *func, int line)
{
	say("/***********************************************\\\n", file, func, line);
	say("| % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[0],  mat.m[1],  mat.m[2]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[3],  mat.m[4],  mat.m[5]);
	say("| % 6.6lf | % 6.6lf | % 6.6lf |\n", file, func, line, mat.m[6],  mat.m[7],  mat.m[8]);
	say("\\***********************************************/\n", file, func, line);
}

int		mat44_coor(int row, int col)
{
	return ((4 * row) + col);
}
int		mat33_coor(int row, int col)
{
	return ((3 * row) + col);
}
int		mat22_coor(int row, int col)
{
	return ((2 * row) + col);
}

void	print_mat4_cel(t_mat44 mat, int row, int col)
{
	say("% 6.6lf", DEB, mat.m[mat44_coor(row, col)]);
}
void	print_mat3_cel(t_mat33 mat, int row, int col)
{
	say("% 6.6lf", DEB, mat.m[(3 * row) + col]);
}
void	print_mat2_cel(t_mat22 mat, int row, int col)
{
	say("% 6.6lf", DEB, mat.m[(2 * row) + col]);
}

int		mat44_equal(t_mat44 mat_a, t_mat44 mat_b)
{
	int	saida;

	saida = 1;
	saida = equal(mat_a.m[0], mat_b.m[0]);
	saida = saida && equal(mat_a.m[1],  mat_b.m[1]);
	saida = saida && equal(mat_a.m[2],  mat_b.m[2]);
	saida = saida && equal(mat_a.m[3],  mat_b.m[3]);
	saida = saida && equal(mat_a.m[4],  mat_b.m[4]);
	saida = saida && equal(mat_a.m[5],  mat_b.m[5]);
	saida = saida && equal(mat_a.m[6],  mat_b.m[6]);
	saida = saida && equal(mat_a.m[7],  mat_b.m[7]);
	saida = saida && equal(mat_a.m[8],  mat_b.m[8]);
	saida = saida && equal(mat_a.m[9],  mat_b.m[9]);
	saida = saida && equal(mat_a.m[10], mat_b.m[10]);
	saida = saida && equal(mat_a.m[11], mat_b.m[11]);
	saida = saida && equal(mat_a.m[12], mat_b.m[12]);
	saida = saida && equal(mat_a.m[13], mat_b.m[13]);
	saida = saida && equal(mat_a.m[14], mat_b.m[14]);
	saida = saida && equal(mat_a.m[15], mat_b.m[15]);
	return (saida);
}


t_mat44		mat44_mul(t_mat44 a, t_mat44 b)
{
	t_mat44 saida;
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			saida.m[mat44_coor(row, col)] =
				a.m[mat44_coor(row, 0)] * b.m[mat44_coor(0, col)] +
				a.m[mat44_coor(row, 1)] * b.m[mat44_coor(1, col)] +
				a.m[mat44_coor(row, 2)] * b.m[mat44_coor(2, col)] +
				a.m[mat44_coor(row, 3)] * b.m[mat44_coor(3, col)];
			col++;
		}
		row++;
	}
	return (saida);
}

t_tuple		mat44_tuple_mul(t_mat44 mat, t_tuple tupla)
{
	t_tuple	saida;

	saida.x = (mat.m[0]  * tupla.x) + (mat.m[1]  * tupla.y) + (mat.m[2]  * tupla.z) + (mat.m[3]  * tupla.w);
	saida.y = (mat.m[4]  * tupla.x) + (mat.m[5]  * tupla.y) + (mat.m[6]  * tupla.z) + (mat.m[7]  * tupla.w);
	saida.z = (mat.m[8]  * tupla.x) + (mat.m[9]  * tupla.y) + (mat.m[10] * tupla.z) + (mat.m[11] * tupla.w);
	saida.w = (mat.m[12] * tupla.x) + (mat.m[13] * tupla.y) + (mat.m[14] * tupla.z) + (mat.m[15] * tupla.w);
	return (saida);
}

t_mat44		mat44_identity(void)
{
	t_mat44 saida;

	saida.m[0]  = 1.0; saida.m[1]  = 0.0; saida.m[2]  = 0.0; saida.m[3]  = 0.0;
	saida.m[4]  = 0.0; saida.m[5]  = 1.0; saida.m[6]  = 0.0; saida.m[7]  = 0.0;
	saida.m[8]  = 0.0; saida.m[9]  = 0.0; saida.m[10] = 1.0; saida.m[11] = 0.0;
	saida.m[12] = 0.0; saida.m[13] = 0.0; saida.m[14] = 0.0; saida.m[15] = 1.0;
	return (saida);
}

t_mat44		mat44_transpose(t_mat44 mat)
{
	t_mat44 saida;

	saida.m[0]  = mat.m[0]; saida.m[1]  = mat.m[4]; saida.m[2]  = mat.m[8];  saida.m[3]  = mat.m[12];
	saida.m[4]  = mat.m[1]; saida.m[5]  = mat.m[5]; saida.m[6]  = mat.m[9];  saida.m[7]  = mat.m[13];
	saida.m[8]  = mat.m[2]; saida.m[9]  = mat.m[6]; saida.m[10] = mat.m[10]; saida.m[11] = mat.m[14];
	saida.m[12] = mat.m[3]; saida.m[13] = mat.m[7]; saida.m[14] = mat.m[11]; saida.m[15] = mat.m[15];
	return (saida);
}


double		mat22_det(t_mat22 mat)
{
	double	saida;

	saida = (mat.m[0] * mat.m[3]) - (mat.m[1] * mat.m[2]);
	return (saida);
}


t_mat22		mat33_sub_matrix(t_mat33 mat, int row, int col)
{
	t_mat22	saida;
	int		i;
	int		j;
	int		m;

	saida.m[mat22_coor(0, 0)] = 0.0; saida.m[mat22_coor(0, 1)] = 0.0;
	saida.m[mat22_coor(1, 0)] = 0.0; saida.m[mat22_coor(1, 1)] = 0.0;
	i = 0;
	j = 0;
	m = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i != row && j != col)
			{
				saida.m[m] = mat.m[mat33_coor(i, j)];
				m++;
			}
			j++;
		}
		i++;
	}
	return (saida);
}

t_mat33		mat44_sub_matrix(t_mat44 mat, int row, int col)
{
	t_mat33	saida;
	int		i;
	int		j;
	int		m;

	saida.m[mat33_coor(0, 0)] = 0.0; saida.m[mat33_coor(0, 1)] = 0.0; saida.m[mat33_coor(0, 2)] = 0.0;
	saida.m[mat33_coor(1, 0)] = 0.0; saida.m[mat33_coor(1, 1)] = 0.0; saida.m[mat33_coor(1, 2)] = 0.0;
	saida.m[mat33_coor(2, 0)] = 0.0; saida.m[mat33_coor(2, 1)] = 0.0; saida.m[mat33_coor(2, 2)] = 0.0;
	i = 0;
	j = 0;
	m = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != row && j != col)
			{
				saida.m[m] = mat.m[mat44_coor(i, j)];
				m++;
			}
			j++;
		}
		i++;
	}
	
	return (saida);
}

double	mat33_minor(t_mat33 mat, int row, int col)
{
	double saida;
	t_mat22 b;

	b = mat33_sub_matrix(mat, row, col);
	saida = mat22_det(b);
	return (saida);
}

double	mat33_cofactor(t_mat33 mat, int row, int col)
{
	
	if ((row + col) % 2 == 0)
		return (mat33_minor(mat, row, col));
	else
		return -(mat33_minor(mat, row, col));
}

double mat33_det(t_mat33 mat)
{
	double	saida;
	saida = 0;

	saida += (mat.m[mat33_coor(0, 0)] * mat33_cofactor(mat, 0, 0));
	saida += (mat.m[mat33_coor(0, 1)] * mat33_cofactor(mat, 0, 1));
	saida += (mat.m[mat33_coor(0, 2)] * mat33_cofactor(mat, 0, 2));
	return (saida);
}

double	mat44_minor(t_mat44 mat, int row, int col)
{
	double saida;
	t_mat33 b;

	b = mat44_sub_matrix(mat, row, col);
	saida = mat33_det(b);
	return (saida);
}

double	mat44_cofactor(t_mat44 mat, int row, int col)
{
	
	if ((row + col) % 2 == 0)
		return (mat44_minor(mat, row, col));
	else
		return -(mat44_minor(mat, row, col));
}

double mat44_det(t_mat44 mat)
{
	double	saida;
	saida = 0;

	saida += (mat.m[mat44_coor(0, 0)] * mat44_cofactor(mat, 0, 0));
	saida += (mat.m[mat44_coor(0, 1)] * mat44_cofactor(mat, 0, 1));
	saida += (mat.m[mat44_coor(0, 2)] * mat44_cofactor(mat, 0, 2));
	saida += (mat.m[mat44_coor(0, 3)] * mat44_cofactor(mat, 0, 3));
	return (saida);
}

t_mat44	mat44_inverse(t_mat44 mat)
{
	t_mat44 saida;
	int		row;
	int		col;
	double	c;
	double	d_orig;

	if (mat44_det(mat) != 0)
	{
		saida = mat;
		d_orig = mat44_det(saida);
		row = 0;
		while (row < 4)
		{
			col = 0;
			while (col < 4)
			{
				c = mat44_cofactor(mat, row, col);
				saida.m[mat44_coor(col, row)] = c / d_orig;
				col++;
			}
			row++;
		}
	}
	else
		saida = mat44_identity();
	return (saida);
}

t_mat44	mat44_translate(double x, double y, double z)
{
	t_mat44	saida;

	saida = mat44_identity();

	saida.m[3]  = x;
	saida.m[7]  = y;
	saida.m[11] = z;
	return (saida);
}

t_mat44	mat44_scaling(double x, double y, double z)
{
	t_mat44	saida;

	saida = mat44_identity();

	saida.m[0]  = x;
	saida.m[5]  = y;
	saida.m[10] = z;
	return (saida);
}

t_mat44	mat44_rotate_x(double r)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[5]  =  cos(r);
	saida.m[6]  = -sin(r);
	saida.m[9]  =  sin(r);
	saida.m[10] =  cos(r);
	return (saida);
}

t_mat44	mat44_rotate_y(double r)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[0]  =  cos(r);
	saida.m[2]  =  sin(r);
	saida.m[8]  = -sin(r);
	saida.m[10] =  cos(r);
	return (saida);
}

t_mat44	mat44_rotate_z(double r)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[0]  =  cos(r);
	saida.m[1]  = -sin(r);
	saida.m[4]  =  sin(r);
	saida.m[5]  =  cos(r);
	return (saida);
}

t_mat44	mat44_shearing(double xy, double xz, double yx, double yz, double zx, double zy)
{
	t_mat44	saida;

	saida = mat44_identity();
	saida.m[1]  = xy;
	saida.m[2]  = xz;
	saida.m[4]  = yx;
	saida.m[6]  = yz;
	saida.m[8]  = zx;
	saida.m[9]  = zy;
	return (saida);
}

t_ray	ray_create(t_tuple origin, t_tuple direction)
{
	t_ray	saida;

	saida.origin = origin;
	saida.direction = direction;
	return (saida);
}

t_tuple	ray_position(t_ray ray, double dist)
{
	t_tuple	saida;

	saida = tup_add(ray.origin, mul_scalar(ray.direction, dist));
	return (saida);
}

t_ray	ray_transform(t_ray ray, t_mat44 matrix)
{
	t_ray saida;

	saida = ray;
	saida.origin = mat44_tuple_mul(matrix, saida.origin);
	saida.direction = mat44_tuple_mul(matrix, saida.direction);
	return (saida);
}

t_list	*ray_sp_intercection(t_ray ray, t_esfera sp)
{
	t_tuple sphere_to_ray;
	double	a;
	double	b;
	double	c;
	t_list	*saida;
	t_hit	*hit;
	t_solution	solution;

	saida = NULL;

	ray = ray_transform(ray, mat44_inverse(sp.transform));

	sphere_to_ray = tup_sub(ray.origin, point(0, 0, 0));
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(ray.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	solution = (solve_equation(a, b, c));
	if (solution.n >= 1 && solution.n <= 2)
	{
		hit = (t_hit *)malloc(sizeof(t_hit));
		hit->obj.tipo = SPHERE;
		hit->obj.sp = sp;
		hit->t = solution.s1;
		saida = list_init(hit);
	}
	if (solution.n == 2)
	{
		hit = (t_hit *)malloc(sizeof(t_hit));
		hit->obj.tipo = SPHERE;
		hit->obj.sp = sp;
		hit->t = solution.s2;
		list_add(saida, hit);
	}
	return (saida);
}

t_tuple	sp_normal(t_esfera sphere, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mat44_tuple_mul(mat44_inverse(sphere.transform), world_point);
	object_normal = tup_sub(object_point, point(0.0, 0.0, 0.0));
	world_normal = mat44_tuple_mul(mat44_transpose(mat44_inverse(sphere.transform)), object_normal);
	world_normal.w = 0.0;
	return normalize(world_normal);
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return tup_sub(in, mul_scalar(normal, 2 * dot(in, normal)));
}

t_cor	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_cor	effective_color;
	t_cor	ambient;
	t_tuple lightv;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	light_dot_normal;
	t_cor	diffuse;
	t_cor	specular;
	double	factor;

	effective_color = color_mul(material.color, light.cor);
	lightv = normalize(tup_sub(light.position, point));
	ambient = color_mul_scalar(effective_color, material.ambient);
	light_dot_normal = dot(lightv, normalv);
	if (light_dot_normal < 0.0)
	{
		diffuse = color(0.0, 0.0, 0.0);
		specular = color(0.0, 0.0, 0.0);
	}
	else
	{
		diffuse = color_mul_scalar(effective_color, material.diffuse * light_dot_normal);
		reflectv = reflect(mul_scalar(lightv, -1.0), normalv);
		reflect_dot_eye = dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = color(0.0, 0.0, 0.0);
		else
		{
			factor = pow(reflect_dot_eye, material.shininess);
			specular = color_mul_scalar(light.cor, material.specular * factor);
		}
	}
	return (color_add(color_add(ambient, diffuse), specular));
}

t_cor	lighting_new(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normalv, int in_shadow)
{
	t_cor	effective_color;
	t_cor	ambient;
	t_tuple lightv;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	light_dot_normal;
	t_cor	diffuse;
	t_cor	specular;
	double	factor;

	effective_color = color_mul(material.color, light.cor);
	lightv = normalize(tup_sub(light.position, point));
	ambient = color_mul_scalar(effective_color, material.ambient);
	light_dot_normal = dot(lightv, normalv);
	if (light_dot_normal < 0.0)
	{
		diffuse = color(0.0, 0.0, 0.0);
		specular = color(0.0, 0.0, 0.0);
	}
	else
	{
		diffuse = color_mul_scalar(effective_color, material.diffuse * light_dot_normal);
		reflectv = reflect(mul_scalar(lightv, -1.0), normalv);
		reflect_dot_eye = dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = color(0.0, 0.0, 0.0);
		else
		{
			factor = pow(reflect_dot_eye, material.shininess);
			specular = color_mul_scalar(light.cor, material.specular * factor);
		}
	}
	if (in_shadow == 1)
		return (ambient);
	else
		return (color_add(color_add(ambient, diffuse), specular));
}

void	put_pixel(t_img *img, int x, int y, t_cor cor)
{
	int ratio;
	int	offset;

	ratio = (img->bits_per_pixel / img->bits_per_byte);
	offset = (x + (y * img->size_line / ratio));
	*((unsigned int *)img->data + offset) = cor_to_rgb(cor);
}

t_hit	closest_hit(t_list *hits)
{
	t_hit	hit;
	t_list	*temp_list;
	int		hit_isfirst;

	hit_isfirst = 1;
	hit.t = -42.0;
	temp_list = NULL;
	if (hits != NULL)
		hits = first_item(hits);
	while (hits != NULL)
	{
		if (((t_hit *)hits->data)->t > 0.0 && (((t_hit *)hits->data)->t < hit.t || hit_isfirst))
		{
			hit_isfirst = 0;
			hit = *((t_hit *)hits->data);
		}
		temp_list = hits;
		hits = hits->next;
	}
	if (temp_list != NULL)
		hits = temp_list;
	return (hit);
}


t_list	*intersect_world(t_vars vars, t_ray ray)
{
	t_list	*hits_inter;
	t_list	*hits;
	t_list	*temp_list;
	t_list	*temp_temp_list;

	if (vars.objs != NULL)
		vars.objs = first_item(vars.objs);
	temp_list = NULL;
	hits = NULL;
	while (vars.objs != NULL)
	{
		hits_inter = NULL;
		ray.direction = normalize(ray.direction);
		if (((t_objeto *)vars.objs->data)->tipo == SPHERE)
			hits_inter = ray_sp_intercection(ray, ((t_objeto *)vars.objs->data)->sp);
		else if (((t_objeto *)vars.objs->data)->tipo == PLANE)
			hits_inter = ray_pl_intercection(ray, ((t_objeto *)vars.objs->data)->pl);
		else if (((t_objeto *)vars.objs->data)->tipo == CYLINDER)
			hits_inter = ray_cy_intercection(ray, ((t_objeto *)vars.objs->data)->cy);
		
		temp_temp_list = NULL;
		while (hits_inter != NULL)
		{
			if (hits == NULL)
				hits = list_init(hits_inter->data);
			else
				list_add(hits, hits_inter->data);
			temp_temp_list = hits_inter;
			hits_inter = hits_inter->next;
		}
		if (temp_temp_list != NULL)
			hits_inter = temp_temp_list;
		clear_list(hits_inter);
		temp_list = vars.objs;
		vars.objs = vars.objs->next;
	}
	if (temp_list != NULL)
		vars.objs = temp_list;
	return (hits);
}

t_comps	prepare_computations(t_hit	intersection, t_ray ray)
{
	t_comps	comps;

	comps = (t_comps) {0};
	comps.t = intersection.t;
	comps.object = intersection.obj;
	comps.point = ray_position(ray, comps.t);
	comps.eyev = mul_scalar(ray.direction, -1.0);
	if (comps.object.tipo == SPHERE)
		comps.normalv = sp_normal(comps.object.sp, comps.point);
	else if (comps.object.tipo == PLANE)
		comps.normalv = pl_normal(comps.object.pl);
	else if (comps.object.tipo == CYLINDER)
		comps.normalv = cy_normal(comps.object.cy, comps.point);
	comps.over_point = tup_add(comps.point, mul_scalar(comps.normalv, EPSILON));
	if (dot(comps.normalv, comps.eyev) < 0.0)
	{
		comps.inside = 1;
		comps.normalv = mul_scalar(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	return (comps);
}

t_material	choose_material(t_comps comps)
{
	t_material saida;

	saida = (t_material) {0};
	if (comps.object.tipo == SPHERE)
		saida = comps.object.sp.material;
	else if (comps.object.tipo == PLANE)
		saida = comps.object.pl.material;
	else if (comps.object.tipo == CYLINDER)
		saida = comps.object.cy.material;
	return (saida);
}

t_cor	shade_hit(t_vars world, t_comps comps)
{
	t_cor		saida;
	int			shadowed;
	t_material	material;

	shadowed = is_shadowed(world, comps.over_point);
	material = choose_material(comps);
	saida = lighting_new(material,
	*((t_light *)world.lights->data),
	comps.over_point,
	comps.eyev,
	comps.normalv, shadowed);
	return (saida);
}

t_cor	color_at(t_vars vars, t_ray ray)
{
	t_list	*hits;
	t_cor	hit_cor;
	t_hit	hit;
	t_comps	comps;

	hit_cor = color(0.0, 0.0, 0.0);
	hits = intersect_world(vars, ray);
	hit = closest_hit(hits);
	if (hits != NULL)
		clear_list_all(hits);
	if (hit.t != -42.0)
	{
		comps = prepare_computations(hit, ray);
		hit_cor = shade_hit(vars, comps);
		if (hit_cor.r > 1.0)
			hit_cor.r = 1.0;
		if (hit_cor.g > 1.0)
			hit_cor.g = 1.0;
		if (hit_cor.b > 1.0)
			hit_cor.b = 1.0;
	}
	return (hit_cor);
}


t_mat44	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_mat44	saida;
	t_tuple	forward;
	t_tuple	upn;
	t_tuple	left;
	t_tuple	true_up;
	t_mat44	orientation;

	forward = normalize(tup_sub(to, from));
	upn = normalize(up);
	left = cross(forward, upn);
	true_up = cross(left, forward);
	orientation.m[0]  = left.x;     orientation.m[1]  = left.y;     orientation.m[2]  = left.z;     orientation.m[3]  = 0;
	orientation.m[4]  = true_up.x;  orientation.m[5]  = true_up.y;  orientation.m[6]  = true_up.z;  orientation.m[7]  = 0;
	orientation.m[8]  = -forward.x; orientation.m[9]  = -forward.y; orientation.m[10] = -forward.z; orientation.m[11] = 0;
	orientation.m[12] = 0;          orientation.m[13] = 0;          orientation.m[14] = 0;          orientation.m[15] = 1;
	saida = mat44_mul(orientation, mat44_translate(-from.x, -from.y, -from.z));
	return (saida);
}

t_camera	setup_camera(t_vars vars)
{
	t_camera camera;
	double half_view;
	double aspect;

	camera.hsize = (double)vars.largura;
	camera.vsize = (double)vars.altura;
	camera.field_of_view = (vars.cam.fov/180.0) * (PI);
	camera.transform = vars.cam.transform;
	half_view = tan(camera.field_of_view / 2);
	aspect = camera.hsize / camera.vsize;
	if (aspect >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / camera.hsize;
	return (camera);
}

t_ray	ray_for_pixel(t_camera camera, int px, int py)
{
	t_ray ray;
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_tuple pixel;
	t_tuple origin;
	t_tuple direction;

	xoffset = (px + 0.5) * camera.pixel_size;
	yoffset = (py + 0.5) * camera.pixel_size;
	world_x = camera.half_width - xoffset;
	world_y = camera.half_height - yoffset;
	pixel = mat44_tuple_mul(mat44_inverse(camera.transform), point(world_x, world_y, -1));
	origin = mat44_tuple_mul(mat44_inverse(camera.transform), point(0, 0, 0));
	direction = normalize(tup_sub(pixel, origin));

	ray = ray_create(origin, direction);
	return (ray);
}


int	is_shadowed(t_vars world, t_tuple point)
{
	t_tuple	v;
	double	dist;
	t_tuple	direction;
	t_ray	r;
	t_list	*hits;
	t_hit	hit;

	v = tup_sub(((t_light *)world.lights->data)->position, point);
	dist = magnitude(v);
	direction = normalize(v);
	r = ray_create(point, direction);
	hits = intersect_world(world, r);
	hit = closest_hit(hits);
	if (hits != NULL)
		clear_list_all(hits);
	if (hit.t != -42.0 && hit.t < dist)
		return (1);
	else
		return (0);
}

t_tuple	sp_normal_new(t_esfera sphere, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = mat44_tuple_mul(mat44_inverse(sphere.transform), world_point);
	object_normal = tup_sub(object_point, point(0.0, 0.0, 0.0));
	world_normal = mat44_tuple_mul(mat44_transpose(mat44_inverse(sphere.transform)), object_normal);
	world_normal.w = 0.0;
	return normalize(world_normal);
}

t_tuple	pl_normal(t_plano plane)
{
	return mat44_tuple_mul(mat44_inverse(plane.transform), vector(0, 1, 0));
}

t_list	*ray_pl_intercection(t_ray ray, t_plano plane)
{
	t_list	*saida;
	t_hit	*hit;
	double	t;

	ray = ray_transform(ray, mat44_inverse(plane.transform));
	saida = NULL;
	if (absolute(ray.direction.y) < EPSILON)
		return (saida);
	t = -ray.origin.y / ray.direction.y;
	hit = (t_hit *)malloc(sizeof(t_hit));
	hit->obj.tipo = PLANE;
	hit->obj.pl = plane;
	hit->t = t;
	saida = list_init(hit);
	return (saida);
}

t_tuple	cy_normal(t_cylinder cylinder, t_tuple world_point)
{
	t_tuple	object_point;

	object_point = mat44_tuple_mul(mat44_inverse(cylinder.transform), world_point);
	return vector(object_point.x, 0, object_point.z);
	// return mat44_tuple_mul(mat44_inverse(cylinder.transform), vector(world_point.x, 0, world_point.z));
	// return mat44_tuple_mul(cylinder.transform, vector(world_point.x, 0, world_point.z));
	// return vector(world_point.x, 0, world_point.z);
}


// t_tuple	sp_normal(t_esfera sphere, t_tuple world_point)
// {
// 	t_tuple	object_point;
// 	t_tuple	object_normal;
// 	t_tuple	world_normal;

// 	object_point = mat44_tuple_mul(mat44_inverse(sphere.transform), world_point);
// 	object_normal = tup_sub(object_point, point(0.0, 0.0, 0.0));
// 	world_normal = mat44_tuple_mul(mat44_transpose(mat44_inverse(sphere.transform)), object_normal);
// 	world_normal.w = 0.0;
// 	return normalize(world_normal);
// }



t_list	*ray_cy_intercection(t_ray ray, t_cylinder cylinder)
{
	t_list		*saida;
	t_hit		*hit;
	double		a;
	double		b;
	double		c;
	t_solution	solution;
	double		y0;

	ray = ray_transform(ray, mat44_inverse(cylinder.transform));
	saida = NULL;
	a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (equal(absolute(a), EPSILON))
		return (saida);
	b = (2 * ray.origin.x * ray.direction.x +
		2 * ray.origin.z * ray.direction.z);
	c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	solution = (solve_equation(a, b, c));
	if (solution.n >= 1 && solution.n <= 2)
	{
		y0 = ray.origin.y + solution.s1 * ray.direction.y;
		if (y0 < (cylinder.height / 2) && y0 > -(cylinder.height / 2))
		{
			hit = (t_hit *)malloc(sizeof(t_hit));
			hit->obj.tipo = CYLINDER;
			hit->obj.cy = cylinder;
			hit->t = solution.s1;
			saida = list_init(hit);
		}
	}
	if (solution.n == 2)
	{
		y0 = ray.origin.y + solution.s2 * ray.direction.y;
		if (y0 < (cylinder.height / 2) && y0 > -(cylinder.height / 2))
		{
			hit = (t_hit *)malloc(sizeof(t_hit));
			hit->obj.tipo = CYLINDER;
			hit->obj.cy = cylinder;
			hit->t = solution.s2;
			if (saida == NULL)
				saida = list_init(hit);
			else
				list_add(saida, hit);
		}
	}
	return (saida);
}

void	draw_main(t_vars vars, int x, int y, t_img img)
{
	t_ray	ray;
	t_cor	hit_cor;
	t_camera	camera;

	camera = setup_camera(vars);
	ray = ray_for_pixel(camera, x, y);
	hit_cor = color_at(vars, ray);
	put_pixel(&img, x, y, hit_cor);
	
	if (x == 3 && y == 5)
	{
		// say("rendering image...\n", DEB);
	}
}

void	draw(t_vars vars)
{
	int		x;
	int		y;
	t_img	img;

	img.ptr = mlx_new_image(vars.mlx, vars.largura, vars.altura);
	img.data = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	img.bits_per_byte = 8;

	y = 0;
	while (y < vars.altura)
	{
		x = 0;
		while (x < vars.largura)
		{
			draw_main(vars, x, y, img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.ptr, 0, 0);
	mlx_destroy_image(vars.mlx, img.ptr);
}
