#include "term_3d.h"
unsigned	search_bot(unsigned	*box, unsigned	*bp);

void	collor(char	*print, unsigned	*bp)
{
	unsigned	box[3];
	size_t		bi;

	mkbox(box, bp);
	bi = 0;
	while (bi < D_X * D_Y)
	{
		if (bp[bi] < box[0])
			print[bi + (bi / D_X)] = '#';
		else if (bp[bi] >= box[0])
			print[bi + (bi / D_X)] = 'o';
		else if (bp[bi] <= box[1])
			print[bi + (bi / D_X)] = '+';
		else if (bp[bi] <= box[2])
			print[bi + (bi / D_X)] = '-';
		if (bp[bi] == 0)
			print[bi + (bi / D_X)] = ' ';
		print[(((bi / D_X) + 1) * (D_X + 1)) - 1] = '\n';
		bi++;
	}
	return ;
}

void	mkbox(unsigned	*box, unsigned	*bp)
{
	unsigned	m[2];
	size_t		i[4];

	bzero(i, sizeof(size_t) * 2);
	m[1] = 0;
	while(i[0] < 3)
	{
		while ((i[1] < ((D_X * D_Y) / 4) * (i[0] + 1) && m[1]) || !i[0])
		{
			bzero(i + 2, sizeof(size_t) * 2);
			m[0] = m[1];
			countnum(box, bp, m, i);
			i[1] += i[3];
		}
		box[i[0]] = m[1];
		i[0]++;
	}
	return ;
}

void	countnum(unsigned	*box, unsigned	*bp, unsigned	*m, size_t	*i)
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
