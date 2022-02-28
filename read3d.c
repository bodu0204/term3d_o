/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:06:31 by ryoakira          #+#    #+#             */
/*   Updated: 2022/02/28 15:12:58 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_3d.h"
size_t	points_3d(char	*file);
void	value_3d(char	*file);
size_t	nextvalue_3d(char	*s, size_t	ii);
double	avalue_3d(char	*str);
extern double		*g_obj;
extern unsigned int	g_objlen;

void	read3d(char	*file)
{
	size_t	p;

	p = points_3d(file);
	g_obj = malloc(sizeof(double) * p * 3);
	if (!g_obj)
	{
		write(1, "malloc error\n", 13);
		free(g_obj);
		exit(0);
	}
	bzero(g_obj, sizeof(double) * p * 3);
	g_objlen = p * 3;
	value_3d(file);
	return ;
}

size_t	points_3d(char	*file)
{
	size_t	i;
	size_t	p;

	i = 0;
	p = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			p++;
		i++;
	}
	return (p);
}

void	value_3d(char	*file)
{
	size_t	i;
	size_t	ii;

	i = 0;
	ii = 0;
	while (i < g_objlen)
	{
		if (*(file + ii) != '\n' && *(file + ii) != ',')
			g_obj[i + X] = atof(file + ii);
		ii = nextvalue_3d(file, ii);
		if (*(file + ii) != '\n' && *(file + ii) != ',')
			g_obj[i + Y] = atof(file + ii);
		ii = nextvalue_3d(file, ii);
		if (*(file + ii) != '\n' && *(file + ii) != ',')
			g_obj[i + Z] = atof(file + ii);
		while (*(file + ii) != '\n')
			ii++;
		ii++;
		i += 3;
	}
	return ;
}

size_t	nextvalue_3d(char	*s, size_t	ii)
{
	while (*(s + ii) != '\n' && *(s + ii) != ',')
		ii++;
	if (*(s + ii) == ',')
		ii++;
	return (ii);
}
/*
double	avalue_3d(char	*str)
{
	double	value;
	double	dvalue;
	int		sin;
	char	s[BUFFER];

	sin = 1;
	if (str[0] == '-')
		sin = -1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	value = atoi(str);
	while (isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		strlcpy(s, str, 10);
		dvalue = atoi(s);
		while (dvalue > 1)
			dvalue /= 10.0;
		value += dvalue;
	}
	return (value * sin);
}
 */
