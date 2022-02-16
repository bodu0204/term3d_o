#include "term_3d.h"

void	readfile(void);
t_point	angle(t_point	*);

t_point	*g_obj;
t_point	g_gole[3];

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
		angle(camera);

	}
	return (0);
}
