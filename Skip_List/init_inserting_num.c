#include "stack_list.h"

struct node* init_inserting_num(int number)
{
	int temp  = 0;
	int level = node_level();

	struct node* p_node = (struct node*)malloc(sizeof(struct node) + 
				sizeof(struct node*)*(level));

	if(!p_node)
	{
		return NULL;
	}

	/*
	** Initialization of @struct node
	*/
	p_node->data  = number;
	p_node->level = level;
	
	for(temp = 0;temp < level;temp++)
	{
		p_node->next[temp] = NULL;
	}
}
