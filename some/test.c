void	rmalgebra(double	*a, int	p, int	x, int	y);
#include <stdio.h>

int	linear_algebra(double	*algebra, double	*solution, int	x, int	y)
{
	int		i;
	(void)solution;

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


int main (void)
{
	double	d[10000];
	int		i;

	d[0] = 1;
	d[1] = 1;
	d[2] = 1;
	d[3] = 10;
	d[4] = 1;
	d[5] = 4;
	d[6] = 2;
	d[7] = 17;
	d[8] = 2;
	d[9] = 3;
	d[10] = 1;
	d[11] = 17;
	linear_algebra(d, NULL, 4, 3);
	i = 0;
	while (i < 12)
	{
		printf("[%3d] = %9lf,\t", i + 1, d[i]);
		if (!((i + 1) % 4))
			printf("\n");
		i++;
	}
}
