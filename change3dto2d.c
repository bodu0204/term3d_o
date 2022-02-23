#include "term_3d.h"
void	getvector(t_vector	*v, t_camera	camera);
void	changevector(unsigned	*bp, t_camera	camera, t_vector	*v);
void	collor(char	*print, unsigned	*bp);
void	output(char	*print);

extern double	*g_obj;
extern unsigned	g_objlen;

void	change3dto2d(t_camera	camera)
{
	char	print[(D_X + 1) * D_Y];
	unsigned	bp[D_X * D_Y];
	t_vector	v[3];

	getvector(v, camera);
	changevector(bp, camera, v);
	collor(print, bp);
	output(print);
	return ;
}
