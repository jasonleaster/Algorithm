/*********************************************************************
code writer : EOF
code date : 2014.03.07
e-mail: jasonleaster@gmail.com
code purpose:
		Just a implementation of function queue_enter. I would be
happy, if my code will help you to know what is queue.
*******************************************************************/
#include "BFS.h"

int queue_destory(struct node* p_queue_tail)
{
	if(!p_queue_tail)
	{
		return SUCCESS;
	}
	struct node* p_temp_node = NULL;
	
	p_temp_node = p_queue_tail->next;
	while(p_temp_node != NULL)
	{
		p_queue_tail->next = p_temp_node->next;
		free(p_temp_node);
		p_temp_node = p_queue_tail->next;
	}	
	
	free(p_queue_tail);

	return SUCCESS;
}
