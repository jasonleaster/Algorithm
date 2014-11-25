#include "tls.h"


void release_table(struct table* p_table)
{
	if(!p_table)
	{
		return;
	}

	free(p_table);
}
