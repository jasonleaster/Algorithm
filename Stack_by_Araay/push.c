/*****************************************************
Code writer	:	EOF
Code date	:	2014.09.13
code file	:	push.c
e-mail		:	jasonleaster@gmail.com

code purpose	:
	This file("push.c") a implementation for 
functin "is_full()".

	If there is something wrong with my code, 
please touch me by e-mail. Thank you.

*****************************************************/
#include "stack.h"

int push(struct stack* p_stack,int num)
{

	int index = p_stack->top_of_stack;
	int ret   = 0;

	if(is_full(p_stack) == FULL_STACK)
	{
		printf("ATTENTION! Stack is full and can't be pushed.");
	}
	else
	{
		index = --(p_stack->top_of_stack);

		p_stack->array[index] = num;

		return SUCCESS_RET;
	}
		

	return FAILED_RET;
}
