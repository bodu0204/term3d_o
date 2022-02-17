#include "term_3d.h"

void	read3d(char	*file);
int		openfile(char	*name);
size_t	filesize(int fd);
int		translate(char *name, char	*file);
extern t_point	*g_obj;

void	readfile(void)
{
	char		name[BUFFER];
	size_t		size;
	char		*file;
	int			fd;

	fd = -1;
	while (fd == -1)
	{
		bzero(name, BUFFER);
		fd = openfile(name);
		size = filesize(fd);
		file = malloc(size + 1);
		if (!file)
		{
			write(1, "malloc error\n", 13);
			error();
		}
		fd = openfile(name);
		read(fd, file, size);
		file[size] = '\0';
		close(fd);
		fd = translate(name, file);
		free(file);
	}
	return ;
}

int	openfile(char	*name)
{
	int	i;
	int	fd;

	if (*name)
		fd = open(name, O_RDONLY);
	else
	{
		while (1)
		{
			write(1, "input file name:", 16);
			i = input_str(name);
			if (i != -1)
				fd = open(name, O_RDONLY);
			if (i != -1 && fd != -1)
				break ;
			write(1, "can't open this file\n", 21);
		}
	}
	return (fd);
}

size_t	filesize(int fd)
{
	size_t	size;
	ssize_t	i;
	char	s[BUFFER];

	i = read(fd, s, BUFFER);
	size = i;
	while (i == BUFFER)
	{
		size += BUFFER;
		i = read(fd, s, BUFFER);
	}
	if (i < 0)
	{
		write(1, "read error\n", 11);
		error();
	}
	return (size + i);
}

int	translate(char *name, char	*file)
{
	size_t	i;

	i = 0;
	while (name[i] != '.')
		i++;
	if (!strcmp(name + i, ".3d"))
		read3d(file);
	else
	{
		write(1, "This format is not supported\n", 29);
		return (-1);
	}
	return (0);
}
