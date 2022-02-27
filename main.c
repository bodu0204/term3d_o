#include "term_3d.h"

void	readfile(void);
void	angle(t_camera	*camera);
void	change3dto2d(t_camera	camera);

double	*g_obj = NULL;
unsigned	g_objlen = 0;
t_point	g_order[3];
enum e_camera
{
	coordinate,
	vecter,
	flag
};

int	main(void)
{
	t_camera	camera;

	camera.coordinate_x = -10000;/* test */
	camera.coordinate_y = 0;/* test */
	camera.coordinate_z = 5;/* test */

	readfile();
	while (1)
	{
		//get_order();
		//angle(&camera);
		change3dto2d(camera);
	}
	return (0);
}
