/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:06:45 by ryoakira          #+#    #+#             */
/*   Updated: 2022/02/28 04:44:10 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_3D_H
# define TERM_3D_H
# include <stdio.h>
# include <limits.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <sys/time.h>
# include <math.h>
# define D_X 150
# define D_Y 100
# define BUFFER 32
enum e_buf
{
	X,
	Y,
	Z
};
typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;
typedef struct s_vector
{
	double	vector_x;
	double	vector_y;
	double	vector_z;
}	t_vector;
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
int		input_str(char *s);
int		linear_algebra(double	*algebra, double	*solution, int	x, int	y);
double	time_diff(void);
#endif
