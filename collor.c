/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:05:55 by ryoakira          #+#    #+#             */
/*   Updated: 2022/02/28 01:52:43 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term_3d.h"
void	mkbox(unsigned int	*box, unsigned int	*bp);
size_t	countzero(unsigned int	*bp);
void	countnum(unsigned int	*bp, unsigned int	*m, size_t	*i);
void	newline(char	*print);

void	collor(char	*print, unsigned int	*bp)
{
	unsigned int	box[3];
	size_t			bi;

	mkbox(box, bp);
	bi = 0;
	while (bi < D_X * D_Y)
	{
		if (bp[bi] < box[0])
			print[bi + (bi / D_X)] = '-';
		else if (bp[bi] >= box[2])
			print[bi + (bi / D_X)] = '#';
		else if (bp[bi] >= box[1])
			print[bi + (bi / D_X)] = 'o';
		else
			print[bi + (bi / D_X)] = '+';
		if (bp[bi] == 0)
			print[bi + (bi / D_X)] = ' ';
		bi++;
	}
	newline(print);
	return ;
}

void	mkbox(unsigned int	*box, unsigned int	*bp)
{
	unsigned int	m[2];
	size_t			i[4];
	size_t			b;

	bzero(box, sizeof(unsigned int) * 3);
	bzero(i, sizeof(size_t) * 4);
	b = countzero(bp) / 4;
	m[1] = 0;
	while (i[0] < 3)
	{
		while ((i[1] < b * (i[0] + 1) && m[1]) || !i[2])
		{
			bzero(i + 2, sizeof(size_t) * 2);
			m[0] = m[1];
			countnum(bp, m, i);
			i[1] += i[3];
		}
		box[i[0]] = m[1];
		i[0]++;
	}
	return ;
}

size_t	countzero(unsigned int	*bp)
{
	size_t	i;
	size_t	ii;

	i = 0;
	ii = 0;
	while (i < D_X * D_Y)
	{
		if (bp[i] != 0)
			ii++;
		i++;
	}
	return (ii);
}

void	countnum(unsigned int	*bp, unsigned int	*m, size_t	*i)
{
	while (i[2] < D_X * D_Y)
	{
		if (bp[i[2]] > m[0])
		{
			if (m[0] == m[1] || bp[i[2]] < m[1])
			{
				m[1] = bp[i[2]];
				i[3] = 1;
			}
			else if (bp[i[2]] == m[1])
				i[3]++;
		}
		i[2]++;
	}
	return ;
}

void	newline(char	*p)
{
	size_t	i;

	i = D_X;
	while (i < (D_X + 1) * D_Y)
	{
		p[i] = '\n';
		i += D_X + 1;
	}
	return ;
}
