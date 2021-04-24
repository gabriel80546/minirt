#include "minirt.h"

t_mat44	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_mat44	saida;
	t_tuple	forward;
	t_tuple	upn;
	t_tuple	left;
	t_tuple	true_up;
	t_mat44	orientation;

	orientation = (t_mat44){0};
	forward = normalize(tup_sub(to, from));
	upn = normalize(up);
	left = cross(forward, upn);
	true_up = cross(left, forward);
	orientation = set_row_ooone(orientation,
			left.x, left.y, left.z, 0.0);
	orientation = set_row_tttwo(orientation,
			true_up.x, true_up.y, true_up.z, 0.0);
	orientation = set_row_three(orientation,
			-forward.x, -forward.y, -forward.z, 0.0);
	orientation = set_row_ffour(orientation,
			0.0, 0.0, 0.0, 1.0);
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
	pixel = mat44_tuple_mul(mat44_inverse(camera.transform),
			point(world_x, world_y, -1));
	origin = mat44_tuple_mul(mat44_inverse(camera.transform),
			point(0, 0, 0));
	direction = normalize(tup_sub(pixel, origin));
	ray = ray_create(origin, direction);
	return (ray);
}

t_cam	empty_cam(void)
{
	t_cam	saida;

	saida.pos.x = 0.0;
	saida.pos.y = 0.0;
	saida.pos.z = 0.0;
	saida.direc.x = 0.0;
	saida.direc.y = 0.0;
	saida.direc.z = 1.0;
	saida.transform = mat44_identity();
	saida.rot.x = 0.0;
	saida.rot.y = 0.0;
	saida.rot.z = 0.0;
	saida.fov = 90.0;
	return (saida);
}
