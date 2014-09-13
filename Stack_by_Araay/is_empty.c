/*****************************************************
Code writer	:	EOF
Code date	:	2014.09.13
code file	:	stack.h
e-mail		:	jasonleaster@gmail.com

code purpose	:
	This file("is_empty.c") a implementation for 
function "is_empty()".

	If there is something wrong with my code, 
please touch me by e-mail. Thank you.

*****************************************************/
#include "stack.h"

int is_empty(struct stack* p_stack)
{
	if(p_stack->top_of_stack >= p_stack->stack_size)
	{
		return EMPTY_STACK;
	}
	else
	{
		return UNEMPTY_STACK;	
	}
}
