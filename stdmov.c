/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdmov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:06:40 by ryoakira          #+#    #+#             */
/*   Updated: 2022/02/28 16:07:43 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_3d.h"
void	stset(t_camera	*camera, t_vector	*v, double	pi);

void	stdmov(t_vector	*v, t_camera	*camera)
{
	static double	dig = 0;

	dig += time_diff();
	if (dig > 2)
		dig -= 2;
	stset(camera, v, dig * M_PI);
	return ;
}

void	stset(t_camera	*camera, t_vector	*v, double	pi)
{
	camera->coordinate_x = cos(pi) * 10;
	camera->coordinate_y = sin(pi) * 10;
	camera->coordinate_z = 5;
	v[X].vector_x = 0.1 * cos(pi - (0.5 * M_PI));
	v[X].vector_y = 0.1 * sin(pi - (0.5 * M_PI));
	v[X].vector_z = 0;
	v[Y].vector_x = 0;
	v[Y].vector_y = 0;
	v[Y].vector_z = 0.1;
	v[Z].vector_x = cos(pi + M_PI);
	v[Z].vector_y = sin(pi + M_PI);
	v[Z].vector_z = 0;
}
