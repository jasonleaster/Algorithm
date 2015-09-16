/*****************************************************************
code writer: EOF
code date: 2014.03.03
e-mail: jasonleaster@gmail.com
code purpose :
	This code is a implementation for function pop_stack
If there is something wrong with my code, please touch me by e-mail

*****************************************************************/
#include "stdlib.h"
#include "stdio.h"
#include "stack.h"

int pop_stack(struct node* p_top)
{
	struct node* temp = NULL;
	
	if(is_empty(p_top) == EMPTY)
	{
		printf("empty stack!\nprocess end");
		return EMPTY;
	}
	else
	{
		temp = p_top->next;
		p_top->next = p_top->next->next;
		printf("%d\n",temp->data);
		free(temp);
	}
}

