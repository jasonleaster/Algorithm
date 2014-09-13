/****************************************************************
code writer : EOF
code date: 2014.03.07
e-mail: jasonleaster@gmail.com
code purpose:
		Just a implementation of function queue_enter. I would be
happy, if my code will help you to know what is queue.
****************************************************************/
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

int queue_enter(struct node** pp_queue_header ,struct node** pp_queue_tail,int number)
{
	struct node* p_new_node = NULL;
	struct node* p_temp_node = NULL;

	p_new_node = (struct node*)malloc(sizeof(struct node));
	if(p_new_node == NULL)
	{
		printf("malloc error!\nqueue enter failed\n");
		return FAILED;
	}

	if(!(*pp_queue_tail))	
	{
		*pp_queue_tail   = p_new_node;
		*pp_queue_header = p_new_node;

		p_new_node->previous = NULL;
		p_new_node->next     = NULL;
	}
	else
	{
		
		p_temp_node = (*pp_queue_tail);
	
		p_new_node->data = number;

		p_new_node->next = p_temp_node;
		p_new_node->previous = NULL;

	
		p_temp_node->previous = p_new_node;
	
		(*pp_queue_tail) = p_new_node;

	}

	return SUCCESS;
}


