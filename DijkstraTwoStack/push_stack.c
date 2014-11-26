/*******************************************************************
code writer : EOF
code date:2014.03.03
e-mail:jasonleaster@gmail.com
code purpose :
	This is my implementaion for function push_stack
If there is somrthing wrong with my code, please touche me by e-mail.

*******************************************************************/
#include "stack.h"

int push_stack(struct node** pp_top,int number)
{
	struct node* temp = NULL;
	struct node* new_node = NULL;
	
	new_node = (struct node*)malloc(sizeof(struct node));
	
	if(new_node == NULL)
	{
		printf("malloc failed\nprocess end\n");
		return 0;
	}
	
	new_node->data = number;
	new_node->next = (*pp_top)->next;
	(*pp_top)->next = new_node;
}

