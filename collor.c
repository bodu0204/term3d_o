#include "term_3d.h"
unsigned	search_bot(unsigned	*box, unsigned	*bp);

void	collor(char	*print, unsigned	*bp)
{
	unsigned	box[3];
	box[0]  = search_bot(box, bp);
	box[1]  = search_mid(box, bp);
	box[2]  = search_top(box, bp);
}

unsigned	search_bot(unsigned	*box, unsigned	*bp)
{
	unsigned	n;
	unsigned	min;
	size_t		i;
	size_t		nm;
	size_t		m;

	i = 0;
	min = 0;
	while(m > ((D_X * D_Y) / 4) * 3)
	

}
