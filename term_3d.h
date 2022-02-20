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
	long	x;
	long	y;
	long	z;
}	t_point;

typedef struct s_camera
{
	long	coordinate_x;
	long	coordinate_y;
	long	coordinate_z;
	long	vector_x;
	long	vector_y;
	long	vector_z;
	long	zoom;
	long	time;
	char	flag[8];
}	t_camera;

int	input_str(char *s);
void error(void);
#endif
