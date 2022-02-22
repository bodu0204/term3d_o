#include "term_3d.h"

int	input_str(char *s)
{
	int	l;
	int	e;

	bzero(s, BUFFER);
	l = read(0, s, BUFFER);
	e = 0;
	while (s[BUFFER - 1] != '\0' || e)
	{
		e = 1;
		if (s[BUFFER - 1] == '\0')
		{
			bzero(s, BUFFER);
			return (-1);
		}
		bzero(s, BUFFER);
		read(0, s, BUFFER);
	}
	s[l - 1] = '\0';
	return (l);
}

int	linear_algebra(double	*algebra, double	*solution, int	x, int	y)
{
	int		i;

	i = 0;
	while (i < y)
	{
		//if (/* 入れ替え＋実行可能か判断 */)
		//{
		//}
		rmalgebra(algebra, i, x, y);
		i++;
	}
	return (0);
}

enum e_buf
{
	X,
	Y,
	Z
};

void	rmalgebra(double	*a, int	p, int	x, int	y)
{
	int		i[2];

	i[X] = p + 1;
	while (i[X] < x)
	{
		*(a + (p * x) + i[X]) /= *(a + (p * x) + p);
		i[X]++;
	}
	*(a + (p * x) + p) = 1;
	i[Y] = 0;
	while (i[Y] < y)
	{
		if (i[Y] != p)
		{
			i[X] = p + 1;
			while (i[X] < x)
			{
				a[(x * i[Y]) + i[X]] -= a[(p * x) + i[X]] * a[(x * i[Y]) + p];
				i[X]++;
			}
			*(a + (x * i[Y]) + p) = 0;
		}
		i[Y]++;
	}
	return ;
}
