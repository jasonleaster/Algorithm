#include "skip_list.h"

int node_level(void)
{
	int level = 1;
	double ret = 0;

	ret = ((double)rand())/RAND_MAX;

	while(ret < 0.5)
	{
		ret = ((double)rand())/RAND_MAX;
		level++;
	}

	return level;
}
