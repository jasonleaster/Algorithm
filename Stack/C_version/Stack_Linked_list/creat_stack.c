/*********************************************************************
code writer : EOF
code date : 2014.03.03
e-mail : jasonleaster@gmail.com
code purpose : 
		This code is my implementation for function creat_stack.
functin creat_stack would creat a the first node of the stack and just only
the first node. You must know what is stack...

If there is something wrong with my code, please touch me by e-mail.

**********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct node* creat_stack(void)
{
	struct node* p_top = NULL;

	p_top = (struct node*)malloc(sizeof(struct node));
	
	if(p_top == NULL)
	{
		printf("malloc failed\n");
	}
	
	p_top->next = NULL;

	while(is_empty(p_top) == NON_EMPTY)
	{
		pop_stack(p_top);	
	}
	
	return p_top;
}

