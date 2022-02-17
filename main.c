#include "term_3d.h"

void	readfile(void);
t_point	angle(t_point	*);

t_point	*g_obj = NULL;
t_point	g_order[3];

enum camera {
	coordinate,
	screen,
	flag
};

int main (void)
{
	t_point	camera[2];

	readfile();
	while (1)
	{
		get_order();
		angle(camera);
		change3dto2d();
	}
	return (0);
}
