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
