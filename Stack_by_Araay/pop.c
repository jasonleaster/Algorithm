/*****************************************************
Code writer	:	EOF
Code date	:	2014.09.13
code file	:	pop.c
e-mail		:	jasonleaster@gmail.com

code purpose	:
	This file("pop.c") a implementation for
functin "pop()".

	If there is something wrong with my code, 
please touch me by e-mail. Thank you.

*****************************************************/
#include "stack.h"

int pop(struct stack* p_stack)
{
	int index = p_stack->top_of_stack;
	int ret   = 0;

	if(is_empty(p_stack) == UNEMPTY_STACK)
	{
		
		ret = p_stack->array[index];

		(p_stack->top_of_stack)++;

		return ret;
	}
	else
	{
		printf("ATTENTION! empty stack can't pop anything!\n");

	}
	
	return FAILED_RET;
}
