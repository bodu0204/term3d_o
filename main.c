/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:06:07 by ryoakira          #+#    #+#             */
/*   Updated: 2022/02/28 01:09:05 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_3d.h"
void	readfile(void);
void	change3dto2d(void);

double	*g_obj = NULL;
unsigned	g_objlen = 0;

int	main(void)
{
	readfile();
	while (1)
	{
		change3dto2d();
	}
	return (0);
}
