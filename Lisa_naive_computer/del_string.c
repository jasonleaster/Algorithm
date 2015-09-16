#include "stack.h"

void del_string(struct string* p_string)
{
	if(!p_string)
	{
		return ;
	}

	free(p_string);
}
