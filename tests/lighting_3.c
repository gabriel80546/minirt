#include <stdio.h>
#include "minirt.h"
#include "check.h"

int main(void)
{
	t_material material;
	t_tuple	eyev;
	t_tuple	normalv;
	t_light	luz;
	t_tuple	position;
	t_cor	result;
	t_debug deb;

	deb = (t_debug){0};
	deb.x = 1;
	deb.x_bugado = 2;
	deb.x_iluminado = 3;
	deb.x_sombreado = 4;

	printf("lighting_3: ");
	// eyev = vector(0, 0, -1);
	// And normalv ← vector(0, 0, -1);
	// And light ← point_light(point(0, 0, -10), color(1, 1, 1));
	// When result ← lighting(m, light, position, eyev, normalv);
	// color(1.9, 1.9, 1.9)

	material = (t_material){0};
	material.color = color(1.0, 1.0, 1.0);
	material.ambient = 0.1;
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	luz = (t_light){0};
	luz.bright = 1.0;
	luz.cor = color(1.0, 1.0, 1.0);
	luz.position = point(0.0, 10.0, -10.0);
	position = point(0.0, 0.0, 0.0);
	eyev = vector(0.0, 0.0, -1.0);
	normalv = vector(0.0, 0.0, -1.0);
	result = lighting(material, luz, position, eyev, normalv, 0, deb);
	check(equal(result.r, 0.7364)
		&& equal(result.g, 0.7364)
		&& equal(result.b, 0.7364));
	printf("\n");
	return (0);
}
