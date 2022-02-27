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

double	time_diff(void)
{
	static struct timespec	p = {0};
	struct timespec			n;
	unsigned				sec;
    int						nsec;

	if (!p.tv_sec)
	{
		clock_gettime(CLOCK_REALTIME, &p);
		return (0);
	}
	clock_gettime(CLOCK_REALTIME, &n);
	sec = n.tv_sec - p.tv_sec;
	nsec = n.tv_nsec - p.tv_nsec;
	p = n;
	return ((double)sec + (double)nsec / (1000 * 1000 * 1000));
}
