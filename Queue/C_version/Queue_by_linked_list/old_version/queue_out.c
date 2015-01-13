/***********************************************************************
code writer : EOF
code date : 2014.03.07
e-mail: jasonleaster@gmail.com
code purpose:
		Just a implementation of function queue_out. I would be
happy, if my code will help you to know what is queue.

If something wrong with my code, please touch me by e-mail.

************************************************************************/
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void queue_out(struct node** pp_queue_header)
{
	struct node* p_temp_node = NULL;
	
	p_temp_node = (*pp_queue_header);
	
	(*pp_queue_header) = (*pp_queue_header)->previous;
	(*pp_queue_header)->next = NULL;
	
	printf("queue out data :%d\n",p_temp_node->data);

	free(p_temp_node);
}

