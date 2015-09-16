#include "skip_list.h"

struct node* init_skip_list(void)
{
	struct skip_list* p_skip_list = NULL;

	p_skip_list = (struct skip_list*)malloc(sizeof(struct skip_list));

	if(!p_skip_list)
	{
		printf("malloc failed in %s\n",__FUNCTION__);
		return NULL;
	}
	
	/*
	** Initialization of @struct skip_list
	*/
	p_skip_list->node_number = 0;
	p_skip_list->new_skip_list = init_skip_list;
	p_skip_list->del_skip_list = release_skip_list;
	p_skip_list->header.data   = 0;
	p_skip_list->header.level  = 0;

	return p_skip_list;
}
