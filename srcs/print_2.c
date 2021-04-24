#include "minirt.h"
#include <stdarg.h>
#include <sys/time.h>

int	say(const char *format, char *file, const char *func, int line, ...)
{
	va_list			args;
	int				saida;
	struct timeval	tempo;

	gettimeofday(&tempo, NULL);
	printf("%03ld.%06ld:%s(%s:%d): ", (tempo.tv_sec % 600), tempo.tv_usec,
		file, func, line);
	va_start(args, line);
	saida = vprintf(format, args);
	va_end(args);
	fflush(stdout);
	return (saida);
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
