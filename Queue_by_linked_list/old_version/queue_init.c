/******************************************************************
code writer : EOF
code   date : 2014.03.07
e-mail : jasonleaster@gmail.com
Attention:
	Just a implementation of function queue_init. I would be
happy, if my code will help you to know what is queue.
we assuem that ...

Input data ---> tail | | |queue| | |  header ---> Output data
	
If something wrong with my code please touch me by e-mail.

*******************************************************************/
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

int queue_init(struct node** pp_queue_header,struct node** pp_queue_tail,int queue_size)
{
	int temp = 0;
	struct node* p_current_node;
	struct node* p_next_node;

	for(temp = 0; temp< queue_size;temp++)
	{
		if(temp == 0)
		{
			(*pp_queue_header) = (struct node*)malloc(sizeof(struct node));
			if((*pp_queue_header) == NULL)
			{
				printf("malloc error!\ninitilization failed!\n");
				return FAILED;
			}

			p_current_node = (*pp_queue_header);
			p_current_node->data = 0;
			p_current_node->previous = NULL;
			p_current_node->next = NULL;
			p_next_node = p_current_node;
			(*pp_queue_header) = p_current_node;
		}
		else
		{
			p_current_node = (struct node*)malloc(sizeof(struct node));
			if(p_current_node == NULL)
			{
				printf("malloc error!\ninitilization failed\n");
				return FAILED;
			}
			p_next_node->previous = p_current_node;
			p_current_node->next = p_next_node;
			p_current_node->data = 0;
			p_current_node->previous = NULL;
			p_next_node = p_current_node;
			
			if(temp == queue_size-1)
			{
				(*pp_queue_tail) = p_current_node;
			}
		}
	}

	return SUCCESS;	
}

