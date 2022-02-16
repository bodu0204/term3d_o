#include "term_3d.h"

extern t_point	*g_obj;


void readfile(void)
{
	char		name[BUFFER];
	size_t		size;
	char		*file;
	int			fd;

	bzero(name, BUFFER);
	fd = openfile(name);
	size = filesize(fd);
	file = malloc(size + 1);
	fd = openfile(name);
	read(fd, file, size);
	file[size] = '\0';
	close(fd);
	translate(file);
	free(file);
	return ;
}

int	openfile(char	*name)
{
	int	i;
	int	fd;

	if (*name)
		open(name, O_RDONLY);
	else
	{
		while(1)
		{
			write(1, "input file name:", 16);
			i = input_str(name);
			if (i != -1)
				fd = open(name, O_RDONLY);
			if (i != -1 && fd != -1)
				break ;
			write(1, "can't open file", 16);
		}
	}

}
