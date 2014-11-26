/*****************************************************************
code writer: EOF
code date: 2014.03.03
e-mail: jasonleaster@gmail.com
code purpose :
	This code is a implementation for function pop_stack
If there is something wrong with my code, please touch me by e-mail

*****************************************************************/
#include "stack.h"

int pop_stack(struct node* p_top)
{
	struct node* temp = NULL;
	
	int number = 0;

	if(is_empty(p_top) == EMPTY)
	{
		printf("empty stack!\nprocess end");
		return EMPTY;
	}
	else
	{
		temp = p_top->next;
		p_top->next = p_top->next->next;
		number = temp->data;
		free(temp);
	}

	return number;
}

