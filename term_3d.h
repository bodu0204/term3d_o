#ifndef TERM_3D
#define TERM_3D

#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define D_X 150
#define D_Y 100
#define BUFFER 32
typedef struct s_point
{
	long	x;
	long	y;
	long	z;
}	t_point;

int	input_str(char *s);
void error(void);
#endif
