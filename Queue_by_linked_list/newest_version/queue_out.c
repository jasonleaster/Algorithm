/***********************************************************************
code writer : EOF
code date : 2014.09.13
e-mail: jasonleaster@gmail.com
code purpose:
		Just a implementation of function queue_out. I would be
happy, if my code will help you to know what is queue.

If something wrong with my code, please touch me by e-mail.

************************************************************************/
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int queue_out(struct node** pp_queue_header)
{
	struct node* p_temp_node = NULL;
	int ret = 0;

	if( !(*pp_queue_header))
	{
		/*
		**	There is no way to check the return value.
		** when we use "queue_out()". So, you needn't to do
		** that.
		*/
		printf("ATTENTION! There is nothing in the queue.\n");
		return EMPTY_QUEUE;
	}

	p_temp_node = (*pp_queue_header);
	
	(*pp_queue_header) = (*pp_queue_header)->previous;
	(*pp_queue_header)->next = NULL;
	
	ret = p_temp_node->data;
	free(p_temp_node);
	p_temp_node = NULL;

	return ret;
}

