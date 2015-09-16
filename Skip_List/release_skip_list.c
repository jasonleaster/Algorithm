#include "skip_list.h"

void release_skip_list(struct skip_list* p_skip_list)
{
	if(!p_skip_list)
	{
		return ;
	}

	struct node* p_next = p_skip_list->header.next[0];
	struct node* p_tmp  = p_next->next[0];

	for(;!!p_next;p_next = p_tmp,p_tmp  = p_next->next[0])
	{
		p_skip_list->header.next[0] = p_tmp;
		free(p_next);
	}

	free(p_skip_list);
}
