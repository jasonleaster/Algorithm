/*****************************************************
Code writer	:	EOF
Code date	:	2014.09.13
code file	:	is_full.c
e-mail		:	jasonleaster@gmail.com

code purpose	:
	This file("is_full.c") a implementation for 
functin "is_full()".

	If there is something wrong with my code, 
please touch me by e-mail. Thank you.

*****************************************************/
#include "stack.h"

int is_full(struct stack* p_stack)
{
	if(p_stack->top_of_stack < 0)
	{
		return FULL_STACK;
	}
	else
	{
		return UNFULL_STACK;
	}
}
