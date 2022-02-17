#include "term_3d.h"

size_t	points_3d(char	*file);
void	value_3d(char	*file);
size_t	nextvalue(char	*s, size_t	ii);
long	avalue_3d(char	*str);
extern t_point	*g_obj;

void	read3d(char	*file)
{
	size_t	p;

	p = points_3d(file);
	g_obj = malloc(sizeof(t_point) * (p + 1));
	if (!g_obj)
	{
		write(1, "malloc error\n", 13);
		error();
	}
	bzero(g_obj, sizeof(t_point) * (p + 1));
	g_obj->x = p + 1;
	value_3d(file);
	return ;
}

size_t	points_3d(char	*file)
{
	size_t	i;
	size_t	p;

	i = 0;
	p = 0;
	while (!file[i])
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

	i = 1;
	ii = 0;
	while (i < g_obj->x)
	{
		if (*(file + ii) != '\n' && *(file + ii) != ',')
			(g_obj + i)->x = avalue_3d(file + ii);
		ii = nextvalue(file, ii);
		if (*(file + ii) != '\n' && *(file + ii) != ',')
			(g_obj + i)->y = avalue_3d(file + ii);
		ii = nextvalue(file, ii);
		if (*(file + ii) != '\n' && *(file + ii) != ',')
			(g_obj + i)->z = avalue_3d(file + ii);
		while (*(file + ii) != '\n')
			ii++;
		ii++;
		i++;
	}
	return ;
}

size_t	nextvalue(char	*s, size_t	ii)
{
	while (*(s + ii) != '\n' && *(s + ii) != ',')
		ii++;
	if (*(s + ii) == ',')
		ii++;
	return (ii);
}

long	avalue_3d(char	*str)
{
	long	value;
	long	dvalue;
	int		sin;
	char	s[BUFFER];

	sin = 1;
	if (str[0] == '-')
		sin = -1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	value = atoi(str) * 10000000000;
	while (isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		strlcpy(s, str, 10);
		dvalue = atoi(str);
		while (dvalue < 10000000000)
			dvalue *= 10;
		value += dvalue;
	}
	return (value * sin);
}
