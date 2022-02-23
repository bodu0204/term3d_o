#include "term_3d.h"

extern double	*g_obj;
extern unsigned	g_objlen;

void	changevector(unsigned	*bp, t_camera	camera, t_vector	*v)
{
	double	*cpobj;
	size_t	i;

	cpobj = malloc(g_objlen);
	if (!cpobj)
	{
		write(1, "malloc error\n", 13);
		error();
	}
	i = 0;
	while (i < g_objlen)
	{
		solvevector(cpobj + i, g_obj + i, camera, v);
		i += 3;
	}
	changebp(bp, cpobj);
	free(cpobj);
	return	;
}

void	solvevector(double	*dobj, double	*sobj, t_camera	camera, t_vector	*v)
{
	double		a[12];

	a[0] = (v + 0)->vector_x;
	a[1] = (v + 1)->vector_x;
	a[2] = (v + 2)->vector_x;
	a[3] = sobj[0] - camera.coordinate_x;
	a[4] = (v + 0)->vector_y;
	a[5] = (v + 1)->vector_y;
	a[6] = (v + 2)->vector_y;
	a[7] = sobj[1] - camera.coordinate_y;
	a[8] = (v + 0)->vector_z;
	a[9] = (v + 1)->vector_z;
	a[10] = (v + 2)->vector_z;
	a[11] = sobj[2] - camera.coordinate_z;
	linear_algebra(a, dobj, 4, 3);
}
