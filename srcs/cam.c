#include "minirt.h"

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
	orientation.m[0] = left.x; orientation.m[1] = left.y; orientation.m[2] = left.z; orientation.m[3] = 0;
	orientation.m[4] = true_up.x; orientation.m[5] = true_up.y; orientation.m[6] = true_up.z; orientation.m[7] = 0;
	orientation.m[8] = -forward.x; orientation.m[9] = -forward.y; orientation.m[10] = -forward.z; orientation.m[11] = 0;
	orientation.m[12] = 0; orientation.m[13] = 0; orientation.m[14] = 0; orientation.m[15] = 1;
	saida = mat44_mul(orientation, mat44_translate(-from.x, -from.y, -from.z));
	return (saida);
}

t_camera	setup_camera(t_vars vars)
{
	t_camera	camera;
	double		half_view;
	double		aspect;

	camera.hsize = (double)vars.largura;
	camera.vsize = (double)vars.altura;
	camera.field_of_view = (vars.cam.fov / 180.0) * (PI);
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
	t_ray	ray;
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

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
