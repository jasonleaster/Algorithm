/******************************************************************************
code writer : EOF
code date : 2014.03.07
e-mail: jasonleaster@gmail.com
code purpose:
		Just a implementation of function queue_print. I would be
happy, if my code will help you to know what is queue.

If something wrong with my code, please touch me by e-mail.

***********************************************************************************/

#include "BFS.h"
void queue_print(struct node* p_queue_tail)
{
	struct node* p_temp_node = NULL;
	
	p_temp_node = p_queue_tail;

	printf("queue data at this time:\n");

	while(p_temp_node != NULL)
	{
		printf("%d ",p_temp_node->data);
		p_temp_node = p_temp_node->next;
	}

	printf("\n");
}

