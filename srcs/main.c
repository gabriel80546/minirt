#include <stdio.h>
#include "mlx.h"

int	main(void)
{
//	printf("Hello World!\n");

	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
	return (0);
}
