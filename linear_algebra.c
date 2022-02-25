#include "term_3d.h"
int	swap_algebra(double	*algebra, int	p, int	x, int	y);
void	rmalgebra(double	*a, int	p, int	x, int	y);

int	linear_algebra(double	*algebra, double	*solution, int	x, int	y)
{
	int		i;

	i = 0;
	while (i < y)
	{
		if (swap_algebra(algebra, i, x, y))
			break ;
		rmalgebra(algebra, i, x, y);
		i++;
	}
	if (i != y)
		return (1);
	i = 0;
	while (i < y)
	{
		solution[i] = algebra[((i + 1) * x) - 1];
		i++;
	}
	return (0);
}

int	swap_algebra(double	*algebra, int	p, int	x, int	y)
{
	int		i[2];
	double	buf;

	if (algebra[(x * p) + p] == 0)
	{
		i[Y] = p + 1;
		while (algebra[(x * i[Y]) + p] == 0 && i[Y] < y)
			i[Y]++;
		if (i[Y] < y)
		{
			i[X] = p;
			while (i[X] < x)
			{
				buf = algebra[(x * p) + i[X]];
				algebra[(x * p) + i[X]] = algebra[(x * i[Y]) + i[X]];
				algebra[(x * i[Y]) + i[X]] = buf;
				i[X]++;
			}
		}
		else
			return (1);
	}
	return (0);
}

void	rmalgebra(double	*a, int	p, int	x, int	y)
{
	int	i[2];

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
