
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

// A matrix multiplied by a tuple​  ​Given​ the following matrix A:​
// | 1 | 2 | 3 | 4 |
// | 2 | 4 | 4 | 2 |
// | 8 | 6 | 4 | 1 |
// | 0 | 0 | 0 | 1 |
// ​And​ b ← tuple(1, 2, 3, 1)​  ​Then​ A * b = tuple(18, 24, 33, 1)
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


// : Calculating a minor of a 3x3 matrix​  ​Given​ the following 3x3 matrix A:
// |  3 |  5 |  0 |
// |  2 | -1 | -7 |
// |  6 | -1 |  5 |
// ​And​ B ← submatrix(A, 1, 0)​
// ​Then​ determinant(B) = 25
// ​And​ minor(A, 1, 0) = 25
double	mat33_minor(t_mat33 mat, int row, int col)
{
	double saida;
	t_mat22 b;

	b = mat33_sub_matrix(mat, row, col);
	saida = mat22_det(b);
	return (saida);
}

// : Calculating a cofactor of a 3x3 matrix​  ​Given​ the following 3x3 matrix A:
// |  3 |  5 |  0 |
// |  2 | -1 | -7 |
// |  6 | -1 |  5 |
// ​Then​ minor(A, 0, 0) = -12
// ​And​ cofactor(A, 0, 0) = -12
// ​And​ minor(A, 1, 0) = 25​
// ​And​ cofactor(A, 1, 0) = -25
double	mat33_cofactor(t_mat33 mat, int row, int col)
{
	
	if ((row + col) % 2 == 0)
		return (mat33_minor(mat, row, col));
	else
		return -(mat33_minor(mat, row, col));
}

// : Calculating the determinant of a 3x3 matrix​  ​Given​ the following 3x3 matrix A:
// |  1 |  2 |  6 |
// | -5 |  8 | -4 |
// |  2 |  6 |  4 |
// ​Then​ cofactor(A, 0, 0) = 56
// ​And​ cofactor(A, 0, 1) = 12​
// ​And​ cofactor(A, 0, 2) = -46
// ​And​ determinant(A) = -196
// determinant(M)
// det ← 0​​
// ​if​ M.size = 2
// 	det ← M​[​0, 0​]​ * M​[​1, 1​]​ - M​[​0, 1​]​ * M​[​1, 0​]
// ​else
// 	​for​ column ← 0 to M.size - 1
// 	det ← det + M​[​0, column​]​ * cofactor(M, 0, column)
// 	​end​ ​for
// ​end​ ​if
// ​return​ det​​
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

	// mat44_mi
	saida += (mat.m[mat44_coor(0, 0)] * mat44_cofactor(mat, 0, 0));
	saida += (mat.m[mat44_coor(0, 1)] * mat44_cofactor(mat, 0, 1));
	saida += (mat.m[mat44_coor(0, 2)] * mat44_cofactor(mat, 0, 2));
	saida += (mat.m[mat44_coor(0, 3)] * mat44_cofactor(mat, 0, 3));
	return (saida);
}

// inverse(M)
// 	fail ​if​ M is not invertible​​
// 	M2 ← new matrix of same size as M
// 	​for​ row ← 0 to M.size - 1
// 		​for​ col ← 0 to M.size - 1
// 			c ← cofactor(M, row, col)
// 			// note that "col, row" here, instead of "row, col",
// 			// accomplishes the transpose operation!
// 			M2​[​col, row​]​ ← c / determinant(M)
// 		​end​ ​for
// 	​end​ ​for
// ​return​ M2
t_mat44	inverse(t_mat44 mat)
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


void	draw_main(t_vars vars, int x, int y, t_img img)
{
	t_projectile p;
	t_tuple	gravity;
	t_tuple	wind;
	int	xis;
	int yis;
	// int k;
	// int j;

	// t_mat44	mat;
	// mat.m[0]  =  1.0; mat.m[1]  =  2.0; mat.m[2]  =  3.0; mat.m[3]  =  4.0;
	// mat.m[4]  =  5.5; mat.m[5]  =  6.5; mat.m[6]  =  7.5; mat.m[7]  =  8.5;
	// mat.m[8]  =  9.0; mat.m[9]  = 10.0; mat.m[10] = 11.0; mat.m[11] = 12.0;
	// mat.m[12] = 13.5; mat.m[13] = 14.5; mat.m[14] = 15.5; mat.m[15] = 16.5;
	// t_mat22	mat2;
	// mat2.m[0]  = -3.0; mat2.m[1]  =  5.0;
	// mat2.m[2]  =  1.0; mat2.m[3]  = -2.0;
	// t_mat33	mat3;
	// mat3.m[0]  = -3.0; mat3.m[1]  =  5.0; mat3.m[2]  =  0.0;
	// mat3.m[3]  =  1.0; mat3.m[4]  = -2.0; mat3.m[5]  = -7.0;
	// mat3.m[6]  =  0.0; mat3.m[7]  =  1.0; mat3.m[8]  =  1.0;
	// t_mat44 mat_a;
	// mat_a.m[0]  =  1.0; mat_a.m[1]  =  2.0; mat_a.m[2]  =  3.0; mat_a.m[3]  =  4.0;
	// mat_a.m[4]  =  5.0; mat_a.m[5]  =  6.0; mat_a.m[6]  =  7.0; mat_a.m[7]  =  8.0;
	// mat_a.m[8]  =  9.0; mat_a.m[9]  =  8.0; mat_a.m[10] =  7.0; mat_a.m[11] =  6.0;
	// mat_a.m[12] =  5.0; mat_a.m[13] =  4.0; mat_a.m[14] =  3.0; mat_a.m[15] =  2.0;
	// t_mat44 mat_b;
	// mat_b.m[0]  =  1.0; mat_b.m[1]  =  2.0; mat_b.m[2]  =  3.0; mat_b.m[3]  =  4.0;
	// mat_b.m[4]  =  5.0; mat_b.m[5]  =  6.0; mat_b.m[6]  =  7.0; mat_b.m[7]  =  8.0;
	// mat_b.m[8]  =  9.0; mat_b.m[9]  =  8.0; mat_b.m[10] =  7.0; mat_b.m[11] =  6.0;
	// mat_b.m[12] =  5.0; mat_b.m[13] =  4.0; mat_b.m[14] =  3.0; mat_b.m[15] =  2.0;

	// t_mat44 mat_c;
	// mat_c.m[0]  = -2.0; mat_c.m[1]  =  1.0; mat_c.m[2]  =  2.0; mat_c.m[3]  =  3.0;
	// mat_c.m[4]  =  3.0; mat_c.m[5]  =  2.0; mat_c.m[6]  =  1.0; mat_c.m[7]  = -1.0;
	// mat_c.m[8]  =  4.0; mat_c.m[9]  =  3.0; mat_c.m[10] =  6.0; mat_c.m[11] =  5.0;
	// mat_c.m[12] =  1.0; mat_c.m[13] =  2.0; mat_c.m[14] =  7.0; mat_c.m[15] =  8.0;


	t_mat44	mat_d;
	mat_d.m[0]  =  1.0; mat_d.m[1]  =  2.0; mat_d.m[2]  =  3.0; mat_d.m[3]  =  4.0;
	mat_d.m[4]  =  2.0; mat_d.m[5]  =  4.0; mat_d.m[6]  =  4.0; mat_d.m[7]  =  2.0;
	mat_d.m[8]  =  8.0; mat_d.m[9]  =  6.0; mat_d.m[10] =  4.0; mat_d.m[11] =  1.0;
	mat_d.m[12] =  0.0; mat_d.m[13] =  0.0; mat_d.m[14] =  0.0; mat_d.m[15] =  1.0;

	t_tuple	tupla_teste;
	tupla_teste = tupla(1, 2, 3, 1);


	// |  1 | 5 |
	// | -3 | 2 |
	t_mat22	mat_a;
	mat_a.m[0] =  1.0; mat_a.m[1] =  5.0;
	mat_a.m[2] = -3.0; mat_a.m[3] =  2.0;


	// |  1 | 5 |  0 |
	// | -3 | 2 |  7 |
	// |  0 | 6 | -3 |
	t_mat33	mat_b;
	mat_b.m[0] =  1.0; mat_b.m[1] =  5.0; mat_b.m[2] =  0.0;
	mat_b.m[3] = -3.0; mat_b.m[4] =  2.0; mat_b.m[5] =  7.0;
	mat_b.m[6] =  0.0; mat_b.m[7] =  6.0; mat_b.m[8] = -3.0;

	// |  3 |  5 |  0 |
	// |  2 | -1 | -7 |
	// |  6 | -1 |  5 |
	t_mat33	mat_e;
	mat_e.m[0] =  3.0; mat_e.m[1] =  5.0; mat_e.m[2] =  0.0;
	mat_e.m[3] =  2.0; mat_e.m[4] = -1.0; mat_e.m[5] = -7.0;
	mat_e.m[6] =  6.0; mat_e.m[7] = -1.0; mat_e.m[8] =  5.0;

	// |  1 |  2 |  6 |
	// | -5 |  8 | -4 |
	// |  2 |  6 |  4 |
	t_mat33	mat_f;
	mat_f.m[0] =  1.0; mat_f.m[1] =  2.0; mat_f.m[2] =  6.0;
	mat_f.m[3] = -5.0; mat_f.m[4] =  8.0; mat_f.m[5] = -4.0;
	mat_f.m[6] =  2.0; mat_f.m[7] =  6.0; mat_f.m[8] =  4.0;


	// | -6 |  1 |  1 |  6 |
	// | -8 |  5 |  8 |  6 |
	// | -1 |  0 |  8 |  2 |
	// | -7 |  1 | -1 |  1 |
	t_mat44	mat_c;
	mat_c.m[0]  = -6.0; mat_c.m[1]  =  1.0; mat_c.m[2]  =  1.0; mat_c.m[3]  =  6.0;
	mat_c.m[4]  = -8.0; mat_c.m[5]  =  5.0; mat_c.m[6]  =  8.0; mat_c.m[7]  =  6.0;
	mat_c.m[8]  = -1.0; mat_c.m[9]  =  0.0; mat_c.m[10] =  8.0; mat_c.m[11] =  2.0;
	mat_c.m[12] = -7.0; mat_c.m[13] =  1.0; mat_c.m[14] = -1.0; mat_c.m[15] =  1.0;



    // | -2 | -8 |  3 |  5 |
	// | -3 |  1 |  7 |  3 |​
	// |  1 |  2 | -9 |  6 |
	// | -6 |  7 |  7 | -9 |
	t_mat44	mat_g;
	mat_g.m[0]  = -2.0; mat_g.m[1]  = -8.0; mat_g.m[2]  =  3.0; mat_g.m[3]  =  5.0;
	mat_g.m[4]  = -3.0; mat_g.m[5]  =  1.0; mat_g.m[6]  =  7.0; mat_g.m[7]  =  3.0;
	mat_g.m[8]  =  1.0; mat_g.m[9]  =  2.0; mat_g.m[10] = -9.0; mat_g.m[11] =  6.0;
	mat_g.m[12] = -6.0; mat_g.m[13] =  7.0; mat_g.m[14] =  7.0; mat_g.m[15] = -9.0;


	// |  8 | -5 |  9 |  2 |
	// |  7 |  5 |  6 |  1 |
	// | -6 |  0 |  9 |  6 |
	// | -3 |  0 | -9 | -4 |
	t_mat44	mat_h;
	mat_h.m[0]  =  8.0; mat_h.m[1]  = -5.0; mat_h.m[2]  =  9.0; mat_h.m[3]  =  2.0;
	mat_h.m[4]  =  7.0; mat_h.m[5]  =  5.0; mat_h.m[6]  =  6.0; mat_h.m[7]  =  1.0;
	mat_h.m[8]  = -6.0; mat_h.m[9]  =  0.0; mat_h.m[10] =  9.0; mat_h.m[11] =  6.0;
	mat_h.m[12] = -3.0; mat_h.m[13] =  0.0; mat_h.m[14] = -9.0; mat_h.m[15] = -4.0;


	// |  9 |  3 |  0 |  9 |
	// | -5 | -2 | -6 | -3 |
	// | -4 |  9 |  6 |  4 |
	// | -7 |  6 |  6 |  2 |​
	t_mat44	mat_i;
	mat_i.m[0]  =  9.0; mat_i.m[1]  =  3.0; mat_i.m[2]  =  0.0; mat_i.m[3]  =  9.0;
	mat_i.m[4]  = -5.0; mat_i.m[5]  = -2.0; mat_i.m[6]  = -6.0; mat_i.m[7]  = -3.0;
	mat_i.m[8]  = -4.0; mat_i.m[9]  =  9.0; mat_i.m[10] =  6.0; mat_i.m[11] =  4.0;
	mat_i.m[12] = -7.0; mat_i.m[13] =  6.0; mat_i.m[14] =  6.0; mat_i.m[15] =  2.0;



	p = projectile(point(0, 1, 0), mul_scalar(normalize(vector(1, 1.8, 0)), 11.25));
	gravity = vector(0, -0.1, 0);
	wind = vector(-0.01, 0, 0);

	if (x == 3 && y == 5)
	{
		printf("mat_d => \n");
		print_mat44(mat_d);
		printf("tupla_teste => \n");
		print_tuple(tupla_teste);
		printf("mat_d * tupla_teste => \n");
		print_tuple(mat44_tuple_mul(mat_d, tupla_teste));


		if(mat44_equal(mat_d, mat44_mul(mat_d, mat44_identity())))
			printf("mat44_equal(mat_d, mat44_mul(mat_d, mat44_identity())) == true OK\n");
		else
			printf("mat44_equal(mat_d, mat44_mul(mat_d, mat44_identity())) == false KO\n");
		
		printf("transpose(mat_d) => \n");
		print_mat44(mat44_transpose(mat_d));

		printf("mat_a => \n");
		print_mat22(mat_a);

		printf("mat22_det(mat_a) = % 6.6lf\n", mat22_det(mat_a));

		printf("mat_b => \n");
		print_mat33(mat_b);
		printf("mat33_sub_matrix(mat_b) => \n");
		print_mat22(mat33_sub_matrix(mat_b, 0, 2));

		printf("mat_c => \n");
		print_mat44(mat_c);
		printf("mat33_sub_matrix(mat_c) => \n");
		print_mat33(mat44_sub_matrix(mat_c, 2, 1));

		printf("mat_e => \n");
		print_mat33(mat_e);
		printf("mat33_minor(mat_e) = % 6.6lf\n", mat33_minor(mat_e, 1, 0));
		printf("mat33_cofactor(mat_e) = % 6.6lf\n", mat33_cofactor(mat_e, 0, 0));
		printf("mat33_cofactor(mat_e) = % 6.6lf\n", mat33_cofactor(mat_e, 1, 0));


		
		printf("mat_f => \n");
		print_mat33(mat_f);
		printf("mat33_det(mat_f) = % 6.6lf\n", mat33_det(mat_f));

		printf("mat_g => \n");
		print_mat44(mat_g);
		printf("mat44_det(mat_g) = % 6.6lf\n", mat44_det(mat_g));

		printf("mat_h => \n");
		print_mat44(mat_h);
		printf("inverse(mat_h) => \n");
		print_mat44(inverse(mat_h));

		printf("mat_i => \n");
		print_mat44(mat_i);
		printf("inverse(mat_i) => \n");
		print_mat44(inverse(mat_i));
		

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
