/*****************************************************
Code writer	:	EOF
Code date	:	2014.09.13
code file	:	init_stack.c
e-mail		:	jasonleaster@gmail.com

code purpose	:
	This file("init_stack.c") a source file  for
a implementation of ADT-stack in array-type.

	If there is something wrong with my code, 
please touch me by e-mail. Thank you.

*****************************************************/
#include "stack.h"

struct stack* init_stack(void)
{

	struct stack* p_stack = NULL;
 
	p_stack = (struct stack*)malloc(sizeof(struct stack));

	if(!p_stack)
	{
		printf("In %s: line:%d malloc failed\n",__FUNCTION__,__LINE__);
		return 0;
	}
	else
	{
		p_stack->top_of_stack = STACK_SIZE;
		p_stack->stack_size   = STACK_SIZE;
	}

	return p_stack;
}
