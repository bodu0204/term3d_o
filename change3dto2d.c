#include "term_3d.h"
void	getvector(t_vector	*v, t_camera	*camera);
void	changevector(unsigned	*bp, t_camera	camera, t_vector	*v);
void	collor(char	*print, unsigned	*bp);
void	output(char	*print);
void	stdmov(t_vector	*v, t_camera	*camera);

extern double	*g_obj;
extern unsigned	g_objlen;

void	change3dto2d(t_camera	camera)
{
	char	print[((D_X + 1) * D_Y) + 1];
	unsigned	bp[D_X * D_Y];
	t_vector	v[3];

	bzero(bp, sizeof(unsigned) * D_X * D_Y);
	getvector(v, &camera);
	//(v + X)->vector_x = 0;/* test */
	//(v + X)->vector_y = -0.1;/* test */
	//(v + X)->vector_z = 0;/* test */
	//(v + Y)->vector_x = 0;/* test */
	//(v + Y)->vector_y = 0;/* test */
	//(v + Y)->vector_z = -0.1;/* test */
	//(v + Z)->vector_x = 1;/* test */
	//(v + Z)->vector_y = 0;/* test */
	//(v + Z)->vector_z = 0;/* test */

	changevector(bp, camera, v);
	collor(print, bp);
	print[((D_X + 1) * D_Y)] = '\0';
	output(print);
	return ;
}

void	getvector(t_vector	*v, t_camera	*camera)
{
	if(1)
		stdmov(v, camera);
	return ;
}

void	output(char	*print)
{
	size_t	i;

	i = (D_X + 1) * (D_Y - 1);
	while (i > 0)
	{
		write(1, print + i, D_X + 1);/* test */
		printf("\033[%dA" ,2);/* up 10 */
		printf("\033[%dD" ,D_X); //カーソルを10行だけ左に移動
		printf("\033[2K");/* clear line */
		fflush(stdout);
		i -= D_X + 1;
	}
	printf("\033[%dB" ,D_Y);/* down 10 */
	return ;
}
