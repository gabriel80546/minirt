
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


void	print_tuple(t_tuple tupla)
{
	printf("tupla.x = % 6.6lf\n", tupla.x);
	printf("tupla.y = % 6.6lf\n", tupla.y);
	printf("tupla.z = % 6.6lf\n", tupla.z);
	printf("tupla.w = % 6.6lf\n", tupla.w);
}

void	print_mat44(t_mat44 mat)
{
	printf("/***********************************************\\\n");
	printf("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[0],  mat.m[1],  mat.m[2],  mat.m[3]);
	printf("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[4],  mat.m[5],  mat.m[6],  mat.m[7]);
	printf("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[8],  mat.m[9],  mat.m[10], mat.m[11]);
	printf("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[12], mat.m[13], mat.m[14], mat.m[15]);
	printf("\\***********************************************/\n");
}

void	print_mat22(t_mat22 mat)
{
	printf("/***********************\\\n");
	printf("| % 6.6lf | % 6.6lf |\n", mat.m[0],  mat.m[1]);
	printf("| % 6.6lf | % 6.6lf |\n", mat.m[2],  mat.m[3]);
	printf("\\***********************/\n");
}

void	print_mat33(t_mat33 mat)
{
	printf("/***********************************************\\\n");
	printf("| % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[0],  mat.m[1],  mat.m[2]);
	printf("| % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[3],  mat.m[4],  mat.m[5]);
	printf("| % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[6],  mat.m[7],  mat.m[8]);
	printf("\\***********************************************/\n");
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
	printf("% 6.6lf", mat.m[mat44_coor(row, col)]);
}
void	print_mat3_cel(t_mat33 mat, int row, int col)
{
	printf("% 6.6lf", mat.m[(3 * row) + col]);
}
void	print_mat2_cel(t_mat22 mat, int row, int col)
{
	printf("% 6.6lf", mat.m[(2 * row) + col]);
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


/* 
canvas ← canvas(canvas_pixels, canvas_pixels)
​color  ← color(1, 0, 0)
// red​​shape  ← sphere()​
// for each row of pixels in the canvas
​​​for​ y ← 0 to canvas_pixels - 1
// compute the world y coordinate (top = +half, bottom = -half)
	world_y ← half - pixel_size * y​​
// for each pixel in the row​
​for​ x ← 0 to canvas_pixels - 1
// compute the world x coordinate (left = -half, right = half)
world_x ← -half + pixel_size * x
// describe the point on the wall that the ray will target
position ← point(world_x, world_y, wall_z)
r ← ray(ray_origin, normalize(position - ray_origin))
xs ← intersect(shape, r)
​if​ hit(xs) is defined
write_pixel(canvas, x, y, color)
​end​ ​if
​end​ ​for
 */

t_vec	setup_tela(t_vars vars, int x, int y)
{
	t_vec	saida;
	double	ttan;
	double	tcam;

	ttan = (tan((((vars.cam.fov) / 2.0) * PI) / 180.0));
	tcam = (((vars.largura - vars.altura) / 2));
	saida.x =  ((((2 * ttan) / vars.largura) * x) - ttan);
	saida.y = -((((2 * ttan) / vars.largura) * (y + tcam)) - ttan);
	saida.z =  1.0;

	saida = rotacao_x(saida, vec_to_spherical_inc(vars.cam.direc));
	saida = rotacao_y(saida, vec_to_spherical_azi(vars.cam.direc));

	saida.x += vars.cam.pos.x;
	saida.y += vars.cam.pos.y;
	saida.z += vars.cam.pos.z;
	return (saida);
}

t_ray	gen_rays(t_vars vars, int x, int y)
{
	t_ray	saida;
	double	ttan;
	double	tcam;

	ttan = (tan((((vars.cam.fov) / 2.0) * PI) / 180.0));
	tcam = (((vars.largura - vars.altura) / 2));
	saida.origin = point(vars.cam.pos.x, vars.cam.pos.y, vars.cam.pos.z);
	saida.direction = normalize(vector(
					((((2 * ttan) / vars.largura) * x) - ttan),
					-((((2 * ttan) / vars.largura) * (y + tcam)) - ttan),
					1.0));
	return (saida);
}

void	draw_main(t_vars vars, int x, int y, t_img img)
{
	t_ray	ray;
	t_list	*hits;
	t_list	*temp_list;

	ray = gen_rays(vars, x, y);
	if (((t_objeto *)vars.objs->data)->tipo == SPHERE)
	{
		hits = ray_sp_intercection(ray, ((t_objeto *)vars.objs->data)->sp);
		temp_list = NULL;
		while (hits != NULL)
		{
			// printf("hits.t = % 6.6lf\n", ((t_hit *)hits->data)->t);
			// printf("hits.obj.sp.diametro = % 6.6lf\n", ((t_hit *)hits->data)->obj.sp.diametro);
			temp_list = hits;
			hits = hits->next;
		}
		if (temp_list != NULL)
			hits = temp_list;
		if (hits != NULL)
			*((unsigned int *)img.data + (x + ((vars.altura - y) * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = cor_to_rgb(color(1.0, 0.0, 0.0));
	}
	else
		printf("objs nao aponta para uma esfera\n");
	if (hits != NULL)
		clear_list_all(hits);
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
