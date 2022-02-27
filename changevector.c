/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changevector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:05:50 by ryoakira          #+#    #+#             */
/*   Updated: 2022/02/28 01:50:42 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_3d.h"
void	changebp(unsigned int	*bp, double	*cpobj);
void	solvevector(double	*b, double	*s, t_camera	c, t_vector	*v);
extern double		*g_obj;
extern unsigned int	g_objlen;

void	changevector(unsigned int	*bp, t_camera	camera, t_vector	*v)
{
	double	*cpobj;
	size_t	i;

	cpobj = malloc(sizeof(double) * g_objlen);
	if (!cpobj)
	{
		write(1, "malloc error\n", 13);
		free(g_obj);
		exit(0);
	}
	i = 0;
	while (i < g_objlen)
	{
		solvevector(cpobj + i, g_obj + i, camera, v);
		i += 3;
	}
	changebp(bp, cpobj);
	free(cpobj);
	return ;
}

void	solvevector(double	*b, double	*s, t_camera	c, t_vector	*v)
{
	double		a[12];

	a[0] = (v + 0)->vector_x;
	a[1] = (v + 1)->vector_x;
	a[2] = (v + 2)->vector_x;
	a[3] = s[0] - c.coordinate_x;
	a[4] = (v + 0)->vector_y;
	a[5] = (v + 1)->vector_y;
	a[6] = (v + 2)->vector_y;
	a[7] = s[1] - c.coordinate_y;
	a[8] = (v + 0)->vector_z;
	a[9] = (v + 1)->vector_z;
	a[10] = (v + 2)->vector_z;
	a[11] = s[2] - c.coordinate_z;
	if (linear_algebra(a, b, 4, 3))
		printf("error\n");
}

void	changebp(unsigned int	*bp, double	*cpobj)
{
	size_t	i;
	int		c[2];

	i = 0;
	while (i < g_objlen)
	{
		if (cpobj[i + Z] > 0)
		{
			c[X] = cpobj[i + X] + (D_X / 2);
			c[Y] = cpobj[i + Y] + (D_Y / 2);
			if (c[X] >= 0 && c[X] < D_X && c[Y] >= 0 && c[Y] < D_Y)
				bp[(c[Y] * D_X) + c[X]]++;
		}
		i += 3;
	}
	return ;
}
