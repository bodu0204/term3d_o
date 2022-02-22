#ifndef TERM_3D
#define TERM_3D

#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>


#define D_X 150
#define D_Y 100
#define BUFFER 32
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_camera
{
	double	coordinate_x;
	double	coordinate_y;
	double	coordinate_z;
	double	vector_x;
	double	vector_y;
	double	vector_z;
	double	zoom;
	double	time;
	char	flag[8];
}	t_camera;

int	input_str(char *s);
void error(void);
#endif
