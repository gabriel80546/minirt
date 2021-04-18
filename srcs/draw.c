
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

typedef struct	s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}				t_projectile;


t_projectile	projectile(t_tuple position, t_tuple velocity)
{
	t_projectile	saida;

	saida.position = position;
	saida.velocity = velocity;
	return (saida);
}

t_projectile	tick(t_tuple gravity, t_tuple wind, t_projectile proj)
{
	t_tuple	position;
	t_tuple	velocity;

	position = tup_add(proj.position, proj.velocity);
	velocity = tup_add(proj.velocity, tup_add(gravity, wind));
	return projectile(position, velocity);
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

// |  1   |  2   |  3   |  4   |
// |  5.5 |  6.5 |  7.5 |  8.5 |
// |  9   | 10   | 11   | 12   |
// | 13.5 | 14.5 | 15.5 | 16.5 |
// Then​ M[0,0] = 1​
// And​ M[0,3] = 4
// And​ M[1,0] = 5.5
// And​ M[1,2] = 7.5
// And​ M[2,2] = 11​
// And​ M[3,0] = 13.5
// And​ M[3,2] = 15.5


void	print_mat44(t_mat44 mat)
{
	printf("/***********************************************\\\n");
	printf("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[0],  mat.m[1],  mat.m[2],  mat.m[3]);
	printf("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[4],  mat.m[5],  mat.m[6],  mat.m[7]);
	printf("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[8],  mat.m[9],  mat.m[10], mat.m[11]);
	printf("| % 6.6lf | % 6.6lf | % 6.6lf | % 6.6lf |\n", mat.m[12], mat.m[13], mat.m[14], mat.m[15]);
	printf("\\***********************************************/\n");
}


int		mat44_coor(int row, int col)
{
	return ((4 * row) + col);
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

void	draw_main(t_vars vars, int x, int y, t_img img)
{
	t_projectile p;
	t_tuple	gravity;
	t_tuple	wind;
	int	xis;
	int yis;
	int k;
	int j;

	t_mat44	mat;
	mat.m[0]  =  1.0; mat.m[1]  =  2.0; mat.m[2]  =  3.0; mat.m[3]  =  4.0;
	mat.m[4]  =  5.5; mat.m[5]  =  6.5; mat.m[6]  =  7.5; mat.m[7]  =  8.5;
	mat.m[8]  =  9.0; mat.m[9]  = 10.0; mat.m[10] = 11.0; mat.m[11] = 12.0;
	mat.m[12] = 13.5; mat.m[13] = 14.5; mat.m[14] = 15.5; mat.m[15] = 16.5;
	t_mat22	mat2;
	mat2.m[0]  = -3.0; mat2.m[1]  =  5.0;
	mat2.m[2]  =  1.0; mat2.m[3]  = -2.0;
	t_mat33	mat3;
	mat3.m[0]  = -3.0; mat3.m[1]  =  5.0; mat3.m[2]  =  0.0;
	mat3.m[3]  =  1.0; mat3.m[4]  = -2.0; mat3.m[5]  = -7.0;
	mat3.m[6]  =  0.0; mat3.m[7]  =  1.0; mat3.m[8]  =  1.0;
	t_mat44 mat_a;
	mat_a.m[0]  =  1.0; mat_a.m[1]  =  2.0; mat_a.m[2]  =  3.0; mat_a.m[3]  =  4.0;
	mat_a.m[4]  =  5.0; mat_a.m[5]  =  6.0; mat_a.m[6]  =  7.0; mat_a.m[7]  =  8.0;
	mat_a.m[8]  =  9.0; mat_a.m[9]  =  8.0; mat_a.m[10] =  7.0; mat_a.m[11] =  6.0;
	mat_a.m[12] =  5.0; mat_a.m[13] =  4.0; mat_a.m[14] =  3.0; mat_a.m[15] =  2.0;
	t_mat44 mat_b;
	mat_b.m[0]  =  1.0; mat_b.m[1]  =  2.0; mat_b.m[2]  =  3.0; mat_b.m[3]  =  4.0;
	mat_b.m[4]  =  5.0; mat_b.m[5]  =  6.0; mat_b.m[6]  =  7.0; mat_b.m[7]  =  8.0;
	mat_b.m[8]  =  9.0; mat_b.m[9]  =  8.0; mat_b.m[10] =  7.0; mat_b.m[11] =  6.0;
	mat_b.m[12] =  5.0; mat_b.m[13] =  4.0; mat_b.m[14] =  3.0; mat_b.m[15] =  2.0;

	t_mat44 mat_c;
	mat_c.m[0]  = -2.0; mat_c.m[1]  =  1.0; mat_c.m[2]  =  2.0; mat_c.m[3]  =  3.0;
	mat_c.m[4]  =  3.0; mat_c.m[5]  =  2.0; mat_c.m[6]  =  1.0; mat_c.m[7]  = -1.0;
	mat_c.m[8]  =  4.0; mat_c.m[9]  =  3.0; mat_c.m[10] =  6.0; mat_c.m[11] =  5.0;
	mat_c.m[12] =  1.0; mat_c.m[13] =  2.0; mat_c.m[14] =  7.0; mat_c.m[15] =  8.0;

	p = projectile(point(0, 1, 0), mul_scalar(normalize(vector(1, 1.8, 0)), 11.25));
	gravity = vector(0, -0.1, 0);
	wind = vector(-0.01, 0, 0);

	if (x == 3 && y == 5)
	{
// Then​ M[0,0] = 1​
// And​ M[0,3] = 4
// And​ M[1,0] = 5.5
// And​ M[1,2] = 7.5
// And​ M[2,2] = 11​
// And​ M[3,0] = 13.5
// And​ M[3,2] = 15.5

		printf("mat_a => \n");
		print_mat44(mat_a);
		printf("mat_b => \n");
		print_mat44(mat_b);
		if (mat44_equal(mat_a, mat_b))
			printf("(mat_a and mat_b) is equal\n");
		else
			printf("(mat_a and mat_b) is not equal\n");
		printf("mat_c => \n");
		print_mat44(mat_c);
		printf("mat_b * mat_c => \n");
		print_mat44(mat44_mul(mat_b, mat_c));

		k = 0; j = 0;
		printf("M[%i, %i] = ", k, j);
		print_mat4_cel(mat, k, j);
		printf("\n");
		k = 0; j = 3;
		printf("M[%i, %i] = ", k, j);
		print_mat4_cel(mat, k, j);
		printf("\n");
		k = 1; j = 0;
		printf("M[%i, %i] = ", k, j);
		print_mat4_cel(mat, k, j);
		printf("\n");
		k = 1; j = 2;
		printf("M[%i, %i] = ", k, j);
		print_mat4_cel(mat, k, j);
		printf("\n");
		k = 2; j = 2;
		printf("M[%i, %i] = ", k, j);
		print_mat4_cel(mat, k, j);
		printf("\n");
		k = 3; j = 0;
		printf("M[%i, %i] = ", k, j);
		print_mat4_cel(mat, k, j);
		printf("\n");
		k = 3; j = 2;
		printf("M[%i, %i] = ", k, j);
		print_mat4_cel(mat, k, j);
		printf("\n");



		printf("mat2\n");

		k = 0; j = 0;
		printf("M[%i, %i] = ", k, j);
		print_mat2_cel(mat2, k, j);
		printf("\n");
		k = 0; j = 1;
		printf("M[%i, %i] = ", k, j);
		print_mat2_cel(mat2, k, j);
		printf("\n");
		k = 1; j = 0;
		printf("M[%i, %i] = ", k, j);
		print_mat2_cel(mat2, k, j);
		printf("\n");
		k = 1; j = 1;
		printf("M[%i, %i] = ", k, j);
		print_mat2_cel(mat2, k, j);
		printf("\n");




		printf("mat3\n");


		k = 0; j = 0;
		printf("M[%i, %i] = ", k, j);
		print_mat3_cel(mat3, k, j);
		printf("\n");
		k = 1; j = 1;
		printf("M[%i, %i] = ", k, j);
		print_mat3_cel(mat3, k, j);
		printf("\n");
		k = 2; j = 2;
		printf("M[%i, %i] = ", k, j);
		print_mat3_cel(mat3, k, j);
		printf("\n");

		int count = 0;
		while (p.position.y > 0 && 0)
		{
			printf("count = %d\n", count);
			printf("p.position => \n");
			print_tuple(p.position);
			p = tick(gravity, wind, p);
			printf("p.position => \n");
			print_tuple(p.position);
			xis = ((int)p.position.x);
			yis = ((int)p.position.y);
			printf("x = %d\n", xis);
			printf("y = %d\n", yis);
			if (yis >= 0 && xis >= 0)
				*((unsigned int *)img.data + (xis + ((vars.altura - yis) * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = cor_to_rgb(color(1.0, 0.0, 0.0));
			count++;
		}
		printf("precisou de %i ticks para bater no chao\n", count);
	}
	// if (x + y > (vars.largura / 2))
	// 	*((unsigned int *)img.data + (x + (y * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = 0xFF0000;
	// else
	// 	*((unsigned int *)img.data + (x + (y * img.size_line / (img.bits_per_pixel / img.bits_per_byte)))) = cor_to_rgb(color(0.0, 1.0, 0.0));
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
