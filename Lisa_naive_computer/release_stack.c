#include "stack.h"

void release_stack(struct node* p_top)
{
	while(is_empty(p_top) == NON_EMPTY)
	{
		pop_stack(p_top);
	}
}
